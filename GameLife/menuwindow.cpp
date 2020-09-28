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
