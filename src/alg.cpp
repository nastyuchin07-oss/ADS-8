// Copyright 2021 NNTU-CS

#include "../include/bst.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

void makeTree(BST<std::string>& tree, const char* filename) {
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
        tree.Insert(word);
        word.clear();
      }
    }
  }

  if (!word.empty()) {
    tree.Insert(word);
  }

  file.close();
}

void printFreq(BST<std::string>& tree) {
  std::ofstream out_file("result/freq.txt");

  if (!out_file.is_open()) {
    std::cerr << "Error: Cannot create output file" << std::endl;
    return;
  }

  int size = tree.Size();
  std::pair<std::string, int>* nodes =
      new std::pair<std::string, int>[size];

  tree.GetNodes(nodes, &size);

  for (int i = 0; i < size - 1; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (nodes[i].second < nodes[j].second) {
        std::swap(nodes[i], nodes[j]);
      }
    }
  }

  for (int i = 0; i < size; ++i) {
    out_file << nodes[i].first << ": " << nodes[i].second << std::endl;
  }

  delete[] nodes;
  out_file.close();
}
