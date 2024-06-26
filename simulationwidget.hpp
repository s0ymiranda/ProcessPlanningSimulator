/*
    2024
    This file contains the declaration of the class SimulationWidget.
    This widget is for the simulation.
*/
#ifndef SIMULATIONWIDGET_HPP
#define SIMULATIONWIDGET_HPP

#include <algorithms.hpp>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QFrame>
#include <sstream>
#include <QLabel>
#include <unordered_set>
#include <string>

class SimulationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationWidget(AlgorithmType, QWidget *parent = nullptr);
    void create_threads();
    void style_layouts();
    ~SimulationWidget();

private:
    //layouts
    QVBoxLayout layout;
    QHBoxLayout processes_layout;
    QVBoxLayout title;
    QHBoxLayout processes_title_layout;
    QHBoxLayout report_layout;
    QHBoxLayout buttons_layout;

    QVBoxLayout time_layout;
    QVBoxLayout cpu_layout;
    QVBoxLayout created_layout;
    QVBoxLayout completed_layout;
    QVBoxLayout blocked_layout;
    QVBoxLayout waited_layout;
    QVBoxLayout execute_layout;
    QVBoxLayout blocked_t_layout;

    //title
    QLabel *title_l = new QLabel("title");

    //Lists
    QListWidget processes_list;
    QListWidget current_list;
    QListWidget completed_list;
    QListWidget blocked_list;

    //buttons
    QPushButton button_close;
    QPushButton button_stop;

    //labels for tittle report
    QLabel *total_time_t = new QLabel("Time(ms): ");
    QLabel *CPU_usage_t = new QLabel("CPU usage(%): ");
    QLabel *total_process_created_t = new QLabel("Process Created: ");
    QLabel *total_process_completed_t = new QLabel("Process completed: ");
    QLabel *total_process_blocked_t = new QLabel("Process Blocked: ");
    QLabel *average_waited_time_t = new QLabel("Average Waited Time: ");
    QLabel *average_executed_time_t = new QLabel("Average Executed Time: ");
    QLabel *average_blocked_time_t = new QLabel("Average blocked time");

    //labels for reports
    QLabel *total_time = new QLabel("Time: ");
    QLabel *CPU_usage = new QLabel("CPU usage");
    QLabel *total_process_created = new QLabel("Process Created: ");
    QLabel *total_process_completed = new QLabel("Process completed: ");
    QLabel *total_process_blocked = new QLabel("Process Blocked: ");
    QLabel *average_waited_time = new QLabel("Average Waited Time: ");
    QLabel *average_executed_time = new QLabel("Average Executed Time: ");
    QLabel *average_blocked_time = new QLabel("Average blocked time");

    //algorithm
    std::shared_ptr<Algorithm> algorithm;

    //threads
    std::thread processes;
    std::thread processes_creator;
    std::thread modify_process_list;
    std::thread modify_current_list;
    std::thread modify_completed_list;
    std::thread modify_blocked_list;
    std::thread blocked_thread;

    bool simulation_closed{false};

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point;//start time point of the simulation
    std::chrono::time_point<std::chrono::high_resolution_clock> end_point;//end time point of the simulation
private slots:
    void on_button_close_pressed();
    void on_button_stop_pressed();

signals:
    void button_close_pressed();
    void button_stop_pressed();
};

#endif // SIMULATIONWIDGET_HPP
