using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WanderScript : MonoBehaviour
{
    public GameObject character;  // Objek karakter yang akan bergerak.
    public GameObject WanderTarget; // Tujuan perambulan karakter.

    private Vector3 velocity;      // Kecepatan karakter.
    public float mass = 15;        // Massa karakter (pengaruh kecepatan).
    public float MaxVelocity = 3;  // Kecepatan maksimum karakter.
    public float MaxForce = 15;    // Besaran gaya maksimum yang dapat diberikan.

    public float CircleRadius = 3;   // Radius lingkaran perambulan.
    public float CircleDistance = 6; // Jarak antara karakter dan pusat lingkaran perambulan.
    public float WanderAngle = 15.0f; // Sudut awal perambulan.
    public float AngleChange = 5;    // Perubahan sudut perambulan.

    void Start()
    {
        InvokeRepeating("NextWayPoint", 2.0f, 5.0f); // Memanggil NextWayPoint setiap beberapa detik.
        velocity = Vector3.zero; // Menginisialisasi kecepatan awal menjadi nol.
    }

    private void NextWayPoint()
    {
        // Mengatur posisi tujuan perambulan karakter secara acak.
        Vector3 wan = new Vector3(Random.Range(-15, 15), 1, Random.Range(-6, 6));
        WanderTarget.transform.position = wan;
        Debug.Log("pindah");
    }

    void Update()
    {
        // Menghitung vektor kecepatan yang diinginkan menuju tujuan perambulan.
        Vector3 desiredVelocity = WanderTarget.transform.position - character.transform.position;
        desiredVelocity = desiredVelocity.normalized * MaxVelocity;

        // Menghitung gaya (steering) untuk perambulan.
        Vector3 wand = desiredVelocity - velocity;
        Vector3 steering = Wander(wand);
        steering = Vector3.ClampMagnitude(steering, MaxForce);
        steering /= mass;

        // Memperbarui kecepatan karakter dengan mempertimbangkan gaya.
        velocity = Vector3.ClampMagnitude(velocity + steering, MaxVelocity);

        // Memindahkan karakter.
        character.transform.position += velocity * Time.deltaTime;

        // Membatasi ketinggian karakter dan mengatur arah hadap karakter sesuai kecepatan.
        character.transform.position = new Vector3(character.transform.position.x, 1, character.transform.position.z);
        character.transform.forward = velocity.normalized;
    }

    private Vector3 Wander(Vector3 velocity)
    {
        // Menghitung pusat lingkaran perambulan.
        Vector3 circleCentre = velocity.normalized;
        circleCentre *= CircleDistance;

        // Menghitung pemindahan (displacement) berdasarkan sudut perambulan.
        Vector3 displacement = new Vector3(Mathf.Clamp01(1.0f), 1, Mathf.Clamp01(1.0f));
        displacement *= CircleRadius;
        displacement = setAngle(displacement, WanderAngle);

        // Mengupdate sudut perambulan dengan variasi acak.
        WanderAngle += Random.Range(0.01f, 1.0f) * AngleChange - AngleChange * 0.5f;

        // Menghitung gaya perambulan.
        Vector3 wanderforce = circleCentre + displacement;
        return wanderforce;
    }

    private Vector3 setAngle(Vector3 vector, float WanderAngle)
    {
        // Mengatur sudut vektor berdasarkan sudut perambulan.
        Vector3 v = vector;
        float len = vector.magnitude;
        v.x = Mathf.Cos(WanderAngle) * len;
        v.z = Mathf.Sin(WanderAngle) * len;
        return v;
    }
}
