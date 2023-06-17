#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "leitorArquivos.h"
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"

using namespace std;

LeitorArquivos::LeitorArquivos(){}

vector <FiguraGeometrica *> LeitorArquivos::parse(string filename){
    vector <FiguraGeometrica *> figs;
    ifstream fig;
    stringstream ss;
    string s, token;

    fig.open(filename);

    if(!fig.is_open()){
        exit(0);
    }

    while(fig.good()){
        getline(fig, s);

        if(fig.good()){
            ss.clear();
            ss.str(s);
            ss >> token;

            if(ss.good()){
                if(token.compare("dim") == 0){
                    ss >> dimx >> dimy >> dimz;
                }else if(token.compare("putvoxel") == 0){
                    int x0, y0, z0;
                    ss>>x0>>y0>>z0>>r>>g>>b>>a;
                    figs.push_back(new PutVoxel(x0, y0, z0, r, g, b, a));
                }else if(token.compare("putbox") == 0){
                    int x0,x1,y0,y1,z0,z1;
                    ss>>x0>>x1>>y0>>y1>>z0>>z1>>r>>g>>b>>a;
                    figs.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
                }else if(token.compare("putsphere") == 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss>>xcenter>>ycenter>>zcenter>>radius>>r>>g>>b>>a;
                    figs.push_back(new PutSphere(xcenter,ycenter,zcenter,radius,r,g,b,a));
                }else if(token.compare("putellipsoid") == 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss>>xcenter>>ycenter>>zcenter>>rx>>ry>>rz>>r>>g>>b>>a;
                    figs.push_back(new PutEllipsoid(xcenter,ycenter,zcenter,nx,ny,nz,r,g,b,a));
                }else if(token.compare("cutvoxel") == 0){
                    int x, y, z;
                    ss>>x>>y>>z;
                    figs.push_back(new CutVoxel(x,y,z));
                }else if(token.compare("cutbox") == 0){
                    int x0,x1,y0,y1,z0,z1;
                    ss>>x0>>x1>>y0>>y1>>z0>>z1;
                    figs.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
                }else if(token.compare("cutsphere") == 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    figs.push_back(new CutSphere(xcenter,ycenter,zcenter,radius));
                }else if(token.compare("cutellipsoid") == 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                    figs.push_back(new CutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz));
                }
            }
        }
    }
    return(figs);
}

int LeitorArquivos::getDimx(){
    return dimx;
}

int LeitorArquivos::getDimy(){
    return dimy;
}

int LeitorArquivos::getDimz(){
    return dimz;
}

