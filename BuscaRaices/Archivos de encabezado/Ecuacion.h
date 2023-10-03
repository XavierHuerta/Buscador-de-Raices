#include <vector>

using namespace std;

class Ecuacion{

    public:
    static vector <float> raices;

    static vector <float> tercer_G(char const *argv[]);
    static vector <float> segundo_G(char const *argv[]);

    vector <float> calculaPosiblesRaices();

};