# CS 225 Data Structures
## Project Proposal (acc11-amallik2-rustomi2)

1. **Leading Question** Given a datasets of Wikipedia articles and their respective links, we want to find the shortest path between any two articles and cluster the entire list of articles into different categories.
2. **Dataset Acquistion and Processing** We propose using the [SNAP Wikipedia Navigation Dataset](https://snap.stanford.edu/data/wikispeedia.html). We'll focus on the links subset of this data, which consists of pairs of article names denoting that the first article contains a hyperlink to the second. This data is provided as a `*.tsv` file, which we can read line by line, delimiting pairs by a \t tab. The total number of lines is 119,882, which we realize is quite large. We propose that we can form a subset of the network for development if needed.

3. **Graph Algorithms** For our graph traversal, we propose to implement a simple BFS using an iterator. We expect the input to our iterator
   constructor to be the starting airport ID node. Every time we call `operator++` on our implemented iterator, we expect it to update its internal
   position to a new airport ID node, until there are no nodes left to traverse. 
   
   For one of our algorithms, we propose implementing Dijikstra's Algorithm. We expect the input to be the starting airport ID node and the destination
   airport ID node. We expect the output to be the shortest path with the smallest number of connections from the starting airport to the destination
   airport.
   
   For our final algorithm, we propose projecting our found shortest path (subgraph) onto a world map, using the locations of the airport IDs. We will 
   map the respective latitude and longitudes of each airport onto the map, and then project our graph. We expect the input to be the shortest path
   found using our Dijikstra's Algorithm implementation.
4. **Timeline** 

   April 7 - sync to complete project proposal and team contract
   
   April 9 - submit project proposal and team contract
   
   April 12 - set up initial repository and Makefile
   
   April 15 - finish reading in data into array format and write simple tests to verify correctness
   
   April 19 - convert array format into graph format and pass simple tests
   
   April 22 - write BFS iterator and verify with tests
   
   April 29 - write Dijikstra's and verify with tests
   
   May 5 - write graph projection onto World Map and verify with tests
   
   May 7 - finish report
   
   May 9 - sync to record final presentation
   
   May 11 - finish editing presentation and submit
