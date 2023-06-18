#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include "FiguraGeometrica.h"
#include <string>
using namespace std;

class Interpretador
{
    int dimx,dimy,dimz;
    float r,g,b,a;
public:
    Interpretador();
    ~Interpretador(){};

    vector<FiguraGeometrica*> anl(string filename);

    int getdimx();
    int getdimy();
    int getdimz();
};

#endif
