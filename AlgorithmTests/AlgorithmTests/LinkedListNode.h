#pragma once
#include <iostream>
template <class T>
class LinkedListNode
{
private:
	LinkedListNode<T>* priorNode = nullptr;
	LinkedListNode<T>* nextNode = nullptr;
	T value;
public:
	LinkedListNode(T val, LinkedListNode* prior, LinkedListNode* next) :value(val), priorNode(prior), nextNode(next) {};
	LinkedListNode(T val) :value(val), priorNode(nullptr), nextNode(nullptr) {};
	void insertAfter(T val) {
		LinkedListNode<T>* node(new LinkedListNode<T>(val, this, nullptr));
		
		nextNode = node;
		std::cout << "Next node of " << value << " is " << nextNode->getValue() << std::endl;
	}
	void insertBefore(T val) {
		
		
		if (priorNode) {
			priorNode->insertAfter(val);
			priorNode->getNext()->setNext(this);
			priorNode = priorNode->getNext();
		}
		else {
			LinkedListNode<T>* node(new LinkedListNode<T>(val, priorNode, this));
			priorNode = node;
		} 
	}
	LinkedListNode<T>* getPrior() {
		return priorNode;
	}
	LinkedListNode<T>* getNext() {
		return nextNode;
	}
	void setPrior(LinkedListNode* node) {
		priorNode=node;
	}
	void setNext(LinkedListNode* node) {
		nextNode = node;
	}
	T getValue() {
		return value;
	}
};

