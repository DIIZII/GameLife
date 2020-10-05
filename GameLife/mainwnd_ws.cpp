#include "mainwnd_ws.h"

MainWnd_WS::MainWnd_WS()
{
    MenuWindow::instance()->show();
}

MainWnd_WS::~MainWnd_WS()
{

}

void MainWnd_WSDelFunc(MainWnd_WS * p) { delete p;}

std::shared_ptr<MainWnd_WS> MainWnd_WS::m_instance;

std::shared_ptr<MainWnd_WS> MainWnd_WS::instance()
{
    if(!m_instance){
        m_instance.reset(new MainWnd_WS, MainWnd_WSDelFunc);
    }
    return m_instance;
}
