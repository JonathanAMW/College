using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SeekFleeScript : MonoBehaviour
{
    [SerializeField] private GameObject _character; // Objek karakter yang akan bergerak.
    [SerializeField] private GameObject _target;    // Objek target yang akan ditemui atau dihindari.

    [SerializeField] private bool _fleeMode = false; // Mode bergerak (seek/flee). Jika true, karakter akan menghindari target.

    private Vector3 _velocity;        // Kecepatan karakter.
    [SerializeField] private float _mass = 15.0f;     // Massa karakter (pengaruh kecepatan).
    [SerializeField] private float _maxVelocity = 3.0f; // Kecepatan maksimum karakter.
    [SerializeField] private float _maxForce = 15.0f;  // Besaran gaya maksimum yang dapat diberikan.

    // Start is called before the first frame update
    void Start()
    {
        _velocity = Vector3.zero; // Menginisialisasi kecepatan awal menjadi nol.
    }

    // Update is called once per frame
    void Update()
    {
        // Menghitung vektor kecepatan yang diinginkan menuju target.
        Vector3 desiredVelocity = _target.transform.position - _character.transform.position;
        desiredVelocity = desiredVelocity.normalized * _maxVelocity;

        // Menghitung gaya (steering) yang diperlukan untuk mencapai kecepatan yang diinginkan.
        Vector3 steering = desiredVelocity - _velocity;
        steering = Vector3.ClampMagnitude(steering, _maxForce);
        steering /= _mass;

        // Memperbarui kecepatan karakter dengan mempertimbangkan gaya.
        _velocity = Vector3.ClampMagnitude(_velocity + steering, _maxVelocity);

        // Memindahkan karakter berdasarkan mode (seek atau flee).
        if (!_fleeMode)
            _character.transform.position += _velocity * Time.deltaTime; // Seek mode.
        else
            _character.transform.position += (-1 * _velocity) * Time.deltaTime; // Flee mode.

        // Membatasi ketinggian karakter dan mengatur arah hadap karakter sesuai kecepatan.
        _character.transform.position = new Vector3(_character.transform.position.x, 1, _character.transform.position.z);
        _character.transform.forward = _velocity.normalized;
    }
}
