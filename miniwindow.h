#ifndef MINIWINDOW_H
#define MINIWINDOW_H

#include <QWidget>

class MiniWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MiniWindow(QWidget *parent = nullptr);

signals:
};

#endif // MINIWINDOW_H
