#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"

#include <ostream>

template <typename T> class ListArray : public List<T> {
private:
  T *arr;
  int max;
  int n;
  static const int MINSIZE = 2;

public:
  ListArray() { this->arr = malloc(sizeof(T) * MINSIZE); }

  ~ListArray() { delete[](this->arr); }

  T operator[](int pos) {
    if(pos >= 0 || pos < this->n) return this->arr[this->n];
    else throw std::out_of_range("Indice fuera de rango\n");
  }

  friend std::ostream &operator<<(std::ostream &out,
                                  const ListArray<T> &list) {
    out << "[";
    for(int i = 0; i < list.n - 1; i++)
      out << list[i] << ", ";
    out << list[list.n] << "]";
    return out;
  }

  void resize(int new_size) {
    T arr = new T[new_size];
    int data_size = new_size < this->max ? new_size : this->n;
    for(int i = 0; i < data_size; i++)
      arr[i] = this->arr[i];
    delete[] this->arr;
    this->arr = arr;
    this->max = new_size;
  }

  virtual void insert(int pos, T e) {
    if(pos < 0 || pos > n)
      throw std::out_of_range("Posicion invalida en insert()");
    if(n == max) resize(max * 2);
    for(int i = n; i > pos; i--)
      arr[i] = arr[i - 1];
    arr[pos] = e;
    n++;
  }

  virtual void append(T e) { insert(n, e); }

  virtual void prepend(T e) { insert(0, e); }

  virtual T remove(int pos) {
    for(int i = pos; i < this->n; i++)
      this->arr[pos] = this->arr[pos - 1];
    n--;
  }

  virtual T get(int pos) const { return this->arr[pos]; }

  virtual int search(T e) const {
    for(int i = 0; i < this->n; i++) {
      if(this->arr[i] == e) return i;
    }
    return -1;
  }

  virtual bool empty() const { return this->n == 0; }

  virtual int size() const { return this->n; }
};

#endif // LISTARRAY_H
