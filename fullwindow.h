#ifndef FULLWINDOW_H
#define FULLWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QPainter>
#include <QPushButton>
#include <QAction>
#include <QHBoxLayout>

class FullWindow : public QWidget
{
    Q_OBJECT
private slots:
    void minimizeWindow() {
        this->showMinimized();  // 最小化窗口
    }

    void maximizeWindow() {
        if (this->isMaximized()) {
            this->showNormal();  // 如果窗口已经是最大化的，则恢复正常大小
        } else {
            this->showMaximized();  // 最大化窗口
        }
    }
public:
    FullWindow(QWidget *parent = nullptr);
    ~FullWindow();
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
private:
    QPixmap m_background;
    QFrame *frame;
    QWidget *MenuBar;
};
#endif // FULLWINDOW_H
