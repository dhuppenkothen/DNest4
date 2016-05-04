#include "Cauchy.h"
#include <stdexcept>
#include <cmath>

namespace DNest4
{

Cauchy::Cauchy(double center, double width)
:center(center)
,width(width)
{
    if(width <= 0.0)
        throw std::domain_error("Cauchy distribution must have positive width.");
}

double Cauchy::cdf(double x) const
{
    return atan((x - center)/width)/M_PI + 0.5;
}

double Cauchy::cdf_inverse(double x) const
{
    if(x < 0.0 || x > 1.0)
        throw std::domain_error("Input to cdf_inverse must be in [0, 1].");
    return center + width*tan(M_PI*(x - 0.5));
}

} // namespace DNest4

