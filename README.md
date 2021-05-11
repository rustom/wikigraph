# CS 225 Final Project - WikiGraph
### Team Members: Ayan Mallik, Alec Chen, and Rustom Ichhaporia

## Overview

Welcome to WikiGraph! For our final project, we analyzed the [SNAP Wikipedia Navigation Dataset](https://snap.stanford.edu/data/wikispeedia.html), which contains thousands
of articles and lists their respective links. By creating a graph where nodes represent articles and edges represent links, we were able to find the shortest weighted/unweighted
path between any two articles by implementing a BFS iterator along with Djikstra's algorithm. Plus, we used Kosaraju's algorithm to cluster articles that can travel from one
to another.

## Repository Structure

Our repository contains four major folders:

**data** - stores the full dataset of articles and links in addition to small files used for testing 

**include** - holds the header files for the `articles` and `io_handler` classes

**src** - contains the source files for the `articles` and `io_handler` classess

**tests** - contains the two files in the test suite - *catch.hpp* and *test.cpp*

Alongside those four folders, there are two important files: *main.cpp* is the entry point of our main executable and *results.md* holds our results report.

## Setup Requirements

We recommend building and running our main executable or test suite on EWS. Nevertheless, you need to have **Make** set up on your environment to run our program.

## Main Executable

Our main function acts a driver where you can do the following:

- print the contents of the articles graph
- find the shortest unweighted path between a source and target article
- find the shortest weighted path where the weight of each edge is based on the number of links within that current article
- identify clusters of articles where each article in the same cluster can travel to one another

To build the main executable, type the following command in the terminal:
```
make
```

When running the executable, you must specify two arguments: the paths to the articles list and the mapping of links. For running our program on the full dataset, type the 
following:

```
./wikigraphs data/articles.tsv data/links.tsv 
```

## Test Suite

Our test suite covers our BFS iterator, our pathfinding algorithms (weighted and unweighted), and our clustering algorithm usign Kosaraju's technique. Notable tests check the
following features and partitions of our code:

- storage of our Wikipedia dataset within our unordered_map data structure
- ordering of our BFS traversal
- different paths (weighted vs unweighted) for the same source and target articles
- single vs multiple clusters for graphs with the same articles but different links.

To build our test suite, enter the following command:
```
make test
```

Afterwards, run the generated executable by typing:
```
./a.out
```
