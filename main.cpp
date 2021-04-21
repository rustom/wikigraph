#include <iostream>
#include "include/io_handler.hpp"
#include "include/articles.hpp"

int main() {
  wikigraphs::Articles article;

  wikigraphs::IOHandler io;
  
  io.ReadArticles("data/articles.tsv");

}