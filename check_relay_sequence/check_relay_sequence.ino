void setup() {
  pinMode(1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

int pin1Status, pin5Status, var = 0, durataImpulso = 500;

void loop() {
  pin1Status = digitalRead(1); //Guardo se c'è tensione a 5V al pin 1
  if(pin1Status == LOW){ //Se non c'è tensione entro nella sequenza
    delay(10000); //Attendo 10 secondi
    pin1Status=digitalRead(1); // Leggo nuovamente se è presente la tensione oppure no, se c'è tensione esco e ripeto il controllo da capo come se non fosse successo niente
    if(pin1Status == LOW){ //Se non c'è tensione entro qui, altimenti esco e ricomincio il controllo
      digitalWrite(2, HIGH); //Uscita alimentazione dal pin 2
      digitalWrite(3, HIGH); //Impulso in uscita dal pin 3
      delay(durataImpulso);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH); //Uscita alimentazione dal pin 4
      pin5Status = digitalRead(5); //Lettura presenza tensione al pin 5
      while(pin5Status == LOW){ //Se non è presente aspetta finché non arriva, quando arriva esci e continua con l'esecuzione delle altre istruzioni
        delay(100); //Aspetto un decimo di secondo
        pin5Status = digitalRead(5); //Ripeti il controllo di presenza della tensione al pin 5
      }
      //Qui si arriva se era presente tensione al pin 5 al momento del controllo
      digitalWrite(4, LOW); //Interruzione alimentazione al pin 4
      digitalWrite(6, HIGH); //Impulso in uscita dal pin 6
      delay(durataImpulso);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH); //Uscita alimentazione dal pin 7
      delay(1000); //Attesa di 1 secondo
      digitalWrite(8, HIGH); //Guardo se c'è tensione a 5V al pin 1
      while(var == 0){
        pin1Status = digitalRead(1); //Guardo se c'è tensione a 5V al pin 1
        if(pin1Status == HIGH){ //Se c'è tensione al pin 1 entro qui
          delay(10000); //Aspetto 10 secondi
          pin1Status = digitalRead(1); //Guardo se c'è tensione a 5V al pin 1 
          if(pin1Status == HIGH){
            var = 1; //Se dopo 10 secondi c'è tensione al pin1 esco da qui e proseguo, altrimenti ripeto il controllo ed aspetto
            }
          }
        }
      digitalWrite(8, LOW); //Termine alimentazione dal pin 8
      digitalWrite(2, LOW); //Termine alimentazione dal pin 2
      delay(1000); //Aspetto 1 secondo
      digitalWrite(7, LOW); //Termine alimentazione dal pin 7
    }
  }
  delay(1000); //Aspetto 1 secondo prima di ripetere il controllo ed eventualmente ricominciare tutta la sequenza
}
