#include "cutSphere.h"
#include "sculptor.h"
#include <math.h>

CutSphere::CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius){
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
}

void CutSphere::draw(Sculptor &t){
    for(int i=xcenter-radius; i<xcenter+radius; i++){
        for(int j=ycenter-radius; j<ycenter+radius; j++){
            for(int k=zcenter-radius; k<zcenter+radius; k++){
                if((pow((i-xcenter), 2) + pow((j-ycenter), 2) + pow((k-zcenter), 2)) < pow(radius, 2)){
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}
