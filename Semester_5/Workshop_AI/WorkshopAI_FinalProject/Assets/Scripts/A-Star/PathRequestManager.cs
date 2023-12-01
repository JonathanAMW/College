using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System;

public class PathRequestManager : MonoBehaviour {

	Queue<PathRequest> pathRequestQueue = new Queue<PathRequest>(); // Queue to store path requests
	PathRequest currentPathRequest; // Current path request being processed

	static PathRequestManager instance; // Singleton instance of the PathRequestManager
	Pathfinding pathfinding; // Reference to the Pathfinding script for path calculations

	bool isProcessingPath; // Flag to indicate if a path is being processed

	void Awake() {
		instance = this; // Assign the current instance to the singleton
		pathfinding = GetComponent<Pathfinding>(); // Get the Pathfinding component
	}

	// Static method to request a path from PathRequestManager
	public static void RequestPath(Vector3 pathStart, Vector3 pathEnd, Action<Vector3[], bool> callback) {
		PathRequest newRequest = new PathRequest(pathStart, pathEnd, callback); // Create a new path request
		instance.pathRequestQueue.Enqueue(newRequest); // Enqueue the new request
		instance.TryProcessNext(); // Attempt to process the next path request
	}

	// Attempt to process the next path request in the queue
	void TryProcessNext() {
		if (!isProcessingPath && pathRequestQueue.Count > 0) { // Check if not processing a path and queue is not empty
			currentPathRequest = pathRequestQueue.Dequeue(); // Dequeue the next path request
			isProcessingPath = true; // Set flag to indicate processing
			pathfinding.StartFindPath(currentPathRequest.pathStart, currentPathRequest.pathEnd); // Start finding the path
		}
	}

	// Method called when a path has finished processing
	public void FinishedProcessingPath(Vector3[] path, bool success) {
		currentPathRequest.callback(path, success); // Invoke the callback with the path result
		isProcessingPath = false; // Reset processing flag
		TryProcessNext(); // Attempt to process the next path request
	}

	// Structure to hold a path request
	struct PathRequest {
		public Vector3 pathStart;
		public Vector3 pathEnd;
		public Action<Vector3[], bool> callback;

		public PathRequest(Vector3 _start, Vector3 _end, Action<Vector3[], bool> _callback) {
			pathStart = _start;
			pathEnd = _end;
			callback = _callback;
		}
	}
}


