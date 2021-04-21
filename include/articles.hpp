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

  void AddArticle(const string & name);

  void AddLink(const string & article, const string & link);

 private:
  unordered_map<string, vector<string>> articles;
};

}