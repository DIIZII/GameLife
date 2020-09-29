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

/* Инициализация статической переменной класса.
 * Статическая переменная класса должна инициализироваться в обязательном порядке
 * */
int QDynamicButton::ResID = 0;
