#pragma once
#ifndef WORD_CARD_H_
#define WORD_CARD_H_

#include <string>
#include "bidirlist.h"
#include "vocabulary.h"
#include "filereader.h"

using std::string;

class WordCard {
 public:
  WordCard() = default;
  explicit WordCard(string &string) : word_(string), counter_(1){}

  WordCard(const WordCard& card) {
    word_ = card.word_;
    counter_ = card.counter_ + 1;
  }
  WordCard operator=(const WordCard& other) {
    word_ = other.word_;
    counter_ = other.counter_;
    return *this;
  }

  WordCard(const WordCard &&card) : word_(card.word_), counter_(card.counter_ + 1) {
    card.~WordCard();
  }
  WordCard& operator=(WordCard&& other) {
    *this = other;
    other.~WordCard();
    return *this;
  }

  ~WordCard() = default;

  string GetWord() const { return word_; }
  size_t GetCounter() const { return counter_; }

  void IncCounter() { counter_++;
  }

  bool operator==(const WordCard& other) {
    return (word_ == other.word_ && counter_ == other.counter_) ? true : false;
  }
  bool operator!=(const WordCard& other) {
    return !(*this == other);
  }

  bool operator<(const WordCard& card) {
    return (word_ < card.word_ || counter_ < card.counter_) ? true : false;
  }

 private:
  string word_ = "";
  size_t counter_;
};

#endif