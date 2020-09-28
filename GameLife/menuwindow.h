#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include "workwindow.h"


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

private:
    Ui::MenuWindow *ui;

    friend class std::shared_ptr<MenuWindow>;
    static std::shared_ptr<MenuWindow> m_instance;

};

void MenuWindowDelFunc(MenuWindow *p);

#endif // MENUWINDOW_H
