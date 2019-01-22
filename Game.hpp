// For adding header files define your includes here and add the headers in Game folder.
// For example, You may see these files - Attacker.hpp,Defender.hpp and Goalkeeper.hpp
// For checking out the skills you may see skills.h placed in Skills folder.
#pragma once
#include "skills.h"
#include "Attacker.hpp"
#include "Defender.hpp"
#include "GoalKeeper.hpp"

// Change your team color here (BLUE_TEAM/YELLOW_TEAM)face

Simulator::TeamColor teamColor = Simulator::BLUE_TEAM;

// Make usingDebugger is false when playing against an opponent
bool usingDebugger = true;

namespace MyStrategy
{
  // Write your strategy here in game function.
  // You can also make new functions and call them from game function.
  void game(BeliefState *state)
  {
	  if(state->ballPos.x > 0 ){
		  attacker1(state,2);
		  defender1(state,1);
		  goalkeeper(state,0);
	  }
	  if(state->ballPos.x < 0){
	  //attacker_to_defender(state,2);
		attacker1(state,2);
		defender1(state,1);
		goalkeeper(state,0);
	  }
  }
}