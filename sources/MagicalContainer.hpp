/**
 *@author Sari Safe
 *@since 4.06.23
 * URL TUTORIAL:
 * https://en.cppreference.com/w/
 * https://hackingcpp.com/cpp/cheat_sheets.html
 */

#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP
#include "ADTNode.hpp"
#include <iostream>
#include <cmath>

namespace ariel
{
    class MagicalContainer
    {
    private:
        // data members
        int _size;
        int _primeS; // prime size
        ADTNode *_Head;
        ADTNode *_Tail;
        ADTNode *_primeH;
        ADTNode *_primeT;

    public:
        // Constructor
        MagicalContainer();
        // Destructor
        ~MagicalContainer();
        // Add an element to the container
        void addElement(int element);
        // Remove an element from the container
        void removeElement(int element);
        // Get the size of the container
        int size() const;

        class SideCrossIterator
        {
        public:
            // ctor's
            SideCrossIterator(MagicalContainer &);
            SideCrossIterator(SideCrossIterator &);
            ~SideCrossIterator();
            // the head annd the tail
            SideCrossIterator begin();
            SideCrossIterator end();
            // oprator's
            int operator*();
            SideCrossIterator &operator++();
            bool operator==(const SideCrossIterator &seconed) const;
            bool operator!=(const SideCrossIterator &seconed) const;
            bool operator>(const SideCrossIterator &seconed) const;
            bool operator<(const SideCrossIterator &seconed) const;
        };
        class AscendingIterator
        {

        public:
            // ctor's
            AscendingIterator(MagicalContainer &);
            AscendingIterator(AscendingIterator &);
            ~AscendingIterator();
            // the head annd the tail
            AscendingIterator begin();
            AscendingIterator end();
            // oprator's
            int operator*();
            AscendingIterator &operator++();
            bool operator==(const AscendingIterator &seconed) const;
            bool operator!=(const AscendingIterator &seconed) const;
            bool operator>(const AscendingIterator &seconed) const;
            bool operator<(const AscendingIterator &seconed) const;
        };
        class PrimeIterator
        {
        public:
            // ctor's
            PrimeIterator(MagicalContainer &);
            PrimeIterator(PrimeIterator &);
            ~PrimeIterator();
            // the head annd the tail
            PrimeIterator begin();
            PrimeIterator end();
            // oprator's
            int operator*();
            PrimeIterator &operator++();
            bool operator==(const PrimeIterator &seconed) const;
            bool operator!=(const PrimeIterator &seconed) const;
            bool operator>(const PrimeIterator &seconed) const;
            bool operator<(const PrimeIterator &seconed) const;
        };
    };
};
#endif // MAGICALCONTAINER_HPP
