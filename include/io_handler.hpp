#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility> // std::pair
#include <fstream>
#include <sstream> // std::getline

using std::string;
using std::vector;
using std::pair;
using std::ifstream;

namespace wikigraphs { 

class IOHandler {
 public: 

  vector<string> ReadArticles(const string & file_name);

  vector<pair<string, string>> ReadLinks(const string & file_name);

 private: 
};

}