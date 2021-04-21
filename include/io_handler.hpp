#pragma once

#include <string>
#include <vector>
#include <utility> // std::pair

using std::string;
using std::vector;
using std::pair;

namespace wikigraphs { 

class IOHandler {
 public: 

  vector<string> ReadArticles(const string & file_name);

  vector<pair<string, string>> ReadLinks(const string & file_name);

 private: 
};

}