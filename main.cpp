#include <iostream>
#include "include/io_handler.hpp"
#include "include/articles.hpp"

int main() {
  wikigraphs::Articles articles("data/articles.tsv", "data/links.tsv");

  articles.PrintArticleMap();

}