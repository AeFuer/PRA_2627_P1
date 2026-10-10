#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T>{
	
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;

		void resize(int new_size){
			T* aux = new T[new_size];
			for(int i = 0; i < max; i++){
				aux[i] = this->arr[i];
			}
			delete[] this->arr;
			this->arr = aux;
			this->max = new_size;
		}

	public:
		ListArray(){
			arr = new T[MINSIZE];
			n = 0;
			max = MINSIZE;
		}
		
		~ListArray() override{
			delete arr;
		}
		
		void insert(int pos, T e) override{
			if(pos < 0 || pos > size()){
				throw std::out_of_range("Position is out of List Range");
			}
			if(size() == max){
				resize(max*2);
			}
			for(int i = size()-1; i >= pos; i--){
				arr[i+1] = arr[i];
			}
			arr[pos] = e;
			n++;
		}

		void append(T e) override{
			insert(size(), e);
		}

		void prepend(T e) override{
			insert(0, e);
		}

		T remove(int pos) override{
			if(pos < 0 || pos >=size()){
				throw std::out_of_range("Position is out of List range");
			}
			T out = arr[pos];
			for(int i = pos; i < size(); i++){
				arr[i] = arr[i+1];
			}
			n--;
			if(size()/2+1 < max){
				resize(max/2+1);
			}
			return out;
		}

		T get(int pos) override {
			if(pos < 0 || pos >=size()){
				throw std::out_of_range("Position is out of List Range");
			}
			return arr[pos];
		}

		int search(T e) override {
			for(int i = 0; i < size(); i++){
				if(arr[i] == e){
					return i;
				}
			}
			return -1;
		}

		bool empty() override{
			return size() == 0 ? true : false;
		}

		int size() override{
			return n;
		}

		T operator[](int pos){
			if(pos < 0 || pos >= size()){
				throw std::out_of_range("Position is out of List Range");
			}
			return arr[pos];
		}
		
		friend std::ostream& operator<<(std::ostream &out, ListArray<T> &list){
			out << "List => [";
			if(list.size() > 0){
				for(int i = 0; i < list.size()-1; i++){
					out << list[i] << ", ";
				}
				out << list[list.size()-1];
			}
			out << ']';
			return out;
		}
};		

