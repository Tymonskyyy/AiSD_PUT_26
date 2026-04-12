#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definicja jednego "klocka" (wezla) w naszym drzewie
struct Node {
    long long key;      // Nasza liczba
    Node* left, * right; // Lewe i prawe "ramie" (miejsce na mniejsze i wieksze liczby)
};

// Funkcja pomocnicza: przygotowuje zupelnie nowy klocek i wpisuje w niego liczbe
Node* newNode(long long key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr; // Na razie ten klocek nie trzyma zadnych dzieci
    return node;
}

// GLOWNY MECHANIZM: Budowanie drzewa tak, zeby bylo rowne z obu stron
Node* buildBalancedTree(const vector<long long>& arr, int start, int end) {
    // Jesli rzad sie skonczyl (brak klockow do postawienia), konczymy
    if (start > end) return nullptr;

    // Szukamy liczby, ktora jest dokladnie na SRODKU rzedu
    // Dzieki temu po lewej i po prawej zostanie nam tyle samo liczb
    int mid = start + (end - start) / 2;

    // Robimy ze srodkowej liczby szefa (korzen) tego fragmentu drzewa
    Node* node = newNode(arr[mid]);

    // Teraz to samo robimy z lewa polowa liczb (zostana lewymi dziecmi szefa)
    node->left = buildBalancedTree(arr, start, mid - 1);

    // I to samo z prawa polowa (zostana prawymi dziecmi szefa)
    node->right = buildBalancedTree(arr, mid + 1, end);

    // Zwracamy gotowy, idealnie wywazony fragment drzewa
    return node;
}

bool first = true; // Flaga, dzieki ktorej wiemy, czy wlasnie wypisujemy pierwsza liczbe

// Funkcja do pokazywania drzewa: wypisuje szefa, potem lewa strone, potem prawa
void preOrder(Node* root) {
    if (root == nullptr) return; // Jesli tu nic nie ma, wracamy

    // Jesli to nie jest pierwsza wypisana liczba, dajemy spacje (wymog sędziego)
    if (!first) cout << " ";
    cout << root->key; // Wypisujemy aktualna liczbe
    first = false;     // Skoro juz cos wypisalismy, "first" zmienia sie na false

    preOrder(root->left);  // Idziemy sprawdzic i wypisac wszystko po lewej
    preOrder(root->right); // Idziemy sprawdzic i wypisac wszystko po prawej
}

int main() {
    // Przyspieszacze, zeby program nie mulil przy duzych danych
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0; // Ile liczb bedzie w sumie?

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Wrzucamy wszystkie liczby do jednego wora (tablicy)
    }

    // 1. Sortujemy liczby od najmniejszej do najwiekszej.
    // To jest KLUCZ: tylko z posortowanego rzedu mozemy latwo wybrac srodek.
    sort(arr.begin(), arr.end());

    // 2. Budujemy drzewo metoda "dzielenia na pol" (od srodka)
    Node* root = buildBalancedTree(arr, 0, n - 1);

    // 3. Wypisujemy wynik w kolejnosci PREORDER
    first = true;
    preOrder(root);
    cout << endl; // Na samym koncu dajemy "Enter"

    return 0;
}