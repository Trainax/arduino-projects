int valoreSensore1;
int valoreSensore2;
int LEDInizioMisurazione=7;
int inizio;
int fine;
float differenza;
float velocita;
float velocitaInScala;
String output="";

float fattoreScala=87.00;

float distanzaInCm=15.00;


void setup() {
  // put your setup code here, to run once:
  pinMode(LEDInizioMisurazione, OUTPUT);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  valoreSensore1=analogRead(A0);
  if(valoreSensore1 < 600){
    inizio=millis();
    digitalWrite(LEDInizioMisurazione, HIGH);
    valoreSensore2=analogRead(A1);
    while(valoreSensore2 > 600){
      valoreSensore2=analogRead(A1);
      }
    fine=millis();
    differenza=fine-inizio;
    if(differenza>2){
      differenza=differenza/1000;
      velocita=distanzaInCm/differenza;
      velocita=velocita*0.036;
      output=output+"Il transito tra i due rilevatori è durato "+differenza*1000+" millisecondi. Il treno procedeva a "+velocita+" km/h, equivalenti a "+velocita*fattoreScala+" km/h in scala\n";
      Serial.println(output);
    }
    digitalWrite(LEDInizioMisurazione, LOW);
    
    }

}
