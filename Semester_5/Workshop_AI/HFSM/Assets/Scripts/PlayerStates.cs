using UnityEngine;

public class PlayerGroundedState : PlayerBaseState
{
    public PlayerGroundedState(PlayerStateMachine currentContext, PlayerStateFactory playerStateFactory)
    : base (currentContext, playerStateFactory) 
    {
        _isRootState = true;
        InitializeSubState();
    }

    public override void EnterState()
    {
        Debug.Log("Grounded");
    }
    public override void ExitState(){}
    public override void UpdateState()
    {
        CheckSwitchStates();
    }

    public override void CheckSwitchStates()
    {
        if(_ctx.IsJumpPressed)
        {
            SwitchState(_factory.Jump());
        }
    }

    public override void InitializeSubState()
    {
        if(!_ctx.IsMovementPressed)
        {
            SetSubState(_factory.Idle());
        }
        else
        {
            SetSubState(_factory.Move());
        }
    }

}

public class PlayerJumpState : PlayerBaseState
{
    public PlayerJumpState(PlayerStateMachine currentContext, PlayerStateFactory playerStateFactory)
    : base (currentContext, playerStateFactory) 
    {
        _isRootState = true;
        InitializeSubState();
    }

    public override void EnterState()
    {
        Debug.Log("Jump");
    }
    public override void ExitState()
    {

    }

    public override void UpdateState()
    {
        CheckSwitchStates();
    }

    public override void CheckSwitchStates()
    {
        if(_ctx.IsGrounded)
        {
            SwitchState(_factory.Grounded());
        }
    }

    public override void InitializeSubState()
    {
        if(!_ctx.IsMovementPressed)
        {
            SetSubState(_factory.Idle());
        }
        else
        {
            SetSubState(_factory.Move());
        }
    }

}

public class PlayerIdleState : PlayerBaseState
{
    public PlayerIdleState(PlayerStateMachine currentContext, PlayerStateFactory playerStateFactory)
    : base (currentContext, playerStateFactory) {}
    public override void EnterState()
    {
        Debug.Log("Idle");
    }
    public override void ExitState(){}
    public override void UpdateState()
    {
        CheckSwitchStates();
    }

    public override void CheckSwitchStates()
    {
        if(_ctx.IsMovementPressed)
        {
            SwitchState(_factory.Move());
        }
    }
    public override void InitializeSubState(){}

}

public class PlayerMoveState : PlayerBaseState
{
    public PlayerMoveState(PlayerStateMachine currentContext, PlayerStateFactory playerStateFactory)
    : base (currentContext, playerStateFactory) {}
    public override void EnterState()
    {
        Debug.Log("Move");
    }
    public override void ExitState(){}
    public override void UpdateState()
    {
        CheckSwitchStates();
    }

    public override void CheckSwitchStates()
    {
        if(!_ctx.IsMovementPressed)
        {
            SwitchState(_factory.Idle());
        }
    }

    public override void InitializeSubState(){}

}