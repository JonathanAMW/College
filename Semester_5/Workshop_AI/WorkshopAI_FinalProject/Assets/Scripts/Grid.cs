using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class Grid : MonoBehaviour {

    // Public variables
    public bool displayGridGizmos; // Indicates whether to display grid gizmos in the editor
    public LayerMask unwalkableMask; // Defines the layer mask for unwalkable objects
    public Vector2 gridWorldSize; // Defines the size of the grid in world units
    public float nodeRadius; // Radius of each node in the grid
    Node[,] grid; // 2D array to store nodes in the grid

    // Variables for grid calculations
    float nodeDiameter; // Diameter of a node
    int gridSizeX, gridSizeY; // Size of the grid in X and Y directions

    // Awake method called when the script instance is being loaded
    void Awake() {
        // Calculate node diameter, grid size in X and Y directions, and create the grid
        nodeDiameter = nodeRadius * 2;
        gridSizeX = Mathf.RoundToInt(gridWorldSize.x / nodeDiameter);
        gridSizeY = Mathf.RoundToInt(gridWorldSize.y / nodeDiameter);
        CreateGrid(); // Call the method to create the grid
    }

    // Property to get the maximum size of the grid
    public int MaxSize {
        get {
            return gridSizeX * gridSizeY;
        }
    }

    // Method to create the grid by populating nodes
    void CreateGrid() {
        // Initialize the grid with nodes based on world position calculations
        grid = new Node[gridSizeX, gridSizeY];
        Vector3 worldBottomLeft = transform.position - Vector3.right * gridWorldSize.x / 2 - Vector3.forward * gridWorldSize.y / 2;

        for (int x = 0; x < gridSizeX; x++) {
            for (int y = 0; y < gridSizeY; y++) {
                Vector3 worldPoint = worldBottomLeft + Vector3.right * (x * nodeDiameter + nodeRadius) + Vector3.forward * (y * nodeDiameter + nodeRadius);
                bool walkable = !(Physics.CheckSphere(worldPoint, nodeRadius, unwalkableMask));
                grid[x, y] = new Node(walkable, worldPoint, x, y); // Create a node and assign it to the grid
            }
        }
    }

    // Method to get neighboring nodes for a given node
    public List<Node> GetNeighbours(Node node) {
        List<Node> neighbours = new List<Node>();

        // Loop through adjacent nodes around the given node
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (x == 0 && y == 0)
                    continue;

                int checkX = node.gridX + x;
                int checkY = node.gridY + y;

                // Check if the adjacent node is within the grid boundaries
                if (checkX >= 0 && checkX < gridSizeX && checkY >= 0 && checkY < gridSizeY) {
                    neighbours.Add(grid[checkX, checkY]); // Add the valid adjacent node to the list
                }
            }
        }

        return neighbours; // Return the list of neighboring nodes
    }

    // Method to get a node from a given world position
    public Node NodeFromWorldPoint(Vector3 worldPosition) {
        float percentX = (worldPosition.x + gridWorldSize.x / 2) / gridWorldSize.x;
        float percentY = (worldPosition.z + gridWorldSize.y / 2) / gridWorldSize.y;
        percentX = Mathf.Clamp01(percentX);
        percentY = Mathf.Clamp01(percentY);

        int x = Mathf.RoundToInt((gridSizeX - 1) * percentX);
        int y = Mathf.RoundToInt((gridSizeY - 1) * percentY);
        return grid[x, y]; // Return the node corresponding to the world position
    }

    // Method for drawing grid gizmos in the editor
    void OnDrawGizmos() {
        Gizmos.DrawWireCube(transform.position, new Vector3(gridWorldSize.x, 1, gridWorldSize.y));
        if (grid != null && displayGridGizmos) {
            foreach (Node n in grid) {
                Gizmos.color = (n.walkable) ? Color.white : Color.red;
                Gizmos.DrawCube(n.worldPosition, Vector3.one * (nodeDiameter - 0.1f));
            }
        }
    }
}
