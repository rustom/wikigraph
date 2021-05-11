#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "../include/articles.hpp"
#include "../include/io_handler.hpp"

using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using wikigraphs::Articles;

// Helper methods
void PrintGraph(unordered_map<string, unordered_set<string>> graph) {
  for (const pair<const string, unordered_set<string>> &p : graph) {
    cout << p.first << ": ";
    for (const string &s : p.second) {
      cout << s << ", ";
    }
    cout << endl;
  }
}

TEST_CASE("Loading in data files") {
  Articles articles("data/tests/articles.tsv", "data/tests/links.tsv");
  unordered_map<string, unordered_set<string>> structure =
      articles.GetArticles();

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

  SECTION("BFS Iterator follows queue sequence when traversing articles") {
    Articles::Iterator it = articles.begin();

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

  SECTION("Adding a new link to the articles graphs changes the ordering of "
          "the BFS traversal") {
    articles.AddLink("6", "4");
    Articles::Iterator it = articles.begin();

    REQUIRE(*it == "6");
    ++it;

    REQUIRE(*it == "2");
    ++it;

    REQUIRE(*it == "4");
    ++it;

    REQUIRE(*it == "3");
    ++it;

    REQUIRE(*it == "5");
    ++it;

    REQUIRE(*it == "End of iterator");
  }

  SECTION("Adding new links between disconnected components expands number of "
          "articles visited") {
    articles.AddLink("3", "1");
    Articles::Iterator it = articles.begin();

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

    REQUIRE(*it == "1");
    ++it;

    REQUIRE(*it == "End of iterator");
  }
}

TEST_CASE("Determing shortest path from source to target article") {
  Articles articles("data/tests/articles.tsv", "data/tests/links.tsv");

  SECTION("Unweighted (BFS Traversal)") {
    REQUIRE(articles.ShortestPathUnweighted("1", "6") ==
            vector<string>({"1", "2", "3", "6"}));
  }

  SECTION("Weighted (Djikstra's algorithm)") {
    // Fix this output
    REQUIRE(articles.ShortestPathWeighted("4", "2") ==
            vector<string>({"4", "3", "6", "2"}));
  }

  SECTION("Weighted and Unweighted can produce different shortest paths") {
    REQUIRE(articles.ShortestPathUnweighted("1", "3") ==
            vector<string>({"1", "2", "3"}));
    REQUIRE(articles.ShortestPathWeighted("1", "3") ==
            vector<string>({"1", "5", "4", "3"}));
  }
}

TEST_CASE("Determing no path from source to target article") {
  Articles articles("data/tests/articles.tsv", "data/tests/links.tsv");

  SECTION("Unweighted path algorithm returns empty list") {
    REQUIRE(articles.ShortestPathUnweighted("6", "1") == vector<string>());
  }

  SECTION("Weighted path algorithm also returns empty list") {
    REQUIRE(articles.ShortestPathWeighted("6", "1") == vector<string>());
  }
}

TEST_CASE(
    "Kosaraju's algorithm identifies clusters of articles within the graph") {
  SECTION("Articles graph has multiple clusters of articles") {
    Articles articles("data/tests/articles.tsv",
                      "data/tests/multiple_clusters_links.tsv");
    vector<vector<string>> clusters = articles.GetClusters();

    SECTION("Number of clusters") { REQUIRE(clusters.size() == 3); }

    SECTION("First cluster") {
      REQUIRE(clusters.at(0) == vector<string>({"3", "5", "2", "6"}));
    }

    SECTION("Second cluster") {
      REQUIRE(clusters.at(1) == vector<string>({"1"}));
    }

    SECTION("Third cluster") {
      REQUIRE(clusters.at(2) == vector<string>({"4"}));
    }
  }
  SECTION("Articles graph has single cluster containing all the artices") {
    Articles articles("data/tests/articles.tsv",
                      "data/tests/single_cluster_links.tsv");
    vector<vector<string>> clusters = articles.GetClusters();

    SECTION("Number of clusters") { REQUIRE(clusters.size() == 1); }

    SECTION("Single cluster contains all of the articles") {
      REQUIRE(clusters.at(0) == vector<string>({"1", "2", "3", "4", "5", "6"}));
    }
  }
}
