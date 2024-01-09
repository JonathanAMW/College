using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerFSMState_CROUCH : PlayerFSMState
{
    public PlayerFSMState_CROUCH(Player player)
        : base(player)
    {
        _id = PlayerFSMStateType.CROUCH;
    }

    public override void Enter()
    {
        _player.playerAnimator.SetBool("Crouch", true);
    }

    public override void Exit()
    {
        _player.playerAnimator.SetBool("Crouch", false);
    }

    public override void Update()
    {
        if (Input.GetButton("Crouch")) { }
        else
        {
            _player.playerFSM.SetCurrentState(PlayerFSMStateType.MOVEMENT);
        }
    }

    public override void FixedUpdate() { }
}
