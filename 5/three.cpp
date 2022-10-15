// напишите итератор для линкед листа

#include <initializer_list>
#include <iostream>

class linked_list {
 private:
  struct node {
    int data;
    node* next;
  };

 public:
  class iterator {
   public:
    explicit iterator(node* node) : node_(node) {}
    iterator(const iterator& other) = default;

    int& operator*() { return node_->data; }

    bool operator==(const iterator& other) const {
      return this->node_ == other.node_;
    }

    bool operator!=(const iterator& other) const { return !(*this == other); }

    iterator& operator++() {
      node_ = node_->next;
      return *this;
    }

    iterator operator++(int) {
      iterator tmp(node_);
      node_ = node_->next;
      return tmp;
    }

   private:
    node* node_;
  };

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

  iterator begin() { return iterator(head_); }

  iterator end() { return iterator(nullptr); }

 private:
  node* head_;
};

int main(int argc, char** argv) {
  linked_list list = {1, 2, 3};
  linked_list::iterator it = list.begin();
  linked_list::iterator end = list.end();
  while (it != end) {
    std::cout << (*it) << std::endl;
    it++;
  }
  for (int i : list) {
    std::cout << i << std::endl;
  }
}