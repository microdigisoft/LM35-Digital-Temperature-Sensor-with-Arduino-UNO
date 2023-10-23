float temp;//Variable to read store temperature reading
int tempPin = 0;// Initialize A0 pin to read temperature data
void setup() {
  Serial.begin(9600);
}
void loop() {
  temp = analogRead(tempPin);// read analog volt from sensor and save to variable temp
  temp = temp * 0.48828125;  // convert the analog volt to its temperature equivalent
  Serial.print("TEMPERATURE = ");
  Serial.print(temp); // display temperature value
  Serial.println();
  delay(1000); // update sensor reading each one second
}