#include "../include/articles.hpp"
#include "../include/io_handler.hpp"

using std::string;
using std::unordered_set;
using std::vector;
using std::pair;



namespace wikigraphs {

Articles::Articles(const string & article_path, const string & link_path) {
  wikigraphs::IOHandler io;
  
  vector<string> article_names = io.ReadArticles(article_path);

  vector<pair<string, string>> links = io.ReadLinks(link_path);

  AddArticles(article_names);
  
  AddLinks(links);
}

void Articles::AddArticle(const string & article) {
  articles.insert({article, unordered_set<string>()});
}

void Articles::AddArticles(const vector<string> & articles) {
  for (const string & article : articles) {
    AddArticle(article);
  }
}

void Articles::AddLink(const string & article, const string & link) {
  articles.at(article).insert(link);
}


void Articles::AddLinks(const vector<pair<string, string>> & links) {
  for (const pair<string, string> & link : links) {
    AddLink(link.first, link.second);
    
  }
}

void Articles::PrintArticleMap() {
  for (const auto & article : articles) {
    std::cout << "Article: " << article.first << std::endl;
    for (const string & link : article.second) {
      std::cout << "\t" << link << std::endl;
    }
  }
}

unordered_map<string, unordered_set<string>> Articles::GetArticles() {
  return articles;
}

unordered_set<string> Articles::GetLinkedArticles(const string & article) {
  return articles[article];
}

vector<string> Articles::ShortestPathUnweighted(const string & source, const string & target) {

  unordered_map<string, string> prev;
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

  if (prev.count(target) == 0) {
    std::cout << "No path to target " << target << "." << std::endl;
    return vector<string>();
  }

  vector<string> path;
  string curr = target;
  while (curr != source) {
    path.push_back(curr);
    curr = prev[curr];
  }
  path.push_back(source);
  std::reverse(path.begin(), path.end());

  return path;

}

vector<string> Articles::ShortestPathWeighted(const string & source, const string & target) {

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

Articles::Iterator Articles::begin() {
  auto start_it = articles.begin();
  string start = start_it->first;
  return Iterator(this, start);
}

Articles::Iterator Articles::end() {
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