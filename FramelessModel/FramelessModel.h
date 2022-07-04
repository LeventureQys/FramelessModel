#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FramelessModel.h"
#include "qevent.h"
#include "define.h"

//这是一个无边框软件模板
class FramelessModel : public QMainWindow
{
    Q_OBJECT

public:
    FramelessModel(QWidget *parent = Q_NULLPTR);

private:
    Ui::FramelessModelClass ui;










public:
	void region(const QPoint &currentGlobalPoint);  //鼠标的位置,改变光标
protected:
	//鼠标按下移动及释放事件
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	QPoint m_movePoint;  //鼠标的位置
	bool isLeftPressDown;  // 判断左键是否按下
	Direction dir;        // 窗口大小改变时，记录改变方向

};
