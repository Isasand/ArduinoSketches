#include <Adafruit_NeoPixel.h>

const byte neoPin = 10; 
const byte neoPixels = 24; 
byte neoBright = 100; 
Adafruit_NeoPixel ring = Adafruit_NeoPixel(neoPixels, neoPin, NEO_GRB); 



void setup() {
  // put your setup code here, to run once:
  ring.begin(); 
  ring.setBrightness(neoBright); 
  ring.show(); 
}

void setPink(){

    int i = 24; 
for (int j = 0; j<neoPixels; j++){
    ring.setPixelColor(j-1, ring.Color(0,0,0)); 
    ring.setPixelColor(j, ring.Color(255,20,147)); 
    ring.setPixelColor(i+1, ring.Color(0,0,0)); 
    ring.setPixelColor(i, ring.Color(0, 0, 153)); 
    ring.show(); 
    delay(30); 
    i--;
}
ring.setPixelColor(23, ring.Color(0,0,0)); 
ring.show(); 

}

void setPink2(){

    int i = 24; 
for (int j = 0; j<neoPixels; j++){
    //ring.setPixelColor(j-1, ring.Color(0,0,0)); 
    ring.setPixelColor(j, ring.Color(255,20,147)); 
    //ring.setPixelColor(i+1, ring.Color(0,0,0)); 
    ring.setPixelColor(i, ring.Color(0, 0, 153)); 
    ring.show(); 
    delay(30); 
    i--;
}
/*ring.setPixelColor(23, ring.Color(0,0,0)); 
ring.show(); */

}

void setGreen(){
  for(int i = 0; i < 10; i++){
    ring.setPixelColor(i, ring.Color(0, 204, 0));
    ring.show(); 
    delay(30); 
  }
}

void setYellow(){
  for(int i = 10; i< 14; i++){
    ring.setPixelColor(i, ring.Color(255, 255, 0)); 
    ring.show(); 
    delay(30); 
  }
}

void setOrange(){
  for(int i = 14; i<19; i++){
    ring.setPixelColor(i, ring.Color(204, 51, 0)); 
    ring.show(); 
   delay(30); 
  }
}

void setRed(){
  for(int i = 19; i<neoPixels; i++){
    ring.setPixelColor(i, ring.Color(204, 0, 0)); 
    ring.show(); 
    delay(30); 
  }
}

void emptyRing(){
  for(int i = neoPixels; i>0; i--){
    ring.setPixelColor(i, ring.Color(0,0,0)); 
    ring.show(); 
    delay(30); 
  }
}

void balls(){

    int i = 24; 
for (int j = 0; j<neoPixels; j++){
    ring.setPixelColor(j-1, ring.Color(0,0,0)); 
    ring.setPixelColor(j, ring.Color(255, 255, 0)); 
    ring.setPixelColor(i+1, ring.Color(0,0,0)); 
    ring.setPixelColor(i, ring.Color(0, 0, 153)); 
    ring.show(); 
    delay(30); 
    i--;
}
ring.setPixelColor(23, ring.Color(0,0,0)); 
ring.show(); 

}


void oneBall(){
  for (int j = neoPixels; j>=0; j--){
    ring.setPixelColor(j, ring.Color(255, 255, 0)); 
    
    ring.setPixelColor(j-1, ring.Color(0,0,0)); 
    ring.show(); 
    delay(10); 
  }
}


void onePinkBall(){

for (int j = 0; j<neoPixels; j++){
    ring.setPixelColor(j-1, ring.Color(0,0,0)); 
    ring.setPixelColor(j, ring.Color(255,20,147)); 
    ring.show(); 
    delay(30);
}
ring.setPixelColor(23, ring.Color(0,0,0)); 
ring.show(); 

}

void loop() {
    
  /*setGreen(); 
  setYellow(); 
  setOrange(); 
  setRed(); 
  emptyRing(); */
  onePinkBall(); 
  setPink(); 
  setPink(); 
  
  setPink(); 
  setPink2();
  
  emptyRing();  
  balls(); 
  oneBall(); 
  oneBall(); 
  oneBall(); 
}