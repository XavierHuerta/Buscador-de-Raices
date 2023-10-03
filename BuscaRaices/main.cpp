#include <iostream>

#include <Ecuacion.h>

using namespace std;

int main(int argc, char const *argv[])
{
    //si no ingreso los argumentos enla ejecucion
    if(argc == 0 || argc < 4){
        perror("No igreso correctamente los argumentos");
    }
    else{
        if(*argv[1] != 0){//ecuacion de 3er grado
            
        }else if(*argv[2] != 0){//ecuacion de 2do grado
            mostrarRaices(Ecuacion::segundo_G(argv));
        }else{//ecuacion de tercer grado

        }
    }

    return 0;
}

void mostrarRaices(vector <float> raices){
    cout << "Las raices son: " << endl;
    cout << "{";
    for (int i = 0; i < raices.size(); i++)
    {
        cout << raices.at(i) << ", ";
    }
    cout << "}" << endl;
    
}
