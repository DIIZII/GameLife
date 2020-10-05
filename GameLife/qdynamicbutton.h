#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QPushButton>

class QDynamicButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QDynamicButton(QWidget *parent = 0);
    ~QDynamicButton();
    static int ResID;   // Статическая переменная, счетчик номеров кнопок
    int getID();        // Функция для возврата локального номера кнопки
    bool Live = false;
    bool NextLive = Live;
    size_t NeighborsLive = 0;

    size_t CheckSize(size_t Count, size_t Size);

    bool ResultStep(size_t Result, bool Live);

public slots:

private:
    int buttonID = 0;   // Локальная переменная, номер кнопки
};

#endif // QDYNAMICBUTTON_H
