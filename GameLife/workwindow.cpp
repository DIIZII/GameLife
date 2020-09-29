#include "workwindow.h"
#include "ui_workwindow.h"

WorkWindow::WorkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkWindow)
{
    ui->setupUi(this);

    buildfield();
}

WorkWindow::~WorkWindow()
{
    delete ui;
}

void WorkWindowDelFunc(WorkWindow *p) { delete p;}

std::shared_ptr<WorkWindow> WorkWindow::m_instance;

std::shared_ptr<WorkWindow> WorkWindow::instance()
{
    if(!m_instance){
        m_instance.reset(new WorkWindow, WorkWindowDelFunc);
    }
    return m_instance;
}

void WorkWindow::on_pushButtonBack_clicked()
{
    this->close();//hide
    MenuWindow::instance()->show();
}

void WorkWindow::buildfield()
{
    value_sizeX = static_cast<size_t>( ui->spinBoxX->value() );
    value_sizeY = static_cast<size_t>( ui->spinBoxY->value() );

    for(size_t tmp_x = 0;tmp_x < value_sizeX; tmp_x++)
    {
        for(size_t tmp_y = 0; tmp_y < value_sizeY;tmp_y++)
        {
            QDynamicButton *button = new QDynamicButton(this);  // Создаем объект динамической кнопки
            /* Добавляем кнопку в слой с вертикальной компоновкой
            * */
            ui->gridLayoutView->addWidget(button,tmp_x,tmp_y);
            /* Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
            * */
            connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
        }

    }
}

void WorkWindow::clearfield()
{
}

void WorkWindow::updatefield()
{
    for(size_t i = 0; i < value_sizeX; i++)
    {
        for(size_t j = 0; j < value_sizeY; j++)
        {
            QDynamicButton *buttonRes = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAtPosition(i,j)->widget());
            if(buttonRes->Live)
                buttonRes->setStyleSheet(" background-color: rgb( 0, 0, 0)");
            else
                buttonRes->setStyleSheet(" background-color: rgb( 255, 255, 255)");
        }
    }
}

void WorkWindow::NextStepGame()
{
    for(size_t i = 0; i < value_sizeX; i++)
    {
        for(size_t j = 0; j < value_sizeY; j++)
        {
            QDynamicButton *buttonRes = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAtPosition(i,j)->widget());

            size_t tmp_i = buttonRes->CheckSize(i-1,value_sizeX);
            size_t tmp_j = buttonRes->CheckSize(j,value_sizeY);
            QDynamicButton *button1 = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAtPosition(tmp_i,tmp_j)->widget());

            tmp_i = buttonRes->CheckSize(i-1,value_sizeX);
            tmp_j = buttonRes->CheckSize(j+1,value_sizeY);
            QDynamicButton *button2 = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAtPosition(tmp_i,tmp_j)->widget());

            tmp_i = buttonRes->CheckSize(i,value_sizeX);
            tmp_j = buttonRes->CheckSize(j+1,value_sizeY);
            QDynamicButton *button3 = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAtPosition(tmp_i,tmp_j)->widget());

            tmp_i = buttonRes->CheckSize(i+1,value_sizeX);
            tmp_j = buttonRes->CheckSize(j+1,value_sizeY);
            QDynamicButton *button4 = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAtPosition(tmp_i,tmp_j)->widget());

            tmp_i = buttonRes->CheckSize(i+1,value_sizeX);
            tmp_j = buttonRes->CheckSize(j,value_sizeY);
            QDynamicButton *button5 = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAtPosition(tmp_i,tmp_j)->widget());

            tmp_i = buttonRes->CheckSize(i+1,value_sizeX);
            tmp_j = buttonRes->CheckSize(j-1,value_sizeY);
            QDynamicButton *button6 = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAtPosition(tmp_i,tmp_j)->widget());

            tmp_i = buttonRes->CheckSize(i,value_sizeX);
            tmp_j = buttonRes->CheckSize(j-1,value_sizeY);
            QDynamicButton *button7 = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAtPosition(tmp_i,tmp_j)->widget());

            tmp_i = buttonRes->CheckSize(i-1,value_sizeX);
            tmp_j = buttonRes->CheckSize(j-1,value_sizeY);
            QDynamicButton *button8 = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAtPosition(tmp_i,tmp_j)->widget());

            buttonRes->NeighborsLive = button1->Live
                    + button2->Live
                    + button3->Live
                    + button4->Live
                    + button5->Live
                    + button6->Live
                    + button7->Live
                    + button8->Live;
            buttonRes->NextLive = buttonRes->ResultStep(buttonRes->NeighborsLive,buttonRes->Live);
        }
    }

    for(size_t i = 0; i < value_sizeX; i++)
    {
        for(size_t j = 0; j < value_sizeY; j++)
        {
            QDynamicButton *buttonRes = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAtPosition(i,j)->widget());
            buttonRes->Live = buttonRes->NextLive;
        }
    }
    updatefield();
}

void WorkWindow::on_pushButtonEnter_clicked()
{
    if(value_sizeX != static_cast<size_t>( ui->spinBoxX->value() ) ||
            value_sizeY != static_cast<size_t>( ui->spinBoxY->value() ))
    {
        deleteButtons();
        buildfield();
    }

}

void WorkWindow::deleteButtons()
{
//    /* Выполняем перебор всех элементов слоя, где располагаются динамические кнопки
//     * */
//    for(int i = 0; i < ui->gridLayoutView->rowCount() * ui->gridLayoutView->columnCount() - 1; i++ )
//    {
//        /* Производим каст элемента слоя в объект динамической кнопки
//         * */
//        QDynamicButton *button = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAt(0)->widget());
//        /* Если номер кнопки соответствует числу, которое установлено
//         * в lineEdit, то производим удаление данной кнопки
//         * */
//        std::cout << button->getID() << std::endl;
//        button->hide();
//        delete button;
//    }
//    QDynamicButton::ResID = 0;

    if(QDynamicButton::ResID != 0)
    {
        for(size_t i = 0; i < value_sizeX; i++)
        {
            for (size_t j = 0; j < value_sizeY; j++)
            {
                QDynamicButton *button = qobject_cast<QDynamicButton*>(ui->gridLayoutView->itemAtPosition(i,j)->widget());
                std::cout << button->getID() << std::endl;
                if(button->getID())
                {
                    button->hide();
                    delete button;
                }
            }
        }
    }
    QDynamicButton::ResID = 0;
    std::cout << ui->gridLayoutView->rowCount() << " " << ui->gridLayoutView->columnCount() << std::endl;
    std::cout << ui->gridLayoutView->rowCount() << " " << ui->gridLayoutView->columnCount() << std::endl;

}

void WorkWindow::slotGetNumber()
{
    QDynamicButton *button = (QDynamicButton*) sender();
    if(button->Live)
    {
        button->setStyleSheet(" background-color: rgb( 255, 255, 255)");
        button->Live = false;
    }
    else
    {
        button->setStyleSheet(" background-color: rgb( 0, 0, 0)");
        button->Live = true;
    }

}

void WorkWindow::on_pushButtonStartStop_clicked()
{
    if(ui->pushButtonStartStop->text() == "Старт")
        ui->pushButtonStartStop->setText("Стоп");
    else if(ui->pushButtonStartStop->text() == "Стоп")
        ui->pushButtonStartStop->setText("Старт");
    else
        std::cout << "Error" << std::endl;

    int step = 0;
    while (step < 1000)
    {
        NextStepGame();
        step++;
        std::cout << step << std::endl;
    }
}
