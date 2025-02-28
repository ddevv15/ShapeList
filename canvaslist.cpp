/*
Name: Dev KishorKumar Shah
UIN: 658560014
Professor: Ethan Ordentlich
Project 3 – Shape List
Class - CS251
*/

#include <iostream>
#include "canvaslist.h"

// Default Constructor
// Initializes an empty CanvasList
CanvasList::CanvasList() : listSize(0), listFront(nullptr) {}

// Copy Constructor
// Constructs a  copy of another CanvasList
CanvasList::CanvasList(const CanvasList &other) : listSize(0), listFront(nullptr)
{
    ShapeNode *current = other.listFront;
    while (current)
    {
        push_back(current->value->copy());
        current = current->next;
    }
}

// Assignment Operator Overload
// Assigns the values from another CanvasList
CanvasList &CanvasList::operator=(const CanvasList &other)
{
    if (this == &other)
    {
        return *this;
    }

    clear();
    ShapeNode *current = other.listFront;
    while (current)
    {
        push_back(current->value->copy());
        current = current->next;
    }
    return *this;
}

// Virtual Destructor
// Destructor that clears the list
CanvasList::~CanvasList()
{
    clear();
}

// Clears the linked list and frees memory
void CanvasList::clear()
{
    while (listFront)
    {
        ShapeNode *temp = listFront;
        listFront = listFront->next;
        delete temp->value;
        delete temp;
    }
    listSize = 0;
}

// Check if the list is empty
bool CanvasList::isempty() const
{
    return listSize == 0;
}

// Get the size of the list
ShapeNode *CanvasList::front() const
{
    return listFront;
}

void CanvasList::insertAfter(int idx, Shape *shape)
{
    if (idx < 0 || idx >= size())
    {
        return;
    }
    ShapeNode *current = listFront;
    for (int i = 0; i < idx; i++)
    {
        current = current->next;
    }
    ShapeNode *new_node = new ShapeNode();
    new_node->value = shape;
    new_node->next = current->next;
    current->next = new_node;
    listSize++;
}

Shape *CanvasList::pop_front()
{
    if (!listFront)
    {
        // List is empty
        return nullptr;
    }

    // Store the shape from the listFront node
    Shape *shapeToReturn = listFront->value;

    if (!listFront->next)
    {
        // Only one element in the list
        delete listFront;
        listFront = nullptr;
    }
    else
    {
        // More than one element in the list
        ShapeNode *temp = listFront;
        listFront = listFront->next;
        delete temp;
    }

    listSize--;
    return shapeToReturn;
}

Shape *CanvasList::pop_back()
{
    if (!listFront)
    {
        return nullptr;
    }
    if (!listFront->next)
    {
        Shape *shape = listFront->value;
        delete listFront;
        listFront = nullptr;
        listSize--;
        return shape;
    }
    ShapeNode *current = listFront;
    while (current->next && current->next->next)
    {
        current = current->next;
    }
    Shape *shape = current->next->value;
    delete current->next;
    current->next = nullptr;
    listSize--;
    return shape;
}

// Remove shapeNode at the given index
Shape *CanvasList::shapeAt(int idx) const
{
    if (idx < 0 || idx >= size())
    {
        return nullptr;
    }
    ShapeNode *current = listFront;
    for (int i = 0; i < idx; i++)
    {
        current = current->next;
    }
    return current->value;
}

void CanvasList::push_back(Shape *shape)
{
    ShapeNode *new_node = new ShapeNode();
    new_node->value = shape;
    new_node->next = nullptr;

    if (!listFront)
    {
        listFront = new_node;
    }
    else
    {
        ShapeNode *current = listFront;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    listSize++;
}

// Implementation for CanvasList::push_front(Shape*)
void CanvasList::push_front(Shape *shape)
{
    ShapeNode *new_node = new ShapeNode();
    new_node->value = shape;
    new_node->next = listFront;
    listFront = new_node;
    listSize++;
}

// Implementation for CanvasList::printAddresses() const
void CanvasList::printAddresses() const
{
    ShapeNode *current = listFront;
    while (current)
    {
        std::cout << current << "	" << current->value << std::endl;
        current = current->next;
    }
}

// Implementation for draw
void CanvasList::draw() const
{
    ShapeNode *current = listFront;
    while (current)
    {
        current->value->printShape();
        current = current->next;
    }
}

// Returns the size of the linked list
int CanvasList::size() const
{
    return listSize;
}

// Removes the ShapeNode at the given index
void CanvasList::removeAt(int idx)
{
    if (idx < 0 || idx >= size())
    {
        return;
    }
    if (idx == 0)
    {
        ShapeNode *temp = listFront;
        listFront = listFront->next;
        delete temp->value;
        delete temp;
        listSize--;
        return;
    }
    ShapeNode *current = listFront;
    for (int i = 0; i < idx - 1; i++)
    {
        current = current->next;
    }
    ShapeNode *toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete->value;
    delete toDelete;
    listSize--;
}

// Finds the index of the first Shape with the given x, y values
int CanvasList::find(int x, int y) const
{
    int idx = 0;
    ShapeNode *current = listFront;
    while (current)
    {
        if (current->value->getX() == x && current->value->getY() == y)
        {
            return idx;
        }
        current = current->next;
        idx++;
    }
    return -1;
}

// Removes every other ShapeNode from the list
void CanvasList::removeEveryOther()
{
    bool remove = false;
    ShapeNode *current = listFront;
    ShapeNode *prev = nullptr;
    while (current)
    {
        if (remove)
        {
            if (!prev)
            {
                listFront = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            delete current->value;
            delete current;
            listSize--;
            current = (prev) ? prev->next : listFront;
        }
        else
        {
            prev = current;
            current = current->next;
        }
        remove = !remove;
    }
}
