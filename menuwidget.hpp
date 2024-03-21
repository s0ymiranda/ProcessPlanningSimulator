#ifndef MENUWIDGET_HPP
#define MENUWIDGET_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

class MenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWidget(QWidget *parent = nullptr);
public:
    QVBoxLayout layout;
    /*QComboBox options;
    QPushButton start_simulation_btn;*/
    QPushButton FCFS;
    QPushButton RS;
    QPushButton PNE;
    QPushButton SJF;
    QPushButton RR;
    QPushButton SRTF;
    QPushButton PE;

private slots:
    void on_FCFS_pressed();
    void on_RS_pressed();
    void on_PNE_pressed();
    void on_SJF_pressed();
    void on_RR_pressed();
    void on_SRTF_pressed();
    void on_PE_pressed();
signals:
    void FCFS_pressed();
    void RS_pressed();
    void PNE_pressed();
    void SJF_pressed();
    void RR_pressed();
    void SRTF_pressed();
    void PE_pressed();
};

#endif // MENUWIDGET_HPP
