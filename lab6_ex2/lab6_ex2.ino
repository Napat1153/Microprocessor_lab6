#include <ThreeWire.h> 
#include <RtcDS1302.h>

ThreeWire myWire(4,5,2); // IO, SCLK, CE 
RtcDS1302<ThreeWire> Rtc(myWire);

void printDateTime(const RtcDateTime& dt){ 
  Serial.print(dt.Year(), DEC);
  Serial.print('/');
  Serial.print(dt.Month(), DEC); 
  Serial.print('/');
  Serial.print(dt.Day(), DEC); 
  Serial.print(' '); 
  Serial.print(dt.Hour(), DEC); 
  Serial.print(':'); 
  Serial.print(dt.Minute(), DEC); 
  Serial.print(':'); 
  Serial.print(dt.Second(), DEC); 
  Serial.println();
  Serial.print("Total Seconds since 1/1/2000 : "); 
  Serial.print(dt.TotalSeconds());
  Serial.println();
}
RtcDateTime start_instant;
void setup() { 
  Serial.begin(57600);
  Rtc.Begin();
  RtcDateTime setting_time(2020,2,20,00,00,00);
// year, month, dayOfMonth, hour, minute, second
printDateTime(setting_time);
//Try to comment This line
Rtc.SetDateTime(setting_time);
start_instant = Rtc.GetDateTime().TotalSeconds();
Serial.println("START");
}

void loop()
 {
RtcDateTime now = Rtc.GetDateTime();
auto seconds = now.TotalSeconds();

if(seconds - start_instant <= 120)
{
  printDateTime(now);

  digitalWrite(13,seconds%2);
}
else{
  digitalWrite(13,LOW);
}
delay(1000); }
