#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {
    private:
	T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;
    public:
	ListArray() {
		arr = malloc(sizeof(T) * MINSIZE);	
	}
	
	~ListArray() {
		delete[](arr);
	}

	T operator[](int pos) {
		if(pos >= 0 || pos < n)
			return arr[n];
		else
			throw std::out_of_range();
	}

	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
		out << "[";
		for(int i = 0; i < list.n - 1; i++)
			out << list[i] << ", ";
		out << list[list.n] << "]";
		return out;
	}
	
	void resize(int new_size);
	virtual void insert(int pos, T e) {
		if(pos < 0 || pos > n)
			throw std::out_of_range("Posicion invalida en insert()");
		if(n == max)
			resize(max * 2);
		for(int i = n; i > pos; i--)
			arr[i] = arr[i - 1];
		arr[pos] = e;
		n++;
	}

	virtual void append(T e) {
		insert(n, e);
	}

	virtual void prepend(T e) {
		insert(0, e);
	}

	virtual T remove(int pos) {
		
	}

	virtual T get(int pos) const = 0;
	virtual int search(T e) const = 0;
	virtual bool empty() const = 0;
	virtual int size() const = 0;
};

#endif // LISTARRAY_H
