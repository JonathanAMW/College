using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerFSMState_TAKE_DAMAGE : PlayerFSMState
{
    public PlayerFSMState_TAKE_DAMAGE(Player player)
        : base(player)
    {
        _id = PlayerFSMStateType.TAKE_DAMAGE;
    }

    public override void Enter() { }

    public override void Exit() { }

    public override void Update() { }

    public override void FixedUpdate() { }
}
