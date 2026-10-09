#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
		
		Node<T>* first;
		int n;

    public:

        ListLinked(){
			first = nullptr;
			n = 0;
		}

		void insert(int pos, T e) override{
			if(pos < 0 || pos >= size()){
				throw std::out_of_range("Position out of range of List");
			}
			if(pos == 0){
				Node<T>* node = new Node(e,first);
				first = node;
			} else if(pos == size()-1){
				Node<T>* node = new Node(e);
				Node<T>* aux = first;
				while(aux->next != nullptr){
					aux = aux->next;
				}
				aux -> next = node;
			} else {
				Node<T>* node = new Node(e);
				Node<T>* aux = first;
				Node<T>* prev = nullptr;
				for(int i = 0; i < pos; i++){
					prev = aux;
					aux = aux->next;
				}
				node->next = aux;
				prev->next = node;
			}
		}

		void append(T e) override{
			insert(size(), e);
		}

		void prepend(T e) override{
			insert(0, e);
		}

		T remove(int pos){
			T node;
			if(pos < 0 || pos >= size()){
				throw std::out_of_range("Position out of range of List");
			}
			if(pos == 0){
				node = first->data;
				Node<T>* aux = first;
				first = first->next;
				delete aux;
			} else {
				Node<T>* aux = first;
				Node<T>* prev = nullptr;
				for(int i = 0; i < pos; i++){
					prev = aux;
					aux = aux->next;
				}
				node = aux->data;
				prev->next = aux->next;
				delete aux;
			}
			return node;
		}

		T get(int pos) override {
			if(pos < 0 || pos >= size()){
				throw std::out_of_range("Position out of range of List");
			}
			T node;
			if(pos == 0){
				node = first->data;
			} else {
				Node<T>* aux = first;
				for(int i = 0; i < pos; i++){
					aux = aux->next;
				}
				node = aux->data;
			}
			return node;
		}

		int search(T e) override {
			if(empty()){
				return -1;
			}
			int pos = 0;
			Node<T>* aux = first;
			while(aux->next != nullptr && aux->data != e){
				aux = aux->next;
				pos++;
			}
			return aux->data == e ? pos : -1;
		}

		bool empty() override {
			return first == nullptr? true : false;
		}

		int size() override {
			Node<T>* aux = first;
			int n = 0;
			while(aux != nullptr){
				aux = aux->next;
				n++;
			}
			return n;
		}

		T operator[](int pos){
			return get(pos);
		}

		friend std::ostream& operator<<(std::ostream &out, ListLinked &list){
			out << "List => [";
			if(!empty()){
				Node<T>* aux = list->first;
				while(aux->next!= nullptr){
					out << aux->data << ", ";
				}
				out << aux->data;
			}
			out << "]";
			return out;
		}

		~ListLinked(){
			if(!empty()){
				Node<T>* aux = first->next;
				while(aux!=nullptr){
					delete first;
					first = aux;
					aux = first->next;
				}
			}
		}
};

#endif
