#ifndef ROLESWINDOW_H
#define ROLESWINDOW_H

#include <QWidget>

#include "menuwindow.h"

namespace Ui {
class RolesWindow;
}

class RolesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RolesWindow(QWidget *parent = nullptr);
    ~RolesWindow();

    static std::shared_ptr<RolesWindow> instance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RolesWindow *ui;

    friend class std::shared_ptr<RolesWindow>;
    static std::shared_ptr<RolesWindow> m_instance;

};

void RolesWindowDelFunc(RolesWindow *p);

#endif // ROLESWINDOW_H
