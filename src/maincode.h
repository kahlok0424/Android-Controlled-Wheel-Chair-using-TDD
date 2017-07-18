#ifndef _MAINCODE_H
#define _MAINCODE_H

#define MOTOR_LEFT_STEP_PIN   4
#define MOTOR_LEFT_DIR_PIN    5
#define MOTOR_RIGHT_STEP_PIN  0
#define MOTOR_RIGHT_DIR_PIN   2
#define MOTOR_LEFT_FOWARD     1
#define MOTOR_LEFT_BACKWARD   0
#define MOTOR_RIGHT_FOWARD    0
#define MOTOR_RIGHT_BACKWARD  1

typedef struct AngleSpeed AngleSpeed;
struct  AngleSpeed {
  int Speed;
  int Angle;
  int previousAngle;
  int previousSpeed;
};

typedef struct MotorInfo MotorInfo;
struct  MotorInfo {
  int motorControlPin;
  int pinState;
  int dirPin;
  int dir;
  int steps;
  unsigned long prevTime;
  unsigned long delay;
};


void Calculation(AngleSpeed *MainInfo , MotorInfo *leftMotor , MotorInfo *rightMotor);
void oldCalculation(AngleSpeed *MainInfo , MotorInfo *leftMotor , MotorInfo *rightMotor);

#endif // _MAINCODE_H
