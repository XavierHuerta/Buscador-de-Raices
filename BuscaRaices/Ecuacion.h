
#include <vector>

using namespace std;

class Ecuacion{
    private:
    vector <float> roots;
    float a, b, c, d;

    //Metodos para ecuaciones de primer grado
    vector <float> primer_G();

    //Metodos para ecuaciones de segundo grado
    vector <float> segundo_G();

    //Metodos para ecuaciones de tercer grado
    vector <float> tercer_G();
    vector <float> divSintetic(float a, float b, float c, float d);
    vector <float> GenPosRootSolves(float a, float d);
    vector <float> GenDivsA(float a);
    vector <float> GenDivsD(float d);

    public:
    Ecuacion();
    Ecuacion(float, float);//Primer grado
    Ecuacion(float, float, float);//Segundo grado
    Ecuacion(float, float, float, float);//tercer grado

    //metodo para mostrar las raices solucion
    void showRoots();

};