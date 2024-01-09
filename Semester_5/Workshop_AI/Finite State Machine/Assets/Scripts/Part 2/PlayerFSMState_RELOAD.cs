using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerFSMState_RELOAD : PlayerFSMState
{
    public float ReloadTime = 3.0f;

    float dt = 0.0f;

    public int previousState;

    public PlayerFSMState_RELOAD(Player player)
        : base(player)
    {
        _id = PlayerFSMStateType.RELOAD;
    }

    public override void Enter()
    {
        //Debug.Log("PlayerFSMState_RELOAD");

        _player.playerAnimator.SetTrigger("Reload");

        dt = 0.0f;
    }

    public override void Exit()
    {
        if (_player.totalAmunitionCount > _player.maxAmunitionBeforeReload)
        {
            _player.bulletsInMagazine += _player.maxAmunitionBeforeReload;

            _player.totalAmunitionCount -= _player.bulletsInMagazine;
        }
        else if (
            _player.totalAmunitionCount > 0
            && _player.totalAmunitionCount < _player.maxAmunitionBeforeReload
        )
        {
            _player.bulletsInMagazine += _player.totalAmunitionCount;

            _player.totalAmunitionCount = 0;
        }

        //Debug.Log("PlayerFSMState_RELOAD - Exit");
    }

    public override void Update()
    {
        dt += Time.deltaTime;

        //_player.playerAnimator.SetTrigger("Reload");

        //_player.playerEffects.Reload();

        if (dt >= ReloadTime)
        {
            //Debug.Log("Reload complete in " + dt);

            _player.playerFSM.SetCurrentState(PlayerFSMStateType.MOVEMENT);
        }
    }

    public override void FixedUpdate() { }
}
