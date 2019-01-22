#pragma once
#include "skills.h"

namespace MyStrategy
{
  // Naive example for attacker


/*void  attacker1(BeliefState * state,int botID){
	
int   vr = 0;
int   vl = 0;
float  tR= state->homeAngle[botID];
float c;
float angle;
Point2D<int> T = state->ballPos;
Point2D<int> A =state->homePos[botID];


  //T = member(1).model("Ball").transform.position
 // T.x = gRight - T.x
  //T.y = ftop - T.y
  //A = whichBot.pos
  //A.x = gRight - A.x
  //A.y = ftop - A.y
  //tR = whichBot.rot.z -180
  if  (tR < .001)  tR = tR + 360;
  if (tR >360.001) tR = tR - 360;
  
  vr = 50;
  vl = 50;
  if (A.x <(T.x -10)  && tR >340 && tR < 20){ 
    vr = 50;
    vl = 50;
  }
  else if (A.x <(T.x -10) && tR <340 || tR > 20){ 
    vr = 20;
    vl = 20;
  }
  if(  A.x >(T.x -20) )    {
    vr = 50;
	vl = 50;}
  else if (A.x >(T.x -20))    
   { vr = 20;
  vl = 20;}
  
  if( A.x <(T.x -15)){
    if (tR < 340 && tR  > 180) {
      vr = vr+55;
      vl =  vl - 30;
	}
  }
    if (tR > 20 && tR < 180) 
     {
		vr = vr -30;
		vl = vl +55;
	}
    end if 
  end if 
  -----------
  if (A.y <5 )
    vr = -100;
    vl = -120;
  end if 
  if A.y > ftop - fbot  - 5 then
    vr =  -120
    vl = -110
  end if 
  if A.x <5 then
    vr = -110
    vl = -120
  end if 
  if A.y > 56 then
    vr =  -120
    vl = -100
  end if 
  --------
  if A.x >(T.x -15) and tR <355 and tR > 180 and abs(A.y - T.y) < 1 then
    vr = vr+55
    vl =  vl 
  end if 
  if A.x >(T.x -15) and tR > 5 and tR < 180 and abs(A.y - T.y) < 1 then
    vr = vr 
    vl = vl +55
  end if 
  if A.x >(T.x -20) and A.y = (T.y ) and tR > 179 and  tR < 181 then
    vr = vr 
    vl =vl 
  else if A.x >(T.x -20) and A.x <(T.x -8) and A.y >(T.y) then
    vr = vr 
    vl =vl + 3
  else if  A.x >(T.x -20) and A.x <(T.x -8) and A.y <(T.y  )  then
    vr = vr +3
    vl =vl 
  end if 
  if  A.x >(T.x +1) then
    vr = 60
    vl = 40
    --else if  A.x>T.x - 1  then
    --vr = 50
    --vl =50
  end if 
  
  velocity(whichBot , vl, vr)
  
  }
	
	
	
	
	}
	*/
  void attacker(BeliefState *state,int botID)
  {
    print("Attacker\n");
	Vec2D fpoint(HALF_FIELD_MAXX,0);
	Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
	// Go to ball if ball is far
	// Take ball to the goal
	if( Vec2D::distSq(state->homePos[botID],state->ballPos) < 2*BOT_BALL_THRESH)
		GoToPoint(botID,state,fpoint,PI/2,true,false);
	else 
		GoToPoint(botID,state,ballPoint,0,false, true);
  }
  

  void attacker1(BeliefState *state,int botID){
  
	  float  r= state->homeAngle[botID];
	  float c;
	  if(r<0) r= r+360;
	  if(r > 360 ) r = r- 360;
	  int vr=0;
	  int vl = 20 ;
	  float angle;
	  Point2D<int> t = state->ballPos;
	  Point2D<int> a =state->homePos[botID];
	  //state->ball
	  int dx,dy;
	  if(abs(a.y-t.y)>7 || t.x > a.x){
		dx=a.x-t.x;
		dy=a.y-t.y;
		if(dx-5 == 0){
	  
				if(dy > 0 )
					
				 TurnToAngle(botID,state,angle=270);
			
				else TurnToAngle(botID,state,angle=90.0);
		}
		
		else if(dy = 0 ){
		  if(dx-5>0)
		    TurnToAngle(botID,state,angle=360);
			
		  else  TurnToAngle(botID,state,angle=180);
			}
		else {
	    TurnToAngle(botID,state,angle=atan(abs(dy/dx))*180/3.14);
		}
		if(dx - 5 > 0){
		
			if(dy > 0 )
			   TurnToAngle(botID,state,angle=angle- 180);
			else if(dy < 0 )
				TurnToAngle(botID,state,angle= 180 - angle );
		
		}
		if(dx - 5 < 0 ){
			if(dy > 0)
				TurnToAngle(botID,state,angle=-angle);
			else 
				TurnToAngle(botID,state,angle = 90-angle );
		}
	  
		if(atan(abs(dy/dx))*180/3.14  < 0) TurnToAngle(botID,state,angle=angle + 360 );
		if(atan(abs(dy/dx))*180/3.14  > 360) TurnToAngle(botID,state,angle=angle - 360 );
		if(atan(abs(dy/dx))*180/3.14   > 360 ) TurnToAngle(botID,state,angle = angle - 360 );
		
	  
	  
   c= r;
   if(abs(c-angle)<40 ){
   vr=100;
   vl=100;
   if(c>angle)
		vr=vr-10;
   else if(c < angle )
	   vl=vl-10;
   }
   else{
   if(r > angle)
	   vl= vl+abs(r-angle);
   else 
	   vr=vr+abs(r-angle);
  
   }

    Velocity(botID,vl,vr);



  }
	  else {
	  
			dx  = a.x - t.x ;
			dy = a.y - t.y;
			if(dx== 0){
			  if(dy > 0)
				  angle=270;
			  else angle=90;
			
			}
			else if(dy ==0){
				if(dx > 0)
				angle=360;
				else angle=180;
				}
			else angle=atan(abs(dy/dx)*180/3.14);
			if(dx>0){
				if(dy>0)
				angle=angle-180;
				else angle  = 180 - angle;
			}
			if(dx<0){
				if(dy > 0) angle =180- angle -180;
				else angle=270-angle-180;
			}
			if(angle < 0)  angle= angle +360;
			if(angle > 360 ) angle = angle -360;
			
		c= r;
		if(abs(c-angle)<40){
		vr= 100;
		vl=100;
		if(c>angle) vr = vr - 10;
		if(c < angle) vl = vl -10 ;
		}
		else {
		
			if(r>angle) vl= vl+abs(r-angle);
			else vr  = vr + abs(r- angle);
		}
	  
		TurnToAngle(botID,state,angle);
		Velocity(botID,vl,vr);
	  
	  
	  }
				
			
			
			}

		

	  
  
  }



