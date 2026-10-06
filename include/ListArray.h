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
		
		void insert(int pos, T e){
			if(pos > n){
				throw std::out_of_range("Inserted Position Out of Range");
			}
			if(pos == n){
				resize(max+1);
			}
			for(int i = n){





		T operator[](int pos){
			
