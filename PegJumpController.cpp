//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#include "PegJumpController.h"
#include "PegJumpView.h"

const int numGames = 1;

int main()
{
  PegJumpView View;
  int gameScore[numGames] = {0};
	int gameSelected;
  string gameRestart;

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

    do
    {
      View.playAgain();

      if (!(cin >> gameRestart))
      {
        cin.clear();
        cin.ignore();
      }

      if (gameRestart == "9")
        View.printMenu(gameScore);

    } while (gameRestart == "9");

  } while (gameRestart == "y" || gameRestart == "yes");

  return 0;
}
