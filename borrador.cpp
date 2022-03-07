#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <map>
#include <cstdlib>
using namespace std;

// Declarar arreglo bidimensional
const int fila = 9;
const int columna = 10;

int a = 0;
int b = 0;

int asientos[fila][columna];
int numeros[10] =
    {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char letras[10] =
    {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

void imprimir_asiento();
void comprar_asiento();

int main()
{

    system("cls");
    cout << "Bienvenido al programa de compra de asientos de una sala de cine" << endl;
    while (true)
    {
        cout << "Ingrese que desea hacer: " << endl;
        cout << "1. Imprimir asientos" << endl;
        cout << "2. Comprar asiento" << endl;
        cout << "3. Salir" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            imprimir_asiento();
            break;
        case 2:
            comprar_asiento();
            break;
        case 3:
            exit(0);
            break;
        }
    }
}

// imprime el arreglo
void imprimir_asiento()
{
    for (int i = 0; i < fila; i++)
    {
        // Imprimir letras
        cout << " " << letras[i] << " |";
        for (int j = 0; j < columna; j++)
        {
            cout << setw(3) << asientos[i][j];
        }
        cout << endl;
    }
    // Imprime el arreglo de numeros
    cout << "-----------------------------------" << endl;
    cout << "    ";
    for (int i = 0; i < 10; i++)
    {
        cout << setw(3) << numeros[i];
    }
    cout << endl;
}

// recibe la fila y la columna del asiento que se desea comprar y pasa el valor a 1
void comprar_asiento()
{
    cout << "Por favor ingrese la cantidad de asientos que desea comprar" << endl;
    int cantidad;
    cin >> cantidad;
    imprimir_asiento();

    for (int i = 0; i < cantidad; i++)
    {
        cout << "Por favor ingrese la fila del asiento que desea comprar" << endl;
        cin >> a;
        cout << "Por favor ingrese la columna del asiento que desea comprar" << endl;
        cin >> b;

        if (a > 0 && a < 10 && b > 0 && b < 11)
        {
            if (asientos[a - 1][b - 1] == 0)
            {
                asientos[a - 1][b - 1] = 1;
                cout << "Asiento comprado" << endl;
            }
            else
            {
                cout << "Asiento ocupado. intente con otro" << endl;
                i = i - 1;
            }
        }
        else
        {
            cout << "Asiento no existe, intente con otro" << endl;
            i = i - 1;
        }
    }
}
