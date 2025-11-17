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
  ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

  ~ListArray() { delete[] arr; }

  T operator[](int pos) const {
    if(pos >= 0 && pos < this->n) return this->arr[pos];
    else throw std::out_of_range("Indice fuera de rango\n");
  }

  friend std::ostream &operator<<(std::ostream &out,
                                  const ListArray<T> &list) {
    out << "[";
    for(int i = 0; i < list.n; i++) {
      if(i > 0) out << ", ";
      out << list[i];
    }
    out << "]";
    return out;
  }

  void resize(int new_size) {
    T *new_arr = new T[new_size];
    int limit = n < new_size ? n : new_size;
    for(int i = 0; i < limit; i++)
      new_arr[i] = this->arr[i];
    delete[] this->arr;
    this->arr = new_arr;
    this->max = new_size;
    if(n > new_size) n = new_size;
  }

  virtual void insert(int pos, T e) {
    if(pos < 0 || pos > n)
      throw std::out_of_range("Posicion invalida");
    if(n == max) resize(max * 2);
    for(int i = n; i > pos; i--)
      arr[i] = arr[i - 1];
    arr[pos] = e;
    n++;
  }

  virtual void append(T e) { insert(n, e); }

  virtual void prepend(T e) { insert(0, e); }

  virtual T remove(int pos) {
    if(pos < 0 || pos >= n)
      throw std::out_of_range("Posicion invalida");
    T removed = this->arr[pos];
    for(int i = pos; i < this->n - 1; i++) {
      this->arr[pos] = this->arr[pos + 1];
    }
    n--;
    return removed;
  }

  virtual T get(int pos) const {
    if(pos < 0 || pos >= n)
      throw std::out_of_range("Posicion invalida");
    return this->arr[pos];
  }

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
