using UnityEngine;

public class WaypointMOver : MonoBehaviour
{
    [SerializeField] private WaypointScript _waypoints; // Reference to a WaypointScript for managing waypoints
    [SerializeField] private float _moveSpeed = 5f; // Movement speed of the object

    [Range(0f, 15f)]
    [SerializeField] private float _rotateSpeed = 4f; // Rotation speed of the object
    [SerializeField] private float _distanceThreshold = 0.1f; // Distance threshold to consider reaching a waypoint

    private Transform _currentWaypoint; // Reference to the current waypoint the object is moving towards

    private Quaternion _rotationGoal; // Quaternion representing the desired rotation of the object
    private Vector3 _directionToWaypoint; // Direction vector towards the current waypoint

    // Start is called before the first frame update
    private void Start()
    {
        // Initialize the object's position and look direction based on the first waypoint

        // Get the first waypoint from the WaypointScript
        _currentWaypoint = _waypoints.GetNextWaypoint(_currentWaypoint);

        // Set the object's position to the waypoint's position
        transform.position = _currentWaypoint.position;

        // Get the next waypoint and make the object look at it for initial orientation
        _currentWaypoint = _waypoints.GetNextWaypoint(_currentWaypoint);

        // Make the object look at the next waypoint
        transform.LookAt(_currentWaypoint);
    }

    // Update is called once per frame
    void Update()
    {
        // Move the object towards the current waypoint
        transform.position = Vector3.MoveTowards(transform.position, _currentWaypoint.position, _moveSpeed * Time.deltaTime);

        // Check if the object is close enough to the current waypoint
        if (Vector3.Distance(transform.position, _currentWaypoint.position) < _distanceThreshold)
        {
            // If the object is close enough, get the next waypoint and adjust the object's orientation
            _currentWaypoint = _waypoints.GetNextWaypoint(_currentWaypoint);

            // Make the object look at the next waypoint
            transform.LookAt(_currentWaypoint);
        }

        // Call a method to rotate the object towards the current waypoint
        RotateTowardsWaypoint();
    }

    private void RotateTowardsWaypoint()
    {
        // Calculate the direction vector towards the current waypoint
        _directionToWaypoint = (_currentWaypoint.position - transform.position).normalized;

        // Calculate the desired rotation using Quaternion.LookRotation
        _rotationGoal = Quaternion.LookRotation(_directionToWaypoint);

        // Smoothly interpolate the object's rotation towards the desired rotation
        transform.rotation = Quaternion.Slerp(transform.rotation, _rotationGoal, _rotateSpeed * Time.deltaTime);
    }
}



// public class WaypointMOver : MonoBehaviour
// {
//     [SerializeField] private WaypointScript _waypoints; // Reference to a WaypointScript for managing waypoints
//     [SerializeField] private float _moveSpeed = 5f; // Movement speed of the object
//     [SerializeField] private float _distanceThreshold = 0.1f; // Distance threshold to consider reaching a waypoint

//     private Transform _currentWaypoint; // Reference to the current waypoint the object is moving towards

//     // Start is called before the first frame update
//     private void Start()
//     {
//         // Initialize the object's position and look direction based on the first waypoint
//         _currentWaypoint = _waypoints.GetNextWaypoint(_currentWaypoint); // Get the first waypoint
//         transform.position = _currentWaypoint.position; // Set the object's position to the waypoint's position

//         // Get the next waypoint and make the object look at it for initial orientation
//         _currentWaypoint = _waypoints.GetNextWaypoint(_currentWaypoint); // Get the next waypoint
//         transform.LookAt(_currentWaypoint); // Make the object look at the next waypoint
//     }

//     // Update is called once per frame
//     void Update()
//     {
//         // Move the object towards the current waypoint
//         transform.position = Vector3.MoveTowards(transform.position, _currentWaypoint.position, _moveSpeed * Time.deltaTime);

//         // Check if the object is close enough to the current waypoint
//         if (Vector3.Distance(transform.position, _currentWaypoint.position) < _distanceThreshold)
//         {
//             // If the object is close enough, get the next waypoint and adjust the object's orientation
//             _currentWaypoint = _waypoints.GetNextWaypoint(_currentWaypoint); // Get the next waypoint
//             transform.LookAt(_currentWaypoint); // Make the object look at the next waypoint
//         }
//     }
// }
