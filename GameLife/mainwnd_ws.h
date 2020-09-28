#ifndef MAINWND_WS_H
#define MAINWND_WS_H

#include "menuwindow.h"
#include "iostream"
#include "menuwindow.h"

class MainWnd_WS
{

public:

    MainWnd_WS();
    ~MainWnd_WS();

    static std::shared_ptr<MainWnd_WS> instance();

private:

    friend class std::shared_ptr<MainWnd_WS>;
    static std::shared_ptr<MainWnd_WS> m_instance;

};

void MainWnd_WSDelFunc(MainWnd_WS *p);

#endif // MAINWND_WS_H
