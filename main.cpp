#include <iostream>
#include "include/io_handler.hpp"
#include "include/articles.hpp"

int main() {
  wikigraphs::Articles articles;

  wikigraphs::IOHandler io;
  
  std::vector<std::string> article_names = io.ReadArticles("data/articles.tsv");

  std::vector<std::pair<std::string, std::string>> links = io.ReadLinks("data/links.tsv");

}