# Graph Representation and Dijkstra's Algorithm for Map Navigation

This program demonstrates three different ways to store a graph in C++: edge list, adjacency matrix, and adjacency list. It also utilizes Dijkstra's algorithm to create a basic map navigation system for a small mock city map.
In-depth, information can be found on the [wiki tab](https://github.com/JaysonBam/Basic_Navigation_Algorithm/wiki).<br>
![images](https://github.com/JaysonBam/Basic_Navigation_Algorithm/assets/137817727/06b3677f-d21d-4ed1-94c6-fca4e21ee2a3)
## Files
//to come

## Graph Representations
This program provides three different representations for the graph:
1. **Edge List**: The edges are stored as pairs (source, destination, weight) in an array of some sort.
2. **Adjacency Matrix**: The graph is represented as a 2D matrix, where matrix[i][j] represents the weight of the edge between nodes i and j.
3. **Adjacency List**: Each node is associated with a list of adjacent nodes and their corresponding edge weights.

## Dijkstra's Algorithm
Dijkstra's algorithm is implemented to find the shortest path between two given nodes in the graph. The algorithm is implemented in the `shortestPath` function.

## Program Flow
1. Create a graph using the desired representation (edge list, adjacency matrix, or adjacency list).
2. Add nodes and edges to the graph to represent the mock city map.
3. Prompt the user to enter the source and destination vertices for navigation.
4. Use Dijkstra's algorithm to find the shortest path between the source and destination.
5. Display the shortest path and its total distance to the user.
