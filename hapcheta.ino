#include "LiquidCrystal.h"
LiquidCrystal lcd(3, 2, A3, A2, A1, A0);

int bizogama = 0;
int waltrikom = 0;
int siofor = 0;
int apidra = 0;
int tujeo = 0;
int magneb6 = 0;
char* list[]{"Bizogama: ", bizogama,
             "Waltrikom: ", waltrikom,
             "Siofor: ", siofor,
             "Apidra: ", apidra,
             "Tujeo: ", tujeo,
             "Magne B6: ", magneb6};
void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(" Pill monitor ");
  Serial.begin(9600);
}
void loop() {
  int value = analogRead(A4);
  
  //Buttons
  //Serial.println("Button:");
  //Serial.println(value);
  
  if (value > 850 && value < 1000) {   // button - menu
    lcd.clear();
    lcd.print("All Pills: "); 
    lcd.setCursor(0, 1);
    lcd.print("b"+(String)bizogama+"w"+(String)waltrikom+"s"+(String)siofor+"a"+(String)apidra+"t"+(String)tujeo+"m"+(String)magneb6+"");
  } else if (value > 810 && value < 850) {    // button - right
    lcd.clear();
    lcd.print("Waltrikom: "+(String)waltrikom+"");    
  } else if (value > 740 && value < 810) {    // button - down
    lcd.clear();
    lcd.print("Bizogama: "+(String)bizogama+"");
    bizogama++;
  } else if (value > 600 && value < 740) {    // button - left
    lcd.clear();
    lcd.print("B2: "+(String)bizogama+"");
  } else if (value > 450 && value < 600) {    // button - up
    lcd.clear();
    lcd.print("B3: "+(String)bizogama+""); 
  } else if (value < 450) {   // button - reset
    lcd.clear();
    lcd.print("Reset");
    bizogama = 0;
    waltrikom = 0;
    siofor = 0;
    apidra = 0;
    tujeo = 0;
    magneb6 = 0;
  }
  delay(100);
}
