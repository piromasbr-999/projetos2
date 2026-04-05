#include <iostream>
using namespace std;

int main() {
    int numero;
    int numero2;

    cout << "Fale o primeiro numero: ";
    cin >> numero;

    cout << "Fale o segundo numero: ";
    cin >> numero2;

    if (numero > numero2) {
        cout << "O maior numero e " << numero << "\n";
    }
    else if (numero2 > numero) {
        cout << "O maior numero e " << numero2 << "\n";
    }
    else {
        cout << "Os numeros sao iguais\n";
    }

    return 0;
}