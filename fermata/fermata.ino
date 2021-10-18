int rele = 5;
int valore;
int buzzer=4;
int LEDgiallo=3;
int LEDverde=2;
int LEDrosso=6;

void setup() {
        // put your setup code here, to run once:
        pinMode(rele, OUTPUT);
        pinMode(A0, INPUT);
        Serial.begin(9600);
        pinMode(buzzer, OUTPUT);
        pinMode(LEDgiallo, OUTPUT);
        pinMode(LEDverde, OUTPUT);
        pinMode(LEDrosso, OUTPUT);
}

void loop() {
        // put your main code here, to run repeatedly:
        valore=analogRead(A0);
        if(valore < 500) {
                digitalWrite(LEDrosso, HIGH);
                delay(3000);
                digitalWrite(buzzer, HIGH);
                digitalWrite(LEDgiallo, HIGH);
                delay(500);
                digitalWrite(buzzer, LOW);
                delay(500);
                digitalWrite(buzzer, HIGH);
                delay(500);
                digitalWrite(buzzer, LOW);
                delay(500);
                digitalWrite(buzzer, HIGH);
                delay(1000);
                digitalWrite(buzzer, LOW);
                digitalWrite(LEDverde, HIGH);
                delay(500);
                digitalWrite(rele, HIGH);
                delay(4000);
                digitalWrite(rele, LOW);
                digitalWrite(LEDgiallo, LOW);
                digitalWrite(LEDrosso, LOW);
                digitalWrite(LEDverde, LOW);
        }
}
