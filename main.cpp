#include <iostream>
#include "LinkedList.h"
#include <string>
using namespace std;

int main()
{
    LinkedList todo;
    int choice, id;
    string title, description, status;

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
           cin.ignore();
           cout << "Enter the title of the task: \n";
           getline(cin, title);
           cout << "Enter the description of the task: \n";
           getline(cin, description);
           cout << "Enter the status of the task: \n";
           getline(cin, status);
           todo.addTask(title, description, status);
           break;
       case 2:
           todo.displayAllTasks();
           break;
       case 3:
           cout << "Enter the ID of the task to search: ";
           cin >> id;
           cin.ignore();
           todo.searchTaskID(id);
           break;
       case 4:
           cout << "Enter the ID of the task to mark as done: ";
           cin >> id;
           cin.ignore();
           todo.markAsDone(id);
           break;
       case 0:
           cout << "Exiting... Goodbye!\n";
           break;
       default:
           cout << "Invalid choice! Please enter a number between 0-4.\n";
           break;
       }

       

   } while (choice != 0);

    
    return 0;
}
