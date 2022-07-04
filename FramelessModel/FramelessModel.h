#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FramelessModel.h"
#include "qevent.h"
#include "define.h"

//����һ���ޱ߿����ģ��
class FramelessModel : public QMainWindow
{
    Q_OBJECT

public:
    FramelessModel(QWidget *parent = Q_NULLPTR);

private:
    Ui::FramelessModelClass ui;










public:
	void region(const QPoint &currentGlobalPoint);  //����λ��,�ı���
protected:
	//��갴���ƶ����ͷ��¼�
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	QPoint m_movePoint;  //����λ��
	bool isLeftPressDown;  // �ж�����Ƿ���
	Direction dir;        // ���ڴ�С�ı�ʱ����¼�ı䷽��

};
