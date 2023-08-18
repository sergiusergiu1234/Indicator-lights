//switch variables
int  counter=0;
int holdCounter=0;
//left switch
int SW1_pin=2;   
int SW1=0;    //switch value
int SW1state; 
int lastSW1state=0;

//right switch
int SW2_pin=3;   
int SW2=0;    //switch value
int SW2state; 
int lastSW2state=0;

//hazard switch
int SW3_pin=4;   
int SW3=0;    //switch value
int SW3state; 
int lastSW3state=0;

//led variables
int ledCounter=0;
int requiredBlinks=0;
int blinksCounter=0;

//left led
int LED1_pin=8;
int led1State=0;
int lastLed1State=0;

//right led
int LED2_pin=9;
int led2State=0;
int lastLed2State=0;

int potPin=A0; //potentiometer pin
int volum=0;//potentiometer value
int times=0;
int mediu=0;
void setup() {
  pinMode(SW1_pin,INPUT);
  pinMode(SW2_pin,INPUT);
  pinMode(LED1_pin,OUTPUT);
  pinMode(LED2_pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(10);
SM_s1();
SM_led();

if(SW1state==2){led1State=2;}
  
    if((lastSW1state != SW1state) | (lastLed1State != led1State) | (lastSW2state != SW2state) | (lastLed2State != led2State)) {
      Serial.print("Left Switch  State: "); Serial.print(SW1state);
      Serial.print(" | Right Switch State: "); Serial.print(SW2state);
      Serial.print(" | Left led State: "); Serial.print(led1State);
      Serial.print(" | Right led State: "); Serial.print(led2State);
}
}


void SM_s1(){
  SW1= digitalRead(SW1_pin);
  lastSW1state = SW1state;
  
  switch (SW1state){
    case 0: //reset
      counter=0;
      SW1state=1;
    break;
    
    case 1 ://press
       if(SW1==HIGH){SW1state=2;}
    break;

    case 2 : //hold
            counter++;
            holdCounter++;
         if(SW1==LOW){SW1state=3;}
         if(holdCounter>50){SW1state=4;requiredBlinks=1000;

           }    //start normal
    break;

    case 3: //released
         if(counter<50 && counter != 0){requiredBlinks=3;}   //start lane switch left 
         SW1state=0;
    break;

    case 4: //still holding
        if(SW1==LOW){SW1state=5;holdCounter=0;}
         volum=analogRead(potPin);
         times=map(volum,0,1023,10,100);
    break;

    case 5: //long pressed  
        holdCounter++;
        if(holdCounter>=10){SW1state=0;requiredBlinks=0;}  //stop normal mode
        if(SW1==HIGH){SW1state=4;}
    break;
    }
  }

  void SM_s2(){
  SW2= digitalRead(SW2_pin);
  lastSW2state = SW2state;
  
  switch (SW2state){
    case 0: //reset
      counter=0;
      SW2state=1;
    break;
    
    case 1 ://pressed
       
    break;

    case 2 : //release
           
    break;

    case 3: //LONG PRESSED
    break;

    case 4: //medium presed
      
    break;
    }
  }

  void SM_led(){
    lastLed1State= led1State;

    switch(led1State){
      
      case 0 : //reset
         ledCounter=0;
         blinksCounter=0;
         led1State=1;
         mediu=0;
      break;
      
      case 1 : //  wait
      break;
      
      case 2 : //turn on
        digitalWrite(LED1_pin,HIGH);
        led1State=3;
      break;
            
      case 3: //on
        ledCounter++;
      if(ledCounter >= 30){led1State=4;ledCounter=0;}
      //    if(ledCounter >= times/2){led1State=4;ledCounter=0;}

      break;


      case 4: //turn off
        digitalWrite(LED1_pin,LOW);
                blinksCounter++;
        led1State=5;
      break;

      
      case 5 :   //off
        ledCounter++;
        if(ledCounter >= 70){led1State=2;ledCounter=0;}
      //  if(ledCounter >= times/2){led1State=2;ledCounter=0;}

        if(blinksCounter >= requiredBlinks){led1State=0;}
      break;
      }
}
