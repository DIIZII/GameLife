#include "roleswindow.h"
#include "ui_roleswindow.h"

RolesWindow::RolesWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RolesWindow)
{
    ui->setupUi(this);
}

RolesWindow::~RolesWindow()
{
    delete ui;
}

void RolesWindowDelFunc(RolesWindow * p) { delete p;}

std::shared_ptr<RolesWindow> RolesWindow::m_instance;

std::shared_ptr<RolesWindow> RolesWindow::instance()
{
    if(!m_instance){
        m_instance.reset(new RolesWindow, RolesWindowDelFunc);
    }
    return m_instance;
}

void RolesWindow::on_pushButton_clicked()
{
    this->close();
    MenuWindow::instance()->show();
}
