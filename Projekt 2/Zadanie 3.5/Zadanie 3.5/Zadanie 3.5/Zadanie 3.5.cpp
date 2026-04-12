#include <iostream>  // Biblioteka do wczytywania i wypisywania danych (cin, cout)
#include <string>    // Biblioteka do obsługi wyrazów (nasze komendy ADD, DEL itd.)

using namespace std; // Żeby nie pisać std:: przed każdym cout i cin

// 1. Definiujemy "wagonik" naszego pociągu (struktura ogniwa listy)
struct Node {
    int key;         // Tu przechowujemy naszą liczbę (ładunek wagonika)
    Node* next;      // Strzałka (wskaźnik) na następny wagonik w pociągu
    Node* prev;      // Strzałka (wskaźnik) na poprzedni wagonik w pociągu
};

// 2. Globalne zmienne sterujące listą (dostępne dla każdej funkcji)
Node* head = nullptr; // Nasza "lokomotywa" (początek listy). nullptr znaczy, że lista jest pusta.
int listSize = 0;     // Licznik elementów, żebyśmy zawsze wiedzieli, ile ich jest (operacja SIZE)

// FUNKCJA: Dodawanie elementu na sam początek (ADD)
void add(int x) {
    Node* newNode = new Node;  // Tworzymy fizycznie nowy wagonik w pamięci RAM
    newNode->key = x;          // Wkładamy liczbę 'x' do środka wagonika
    newNode->next = head;      // Nowy wagonik podpinamy pod dotychczasowy początek
    newNode->prev = nullptr;   // Przed nowym wagonikiem nie ma nic (bo staje się pierwszy)

    if (head != nullptr) {     // Jeśli pociąg nie był pusty...
        head->prev = newNode;  // ...to stary pierwszy wagonik musi "złapać za hak" nowy wagonik
    }
    head = newNode;            // Oficjalnie ogłaszamy, że nowy wagonik to teraz początek (head)
    listSize++;                // Skoro dodaliśmy element, zwiększamy licznik o 1
}

// FUNKCJA: Usuwanie pierwszego napotkanego elementu o wartości x (DEL)
void del(int x) {
    Node* temp = head;         // Zaczynamy szukanie od samego początku (od lokomotywy)