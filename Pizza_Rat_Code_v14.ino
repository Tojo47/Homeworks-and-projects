#include <LiquidCrystal.h>

LiquidCrystal lcd(24, 22, 10, 11, 12, 13);

char array1[]=" T.K. presents               ";  //the string to print on the LCD
char array2[]=" PIZZA    RAT!             ";  //the string to print on the LCD
int tim = 250;                               //the value of delay time

const int ButtonGreen = 28; //button 28 is right 
const int ButtonBlack = 26; // button 26 is left

int StateButtonGreen = 0;
int StateButtonBlack = 0;

int STATE = 0;

boolean PressingButtonGreen = false;
boolean PressingButtonBlack = false;

boolean greenReady = false;
boolean blackReady = false;
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(ButtonGreen, INPUT);
  pinMode(ButtonBlack, INPUT);

  STATE = 0;
}

void loop()
{
  StateButtonGreen = digitalRead(ButtonGreen);
  StateButtonBlack = digitalRead(ButtonBlack);



  if (StateButtonGreen == HIGH) 
  {
    PressingButtonGreen = true;
  }

  if (StateButtonGreen == LOW && PressingButtonGreen == true) 
  {
    PressingButtonGreen = false;
    greenReady = true;
    Serial.println("greeb button ready");
    
  }

  if (StateButtonBlack == HIGH) 
  {
    PressingButtonBlack = true;
  }

  if (StateButtonBlack == LOW && PressingButtonBlack == true)
  {
    PressingButtonBlack = false;
    blackReady = true;
    Serial.println("black button ready");
  }

  


  if (STATE == 0)
  { 
   

    lcd.setCursor(15,0);  // set the cursor to column 15, line 0
    for (int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++)
    {
      lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
      lcd.print(array1[positionCounter1]);  // Print a message to the LCD.
      delay(tim);  //wait for 250 microseconds
    }
    lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.

    
     lcd.setCursor(15,1);  // set the cursor to column 15, line 1
    for (int positionCounter2 = 0; positionCounter2 < 26; positionCounter2++)
    {
      lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
      lcd.print(array2[positionCounter2]);  // Print a message to the LCD.
      delay(tim);  //wait for 250 microseconds
    }
    lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.


    Instruction0();

    
    
  }


if (STATE == 7)
{
  if (greenReady == true)
  {
  Story();
  
  greenReady = false;
  }
  else if (blackReady == true)
  {
    lcd.setCursor(0,0);
    lcd.print("Press the green");
    lcd.setCursor(0,1);
    lcd.print("Button");
    delay(2000);
    lcd.clear();
    blackReady = false;

  }
}


 if (STATE == 6) 
 {
   Instruction1();
    
 }


 if (STATE == 1)  // Do you find pizza?
 {

    if (greenReady == true) 
    {
      //Serial.print("BG.= Boutton Green has been pressed");
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("I Found Pizza!");
      delay(1750);
      lcd.clear();
      StateButtonGreen = 0;
      StateButtonGreen = LOW;
      StateButtonBlack = LOW;
      
      greenReady = false;
      
      Instruction2();
     
    }

    else if (blackReady == true)
    {
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("Didn't Find!");
      delay(1750);
      lcd.clear();

      lcd.setCursor (0, 0);
      lcd.print ("   Try again  ");
      delay(1500);
      lcd.clear();
      StateButtonBlack = 0;
      STATE = 0;
      StateButtonGreen = LOW;
      StateButtonBlack = LOW;
      
      blackReady = false;

      Instruction1();
      blackReady = false;
    }

    
 }

 if (STATE == 2)   // Do you eat Pizza?
 {
    if (greenReady == true) 
    {
      //Serial.print("BG.= Boutton Green has been pressed");
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("Killed by pigeon");
      delay(1750);
      lcd.clear();

      lcd.setCursor (0, 1);
      lcd.print ("   Try Again   ");
      delay(1500);
      lcd.clear();      
      StateButtonGreen = 0;
      StateButtonGreen = LOW;
      StateButtonBlack = LOW;
      Instruction2();
      
      greenReady = false;
    }

    else if (blackReady == true)
    {
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("Take it Home");
      delay(1750);
      lcd.clear();
      StateButtonBlack = 0;
      Instruction3();
      
      blackReady = false;
    }

    
  
 }

 if (STATE == 3)   // Encountering stairs
  {
    if (greenReady == true) 
    {
      //Serial.print("BG.= Boutton Green has been pressed");
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("Stepped by humans");
      delay(1750);
      lcd.clear();

      lcd.setCursor (0, 1);
      lcd.print ("   Try Again  ");
      delay(1500);
      lcd.clear();
      StateButtonGreen = 0;
      StateButtonGreen = LOW;
      StateButtonBlack = LOW;
      Instruction3();
      greenReady = false;
    }

    else if (blackReady == true)
    {
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("Throw downstairs");
      delay(1750);
      lcd.clear();
      StateButtonBlack = 0;
      Instruction4();
      
      blackReady = false;
    }

  }

 if (STATE == 4)   // Arrive near nest hole
  {
    if (greenReady == true) 
    {
      //Serial.print("BG.= Boutton Green has been pressed");
      lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print ("Stuck. Eaten");
      lcd.setCursor(0, 1);
      lcd.print ("by Snake");
      delay(1950);
      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.print ("   Try Again  ");
      delay(1500);
      lcd.clear();
      StateButtonGreen = 0;
      StateButtonGreen = LOW;
      StateButtonBlack = LOW;
      Instruction4();

      greenReady = false;
    }

    else if (blackReady == true)
    {
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("Go around");
      delay(1950);
      lcd.clear();
      StateButtonBlack = 0;
      Instruction5();
      blackReady = false;
    }

  }

 if (STATE == 5)   // Found other way.Now facing Turtle Gang
  {
    if (greenReady == true) 
    {
      //Serial.print("BG.= Boutton Green has been pressed");
      lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print ("Defeated Turtle");
      lcd.setCursor(0, 1);
      lcd.print ("Ninja");
      delay(1950);
      lcd.clear();
      StateButtonGreen = 0;
      StateButtonGreen = LOW;
      StateButtonBlack = LOW;
      Instruction6();

      greenReady = false;
    }

    else if (blackReady == true)
    {
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print (" Lost to Ninja ");
      delay(1950);
      lcd.clear();

      lcd.setCursor (0, 1);
      lcd.print ("   Try Again  ");
      delay(1500);
      lcd.clear();
      StateButtonBlack = 0;
      Instruction5();

      blackReady = false;
    }
    
  }
  
}

