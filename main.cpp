#include <iostream>
#include <list>
#include <cmath>

using namespace std;

// Implementacja tablicy z haszowaniem
class HashTable {
private:
    static const int TABLE_SIZE = 10;

    // Definicja wewnętrznego elementu przechowywanego w tablicy
    struct HashNode {
        double key;
        string value;
    };

    // Lista do obsługi kolizji
    list<HashNode> table[TABLE_SIZE];

    // Funkcje haszujące

    int hash1(double key) {
        return floor(key * TABLE_SIZE);
    }

    int hash2(int key) {
        return key % TABLE_SIZE;
    }

    int hash3(int key) {
        double A = (sqrt(5) - 1) / 2;
        return floor(TABLE_SIZE * fmod(key * A , 1));
    }

public:
    // Metoda dodająca element do tablicy
    void insert_floor(double key, string value) {
        int index = hash1(key);
        HashNode newNode;
        newNode.key = key;
        newNode.value = value;
        table[index].push_back(newNode);
    }

    void insert_modulo(int key, string value) {
        int index = hash2(key);
        HashNode newNode;
        newNode.key = key;
        newNode.value = value;
        table[index].push_back(newNode);
    }

    void insert_modulo_A(int key, string value) {
        int index = hash3(key);
        HashNode newNode;
        newNode.key = key;
        newNode.value = value;
        table[index].push_back(newNode);
    }

    void insert_linear(int key, string value) {
        int index = hash2(key);
        int i = 0;
        while (!table[index].empty()) {
            index = (index + i) % TABLE_SIZE;
            i++;
        }
        HashNode newNode;
        newNode.key = key;
        newNode.value = value;
        table[index].push_back(newNode);
    }


    void insert_quadratic(double key, string value) {
        int index = hash3(key);
        int i = 0;
        int c1 = 1; // pierwsza stała adresowania kwadratowego
        int c2 = 3; // druga stała adresowania kwadratowego
        while (!table[index].empty()) {
            index = (hash1(key) + c1 * i + c2 * i * i) % TABLE_SIZE;
            i++;
        }
        HashNode newNode;
        newNode.key = key;
        newNode.value = value;
        table[index].push_back(newNode);
    }

    void insert_double_hashing(double key, string value) {
        int index = hash2(key);
        int i = 0;
        while (!table[index].empty()) {
            index = (hash2(key) + i * hash3(key)) % TABLE_SIZE;
            i++;
        }
        HashNode newNode;
        newNode.key = key;
        newNode.value = value;
        table[index].push_back(newNode);
    }


    // Metoda wyświetlająca zawartość tablicy
    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "]: ";
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                cout << "(" << it->key << ", " << it->value << ") ";
            }
            cout << endl;
        }
    }
};

int main() {

    cout << "Tablica hashujaca z funckja hashowania floor:" << endl;
    HashTable ht_floor;

    // Dodawanie elementów do tablicy
    ht_floor.insert_floor(0.5, "Apple");
    ht_floor.insert_floor(0.23, "Banana");
    ht_floor.insert_floor(0.95, "Orange");

    // Wyświetlanie zawartości tablicy
    ht_floor.display();
////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Tablica hashujaca z funckja hashowania modulo:" << endl;
    HashTable ht_modulo;

    // Dodawanie elementów do tablicy
    ht_modulo.insert_modulo(5, "Apple");
    ht_modulo.insert_modulo(23, "Banana");
    ht_modulo.insert_modulo(17, "Orange");

    // Wyświetlanie zawartości tablicy
    ht_modulo.display();
////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Tablica hashujaca z funckja hashowania modulo_A:" << endl;
    HashTable ht_modulo_A;

    // Dodawanie elementów do tablicy
    ht_modulo_A.insert_modulo_A(5, "Apple");
    ht_modulo_A.insert_modulo_A(23, "Banana");
    ht_modulo_A.insert_modulo_A(15, "Orange");

    // Wyświetlanie zawartości tablicy
    ht_modulo_A.display();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Tablica hashujaca z funckja hashowania modulo_A i liniowym rozwiazywaniem kolizji :" << endl;
    HashTable ht_linear;

    // Dodawanie elementów do tablicy
    ht_linear.insert_linear(5, "Apple");
    ht_linear.insert_linear(23, "Banana");
    ht_linear.insert_linear(15, "Orange");

    // Wyświetlanie zawartości tablicy
    ht_linear.display();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Tablica hashujaca z funckja hashowania modulo_A i adresowaniem kwadratowym jako funkcją rozwiazywania kolizji :" << endl;
    HashTable ht_quadratic;

    // Dodawanie elementów do tablicy
    ht_quadratic.insert_quadratic(5, "Apple");
    ht_quadratic.insert_quadratic(23, "Banana");
    ht_quadratic.insert_quadratic(15, "Orange");

    // Wyświetlanie zawartości tablicy
    ht_quadratic.display();
///////////////////////////////////////////////////////////////////////////////////////
    cout << "Tablica hashujaca z funckja hashowania modulo_floor i funkcją pomocniczą modulo_A oraz hashowaniem podwujnym jako funkcją rozwiazywania kolizji :" << endl;
    HashTable ht_double_hashing;

    // Dodawanie elementów do tablicy
    ht_double_hashing.insert_double_hashing(5, "Apple");
    ht_double_hashing.insert_double_hashing(23, "Banana");
    ht_double_hashing.insert_double_hashing(15, "Orange");

    // Wyświetlanie zawartości tablicy
    ht_double_hashing.display();
    return 0;
}