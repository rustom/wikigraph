#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using std::string;
using std::vector;
using std::unordered_map;
using std::pair;
using std::unordered_set;

namespace wikigraphs {

class Articles {
 public: 
  Articles(const string & article_path, const string & link_path);

  void AddArticle(const string & article);

  void AddArticles(const vector<string> & articles);

  void AddLink(const string & article, const string & link);

  void AddLinks(const vector<pair<string, string>> & links);

  void PrintArticleMap();

 private:
  unordered_map<string, unordered_set<string>> articles;
};

}