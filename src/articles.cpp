#include "../include/articles.hpp"

using std::string;

namespace wikigraphs {

void Articles::AddArticle(const string & article) {
  articles.insert({article, vector<string>()});
}

void Articles::AddLink(const string & article, const string & link) {
  articles.at(article).push_back(link);
}

}