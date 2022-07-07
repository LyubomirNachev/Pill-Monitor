#include "LiquidCrystal.h"
LiquidCrystal lcd(3, 2, A3, A2, A1, A0);

int hapche = 0;

int bizogama = 0;
int waltrikom = 0;
int siofor = 0;
int apidra = 0;
int tujeo = 0;
int magneb6 = 0;

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
    hapche = 0;
  } else if (value > 810 && value < 850) {    // button - right
    if(hapche == 0){
      bizogama++;
      lcd.clear();
      lcd.print("Bizogama: "+(String)bizogama+"");
    }else if(hapche == 1){
      waltrikom++;
      lcd.clear();
      lcd.print("Waltrikom: "+(String)waltrikom+"");
    }else if(hapche == 2){
      siofor++;
      lcd.clear();
      lcd.print("Siofor: "+(String)siofor+"");
    }else if(hapche == 3){
      apidra++;
      lcd.clear();
      lcd.print("Apidra: "+(String)apidra+"");
    }else if(hapche == 4){
      tujeo++;
      lcd.clear();
      lcd.print("Tujeo: "+(String)tujeo+"");
    }else if(hapche == 5){
      magneb6++;
      lcd.clear();
      lcd.print("Magne B6: "+(String)magneb6+"");
    }     
  } else if (value > 740 && value < 810) {    // button - down
    hapche++;
    if(hapche == 0){
      lcd.clear();
      lcd.print("Bizogama: "+(String)bizogama+"");
    }else if(hapche == 1){
      lcd.clear();
      lcd.print("Waltrikom: "+(String)waltrikom+"");
    }else if(hapche == 2){
      lcd.clear();
      lcd.print("Siofor: "+(String)siofor+"");
    }else if(hapche == 3){
      lcd.clear();
      lcd.print("Apidra: "+(String)apidra+"");
    }else if(hapche == 4){
      lcd.clear();
      lcd.print("Tujeo: "+(String)tujeo+"");
    }else if(hapche == 5){
      lcd.clear();
      lcd.print("Magne B6: "+(String)magneb6+"");
    }else{
      hapche = 0;
      lcd.clear();
      lcd.print("Bizogama: "+(String)bizogama+"");
    }
  } else if (value > 600 && value < 740) {    // button - left
    if(hapche == 0){
      bizogama--;
      lcd.clear();
      lcd.print("Bizogama: "+(String)bizogama+"");
    }else if(hapche == 1){
      waltrikom--;
      lcd.clear();
      lcd.print("Waltrikom: "+(String)waltrikom+"");
    }else if(hapche == 2){
      siofor--;
      lcd.clear();
      lcd.print("Siofor: "+(String)siofor+"");
    }else if(hapche == 3){
      apidra--;
      lcd.clear();
      lcd.print("Apidra: "+(String)apidra+"");
    }else if(hapche == 4){
      tujeo--;
      lcd.clear();
      lcd.print("Tujeo: "+(String)tujeo+"");
    }else if(hapche == 5){
      magneb6--;
      lcd.clear();
      lcd.print("Magne B6: "+(String)magneb6+"");
    }
  } else if (value > 450 && value < 600) {    // button - up
    hapche--;
    if(hapche == 0){
      lcd.clear();
      lcd.print("Bizogama: "+(String)bizogama+"");
    }else if(hapche == 1){
      lcd.clear();
      lcd.print("Waltrikom: "+(String)waltrikom+"");
    }else if(hapche == 2){
      lcd.clear();
      lcd.print("Siofor: "+(String)siofor+"");
    }else if(hapche == 3){
      lcd.clear();
      lcd.print("Apidra: "+(String)apidra+"");
    }else if(hapche == 4){
      lcd.clear();
      lcd.print("Tujeo: "+(String)tujeo+"");
    }else if(hapche == 5){
      lcd.clear();
      lcd.print("Magne B6: "+(String)magneb6+"");
    }else{
      hapche = 5;
      lcd.clear();
      lcd.print("Magne B6: "+(String)magneb6+"");
    }
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
