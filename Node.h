#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int id;
    string title;
    string description;
    string status;

    Node *next;

    Node(int id, string title, string description, string status)
    {
        this->id = id;
        this->title = title;
        this->description = description;
        this->status = status;

        next = NULL;
    }
};

#endif
