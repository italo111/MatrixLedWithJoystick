#include<LedControl.h>
int DIN = 12;
int CS = 11;
int CLK = 10;
int buzzer = 9;

LedControl lc = LedControl(DIN,CLK,CS,0);
int x = 0;
int y = 0;
int xPin;
int yPin;
void setup() {
  // put your setup code here, to run once:
lc.shutdown(0,false);
lc.setIntensity(0,1);
lc.clearDisplay(0);
Serial.begin(9600);

}


  void loop(){
    noTone(buzzer);
    xPin = analogRead(1);//A0
    yPin = analogRead(0);//A1
    
 if(xPin > 700){
     x++;
    if(x == 9){
     
      x = 8;
      tone(buzzer,450);
      
    }
    printByte( x,y);

 }
 else if(xPin < 300){
  x--;
  if(x<1){
    x =1;
    tone(buzzer,450);
    
  }
  printByte(x,y);
 }
 else if(yPin <300){
  y++;
  printByte(x,y);
  if(y==9){
  y = 8;
  tone(buzzer,20);
  delay(20);
  }
 }
 else if(yPin >700){
  y--;
  if(y <1){
    y = 0;
    tone(buzzer,20);
    delay(20);
  }
  printByte(x,y);
 }
 

 
// do something based on keystroke recieved


}
//void printByte(byte character[], int x){
void printByte( int g, int r){
  //int i ;
  //for(i = 0; i<8; i++){
    //lc.setRow(0,i,character[i]);
  //}
  
  for(int i = 0; i< 8; i++){
    
    if(i == (g -1)){
     // lc.setRow(0, i, 0x01);
      if(y== 0){
        lc.setRow(0,i,0x01);
      }
      else if(y == 1){
        lc.setRow(0,i,0x02);
      }
      else if(y==2){
        lc.setRow(0,i,0x04);
      }
      else if(y == 3){
        lc.setRow(0,i,0x08);
      }
      else if(y==4){
        lc.setRow(0,i,0x10);
      }
      else if(y == 5){
        lc.setRow(0,i,0x20);
      }
      else if(y==6){
        lc.setRow(0,i,0x40);
      }
      else if(y == 7){
        lc.setRow(0,i,0x80);
      }
     
     
    }
    else{
      lc.setRow(0,i,0x00);
    }
  }
  
  
}
