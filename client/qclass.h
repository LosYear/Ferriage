// ������ ��� ���
// ������ ����� �� ����� ��������� � Qt, ��� ������������� � ������ �����,
// � ��� �� ����� ��������

#ifndef QCLASS_H
#define QCLASS_H

#define coordinate QPair<int, int>
#define coordinates QPair<coordinate, coordinate>

#include <QString>
#include <QVector>
#include <QLabel>
#include <QMap>
#include <QPair>

using namespace std;

class QClass
{
    public:
        QClass();

        void setName (QString name); // ������ ��� ����
        QString getName (); // �������� ��� ����

        void setCount (int count); // ������ ���������� ��������
        int getCount (); // �������� ���������� ��������

        void setImgs (QVector <QPixmap> imgs);
        QPixmap getImg (int index);

        bool getPainted(); // ��������� �� ������
        void setPainted(bool isPainted); // ������ ��������� �������

        bool getEdited(); // ���������� �� ������ � �����������
        void setEdited(bool isEdited);
    private:
        QString name; // ������ ���� ���������� � ���������� �� ��������, ������ ��� �� ��������
        int count; // ���������� ��������. count >= 1
        QVector <QPixmap> imgs; // �������� ��������, ������� �������� - �����������
        //QMap <int, coordinates> positions; // ���������� ��������
        bool isPainted;
        bool isEdited;

};

#endif // QCLASS_H
