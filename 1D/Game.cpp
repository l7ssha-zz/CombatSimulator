#include "Game.h"

using namespace std;

Game::Game()
{
}


Game::~Game()
{
}

void Game::game()
{
	//Dont forget to seed your random engine with time!
	default_random_engine randomEngine(time(NULL));
	uniform_real_distribution<float> attack(0.0f, 1.0f);

	// Human properties
	float humanAttack = 0.1f;
	float humanHealth = 250.0f;
	float humanDamage = 200.0f;
	float currentHumanHealth = humanHealth;

	//skeleton properties
	float skeletonAttack = 0.6f;
	float skeletonHealth = 50.0f;
	float skeletonDamage = 40.0f;
	float currentSkeletonHealth = skeletonHealth;

	float attackResult;

	int startSkeletons;
	int startHumans;

	int numSkeletons;
	int numHumans;

	char turn = 'H';

	cout << "*** Skeletons Vs Humans! ***\n\n";

	//Get the number of humans
	cout << "Enter the number of humans: ";
	cin >> numHumans;

	startHumans = numHumans;

	//Get the number of skeletons
	cout << "Enter the number of skeletons: ";
	cin >> numSkeletons;

	startSkeletons = numSkeletons;

	//cout << "\nBeginning combat!\n\n";

	while ((numHumans > 0) && (numSkeletons > 0)) {
		//Get our attack result
		attackResult = attack(randomEngine);

		// Humans turn
		if (turn == 'H') {

			//Check if attack was successful
			if (attackResult <= humanAttack) {
				currentSkeletonHealth -= humanDamage;

				if (currentSkeletonHealth < 0) {
					numSkeletons--;
					currentSkeletonHealth = skeletonHealth;
				}
			}
			//now its skellys turn!
			turn = 'S';

		}
		else { // if its not humans turn, then we know its skellys turn!

			if (attackResult <= skeletonAttack) {
				currentHumanHealth -= skeletonDamage;

				if (currentHumanHealth < 0) {
					numHumans--;
					currentHumanHealth = humanHealth;
				}
			}
			//now its humans turn!
			turn = 'H';

		}

	}

	cout << "\nBattle is over!\n\n";

	//print out the results!
	if (numHumans > 0) {
		cout << "Humans won!\n";
		cout << "There are " << numHumans << " humans left!\n";
	}
	else {
		cout << "Skeletons won!\n";
		cout << "There are " << numSkeletons << " skeletons left!\n";
	}

	//KILL COUNTER!
	cout << startHumans - numHumans << " humans and " << startSkeletons - numSkeletons << " skeletons lost their lives.\n\n";

	system("PAUSE");
}
