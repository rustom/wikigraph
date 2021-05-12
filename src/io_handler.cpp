#include "../include/io_handler.hpp"

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::make_pair;
using std::ofstream;
using std::unordered_map;
using std::unordered_set;

namespace wikigraphs {

vector<string> IOHandler::ReadArticles(const string &file_name) {

  // Creates ifstream using path to list of articles
  vector<string> article_names;
  ifstream articles_file(file_name);
  string line;

  // Adds each article names to the list of articles
  while (!articles_file.eof()) {
    getline(articles_file, line);
    article_names.push_back(line);
  }

  return article_names;
}

vector<pair<string, string>> IOHandler::ReadLinks(const string &file_name) {

  // Creates ifstream using path to mapping of links
  vector<pair<string, string>> links;
  ifstream links_file(file_name);
  string line;

  while (!links_file.eof()) {
    getline(links_file, line, '\t');
    string article = line;
    getline(links_file, line, '\n');
    string link = line;

    // Pushes article-link pairing to list of links
    links.push_back(make_pair(article, link));
  }

  return links;
}

void IOHandler::WriteStronglyConnectedComponents(
    const vector<vector<string>> &components) {
  ofstream file;
  file.open("output/kosaraju.txt");

  for (const auto &component : components) {
    file << "New Cluster: " << endl;
    for (const string &article : component) {
      file << "\t" << article << endl;
    }
  }

  file.close();
}

void IOHandler::WriteArticles(
    const unordered_map<string, unordered_set<string>> &articles) {
  ofstream file;
  file.open("output/article_map.txt");

  for (const auto &article : articles) {
    file << "Article: " << article.first << endl;
    for (const string &link : article.second) {
      file << "\t" << link << endl;
    }
  }

  file.close();
}

void IOHandler::WritePath(const vector<string> &path, bool isWeighted) {
  ofstream file;

  string filename = "output/";

  filename += isWeighted ? "weighted_" : "unweighted_"; 

  filename += "path_" + path[0] + "_to_" + path[path.size() - 1] + ".txt";

  file.open(filename);

  for (size_t i = 0; i < path.size(); ++i) {
    file << i << " " << path[i] << endl;
  }

  file.close();
}

} // namespace wikigraphs