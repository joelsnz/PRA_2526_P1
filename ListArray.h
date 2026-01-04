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
  ListArray() : arr(new T[ListArray::MINSIZE]), max(ListArray::MINSIZE), n(0) {}

  ~ListArray() { delete[] arr; }

  T operator[](int pos) const {
    if (pos >= 0 && pos < n)
      return arr[pos];
    else
      throw std::out_of_range("Posicion invalida");
  }

  friend std::ostream &operator<<(std::ostream &out, const ListArray<T> &list) {
    out << "List => [";
    for (int i = 0; i < list.n; i++) {
      if (i == 0)
        out << std::endl;
      out << "  " << list[i] << std::endl;
    }
    out << "]";

    return out;
  }

  void resize(int new_size) {
    T *new_arr = new T[new_size];
    int limit = n < new_size ? n : new_size;

    for (int i = 0; i < limit; i++)
      new_arr[i] = arr[i];

    delete[] arr;

    arr = new_arr;
    max = new_size;
    if (n > new_size)
      n = new_size;
  }

  void insert(int pos, T e) override {
    if (pos < 0 || pos > n)
      throw std::out_of_range("Posicion invalida");

    if (n == max)
      resize(max * 2);

    for (int i = n; i > pos; i--)
      arr[i] = arr[i - 1];

    arr[pos] = e;
    n++;
  }

  void append(T e) override { insert(n, e); }

  void prepend(T e) override { insert(0, e); }

  T remove(int pos) override {
    if (pos < 0 || pos >= n)
      throw std::out_of_range("Posicion invalida");
    T removed = arr[pos];
    for (int i = pos; i < n - 1; i++) {
      arr[pos] = arr[pos + 1];
    }
    n--;
    return removed;
  }

  T get(int pos) const override {
    if (pos < 0 || pos >= n)
      throw std::out_of_range("Posicion invalida");
    return arr[pos];
  }

  int search(T e) const override {
    for (int i = 0; i < n; i++) {
      if (arr[i] == e)
        return i;
    }
    return -1;
  }

  bool empty() const override { return n == 0; }

  int size() const override { return n; }
};

#endif // LISTARRAY_H
