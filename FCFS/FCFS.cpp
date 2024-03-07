#include <iostream>
#include <fstream>
using namespace std;

const int wiersze = 3;
const int kolumny = 15;
int proces[wiersze][kolumny]; // Tablica danych testowych procesow
int czasOczekiwania[kolumny];
int czasZakonczenia[kolumny];

int main() {
    ifstream plik("dane.txt"); // Otwiera plik do odczytu
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) plik >> proces[i][j];   // Wczytuje kolejną liczbę z pliku do tablicy
    }
    plik.close();   // Zamyka plik
    
    int taktCzasu = 0;
    for (int i = 0; i < kolumny; i++) {
        taktCzasu += proces[1][i]; // Modyfikacja taktuCzasu o czas wykonania procesu
        czasZakonczenia[i] = taktCzasu; // Zapisanie czasu zakonczenia procesu
        czasOczekiwania[i] = czasZakonczenia[i] - proces[0][i] - proces[1][i]; // Zapisanie czasu oczekiwania procesu
    }
    double sredniCzasOczekiwania = 0;
    for (int i = 0; i < kolumny; i++) sredniCzasOczekiwania += czasOczekiwania[i];
    
    for (int i = 0; i < kolumny; i++) cout << "Proces " << i+1 << ": czas oczekiwania = " << czasOczekiwania[i] << ", czas zakończenia = " << czasZakonczenia[i] << endl;
    sredniCzasOczekiwania /= kolumny;
    cout << "Sredni czas oczekiwania dla algorytmu FCFS: " << sredniCzasOczekiwania << endl; // Wyswietlenie sredniego czasu oczekiwania procesu
    ofstream plikk; // Przesyla raport programu do pliku
    plikk.open("wynikFCFS.txt");
    plikk << "Sredni czas oczekiwania dla metody FCFS: " << sredniCzasOczekiwania << endl;
    plikk.close();
    return 0;
}