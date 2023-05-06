const int outputPin = 13;
const int inputPin = 8;
const int shootPerSec = 13;
const int delatMillisAdd = 1000 / shootPerSec;
const int magOnTime = 35;

void setup(void)
{
  pinMode(outputPin, OUTPUT);
  pinMode(inputPin, INPUT);
}
long long timecnt = 0;
uint8_t readSta = 0;

long long enable_time = 0;
void loop(void)
{
  readSta <<= 1;
  if (digitalRead(inputPin))
  {
    readSta++;
  }

  if (readSta == 0)
  {
    if (timecnt < 0)
    {
      timecnt = millis() + delatMillisAdd;
      enable_time = millis() + magOnTime;
    }
    else
    {
      if (millis() > timecnt)
      {
        timecnt = millis() + delatMillisAdd;
        enable_time = millis() + magOnTime;
      }
    }
  }
  else
  {
    timecnt = -1;
  }

  if (millis() < enable_time)
  {
    digitalWrite(outputPin, HIGH);
  }
  else
  {
    digitalWrite(outputPin, LOW);
  }
}
