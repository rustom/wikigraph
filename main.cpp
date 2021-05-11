#include <iostream>
#include "include/io_handler.hpp"
#include "include/articles.hpp"

int main(int argc, char** argv) {
  // Print articles map
  // Shortest unweighted path
  // Shortest weighted path
  // Kosaraju's

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

  auto path = articles.ShortestPathUnweighted("Scheme_programming_language", "Duchenne_muscular_dystrophy");
  for (string article : path) {
    std::cout << article << std::endl;
  }

  path = articles.ShortestPathUnweighted("Duchenne_muscular_dystrophy", "Scheme_programming_language");

  for (string article : path) {
    std::cout << article << std::endl;
  }

  vector<vector<string>> clusters = articles.GetClusters();

  for (const auto& cluster : clusters) {
    std::cout << "New Cluster: " << std::endl;
    for (const string & article : cluster) {
      std::cout << "\t" << article << std::endl;
    }
  }

}