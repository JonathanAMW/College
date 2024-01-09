using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerFSMState_DEAD : PlayerFSMState
{
    public PlayerFSMState_DEAD(Player player)
        : base(player)
    {
        _id = PlayerFSMStateType.DEAD;
    }

    public override void Enter()
    {
        Debug.Log("Player dead");

        _player.playerAnimator.SetTrigger("Die");
    }

    public override void Exit() { }

    public override void Update() { }

    public override void FixedUpdate() { }
}
