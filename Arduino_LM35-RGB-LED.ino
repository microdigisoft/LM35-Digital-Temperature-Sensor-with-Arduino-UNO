// Declaring global variable
int R_LED = 13;//Initialize the pin13 for RED LED
int G_LED = 12;//Initialize the pin13 for YELLOW LED
int B_LED = 10;//Initialize the pin13 for BLUE LED
const int temp = 0;
void setup() {
  Serial.begin (9600);
  pinMode (R_LED, OUTPUT);// declaring the RED LED as an output
  pinMode (B_LED, OUTPUT);// declaring the BLUE LED as an output
  pinMode (G_LED, OUTPUT);// declaring the YELLOW LED as an output
  pinMode (temp, INPUT);
}
void loop()
{
  float Real_Voltage = analogRead(temp) * 0.004882814; // reading the sensor value and convert it to voltage
  float Temp_C = Real_Voltage * 100.0;   // changing the voltage into Celsius
  float Temp_F = Temp_C * (9.0 / 5.0) + 32.0;
  Serial.print("Temp in C: ");
  Serial.println(Temp_C);
  Serial.print("Temp in F: ");
  Serial.println(Temp_F);
  if ( Temp_C >= 36.0)
  {
    Serial.println("Warning: It is hot");
    Serial.println("");
    digitalWrite(R_LED, HIGH); // Red LED on

    delay(2000);// wait for one sec
    digitalWrite(G_LED, LOW);
    digitalWrite(R_LED, LOW);// Red LED off
    delay(2000); // wait for one sec
  }
  else if (Temp_C <= 26.0)
  {
    Serial.println("Warning: It is cold");
    Serial.println("");
    digitalWrite(G_LED, HIGH);  // GREEN LED on
    delay(2000);
    digitalWrite(B_LED, LOW);
    digitalWrite(G_LED, LOW);
    //analogWrite(Buz,0);
    delay(2000);    // wait for a sec
  }
  else
  {
    Serial.println("Warning: It is Normal ");
    Serial.println("");
    digitalWrite(R_LED, LOW);
    digitalWrite(G_LED, LOW);
    digitalWrite(B_LED, HIGH);
    delay(2000);
  }
}
