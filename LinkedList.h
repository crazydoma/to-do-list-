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

    void addTask(int id, string title, string description, string status)
    {
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
        cout << "Task added successfully: " << title << endl;
    }

    void editTask(int id, string newTitle, string newDescription, string newStatus)
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to edit." << endl;
            return;
        }

        Node *temp = head;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                temp->title = newTitle;
                temp->description = newDescription;
                temp->status = newStatus;
                found = true;
                cout << "Task with ID " << id << " has been updated." << endl;
                return;
            }
            temp = temp->next;
        }

        if (!found)
        {
            cout << "Task with ID " << id << " not found." << endl;
        }
    }

    void displayAllTasks()
    {
        Node *temp = head;
        cout << "\n--- To-Do List ---" << endl;
        while (temp != NULL)
        {
            cout << "ID: " << temp->id << " | Title: " << temp->title
                 << " | Status: " << temp->status << endl;
            temp = temp->next;
        }
        cout << "\n-----------------------------------------------\n"
             << endl;
    }

    // Masry
    void searchTaskID(int id)
    {
        if (head == NULL)
        {
            cout << "\n The List is Empty, Nothing to Search for!" << endl;
            return;
        }
        Node *temp = head;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                cout << "ID: " << temp->id << " | Title: " << temp->title
                     << " | Status: " << temp->status << endl;
                found = true;
                break;
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
