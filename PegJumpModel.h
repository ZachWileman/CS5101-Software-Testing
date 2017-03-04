//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#ifndef PegJumpModel_h
#define PegJumpModel_h

#include "Board.h"

class PegJumpModel
{
public:
  PegJumpModel() {}
  bool autoSolver(Board tempBoard, vector<Peg> remainingPegs, vector<char> solutionList);

};

#endif
