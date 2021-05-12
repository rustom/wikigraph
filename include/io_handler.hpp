#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility> // std::pair
#include <fstream>
#include <sstream> // std::getline
#include <unordered_map>
#include <unordered_set>

using std::string;
using std::vector;
using std::pair;
using std::ifstream;
using std::unordered_map;
using std::unordered_set;

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

  /** 
   * Writes Kosaraju's strongly connected components to a file in the output directory. 
   */
  void WriteStronglyConnectedComponents(const vector<vector<string>> & components);

  /** 
   * Writes the graph of articles to a file in the output directory.
   */
  void WriteArticles(const unordered_map<string, unordered_set<string>> & articles);

  /** 
   * Writes a path of articles to the output directory.
   */
  void WritePath(const vector<string> & path, bool isWeighted);

 private: 
};

}