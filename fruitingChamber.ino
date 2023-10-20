#include <SPI.h>
#include <Ds1302.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define Type DHT11
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Ds1302 rtc(3, 5, 6); //(RST, CLK, DAT)

const int fan = 9; 
const int heater = 10;
const int mist = 7;
const int light = 4;
const int HTsense = 12;
float humidity;
float tempF;
float tempC;
static int fanCounter;
static int heaterCounter;
static int mistCounter; 
static bool heaterState = false;
static bool mistState = false;
DHT HT(HTsense, Type);

void toggleHeater(bool state) {
  if(state == true) {
    digitalWrite(heater, HIGH);
    digitalWrite(fan, HIGH);
    fanCounter = 60;
    heaterCounter = 4;
  } else if(state == false){
    if(heaterCounter > 0) {
      digitalWrite(heater, HIGH); 
      heaterCounter -= 1;     
    } else {
      digitalWrite(heater, LOW);
    }
    if(fanCounter > 0) {
      digitalWrite(fan, HIGH);
      fanCounter -=1;
    } else {
      digitalWrite(fan, LOW);
    }
  }
}
void toggleMist(bool state) {
  if(state) {
    if(mistState == true) {
      mistCounter = 30;
    } else {
      digitalWrite(mist, HIGH);
      delay(100);
      digitalWrite(mist, LOW);  
      mistState = true; 
      mistCounter = 30; 
    }
  } else if(!state) {
      if(mistCounter > 0) {
        mistCounter -=1;
        Serial.println(mistCounter);
      } else
        if(mistState == true){
          digitalWrite(mist, HIGH);
          delay(100);
          digitalWrite(mist, LOW);
          delay(50);    
          digitalWrite(mist, HIGH);
          delay(100);
          digitalWrite(mist, LOW);
          mistState = false;
        } else {}
  }
}

void setup() {
  Serial.begin(9600);
  HT.begin();
  delay(100);
  rtc.init();
  pinMode(fan, OUTPUT);
  pinMode(heater, OUTPUT);
  pinMode(mist, OUTPUT);
  pinMode(light, OUTPUT);
  pinMode(HTsense, INPUT);

//  If the RTC needs to be updated
  if (rtc.isHalted())
    {
        Serial.println("RTC is halted. Setting time...");
        Ds1302::DateTime dt = {
            .year = 23,
            .month = Ds1302::MONTH_MAY,
            .day = 8,
            .hour = 21,
            .minute = 22,
            .second = 0,
            .dow = Ds1302::DOW_MON
        };
        rtc.setDateTime(&dt);
    }
  
  //  If the OLED address is not found
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  delay(2000);
}

void loop() {
  Ds1302::DateTime now;
  rtc.getDateTime(&now);
  Serial.print(now.hour);
  Serial.print(":");
  if(now.minute < 10) {
    Serial.print(0);
  }
  Serial.print(now.minute);
  Serial.print("  ||  Humidity: ");
  if(humidity > 100) {
    Serial.print(100);
  } else {
    Serial.print(humidity);
  }
  Serial.print("%  ||  ");
  Serial.print("Temperature: ");
  Serial.print(tempF);
  Serial.println("F");
  
  humidity = HT.readHumidity();
  tempF = HT.readTemperature(true);
  tempC = HT.readTemperature();

//  Lighting Schedule 
  if(now.hour < 12) {
    digitalWrite(light, HIGH);
  } else {
    digitalWrite(light, LOW);
  }

  //  Temperature monitoring and heater control
  if(tempF < 70) {
    toggleHeater(true);
    heaterState = true;
  } else {
    toggleHeater(false);
    heaterState = false;
  }

  //  Humidity monitoring and mist control
  if(humidity < 85) {
    toggleMist(true);
  } else {
    toggleMist(false);
  }
  //  OLED Display  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(23,16);
  display.print(tempF);
  display.println(" F");

  display.setTextSize(2);         
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(27,32);
  display.print(humidity);
  display.println("%");
  delay(1000);
}
