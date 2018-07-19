#include <iostream>
#include <random>
#include <ctime>
#include <string>


int randomBetween(int min, int max)
{
	if (min == max)
	{
		return min;
	}
	else if (min > max)
	{
		randomBetween(max, min);
	}

	int range = max - min;

	int randomValue = rand() % (range + 1);
	randomValue += min;

	return randomValue;
}

int doAttack(const int& curArmour, const int& curAccuracy, const int& curDamage) //Two Knights Fighting, where the health and armour are of the defending knight,
{																		   //and the accuracy and damage are of the attacking knight.
	int randHit = randomBetween(1, curAccuracy);
	int randAC = randomBetween(1, curArmour);

	std::cout << randHit << " Attack VS " << randAC << " AC\n";

	if (randHit >= randAC)
	{
		int randDamage = randomBetween(1, curDamage);
		std::cout << "The defending knight was hit for " << randDamage << " damage!\n";
		return randDamage;
	}
	else
	{
		std::cout << "The attack missed\n";
		return 0;
	}
}

void draw(int knightOne, std::string knightOneName, int knightTwo, std::string knightTwoName)
{
	std::cout << "\n" << knightOneName << ":\t" << knightOne << "\n" << knightTwoName << ":\t" << knightTwo << std::endl;
}

int main() //-----------------------------------------------------------------------------------------
{
	srand((unsigned int)time(nullptr));


	bool yourTurn = true;
	bool surrender = false;

	char action = 0;

	const int totalKnights = 1000;
	int knightStats[1000][4];



	for (int i = 0; i < totalKnights; i++)
	{
		knightStats[i][0] = 100; //Health
		knightStats[i][1] = 20;  //Attack
		knightStats[i][2] = 20;  //Defense
		knightStats[i][3] = 8;	 //Damage
	}

	std::string knightName[1000];

	for (int i = 0; i < totalKnights; i++)
	{
		knightName[i] = std::string("Knight ") + std::to_string(i + 1);

		//std::cout << knightName[i] << "\tHP: " << knightStats[i][0] << "\t Att: " << knightStats[i][1] << "\tDef: " << knightStats[i][2] << "\tDam: " << knightStats[i][3] << std::endl;
	}

	std::cout << "Your name is " << knightName[0] << ".\nYou were going about your daily routine when suddenly:\n" << std::endl;

	int opponentKnight = randomBetween(1, totalKnights);

	std::cout << "You were challenged to a duel by " << knightName[opponentKnight] << std::endl;
	std::cout << knightName[0] << " has " << knightStats[0][0] << " hit points!\n" << knightName[opponentKnight]<< " Has " << knightStats[opponentKnight][0] << " hit points\n";

	std::cout << "\nPress A for Attack\nPress D for Defend\nPress S for Surrender\n\n";
	system("pause");

	//Attacking Phase
	while (knightStats[0][0] > 0 && knightStats[opponentKnight][0] > 0 && !surrender)
	{
		knightStats[0][3] = 20;


		if (!surrender)
		{
			std::cout << "\n" << knightName[0] << "'s Turn!\n";
			std::cin >> action;
			switch (action)
			{
			case 'a':
			case 'A':
			{
				std::cout << "\n" << knightName[0] << " attacks!\n";
				knightStats[opponentKnight][0] -= doAttack(knightStats[opponentKnight][1], knightStats[0][2], knightStats[0][3]); //if the attack hits, knight health = knight health - damage roll

				if (knightStats[opponentKnight][0] < 0)
				{
					knightStats[opponentKnight][0];
				}
				draw(knightStats[0][0], knightName[0], knightStats[opponentKnight][0], knightName[opponentKnight]);

				break;
			}
			case 'd':
			{
				std::cout << knightName[0] << "defends for this turn";
				knightStats[0][1] += 10;
				break;
			}
			case 's':
			{
				std::cout << knightName[0] << ": I surrender! You have bested me!\n";
				surrender = true;
				break;
			}

			}
		}
		if (!surrender && knightStats[opponentKnight][0] > 0)
		{
			std::cout << "\n" << knightName[opponentKnight] << "'s Turn!\n";
			system("pause");
			std::cout << "\n" << knightName[opponentKnight] << " attacks!\n";
			knightStats[0][0] -= doAttack(knightStats[0][1], knightStats[opponentKnight][2], knightStats[opponentKnight][3]);
			if (knightStats[0][0] < 0)
			{
				knightStats[0][0] = 0;
			}
			draw(knightStats[0][0], knightName[0], knightStats[opponentKnight][0], knightName[opponentKnight]);
		}

	}

	system("pause");
	return 0;
}