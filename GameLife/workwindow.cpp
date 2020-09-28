#include "workwindow.h"
#include "ui_workwindow.h"

WorkWindow::WorkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkWindow)
{
    ui->setupUi(this);
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
