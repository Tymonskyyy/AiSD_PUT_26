#include <iostream>  // Biblioteka do "gadania" z komputerem (wczytywanie i wypisywanie)
#include <string>    // Biblioteka, żeby komputer rozumiał napisy jak "ADD" czy "DEL"

using namespace std; // Żeby nie pisać wszędzie "std::", oszczędzamy czas i palce

int main() {
    // Te dwie linie poniżej to taki "turbodoładowacz" - sprawiają, że wczytywanie danych leci szybciej
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Zmienna na to, ile w ogóle komend nam użytkownik wrzuci (np. 10)
    if (!(cin >> T)) return 0; // Wczytujemy to T. Jeśli się nie uda, kończymy program

    // Tworzymy dynamiczną tablicę (nasz rząd krzeseł) o rozmiarze T
    // "new int[T]" oznacza: "komputerze, zarezerwuj mi dokładnie T miejsc w pamięci"
    int* queueArray = new int[T];

    int head = 0;        // Palec wskazujący na pierwsze zajęte krzesło (osoba do wyjścia)
    int tail = 0;        // Palec wskazujący na miejsce, gdzie usiądzie następna osoba, która przyjdzie
    int currentSize = 0; // Licznik: ile osób aktualnie faktycznie siedzi w kolejce
    int capacity = T;    // Maksymalna liczba krzeseł, jaką mamy w poczekalni

    string command; // Pudełko na nazwę komendy (np. "ADD", "DEL")

    // Pętla, która kręci się tyle razy, ile mamy komend (T maleje aż do zera)
    while (T--) {
        if (!(cin >> command)) break; // Wczytaj komendę. Jeśli dane się skończą - wyjdź z pętli

        if (command ==