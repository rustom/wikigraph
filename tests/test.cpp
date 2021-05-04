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
  for (const pair<const string, unordered_set<string>> & p : graph) {
    cout << p.first << ": ";
    for (const string & s : p.second) {
      cout << s << ", ";
    }
    cout << endl;
  }
}

TEST_CASE("Loading in data files") {
  Articles articles("data/tests/articles.tsv", "data/tests/links.tsv");
  unordered_map<string, unordered_set<string>> structure = articles.GetArticles();

  unordered_map<string, unordered_set<string>> solution;
  solution.insert({"1", unordered_set<string>({"1", "2", "5"})});
  solution.insert({"2", unordered_set<string>({"2", "3", "5"})});
  solution.insert({"3", unordered_set<string>({"4", "6"})});
  solution.insert({"4", unordered_set<string>({"3"})});
  solution.insert({"5", unordered_set<string>({"4"})});
  solution.insert({"6", unordered_set<string>({"2"})});

  REQUIRE(solution == structure);
}

TEST_CASE("BFS Iterator") {
  Articles articles("data/tests/articles.tsv", "data/tests/links.tsv");
  Articles::Iterator it = articles.begin();

  SECTION("BFS Iterator follows queue sequence when traversing articles") {
    REQUIRE(*it == "6");
    ++it;

    REQUIRE(*it == "2");
    ++it;

    REQUIRE(*it == "3");
    ++it;

    REQUIRE(*it == "5");
    ++it;

    REQUIRE(*it == "4");
    ++it;

    REQUIRE(*it == "End of iterator");
  }
}

TEST_CASE("Shortest paths") {
  Articles articles("data/tests/articles.tsv", "data/tests/links.tsv");

  SECTION("Unweighted") {
    REQUIRE(articles.ShortestPathUnweighted("1", "6") == vector<string>({"1", "2", "3", "6"}));
  } 

  SECTION("Weighted") {
    // Fix this output
    REQUIRE(articles.ShortestPathWeighted("4", "2") == vector<string>({"4", "3", "6", "2"}));
  }

  SECTION("Weighted and Unweighted can produce different shortest paths") {
    REQUIRE(articles.ShortestPathUnweighted("1", "3") == vector<string>({"1", "2", "3"}));
    REQUIRE(articles.ShortestPathWeighted("1", "3") == vector<string>({"1", "5", "4", "3" }));
  }
}
