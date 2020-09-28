#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include <QWidget>
#include "menuwindow.h"

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

private:
    Ui::WorkWindow *ui;

    friend class std::shared_ptr<WorkWindow>;
    static std::shared_ptr<WorkWindow> m_instance;

};

void WorkWindowDelFunc(WorkWindow *p);

#endif // WORKWINDOW_H
