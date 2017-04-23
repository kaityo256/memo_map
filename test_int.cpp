#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <random>
#include "memo_map.hpp"

int
main(void) {
  const size_t size = 20;
  memo_map<std::string, int> m(size);
  std::mt19937 mt;
  std::uniform_int_distribution<int> ud(0, 100);
  typedef std::pair<std::string, int> pair_si;
  std::vector< pair_si >v;
  std::cout << "Input Data" << std::endl;
  for (size_t i = 0; i < size; i++) {
    std::stringstream ss;
    ss << "test" << std::setfill('0') << std::setw(3) << i;
    std::string key = ss.str();
    m[key] = ud(mt);
    std::cout << key << "->";
    std::cout << std::setfill('0') << std::setw(3);
    std::cout << m[key] << std::endl;
  }
  std::cout << "Cached Data" << std::endl;
  for (auto &i : m) {
    std::cout << i.first << "->";
    std::cout << std::setfill('0') << std::setw(3);
    std::cout << i.second << std::endl;
  }
}
