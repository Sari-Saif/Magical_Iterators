#include "ADTNode.hpp"

using namespace ariel;

ADTNode::ADTNode(int data) : _Next(nullptr), _Back(nullptr), _prime_Next(nullptr), _prime_Back(nullptr)
{

    this->_data = data;
}

ADTNode *ADTNode::getNext() { return this->_Next; }
ADTNode *ADTNode::get_PrimeNext() { return this->_prime_Next; }
ADTNode *ADTNode::getBack() { return this->_Back; }
ADTNode *ADTNode::get_PrimeBack() { return this->_prime_Back; }

void ADTNode::setNext(ADTNode *update) { _Next = update; }
void ADTNode::set_PrimeNext(ADTNode *update) { _prime_Next = update; }
void ADTNode::setBack(ADTNode *update) { _prime_Back = update; }
void ADTNode::set_PrimeBack(ADTNode *update) { _Back = update; }

int ADTNode::node_Value()
{
    return this->_data;
}

ostream &ariel::operator<<(ostream &os, const ADTNode &target)
{
    os << target._data << std::endl;
    return os;
}
