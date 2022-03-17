#include <Adafruit_NeoPixel.h>
#include "NeoPixelMatrix.h"

#define Pin 16
#define height 8
#define width 32

Adafruit_NeoPixel pixels(256, Pin, NEO_GRB + NEO_KHZ800);

class NeoPixelMatrix{
  private:
    
    
    int backgroundColor [3];

    int space = 1;

    //Stores color of all the pixels


  public:
    int cusor;


    NeoPixelMatrix(void){
      pixels.begin();
      pixels.clear();
      cusor = 0;

      //Sets background color to nothing for defult color
      for(int i = 0;i < 3;i++){
        backgroundColor[i] = 0;
      }
    }

    //Returns if char is found and adds it to array at the cusor point and moves cusor
    void addChar(char ch, uint8 r, uint8 g, uint8 b){
      bool boolOutArr [8][4];

      //Sets all to false by defult
      for(int i = 0;i < 8; i++){
        for(int x = 0; x < 4;x++){
          boolOutArr[i][x] = false;
        }
      }
      
      if(ch == 'a'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = false;
        boolOutArr[6][2] = false;
        boolOutArr[6][3] = true;
      }
      
      if(ch == 'b'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = false;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = false;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = false;
      }
      
      if(ch == 'c'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = false;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = false;
        boolOutArr[4][2] = false;
        boolOutArr[4][3] = false;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = false;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = true;
      }
      
      if(ch == 'd'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = false;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = false;
        boolOutArr[4][2] = false;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = false;
      }
      
      if(ch == 'e'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = false;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = false;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = false;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = true;
      }
      
      if(ch == 'f'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = false;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = false;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = false;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = false;
        boolOutArr[6][2] = false;
        boolOutArr[6][3] = false;
      }

      if(ch == 'g'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = false;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = false;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = true;
      }

      if(ch == 'h'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = false;
        boolOutArr[2][2] = false;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = false;
        boolOutArr[6][2] = false;
        boolOutArr[6][3] = true;
      }

      if(ch == 'i'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = false;

        //Line 2
        boolOutArr[3][0] = false;
        boolOutArr[3][1] = true;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = false;

        //Line 3
        boolOutArr[4][0] = false;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = false;
        boolOutArr[4][3] = false;

        //Line 4
        boolOutArr[5][0] = false;
        boolOutArr[5][1] = true;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = false;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = false;
      }

      if(ch == 'j'){
        
        //Line 1
        boolOutArr[2][0] = false;
        boolOutArr[2][1] = false;
        boolOutArr[2][2] = false;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = false;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = false;
        boolOutArr[4][1] = false;
        boolOutArr[4][2] = false;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = true;
      }

      if(ch == 'k'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = false;
        boolOutArr[2][2] = false;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = true;
        boolOutArr[3][3] = false;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = false;
        boolOutArr[4][3] = false;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = true;
        boolOutArr[5][3] = false;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = false;
        boolOutArr[6][2] = false;
        boolOutArr[6][3] = true;
      }

      if(ch == 'l'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = false;
        boolOutArr[2][2] = false;
        boolOutArr[2][3] = false;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = false;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = false;
        boolOutArr[4][2] = false;
        boolOutArr[4][3] = false;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = false;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = true;
      }

      if(ch == 'm'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = true;
        boolOutArr[3][2] = true;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = false;
        boolOutArr[4][2] = false;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = false;
        boolOutArr[6][2] = false;
        boolOutArr[6][3] = true;
      }

      if(ch == 'n'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = false;
        boolOutArr[2][2] = false;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = true;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = true;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = false;
        boolOutArr[6][2] = false;
        boolOutArr[6][3] = true;
      }

      if(ch == 'o'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = false;
        boolOutArr[4][2] = false;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = true;
      }

      if(ch == 'p'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = false;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = false;
        boolOutArr[6][2] = false;
        boolOutArr[6][3] = false;
      }

      if(ch == 'q'){
        
        //Line 1
        boolOutArr[2][0] = false;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = false;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = false;
        boolOutArr[4][2] = false;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = true;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = false;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = true;
      }

      if(ch == 'r'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = false;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = false;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = false;
        boolOutArr[6][2] = false;
        boolOutArr[6][3] = true;
      }

      if(ch == 's'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = false;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = false;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = true;
      }

      if(ch == 't'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = false;

        //Line 2
        boolOutArr[3][0] = false;
        boolOutArr[3][1] = true;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = false;

        //Line 3
        boolOutArr[4][0] = false;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = false;
        boolOutArr[4][3] = false;

        //Line 4
        boolOutArr[5][0] = false;
        boolOutArr[5][1] = true;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = false;

        //Line 5
        boolOutArr[6][0] = false;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = false;
        boolOutArr[6][3] = false;
      }

      if(ch == 'u'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = false;
        boolOutArr[2][2] = false;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = false;
        boolOutArr[4][2] = false;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = true;
      }

      if(ch == 'v'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = false;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = false;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = true;
        boolOutArr[3][3] = false;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = false;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = false;

        //Line 4
        boolOutArr[5][0] = false;
        boolOutArr[5][1] = true;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = false;

        //Line 5
        boolOutArr[6][0] = false;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = false;
        boolOutArr[6][3] = false;
      }

      if(ch == 'w'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = false;
        boolOutArr[2][2] = false;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = false;
        boolOutArr[4][2] = false;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = true;
        boolOutArr[5][2] = true;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = true;
      }

      if(ch == 'x'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = false;
        boolOutArr[2][2] = false;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = false;
        boolOutArr[3][1] = true;
        boolOutArr[3][2] = true;
        boolOutArr[3][3] = false;

        //Line 3
        boolOutArr[4][0] = false;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = false;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = false;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = true;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = false;
        boolOutArr[6][2] = false;
        boolOutArr[6][3] = true;
      }

      if(ch == 'y'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = false;
        boolOutArr[2][2] = false;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = true;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = false;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = true;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = true;

        //Line 4
        boolOutArr[5][0] = false;
        boolOutArr[5][1] = true;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = false;

        //Line 5
        boolOutArr[6][0] = false;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = false;
        boolOutArr[6][3] = false;
      }

      if(ch == 'z'){
        
        //Line 1
        boolOutArr[2][0] = true;
        boolOutArr[2][1] = true;
        boolOutArr[2][2] = true;
        boolOutArr[2][3] = true;

        //Line 2
        boolOutArr[3][0] = false;
        boolOutArr[3][1] = false;
        boolOutArr[3][2] = true;
        boolOutArr[3][3] = true;

        //Line 3
        boolOutArr[4][0] = false;
        boolOutArr[4][1] = true;
        boolOutArr[4][2] = true;
        boolOutArr[4][3] = false;

        //Line 4
        boolOutArr[5][0] = true;
        boolOutArr[5][1] = true;
        boolOutArr[5][2] = false;
        boolOutArr[5][3] = false;

        //Line 5
        boolOutArr[6][0] = true;
        boolOutArr[6][1] = true;
        boolOutArr[6][2] = true;
        boolOutArr[6][3] = true;
      }




      for(int i = 0;i < 8; i++){
        for(int x = 0; x < 4;x++){

          if((x + cusor)%2 == 0)
            if(boolOutArr[i][x])
              pixels.setPixelColor(((cusor * 8) + (x * 8) + i),r,g,b);
            else
              pixels.setPixelColor(((cusor * 8) + (x * 8) + i),backgroundColor[0],backgroundColor[1],backgroundColor[2]);
          else if((x + cusor)%2 != 0)
            if(boolOutArr[i][x])
              pixels.setPixelColor(((cusor * 8) + (x * 8) + (7 - i)),r,g,b);
            else
               pixels.setPixelColor(((cusor * 8) + (x * 8) + (7 - i)),backgroundColor[0],backgroundColor[1],backgroundColor[2]);
        }
      }

      for(int i = 0; i < space * 8; i++){
        pixels.setPixelColor(i+((cusor+4)*8),backgroundColor[0],backgroundColor[1],backgroundColor[2]);
      }

      cusor += space + 4;
    }

    void addSpace(int sp){
      for(int i = 0; i < 8*sp;i++){
        pixels.setPixelColor(((cusor*8)+i),backgroundColor[0],backgroundColor[1],backgroundColor[2]);
      }
      cusor += sp;
    }

    void setBackgorundColor(int r, int g,int b){
      backgroundColor[0] = r;
      backgroundColor[1] = g;
      backgroundColor[2] = b;
    }


};