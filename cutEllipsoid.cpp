#include "cutEllipsoid.h"
#include <math.h>

CutEllipsoid::CutEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_){
    this->xcenter_=xcenter_;
    this->ycenter_=ycenter_;
    this->zcenter_=zcenter_;
    this->rx_=rx_;
    this->ry_=ry_;
    this->rz_=rz_;
}

void CutEllipsoid::draw(Sculptor &t){
    float xEllipsoid, yEllipsoid, zEllipsoid;
    for(int i=xcenter_-rx_; i<xcenter_+rx_; i++){
        for(int j=ycenter_-ry_; j<ycenter_+ry_; j++){
            for(int k=zcenter_-rz_; k<zcenter_+rz_; k++){
                xEllipsoid = pow(i-xcenter_, 2)/pow(rx_, 2);
                yEllipsoid = pow(j-ycenter_, 2)/pow(ry_, 2);
                zEllipsoid = pow(k-zcenter_, 2)/pow(rz_, 2);
                if((xEllipsoid + yEllipsoid + zEllipsoid) < 1){
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}
