#include <iostream>
#include "include/io_handler.hpp"
#include "include/articles.hpp"

int main(int argc, char** argv) {
  if (argc != 3) {
    throw std::invalid_argument("Must include 2 arguments: paths to articles list and mapping of links");
  }

  string articles_path = argv[1];
  string links_path = argv[2];

  wikigraphs::Articles articles(articles_path, links_path);

  //articles.PrintArticleMap();

  // for (auto it = articles.begin(); it != articles.end(); ++it) {
  //   std::cout << *it << std::endl;
  // }

  auto path = articles.ShortestPathWeighted("Antimony", "London");
  for (string article : path) {
    std::cout << article << std::endl;
  }

}