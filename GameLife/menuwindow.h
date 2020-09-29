#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include "workwindow.h"
#include "roleswindow.h"
#include "historywindow.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

    static std::shared_ptr<MenuWindow> instance();

private slots:
    void on_pushButtonPlay_clicked();

    void on_pushButtonRoles_clicked();

    void on_pushButtonHistory_clicked();

    void on_pushButtonDeveloper_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MenuWindow *ui;

    friend class std::shared_ptr<MenuWindow>;
    static std::shared_ptr<MenuWindow> m_instance;

};

void MenuWindowDelFunc(MenuWindow *p);

#endif // MENUWINDOW_H
