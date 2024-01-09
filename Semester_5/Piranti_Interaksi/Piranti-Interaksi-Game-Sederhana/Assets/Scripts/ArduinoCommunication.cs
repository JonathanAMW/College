using UnityEngine;
using System.IO.Ports;

public class ArduinoCommunication : MonoBehaviour
{
    public string portName = "COM3"; // Change this to match your Arduino's port
    public int baudRate = 9600;
    public float moveSpeed = 1.0f; // Adjust this value to control the movement speed

    private SerialPort serialPort;
    [SerializeField]private GameObject my2DObject;

    private void Start()
    {
        serialPort = new SerialPort(portName, baudRate);
        serialPort.Open();
        my2DObject = this.gameObject; // Replace "My2DObject" with your actual GameObject's name
    }

    private void Update()
    {
        if (serialPort.IsOpen)
        {
            Debug.Log("bukak");

            string data = serialPort.ReadLine();

            Debug.Log(data);

            // Parse the data (assuming it represents a position value, e.g., a float)
            if (float.TryParse(data, out float newPosition))
            {
                Debug.Log("isok");
                // Update the GameObject's position on the X-axis based on the received data
                Vector3 currentPosition = my2DObject.transform.position;
                currentPosition.x = newPosition * moveSpeed; // Adjust the value as needed
                my2DObject.transform.position = currentPosition;
            }
        }
    }

    private void OnApplicationQuit()
    {
        if (serialPort != null && serialPort.IsOpen)
        {
            serialPort.Close();
        }
    }
}
