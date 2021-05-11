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
   * Default constructor that creates articles graphs with empty list of articles
   * Since there are no articles, there aren't any links as well
   */
  Articles();

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
   * Gets a copy of the unordered map that contains the articles/links within the graph
   */
  unordered_map<string, unordered_set<string>> GetArticles();

  /**
   * Gets the list of links within the specified article
   */
  unordered_set<string> GetLinkedArticles(const string & article);

  /**
   * Utilizes the BFS iterator to find the shortest path from the source article to the target article
   * Returns the list of intermediate articles if there is a path
   * If not, returns an empty list and outputs a message saying there is no possible path
   */
  vector<string> ShortestPathUnweighted(const string & source, const string & target);

  /**
   * Runs Djikstra's algorithm to find the shortest weighted path from the source article to the target
   * Weights each edge based on the number of links at that current article
   * Returns a list of articles that contain the least amount of links in total to get from source to target
   */
  vector<string> ShortestPathWeighted(const string & source, const string & target);

  /**
   * Runs Kosaraju's algorithm to detected strongly connected components (clusters) within the articles graph
   * Articles fall within the same cluster if there a path to each article from each article in the cluster
   * Returns a list of clusters (2D vector) where each inner vector represents a cluster of articles
   */
  vector<vector<string>> GetStronglyConnectedComponents();

  /**
   * BFS (breath-first search) iterator
   * Our traversal algorithm for this articles graph data structure
   */
  class Iterator : std::iterator<std::forward_iterator_tag, string> {
   public:
    /**
     * Default constructor that links to null articles graph
     */
    Iterator();

    /**
     * Sets the start node to the respective article within the specified graph
     */
    Iterator(Articles * articles, const string & start);

    /**
     * Increments the iterator to the next article node in the BFS traversal
     * Updates the current node
     */
    Iterator & operator++();

    /**
     * Deferences the iterator to retrieve the name of the current article
     */
    string operator*();

    /**
     * Determines inequality between two iterator
     * Used to track the end of the BFS traversal
     */
    bool operator!=(const Iterator &other);

   private:

    Articles * article_graph;       // Pointer to the articles graph that the iterator is traversing through
    string current;                 // Name of the current article that the iterator is on
    queue<string> q;                // Queue of articles that the iterator will increment towards
    unordered_set<string> visited;  // List of articles that the iterator has already traversed

  };

  /**
   * Returns an iterator starting at the first article within the graph
   */
  Iterator begin();
  
  /**
   * Returns a NULL iterator
   */
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