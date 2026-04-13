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

        if (command == "ADD") { // Jeśli komenda to "ADD"
            int x; // Pudełko na liczbę, którą chcemy dodać
            cin >> x; // Wczytaj tę liczbę

            // Sprawdzamy, czy mamy jeszcze wolne krzesła
            if (currentSize < capacity) {
                queueArray[tail] = x; // Sadzamy gościa na krześle, na które pokazuje ogon (tail)

                // Kluczowy moment: przesuwamy ogon o 1. 
                // "% capacity" to bezpiecznik: jeśli ogon dojdzie do końca rzędu, wraca na krzesło nr 0
                tail = (tail + 1) % capacity;
                currentSize++; // Mamy o jedną osobę więcej w kolejce
            }
        }
        else if (command == "DEL") { // Jeśli komenda to "DEL"
            if (currentSize == 0) { // Jeśli poczekalnia jest pusta
                cout << endl; // Wypisz tylko "Enter" (pustą linię) - tak chciał sędzia
            }
            else {
                // Wypisz liczbę z krzesła, na które pokazuje głowa (head)
                cout << queueArray[head] << endl;

                // Przesuwamy głowę o 1 krzesło dalej. 
                // "% capacity" sprawia, że jeśli głowa wyjdzie poza tablicę, wraca na początek
                head = (head + 1) % capacity;
                currentSize--; // Mamy o jedną osobę mniej w kolejce
            }
        }
        else if (command == "ISEMPTY") { // Jeśli komenda to "ISEMPTY"
            // Jeśli licznik osób wynosi 0, to wypisz TAK, w innym razie NIE
            if (currentSize == 0) cout << "TAK" << endl;
            else cout << "NIE" << endl;
        }
    }

    delete[] queueArray; // Bardzo ważne: oddajemy komputerowi zarezerwowane krzesła (RAM), żeby nie było wycieku
    return 0; // Kończymy program z sukcesem
}