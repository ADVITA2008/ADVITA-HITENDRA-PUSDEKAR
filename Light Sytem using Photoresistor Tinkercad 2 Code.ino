int led1 = 13, led2 = 12, led3 = 8, led4 = 7,  pr = A0;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(pr, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int threshold = 500;
  
  int read = analogRead(pr);
  
  Serial.println(read);
  
  if(read >= threshold) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  if (read >= threshold - 50 && read < threshold){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
   if (read >= threshold - 100 && read < threshold - 50){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
   }
  if (read >= threshold - 150 && read < threshold - 100){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
}
   if (read < threshold - 150){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
}
}
