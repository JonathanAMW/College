using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class PlayerFSMState_MOVEMENT : PlayerFSMState
{
    public PlayerFSMState_MOVEMENT(Player player)
        : base(player)
    {
        _id = PlayerFSMStateType.MOVEMENT;
    }

    public override void Enter()
    {
        base.Enter();
    }

    public override void Update()
    {
        base.Update();

        _player.playerMovement.Move();

        //_player.playerEffects.Aim();

        if (Input.GetButton("Fire1"))
        {
            PlayerFSMState_ATTACK attackState = (PlayerFSMState_ATTACK)
                _player.playerFSM.GetState(PlayerFSMStateType.ATTACK);

            attackState.AttackId = 0;

            _player.playerFSM.SetCurrentState(PlayerFSMStateType.ATTACK);
        }

        if (Input.GetButton("Fire2"))
        {
            PlayerFSMState_ATTACK attackState = (PlayerFSMState_ATTACK)
                _player.playerFSM.GetState(PlayerFSMStateType.ATTACK);

            attackState.AttackId = 1;

            _player.playerFSM.SetCurrentState(PlayerFSMStateType.ATTACK);
        }

        if (Input.GetButton("Fire3"))
        {
            PlayerFSMState_ATTACK attackState = (PlayerFSMState_ATTACK)
                _player.playerFSM.GetState(PlayerFSMStateType.ATTACK);

            attackState.AttackId = 2;

            _player.playerFSM.SetCurrentState(PlayerFSMStateType.ATTACK);
        }

        if (Input.GetButton("Crouch"))
        {
            _player.playerFSM.SetCurrentState(PlayerFSMStateType.CROUCH);
        }
    }

    public override void FixedUpdate()
    {
        base.FixedUpdate();
    }
}
