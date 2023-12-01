using UnityEngine;
using System.Collections;

public class Node : IHeapItem<Node> {
	
	public bool walkable; // Flag indicating if the node is walkable or not
	public Vector3 worldPosition; // Position of the node in world space
	public int gridX; // X index of the node in the grid
	public int gridY; // Y index of the node in the grid

	public int gCost; // Cost from the starting node to this node
	public int hCost; // Heuristic cost from this node to the target node
	public Node parent; // Reference to the parent node in the pathfinding process
	int heapIndex; // Index used in the heap data structure
	
	public Node(bool _walkable, Vector3 _worldPos, int _gridX, int _gridY) {
		walkable = _walkable; // Assigning walkable flag
		worldPosition = _worldPos; // Assigning world position
		gridX = _gridX; // Assigning grid X index
		gridY = _gridY; // Assigning grid Y index
	}

	// Calculates the total cost of the node (gCost + hCost)
	public int fCost {
		get {
			return gCost + hCost;
		}
	}

	// Property for heap index of the node
	public int HeapIndex {
		get {
			return heapIndex;
		}
		set {
			heapIndex = value;
		}
	}

	// Compares the fCost and hCost of this node with another node
	public int CompareTo(Node nodeToCompare) {
		int compare = fCost.CompareTo(nodeToCompare.fCost); // Compare fCosts
		
		if (compare == 0) { // If fCosts are equal, compare hCosts
			compare = hCost.CompareTo(nodeToCompare.hCost);
		}
		
		return -compare; // Return the comparison result
	}
}
