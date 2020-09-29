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

    for(size_t tmp_x = 0; tmp_x < value_sizeX; tmp_x++)
    {
        for(size_t tmp_y = 0; tmp_y < value_sizeY; tmp_y++)
        {
            ValueDynamicButtons vdb;
            vdb.value = false;
            vdb.X = tmp_x;
            vdb.Y = tmp_y;
            std::shared_ptr<QPushButton> newbutton(new QPushButton);
            vec_buttons.push_back(std::make_pair(vdb,newbutton));
            ui->gridLayoutView->addWidget(vec_buttons[vec_buttons.size() - 1].second.get(),
                    vec_buttons[vec_buttons.size() - 1].first.X,
                    vec_buttons[vec_buttons.size() - 1].first.Y);
        }
    }
}

void WorkWindow::clearfield()
{
    vec_buttons.clear();
}

void WorkWindow::on_pushButtonEnter_clicked()
{
    clearfield();
    buildfield();
}
