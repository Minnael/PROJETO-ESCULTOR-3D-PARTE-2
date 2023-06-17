#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "sculptor.h"

class PutEllipsoid : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, nx, ny, nz;
    float r, g, b, a;

public:
    PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _nx, int _ny, int _nz, float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
};

#endif
