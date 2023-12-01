using UnityEngine;

public class TargetMovementController : MonoBehaviour
{
    private Rigidbody _rb;
    private int _speed = 20;

    private void Awake()
    {
        _rb = GetComponent<Rigidbody>();
    }

    private void FixedUpdate()
    {
        float moveHorizontal = Input.GetAxis("Horizontal");
        float moveVertical = Input.GetAxis("Vertical");

        Vector3 movement = new Vector3(moveHorizontal, 0.0f, moveVertical);
        Vector3 newPosition = transform.position + movement * _speed * Time.deltaTime;

        // Use Rigidbody.MovePosition to update the object's position
        _rb.MovePosition(newPosition);
    }
}
