#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Digite um numero se quer saber se e par ou impar: ";
    cin >> numero;

    if (numero % 2 == 0)
    {
        cout << "o numero e par";
    }
    else{
        cout << "numero e impar";
    }           
}