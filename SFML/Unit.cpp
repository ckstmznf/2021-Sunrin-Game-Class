#include "pch.h"
#include "Unit.h"

Unit::Unit(Team team, int hp, float speed, float fireDelayOrigin)
	:team(team),
	hp(hp),
	speed(speed),
	fireDelay(0),
	fireDelayOrigin(fireDelayOrigin),
	die(false)
{

}

void Unit::decreaseHp()
{
	//유닛의 체력을 추가해준다.
	hp--;
	if (hp <= 0) {
		die = true;
	}
}
