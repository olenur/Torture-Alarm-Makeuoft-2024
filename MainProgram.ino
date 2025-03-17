#include <RTClib.h>
#include <Wire.h>
RTC_PCF8523 rtc;

int alarmH = 0, alarmM = 0;

void torture()
{
  digitalWrite(5, HIGH);
  //Other torture devices functionality will be here
}

char t[32];
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  //rtc.adjust(DateTime(F(__DATE__),F(__TIME__))); //(This code is commented out for utility)
  digitalWrite(8, HIGH);
  alarmH = Serial.parseInt();
  Serial.println("Enter the time your alarm should ring (format: HH:MM): ");
  while (!Serial.available()) {
    delay(10);
  }
  String input = Serial.readStringUntil('\n');
  sscanf(input.c_str(), "%d:%d", &alarmH, &alarmM);
}
void loop()
{
  DateTime now = rtc.now();

  sprintf(t, "%02d:%02d:%02d %02d/%02d/%02d", now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());  
  Serial.print(F("Date/Time: "));
  Serial.println(t);
  
  if(now.minute() == alarmM && now.hour() == alarmH && now.second() <= 5) torture();
  if(now.minute() == alarmM && now.hour() == alarmH && now.second() <= 30) digitalWrite(8, LOW);
  else if(now.minute() + 1 == alarmM && now.hour() == alarmH) digitalWrite(8, LOW);
  
  delay(500);
  digitalWrite(5, LOW);
  digitalWrite(8, HIGH);
}