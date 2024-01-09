using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PursueEvade : MonoBehaviour
{
    public GameObject Character;   // Objek karakter yang akan bergerak.
    public GameObject Target;      // Objek target yang akan ditemui atau dihindari.

    public bool IsEvadeMode = false; // Mode bergerak (pursue/evade). Jika true, karakter akan menghindari target.

    private Vector3 _velocity;      // Kecepatan karakter.
    public float Mass = 15;         // Massa karakter (pengaruh kecepatan).
    public float MaxVelocity = 3;   // Kecepatan maksimum karakter.
    public float MaxForce = 15;     // Besaran gaya maksimum yang dapat diberikan.

    // Start is called before the first frame update
    void Start()
    {
        _velocity = Vector3.zero; // Menginisialisasi kecepatan awal menjadi nol.
    }

    // Update is called once per frame
    void Update()
    {
        // Menghitung vektor kecepatan yang diinginkan menuju target.
        Vector3 desiredVelocity = Target.transform.position - Character.transform.position;

        // Menghitung prediksi (pred) berdasarkan perbandingan magnitudo vektor kecepatan yang diinginkan dengan kecepatan maksimum.
        float pred = desiredVelocity.magnitude / MaxVelocity;
        desiredVelocity = desiredVelocity.normalized * MaxVelocity * pred;

        // Menghitung gaya (steering) yang diperlukan untuk mencapai kecepatan yang diinginkan.
        Vector3 steering = desiredVelocity - _velocity;
        steering = Vector3.ClampMagnitude(steering, MaxForce);
        steering /= Mass;

        // Memperbarui kecepatan karakter dengan mempertimbangkan gaya.
        _velocity = Vector3.ClampMagnitude(_velocity + steering, MaxVelocity);

        // Memindahkan karakter berdasarkan mode (pursue atau evade).
        if (!IsEvadeMode)
            Character.transform.position += _velocity * Time.deltaTime; // Pursue mode.
        else
            Character.transform.position += (-1 * _velocity) * Time.deltaTime; // Evade mode.

        // Membatasi ketinggian karakter dan mengatur arah hadap karakter sesuai kecepatan.
        Character.transform.position = new Vector3(Character.transform.position.x, 1, Character.transform.position.z);
        Character.transform.forward = _velocity.normalized;
    }
}
