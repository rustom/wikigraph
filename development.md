## Week 1 (04/18 - 04/24)

Loaded in the dataset of article names and links into our Articles class, which stores the nodes and edges of our graph in an unordered_map. 
The keys of our map represent each article in our dataset where the values are sets of strings that refer to the links within that article.
In addition to processing the Wikipedia dataset, we implement our BFS iterator that traverses each of the articles with a queue implementation.
Our BFS iterator also enabled us to create an additional function that finds the shortest path between any two articles.
