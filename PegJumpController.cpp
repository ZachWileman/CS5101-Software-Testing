//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#include "PegJumpController.h"
#include "PegJumpView.h"
#include <iostream>
using namespace std;

const int numGames = 1;

int main()
{
  PegJumpView View;
  int gameScore[numGames] = {0};
	int gameSelected;

  View.printStart();

	do
	{
		do
		{
      View.gameSelect();

			if (!(cin >> gameSelected))
			{
				cin.clear();
				cin.ignore();
			}

			if (gameSelected == 9)
				View.printMenu(gameScore);

			else if (gameSelected != 1)
        View.invalidChoice();

		} while (gameSelected != 1);
  }

  return 0;
}
