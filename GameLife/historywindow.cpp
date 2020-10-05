#include "historywindow.h"
#include "ui_historywindow.h"

HistoryWindow::HistoryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryWindow)
{
    ui->setupUi(this);
}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}

void HistoryWindowDelFunc(HistoryWindow *p) { delete p;}

std::shared_ptr<HistoryWindow> HistoryWindow::m_instance;

std::shared_ptr<HistoryWindow> HistoryWindow::instance()
{
    if(!m_instance){
        m_instance.reset(new HistoryWindow, HistoryWindowDelFunc);
    }
    return m_instance;
}

void HistoryWindow::on_pushButton_clicked()
{
    this->close();
    MenuWindow::instance()->show();
}
