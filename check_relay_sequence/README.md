# Programma che controlla le entrate di un Arduino UNO ed esegue delle azioni programmate.

## Elenco delle operazioni:

-   Manca tensione per 10 secondi al PIN 3.
-   Impostazione stato HIGH al PIN 4 il quale eccita il relè 1.
-   Impulso di 500 ms in uscita dal PIN 5 il quale eccita il relè 2 e il relè 3.
-   Impostazione stato HIGH al PIN 6 il quale eccita il relè 4.
-   Appena viene fornita alimentazione al PIN 7 viene impostato lo stato LOW al PIN 6.
-   Impulso di 500 ms in uscita dal PIN 8 il quale eccita il relè 5.
-   Impostazione stato HIGH al PIN 9 il quale eccita il relè 6.
-   Attesa di 1 secondo.
-   Impostazione stato HIGH al PIN 10 che eccita il relè 7.
-   Controllo presenza alimentazione per 10 secondi al PIN 3.
-   Impostazione stato LOW ai PIN 10 e 4.
-   Attesa di 1 secondo.
-   Impostazione stato LOW al PIN 9.
