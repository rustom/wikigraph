#include "../include/articles.hpp"
#include "../include/io_handler.hpp"

using std::string;
using std::unordered_set;
using std::vector;
using std::pair;

namespace wikigraphs {

Articles::Articles() {

}

Articles::Articles(const string & article_path, const string & link_path) {
  // Sets up io_handler to read list of articles and mapping of links
  wikigraphs::IOHandler io;
  vector<string> article_names = io.ReadArticles(article_path);
  vector<pair<string, string>> links = io.ReadLinks(link_path);

  // Adds list of articles and links to the articles graph
  AddArticles(article_names);
  AddLinks(links);
}

void Articles::AddArticle(const string & article) {
  articles.insert({article, unordered_set<string>()});
}

void Articles::AddArticles(const vector<string> & articles) {
  // Traverses list of articles to add each new node to the graph
  for (const string & article : articles) {
    AddArticle(article);
  }
}

void Articles::AddLink(const string & article, const string & link) {
  // Adds each link to its respective article
  articles.at(article).insert(link);
}


void Articles::AddLinks(const vector<pair<string, string>> & links) {
  // Traverses each article-link pair in the list of links
  for (const pair<string, string> & link : links) {
    AddLink(link.first, link.second); 
  }
}

unordered_map<string, unordered_set<string>> Articles::GetArticles() {
  return articles;
}

unordered_set<string> Articles::GetLinkedArticles(const string & article) {
  return articles[article];
}

vector<string> Articles::ShortestPathUnweighted(const string & source, const string & target) {
  // Used for backtracking the path of articles from source to target
  unordered_map<string, string> prev;

  // Sets up a BFS iterator starting from the source article
  auto it = Iterator(this, source);
  while (it != end()) {
    string curr = *it;
    unordered_set<string> neighbors = articles[curr];
    for (string article : neighbors) {
      if (prev.count(article) == 0) {
        prev[article] = curr;
      }
    }
    if (prev.count(target) == 1) {
      break;
    }
    ++it;
  }

  // Alerts the user if there's no path from source to target and returns an empty lists
  if (prev.count(target) == 0) {
    std::cout << "No path to target " << target << "." << std::endl;
    return vector<string>();
  }

  // Backtracking
  vector<string> path;
  string curr = target;
  while (curr != source) {
    path.push_back(curr);
    curr = prev[curr];
  }
  path.push_back(source);

  // Reverses the path to put it in its correct ordering
  std::reverse(path.begin(), path.end());

  return path;

}

vector<string> Articles::ShortestPathWeighted(const string & source, const string & target) {
  // Extra local variables that are part of Djikstra's algorithm
  // Djikstra's algorithm requires more space than a standard BFS traversal
  unordered_map<string, string> prev_vis;
  unordered_map<string, int> dist;
  vector<string> next;

  prev_vis[source] = "";
  dist[source] = 0;
  next.push_back(source);

  while (!next.empty()) {

    string next_article = next.back();
    int min_dist = dist[next_article];
    next.pop_back();

    if (next_article == target) {
      break;
    }

    unordered_set<string> adj_articles = articles[next_article];
    for (const string & adj_article : adj_articles) {
      if (prev_vis.count(adj_article) == 1) {
        continue;
      }

      prev_vis[adj_article] = next_article;
      int edge_weight = articles[adj_article].size();
      int new_dist = edge_weight + min_dist;
      dist[adj_article] = new_dist;

      size_t index = FindIndex(next, dist, new_dist);
      next.insert(next.begin() + index, adj_article);

    }

  }

  // Beyond is same as in unweighted path
  if (prev_vis.count(target) == 0) {
    std::cout << "No path to target " << target << "." << std::endl;
    return vector<string>();
  }

  // Backtracking
  vector<string> path;
  string curr = target;
  while (curr != source) {
    path.push_back(curr);
    curr = prev_vis[curr];
  }
  path.push_back(source);
  std::reverse(path.begin(), path.end());

  return path;

}

vector<vector<string>> Articles::GetStronglyConnectedComponents() {
  unordered_set<string> visited_articles;

  // Runs BFS traversal to fill list of visited articles
  for (const string & articles : *this) {
    visited_articles.insert(articles);
  }

  // Transposes the articles graph to run Kosaraju's algorithm
  Articles transposed_graph;

  // Adds each article to the transposed graph
  for (const auto & article : articles) {
    transposed_graph.AddArticle(article.first);
  }

  // Reverses each link to fill the contents of the transposed graph
  for (const auto & article : articles) {
    for (const string & link : article.second) {
      transposed_graph.AddLink(link, article.first);
    }
  }

  vector<vector<string>> clusters;

  // Continues to extract new clusters until there are no articles left
  while (!visited_articles.empty()) {
    vector<string> cluster;

    // Runs BFS iterator on the transposed graph starting at the next visited article
    for (auto it = Iterator(&transposed_graph, *(visited_articles.begin())); it != end(); ++it) {
      string article = *it;

      // Adds the revisited article to the cluster before removing it from the list
      if (visited_articles.find(article) != visited_articles.end()) {
        cluster.push_back(article);
        visited_articles.erase(article);
      }
    }

    clusters.push_back(cluster);
  }

  return clusters;
}

Articles::Iterator Articles::begin() {
  // Creates a BFS iterator starting at the first article in the unordered_map
  auto start_it = articles.begin();
  string start = start_it->first;
  return Iterator(this, start);
}

Articles::Iterator Articles::end() {
  // Returns a default (NULL) iterator
  return Iterator();
}

Articles::Iterator::Iterator() {
  article_graph = NULL;
}

Articles::Iterator::Iterator(Articles * articles, const string & start) {
  article_graph = articles;
  current = start;
  q.push(current);
  visited.insert(current);
}

Articles::Iterator & Articles::Iterator::operator++() {
  if (q.empty()) {
    return *this;
  }

  q.pop();
  unordered_set<string> neighbors = article_graph->GetLinkedArticles(current);
  for (const string & article : neighbors) {
    bool vis = visited.find(article) != visited.end();
    if (!vis) {
      q.push(article);
      visited.insert(article);
    }
  }

  if (q.empty()) {
    article_graph = NULL;
    current = "End of iterator";
  } else {
    current = q.front();
  }

  return *this;
}

string Articles::Iterator::operator*() {
  return current;
}

bool Articles::Iterator::operator!=(const Iterator &other) {
  bool thisEmpty = false; 
  bool otherEmpty = false;

  if (article_graph == NULL) { thisEmpty = true; }
  if (other.article_graph == NULL) { otherEmpty = true; }

  if (thisEmpty && otherEmpty) return false; // both empty then they both have null graphs
  else if ((!thisEmpty)&&(!otherEmpty)) return (q != other.q); // both not empty then compare the traversals
  else return true;
}


size_t Articles::FindIndex(const vector<string> & sorted_list, const unordered_map<string, int> & values, int value) {
  // Used for running Djikstra's algorithm
  int left = 0, right = sorted_list.size();
  while (left != right) {
      int mid = (left + right) / 2;
      if (values.at(sorted_list[mid]) == value) {
          return mid;
      } else if (value > values.at(sorted_list[mid])) {
          right = mid;
      } else {
          left = mid + 1;
      }
  }

  return left;
}

}