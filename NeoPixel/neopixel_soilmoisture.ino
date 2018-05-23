#include <Adafruit_NeoPixel.h>

const byte neoPin = 10; 
const byte neoPixels = 24; 
byte neoBright = 100; 
Adafruit_NeoPixel ring = Adafruit_NeoPixel(neoPixels, neoPin, NEO_GRB); 
int sensor_pin = A0;
int output_value ;
int pixelValue; 
int lastPixelValue = 100;  

void setup() {
  // put your setup code here, to run once:
  ring.begin(); 
  ring.setBrightness(neoBright); 
  ring.show(); 
  Serial.begin(9600);
}


void emptyRing(){
  for(int i = neoPixels; i>0; i--){
    ring.setPixelColor(i, ring.Color(0,0,0)); 
    ring.show(); 
    delay(30); 
  }
}


void setColor( int stopPixel){
  if (stopPixel < lastPixelValue){
    for (int i = stopPixel; i < lastPixelValue; i++){
      ring.setPixelColor(i, ring.Color(0,0,0)); 
      ring.show(); 
    }
  }
  else{  
    int r = 0; 
    int g = 255; 
    int b = 0; 
    for(int j= 0; j<stopPixel; j++){
      if (j > 10){
        r = 255; 
        g = 255; 
        b = 0; 
      }
      if (j > 16){
        r= 255; 
        g= 0; 
        b=0; 
      }
    ring.setPixelColor(j, ring.Color(r, g, b)); 
    ring.show(); 
    delay(10); 
    }
   }
  lastPixelValue = stopPixel; 
}

void loop() {
   output_value= analogRead(sensor_pin);
   output_value = map(output_value,1024,0,0,100);
   pixelValue = map(output_value, 100, 0, 0, 24); 
   setColor(pixelValue); 
   delay(200); 
}
