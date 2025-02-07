//  Vorlesung:  6.3.2020
#include <iostream>
#include <cassert>                                      // assert()
using namespace std;

// Funktion mit  e i n e m   Rueckgabewert
/** Umrechnung von Grad Celsius in Kelvin.
*  @param[in]  grad_C Temperatur in Grad Celsius
*  @return Temperatur in Kelvin
*  @warning Keine Absicherung bzgl. unsinniger Temperaturen (<0 Kelvin)
*/
float c2k(const float grad_C)             // Deklaration + Definition der Funktion
{
    float grad_K;
    grad_K = grad_C + 273.15F;                   // N i c h t!   273,15
    return grad_K;
}

// Funktion mit  m e h r e r e n   Rueckgabewerten
/** Umrechnung von Grad Celsius in Kelvin und Grad Fahrenheit.
*  @param[in]  grad_C Temperatur in Grad Celsius
*  @param[out] grad_K Temperatur in Kelvin
*  @param[out] grad_F Temperatur in Grad Fahrenheit
*/
void c2kf(const float grad_C, float &grad_K, float &grad_F)  // Deklaration + Definition der Funktion
{
    assert( grad_C >= -273.15F);                 // Abbruch bei unsinnigen Werten
    grad_K = c2k(grad_C);
    grad_F = 9 / 5.0F * grad_C + 32;             // N i c h t!   9/5
    return;
}



int main()
{
    float varC, varF;               // Deklaration der Varialen (keine! Initialisierung)
    cout << "Hello world!" << endl;
    cout << " Grad Celsius = ";

    cin  >> varC;                         // Eingabe einer Variablen von Tastatur
    float varK = c2k(varC);          //  Aufruf der Funktion celsius2kelvin

    cout << " Kelvin : " << varK  << endl;
    cout << "####################\n";

    c2kf(varC, varK, varF);               //  Aufruf der Funktion c2kf

    cout << " Kelvin    : " << varK  << endl;
    cout << " Fahrenheit: " << varF  << endl;

    return 0;
}
