#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

const int ButtonGreen = 3; //button 28 is right
const int ButtonBlack = 2; // button 30 is left

String commData = "";

int StateButtonGreen = 0;
int StateButtonBlack = 0;



int STATE = 0;

int serialData;

boolean PressingButtonGreen = false;
boolean PressingButtonBlack = false;


String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(ButtonGreen, INPUT);
  pinMode(ButtonBlack, INPUT);

  STATE = 0;

  inputString.reserve(200);

}

void loop()
{



  if (STATE == 0)
  {
    Instruction1();
  }


  if (STATE == 1)  // Did you find pizza?
  {

    if (stringComplete) {
      if (inputString.equals("yes"))
      {
        Serial.println("You found pizza!");
        Instruction2();

      }

      else if (inputString.equals("no"))
      {

        Serial.println ("Didn't Find!");

        STATE = 0;

      }

      inputString = "";
      stringComplete = false;
    }



  }

  if (STATE == 2)   // Do you eat the Pizza here?
  {
    if (stringComplete) {
      if (inputString.equals("yes"))
      {
        Serial.println ("You were killed by a pigeon");
        Serial.println ("Try again");
        Instruction2();
      }

      else if (inputString.equals("no"))
      {
        Serial.println ("Take it home");

        Instruction3();
      }



    }
  }

  if (STATE == 3)   // Encountering stairs
  {
    if (stringComplete) {
      if (inputString.equals("yes"))
      {
        Serial.println ("You got stepped on by a person");
        Serial.println ("Try again");

        Instruction3();
      }

      else if (inputString.equals("no"))
      {
        Serial.println ("Throw the pizza down the stairs");
        Instruction4();
      }

    }

    if (STATE == 4)   // Arrive near nest hole
    {
      if (stringComplete) {
        if (inputString.equals("yes"))
        {
          //Serial.print("BG.= Boutton Green has been pressed");
          Serial.println ("You got stuck and were eaten by a feral Donald Trump");
          Serial.println ("Try Again");

          Instruction4();
        }

        else if (inputString.equals("no"))
        {
          Serial.println ("Go around");

          Instruction5();
        }

      }

      if (STATE == 5)   // Found other way.Now facing Turtle Gang
      {
        if (stringComplete) {
          if (inputString.equals("yes"))
          {
            //Serial.print("BG.= Boutton Green has been pressed");
            Serial.println ("Defeated the ninja turtle gang");

            Instruction6();

          }

          else if (inputString.equals("no"))
          {
            Serial.println ("Killed by ninja turtle.  They stole your pizza.");
            Serial.println ("Try again");
            Instruction5();
          }

        }

      }



      void Instruction1()
      {
        Serial.println ("Did you find a pizza?");
        Serial.println ("Enter yes or no");

        STATE = 1;

      }

      void Instruction2()
      {
        Serial.println ("Do you want to eat it here?");

        STATE = 2;

      }

      void Instruction3()
      {
        Serial.println ("You encounter some stairs");
        Serial.println ("Do you want to drag it down behind you?");


        STATE = 3;

      }

      void Instruction4()
      {
        Serial.println ("You arrive near your mouse hole.");
        Serial.println ("It is too small to fit the pizza easily. Do you want to force it through?");

        STATE = 4;
      }

      void Instruction5()
      {
        Serial.println ("Found another way in!");
        Serial.println ("Encountered a ninja turtle gang!");


        Serial.println ("Fight or run?"); //Make sure to make serial option fight or run, not yes or no

        STATE = 5;
      }






      void Instruction6()
      {
        Serial.println ("CONGRATULATIONS. YOU WON. EAT THAT PIZZA.");
      }




      void serialEvent() {
        while (Serial.available()) {
          // get the new byte:
          char inChar = (char)Serial.read();
          // add it to the inputString:
          //inputString += inChar;

          if (inChar != '\n') {
            inputString += inChar;
          }

          // if the incoming character is a newline, set a flag
          // so the main loop can do something about it:
          if (inChar == '\n') {
            stringComplete = true;
          }
        }
      }
