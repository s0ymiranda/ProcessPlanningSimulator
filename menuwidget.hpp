/*
    2024
    This file contains the declaration of the class MenuWidget.
    This widget is for showing the buttons for pick an algorithm
*/
#ifndef MENUWIDGET_HPP
#define MENUWIDGET_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <utils.hpp>

class MenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWidget(QWidget *parent = nullptr);
public:
    QVBoxLayout layout;
    QHBoxLayout settings_layout;

    //Buttons for each Algorithm
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
    void update_lambda(int);
    void update_tick(int);
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
