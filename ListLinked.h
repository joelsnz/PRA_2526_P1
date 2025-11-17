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
    for(int i = 0; i < n; i++) {
      Node<T> *aux = first->next;
      delete first;
      first = aux;
    }
  }

  T operator[](int pos);

  friend std::ostream &operator<<(std::ostream &out,
                                  const ListLinked<T> &list);
};

#endif // LISTLINKED_H
