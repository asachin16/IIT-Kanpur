//version 1.0 17th march,2012
//Made by Varun Bhatt

void forward(int m)    //forward motion of bot
{
  forward_motor(1);
  backward_motor(3);
  stop_motor(2);
  stop_motor(4);
  pwm(1,m);
  pwm(3,m);
}

void backward(int m)     //leftward motion of bot
{
  forward_motor(3);
  backward_motor(1);
  stop_motor(2);
  stop_motor(4);
  pwm(1,m);
  pwm(3,m);
}

void right(int m)        //rightward motion of bot
{
  forward_motor(2);
  backward_motor(4);
  stop_motor(1);
  stop_motor(3);
  pwm(2,m);
  pwm(4,m);
}


void left(int m)            //leftward motion of bot
{
  forward_motor(4);
  backward_motor(2);
  stop_motor(1);
  stop_motor(3);
  pwm(2,m);
  pwm(4,m);
}


void rotate_clockwise(int m)        //rotate_clockwise motion of bot
{
  forward_motor(1);
  forward_motor(2);
  forward_motor(3);
  forward_motor(4);
  pwm(1,m);
  pwm(2,m);
  pwm(3,m);
  pwm(4,m); 
}


void rotate_anticlockwise(int m)      //rotate_anticlockwise motion of bot
{
  backward_motor(1);
  backward_motor(2);
  backward_motor(3);
  backward_motor(4);
  pwm(1,m);
  pwm(2,m);
  pwm(3,m);
  pwm(4,m); 
}

void stop_bot()             //stop motion of bot
{
 stop_motor(1);
 stop_motor(2);
 stop_motor(3);
 stop_motor(4);
} 

