/**
 *@author Sari Safe
 *@since 30.05.23
 * URL TUTORIAL:
 * https://en.cppreference.com/w/
 * https://hackingcpp.com/cpp/cheat_sheets.html
 */

#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <iostream>
#include <cmath>

namespace ariel
{
    class MagicalContainer
    {
    private:
        int *elements;
        int size;
        int capacity;

    public:
        // Constructor
        MagicalContainer() : elements(nullptr), size(0), capacity(0) {}
        // Destructor
        ~MagicalContainer()
        {
            delete[] elements;
        }
        // Copy constructor
        MagicalContainer(const MagicalContainer &other);
        // Assignment operator
        MagicalContainer &operator=(const MagicalContainer &other);
        // Copy constructor
        MagicalContainer(const MagicalContainer &other);
        //{
        // size = other.size;
        // capacity = other.capacity;
        // elements = new int[capacity];
        // for (int i = 0; i < size; i++)
        // {
        //     elements[i] = other.elements[i];
        // }
        //}

        // Add an element to the container
        void addElement(int element){
            // if (size == capacity)
            // {
            //     // If the array is full, resize it
            //     int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            //     int *newElements = new int[newCapacity];
            //     for (int i = 0; i < size; i++)
            //     {
            //         newElements[i] = elements[i];
            //     }
            //     delete[] elements;
            //     elements = newElements;
            //     capacity = newCapacity;
            // }
            // elements[size++] = element;
        };

        // Remove an element from the container
        void removeElement(int element);

        // int index = -1;
        // for (int i = 0; i < size; i++)
        // {
        //     if (elements[i] == element)
        //     {
        //         index = i;
        //         break;
        //     }
        // }
        // if (index != -1)
        // {
        //     for (int i = index; i < size - 1; i++)
        //     {
        //         elements[i] = elements[i + 1];
        //     }
        //     size--;
        // }

        // Get the size of the container
        int getSize() const;
        //{
        // return size;
        //}
    };
};
#endif // MAGICALCONTAINER_HPP
