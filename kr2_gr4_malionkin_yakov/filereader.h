#pragma once
#ifndef FILE_READER_H_
#define FILE_READER_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "bidirlist.h"
#include "wordcard.h"
#include "vocabulary.h"

class FileReader {
 public:
  std::vector<std::string> ReadLines(const std::string& file_path) {
    std::ifstream fin(file_path);
    std::string str;
    std::vector<std::string> lines;
    while (getline(fin, str)) {
      lines.push_back(str);
    }
    fin.close();
  }
  std::vector<std::string> ReadWords(const std::string& file_path) {
    std::vector<std::string> lines = ReadWords(file_path);
    std::vector<std::string> words;
    for (int i = 0; i < lines.size(); i++) {
      std::stringstream sin(lines[i]);
      std::string str;
      while (sin >> str) {
        words.push_back(str);
      }
    }
    return words;
  }
};

#endif