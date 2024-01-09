using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerFSMState_ATTACK : PlayerFSMState
{
    private float m_elaspedTime;

    public GameObject AttackGameObject { get; set; } = null;

    public PlayerFSMState_ATTACK(Player player)
        : base(player)
    {
        _id = PlayerFSMStateType.ATTACK;
    }

    private int _attackID = 0;

    private string _attackName;

    public int AttackId
    {
        get
        {

            return _attackID;
        }
        set
        {
            _attackID = value;

            _attackName = "Attack" + (_attackID + 1).ToString();
        }
    }

    public override void Enter()
    {
        //Debug.Log("PlayerFSMState_ATTACK");

        _player.playerAnimator.SetBool(_attackName, true);

        m_elaspedTime = 0.0f;
    }

    public override void Exit()
    {
        //Debug.Log("PlayerFSMState_ATTACK - Exit");

        _player.playerAnimator.SetBool(_attackName, false);
    }

    public override void Update()
    {
        //Debug.Log("Ammo count: " + _player.totalAmunitionCount + ", InMagazine: " + _player.bulletsInMagazine);

        if (_player.bulletsInMagazine == 0 && _player.totalAmunitionCount > 0)
        {
            _player.playerFSM.SetCurrentState(PlayerFSMStateType.RELOAD);

            return;
        }

        if (_player.totalAmunitionCount == 0)
        {
            //Debug.Log("No ammo");

            _player.playerFSM.SetCurrentState(PlayerFSMStateType.MOVEMENT);

            //_player.playerEffects.NoAmmo();

            return;
        }

        //_player.playerEffects.Aim();

        if (Input.GetButton("Fire1"))
        {
            _player.playerAnimator.SetBool(_attackName, true);

            if (m_elaspedTime == 0.0f)
            {
                Fire();
            }

            m_elaspedTime += Time.deltaTime;

            if (m_elaspedTime > 1.0f / _player.roundsPerSecond)
            {
                m_elaspedTime = 0.0f;
            }
        }
        else
        {
            m_elaspedTime = 0.0f;

            _player.playerAnimator.SetBool(_attackName, false);

            _player.playerFSM.SetCurrentState(PlayerFSMStateType.MOVEMENT);
        }
    }

    void Fire()
    {
        float secs = 1.0f / _player.roundsPerSecond;

        //_player.playerEffects.DelayedFire(secs);

        _player.bulletsInMagazine -= 1;
        ;
    }
}
