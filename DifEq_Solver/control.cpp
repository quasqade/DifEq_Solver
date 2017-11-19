#include "control.h"
#include "math.h"

double control_none(double t)
{
    return 0;
}

double control_sin(double t)
{
    return sin(t);
}

double control_ln(double t)
{
    return log(1+t);
}

double control_exp(double t)
{
    return exp(-t);
}

double control_heavyside(double t)
{
    if (t>0)
        return 1;
    return 0;
}
