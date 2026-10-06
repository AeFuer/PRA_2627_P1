#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "List.h"

template<typename T>
class Node{
	public:
		T data;
		Node<T>* next;
		Node(T data){
			this->data = data;
			this->next = nullptr;
		}
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
			out << node.data;
			return out;
		}
};

#endif
