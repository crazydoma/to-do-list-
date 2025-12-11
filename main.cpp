#include <iostream>
#include "LinkedList.h"
#include <string>

#include <chrono>
#include <thread>

using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls"); // للـ Windows
    #endif
}

int main()
{
    LinkedList todo;
    int choice, id;
    string title, description, status = "In Progress";

    do
    {

        cout << "\n===================================\n";
        cout << "      TO-DO LIST MANAGER \n";
        cout << "===================================\n";
        cout << " [1] Add Task\n";
        cout << " [2] View Tasks\n";
        cout << " [3] Search Task by ID\n";
        cout << " [4] Mark Task as Done\n";
        cout << " [5] Show In Progress Tasks\n";
        cout << " [6] Edit Task\n";
        cout << " [7] Delete Task\n";
        cout << " [8] Delete All Tasks\n";
        cout << " [9] Count Tasks\n";
        cout << " [0] Exit\n";
        cout << "===================================\n";
        cout << "Your choice: ";
        cin >> choice;

        clearScreen();

        switch (choice)
        {
        case 1:
            cout << "=====================" << endl;
            cout << "1) ADD NEW TASK MENU " << endl;
            cout << "=====================" << endl;

            cin.ignore();
            cout << "\nEnter The Title Of The Task: ";
            getline(cin, title);
            cout << "\nEnter The Description Of The Task: ";
            getline(cin, description);
            //    cout << "Enter the status of the task: \n";
            //    getline(cin, status);
            todo.addTask(title, description, status);
            break;
        case 2:
            cout << "======================" << endl;
            cout << "2) DISPLAY TASKS MENU " << endl;
            cout << "======================" << endl;

            todo.displayAllTasks();
            break;
        case 3:
            cout << "========================" << endl;
            cout << "3) SEARCH FOR TASK MENU " << endl;
            cout << "========================" << endl;

            cout << "Enter the ID of the task to search: ";
            cin >> id;
            cin.ignore();
            todo.searchTaskID(id);
            break;
        case 4:
            cout << "========================" << endl;
            cout << "4) MARK DONE TASKS MENU " << endl;
            cout << "========================" << endl;

            cout << "Enter the ID of the task to mark as done: ";
            cin >> id;
            cin.ignore();
            todo.markAsDone(id);
            break;

        case 5:
            break;

        case 6:
            cout << "===================" << endl;
            cout << "6) EDIT TASKS MENU " << endl;
            cout << "===================" << endl;


            cout << "\nEnter (ID) To Edit : ";
            cin >> id;
            if (todo.isfound(id) == false)
            {
                cout << "\nTASK NOT FOUND ! \n";
                this_thread::sleep_for(chrono::seconds(2));
            }
            else
            {
                cout << "\nEnter New Title : ";
                cin >> title;
                cout << "\nEnter New Description : ";
                cin >> description;
                todo.editTask(id, title, description);
            }

            break;

        case 7:
            cout << "=====================" << endl;
            cout << "7) DELETE TASKS MENU " << endl;
            cout << "=====================" << endl;

            cout << "\nEnter (ID) To Delete : ";
            cin >> id;

            if (todo.isfound(id) == false)
            {
                cout << "\nTASK NOT FOUND ! \n";
                this_thread::sleep_for(chrono::seconds(2));
            }
            else
            {
                todo.deletetask(id);
            }

            break;

        case 8:
            cout << "=========================" << endl;
            cout << "8) DELETE ALL TASKS MENU " << endl;
            cout << "=========================" << endl;

            todo.deleteAllTasks();
            break;

        case 9:
            cout << "======================" << endl;
            cout << "9) COUT OF TASKS MENU " << endl;
            cout << "======================" << endl;

            if (todo.isempty())
            {
                cout << "List Is Empty \n";
                this_thread::sleep_for(chrono::seconds(2));
            }
            else
            {
                cout << "\nCurrent List Has [ " << todo.countTasks() << " ] Elements. \n";
                this_thread::sleep_for(chrono::seconds(3));
            }

            break;

        case 0:
            cout << "===============================================" << endl;
            cout << "\tExiting... Goodbye :)\t\n";
            cout << "===============================================" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            break;
        default:
            cout << "Invalid choice! Please enter a number between 0-9.\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;
        }


    clearScreen();    

    } while (choice != 0);

    return 0;
}
