#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
     LinkedList todo;
     int choice, id;

    do
    {
        
        cout << "\n===== To-Do List Manager =====\n";
        cout << "1) Add Task\n";
        cout << "2) View Tasks\n";
        cout << "3) Search Task by ID\n";
        cout << "4) Mark Task as Done\n";
        cout << "5) Show In progress Tasks\n";
        cout << "6) Edit Task\n";
        cout << "7) Delete Task\n";
        cout << "8) Delete All Tasks\n";
        cout << "9) Count Tasks\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            
            break;
        
        default:
            break;
        }

        

    } while (choice != 0);


    return 0;
}
