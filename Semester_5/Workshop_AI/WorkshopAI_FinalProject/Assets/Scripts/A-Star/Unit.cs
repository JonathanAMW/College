using UnityEngine;
using System.Collections;

public class Unit : MonoBehaviour {

	public Transform target; // Reference to the target the unit will move towards
	float speed = 20; // Speed of the unit
	Vector3[] path; // Array to hold the calculated path
	int targetIndex; // Index of the current target waypoint in the path

	void Start() {
		// Request a path from the PathRequestManager when the unit starts
		PathRequestManager.RequestPath(transform.position, target.position, OnPathFound);
	}

	// Callback method called when a path is found
	public void OnPathFound(Vector3[] newPath, bool pathSuccessful) {
		if (pathSuccessful) { // Check if the path was calculated successfully
			path = newPath; // Assign the new path
			targetIndex = 0; // Reset the target index to the beginning of the path
			StopCoroutine("FollowPath"); // Stop any existing coroutine for following the path
			StartCoroutine("FollowPath"); // Start following the new path
		}
	}

	// Coroutine to move the unit along the calculated path
	IEnumerator FollowPath() {
		Vector3 currentWaypoint = path[0]; // Get the first waypoint from the path
		while (true) {
			if (transform.position == currentWaypoint) { // Check if the unit reached the current waypoint
				targetIndex++; // Move to the next waypoint in the path
				if (targetIndex >= path.Length) { // Check if reached the end of the path
					yield break; // End the coroutine if reached the end of the path
				}
				currentWaypoint = path[targetIndex]; // Update the current waypoint
			}

			// Move the unit towards the current waypoint
			transform.position = Vector3.MoveTowards(transform.position, currentWaypoint, speed * Time.deltaTime);
			yield return null; // Wait for the next frame
		}
	}

	// Method to draw gizmos for visualizing the path
	public void OnDrawGizmos() {
		if (path != null) { // Check if a path exists
			for (int i = targetIndex; i < path.Length; i++) {
				Gizmos.color = Color.black;
				Gizmos.DrawCube(path[i], Vector3.one); // Draw a cube at each waypoint in the path

				if (i == targetIndex) {
					Gizmos.DrawLine(transform.position, path[i]); // Draw a line from the unit to the current waypoint
				} else {
					Gizmos.DrawLine(path[i - 1], path[i]); // Draw a line between consecutive waypoints
				}
			}
		}
	}
}
