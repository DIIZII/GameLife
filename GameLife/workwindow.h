#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <iostream>

#include "menuwindow.h"

struct ValueDynamicButtons
{
    bool value;
    size_t X;
    size_t Y;
};

typedef std::pair<ValueDynamicButtons,std::shared_ptr<QPushButton>> dynamic_button;

namespace Ui {
class WorkWindow;
}

class WorkWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WorkWindow(QWidget *parent = nullptr);
    ~WorkWindow();

    static std::shared_ptr<WorkWindow> instance();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonEnter_clicked();

private:
    Ui::WorkWindow *ui;

    friend class std::shared_ptr<WorkWindow>;
    static std::shared_ptr<WorkWindow> m_instance;

    void buildfield();
    void clearfield();

    std::vector<dynamic_button> vec_buttons;
    size_t value_sizeX;
    size_t value_sizeY;
};

void WorkWindowDelFunc(WorkWindow *p);

#endif // WORKWINDOW_H
