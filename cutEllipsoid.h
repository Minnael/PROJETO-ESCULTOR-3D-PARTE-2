#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "sculptor.h"

class CutEllipsoid : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, nx, ny, nz;

public:
    CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _nx, int _ny, int _nz);
    void draw(Sculptor &t);
};

#endif
