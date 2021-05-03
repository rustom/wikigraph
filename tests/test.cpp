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
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::pair;
using std::cout;
using std::endl;

// Helper methods
void PrintGraph(unordered_map<string, unordered_set<string>> graph) {
  for (pair<const string, unordered_set<string>> & p : graph) {
    cout << p.first << ": ";
    for (const string & s : p.second) {
      cout << s << ", ";
    }
    cout << endl;
  }
}

TEST_CASE("Loading in data files") {
  REQUIRE(1 == 1);
  Articles articles("data/tests/articles.tsv", "data/tests/links.tsv");
  unordered_map<string, unordered_set<string>> structure = articles.GetArticles();

  unordered_map<string, unordered_set<string>> solution;
  solution.insert({"1", unordered_set<string>({"1", "2"})});
  solution.insert({"2", unordered_set<string>({"3"})});
  solution.insert({"3", unordered_set<string>({"4"})});
  solution.insert({"4", unordered_set<string>({"1"})});

  REQUIRE(solution == structure);
}

TEST_CASE("Shortest paths") {
  Articles articles("data/tests/articles.tsv", "data/tests/links.tsv");

  SECTION("Unweighted") {
    REQUIRE(articles.ShortestPathUnweighted("1", "4") == vector<string>({"1", "2", "3", "4"}));
  } 

  SECTION("Weighted") {
    // Fix this output
    REQUIRE(articles.ShortestPathWeighted("4", "3") == vector<string>({"4", "1", "2", "3" }));
  }
}
