## Week 1 (04/18 - 04/24)

Loaded in the dataset of article names and links into our Articles class, which stores the nodes and edges of our graph in an unordered_map. 
The keys of our map represent each article in our dataset where the values are sets of strings that refer to the links within that article.
In addition to processing the Wikipedia dataset, we implement our BFS iterator that traverses each of the articles with a queue implementation.
Our BFS iterator also enabled us to create an additional function that finds the shortest path between any two articles.

## Week 2 (04/25 - 05/01)

Came up with the idea of weighting each edge of our graph based on the number of links that the current article has. By intergrating weights into
our design, we were able to run Dijkstra's Algorithm, which allows us to find the shortest weighted path between any two articles on the graph.
With our definition of weights, our path from Djikstra's Algorithm can be interpreted as having to search through the least amount of links from
the starting article to the destination article. We also worked on documenting our code before focusing on testing/clustering for the final stretch.

## Week 3 (05/02 - 05/08)

Documented both of the main header files (articles and io_handler) to provide meaningful yet concise descriptions about their functionality and
implementation. Afterwards, we set up the test suite for our final project codebase using catch templates from earlier machine problems. From there,
we tested each of the three pieces of the project that we've completed so far (BFS iterator, shortest unweighted path, and shorted weighted path using
Djikstra's algorithm). Our main focus for this last week is to wrap up Kosaraju's algorithm and film our final project video. Additionally, we need to
complete the various documents including our README.md and our results report.
