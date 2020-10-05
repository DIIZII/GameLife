#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindowDelFunc(MenuWindow *p) { delete p;}

std::shared_ptr<MenuWindow> MenuWindow::m_instance;

std::shared_ptr<MenuWindow> MenuWindow::instance()
{
    if(!m_instance){
        m_instance.reset(new MenuWindow, MenuWindowDelFunc);
    }
    return m_instance;
}

void MenuWindow::on_pushButtonPlay_clicked()
{
    this->close();//hide
    WorkWindow::instance()->show();
}

void MenuWindow::on_pushButtonRoles_clicked()
{
    this->close();
    RolesWindow::instance()->show();
}

void MenuWindow::on_pushButtonHistory_clicked()
{
    this->close();
    HistoryWindow::instance()->show();
}

void MenuWindow::on_pushButtonDeveloper_clicked()
{
    QMessageBox::about(this,"Разработчик","     DIIZII    (Дмитрий Зяблев)\nПрограмма сделанная за 2 дня(29 и 30 сентября 2020 года) с кучей багов((((\nКак я буду писать через 5 лет) проверим)))) ");
}

void MenuWindow::on_pushButton_5_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Выход","Вы действтельно хотите выйти из приложения",QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
        this->close();

}
