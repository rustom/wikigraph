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

/**
 * Articles stores the graph of articles 
 * Nodes represent Wikipedia articles
 * Edges represent links from one article to another
 */
class Articles {
 public: 
  /**
   * Builds the article graph by loading in the articles/links from the respective files
   * Takes in strings that act as file paths to dataset
   */
  Articles(const string & article_path, const string & link_path);

  /**
   * Adds a new article with no links to the unordered map
   */
  void AddArticle(const string & article);

  /**
   * Adds a list of new articles with no links
   */
  void AddArticles(const vector<string> & articles);

  /**
   * Adds a new link to an existing article in the unordered map
   */
  void AddLink(const string & article, const string & link);

  /**
   * Adds a list of article-link pairs to the unordered map
   */
  void AddLinks(const vector<pair<string, string>> & links);

  /**
   * Prints the content of the article graph
   */
  void PrintArticleMap();

  /**
   * Gets a copy of the unordered map that contains the articles/links within the graph
   */
  unordered_map<string, unordered_set<string>> GetArticles();

  /**
   * Gets the list of links within the specified article
   */
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
  /**
   * Contains the articles/links within the article graph
   * Each key maps to a different article
   * Values store the list of links at the specified article
   */
  unordered_map<string, unordered_set<string>> articles;

  /**
   * Binary search helper for Dijkstra's algorithm
   * Finds index within list of sorted articles according to path weight in unordered_map values - descending order
   */
  size_t FindIndex(const vector<string> & sorted_list, const unordered_map<string, int> & values, int value);

};

}