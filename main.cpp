#include <iostream>
#include <fstream>
#include <string>
#include "Voxel.h"
#include "sculptor.h"
#include "interpretador.h"
#include <vector>
#include "putVoxel.h"
#include "putBox.h"
#include "putSphere.h"
#include "putEllipsoid.h"
#include "cutVoxel.h"
#include "cutBox.h"
#include "cutSphere.h"
#include "cutEllipsoid.h"
#include "FiguraGeometrica.h"
using namespace std;

int main(){
    Sculptor *sx;
    Interpretador anl;
    vector<FiguraGeometrica*> fig;

    fig = anl.anl("entrada.txt");

    sx = new Sculptor(anl.getdimx(),anl.getdimy(),anl.getdimz());
    for (size_t x=0; x<fig.size(); x++){
        fig[x] -> draw(*sx);
    }

    sx->writeOFF((char*)"teste.off");

    for (size_t x=0; x<fig.size(); x++){
        delete fig[x];
    }
    delete sx;

    return 0;
}
