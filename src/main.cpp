#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#include "../lib/NeoPixelMatrix/NeoPixelMatrixClass.cpp"


#define SSID "FBI"
#define Password "scoutdog"
#define URL "http://nacatech.com:8585"

ESP8266WiFiMulti WiFiMulti;

#define maxCommands 50
int CyclesBeforeUpdate = 1;

const String defaultCommands = "clear;backgroundColor,0,0,0;space,1;addchar,f,10,0,0;addchar,a,10,0,0;addchar,i,10,0,0;addchar,l,10,0,0;addchar,e,10,0,0;addchar,d,10,0,0;space,1;show;";


NeoPixelMatrix matrix;


String  GetCommands(int timeOut){
  //for test purposes just return defult
  //return defaultCommands;
  
  //Wait For Wifi
  for(int i = 0; i < timeOut; i++){
    if ((WiFiMulti.run() == WL_CONNECTED)) {
      //Serial.println(i);

      WiFiClient client;

      HTTPClient http;


      if (http.begin(client, URL)) {  // HTTP

        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if (httpCode > 0) {
          // HTTP header has been send and Server response header has been handled

          // file found at server
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
            String payload = http.getString();
            return payload;
          }
        } else {
        }

        http.end();
      } else {
      }
    }
    delay(100);
  }
  return defaultCommands;
}



void setup() {
  Serial.begin(9600);
  delay(5000);
  Serial.println("test");
  delay(1000);
  Serial.println("test");
  
}


int updateTime = 60000;

int currentCommand = 0;
int delayUnTell = 0;
String ListOfCommands[maxCommands][10];
int refreshAt = 0;

void loop() {

  if(refreshAt < millis()){
      //Gets commands from server
    String CommandStr = GetCommands(100);

    //Sets up list of commands
    //Send dimention is max pram per command 10
    int ListOfCommandIndex = 0;

    for(int i = 0; i < CommandStr.length(); i++){
      //Serial.println("test2");
      //Removes char if its a whitespace / new line
      if(CommandStr.charAt(i) == '\n' || CommandStr.charAt(i) == ' '){
        CommandStr.remove(i,1);
        i--;
      }
      //Checks for commant and removes it
      else if(CommandStr.charAt(i) == '/'){
        int end;
        for(int x = i; x < CommandStr.length(); x++){
          if(CommandStr.charAt(x) == '\n'){
            CommandStr.remove(i , (x - i) + 1);
            i--;
            break;
          }
        }
      } 
      //Checks for command and adds it to list of commands
      else if(CommandStr.charAt(i) == ';'){
            String CurrentCommand = CommandStr.substring(0 , i+1);
            CommandStr.remove(0, i+1);
            i = -1;

            //Goes thorugh current command to add to list of commands
            int PermIndex = 0;
            for(int x = 0;x < CurrentCommand.length();x++){
              if(CurrentCommand.charAt(x) == ',' || CurrentCommand.charAt(x) == ';'){
                ListOfCommands[ListOfCommandIndex][PermIndex] = CurrentCommand.substring(0,x);
                CurrentCommand.remove(0,x+1);
                x = -1;
                PermIndex ++;
              }
            }
            ListOfCommandIndex++;
        }
    }

    //Start of intrupating commands

    refreshAt = millis() + updateTime;
  }

  
  if(delayUnTell < millis()){
    if(ListOfCommands[currentCommand][0] != ""){
      if(ListOfCommands[currentCommand][0].equalsIgnoreCase("addchar")){
        matrix.addChar(ListOfCommands[currentCommand][1].charAt(0) ,ListOfCommands[currentCommand][2].toInt(),ListOfCommands[currentCommand][3].toInt(),ListOfCommands[currentCommand][4].toInt());
      }else if(ListOfCommands[currentCommand][0].equalsIgnoreCase("clear")){
        pixels.clear();
        matrix.cusor = 0;
      }else if(ListOfCommands[currentCommand][0].equalsIgnoreCase("show")){
        pixels.show();
      }else if(ListOfCommands[currentCommand][0].equalsIgnoreCase("BackgroundColor")){
        matrix.setBackgorundColor(ListOfCommands[currentCommand][1].toInt(),ListOfCommands[currentCommand][2].toInt(),ListOfCommands[currentCommand][3].toInt());
      }else if(ListOfCommands[currentCommand][0].equalsIgnoreCase("delay")){

        delayUnTell = millis() + ListOfCommands[currentCommand][1].toInt();

      }else if(ListOfCommands[currentCommand][0].equalsIgnoreCase("space")){
          matrix.addSpace(ListOfCommands[currentCommand][1].toInt());
      }else if(ListOfCommands[currentCommand][0].equalsIgnoreCase("update")){
          CyclesBeforeUpdate = ListOfCommands[currentCommand][1].toInt();
      }else if(ListOfCommands[currentCommand][0].equalsIgnoreCase("addSpecial")){
          matrix.addSpecial(ListOfCommands[currentCommand][1].charAt(0) ,ListOfCommands[currentCommand][2].toInt(),ListOfCommands[currentCommand][3].toInt(),ListOfCommands[currentCommand][4].toInt());
      }
    }
    currentCommand ++;
    if(currentCommand >= maxCommands)
      currentCommand = 0; 
  }

    
  
}



