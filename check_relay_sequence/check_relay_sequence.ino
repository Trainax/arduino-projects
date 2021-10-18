int pin3Status, pin7Status, var = 0, durataImpulso = 500, millisInizio;

//La connessione dei pin parte dal pin 3

void setup() {
        pinMode(3, INPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);
        pinMode(6, OUTPUT);
        pinMode(7, INPUT);
        pinMode(8, OUTPUT);
        pinMode(9, OUTPUT);
        pinMode(10, OUTPUT);

        //Si consiglia il collegamento di un resistore da 10000 ohm tra ognuno dei pin usati per l'input e GND per evitare letture non accurate

        //Tutte le uscite vengono impostate a livello basso per precauzione

        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
}

void loop() {
        pin3Status = digitalRead(3); //Guardo se c'è tensione a 5V al pin 3
        if(pin3Status == LOW) { //Se non c'è tensione entro nella sequenza
                millisInizio = millis();
                while(millis() < (millisInizio + 10000)) { //Controllo presenza tensione per 10 secondi, se la tensione ritorna (anche se per poco) durante questo controllo tutta la sequenza inizia da capo
                        pin3Status = digitalRead(3);
                        if(pin3Status == HIGH)
                                break;
                        delay(100);
                }
                if(pin3Status == LOW) { //Se non c'è tensione entro qui, altimenti esco e ricomincio il controllo
                        digitalWrite(4, HIGH); //Uscita alimentazione dal pin 4
                        digitalWrite(5, HIGH); //Impulso in uscita dal pin 5
                        delay(durataImpulso);
                        digitalWrite(5, LOW);
                        digitalWrite(6, HIGH); //Uscita alimentazione dal pin 6
                        pin7Status = digitalRead(7); //Lettura presenza tensione al pin 7
                        while(pin7Status == LOW) { //Se non è presente aspetta finché non arriva, quando arriva esci e continua con l'esecuzione delle altre istruzioni
                                delay(100); //Aspetto un decimo di secondo
                                pin7Status = digitalRead(7); //Ripeti il controllo di presenza della tensione al pin 7
                        }
                        //Qui si arriva se era presente tensione al pin 5 al momento del controllo
                        digitalWrite(6, LOW); //Interruzione alimentazione al pin 6
                        digitalWrite(8, HIGH); //Impulso in uscita dal pin 8
                        delay(durataImpulso);
                        digitalWrite(8, LOW);
                        digitalWrite(9, HIGH); //Uscita alimentazione dal pin 9
                        delay(1000); //Attesa di 1 secondo
                        digitalWrite(10, HIGH); //Uscita alimentazione dal pin 10
                        while(var == 0) {
                                millisInizio = millis();
                                while(millis() < (millisInizio + 10000)) { //Controllo presenza tensione per 10 secondi, se la tensione viene a mancare (anche se per poco) durante questo controllo il conteggio dei 10 secondi ricomincia da capo
                                        pin3Status = digitalRead(3);
                                        if(pin3Status == LOW)
                                                break;
                                        delay(100);
                                }
                                if(pin3Status == HIGH)
                                        var = 1;
                        }
                        digitalWrite(10, LOW); //Termine alimentazione dal pin 10
                        digitalWrite(4, LOW); //Termine alimentazione dal pin 4
                        delay(1000); //Attesa di 1 secondo
                        digitalWrite(9, LOW); //Termine alimentazione dal pin 9
                }
        }
        delay(1000); //Aspetto 1 secondo prima di ripetere il controllo ed eventualmente ricominciare tutta la sequenza
}
