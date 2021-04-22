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


vector<string> Articles::ShortestPath(string start, string end) {

  (void) start;
  (void) end;
  return vector<string>();

}

Articles::Iterator::Iterator() {

}

Articles::Iterator::Iterator(Articles * articles, string start) {
  this->articles = articles;
  this->start = start;
}

Articles::Iterator & Articles::Iterator::operator++() {

  return *this;

}

string Articles::Iterator::operator*() {

  return string();

}

bool Articles::Iterator::operator!=(const Iterator &other) {

  (void) other;
  return false;

}


}