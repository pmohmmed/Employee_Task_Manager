

#include "Task.h"

extern vector <Task>  Priority_List;
extern queue  <Task>  Completed_Tasks;

using namespace std;
Date::Date()
{
    year  = 0;
    month = 0;
    day   = 0;
}
Date not_set;


Task::Task()
{

    this->title          = "N/A";
    this->description    = "N/A";
    this->employee_name  = "N/A";
    this->priority       = 0;
    this->assigning_date = not_set;
    this->ending_date    = not_set;

}


Task::Task(string title, string description, string employee_name, short priority, Date assign_date, Date end_date)
{

    this->title          = title;
    this->description    = description;
    this->employee_name  = employee_name;
    this->priority       = priority;
    this->assigning_date = assign_date;
    this->ending_date    = end_date;

}

// Setters
void Task::set_title(){
    bool found = true;
    string title = "";
    cout << "Enter the Task tile: ";

    // make sure that this title is valid
    while(found){

        found = false;
        getline(cin, title );
        while(title == "\n"  ||  title == " " ||  title == "") // ignore unexpected input
            getline(cin, title );




        // search for the title
        for(int i=0;i<Priority_List.size();i++){
            if(Priority_List[i].get_title() == title)
            {
                found = true;
                break;
            }

        }

        if(found){

            cout<<"----------------- This task is already exist ------------------\n";
            cout <<"Enter another title: ";

        }



    }
    this->title  = title;



}

void Task::set_description() {
    string desc = "";
    cout << "Enter the Task Description: ";
    while(desc == "\n" || desc == "" || desc == " ") // ignore unexpected input
        getline(cin, desc);

    this->description = desc;

}

void Task::set_employee_name() {
    string   emp_name =  "";
    cout << "Enter the Employee Name: ";
    while(emp_name == "\n" || emp_name == "" || emp_name == " ")// ignore unexpected input
        getline(cin, emp_name);


    this->employee_name = emp_name;

}

void Task::set_assigning_date(){


    cout << "\n\n-----------------The Assigning Date of the Task------------------\n";


    cout << "Day: ";
    cin >>this->assigning_date.day;


    // check the validation of day
    while(this->assigning_date.day <= 0 || this->assigning_date.day >31){
        cout<< "\n-----------------------------------------------------------------\n";

        cout<<"Enter a valid day: ";
        cin>>this->assigning_date.day;

    }



    cout<< "\n-----------------------------------------------------------------\n";

    cout << "Month: ";
    cin >>assigning_date.month;

    // check the validation of month
    while(this->assigning_date.month <= 0 || this->assigning_date.month >12){
        cout<< "\n-----------------------------------------------------------------\n";

        cout<<"Enter a valid month: ";
        cin>>this->assigning_date.month;

    }



    cout<< "\n-----------------------------------------------------------------\n";

    cout << "Year: ";
    cin >>assigning_date.year;

    // check the validation of year
    while(this->assigning_date.year > 2022 || this->assigning_date.year < 1600){
        cout<< "\n-----------------------------------------------------------------\n";

        cout<<"year should be between (1600 - 2022)\n";
        cout<<"Enter a valid year: ";
        cin>>this->assigning_date.year;

    }




}

void Task::set_ending_date(){

    cout << "\n\n\n-------------------The Ending Date of the Task-------------------\n";



    bool valid = false;
    while(true){ // will break when the user enter a valid date


        cout << "Day: ";
        cin >>this->ending_date.day;

        // check the validation of day
        while(this->ending_date.day <= 0 || this->ending_date.day > 31){
            cout<< "\n-----------------------------------------------------------------\n";
            cout<<"Enter a valid day: ";
            cin>>this->ending_date.day;

        }


        cout<< "\n-----------------------------------------------------------------\n";
        cout << "Month: ";
        cin >>ending_date.month;

        // check the validation of month
        while(this->ending_date.month <= 0 || this->ending_date.month > 12){
            cout<< "\n-----------------------------------------------------------------\n";

            cout<<"Enter a valid month: ";
            cin>>this->ending_date.month;

        }


        cout<< "\n-----------------------------------------------------------------\n";

        cout << "Year: ";
        cin >>ending_date.year;

        // check the validation of year
        while(this->ending_date.year > 9999 || this->ending_date.year < 1600){
            cout<< "\n-----------------------------------------------------------------\n";

            cout<<"year should be between (1600 - 9999)\n";
            cout<<"Enter a valid year: ";
            cin>>this->ending_date.year;
        }

        // check if the ending date greater than the assigning date
        if(this->ending_date.year == this->assigning_date.year){

            if(this->ending_date.month == this->assigning_date.month){

                if(this->ending_date.day >= this->assigning_date.day){
                    break;
                }

            }
            else if(this->ending_date.month > this->assigning_date.month){
                break;
            }


        }
        else if(this->ending_date.year > this->assigning_date.year){
            break;
        }

        // -------------------------------------------------------------------

        cout<<"\n\n--Enter a valid year ( must come after the assigning date or on the same day )";
        cout<< "\n-----------------------------------------------------------------\n";
        cout <<"                 assigning date: ("<<
             this->assigning_date.day<<"/"<<this->assigning_date.month<<"/"<<assigning_date.year
             <<")\n";

    }




}

void Task::set_priority(){

    cout << "Enter the Priority of the task: ";
    cin >> this->priority;

    // check the validation of priority
    while(this->priority <=0 || this->priority >10){
        cout<< "\n-----------------------------------------------------------------\n";
        cout << "--Priorities in {1 : 10}--\n";
        cout << "Enter a valid priority: ";
        cin >> this->priority;
    }

}


// ======================================================


// Getters
string Task::get_title() {
    return this->title;
}

string Task::get_description(){
    return this->description;
}

string Task::get_employee_name(){
    return this->employee_name;
}

short  Task::get_priority() {
    return this->priority;
}

Date   Task::get_assigning_date() {
    return this->assigning_date;
}

Date   Task::get_ending_date()  {
    return this->ending_date;
}

// all info
void   Task::info(){
    cout << "title           | "  << this->title          << endl;
    cout << "Description is  | "  << this->description    << endl;
    cout << "Employee Name   | "  << this->employee_name  << endl;
    cout << "Priority        | "  << this->priority       << endl;
    cout << "Assigning Date  | "  << this->assigning_date.day << "-" << this->assigning_date.month  << "-" << this->assigning_date.year << endl;
    cout << "Ending Date     | "  << this->ending_date.day    << "-" << this->ending_date.month     << "-" << this->ending_date.year    << endl;

    cout << "\n================================================================\n\n";
}