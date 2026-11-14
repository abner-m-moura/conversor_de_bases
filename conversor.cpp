
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Todos os símbolos possíveis, na ordem do seu valor.
const string DIGITOS = "0123456789ABCDEF";

// Descobre o valor de um símbolo. Ex: 'A' -> 10, '7' -> 7; Devolve -1 se o símbolo não existir.
int valorDoDigito(char c)
{
    c = toupper(c);
    for (int i = 0; i < (int)DIGITOS.size(); i++)
    {
        if (DIGITOS[i] == c)
            return i;
    }
    return -1;
}

// Converte um número escrito em qualquer base para decimal; "valido" vira false se digitar algo que não existe na base
long long paraDecimal(const string &numero, int base, bool &valido)
{
    long long resultado = 0;
    valido = true;

    for (char c : numero)
    {
        int valor = valorDoDigito(c);

        // O símbolo precisa existir e ser menor que a base
        if (valor == -1 || valor >= base)
        {
            valido = false;
            return 0;
        }
        resultado = resultado * base + valor;
    }
    return resultado;
}

// Converte um número decimal para qualquer base.
string deDecimal(long long numero, int base)
{
    if (numero == 0)
        return "0";

    string resultado = "";
    while (numero > 0)
    {
        int resto = numero % base;   // o resto é o próximo dígito
        resultado += DIGITOS[resto]; // guarda o símbolo do resto
        numero = numero / base;      // divide para continuar
    }

    // Os restos saem na ordem inversa, então inverte o texto no final
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

// Mostra o menu e devolve o valor da base escolhida
int escolherBase(const string &pergunta)
{
    int opcao;
    cout << "\n"
         << pergunta << "\n";
    cout << "1 - Decimal (10)\n";
    cout << "2 - Binario (2)\n";
    cout << "3 - Octal (8)\n";
    cout << "4 - Duodecimal (12)\n";
    cout << "5 - Hexadecimal (16)\n";
    cout << "Opcao: ";
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        return 10;
    case 2:
        return 2;
    case 3:
        return 8;
    case 4:
        return 12;
    case 5:
        return 16;
    default:
        return -1;
    }
}

int main()
{
    cout << "=== CONVERSOR DE BASES ===\n";

    int baseOrigem = escolherBase("Em qual base esta o seu numero?");
    if (baseOrigem == -1)
    {
        cout << "Opcao invalida!\n";
        return 1;
    }

    int baseDestino = escolherBase("Para qual base quer converter?");
    if (baseDestino == -1)
    {
        cout << "Opcao invalida!\n";
        return 1;
    }

    string numero;
    cout << "\nDigite o numero (A e B para duodecimal, A-F para hexadecimal): ";
    cin >> numero;

    bool valido;
    long long emDecimal = paraDecimal(numero, baseOrigem, valido);

    if (!valido)
    {
        cout << "Numero invalido para a base escolhida!\n";
        return 1;
    }

    string resultado = deDecimal(emDecimal, baseDestino);

    cout << "\nResultado: " << resultado << " (base " << baseDestino << ")\n";
    return 0;
}