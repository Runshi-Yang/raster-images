#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
    const std::vector<unsigned char> &rgb,
    const int width,
    const int height,
    const double factor,
    std::vector<unsigned char> &desaturated)
{
  desaturated.resize(rgb.size());
  double r, g, b, h, s, v;
  for (int i = 0; i < width * height * 3; i += 3)
  {
    // In order to use our rgb_to_hsv function, we need to fit rgb values in [0, 1] range
    r = rgb[i] / 255.0;
    g = rgb[i + 1] / 255.0;
    b = rgb[i + 2] / 255.0;
    // Use our rgb_to_hsv function to get the hsv values
    rgb_to_hsv(r, g, b, h, s, v);
    // Desaturate
    s *= (1.0 - factor);
    // Convert hsv back to rgb
    hsv_to_rgb(h, s, v, r, g, b);
    // Fit rgb values torgb values in [0, 255] range
    desaturated[i] = (unsigned char)(r * 255);
    desaturated[i + 1] = (unsigned char)(g * 255);
    desaturated[i + 2] = (unsigned char)(b * 255);
  }
}
