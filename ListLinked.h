#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"

#include <ostream>
#include <stdexcept>

template <typename T> class ListLinked : public List<T> {
private:
  Node<T> *first;
  int n;

public:
  ListLinked() : first(nullptr), n(0) {}

  ~ListLinked() {
    Node<T> *aux = first;
    while (aux != nullptr) {
      Node<T> *next = aux->next;
      delete aux;
      aux = next;
    }
  }

  T operator[](int pos) {
    Node<T> *aux = first;

    int i = 0;
    while (aux != nullptr && i++ != pos)
      aux = aux->next;

    if (aux != nullptr)
      return aux->data;
    else
      throw std::out_of_range("Posicion invalida");
  }

  friend std::ostream &operator<<(std::ostream &out,
                                  const ListLinked<T> &list) {
    Node<T> *aux = list.first;

    out << "List => [";
    if (aux != nullptr)
      out << std::endl;
    while (aux != nullptr) {
      out << "  " << aux->data << std::endl;
      aux = aux->next;
    }
    out << "]";

    return out;
  }

  void insert(int pos, T e) override {
    if (pos < 0 || pos > n)
      throw std::out_of_range("Posicion invalida");

    Node<T> *aux = first;
    if (pos == 0) {
      first = new Node<T>(e, first);
    } else if (pos == n) {
      while (aux->next != nullptr)
        aux = aux->next;
      aux->next = new Node<T>(e);
    } else {
      for (int i = 0; i < pos - 1; i++) {
        aux = aux->next;
      }
      aux->next = new Node<T>(e, aux->next);
    }

    n++;
  }

  void append(T e) override { insert(n, e); }

  void prepend(T e) override { insert(0, e); }

  T remove(int pos) override {
    if (pos < 0 || pos >= n)
      throw std::out_of_range("Posicion invalida");

    Node<T> *prev = nullptr;
    Node<T> *aux = first;
    Node<T> *to_delete = nullptr;

    int i = 0;
    while (aux != nullptr && i != pos) {
      prev = aux;
      aux = aux->next;
      i++;
    }
    if (aux == first)
      first = first->next;
    else
      prev->next = aux->next;

    to_delete = aux;
    T data = aux->data;
    delete to_delete;
    n--;

    return data;
  }

  T get(int pos) const override {
    Node<T> *aux = first;

    int i = 0;
    while (aux != nullptr && i != pos) {
      aux = aux->next;
      i++;
    }

    if (aux != nullptr)
      return aux->data;
    else
      throw std::out_of_range("Posicion invalida");
  }

  int search(T e) const override {
    Node<T> *aux = first;
    for (int i = 0; i < n; i++) {
      if (aux->data == e)
        return i;
      aux = aux->next;
    }

    return -1;
  }

  bool empty() const override { return n == 0; }

  int size() const override { return n; }
};

#endif // LISTLINKED_H
