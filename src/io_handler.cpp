#include "../include/io_handler.hpp"

namespace wikigraphs {


vector<string> IOHandler::ReadArticles(const string & file_name) {
    
    // Creates ifstream using path to list of articles
    vector<string> article_names;
    std::ifstream articles_file(file_name);
    string line;

    // Adds each article names to the list of articles
    while (!articles_file.eof()) {
        std::getline(articles_file, line);
        article_names.push_back(line);
    }

    return article_names;

}

vector<pair<string, string>> IOHandler::ReadLinks(const string & file_name) {

    // Creates ifstream using path to mapping of links
    vector<pair<string, string>> links;
    std::ifstream links_file(file_name);
    string line;

    while (!links_file.eof()) {
        std::getline(links_file, line, '\t');
        string article = line;
        std::getline(links_file, line, '\n');
        string link = line;

        // Pushes article-link pairing to list of links
        links.push_back(std::make_pair(article, link));
    }

    return links;

}

}