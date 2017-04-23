#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

template<class Key, class Value>
class memo_map : public std::unordered_map<Key, Value> {
private:
  size_t max_size;
  void halves_data(void) {
    typedef std::pair<Key, Value> ptype;
    std::vector< ptype >v;
    for (auto &i : *this) {
      v.push_back(i);
    }
    std::sort(v.begin(), v.end(),
    [](const ptype & x, const ptype  & y) {return x.second > y.second;});
    this->clear();
    for (size_t j = 0; j < max_size / 2; j++) {
      auto i = v[j];
      (*this)[i.first] = i.second;
    }
  }
public:
  memo_map(size_t m) : max_size(m) {
  }
  Value& operator[] (const Key& key) {
    if (this->size() == max_size) {
      halves_data();
    }
    return std::unordered_map<Key, Value>::operator[](key);
  }
};
