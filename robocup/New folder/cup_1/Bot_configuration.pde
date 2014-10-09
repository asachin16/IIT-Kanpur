//version 1.0 17th march,2012
//Made by Varun Bhatt
//making of the most basic functions of each motor
//Here pins of a motor is associated with ascending order from upper terminal of motor to the lower on  
      
#define MOTOR1_U 2          //U defines upper terminal of motor
#define MOTOR1_L 4          // l defines lower terminal of motor
#define MOTOR1_PWM 3        //pwm pin
#define MOTOR2_U A0
#define MOTOR2_L A1
#define MOTOR2_PWM 5
#define MOTOR3_U A2
#define MOTOR3_L A3
#define MOTOR3_PWM 6
#define MOTOR4_U A4
#define MOTOR4_L A5
#define MOTOR4_PWM 9

void forward_motor(int i)
{
  if(i==1) //motor1
  {
    digitalWrite(MOTOR1_U, HIGH);
    digitalWrite(MOTOR1_L, LOW);
  }
  else if(i==2)
  {
    digitalWrite(MOTOR2_U, HIGH);
    digitalWrite(MOTOR2_L, LOW);
  }
  else if(i==3)
  {
    digitalWrite(MOTOR3_U, HIGH);
    digitalWrite(MOTOR3_L, LOW);
  }
  else if(i==4)
  {
    digitalWrite(MOTOR4_U, HIGH);
    digitalWrite(MOTOR4_L, LOW);
  }
}


  
void backward_motor(int i)
{
  if(i==1) //motor1
  {
    digitalWrite(MOTOR1_L, HIGH);
    digitalWrite(MOTOR1_U, LOW);
  }
  else if(i==2)
  {
    digitalWrite(MOTOR2_L, HIGH);
    digitalWrite(MOTOR2_U, LOW);
  }
  else if(i==3)
  {
    digitalWrite(MOTOR3_L, HIGH);
    digitalWrite(MOTOR3_U, LOW);
  }
  else if(i==4)
  {
    digitalWrite(MOTOR4_L, HIGH);
    digitalWrite(MOTOR4_U, LOW);
  }
}



void stop_motor(int i)
{
  if(i==1) //motor1
  {
    digitalWrite(MOTOR1_L, HIGH);
    digitalWrite(MOTOR1_U, HIGH);
  }
  else if(i==2)
  {
    digitalWrite(MOTOR2_L, HIGH);
    digitalWrite(MOTOR2_U, HIGH);
  }
  else if(i==3)
  {
    digitalWrite(MOTOR3_L, HIGH);
    digitalWrite(MOTOR3_U, HIGH);
  }
  else if(i==4)
  {
    digitalWrite(MOTOR4_L, HIGH);
    digitalWrite(MOTOR4_U, HIGH);
  }
}




  
void pwm(int i,int pwm)
{
  if(i==1)
  {
    analogWrite(MOTOR1_PWM,pwm);
  }
  else if(i==2)
  {
    analogWrite(MOTOR2_PWM,pwm);
  }
  else if(i==3)
  {
    analogWrite(MOTOR3_PWM,pwm);
  }
  else if(i==4)
  {
    analogWrite(MOTOR4_PWM,pwm);
  }
}
  
    
  
