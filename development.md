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
