#pragma once
#include "HitPointTypes.hpp"

class Health
{
public:

	bool setMaxHP(hpType new_max_hp)
	{
		if (new_max_hp < 1)
			return false;

		MaxHP = new_max_hp;

		if (CurrentHP > MaxHP)
			CurrentHP = MaxHP;

		return true;
	}

	hpType getMaxHP()
	{
		return MaxHP;
	}

	hpType getCurrentHP()
	{
		return CurrentHP;
	}

	// Verhindert, dass wenn man mehr Schaden macht
	// als man Leben hat stirbt und nicht ein
	// negatives HP hat
	void takeDamage(hpType damage)
	{
		if (damage > CurrentHP)
		{
			CurrentHP = 0;
			return;
		}

		// Zieht damage vom Leben ab
		CurrentHP -= damage;
	}

	void heal(hpType amount)
	{
		// Pr�ft ob das aktuelle HP gr��er ist als
		// die erlaubten maximale HP (verhindert overhealing)
		if (amount + CurrentHP > MaxHP)
		{
			CurrentHP = 0;
			return;
		}

		// Wenn der aktuelle HP kleiner ist als Max HP
		// so kann gehealt werden
		CurrentHP += amount;
	}



private:
	// hpType ShieldHP; // Kommt sp�ter, ist komplizierter. Wenn man schaden erh�lt wird es erst vom Schild abgezogen
	hpType CurrentHP;
	hpType MaxHP;
};