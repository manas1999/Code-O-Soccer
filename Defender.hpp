#pragma once
#include "skills.h"

namespace MyStrategy
{
  // Naive example for defender
 


  void defender(BeliefState *state,int botID)
  {
    //print("Defender\n");
	//It follows the ball
	Vec2D dpoint;
	dpoint.x = -HALF_FIELD_MAXX/2;
	dpoint.y = state->ballPos.y;
    GoToPoint(botID,state,dpoint,PI/2,false,false);
  }
  void defender1(BeliefState *state,int botID ){
	  Vec2D dpoint;
	  if(dpoint.x > state->ballPos.x && state->ballPos.x >= -HALF_FIELD_MAXX/2)
	  {
	  dpoint.x = -HALF_FIELD_MAXX/2;
	  dpoint.y=state->ballPos.y- 30;
	  GoToPoint(botID,state,dpoint,PI/2,false,false);

	  }
	  else if(dpoint.x > state->ballPos.x && state->ballPos.x <= -HALF_FIELD_MAXX/2)
	  {
	   dpoint.y=state->ballPos.y;
	   GoToPoint(botID,state,dpoint,PI/2,false,false);
	  }
	  else if(dpoint.x < state->ballPos.x && ( state->ballPos.y > OUR_GOAL_MAXY  ||  state->ballPos.y < OUR_GOAL_MINY ) ) {
	  dpoint.x = state->ballPos.x;
	  dpoint.y=state->ballPos.y;
	  GoToPoint(botID,state,dpoint,PI/2,false,false);

	  
	  }
	
  
  
  
  
  }
}