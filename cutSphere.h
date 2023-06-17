#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "FiguraGeometrica.h"
#include "sculptor.h"

class CutSphere : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, radius;

public:
    CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius);
    void draw(Sculptor &t);
};


#endif
