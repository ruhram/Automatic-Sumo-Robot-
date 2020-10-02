  int motor1, motor2;
  int i;
  int m1in1 = 4;
  int m1in2 = 3;
  int m1pwm = 5;
  int m2in1 = 8;
  int m2in2 = 9;
  int m2pwm = 10;
  int sensor1 = A1;
  int sensor2 = A0;
  int sensor3 = A4;
  int sensor4 = A2;
  int sensor5 = A6;
  int proxy1;
  int proxy2;
  int proxy3;
  int garis1;
  int garis2;
  int jarak;
  const int proxyon = 300;
  const int proxyoff = 200;
  
void setup() {
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(m1in1, OUTPUT);
  pinMode(m1in2, OUTPUT);
  pinMode(m1pwm, OUTPUT);
  pinMode(m2in1, OUTPUT);
  pinMode(m2in2, OUTPUT);
  pinMode(m2pwm, OUTPUT);
  
}

void loop() {
  proxy1 = analogRead(sensor1);
  proxy2 = analogRead(sensor2);
  proxy3 = analogRead(sensor5);
  garis2 = analogRead(sensor4);
  garis1 = analogRead(sensor3);
  jarak = map(proxy3, 200, 630, 80,10);
  Serial.println(garis1);
  
  //motor1
  digitalWrite(m1in1, HIGH);
  digitalWrite(m1in2, LOW);
  analogWrite(m1pwm, 50);
  //motor2
  digitalWrite(m2in1, HIGH);
  digitalWrite(m2in2, LOW);
  analogWrite(m2pwm, 50);
   if(proxy1<=proxyon){
    //motor1
    digitalWrite(m1in1, HIGH);
    digitalWrite(m1in2, LOW);
    analogWrite(m1pwm, 100);
    //motor2
    digitalWrite(m2in1, LOW);
    digitalWrite(m2in2, HIGH);
    analogWrite(m2pwm, 100);
    
    }

    if(jarak<=82){
    //motor1
    digitalWrite(m1in1, HIGH);
    digitalWrite(m1in2, LOW);
    analogWrite(m1pwm, 100);
    //motor2
    digitalWrite(m2in1, HIGH);
    digitalWrite(m2in2, LOW);
    analogWrite(m2pwm, 100);
    delay(100);  
    }
    
    if(proxy2<=proxyon){
    //motor1
    digitalWrite(m1in1, LOW);
    digitalWrite(m1in2, HIGH);
    analogWrite(m1pwm, 100);
    //motor2
    digitalWrite(m2in1, HIGH);
    digitalWrite(m2in2, LOW);
    analogWrite(m2pwm, 100);  
    }

    if(proxy2<=proxyon && jarak<=82){
    //motor1
    digitalWrite(m1in1, HIGH);
    digitalWrite(m1in2, LOW);
    analogWrite(m1pwm, 255);
    //motor2
    digitalWrite(m2in1, HIGH);
    digitalWrite(m2in2, LOW);
    analogWrite(m2pwm, 255);
    delay(100);  
    }

    if(proxy2<=proxyon && jarak<=82 && proxy1<=proxyon){
    //motor1
    digitalWrite(m1in1, HIGH);
    digitalWrite(m1in2, LOW);
    analogWrite(m1pwm, 255);
    //motor2
    digitalWrite(m2in1, HIGH);
    digitalWrite(m2in2, LOW);
    analogWrite(m2pwm, 255);
    delay(100);  
    }
}
