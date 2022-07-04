#include "FramelessModel.h"

FramelessModel::FramelessModel(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);                //ȡ��������
																  // ȥ��������,ȥ���������������ö�
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);



}

void FramelessModel::region(const QPoint & currentGlobalPoint)
{
	// ��ȡ��������Ļ�ϵ�λ������topLeftΪ���Ͻǵ㣬rightButtonΪ���½ǵ�
	QRect rect = this->rect();

	QPoint topLeft = this->mapToGlobal(rect.topLeft()); //�����Ͻǵ�(0,0)ת��Ϊȫ������
	QPoint rightButton = this->mapToGlobal(rect.bottomRight());

	int x = currentGlobalPoint.x(); //��ǰ��������
	int y = currentGlobalPoint.y();

	if (((topLeft.x() + PADDING >= x) && (topLeft.x() <= x))
		&& ((topLeft.y() + PADDING >= y) && (topLeft.y() <= y)))
	{
		// ���Ͻ�
		dir = LEFTTOP;
		this->setCursor(QCursor(Qt::SizeFDiagCursor));  // ���ù����״
	}
	else if (((x >= rightButton.x() - PADDING) && (x <= rightButton.x()))
		&& ((y >= rightButton.y() - PADDING) && (y <= rightButton.y())))
	{
		// ���½�
		dir = RIGHTBOTTOM;
		this->setCursor(QCursor(Qt::SizeFDiagCursor));
	}
	else if (((x <= topLeft.x() + PADDING) && (x >= topLeft.x()))
		&& ((y >= rightButton.y() - PADDING) && (y <= rightButton.y())))
	{
		//���½�
		dir = LEFTBOTTOM;
		this->setCursor(QCursor(Qt::SizeBDiagCursor));
	}
	else if (((x <= rightButton.x()) && (x >= rightButton.x() - PADDING))
		&& ((y >= topLeft.y()) && (y <= topLeft.y() + PADDING)))
	{
		// ���Ͻ�
		dir = RIGHTTOP;
		this->setCursor(QCursor(Qt::SizeBDiagCursor));
	}
	else if ((x <= topLeft.x() + PADDING) && (x >= topLeft.x()))
	{
		// ���
		dir = LEFT;
		this->setCursor(QCursor(Qt::SizeHorCursor));
	}
	else if ((x <= rightButton.x()) && (x >= rightButton.x() - PADDING))
	{
		// �ұ�
		dir = RIGHT;
		this->setCursor(QCursor(Qt::SizeHorCursor));
	}
	else if ((y >= topLeft.y()) && (y <= topLeft.y() + PADDING))
	{
		// �ϱ�
		dir = UP;
		this->setCursor(QCursor(Qt::SizeVerCursor));
	}
	else if ((y <= rightButton.y()) && (y >= rightButton.y() - PADDING))
	{
		// �±�
		dir = DOWN;
		this->setCursor(QCursor(Qt::SizeVerCursor));
	}
	else
	{
		// Ĭ��
		dir = NONE;
		this->setCursor(QCursor(Qt::ArrowCursor));
	}

}

void FramelessModel::mousePressEvent(QMouseEvent * event)
{
	switch (event->button())
	{
	case Qt::LeftButton:
		isLeftPressDown = true;

		if (dir != NONE)
		{
			this->mouseGrabber(); //���ص�ǰץȡ�������Ĵ���
		}
		else
		{
			m_movePoint = event->globalPos() - this->frameGeometry().topLeft();
			//globalPos()���λ�ã�topLeft()�������Ͻǵ�λ��
		}
		break;
	case Qt::RightButton:
		//this->setWindowState(Qt::WindowMinimized);
		break;
	default:
		FramelessModel::mousePressEvent(event);
	}
 
}

void FramelessModel::mouseMoveEvent(QMouseEvent * event)
{
	QPoint globalPoint = event->globalPos();   //���ȫ������

	QRect rect = this->rect();  //rect == QRect(0,0 1280x720)
	QPoint topLeft = mapToGlobal(rect.topLeft());
	QPoint bottomRight = mapToGlobal(rect.bottomRight());

	if (this->windowState() != Qt::WindowMaximized)
	{
		if (!isLeftPressDown)  //û�а������ʱ
		{
			this->region(globalPoint); //���ڴ�С�ĸı䡪���ж����λ�ã��ı�����״
		}
		else
		{
			if (dir != NONE)
			{
				QRect newRect(topLeft, bottomRight); //����һ������  �϶������1000*1618

				switch (dir)
				{
				case LEFT:

					if (bottomRight.x() - globalPoint.x() <= this->minimumWidth())
					{
						newRect.setLeft(topLeft.x());  //С�ڽ������С���ʱ������Ϊ���ϽǺ�����Ϊ����x
													   //ֻ�ı���߽�
					}
					else
					{
						newRect.setLeft(globalPoint.x());
					}
					break;
				case RIGHT:
					newRect.setWidth(globalPoint.x() - topLeft.x());  //ֻ�ܸı��ұ߽�
					break;
				case UP:
					if (bottomRight.y() - globalPoint.y() <= this->minimumHeight())
					{
						newRect.setY(topLeft.y());
					}
					else
					{
						newRect.setY(globalPoint.y());
					}
					break;
				case DOWN:
					newRect.setHeight(globalPoint.y() - topLeft.y());
					break;
				case LEFTTOP:
					if (bottomRight.x() - globalPoint.x() <= this->minimumWidth())
					{
						newRect.setX(topLeft.x());
					}
					else
					{
						newRect.setX(globalPoint.x());
					}

					if (bottomRight.y() - globalPoint.y() <= this->minimumHeight())
					{
						newRect.setY(topLeft.y());
					}
					else
					{
						newRect.setY(globalPoint.y());
					}
					break;
				case RIGHTTOP:
					if (globalPoint.x() - topLeft.x() >= this->minimumWidth())
					{
						newRect.setWidth(globalPoint.x() - topLeft.x());
					}
					else
					{
						newRect.setWidth(bottomRight.x() - topLeft.x());
					}
					if (bottomRight.y() - globalPoint.y() >= this->minimumHeight())
					{
						newRect.setY(globalPoint.y());
					}
					else
					{
						newRect.setY(topLeft.y());
					}
					break;
				case LEFTBOTTOM:
					if (bottomRight.x() - globalPoint.x() >= this->minimumWidth())
					{
						newRect.setX(globalPoint.x());
					}
					else
					{
						newRect.setX(topLeft.x());
					}
					if (globalPoint.y() - topLeft.y() >= this->minimumHeight())
					{
						newRect.setHeight(globalPoint.y() - topLeft.y());
					}
					else
					{
						newRect.setHeight(bottomRight.y() - topLeft.y());
					}
					break;
				case RIGHTBOTTOM:
					newRect.setWidth(globalPoint.x() - topLeft.x());
					newRect.setHeight(globalPoint.y() - topLeft.y());
					break;
				default:
					break;
				}
				this->setGeometry(newRect);
			}
			else
			{
				move(event->globalPos() - m_movePoint); //�ƶ�����
				event->accept();
			}
		}
	}

}

void FramelessModel::mouseReleaseEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{
		isLeftPressDown = false;
		if (dir != NONE)
		{
			this->releaseMouse(); //�ͷ����ץȡ
			this->setCursor(QCursor(Qt::ArrowCursor));
			dir = NONE; //��������ָ��
		}
	}

}
