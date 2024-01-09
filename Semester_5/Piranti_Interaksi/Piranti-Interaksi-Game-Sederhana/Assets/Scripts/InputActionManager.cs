using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class InputActionManager : MonoBehaviour
{
    [SerializeField] InputActionAsset asset;


    private void Awake()
    {
        asset.Enable();
        
    }

    private void OnDestroy()
    {
        asset.Disable();
    }
    
}
