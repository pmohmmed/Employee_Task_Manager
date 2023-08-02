
#ifndef EMPLOYEE_TASK_MANAGER_FINAL_TASK_H
#define EMPLOYEE_TASK_MANAGER_FINAL_TASK_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Date
{
public:

    int year;
    int day;
    int month;
    Date();

};

// ===============================================================

class Task
{
private:
    string title, description;
    string employee_name;
    short priority; // 1 : 10
    Date assigning_date;
    Date ending_date;

public:
    // constructors
    Task();
    Task(string title, string description, string employee_name, short priority, Date assign_date, Date end_date);

    void set_title();
    void set_description();
    void set_employee_name();
    void set_assigning_date();
    void set_ending_date();
    void set_priority();
    // ----------------------------------
    string get_title();
    string get_description();
    string get_employee_name();
    Date get_assigning_date();
    Date get_ending_date();
    short get_priority();
    void info(); // all details
};

#endif //EMPLOYEE_TASK_MANAGER_FINAL_TASK_H
