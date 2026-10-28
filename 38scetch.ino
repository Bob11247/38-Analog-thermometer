код:
float voltage = 0;
float sensor = 0;
float currentC = 0;
int angle = 0;

#include <Servo.h>
Servo myservo;

void setup()
{
  myservo.attach(4);
}

int calculateServo(float temperature)
{
float resulta;
  int resultb;
  resulta = -6 * temperature;
  resulta = resulta + 180;
  resultb = int(resulta);
  return resultb;
}
  
void loop()
{
//to read current temp
  sensor = analogRead(0);
  voltage = (sensor * 5000) / 1024;
  voltage = voltage - 500;
  currentC = voltage/10;

  angle = calculateServo(currentC);

  if (angle >= 0 && angle <= 180)
  {
    myservo.write(angle);
    delay(1000);
  }
}
