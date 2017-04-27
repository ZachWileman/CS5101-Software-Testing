//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#include "PegJumpModel.h"

// Function: Autosolve's the peg jump game at whatever state the passed in "tempBoard" is at
// Retutns: bool value that is true if there was a solution found, false if not
bool PegJumpModel::autoSolver(Board tempBoard, vector<Peg> remainingPegs, vector<char> &solutionList)
{
  static vector<char> finalSolution;

	for (int i = 0; i < remainingPegs.size(); i++)
	{
		for (int j = i+1; j < remainingPegs.size(); j++)
		{
			if (tempBoard.checkMove(remainingPegs[i].getPeg(), remainingPegs[j].getPeg()))
			{
				Board newBoard = tempBoard;
				vector<Peg> newPegs = remainingPegs;
				vector<char> newSolutions = solutionList;

				newBoard.updateBoard(newPegs[i].getPeg(), newPegs[j].getPeg());
				newSolutions.push_back(newPegs[i].getPeg());
				newSolutions.push_back(newPegs[j].getPeg());
				newPegs = newBoard.remainingPegs();

				if (newBoard.checkWin())
				{
          finalSolution = newSolutions;
          return true;
				}
				else
				{
					if (autoSolver(newBoard, newPegs, newSolutions))
          {
            solutionList = finalSolution;
            return true;
          }
        }
			}

			if (tempBoard.checkMove(remainingPegs[j].getPeg(), remainingPegs[i].getPeg()))
			{
				Board newBoard = tempBoard;
				vector<Peg> newPegs = remainingPegs;
				vector<char> newSolutions = solutionList;

				newBoard.updateBoard(newPegs[j].getPeg(), newPegs[i].getPeg());
				newSolutions.push_back(newPegs[j].getPeg());
				newSolutions.push_back(newPegs[i].getPeg());
				newPegs = newBoard.remainingPegs();

				if (newBoard.checkWin())
				{
          finalSolution = newSolutions;
          return true;
				}
				else
				{
					if (autoSolver(newBoard, newPegs, newSolutions))
          {
            solutionList = finalSolution;
            return true;
          }
				}
			}
		}
	}

	return false;
}
