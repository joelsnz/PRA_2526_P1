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
    else throw std::out_of_range("Posicion invalida");
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

  void insert(int pos, T e) override {
    if(pos < 0 || pos > this->n)
      throw std::out_of_range("Posicion invalida");

    if(this->n == this->max) resize(this->max * 2);

    for(int i = this->n; i > pos; i--)
      this->arr[i] = this->arr[i - 1];

    this->arr[pos] = e;
    this->n++;
  }

  void append(T e) override { insert(this->n, e); }

  void prepend(T e) override { insert(0, e); }

  T remove(int pos) override {
    if(pos < 0 || pos >= this->n)
      throw std::out_of_range("Posicion invalida");
    T removed = this->arr[pos];
    for(int i = pos; i < this->n - 1; i++) {
      this->arr[pos] = this->arr[pos + 1];
    }
    n--;
    return removed;
  }

  T get(int pos) const override {
    if(pos < 0 || pos >= this->n)
      throw std::out_of_range("Posicion invalida");
    return this->arr[pos];
  }

  int search(T e) const override {
    for(int i = 0; i < this->n; i++) {
      if(this->arr[i] == e) return i;
    }
    return -1;
  }

  bool empty() const override { return this->n == 0; }

  int size() const override { return this->n; }
};

#endif // LISTARRAY_H
