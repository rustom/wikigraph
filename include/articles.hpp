#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using std::string;
using std::vector;
using std::queue;
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

  unordered_set<string> GetLinkedArticles(const string & article);

  vector<string> ShortestPathUnweighted(const string & source, const string & target);

  vector<string> ShortestPathWeighted(const string & source, const string & target);

  class Iterator : std::iterator<std::forward_iterator_tag, string> {
   public:
    Iterator();
    Iterator(Articles * articles, const string & start);

    Iterator & operator++();
    string operator*();
    bool operator!=(const Iterator &other);

   private:

    Articles * article_graph;
    string current;
    queue<string> q;
    unordered_set<string> visited;

  };

  Iterator begin();
  
  Iterator end();

 private:
  unordered_map<string, unordered_set<string>> articles;

  /**
   * Binary search helper for dijkstra's
   * Finds index within list of sorted articles according to path weight in unordered_map values - descending order
   */
  size_t FindIndex(const vector<string> & sorted_list, const unordered_map<string, int> & values, int value);

};

}