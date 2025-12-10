#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
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

    // Destructor to prevent memory leaks
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

    // 1

    void addTask(string title, string description, string status)
    {
        int newId = countTasks() + 1;
        Node *newNode = new Node(newId, title, description, status);

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
        cout << "Task added successfully: " << title << " (ID: " << newId << ")" << endl;
    }

    // 2

    void editTask(int id, string newTitle, string newDescription, string newStatus)
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to edit." << endl;
            return;
        }

        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                temp->title = newTitle;
                temp->description = newDescription;
                temp->status = newStatus;
                cout << "Task with ID " << id << " has been updated." << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Task with ID " << id << " not found." << endl;
    }

    // 3

    void displayAllTasks()
    {
        if (head == NULL)
        {
            cout << "\n--- To-Do List ---" << endl;
            cout << "No tasks found. The list is empty." << endl;
            cout << "\n-----------------------------------------------\n" << endl;
            return;
        }

        Node *temp = head;
        cout << "\n--- To-Do List ---" << endl;
        while (temp != NULL)
        {
            cout << "ID: " << temp->id << " | Title: " << temp->title
                 << " | Description: " << temp->description
                 << " | Status: " << temp->status << endl;
            temp = temp->next;
        }
        cout << "\n-----------------------------------------------\n" << endl;
    }

    // 9
    void searchTaskID(int id)
    {
        if (head == NULL)
        {
            cout << "\nThe list is empty, nothing to search for!" << endl;
            return;
        }
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                cout << "\n--- Task Found ---" << endl;
                cout << "ID: " << temp->id << " | Title: " << temp->title
                     << " | Description: " << temp->description
                     << " | Status: " << temp->status << endl;
                cout << "-----------------------------------------------\n" << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Task with ID " << id << " not found." << endl;
    }

    // 4
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

    // 5
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

    // 6
    void deleteTask(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        // If deleting the head node
        if (head->id == id)
        {
            Node *nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            renumberTasks();
            cout << "Task with ID " << id << " has been deleted." << endl;
            return;
        }

        // Traverse to find the node to delete
        Node *prev = head;
        Node *current = head->next;
        bool found = false;

        while (current != NULL)
        {
            if (current->id == id)
            {
                prev->next = current->next;
                delete current;
                found = true;
                renumberTasks();
                cout << "Task with ID " << id << " has been deleted." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        if (!found)
        {
            cout << "Task with ID " << id << " not found." << endl;
        }
    }

    // 7
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
    }

    // 8
    void markAsDone(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to mark as done." << endl;
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
                return;
            }
            temp = temp->next;
        }

        if (!found)
        {
            cout << "Task with ID " << id << " not found." << endl;
        }
    }
};    
#endif
