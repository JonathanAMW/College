using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System;

public class Pathfinding : MonoBehaviour {
    
    PathRequestManager requestManager; // Reference to the PathRequestManager script
    Grid grid; // Reference to the Grid script
    
    void Awake() {
        requestManager = GetComponent<PathRequestManager>(); // Get the PathRequestManager component
        grid = GetComponent<Grid>(); // Get the Grid component
    }
    
    
    public void StartFindPath(Vector3 startPos, Vector3 targetPos) {
        StartCoroutine(FindPath(startPos, targetPos)); // Start the FindPath coroutine
    }
    
    IEnumerator FindPath(Vector3 startPos, Vector3 targetPos) {

        Vector3[] waypoints = new Vector3[0]; // Initialize an array for waypoints
        bool pathSuccess = false; // Flag indicating whether the path was found
        
        Node startNode = grid.NodeFromWorldPoint(startPos); // Get the node from the world position
        Node targetNode = grid.NodeFromWorldPoint(targetPos); // Get the target node from the world position
        
        
        if (startNode.walkable && targetNode.walkable) { // Check if start and target nodes are walkable
            Heap<Node> openSet = new Heap<Node>(grid.MaxSize); // Create a heap for open nodes
            HashSet<Node> closedSet = new HashSet<Node>(); // Create a set for closed nodes
            openSet.Add(startNode); // Add the start node to the open set
            
            while (openSet.Count > 0) { // Iterate while there are nodes in the open set
                Node currentNode = openSet.RemoveFirst(); // Get the node with the lowest F cost
                closedSet.Add(currentNode); // Add the current node to the closed set
                
                if (currentNode == targetNode) { // Check if the target node is reached
                    pathSuccess = true; // Set pathSuccess flag to true
                    break;
                }
                
                foreach (Node neighbour in grid.GetNeighbours(currentNode)) { // Loop through node's neighbors
                    if (!neighbour.walkable || closedSet.Contains(neighbour)) {
                        continue; // Skip if the neighbor is unwalkable or already evaluated
                    }
                    
                    int newMovementCostToNeighbour = currentNode.gCost + GetDistance(currentNode, neighbour);
                    if (newMovementCostToNeighbour < neighbour.gCost || !openSet.Contains(neighbour)) {
                        neighbour.gCost = newMovementCostToNeighbour; // Update neighbor's movement cost
                        neighbour.hCost = GetDistance(neighbour, targetNode); // Update neighbor's heuristic cost
                        neighbour.parent = currentNode; // Set neighbor's parent node
                        
                        if (!openSet.Contains(neighbour))
                            openSet.Add(neighbour); // Add the neighbor to the open set if not already present
                    }
                }
            }
        }
        yield return null; // Wait for one frame
        
        if (pathSuccess) { // If the path is found
            waypoints = RetracePath(startNode, targetNode); // Retrace the path between start and target nodes
        }
        requestManager.FinishedProcessingPath(waypoints, pathSuccess); // Notify the PathRequestManager of the finished path processing
        
    }
    
    // Method to retrace the path from start to end node
    Vector3[] RetracePath(Node startNode, Node endNode) {
        List<Node> path = new List<Node>(); // Create a list to store the path nodes
        Node currentNode = endNode; // Start from the end node
        
        while (currentNode != startNode) { // Iterate until the start node is reached
            path.Add(currentNode); // Add the current node to the path
            currentNode = currentNode.parent; // Move to the parent node
        }
        Vector3[] waypoints = SimplifyPath(path); // Simplify the path by removing unnecessary nodes
        Array.Reverse(waypoints); // Reverse the waypoints to get the correct order
        return waypoints; // Return the simplified waypoints
        
    }
    
    // Method to simplify the path by removing redundant waypoints
    Vector3[] SimplifyPath(List<Node> path) {
        List<Vector3> waypoints = new List<Vector3>(); // Create a list to store simplified waypoints
        Vector2 directionOld = Vector2.zero; // Store the old direction
        
        for (int i = 1; i < path.Count; i++) {
            Vector2 directionNew = new Vector2(path[i - 1].gridX - path[i].gridX, path[i - 1].gridY - path[i].gridY);
            if (directionNew != directionOld) { // If the direction changes
                waypoints.Add(path[i].worldPosition); // Add the waypoint
            }
            directionOld = directionNew; // Update the old direction
        }
        return waypoints.ToArray(); // Return the simplified waypoints as an array
    }
    
    // Method to calculate the distance between two nodes (heuristic function)
    int GetDistance(Node nodeA, Node nodeB) {
        int dstX = Mathf.Abs(nodeA.gridX - nodeB.gridX);
        int dstY = Mathf.Abs(nodeA.gridY - nodeB.gridY);
        
        if (dstX > dstY)
            return 14 * dstY + 10 * (dstX - dstY); // Diagonal movement cost
        return 14 * dstX + 10 * (dstY - dstX); // Straight movement cost
    }
}
