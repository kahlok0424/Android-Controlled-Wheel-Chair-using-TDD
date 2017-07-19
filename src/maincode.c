#include "maincode.h"
#include <stdio.h>
#include <stdlib.h>

// define pin

/*int TimerExpired(unsigned long duration ,unsigned long previous )
{
   unsigned long current = micros();
  if(duration != -1 && (current - previous >= duration))
  {
   return 1;
  }
  return 0;
}

void motorStep(MotorInfo *motorInfo)
{
  digitalWrite(motorInfo->dirPin , motorInfo->dir);
  if(TimerExpired(motorInfo->delay, motorInfo->prevTime))
  {
    digitalWrite(motorInfo->motorControlPin,1);
    digitalWrite(motorInfo->motorControlPin ,0);
    motorInfo->prevTime = micros();
    motorInfo-> steps ++ ;
  }
}

void Uturn(MotorInfo *leftInfo , MotorInfo *rightInfo)
{
  leftInfo->dir = MOTOR_LEFT_FOWARD;
  leftInfo->delay = 400;
  rightInfo->dir = MOTOR_RIGHT_BACKWARD;
  rightInfo  ->delay = 400;
  while( (leftInfo->steps < 4000) && (rightInfo-> steps <4000) )
  {
      motorStep(leftInfo);
      motorStep(rightInfo);
  }
}

void ForceStop(MotorInfo *leftInfo , MotorInfo *rightInfo)
{
  leftInfo-> delay = -1;
  rightInfo -> delay = -1;
}*/

void Calculation(AngleSpeed *MainInfo , MotorInfo *leftMotor , MotorInfo *rightMotor)
{
    float x =0.0;
    float y =0.0;

      if( MainInfo->Speed == 0 )
     {
      // ForceStop(leftMotor ,rightMotor);
      }

   if(MainInfo->previousSpeed != MainInfo->Speed){
    MainInfo->previousSpeed = MainInfo->Speed;
    leftMotor->delay = 6000 / MainInfo->Speed;
    rightMotor->delay = 6000 / MainInfo->Speed;
   }

   if(MainInfo->previousAngle != MainInfo->Angle)
   {
      MainInfo->previousAngle = MainInfo->Angle;
    if( 0 <= MainInfo->Angle && MainInfo->Angle <= 180)
      {
      leftMotor -> dir = MOTOR_LEFT_FOWARD ;
      rightMotor -> dir = MOTOR_RIGHT_FOWARD;
      x = (float) (MainInfo->Angle /180.0);
      y = (float) (1 - (MainInfo->Angle/180.0));
      printf("x = %f \n",x);
      printf("y = %f \n",y);
      leftMotor -> delay = (unsigned long)(leftMotor->delay * x);
      rightMotor -> delay = (unsigned long)( rightMotor->delay * y);
      }
    else if( 180 < MainInfo->Angle && MainInfo->Angle <= 360)
      {
      leftMotor -> dir = MOTOR_LEFT_BACKWARD;
      rightMotor -> dir = MOTOR_RIGHT_BACKWARD;
      x = (float)(MainInfo->Angle /360.0);
      y = (float)(1 - (MainInfo->Angle/360.0));
      leftMotor -> delay = (unsigned long)(y * leftMotor->delay);
      rightMotor -> delay = (unsigned long)(x * rightMotor->delay);
      }
    }
  }

void oldCalculation(AngleSpeed *MainInfo , MotorInfo *leftMotor , MotorInfo *rightMotor){
  int x = 4;   //calculated value based on the revolution
  int y = 2;    //calculated value negative angle

  if(MainInfo->previousAngle != MainInfo->Angle){
    MainInfo->previousAngle = MainInfo->Angle;
  if( 180 <= (MainInfo->Angle) && (MainInfo->Angle) < 360 )
  {
    leftMotor -> dir = MOTOR_LEFT_FOWARD ;
    rightMotor -> dir = MOTOR_RIGHT_FOWARD;
     if( 180 < (MainInfo->Angle) && ( MainInfo->Angle) < 270 )
     {
        leftMotor -> delay = (unsigned long ) ( ( 360 - MainInfo->Angle) * x );
       rightMotor -> delay = (unsigned long) ( ( MainInfo->Angle - 90 ) * y ) ;
     }
     else // if ( 270 <= (MainInfo-> floatAngle) && ( MainInfo-> floatAngle) < 360)
     {
      leftMotor -> delay = (unsigned long) ( (450 - MainInfo->Angle ) * y ) ;
      rightMotor -> delay = (unsigned long) ( ( MainInfo->Angle - 180 ) * x );
      }
    }
   else if ( 0 <= (MainInfo->Angle ) && ( MainInfo->Angle) < 180 )
      {
        leftMotor -> dir = MOTOR_LEFT_BACKWARD ;
        rightMotor -> dir = MOTOR_RIGHT_BACKWARD;
          if( 0 <= (MainInfo->Angle) && ( MainInfo->Angle) <90)
          {
             leftMotor -> delay = (unsigned long ) ( (MainInfo->Angle + 90) * y );
             rightMotor -> delay = (unsigned long) ( ( MainInfo->Angle + 90 ) * x ) ;
            }
            else //if ( 90 <= (MainInfo -> floatAngle) <180)
            {
              leftMotor -> delay = (unsigned long) ( ( MainInfo->Angle) * x );
              rightMotor -> delay = (unsigned long) ( ( 270 - MainInfo->Angle ) * y );
              }
        }
  }
        if(MainInfo->previousSpeed != MainInfo->Speed){
          MainInfo->previousSpeed = MainInfo->Speed;
        int cSpeed = ( (MainInfo->Speed ) * 2.00 );

        if( 1.00 <= ( cSpeed) && (cSpeed) <= 2.00 )
        {
          leftMotor -> delay = (unsigned long) ( (leftMotor ->delay) / cSpeed ) ;
          rightMotor -> delay = (unsigned long) ( (rightMotor -> delay) / cSpeed) ;
        }
          else if( cSpeed == 0 )
          {
          //  ForceStop(leftMotor ,rightMotor);
            }
          else if ( 0.00 < ( cSpeed) && (cSpeed) < 1.00 )
          {
             leftMotor -> delay = (unsigned long)  ( ( ( 1 - (cSpeed) )+ 1 )* leftMotor -> delay ) ;
             rightMotor -> delay = (unsigned long) ( ( ( 1 - ( cSpeed) )+ 1 )* rightMotor -> delay ) ;
            }
        }
}

// the loop function runs over and over again forever
/*void loop() {

    motorStep(&leftMotorInfo);
    motorStep(&rightMotorInfo);

    Calculation(&instruction , &leftMotorInfo ,&rightMotorInfo);

}*/
