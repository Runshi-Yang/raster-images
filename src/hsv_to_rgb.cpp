#include "hsv_to_rgb.h"
#include <algorithm>
#include <cmath>

void hsv_to_rgb(
    const double h,
    const double s,
    const double v,
    double &r,
    double &g,
    double &b)
{
  // My implementation of this function is based on the instruction on the following website:
  // https://cs.stackexchange.com/questions/64549/convert-hsv-to-rgb-colors
  double C = s * v;
  double H = h / 60;
  double X = C * (1 - std::fabs(std::fmod(H, 2) - 1));

  double R, G, B;
  if (H == 0)
  {
    R = 0;
    G = 0;
    B = 0;
  }
  else if (H <= 1)
  {
    R = C;
    G = X;
    B = 0;
  }
  else if (H <= 2)
  {
    R = X;
    G = C;
    B = 0;
  }
  else if (H <= 3)
  {
    R = 0;
    G = C;
    B = X;
  }
  else if (H <= 4)
  {
    R = 0;
    G = X;
    B = C;
  }
  else if (H <= 5)
  {
    R = X;
    G = 0;
    B = C;
  }
  else
  {
    R = C;
    G = 0;
    B = X;
  }

  double m = v - C;
  r = R + m;
  g = G + m;
  b = B + m;
}
