#include <iostream>

#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

#include "Ecuacion.h"

using namespace std;

//Metodo Main
int main(int argc, char const *argv[])
{
    //si no ingreso los argumentos en la ejecucion
    if(argc < 5){
        perror("No igreso correctamente los argumentos");
    }
    else{
        if(stof(argv[1]) != 0){//ecuacion de 3er grado
            cout << "Tenemos una Ecuacion de 3er grado" << endl;
            Ecuacion e(stof(argv[1]), stof(argv[2]), stof(argv[3]), stof(argv[4]));
            e.showRoots();
        }
        else if(stof(argv[2]) != 0){//ecuacion de 2do grado

            cout << "Tenemos una Ecuacion de 2do grado" << endl;
            Ecuacion e(stof(argv[2]), stof(argv[3]), stof(argv[4]));
            e.showRoots();

        }else if (stof(argv[3]) != 0){//ecuacion de primer grado
            cout << "Tenemos una Ecuacion de 1er grado" << endl;
            Ecuacion e(stof(argv[3]), stof(argv[4]));
            e.showRoots();
        }
        else{
            perror("no se introdujo nonguna ecuacion");
        }
    }

    return 0;
}