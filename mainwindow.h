#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
enum PLAY_MODE{
    ORDER_MODE,
    RANDOM_MODE,
    CIRCLE_MODE,
};
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void handlePlaySlot();
    void handleModeSlot();
    void handleNextSlot();
    void handlePrevSlot();
    void handleMusicListSlot();
private:
    Ui::MainWindow *ui;
    QMediaPlayer *m_player;
    //当前播放模式
    PLAY_MODE m_mode;
    bool m_isShowFlag=false;
    //音乐绝对路径
    QString  musicDir;
private:
    //设置按钮样式
    void setBtnStyle(QPushButton *button,const QString & filename);
    //初始化按钮
    void initBtn();
    void showAnimation(QWidget * window);


private :
    //设置窗口背景
    void setBackgroundColor(const QString &filename);
    //加载音乐路径
    void loadAppointedMusicDir(const QString& filepath);
    void startpalymusic();

};
#endif // MAINWINDOW_H
