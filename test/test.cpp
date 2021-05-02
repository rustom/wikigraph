#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream> 
#include "../include/articles.hpp"
#include "../include/io_handler.hpp"

using wikigraphs::Articles;

TEST_CASE("Loading in data files") {
  Articles articles("../data/test/articles.tsv", "../data/test/links.tsv");

  SECTION("Read in articles correctly") {
    REQUIRE()
  }

  SECTION("Read in links correctly") {

  }
}