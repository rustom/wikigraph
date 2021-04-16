#include <iostream>
#include "include/io_handler.hpp"
#include "include/article.hpp"

int main() {
  wikigraphs::Article article;
  std::cout << article.GetName() << std::endl;
}