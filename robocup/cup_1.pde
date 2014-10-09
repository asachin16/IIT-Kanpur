//version 1.0 23rd march,2012
//atmega328P
//Made by Varun Bhatt
//To make it run
//W to move forward and then pwm between 0 to 255
//S to move backward
//A to move left
//D to move right
//R to rotate Clockwise
//A to rotte anticlockwise
//Q to stopp
//Eg first of all to move the bot forward press'W' then one by one send 1,4,5,(put the pwm)....to make it run for 145 pwm ......
//eg2. press D,2,3,0 one by one for right ward motion of the bot at speed 230 pwm
//for ease of serial communication use "putty" software easily available on net 
char data,data1,data2,data3;
int i,j,k,t;
void setup()
{
  pinMode(3,OUTPUT);   //motor 1 pwm
  pinMode(2,OUTPUT);   //+ve motor it should be high
  pinMode(4,OUTPUT);
  
  pinMode(5,OUTPUT); 
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  
  pinMode(6,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  
  pinMode(9,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(A4,OUTPUT);
  
  
  Serial.begin(9600);
}



void loop()
{
  data=0;
  data1=0;
  data2=0;
  data3=0;
//  Serial.flush();
  if (Serial.available()>0)
  {
     data=Serial.read();
     Serial.print(data);
     if (data=='W')
     {
       while(!Serial.available()); //wait for keypress
       
       data1=Serial.read();
       i= (data1-48);
       while(!Serial.available()); //wait for keypress
       
       data2=Serial.read();
       j= (data2-48);
       while(!Serial.available()); //wait for keypress
       
       data3=Serial.read();
       k= (data3-48);
       t=(i*100+j*10+k);
       if (t<256)
       {
         forward(t);
       }
       else
         stop_bot();
       
     }
  

//     else if (data=='w')
//     {
//       forward(128);
//     }
     
     else if (data=='S')
     {
       while(!Serial.available()); //wait for keypress
       
       data1=Serial.read();
       i= (data1-48);
       while(!Serial.available()); //wait for keypress
       
       data2=Serial.read();
       j= (data2-48);
       while(!Serial.available()); //wait for keypress
       
       data3=Serial.read();
       k= (data3-48);
       t=(i*100+j*10+k);
       if (t<256)
       {
         backward(t);
       }
       else
         stop_bot();
     }
////     else if (data=='s')
////     {
////       backward(128);
////     }
//     
     else if (data=='A')
     {
       while(!Serial.available()); //wait for keypress
       
       data1=Serial.read();
       i= (data1-48);
       while(!Serial.available()); //wait for keypress
       
       data2=Serial.read();
       j= (data2-48);
       while(!Serial.available()); //wait for keypress
       
       data3=Serial.read();
       k= (data3-48);
       t=(i*100+j*10+k);
       if (t<256)
       {
         left(t);
       }  
         else
         stop_bot();    
     }
////     else if (data=='a')
////     {
////       left(128);
////     }
//     
     else if (data=='D')
     {
       while(!Serial.available()); //wait for keypress
       
       data1=Serial.read();
       i= (data1-48);
       while(!Serial.available()); //wait for keypress
       
       data2=Serial.read();
       j= (data2-48);
       while(!Serial.available()); //wait for keypress
       
       data3=Serial.read();
       k= (data3-48);
       t=(i*100+j*10+k);
       if (t<256)
       {
         right(t);
       }
       else
         stop_bot();
     }
//     else if (data=='d')
//     {
//       right(128);
//     }
     
     else if (data=='R')
     {
       while(!Serial.available()); //wait for keypress
       
       data1=Serial.read();
       i= (data1-48);
       while(!Serial.available()); //wait for keypress
       
       data2=Serial.read();
       j= (data2-48);
       while(!Serial.available()); //wait for keypress
       
       data3=Serial.read();
       k= (data3-48);
       t=(i*100+j*10+k);
       if (t<256)
       {
         rotate_clockwise(t);
       }
       else
         stop_bot(); 
     }
//     else if (data=='r')
//     {
//       rotate_clockwise(128);
//     }
     
     else if (data=='T')
     {
       while(!Serial.available()); //wait for keypress
       
       data1=Serial.read();
       i= (data1-48);
       while(!Serial.available()); //wait for keypress
       
       data2=Serial.read();
       j= (data2-48);
       while(!Serial.available()); //wait for keypress
       
       data3=Serial.read();
       k= (data3-48);
       t=(i*100+j*10+k);
       if (t<256)
       {
         rotate_anticlockwise(t);
       }
       else
         stop_bot();
     }
//     else if (data=='t')
//     {
//       rotate_anticlockwise(128);
//     }
     else if (data=='Q')
     {
       stop_bot();
     }
     
     
     
     
       
  }
}

