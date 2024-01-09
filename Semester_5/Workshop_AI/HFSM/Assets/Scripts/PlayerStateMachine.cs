using System.Collections;
using UnityEngine;

public class PlayerStateMachine : MonoBehaviour
{
    private PlayerBaseState _currentState;
    private PlayerStateFactory _states;

    public PlayerBaseState CurrentState {get{return _currentState;} set{_currentState = value;}}
    
    public bool IsJumpPressed {get; private set;} = false;
    public bool IsMovementPressed {get; private set;} = false;
    public bool IsGrounded {get; private set;} = false;


    private void Awake()
    {
        _states = new PlayerStateFactory(this);
        _currentState = _states.Grounded();
        _currentState.EnterState();
    }
    
    private void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space))
        {
            IsJumpPressed = true;
            IsGrounded = false;
            StartCoroutine("GroundedReset");
        }
        if(Input.GetKeyDown(KeyCode.A))
        {
            IsMovementPressed = true;
        }
        
        _currentState.UpdateStates();


        //Reset
        if(IsJumpPressed)
        {
            IsJumpPressed = false;
        }
        if (IsMovementPressed)
        {
            IsMovementPressed = false;
        }
    }

    private IEnumerator GroundedReset()
    {
        yield return new WaitForSeconds(3f);
        IsGrounded = true;
    }
}
