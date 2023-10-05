#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

//vector usado para almacenar las raices solucion
vector <float> raices;

//Genera un vector con los divisores exactos de d
vector <float> GenDivsD(float d){
    vector <float> divsD;

    for (int i = 1; i <= d; i++)
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

    for (int i = 1; i <= a; i++)
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
    vector <float> dA;
    vector <float> dD;

    dA = GenDivsA(a);
    dD = GenDivsD(d);

    for (int vA = 0; vA < dA.size(); vA++)
    {
        for (int vD = 0; vD < dD.size(); vD++)
        {
            float aux = dD.at(vD) / dA.at(vA);
            if(posRootSolvesV.empty()){
                posRootSolvesV.push_back(aux);
                posRootSolvesV.push_back(-aux);
            }
            else{
                auto it = find(posRootSolvesV.begin(), posRootSolvesV.end(), aux);
                if(it == posRootSolvesV.end()){
                    posRootSolvesV.push_back(aux);
                }
                auto it2 = find(posRootSolvesV.begin(), posRootSolvesV.end(), -aux);
                if(it2 == posRootSolvesV.end()){
                    posRootSolvesV.push_back(-aux);
                }
            }
        }
    }
    
    return posRootSolvesV;
}
//ejecuta una division sintetica hasta encontrar las RootSolves
vector <float> divSintetic(float a, float b, float c, float d){
    vector <float> rS;
    float aux1, aux2, x;
    vector <float> posRootSolve = GenPosRootSolves(a, d);


    for (int i = 0; i < posRootSolve.size(); i++)
    {
        x = posRootSolve.at(i);
        
        aux1 = a * x;
        aux2 = b + aux1;
        aux1 = aux2 * x;
        aux2 = c + aux1;
        aux1 = aux2 * x;
        aux2 = aux1 + d;
        if(aux2 == 0){
            rS.push_back(x);
        }
    }
    
    return rS;
}

//Aplicamos regla de Ruffini
vector <float> tercer_G(char const *argv[]){
    float a = stof(argv[1]);
    float b = stof(argv[2]);
    float c = stof(argv[3]);
    float d = stof(argv[4]);

    raices = divSintetic(a, b, c, d);

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
        if(stof(argv[1]) > 0){//ecuacion de 3er grado
            cout << "Tenemos una Ecuacion de 3er grado" << endl;
            mostrarRaices(tercer_G(argv));
        }
        else if(stof(argv[2]) != 0){//ecuacion de 2do grado

            cout << "Tenemos una Ecuacion de 2do grado" << endl;
            mostrarRaices(segundo_G(argv));

        }else{//ecuacion de primer grado
            cout << "Tenemos una Ecuacion de 1er grado" << endl;
        }
    }

    return 0;
}