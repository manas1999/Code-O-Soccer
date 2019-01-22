#pragma once
#include "skills.h"

/*
	Vec2D can be used to make variables that can store points as (x,y) and provide utility functions.
	Vec2D point1;
	Vec2D point2;
	point1.x = HALF_FIELD_MAXX;
	point1.y = 0;
	similarly for point2 can be specified
	Some utility functions:
	These will appear automatically as you type Vec2D::
	float angle = Vec2D::angle(point1,point2);   
	int distance = Vec2D::distSq(point1,point2);
*/

namespace MyStrategy
{
  // Naive Example for GoalKeeper
   void goalkeeper(BeliefState *state,int botID)
	  
  {

	  float angle1=state->homeAngle[botID];
	  float angle2;
    //print("GoalKeeper\n");
	int angularSpeed=15;
	Vec2D dpoint(OUR_GOAL_X+DBOX_HEIGHT,state->ballPos.y);
	if(state->ballPos.x > HALF_FIELD_MAXX) vibrate(state,botID,OUR_GOAL_MAXY/2);	
    if(dpoint.y > OUR_GOAL_MAXY)
	{
      dpoint.y = OUR_GOAL_MAXY-10;
	  vibrate(state,botID,10);
	}
	if(dpoint.y < OUR_GOAL_MINY)
    {
      dpoint.y = OUR_GOAL_MINY+10;
	  vibrate(state,botID,10);
	}
	  if(dpoint.x <= state->ballPos.x+15 &&  dpoint.x >= state->ballPos.x+10){
	    Spin(botID,angularSpeed);
		angle2=state->homeAngle[botID];
		//i// spped in radians
	}
    GoToPoint(botID,state,dpoint,PI/2,false,false);
	if(angle2!=angle1){
	    TurnToAngle(botID,state,angle1);

	
	
	}
  }
}