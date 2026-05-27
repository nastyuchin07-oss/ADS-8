// Copyright 2021 NNTU-CS

#include "include/bst.h"

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

void makeTree(BST<std::string>* tree, const char* filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Error: Cannot open file " << filename << std::endl;
    return;
  }

  std::string word;
  char ch;

  while (file.get(ch)) {
    unsigned char uch = static_cast<unsigned char>(ch);
    if (std::isalpha(uch)) {
      word += std::tolower(uch);
    } else {
      if (!word.empty()) {
        tree->Insert(word);
        word.clear();
      }
    }
  }

  if (!word.empty()) {
    tree->Insert(word);
  }

  file.close();
}
