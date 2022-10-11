#include "rgb_to_hsv.h"
#include <algorithm>
#include <cmath>

void rgb_to_hsv(
    const double r,
    const double g,
    const double b,
    double &h,
    double &s,
    double &v)
{
  // My implementation of this function is based on the instruction on the lecture slide HSV <=> RGB
  double M = std::max({r, g, b});
  double m = std::min({r, g, b});
  double C = M - m; // chroma

  // Find v
  v = M;

  // Find s
  if (v == 0)
  {
    s = 0;
  }
  else
  {
    s = C / v;
  }

  // Find h
  if (C == 0)
  {
    h = 0;
  }
  else if (M == r)
  {
    h = std::fmod((g - b) / C, 6);
  }
  else if (M == g)
  {
    h = ((b - r) / C) + 2;
  }
  else // M == b
    h = ((r - g) / C) + 4;

  // Fix h value to [0, 360) range
  h *= 60;
  if (h < 0)
  {
    h *= -1;
    h = 360 - std::fmod(h, 360);
  }
  else
  {
    h = std::fmod(h, 360);
  }
}
