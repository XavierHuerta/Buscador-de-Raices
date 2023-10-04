#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

//vector usado para almacenar las raices solucion
vector <float> raices;

//Genera un vector con los divisores exactos de d
vector <float> GenDivsD(float d){
    vector <float> divsD;

    for (int i = 1; i < d; i++)
    {
        if(((int) d  % i) == 0){
            divsD.push_back((float)i);
            divsD.push_back((float)-i);
        }
    }
    
    return divsD;
}

//Genera un vector con los divisores exactos de a
vector <float> GenDivsA(float a){
    vector <float> divsA;
    for (int i = 1; i < a; i++)
    {
        if(((int) a  % i) == 0){
            divsA.push_back((float)i);
            divsA.push_back((float)-i);
        }
    }
    
    return divsA;
}

//Genera un vector son las posibles raices solucion
vector <float> GenPosRootSolves(float a, float d){
    vector <float> posRootSolvesV;
    vector <float> dA = GenDivsA(a);
    vector <float> dD = GenDivsD(d);

    for (int vD = 0; vD < dD.size(); vD++)
    {
        for (int vA = 0; vA < dA.size(); vA++)
        {
            posRootSolvesV.push_back(dD.at(vD) / dA.at(vA));
            posRootSolvesV.push_back( -(dD.at(vD) / dA.at(vA)));
        }
    }
    
    return posRootSolvesV;
}
//ejecuta una division sintetica hasta encontrar las RootSolves
float divSintetic(float a, float b, float c, float d){
    float aux1, aux2, aux3;
    vector <float> posRootSolve = GenPosRootSolves(a, d);
    float sumas [4];

    cout << posRootSolve.size();

    for (int i = 0; i < posRootSolve.size(); i++)
    {
        cout << " - " << posRootSolve.at(i);
    }

    // for (int i = 0; i < posRootSolve.size(); i++)
    // {
        
    // }
    
    return 1;
}


//Aplicamos regla de Ruffini
vector <float> tercer_G(char const *argv[]){
    float a = stof(argv[1]);
    float b = stof(argv[2]);
    float c = stof(argv[3]);
    float d = stof(argv[4]);

    int x = divSintetic(a, b, c, d);

    return raices;
}




//Aplicamos formula general
vector <float> segundo_G(char const *argv[]){
    float a = stof(argv[2]);
    float b = stof(argv[3]);
    float c = stof(argv[4]);

    float discriminante = (float) (pow(b,2) - (4 * a * c));

    if(discriminante >= 0){
        raices.push_back( ( -b + sqrt(discriminante) ) / (2 * a));
        raices.push_back( ( -b - sqrt(discriminante) ) / (2 * a));
    }

    return raices;
}

vector <float> primer_G(char const *argv[]){
    

    return raices;
}

void mostrarRaices(vector <float> raices){
    if(!raices.empty()){
        cout << "Las raices son: " << endl;
        cout << "{";
        for (int i = 0; i < raices.size(); i++)
        {
            cout << raices.at(i) << ", ";
        }
        cout << "}" << endl;
    }
    else{
        cout << "{}";
    }
}

//Metodo Main
int main(int argc, char const *argv[])
{
    //si no ingreso los argumentos en la ejecucion
    if(argc == 0 || argc < 4){
        perror("No igreso correctamente los argumentos");
    }
    else{
        if(*argv[1] > 0){//ecuacion de 3er grado
            cout << "Tenemos una Ecuacion de 3er grado" << endl;
            tercer_G(argv);
        }else 
        if(*argv[2] != 0){//ecuacion de 2do grado

            cout << "Tenemos una Ecuacion de 2do grado" << endl;
            mostrarRaices(segundo_G(argv));

        }else{//ecuacion de primer grado
            cout << "Tenemos una Ecuacion de 1er grado" << endl;
        }
    }

    return 0;
}