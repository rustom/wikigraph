#include "../include/driver.hpp"
#include "../include/articles.hpp"
#include "../include/io_handler.hpp"
#include <fstream>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using wikigraphs::Articles;
using wikigraphs::IOHandler;

namespace wikigraphs {

void Driver::Run(int argc, char **argv) {
  if (argc != 3) {
    throw std::invalid_argument("Must include 2 arguments: paths to articles "
                                "list and mapping of links");
  }

  string articles_path = argv[1];
  string links_path = argv[2];

  Articles articles(articles_path, links_path);

  IOHandler handler;

  string input = " ";

  cout << "Welcome to the wikigraphs program!" << endl;
  cout << "Here you can explore the functionality of our algorithms." << endl;

  while (true) {
    cout << "Please enter a letter for one of the following: " << endl;

    cout << "'k': Write the strongly connected components of the graph to "
            "output/kosaraju.txt using Kosaraju's algorithm"
         << endl;
    cout << "'m': Write the graph of articles to output/article_map.txt"
         << endl;
    cout << "'u': Write the shortest unweighted path between two articles"
         << endl;
    cout << "'w': Write the shortest path between two articles weighted by "
            "the outdegrees of the neighboring nodes"
         << endl;
    cout << "'q': Quit the program" << endl;

    cin >> input;

    if (input == "k") {
      handler.WriteStronglyConnectedComponents(
          articles.GetStronglyConnectedComponents());
    } else if (input == "m") {
      handler.WriteArticles(articles.GetArticles());
    } else if (input == "u") {
      string source;
      string target;
      cout << "Please enter the name of the source article: " << endl;
      cin >> source;
      cout << "Please enter the name of the target article: " << endl;
      cin >> target;

      handler.WritePath(articles.ShortestPathUnweighted(source, target), false);
    } else if (input == "w") {
      string source;
      string target;
      cout << "Please enter the name of the source article: " << endl;
      cin >> source;
      cout << "Please enter the name of the target article: " << endl;
      cin >> target;

      handler.WritePath(articles.ShortestPathWeighted(source, target), true);
    } else if (input == "q") {
      cout << "Thank you for using wikigraphs!" << endl;
      break;
    } else {
      cout << "Please enter a valid option!" << endl << endl;
    }
  }
}

} // namespace wikigraphs