#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <random>
#include "memo_map.hpp"

int
main(void) {
  const size_t size = 20;
  memo_map<std::string, double> m(size);
  std::mt19937 mt;
  std::uniform_real_distribution<double> ud(0.0, 1.0);
  typedef std::pair<std::string, int> pair_si;
  std::vector< pair_si >v;
  std::cout << "Input Data" << std::endl;
  for (size_t i = 0; i < size; i++) {
    std::stringstream ss;
    ss << "test" << std::setfill('0') << std::setw(3) << i;
    std::string key = ss.str();
    m[key] = ud(mt);
    std::cout << key << "->";
    std::cout << std::setprecision(4) << std::fixed;
    std::cout << m[key] << std::endl;
  }
  std::cout << "Cached Data" << std::endl;
  for (auto &i : m) {
    std::cout << i.first << "->";
    std::cout << std::setprecision(4) << std::fixed;
    std::cout << i.second << std::endl;
  }
}
