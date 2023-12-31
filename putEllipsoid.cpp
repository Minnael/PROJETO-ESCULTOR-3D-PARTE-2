#include "putEllipsoid.h"
#include "sculptor.h"
#include <math.h>

PutEllipsoid::PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _nx, int _ny, int _nz, float _r, float _g, float _b, float _a){
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    nx = _nx;
    ny = _ny;
    nz = _nz;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void PutEllipsoid::draw(Sculptor &t){
    t.setColor(r, g, b, a);
    float xEllipsoid, yEllipsoid, zEllipsoid;
    for(int i=xcenter-nx; i<xcenter+nx; i++){
        for(int j=ycenter-ny; j<ycenter+ny; j++){
            for(int k=zcenter-nz; k<zcenter+nz; k++){
                xEllipsoid = pow(i-xcenter, 2)/pow(nx, 2);
                yEllipsoid = pow(j-ycenter, 2)/pow(ny, 2);
                zEllipsoid = pow(k-zcenter, 2)/pow(nz, 2);
                if((xEllipsoid + yEllipsoid + zEllipsoid) < 1){
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}


