#include <Ecuacion.h>

#include <iostream>

#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

//constructores
Ecuacion::Ecuacion(){

}
Ecuacion::Ecuacion(float a, float b){
    this->a = a;
    this->b = b;

    primer_G();
}
Ecuacion::Ecuacion(float a, float b, float c){
    this->a = a;
    this->b = b;
    this->c = c;
    segundo_G();
}
Ecuacion::Ecuacion(float a, float b, float c, float d){
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    tercer_G();
}


/* METODOS PARA LAS ECUACIONES*/

//metodo para las ecuaciones de primer grado
vector <float> Ecuacion::primer_G(){
    roots.push_back(-b/a);

    return roots;
}

//metodo para las ecuaciones de segundo grado
/*Para resolver aplicamos formula general*/
vector <float> Ecuacion::segundo_G(){

    float discriminante = (float) (pow(b, 2) - (4 * a * c));

    if(discriminante >= 0){
        roots.push_back( ( -b + sqrt(discriminante) ) / (2 * a));
        roots.push_back( ( -b - sqrt(discriminante) ) / (2 * a));
    }

    return roots;
}


//Genera un vector con los divisores exactos de d
vector <float> Ecuacion::GenDivsD(float d){
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
vector <float> Ecuacion::GenDivsA(float a){
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
vector <float> Ecuacion::GenPosRootSolves(float a, float d){
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
vector <float> Ecuacion::divSintetic(float a, float b, float c, float d){
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
vector <float> Ecuacion::tercer_G(){
    // float a = stof(argv[1]);
    // float b = stof(argv[2]);
    // float c = stof(argv[3]);
    // float d = stof(argv[4]);

    roots = divSintetic(a, b, c, d);

    return roots;
}



//metodo para mostrar las raices
void Ecuacion::showRoots(){
    if(!roots.empty()){
        cout << "Las raices son: " << endl;
        cout << "{";
        for (int i = 0; i < roots.size(); i++)
        {
            cout << roots.at(i) << ", ";
        }
        cout << "}" << endl;
    }
    else{
        cout << "{}";
    }
}
