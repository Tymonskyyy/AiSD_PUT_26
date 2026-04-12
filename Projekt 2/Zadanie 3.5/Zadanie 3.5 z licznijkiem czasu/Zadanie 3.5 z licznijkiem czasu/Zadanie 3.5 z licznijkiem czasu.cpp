#include <iostream>
#include <vector>
#include <string>
#include <chrono>   // Biblioteka do mierzenia czasu
#include <algorithm> // Do przemieszania tablicy (shuffle)
#include <random>    // Do generatora liczb losowych

using namespace std;

// Nasz wagonik z poprzedniego zadania
struct Node {
    int key;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

// Funkcja dodająca na początek (krok 2)
void add(int x) {
    Node* newNode = new Node;
    newNode->key = x;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) head->prev = newNode;
    head = newNode;
}

// Funkcja szukająca (ListSearch) - to jej czas mierzymy
bool listSearch(int x) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->key == x) return true;
        temp = temp->next;
    }
    return false;
}

// Funkcja do czyszczenia listy przed kolejnym pomiarem
void clearList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Parametry eksperymentu - ZMIENIAJ JE DO POMIARÓW!
    int n = 7000; // Rozmiar listy (np. 1000, 2000, 5000, 10000)
    int k = 700;  // Liczba powtórzeń (dobierz tak, żeby czas nie był 0)

    // 1. Generujemy liczby w tablicy (wariant: rosnąco)
    vector<int> tablica;
    for (int i = 0; i < n; i++) {
        tablica.push_back(i);
    }

    // 2. Dodajemy je do listy
    for (int x : tablica) {
        add(x);
    }

    // 3. Losowo przetasuj tablicę (do szukania)
    auto rng = default_random_engine{};
    shuffle(tablica.begin(), tablica.end(), rng);

    // 4. Zacznij mierzyć czas
    auto start = chrono::high_resolution_clock::now();

    // 5. Powtórz k razy znalezienie KAŻDEJ wartości z tablicy
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            listSearch(tablica[j]);
        }
    }

    // Koniec pomiaru
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    // 6. Średni czas znalezienia JEDNEGO elementu
    // Dzielimy przez k (powtórzenia) i przez n (liczba szukanych elementów)
    double sredniCzas = diff.count() / (k * n);

    cout << "Wyniki dla n = " << n << " oraz k = " << k << ":" << endl;
    cout << "Calkowity czas: " << diff.count() << " s" << endl;
    cout << "Sredni czas jednego szukania: " << sredniCzas << " s" << endl;

    clearList(); // Sprzątamy pamięć
    return 0;
}