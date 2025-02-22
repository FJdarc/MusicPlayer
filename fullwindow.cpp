#include "fullwindow.h"

FullWindow::FullWindow(QWidget *parent)
    : QWidget(parent),
      m_background(":/images/holo.jpg"),
      frame(new QFrame(this)),
      MenuBar(new QWidget(frame))
{
    this->resize(1080,720);
    this->setMinimumSize(1080, 720);
    this->setWindowFlags(Qt::FramelessWindowHint);//无边框窗口

    QHBoxLayout *layout = new QHBoxLayout(MenuBar);
    layout->addStretch();
    QPushButton *close = new QPushButton("X");
    close->setFixedSize(25,25);
    QObject::connect(close, &QPushButton::clicked, this, &FullWindow::close);
    QPushButton *maximize = new QPushButton("+", this);
    maximize->setFixedSize(25, 25);
    connect(maximize, &QPushButton::clicked, this, &FullWindow::maximizeWindow);
    QPushButton *minimize = new QPushButton("-", this);
    minimize->setFixedSize(25, 25);
    connect(minimize, &QPushButton::clicked, this, &FullWindow::minimizeWindow);
    layout->addWidget(minimize);
    layout->addWidget(maximize);
    layout->addWidget(close);
}

FullWindow::~FullWindow() {}

void FullWindow::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QSize scaledSize = m_background.size().scaled(this->size(), Qt::KeepAspectRatioByExpanding);//获取缩放尺寸
    QRect targetRect(QPoint(0, 0), scaledSize);
    targetRect.moveCenter(this->rect().center());//与主窗口中心点对齐
    painter.drawPixmap(targetRect, m_background);
}

void FullWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    update();
    frame->resize(this->size());
    MenuBar->resize(this->width(), 60);
}
