// Данные про вид
// Данный класс не имеет отношения к Qt, его внутренностям и прочей фигне,
// о чем вы могли подумать

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

        void setName (QString name); // Задать имя вида
        QString getName (); // Получить имя вида

        void setCount (int count); // Задать количество потомков
        int getCount (); // Получить количество потомков

        void setImgs (QVector <QPixmap> imgs);
        QPixmap getImg (int index);

        bool getPainted(); // Отрисован ли объект
        void setPainted(bool isPainted); // Задать отрисовку объекта

        bool getEdited(); // Нуждаеться ли объект в перерисовке
        void setEdited(bool isEdited);
    private:
        QString name; // Должно быть уникальным и желательно на латинице, второе еще не доказано
        int count; // Количество потомков. count >= 1
        QVector <QPixmap> imgs; // Картинки спрайтов, нулевая картинка - стандартная
        //QMap <int, coordinates> positions; // Координаты спрайтов
        bool isPainted;
        bool isEdited;

};

#endif // QCLASS_H
