#include <iostream>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,100);

    int numero_secreto = dist(gen);
    int resposta;
    int tentativas = 0;

    cout << "Adivinhe o numero: ";
    cin >> resposta;

    while (resposta != numero_secreto) {

        if (resposta < numero_secreto) {
            cout << "Muito baixo! Tente novamente: ";
            tentativas = tentativas + 1;
        }
        else {
            cout << "Muito alto! Tente novamente: ";
            tentativas = tentativas + 1;
        }

        cin >> resposta;
    }

    cout << "ACERTOU! A resposta era " << numero_secreto << " e voce conseguiu acerta em " << tentativas << " TENTATIVAS" "\n";

    return 0;
}