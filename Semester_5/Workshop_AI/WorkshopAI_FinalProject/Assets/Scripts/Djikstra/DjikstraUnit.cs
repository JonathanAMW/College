using UnityEngine;
using System.Collections;

public class DjikstraUnit : MonoBehaviour {
	[SerializeField] private Transform target; // Reference to the target the unit will move towards
    private Vector3[] path; // Array to hold the calculated path
    private int targetIndex; // Index of the current target waypoint in the path
    private float speed = 15; // Speed of the unit

    void Start()
    {
        // Start the coroutine to continuously follow the target
        StartCoroutine("FollowTarget");
    }

    IEnumerator FollowTarget()
    {
        while (true)
        {
            // Request a new path to the current position of the moving target
            DijkstraPathRequestManager.RequestPath(transform.position, target.position, OnPathFound);

            // Wait for some time before updating the path
            yield return new WaitForSeconds(0.1f); // Adjust the time interval as needed
        }
    }

    // Callback method called when a path is found
    public void OnPathFound(Vector3[] newPath, bool pathSuccessful)
    {
        if (pathSuccessful)
        {
            path = newPath; // Assign the new path
            targetIndex = 0; // Reset the target index to the beginning of the path
            StopCoroutine("FollowPath"); // Stop any existing coroutine for following the path
            StartCoroutine("FollowPath"); // Start following the new path
        }
    }

    IEnumerator FollowPath()
    {
		if(path == null || path.Length == 0) yield break;

        Vector3 currentWaypoint = path[0]; // Get the first waypoint from the path
        while (true)
        {
            if (transform.position == currentWaypoint) // Check if the unit reached the current waypoint
            {
                targetIndex++; // Move to the next waypoint in the path
                if (targetIndex >= path.Length) // Check if reached the end of the path
                {
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
