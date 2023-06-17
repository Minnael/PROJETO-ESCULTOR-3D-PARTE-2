#include "cutEllipsoid.h"
#include "sculptor.h"
#include <math.h>

CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _nx, int _ny, int _nz){
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    nx = _nx;
    ny = _ny;
    nz = _nz;
}

void CutEllipsoid::draw(Sculptor &t){
    float xEllipsoid, yEllipsoid, zEllipsoid;
    for(int i=xcenter-nx; i< xcenter+nx; i++){
        for(int j=ycenter-ny; j<ycenter+ny; j++){
            for(int k=zcenter-nz; k<zcenter+nz; k++){
                xEllipsoid = pow(i-xcenter, 2)/pow(nx, 2);
                yEllipsoid = pow(j-ycenter, 2)/pow(ny, 2);
                zEllipsoid = pow(k-zcenter, 2)/pow(nz, 2);
                if((xEllipsoid + yEllipsoid + zEllipsoid) < 1){
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}



