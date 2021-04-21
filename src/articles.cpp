#include "../include/articles.hpp"

using std::string;

namespace wikigraphs {

void Articles::AddArticle(const string & article) {
  articles.insert({article, vector<string>()});
}

void Articles::AddArticles(const vector<string> & articles) {
  for (const string & article : articles) {
    AddArticle(article);
  }
}

void Articles::AddLink(const string & article, const string & link) {
  articles.at(article).push_back(link);
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

}