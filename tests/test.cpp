#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream> 
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>

#include "../include/articles.hpp"
#include "../include/io_handler.hpp"

using wikigraphs::Articles;
using std::string;
using std::unordered_map;
using std::unordered_set;

TEST_CASE("Loading in data files") {
  REQUIRE(1 == 1);
  Articles articles("data/tests/articles.tsv", "data/tests/links.tsv");
  unordered_map<string, unordered_set<string>> structure = articles.GetArticles();
  articles.PrintArticleMap();

  unordered_map<string, unordered_set<string>> solution;
  solution.insert({"1", unordered_set<string>({"1", "2"})});
  solution.insert({"2", unordered_set<string>({"3"})});
  solution.insert({"3", unordered_set<string>({"4"})});
  solution.insert({"4", unordered_set<string>({})});
  std::cout << "hellO";
  REQUIRE(solution == structure);
}

