

#ifndef EMPLOYEE_TASK_MANAGER_FINAL_FUNCTIONS_H
#define EMPLOYEE_TASK_MANAGER_FINAL_FUNCTIONS_H


#include "Task.h"
#include <string>

using namespace std;

// defined in different file  " main "
extern vector <Task>  Priority_List;
extern queue  <Task>  Completed_Tasks;




void generate();
void add_task();
void edit();
void display_priority_list();
void display_completed_tasks();

// - update ( Completed task and Priority list )
// - reminder
void update();
void insertionSort();


#endif //EMPLOYEE_TASK_MANAGER_FINAL_FUNCTIONS_H
