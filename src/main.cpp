// Copyright 2021 NNTU-CS

#include "../include/bst.h"

#include <iostream>
#include <string>

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
  BST<std::string> word_tree;

  makeTree(word_tree, "src/war_peace.txt");

  std::cout << "Unique words: " << word_tree.Size() << std::endl;
  std::cout << "Tree depth: " << word_tree.Depth() << std::endl;
  std::cout << std::endl;

  printFreq(word_tree);

  std::cout << "Frequency analysis saved to result/freq.txt" << std::endl;

  return 0;
}
