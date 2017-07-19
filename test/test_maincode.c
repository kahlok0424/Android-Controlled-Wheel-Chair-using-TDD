#include "unity.h"
#include "maincode.h"
#include <stdio.h>
#include <stdlib.h>


void setUp(void)
{
}

void tearDown(void)
{
}

void test_maincode_calculation(void)
{
  MotorInfo leftMotorInfo = {
    MOTOR_LEFT_STEP_PIN,
    0 ,
    MOTOR_LEFT_DIR_PIN,
    MOTOR_LEFT_FOWARD,
    0,
    0,
    0,
  };

  MotorInfo rightMotorInfo = {
    MOTOR_RIGHT_STEP_PIN,
    0 ,
     MOTOR_RIGHT_DIR_PIN,
    MOTOR_RIGHT_FOWARD,
    0,
    0,
    0,
  };

    AngleSpeed Maininfo = {
      10,
      300,
      5,
      0,
    };

    printf("Speed = %d \n",Maininfo.Speed);
    printf("Angle = %d \n",Maininfo.Angle);
    Calculation(&Maininfo,&leftMotorInfo,&rightMotorInfo);
    printf("Delay_left = %d \n",leftMotorInfo.delay);
    printf("Delay_right = %d \n",rightMotorInfo.delay);
    TEST_ASSERT_EQUAL(500, rightMotorInfo.delay);
    TEST_ASSERT_EQUAL(100, leftMotorInfo.delay);
}

void test_maincode_old_calculation(void)
{
  MotorInfo leftMotorInfo = {
    MOTOR_LEFT_STEP_PIN,
    0 ,
    MOTOR_LEFT_DIR_PIN,
    MOTOR_LEFT_FOWARD,
    0,
    0,
    0,
  };

  MotorInfo rightMotorInfo = {
    MOTOR_RIGHT_STEP_PIN,
    0 ,
     MOTOR_RIGHT_DIR_PIN,
    MOTOR_RIGHT_FOWARD,
    0,
    0,
    0,
  };

    AngleSpeed Maininfo = {
      10,
      120,
      5,
      180,
    };

    printf("oldSpeed = %d \n",Maininfo.Speed);
    printf("oldAngle = %d \n",Maininfo.Angle);
    oldCalculation(&Maininfo,&leftMotorInfo,&rightMotorInfo);
    printf("old_Delay_left = %d \n",leftMotorInfo.delay);
    printf("old_Delay_right = %d \n",rightMotorInfo.delay);
    TEST_ASSERT_EQUAL(200, rightMotorInfo.delay);
    TEST_ASSERT_EQUAL(200, leftMotorInfo.delay);
}
