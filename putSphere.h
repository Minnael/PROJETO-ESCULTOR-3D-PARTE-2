#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "FiguraGeometrica.h"
#include "sculptor.h"

class PutSphere : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, radius;
    float r, g, b, a;

public:
    PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a);
    void draw(Sculptor &t);
};


#endif
