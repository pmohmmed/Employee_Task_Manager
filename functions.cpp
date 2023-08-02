
#include "functions.h"



void  add_task()
{


    Task new_task;


    new_task.set_title();
    new_task.set_description();
    new_task.set_employee_name();
    new_task.set_priority();
    new_task.set_assigning_date();
    new_task.set_ending_date();
    Priority_List.push_back(new_task);


    cout << "\n\n******************** Task added Successfully *******************\n";




}

void  display_priority_list() {

    cout <<   "\n\n\n======================== Priority list =========================\n\n";
    if (Priority_List.empty()) {

        cout <<     "                         No Data Found                          ";


        cout << "\n\n================================================================\n\n\n";
    }
    else { // display

        int size = Priority_List.size();
        for (int i = size -1; i>=0; i--)
        {
            Priority_List[i].info();
        }
    }



}

void  display_completed_tasks() {

    cout <<   "\n\n\n==================== Completed Tasks list ======================\n\n";

    if (Completed_Tasks.empty()) {

        cout <<     "                         No Data Found                          ";

        cout << "\n\n================================================================\n\n\n";

    }
    else
    {
        // To not remove the original data
        std::queue <Task> _copy = Completed_Tasks;

        while (!_copy.empty())
        {

            _copy.front().info();
            _copy.pop();
        }


    }




}

void  update()
{



    cout << "\n\n\n\n\n"
         << "================================================================\n\n";

    // display, move, remove
    if (!Priority_List.empty()) {

        // display the completed task
        if(Priority_List.size()>1){
            cout << "---------------: you've complete __ ";
            cout<< Priority_List[Priority_List.size() - 1].get_title()<<" __\n";

        }

        // add the task to completed tasks, then remove it from priority list
        Completed_Tasks.push(Priority_List[Priority_List.size() - 1]);
        Priority_List.pop_back();


        // reminder
        if (Priority_List.size())
        {
            int size = Priority_List.size();

            cout << "---------Notice: the next task is: ";
            cout << Priority_List[size - 1].get_title();

        }
        else
        {


            cout << "            Congratulation You've Completed all Tasks       ";

        }
    }
    else{

        cout << "                      No Tasks Found                        ";



    }

    cout << "\n\n"
         << "================================================================\n";


}

void  edit()
{

    int oper; // store the user choice
    int index = 0;
    bool found = false;


    while (true) {
        found = false;
        cout << "----------- To Choose an operation Enter it's number ----------\n";

        cout << "-change the Priority    : 1 " << endl;
        cout << "-change the End Date    : 2 " << endl;
        cout << "-change the Full Task   : 3 " << endl;
        cout << "-Back to the main menu  : 0 " << endl;
        cout << "==> ";
        cin >> oper;



        if (!oper) // 0
            break;

        else if(oper != 1 && oper != 2 && oper != 3){
            cout << "------------------------- invalid choice ----------------------\n";

            continue;

        }


        string name = "";         // title of the target task

        cout << "________________________________________________________________" << endl;
        cout << "Enter the Title of the Task: ";
        while (name == "" || name == "\n")
            getline(cin, name);


        for (int i = 0; i < Priority_List.size(); i++) {
            if (name == Priority_List[i].get_title()) {
                found = true;
                index = i;
                break;
            }

        }
        if (!found) {
            cout << "\n\n=====================This Task doesn't exist===================\n\n";
            continue;
        }

        cout <<     "\n\n=====================You are Editing The task===================\n\n";

        switch (oper) {
            case 1:

                Priority_List[index].set_priority();
                break;


            case 2:
                Priority_List[index].set_ending_date();
                break;

            case 3:

                Priority_List[index].set_title();
                Priority_List[index].set_description();
                Priority_List[index].set_employee_name();
                Priority_List[index].set_priority();
                Priority_List[index].set_assigning_date();
                Priority_List[index].set_ending_date();


                break;



        }
        cout << "\n\n*******************Operation Done Successfully******************\n\n";



        insertionSort();


    }

}

void  generate() {

    bool end_program = false;
    cout << "\n\n================================================================\n";

    cout <<     "____________Welcome to Employee Task manager project____________\n";

    cout <<     "================================================================\n";
    cout << "*\n";
    cout << "*\n";
    cout << "*\n";
    cout << "*\n";

    while (!end_program) {
        short choose;

        cout << "----------- To Choose an operation,  Enter it's number ---------\n";
        cout << "1 - Add  Task                     " << endl;
        cout << "2 - Edit Task                     " << endl;
        cout << "3 - Finish Task                   " << endl;
        cout << "4 - Display the Priority list     " << endl;
        cout << "5 - Display the Completed Tasks   " << endl;
        cout << "0 - Exit" << endl;
        cout << "==> ";
        cin >> choose;


        insertionSort();
        switch (choose) {
            case 0:
                end_program = true;
                break;
            case 1:
                add_task();
                break;
            case 2:
                edit();
                break;
            case 3:
                update();
                break;
            case 4:
                display_priority_list();
                break;
            case 5:
                display_completed_tasks();
                break;
            default:
                cout << "_____________Enter a valid operation number ( 0 - 5 )____________\n";



        }
        insertionSort();
    }




}

void  insertionSort()
{
    // part one
    int j = 0;
    for (int i = Priority_List.size() - 2; i >= 0; i--)
    {
        j = i;
        // put the biggest priority on the end of the vector
        while (Priority_List[j].get_priority() > Priority_List[j + 1].get_priority())
        {
            Task temp;
            temp = Priority_List[j];
            Priority_List[j] = Priority_List[j + 1];
            Priority_List[j + 1] = temp;
            j++;
            // to make sure that ( j + 1 ) is a valid index in priority list
            if (j >= Priority_List.size() - 1)
                break;



        }
    }

    // part two
    for (int i = Priority_List.size() - 2; i >= 0; i--) {

        j = i;
        if (Priority_List[j].get_priority() == Priority_List[j + 1].get_priority() ) {

            // put the lowest date on the end  ( when the priority are equal )
            // sort depend on ( year -- > month --> day --> first in first out  )
            while (j < Priority_List.size() - 1)
            {

                if (Priority_List[j].get_ending_date().year < Priority_List[j + 1].get_ending_date().year)
                {
                    swap(Priority_List[j], Priority_List[j + 1]);
                }
                else if (Priority_List[j].get_ending_date().year == Priority_List[j + 1].get_ending_date().year)
                {
                    if (Priority_List[j].get_ending_date().month < Priority_List[j + 1].get_ending_date().month)
                        swap(Priority_List[j], Priority_List[j + 1]);
                    else if (Priority_List[j].get_ending_date().month == Priority_List[j + 1].get_ending_date().month)
                    {
                        if (Priority_List[j].get_ending_date().day < Priority_List[j + 1].get_ending_date().day)
                        {
                            swap(Priority_List[j], Priority_List[j + 1]);
                        }
                        else if (Priority_List[j].get_ending_date().day == Priority_List[j + 1].get_ending_date().day)
                        {
                            // puts the first entered into the back of the list
                            swap(Priority_List[j], Priority_List[j + 1]);


                        }
                        else
                            break;
                    }
                    else
                        break;
                }
                else
                    break;

                j++;
            }
        }

    }
}

