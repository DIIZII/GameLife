#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <iostream>
#include <QThread>

#include "menuwindow.h"
#include "qdynamicbutton.h"

namespace Ui {
class WorkWindow;
}

class WorkWindow : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)

public:
    explicit WorkWindow(QWidget *parent = nullptr);
    ~WorkWindow();

    static std::shared_ptr<WorkWindow> instance();

    bool running() const;

public slots:
    void setRunning(bool running);

signals:
    void finished();
    void runningChanged(bool running);

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonEnter_clicked();

    void deleteButtons(); // СЛОТ-обработчик нажатия кнопки удаления

    void slotGetNumber();           // СЛОТ для получения номера нажатой динамической кнопки

    void on_pushButtonStartStop_clicked();

    void on_pushButtonClear_clicked();

    void rungame();

private:
    Ui::WorkWindow *ui;

    QThread thread;

    friend class std::shared_ptr<WorkWindow>;
    static std::shared_ptr<WorkWindow> m_instance;

    void buildfield();
    void clearfield();
    void updatefield();

    size_t value_sizeX;
    size_t value_sizeY;

    void NextStepGame();
    bool m_running;
};

void WorkWindowDelFunc(WorkWindow *p);

#endif // WORKWINDOW_H
