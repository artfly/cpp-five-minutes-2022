// напишите итератор для линкед листа

#include <initializer_list>
#include <iostream>

class linked_list {
 public:
  linked_list(const std::initializer_list<int>& initializer) {
    node* prev = nullptr;
    head_ = nullptr;
    for (int i : initializer) {
      node* n = new node{i, nullptr};
      if (prev != nullptr) {
        prev->next = n;
        prev = n;
      } else {
        head_ = n;
        prev = n;
      }
    }
  }

  ~linked_list() {
    while (head_ != nullptr) {
      node* next = head_->next;
      delete head_;
      head_ = next;
    }
  }

 private:
  class iterator;

 public:
  iterator begin() {
    // TODO: return iterator
  }

  iterator end() {
    // TODO: return iterator
  }

 private:
  struct node {
    int data;
    node* next;
  };

  // TODO: iterator

};

int main(int argc, char** argv) {
  linked_list list = {1, 2, 3};
  for (int i : list) {
    std::cout << i << std::endl;
  }
}