# CS 225 Data Structures
## Project Proposal (acc11-amallik2-rustomi2)

1. **Leading Question** 
   Given a datasets of Wikipedia articles and their respective links, we want to find the shortest path between any two articles and cluster the entire list of articles into different categories.

2. **Dataset Acquistion and Processing** 
   We propose using the [SNAP Wikipedia Navigation Dataset](https://snap.stanford.edu/data/wikispeedia.html). We'll focus on the links subset of this data, which consists of pairs of article names denoting that the first article contains a hyperlink to the second. This data is provided as a `*.tsv` file, which we can read line by line, delimiting pairs by a \t tab. The total number of lines is 119,882, which we realize is quite large. We propose that we can form a subset of the network for development and testing if needed. In the end, we will create a directed graph from our Wikipedia dataset where each article is a vertex and the edges represent links within that article to other articles.

3. **Graph Algorithms** 
   For our graph traversal, we will implement a simple BFS using an iterator. Our constructor to the BFS iterator will take in a the name of an article that will act our starting node. Every time we call `operator++` on our implemented iterator, we expect it to update its internal position to a different article in the dataset that was linked by a previous article. Our BFS iterator will end once it has traversed all of the articles in our dataset. 
   
   Our first algorithm will be a pathfinding algorithm that finds the shortest path of any two articles. We propose to implement Dijkstra's Algorithm on our graph to accomplish this task and hope to achieve a runtime of O(ElogV) where V is the number of articles and E is the number of links. Our pathfinding algorithm will take the names of the starting article and the destination article. We expect the output to be the shortest path needing the least number of links to reach the destination article from the starting article.
   
   For our second algorithm, we will use Kosaraju's algorithms to find strongly connected components within our directed graph of Wikipedia articles. By grouping our dataset into different clusters, we hope to find various categories within our datasets where articles within the same category have a path to one another. We hope to reach the optimal runtime of Kosaraju's algorithm of O(V+E) where V and E follow the same definitions as mentioned above.

4. **Timeline** 
   
- [X] April 9 - Submit project proposal and team contract   
- [X] April 16 - Set up Makefile, folder structure, and be able to read in data 
- [ ] April 23 - Create iterators, Dijkstra's algorithm, and their tests 
- [ ] April 29 - Create Kosaraju's algorithms and tests        
- [ ] May 7 - Complete main program driver and report
- [ ] May 8 - Record final presentation and submit
   
