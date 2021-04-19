#pragma once
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

namespace wikigraphs {

class Articles {
 public: 
 private:
  unordered_map<string, vector<string>> articles;
};

}