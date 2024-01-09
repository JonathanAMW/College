using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Patterns;


public enum PlayerFSMStateType
{
    MOVEMENT = 0,

    CROUCH,

    ATTACK,

    RELOAD,

    TAKE_DAMAGE,

    DEAD,
}

public class PlayerFSMState : State
{
    public PlayerFSMStateType ID
    {
        get { return _id; }
    }

    protected Player _player = null;

    protected PlayerFSMStateType _id;

    public PlayerFSMState(FSM fsm, Player player)
        : base(fsm)
    {
        _player = player;
    }

    public PlayerFSMState(Player player)
        : base()
    {
        _player = player;

        m_fsm = _player.playerFSM;
    }

    public override void Enter()
    {
        base.Enter();
    }

    public override void Exit()
    {
        base.Exit();
    }

    public override void Update()
    {
        base.Update();
    }

    public override void FixedUpdate()
    {
        base.FixedUpdate();
    }
}
