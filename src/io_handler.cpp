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

    string name = file_name;
    return vector<pair<string, string>>();

}

}