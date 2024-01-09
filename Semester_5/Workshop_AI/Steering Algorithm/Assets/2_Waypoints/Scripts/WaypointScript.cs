using UnityEngine;

public class WaypointScript : MonoBehaviour
{
    [Range(0f, 2f)]
    [SerializeField] private float _waypointSize = 1f; // Size of the waypoint spheres for visualization

    [SerializeField] private bool _canloop = true; // Indicates if the waypoints should form a loop
    [SerializeField] private bool _isMovingForward = true; // Indicates the order of traversal between waypoints (forward or backward)

    private void OnDrawGizmos()
    {
        // Visualize the waypoints as blue wireframe spheres
        foreach (Transform t in transform)
        {
            Gizmos.color = Color.blue;
            Gizmos.DrawWireSphere(t.position, _waypointSize);
        }

        // Visualize connections between waypoints as red lines
        Gizmos.color = Color.red;
        for (int i = 0; i < transform.childCount - 1; i++)
        {
            Gizmos.DrawLine(transform.GetChild(i).position, transform.GetChild(i + 1).position);
        }

        // If looping is enabled, draw a connection from the last waypoint to the first
        if (_canloop)
        {
            Gizmos.DrawLine(transform.GetChild(transform.childCount - 1).position, transform.GetChild(0).position);
        }
    }

    // Get the next waypoint in the sequence
    public Transform GetNextWaypoint(Transform currentWaypoint)
    {
        if (currentWaypoint == null)
        {
            // If no current waypoint is provided, start with the first one
            return transform.GetChild(0);
        }

        int currentIndex = currentWaypoint.GetSiblingIndex();
        int nextIndex = currentIndex;

        if (_isMovingForward)
        {
            nextIndex += 1;

            if (nextIndex == transform.childCount)
            {
                // If reaching the end, and looping is enabled, return to the first waypoint
                if (_canloop)
                {
                    nextIndex = 0;
                }
                else
                {
                    // If looping is not enabled, stay at the last waypoint
                    nextIndex -= 1;
                }
            }
        }
        else
        {
            nextIndex -= 1;

            if (nextIndex < 0)
            {
                // If moving backward and reaching the beginning, and looping is enabled, return to the last waypoint
                if (_canloop)
                {
                    nextIndex = transform.childCount - 1;
                }
                else
                {
                    // If looping is not enabled, move to the next waypoint
                    nextIndex += 1;
                }
            }
        }

        return transform.GetChild(nextIndex);
    }
}
