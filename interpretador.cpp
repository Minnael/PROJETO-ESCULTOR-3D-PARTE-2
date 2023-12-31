#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "putVoxel.h"
#include "putBox.h"
#include "putSphere.h"
#include "putEllipsoid.h"
#include "cutVoxel.h"
#include "CutBox.h"
#include "cutSphere.h"
#include "cutEllipsoid.h"
#include "interpretador.h"


using namespace std;

Interpretador::Interpretador(){}

vector<FiguraGeometrica*> Interpretador:: anl(string filename){

    vector<FiguraGeometrica*> figuras;
    ifstream arqv;
    string stng,pp;
    stringstream ss;

    arqv.open(filename.c_str());

    if(!arqv.is_open()){
        exit(0);
    }

    while(getline(arqv,stng)){

        ss.clear();
        ss.str(stng);
        ss >> pp;
        cout << pp << " ";

        if(pp.compare("dim")==0){
            ss >> dimx >> dimy >> dimz;
        }
        else if(pp.compare("putvoxel")==0){
            int x_,y_,z_;
            ss >> x_ >> y_ >> z_ >> r >> g >> b >> a;
            figuras.push_back(new PutVoxel(x_, y_, z_, r, g, b, a));
        }
        else if(pp.compare("cutvoxel")==0){
            int x_, y_, z_;
            ss >> x_ >> y_ >> z_;
            figuras.push_back(new CutVoxel(x_,y_,z_));
        }
        else if(pp.compare("putbox")==0){
            int x0; int x1; int y0; int y1; int z0; int z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figuras.push_back(new PutBox(x0,x1,y0, y1, z0,z1, r, g, b, a));
        }
        else if(pp.compare("cutbox")==0){
            int x0; int x1; int y0; int y1; int z0; int z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figuras.push_back(new CutBox(x0,x1,y0, y1, z0,z1));
        }
        else if(pp.compare("putsphere")==0){
            int xcenter; int ycenter; int zcenter; int radius;
            ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            figuras.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
        }
        else if(pp.compare("cutsphere")==0){
            int xcenter; int ycenter; int zcenter; int radius;
            ss >> xcenter >> ycenter >> zcenter >> radius;
            figuras.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
        }
        else if(pp.compare("putellipsoid")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            figuras.push_back(new PutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz, r, g, b, a));
        }
        else if(pp.compare("cutellipsoid")==0){
            int _xcenter, _ycenter, _zcenter, _nx, _ny, _nz;
            ss >> _xcenter >> _ycenter >> _zcenter >> _nx >> _ny >> _nz;
            figuras.push_back(new CutEllipsoid(_xcenter,_ycenter,_zcenter,_nx,_ny,_nz));
        }
    }

    arqv.close();
    return(figuras);
}

int Interpretador::getdimx(){
    return dimx;
}

int Interpretador::getdimy(){
    return dimy;
}

int Interpretador::getdimz(){
    return dimz;
}
