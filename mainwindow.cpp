#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QIcon>//加载图标
#include<QFileDialog>//打开文件夹

#include<QDebug>
#include<QAudioOutput>
#include <ctime>
//加载文件系统
#include<QFile>
#include<QDir>
#include<QFileInfo>
//弹出提示框
#include<QMessageBox>
//动画
#include <QPropertyAnimation>
#include <QPoint>
#include <QEventLoop>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_player(new QMediaPlayer(this))
    ,m_mode(ORDER_MODE)

{
    ui->setupUi(this);

    //标题
    setWindowTitle("MMmmmusic_player");
    //给音乐播放器的指针赋值
    //播放音乐
    QAudioOutput *audioOutput = new QAudioOutput(this);
    m_player->setAudioOutput(audioOutput);
    QString mediapath="D:/qtproj/qtmusicplayer/music/BEAUZ&Linney-Drive You Out 2.0.mp3";
    //D:/qtproj/qtmusicplayer/image/music1.mp3
    m_player->setSource(QUrl::fromLocalFile(mediapath));
    //设置按钮样式
    initBtn();
    //设置窗口大小
    setFixedSize(600,500);
    //设置背景图片
    setBackgroundColor(":/image/background.jpg");
    QString musicDir = "D:/qtproj/qtmusicplayer/music/";  // 相对于当前工作目录
    loadAppointedMusicDir(musicDir);
}
void MainWindow::setBtnStyle(QPushButton *button,const QString &filename)
{    //按钮大小,图标,背景透明，图标大小
    button->setFixedSize(50,50);
    button->setIcon(QIcon(filename));
    button->setStyleSheet("background-color:transparent");
    button->setIconSize(QSize(button->width(),button->height()));}
//初始化按钮
void MainWindow::initBtn()
{

     ui->musicList->hide();

    setBtnStyle(ui->prebtn,":/music_icons/last.png");
    setBtnStyle(ui->nextbtn,":/music_icons/next.png");
    setBtnStyle(ui->playbtn,":/music_icons/pause.png");
    setBtnStyle(ui->modebtn,":/music_icons/order.png");
    setBtnStyle(ui->listbtn,":/music_icons/playlist.png");

    connect(ui->playbtn,&QPushButton::clicked,this,&MainWindow::handlePlaySlot);
    connect(ui->modebtn,&QPushButton::clicked,this,&MainWindow::handleModeSlot);
    connect(ui->nextbtn,&QPushButton::clicked,this,&MainWindow::handleNextSlot);
    connect(ui->prebtn,&QPushButton::clicked,this,&MainWindow::handlePrevSlot);
    connect(ui->listbtn,&QPushButton::clicked,this,&MainWindow::handleMusicListSlot);
}


void MainWindow::setBackgroundColor(const QString &filename)
{
    //创建照片
    QPixmap pixmap(filename);
    //获取窗口大小
    QSize windowSize=this->size();
    //图片缩放☞当前大小
    QPixmap scalePixmap=pixmap.scaled(windowSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    //创建Qpattle对象并设置背景----调色板---
    QPalette palette =this->palette();
    palette.setBrush(QPalette::Window,QBrush(scalePixmap));
    //将调色板应用到窗口
    this->setPalette(palette);
}
void MainWindow::handlePlaySlot(){
    if(m_player->playbackState()==QMediaPlayer::PlayingState)
    {
        m_player->pause();
        ui->playbtn->setIcon(QIcon(":/music_icons/play.png"));
    }else{
        m_player->play();
        ui->playbtn->setIcon(QIcon(":/music_icons/pause.png"));
    }
}
void MainWindow::loadAppointedMusicDir(const QString& filepath){
    QDir dir(filepath);
    if(dir.exists()==false){
        QMessageBox::warning(this,"文件夹","文件打开失败");
        return ;//执行完没有return，说明文件存在
    }
    QFileInfoList fileList=dir.entryInfoList(QDir::Files);
    for(auto element:fileList){
        if(element.suffix()=="mp3"){
            ui->musicList->addItem(element.baseName());
        }
    }
}
void MainWindow::handleModeSlot(){
    if(m_mode==ORDER_MODE){
        m_mode=RANDOM_MODE;
        ui->modebtn->setIcon(QIcon(":/music_icons/random.png"));

    }
    else if(m_mode==RANDOM_MODE){
        m_mode=CIRCLE_MODE;
        ui->modebtn->setIcon(QIcon(":/music_icons/circle.png"));
    }
    else if(m_mode==CIRCLE_MODE){
        m_mode=ORDER_MODE;
        ui->modebtn->setIcon(QIcon(":/music_icons/order.png"));
    }
}

void MainWindow::startpalymusic(){
    //音乐名字
    QString musicname=ui->musicList->currentItem()->text();
    //音乐绝对路径
    QString musicAbsPath="D:/qtproj/qtmusicplayer/music/"+musicname+".mp3";
    m_player->setSource(QUrl::fromLocalFile(musicAbsPath));
    qDebug()<<musicAbsPath<<Qt::endl;
    m_player->play();
}
void MainWindow::handleNextSlot()
{
    int currentRow = ui->musicList->currentRow();
    int nextRow =0;
    if(m_mode==ORDER_MODE){
        nextRow=(currentRow+1)%ui->musicList->count();
    }else if(m_mode==RANDOM_MODE){
        int cnt=0;
        do{nextRow=rand()%ui->musicList->count();
            cnt++;
        }while(currentRow==nextRow&&cnt<=3);

    }else if(m_mode==CIRCLE_MODE){
        nextRow=currentRow;
    }
    ui->musicList->setCurrentRow(nextRow);
    startpalymusic();
}
void MainWindow::handlePrevSlot(){
    int currentRow = ui->musicList->currentRow();
    int prevRow = 0;
    if(m_mode==ORDER_MODE){
        prevRow=currentRow-1;
        if(prevRow<0){
            prevRow=ui->musicList->count()-1;
        }

    }else if(m_mode==RANDOM_MODE){
        int cnt=0;
        do{
            cnt++;
            prevRow=rand()%ui->musicList->count();
        }while(cnt<=3&&currentRow==prevRow);

    }else if(m_mode==CIRCLE_MODE){
        prevRow=currentRow;
    }
    ui->musicList->setCurrentRow(prevRow);
    startpalymusic();
}
//显示出场动画
void MainWindow::showAnimation(QWidget *window) {
    // 确保窗口可见（如果尚未显示）
    if (!window->isVisible()) {
        window->show();
    }

    QPropertyAnimation *animation = new QPropertyAnimation(window, "pos");  // 使用 new 避免局部对象过早销毁
    animation->setDuration(240);
    animation->setStartValue(QPoint(this->width(), 0));
    animation->setEndValue(QPoint(this->width() - ui->musicList->width(), 0));

    // 连接 finished 信号到槽（非阻塞等待）
    connect(animation, &QPropertyAnimation::finished, this, [this, animation, window]() {
        // 动画完成后执行后续逻辑，例如隐藏窗口或清理
        animation->deleteLater();  // 安全删除动画对象
        // 示例：window->hide(); 或其他操作
    });

    // 可选：连接 valueChanged 以监控进度（调试用）

    animation->start(QAbstractAnimation::DeleteWhenStopped);  // 自动删除（可选）
}

void MainWindow::handleMusicListSlot(){
    if(m_isShowFlag==false){
        showAnimation(ui->musicList);
        // ui->musicList->show();
        m_isShowFlag=true;
    }else if(m_isShowFlag==true){
        ui->musicList->hide();
        m_isShowFlag=false;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

