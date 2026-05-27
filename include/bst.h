// Copyright 2021 NNTU-CS

#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>
#include <utility>

template<typename T>
class BST {
 public:
  BST() : root_(nullptr), node_count_(0) {}

  ~BST() {
    Clear(root_);
  }

  void Insert(const T& value) {
    root_ = Insert(root_, value);
    node_count_++;
  }

  bool Search(const T& value) const {
    return Search(root_, value);
  }

  int Size() const {
    return node_count_;
  }

  int Depth() const {
    return Depth(root_);
  }

  bool Empty() const {
    return root_ == nullptr;
  }

  void GetNodes(std::pair<T, int> arr[], int* size) const {
    *size = 0;
    CollectNodes(root_, arr, size);
  }

 private:
  struct Node {
    T key;
    int count;
    Node* left;
    Node* right;

    explicit Node(const T& value)
        : key(value), count(1), left(nullptr), right(nullptr) {}
  };

  Node* root_;
  int node_count_;

  Node* Insert(Node* node, const T& value) {
    if (node == nullptr) {
      return new Node(value);
    }

    if (value < node->key) {
      node->left = Insert(node->left, value);
    } else if (value > node->key) {
      node->right = Insert(node->right, value);
    } else {
      node->count++;
    }

    return node;
  }

  bool Search(Node* node, const T& value) const {
    if (node == nullptr) {
      return false;
    }

    if (value < node->key) {
      return Search(node->left, value);
    } else if (value > node->key) {
      return Search(node->right, value);
    } else {
      return true;
    }
  }

  int Depth(Node* node) const {
    if (node == nullptr) {
      return 0;
    }
    return 1 + std::max(Depth(node->left), Depth(node->right));
  }

  void CollectNodes(Node* node, std::pair<T, int> arr[], int* index) const {
    if (node == nullptr) return;
    CollectNodes(node->left, arr, index);
    arr[(*index)++] = {node->key, node->count};
    CollectNodes(node->right, arr, index);
  }

  void Clear(Node* node) {
    if (node == nullptr) return;
    Clear(node->left);
    Clear(node->right);
    delete node;
  }
};

#endif  // INCLUDE_BST_H_
