#include <iostream>
#include "include/io_handler.hpp"
#include "include/articles.hpp"

int main() {
  wikigraphs::Articles articles("data/articles.tsv", "data/links.tsv");

  // articles.PrintArticleMap();

  for (auto it = articles.begin(); it != articles.end(); ++it) {
    std::cout << *it << std::endl;
  }

}