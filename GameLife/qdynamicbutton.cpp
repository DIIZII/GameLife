#include "qdynamicbutton.h"

QDynamicButton::QDynamicButton(QWidget *parent) :
    QPushButton(parent)
{
    ResID++;            // Увеличение счетчика на единицу
    buttonID = ResID;   /* Присвоение кнопке номера, по которому будет производиться
                         * дальнейшая работа с кнопок
                         * */
    QDynamicButton::setMinimumSize(20,20);
    QDynamicButton::setStyleSheet(" background-color: rgb( 255, 255, 255)");
}

QDynamicButton::~QDynamicButton()
{

}

/* Метод для возврата значения номера кнопки
 * */
int QDynamicButton::getID()
{
    return buttonID;
}

size_t QDynamicButton::CheckSize(size_t Count, size_t Size)
{
    if(Count >= Size) return 0;
    else if (Count < 0) return Size - 1;
    else return Count;
}

bool QDynamicButton::ResultStep(size_t Result, bool Live)
{
    if((Result == 2 && Live) || (Result == 3 && Live))
        return true;
    else if(Result == 3 && !Live)
        return true;
    else
        return false;
}

/* Инициализация статической переменной класса.
 * Статическая переменная класса должна инициализироваться в обязательном порядке
 * */
int QDynamicButton::ResID = 0;
