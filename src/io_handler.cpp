#include "../include/io_handler.hpp"

namespace wikigraphs {


vector<string> IOHandler::ReadArticles(const string & file_name) {

    vector<string> article_names;
    std::ifstream articles_file(file_name);
    string line;

    while (!articles_file.eof()) {
        std::getline(articles_file, line);
        article_names.push_back(line);
    }

    return article_names;

}

vector<pair<string, string>> IOHandler::ReadLinks(const string & file_name) {

    vector<pair<string, string>> links;
    std::ifstream links_file(file_name);
    string line;

    while (!links_file.eof()) {

        std::getline(links_file, line, '\t');
        string article = line;
        std::getline(links_file, line, '\n');
        string link = line;
        links.push_back(std::make_pair(article, link));
    }

    return links;

}

}