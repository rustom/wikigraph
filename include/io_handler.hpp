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

/**
 * IOHandler parses the files containing the articles/links
 * Extracts the files' contents to form the structure of the article graph\
 */
class IOHandler {
 public: 
  /**
   * Reads the list of articles that act as the keys for the article graph
   */
  vector<string> ReadArticles(const string & file_name);

  /**
   * Reads the file containing the list of article-list pairs
   * Returns the values within the article graph
   */
  vector<pair<string, string>> ReadLinks(const string & file_name);

 private: 
};

}