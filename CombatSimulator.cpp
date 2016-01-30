#include "stdafx.h"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main(){

	default_random_engine randomEngine(time(NULL));
	uniform_real_distribution<float> attack(0.0f, 1.0f);

	// Human Properties
	float humanAttack = 0.6f;
	float humanHealth = 250.0f;
	float humanDamage = 200.0f;

	float currentHuman = humanHealth;

	// Zombie Properties
	float zombieAttack = 0.4f;
	float zombieHealth = 150.0f;
	float zombieDamage = 80.0f;

	float currentZombie = zombieHealth;

	float attackResult;

	int numHumans;
	int numZombies;

	char turn = 'H';

	cout << "*** Zombies vs Humans ***\n\n";

	// Get the number of Humans
	cout << "Enter the number of Humans: ";
	cin >> numHumans;

	// Get the number of Zombies
	cout << "Enter the number of Zombies: ";
	cin >> numZombies;

	while ((numHumans > 0) && (numZombies > 0)){

		if (turn == 'H'){
			// Get our attack result
			attackResult = attack(randomEngine);

			// Check if attack was successful
			if (attackResult <= humanAttack){
				currentZombie -= humanDamage;

				if (currentZombie < 0){
					numZombies--;
					currentZombie = zombieHealth;
				}
			}

			turn = 'S';
		}
		else {
			// Get our attack result
			attackResult = attack(randomEngine);

			// Check if attack was successful
			if (attackResult <= zombieAttack){
				currentHuman -= zombieDamage;

				if (currentHuman < 0){
					numHumans--;
					currentHuman = humanHealth;
				}
			}

			turn = 'H';
		}

	}

	if (numHumans == 0){
		cout << "The humans have been defeated.\n\n"; 
		cout << "Results: \n\n";
		cout << "Humans left:	" << numHumans << "\n";
		cout << "Zombies left:	" << numZombies << "\n\n";
	}
	else if (numZombies == 0){
		cout << "The zombies have been defeated.\n\n";
		cout << "Results: \n\n";
		cout << "Humans left:	" << numHumans << "\n";
		cout << "Zombies left:	" << numZombies << "\n\n";
	}

	cout << "Twas a good battle my friends. \n\nCreated by loganCk\n\n";

	system("PAUSE");
	return 0;
}
