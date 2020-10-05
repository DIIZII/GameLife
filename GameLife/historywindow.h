#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QWidget>
#include "menuwindow.h"

namespace Ui {
class HistoryWindow;
}

class HistoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryWindow(QWidget *parent = nullptr);
    ~HistoryWindow();

    static std::shared_ptr<HistoryWindow> instance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HistoryWindow *ui;

    friend class std::shared_ptr<HistoryWindow>;
    static std::shared_ptr<HistoryWindow> m_instance;

};

void HistoryWindowDelFunc(HistoryWindow *p);

#endif // HISTORYWINDOW_H
