# Programma che controlla le entrate di un Arduino UNO ed esegue delle azioni programmate.

## Elenco delle operazioni:

-   Manca tensione per 10 secondi al PIN 1.
-   Impostazione stato HIGH al PIN 2 il quale eccita il relè 1.
-   Impulso di 500 ms in uscita dal PIN 3 il quale eccita il relè 2 e il relè 3.
-   Impostazione stato HIGH al PIN 4 il quale eccita il relè 4.
-   Appena viene fornita alimentazione al PIN 5 viene impostato lo stato LOW al PIN 4.
-   Impulso di 500 ms in uscita dal PIN 6 il quale eccita il relè 5.
-   Impostazione stato HIGH al PIN 7 il quale eccita il relè 6.
-   Attesa di 1 secondo.
-   Controllo alimentazione per 10 secondi al PIN 1.
-   Impostazione stato LOW ai PIN 8 e 2.
-   Attesa di 1 secondo.
-   Impostazione stato LOW al PIN 7.
