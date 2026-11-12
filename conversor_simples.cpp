#include <iostream>
#include <string>
using namespace std;

string DIGITOS = "0123456789ABCDEF";

// Recebe um caractere e devolve o valor dele. Ex: 'A' -> 10
int valorDoDigito(char c)
{
    for (int i = 0; i < 16; i++)
    {
        if (DIGITOS[i] == c)
        {
            return i;
        }
    }
    return -1;
}

// Converte um numero de qualquer base para decimal
int paraDecimal(string numero, int base)
{
    int resultado = 0;

    for (int i = 0; i < numero.size(); i++)
    {
        int valor = valorDoDigito(numero[i]);
        resultado = resultado * base + valor;
    }

    return resultado;
}

// Converte um numero decimal para qualquer base
string deDecimal(int numero, int base)
{
    if (numero == 0)
    {
        return "0";
    }

    string resultado = "";

    while (numero > 0)
    {
        int resto = numero % base;
        resultado = DIGITOS[resto] + resultado; // insere o novo digito na frente
        numero = numero / base;
    }

    return resultado;
}

int main()
{
    int baseOrigem, baseDestino;
    string numero;

    cout << "Bases disponiveis: 2, 8, 10, 12, 16\n";
    cout << "Base de origem: ";
    cin >> baseOrigem;
    cout << "Base de destino: ";
    cin >> baseDestino;
    cout << "Numero (inserir letras em maiusculo): ";
    cin >> numero;

    int emDecimal = paraDecimal(numero, baseOrigem);
    string resultado = deDecimal(emDecimal, baseDestino);

    cout << "Resultado: " << resultado << "\n";

    return 0;
}