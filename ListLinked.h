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
  ListLinked() {
    first = nullptr;
    n = 0;
  }

  ~ListLinked() {
    Node<T> *aux;
    while((aux = first->next)) {
      delete first;
      first = aux;
    }
  }

  T operator[](int pos) {
    if(pos > n - 1)
      throw std::out_of_range("Posicion fuera de rango\n");
    Node<T> *actual = this->first;
    for(int i = 0; i < pos; i++)
      actual = actual->next;
    return actual->data;
  }

  friend std::ostream &operator<<(std::ostream &out,
                                  const ListLinked<T> &list) {
    Node<T> *aux = list.first;
    out << "[";
    do {
      out << aux->data;
      if(aux->next) out << ", ";
    } while((aux = aux->next));
    return out;
  }

  virtual void insert(int pos, T e) {
    if(pos < 0 || pos > n)
      throw std::out_of_range("Posicion invalida");
    Node<T> *aux = first;
    switch(pos) {
    case 0:
      first = new Node<T>(e, first);
      break;
    case n:
      while((aux = aux->next))
        ;
      aux->next = new Node<T>(e);
      break;
    default:
      for(int i = 0; i < pos; i++)
        aux = aux->next;
      aux->next = new Node<T>(e, aux->next);
      break;
    }
    n++;
  }

  virtual void append(T e) { insert(e, 0); }

  virtual void prepend(T e) { insert(e, n); }

  virtual T remove(int pos) {
    if(pos < 0 || pos > n)
      throw std::out_of_range("Posicion invalida");
    Node<T> *aux = this->first;
    for(int i = 0; i < pos - 1; i++)
      aux = aux->next;
    Node<T> to_del = aux->next;
    aux->next = to_del->next;
    T data = to_del->data;
    delete to_del;
    return data;
  }

  virtual T get(int pos) const { return (*this)[pos]; }

  virtual int search(T e) const {
    for(int i = 0; i < n; i++)
      if((*this)[i] == e) return i;
    return -1;
  }

  virtual bool empty() const { return n == 0; }

  virtual int size() const { return n; }
};

#endif // LISTLINKED_H
