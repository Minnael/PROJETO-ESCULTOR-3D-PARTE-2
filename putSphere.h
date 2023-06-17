#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "FiguraGeometrica.h"
#include "sculptor.h"

class PutSphere : public FiguraGeometrica{
protected:
    int xcenter, ycenter, zcenter, radius;
    float r, g, b, a;

public:
    PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float r, float g, float b, float a);
    void draw(Sculptor &t);
};


#endif
