#ifndef BIDIRECTIONAL_LIST_ON_ARRAY_H_
#define BIDIRECTIONAL_LIST_ON_ARRAY_H_

#include <cstdio>
#include <initializer_list>
#include <vector>



template<class T>
class BiDirectionalListOnArray {
 private:
  size_t size_;
  size_t capacity_;

  static const size_t MIN_CAPACITY = 10;
  static const size_t GROWTH_FACTOR = 2;

  T* data_;

  void Extend() {
    capacity_ *= GROWTH_FACTOR;
    T* Data_new = new T[capacity_];
    for (int i = 0; i < size_; i++) {
      Data_new[i] = data_[i];
    }
    delete[] data_;
    data_ = Data_new;
  }

  void CheckCapacityOfList() {
    if (size_ == capacity_) {
      Extend();
    }
  }

  void ToMoveRight(int start_position) {
    for (int i = size_ - 1; i >= start_position; i--) {
      data_[i + 1] = data_[i];
    }
  }

  void ToMoveLeft(int start_position) {
    for (int i = start_position; i < size_ - 1; i++) {
      data_[i] = data_[i + 1];
    }
  }

 public:
  BiDirectionalListOnArray() : size_(0), capacity_(MIN_CAPACITY), data_(new T[MIN_CAPACITY]) {}

  BiDirectionalListOnArray(const std::initializer_list<T> list) : size_(list.size()), capacity_(list.size()), data_(new T[list.size()]) {
    int i = 0;
    for (auto& it : list) {
      data_[i] = it;
      i++;
    }
  }

  BiDirectionalListOnArray(const BiDirectionalListOnArray& list) : size_(list.Size()), capacity_(list.capacity_), data_(new T[list.size_]) {
    for (int i = 0; i < list.Size(); i++) {
      data_[i] = *list[i];
    }
  }

  BiDirectionalListOnArray(BiDirectionalListOnArray&& list) : size_(list.Size()), capacity_(list.Size()), data_(new T[list.Size()]) {
    for (int i = 0; i < list.Size(); i++) {
      data_[i] = std::move(*list[i]);
    }
  }

  ~BiDirectionalListOnArray() {
    delete[] data_;
  }

  int Size() const {
    return size_;
  }

  bool IsEmpty() const {
    return size_ == 0;
  }

  std::vector<T> ToVector() const {
    std::vector<T> vec(size_);
    for (int i = 0; i < size_; i++) {
      vec[i] = data_[i];
    }
  }

  T* Front() const {
    return &data_[0];
  }

  T* Back() const {
    return &data_[size_ - 1];
  }

  void PushFront(const T& value) {
    CheckCapacityOfList();
    ToMoveRight(0);
    data_[0] = val;
    size_++;
  }

  void PushBack(const T& val) {
    CheckCapacity();
    data_[size_++] = val;
  }

  void PushFront(T&& val) {
    CheckCapacityOfList();
    ToMoveRight(0);
    data_[0] = std::move(val);
    size_++;
  }

  void PushBack(T&& val) {
    CheckCapacityOfList();
    data_[size_++] = std::move(val);
  }

  void PopFront() {
    ToMoveLeft(0);
    size_--;
  }

  void PopBack() {
    if (size_ == 0) {
      throw std::exception();
    }
    size_--;
  }

  void InsertBefore(size_t ind, const T& val) {
    CheckCapacityOfList();
    ToMoveRight(ind);
    data_[ind] = val;
    size_++;
  }

  void InsertAfter(size_t index, const T& val) {
    CheckCapacityOfList();
    ToMoveRight(ind + 1);
    data_[ind + 1] = val;
    size_++;
  }

  void InsertBefore(size_t ind, T&& val) {
    CheckCapacityOfList();
    ToMoveRight(ind);
    data_[ind] = std::move(val);
    size_++;
  }

  void InsertAfter(size_t ind, T&& val) {
    CheckCapacityOfList();
    ToMoveRight(ind + 1);
    data_[ind + 1] = std::move(val);
    size_++;
  }

  void Erase(size_t ind) {
    if (ind < 0 || ind >= size_) {
      throw std::exception();
    }
    ToMoveLeft(ind);
    size_--;
  }

  int Find(const T& val) const {
    for (int i = 0; i < size_; i++) {
      if (data_[i] == val) {
        return i;
      }
    }
    return -1;
  }

  std::vector<int> FindAll(const T& val) const {
    std::vector<int> result;
    for (int i = 0; i < size_; i++) {
      if (data_[i] == val) {
        result.push_back(i);
      }
    }
    return result;
  }

  T* operator[](size_t ind) const {
    if (ind < 0 || ind >= size_) {
      throw std::exception();
    }
    return &data_[ind];
  }

  bool operator==(const BiDirectionalListOnArray& list) const {
    if (size_ != list.Size()) {
      return false;
    }
    for (int i = 0; i < size_; i++) {
      if (data_[i] != *list[i]) {
        return false;
      }
    }
    return true;
  }
};

#endif

