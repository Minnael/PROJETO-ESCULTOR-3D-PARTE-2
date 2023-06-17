#ifndef LEITORARQUIVOS_H
#define LEITORARQUIVOS_H
#include <vector>
#include "FiguraGeometrica.h"
#include <string>
#include <stdlib.h>

using namespace std;

class LeitorArquivos{
protected:
    int dimx, dimy, dimz;
    float r, g, b, a;

public:
    LeitorArquivos();
    vector<FiguraGeometrica *> parse(std::string filename);
    int getDimx();
    int getDimy();
    int getDimz();
};

#endif
