#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = NULL;
    }

    void wait(int n)
    {
        this_thread::sleep_for(chrono::seconds(n));
    }

    /*----------------- ADD TASK SECTION ------------------*/

    void addTask(string title, string description, string status)
    {
        int id = countTasks() + 1;
        Node *newNode = new Node(id, title, description, status);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Task added successfully: " << title << " (ID: " << id << ")" << endl;
        wait(1);
    }

    /*----------------- EDIT TASK SECTION ------------------*/

    void editTask(int id, string newTitle, string newDescription)
    {
        // if (head == NULL)
        // {
        //     cout << "List is empty, nothing to edit." << endl;
        //     return;
        // }

        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                temp->title = newTitle;
                temp->description = newDescription;
                // temp->status = newStatus;
                cout << "Task with ID " << id << " has been updated." << endl;
                wait(1);
                return;
            }
            temp = temp->next;
        }

        cout << "Task with ID " << id << " not found." << endl;
        wait(1);
    }

    /*----------------- DISPLAY TASKS SECTION ------------------*/

    void displayAllTasks()
    {
        if (head == NULL)
        {
            cout << "\n================================= TASKS =================================" << endl;
            cout << "\nTASK LIST IS EMPTY :( " << endl;
            cout << "\n=========================================================================\n"
                 << endl;
            wait(1);
            return;
        }

        Node *temp = head;
        cout << "\n================================= TASKS =================================\n"
             << endl;
        while (temp != NULL)
        {
            cout << "ID: " << temp->id << " | Title: " << temp->title
                 << " | Description: " << temp->description
                 << " | Status: " << temp->status << endl;
            temp = temp->next;
        }
        cout << "\n==========================================================================\n"
             << endl;
        string x;     
        cout << "Enter any key to get back to the Main Menu: " ; cin >> x;
        return; 
    }

    /*----------------- SEARCH TASK SECTION ------------------*/

    void searchTaskID(int id)
    {
        if (head == NULL)
        {
            cout << "\nThe list is empty, nothing to search for!" << endl;
            wait(1);
            return;
        }
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                cout << "\n=== Task Found ===" << endl;
                cout << "ID: " << temp->id << " | Title: " << temp->title
                     << " | Description: " << temp->description
                     << " | Status: " << temp->status << endl;
                cout << "==========================================================================" << endl;
                string x;     
                cout << "\n\nEnter any key to get back to the Main Menu: " ; cin >> x;
                return; 
            }
            temp = temp->next;
        }

        cout << "Task with ID " << id << " not found." << endl;
        wait(1);
    }

    /*----------------- COUNT OF TASKS SECTION ------------------*/

    int countTasks()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    /*----------------- DELETE TASK SECTION ------------------*/

    void renumberTasks()
    {
        int counter = 1;
        Node *temp = head;
        while (temp != NULL)
        {
            temp->id = counter;
            counter++;
            temp = temp->next;
        }
    }

    void deletetask(int id)
    {
        //    if ( head == NULL)
        //    {
        //     cout << "List is Empty .. Nothing To delete  \n"; wait();
        //      return ;

        //    }

        Node *temp = head;
        if (head->id == id)
        {
            head = head->next;
            delete temp;
            renumberTasks();
            cout << "Task with id " << id << " Deleted Successfully ! \n";
            wait(1);
            return;
        }
        else
        {
            while (temp != NULL)
            {
                if (temp->next->id == id)
                {
                    Node *deletedtemp;
                    deletedtemp = temp->next->next;
                    delete temp->next;
                    temp->next = deletedtemp;
                    renumberTasks();
                    cout << "Task with id " << id << " Deleted Successfully :) \n";
                    wait(1);
                    return;
                }
                temp = temp->next;
            }
        }
    }

    /*----------------- DELETE ALL TASKS SECTION ------------------*/
    void deleteAllTasks()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = NULL;
        cout << "All tasks have been deleted." << endl;
        wait(1);
    }

    /*----------------- MARK TASK DONE SECTION ------------------*/
    void markAsDone(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to mark as done." << endl;
            wait(1);
            return;
        }

        Node *temp = head;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                temp->status = "Done";
                found = true;
                cout << "Task with ID " << id << " has been marked as done." << endl;
                wait(1);
                return;
            }
            temp = temp->next;
        }

        if (!found)
        {
            cout << "Task with ID " << id << " not found." << endl;
            wait(1);
        }
    }



     /*-------------------------Inprogress----------------------------*/

     void showInprogressTasks()
    {
        if (head == NULL)
        {
            cout << "\nThe list is empty, nothing to view!" << endl;

            wait(1);
            return;
        }

        Node *temp = head;
        cout << "\n=== In Progress Tasks ===\n";

        while (temp != NULL)
        {
            if (temp->status != "Done")
            {
                
                cout << "ID: " << temp->id << " | Title: " << temp->title
                     << " | Description: " << temp->description
                     << " | Status: " << temp->status << endl;
                cout << "==========================================================================" << endl;
            }
            temp = temp->next;
        }
        string x;     
        cout << "\n\nEnter any key to get back to the Main Menu: " ; cin >> x;
        return; 

        
    }

    /*-------------------------EXTRAS----------------------------*/
    bool isfound(int id)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->id == id)
                return true;
            temp = temp->next;
        }
        return false;
    }

    bool isempty()
    {
        return head == NULL;
    }

   
};
#endif