void Instruction0()
  {
      lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print ("Press the green");
      lcd.setCursor(0, 1);
      lcd.print ("Button");
      delay(1999);
      lcd.clear();   

      STATE = 7;
  }

void Instruction1() 
{
  lcd.setCursor(2, 0);
  lcd.print ("Find pizza ");
  delay(2000);
  lcd.setCursor (0, 1);
  lcd.print ("YES : Press GR.");
  delay(1500);
  //lcd.clear();
  lcd.setCursor (0, 1);
  lcd.print ("NO : Press BL.");
  delay(1500);
  lcd.clear();

  STATE = 1;

}

void Instruction2() 
{
  lcd.setCursor(0, 0);
  lcd.print ("Want to eat it ?");
  delay(2000);
  lcd.setCursor (0, 1);
  lcd.print ("YES : Press GR.");
  delay(1500);
  //lcd.clear();
  lcd.setCursor (0, 1);
  lcd.print ("NO : Press BL.");
  delay(1500);
  lcd.clear();

  STATE = 2;

}

void Instruction3() 
{
  lcd.setCursor(0, 0);
  lcd.print ("Now Encountering");
  lcd.setCursor(0, 1);
  lcd.print (" the stairs");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print ("Drag down with");
  lcd.setCursor(0, 1);
  lcd.print ("mouth?:");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor (0, 1);
  lcd.print ("YES : Press GR.");
  delay(1500);
  lcd.setCursor (0, 1);
  lcd.print ("NO : Press BL.");
  delay(1500);
  lcd.clear();

  STATE = 3;

}

void Instruction4()
{
  lcd.setCursor(0, 0);
  lcd.print ("Arrive near ");
  lcd.setCursor(0, 1);
  lcd.print ("Nest Hole");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print ("Too small to ");
  lcd.setCursor(0, 1);
  lcd.print ("fit Pizza");
  delay(2000);
  lcd.clear();  
  
  lcd.setCursor(0, 0);
  lcd.print ("Force it ?");
  lcd.setCursor(0, 1);
  delay(1500);
  lcd.clear();
  
  lcd.setCursor (0, 1);
  lcd.print ("YES : Press GR.");
  delay(1500);
  lcd.setCursor (0, 1);
  lcd.print ("NO : Press BL.");
  delay(1500);
  lcd.clear();

  STATE = 4;
}

void Instruction5()
{
  lcd.setCursor(0, 0);
  lcd.print ("Found other");
  lcd.setCursor(0, 1);
  lcd.print ("  Way ");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print ("Encounter");
  lcd.setCursor(0, 1);
  lcd.print ("  Turtle Ninja ");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print ("  Fight ?");
  lcd.setCursor(0, 1);
  delay(1500);
  lcd.clear();
  
  lcd.setCursor (0, 1);
  lcd.print ("YES : Press GR.");
  delay(1500);
  lcd.setCursor (0, 1);
  lcd.print ("NO : Press BL.");
  delay(1500);
  lcd.clear();

  STATE = 5;
}






void Instruction6()
{
  lcd.setCursor(0, 0);
  lcd.print ("CONGRATULATION");
  lcd.setCursor(0, 1);
  lcd.print ("  YOU WIN! ");
  delay(3000);
  

}


void Story()
//  He used to eat cheese and garbage all over the city.  
//  Then he and his friend cockroach found an empty box. 
//  It is written that Papa John’s makes a legendary pizza like no other.
//  It is said to be one of the most exquisite food of the food chain; the food of the gods.
//  He then decides to take a quest on an adventure to find this legendary food.


{
  lcd.setCursor(0,0);
  lcd.print("He used to eat ");
  lcd.setCursor(0,1);
  lcd.print("cheese and");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("garbage all over");
  lcd.setCursor(0,1);
  lcd.print("the city.");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Then he and his ");
  lcd.setCursor(0,1);
  lcd.print("friend cockroach");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("found an empty ");
  lcd.setCursor(0,1);
  lcd.print("box.");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("It is written ");
  lcd.setCursor(0,1);
  lcd.print("that Papa John’s");
  delay(2200);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("makes a ");
  lcd.setCursor(0,1);
  lcd.print("legendary pizza ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("like no other.");
  lcd.setCursor(0,1);
  delay(2500);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("It is said to be");
  lcd.setCursor(0,1);
  lcd.print("one of the most ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("exquisite food ");
  lcd.setCursor(0,1);
  lcd.print("of the food ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("chain;");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("the food of the ");
  lcd.setCursor(0,1);
  lcd.print("gods.");
  delay(2500);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("He then decides ");
  lcd.setCursor(0,1);
  lcd.print("to take a quest");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("on an adventure");
  lcd.setCursor(0,1);
  lcd.print("to find this ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("legendary food.");
  delay(2500);
  lcd.clear();
  
  
  STATE = 6;
}

