

#ifndef UNTITLED17__VOCABULARY_H_
#define UNTITLED17__VOCABULARY_H_
#include <string>
#include <vector>
#include <fstream>
#include "bidirlist.h"
#include "wordcard.h"
#include "filereader.h"


class Vocabulary {
 public:
  void ReadFileToCards(std::string file_path);
  WordCard* ConvertStringToWordCard(string str);
  void MakeFrequencyVocab();
  void SortWords(); // можно пузырьком 😊
  map<string, size_t> CopyToMap();

 private:
  BiDirectionalListOnArray<WordCard *> list_word_cards;

};
#endif//UNTITLED17__VOCABULARY_H_
