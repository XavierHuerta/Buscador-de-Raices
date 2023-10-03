#include "Ecuacion.h"

#include <math.h>

//Aplicamos regla de Ruffini
vector <float> Ecuacion::tercer_G(char const *argv[]){
    pow(2,2);
}

//Aplicamos formula general
vector <float> Ecuacion::segundo_G(char const *argv[]){
    float a = (float) *argv[2];
    float b = (float) *argv[3];
    float c = (float) *argv[4];

    raices.push_back((-b + sqrt((4 * a) + (b*c)) / (2 * a)));
    raices.push_back((-b - sqrt((4 * a) + (b*c)) / (2 * a)));

    return raices;
}
