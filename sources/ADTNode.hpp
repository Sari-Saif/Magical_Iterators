#ifndef ADT_NODE_HPP
#define ADT_NODE_HPP

#include <iostream>
using std::ostream;

namespace ariel
{

    class ADTNode
    {
    private:
        int _data;
        ADTNode *_Next;
        ADTNode *_Back;
        ADTNode *_prime_Next;
        ADTNode *_prime_Back;

    public:
        // ctor
        ADTNode(int);
        // getters and setters
        ADTNode *getNext();
        ADTNode *get_PrimeNext();
        ADTNode *getBack();
        ADTNode *get_PrimeBack();
        void setNext(ADTNode *);
        void set_PrimeNext(ADTNode *);
        void setBack(ADTNode *);
        void set_PrimeBack(ADTNode *);
        int node_Value();
        // used for tracking(debuging) and print elements
        friend ostream &operator<<(ostream &os, const ADTNode &);
    };

};

#endif // !ADT_NODE_HPP