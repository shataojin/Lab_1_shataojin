#include <iostream>
#include "Game.h"

using namespace std;

void initSomeData(Platform* platforms, int& platformSize) {
	// add xbox and xbox's game
	platforms[platformSize].init("XBox", "Microsoft");

	platforms[platformSize].addGame("Gears of War 4", "Epic Games", "Epic Games");
	Game* game = platforms[platformSize].findGame("Gears of War 4");
	if (game) {
		game->addAchievement("Golden Joystick Awards", "Best game of the year", 80);
		game->addAchievement("The Game Awards", "The 10th Independent Games", 88);
	}

	platforms[platformSize].addGame("Ori and the Blind Forest", "Moon Studios", "Moon Studios");
	Game* game2 = platforms[platformSize].findGame("Ori and the Blind Forest");
	if (game2) {
		game2->addAchievement("The Game Awards", "The 11th Independent Games", 90);
	}

	++platformSize;

	// add ps4 and ps4's game
	platforms[platformSize].init("PS4", "Sony");

	platforms[platformSize].addGame("Bloodborne", "From Software", "Sony Computer Entertainment");
	++platformSize;
}

// display all platforms' games
void displayPlatformNames(Platform* platforms, int platformSize) {
	for (int i = 0; i < platformSize; ++i) {
		cout << i + 1 << ". " << platforms[i].getName() << endl;
	}
	cout << endl;
}

int main() {
	Platform* platforms = new Platform[100];
	int platformSize = 0;

	// init some data for test
	initSomeData(platforms, platformSize);

	cout << "Welcome to Game System" << endl;
	bool loop = true;
	while (loop) {
		cout << endl;
		cout << "Enter options" << endl;
		cout << "1. Display" << endl;
		cout << "2. Create new platform" << endl;
		cout << "3. Create new game" << endl;
		cout << "4. Create new achievement" << endl;
		cout << "5. Exit" << endl;

		int opt;
		cin >> opt;
		cin.ignore(100, '\n');
		switch (opt) {
		case 1: {
			if (platformSize == 0) {
				cout << "No Platform information" << endl;
			}
			else {
				for (int i = 0; i < platformSize; ++i) {
					platforms[i].display();
					cout << endl;
				}
			}
			break;
		}
		case 2: {
			cout << "Enter new platform's name: ";
			string p;
			getline(cin, p);
			cout << "Enter manufacturer: ";
			string m;
			getline(cin, m);
			platforms[platformSize].init(p, m);
			++platformSize;
			cout << "Success add platform" << endl;
			break;
		}
		case 3: {
			// Choose platform
			if (platformSize <= 0) {
				cout << "No platform now" << endl;
				break;
			}
			cout << "Enter platform by index: " << endl;
			displayPlatformNames(platforms, platformSize);
			int idx;
			cin >> idx;
			cin.ignore(100, '\n');
			if (idx < 1 || idx > platformSize) {
				cout << "Invalid platform index" << endl;
				break;
			}
			--idx;

			// Enter game's information
			cout << "Enter game's name: ";
			string n;
			getline(cin, n);
			cout << "Enter publisher: ";
			string p;
			getline(cin, p);
			cout << "Enter developer: ";
			string d;
			getline(cin, d);
			platforms[idx].addGame(n, p, d);
			cout << "Success add game" << endl;
			break;
		}
		case 4: {
			// Choose platform
			if (platformSize <= 0) {
				cout << "No platform now" << endl;
				break;
			}
			cout << "Enter platform by index: " << endl;
			displayPlatformNames(platforms, platformSize);
			int idx;
			cin >> idx;
			cin.ignore(100, '\n');
			if (idx < 1 || idx > platformSize) {
				cout << "Invalid platform index" << endl;
				break;
			}
			--idx;
			
			// choose game
			if (platforms[idx].getGameSize() <= 0) {
				cout << "No game now" << endl;
				break;
			}
			cout << "Enter game by index: " << endl;
			platforms[idx].displayGameNames();
			int idx2;
			cin >> idx2;
			cin.ignore(100, '\n');
			if (idx2 < 1 || idx2 > platforms[idx].getGameSize()) {
				cout << "Invalid game index" << endl;
				break;
			}
			--idx2;

			// enter achievement's information
			cout << "Enter title: ";
			string t;
			getline(cin, t);
			cout << "Enter description: ";
			string d;
			getline(cin, d);
			cout << "Enter score: ";
			int s;
			cin >> s;
			cin.ignore(100, '\n');
			platforms[idx].addAchievement(idx2, t, d, s);
			cout << "Success add achievement" << endl;

			break;
		}
		case 5: {
			// exit loop
			loop = false;
			break;
		}
		default: {
			cout << "Unknown option" << endl;
			break;
		}
		}
	}

	cout << "GG " << endl;
	delete[] platforms;
	return 0;
}