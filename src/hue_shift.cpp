#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
    const std::vector<unsigned char> &rgb,
    const int width,
    const int height,
    const double shift,
    std::vector<unsigned char> &shifted)
{
  shifted.resize(rgb.size());

  double r, g, b, h, s, v;
  for (int i = 0; i < width * height * 3; i += 3)
  {
    // In order to use our rgb_to_hsv function, we need to fit rgb values in [0, 1] range
    r = rgb[i] / 255.0;
    g = rgb[i + 1] / 255.0;
    b = rgb[i + 2] / 255.0;
    // Use our rgb_to_hsv function to get the hsv values
    rgb_to_hsv(r, g, b, h, s, v);
    // Hue shift
    h += shift;
    // Fit h value to [0, 360) range
    if (h < 0)
      h += 360;
    if (h >= 360)
      h -= 360;
    // Convert hsv back to rgb
    hsv_to_rgb(h, s, v, r, g, b);
    // Fit rgb values torgb values in [0, 255] range
    shifted[i] = (unsigned char)(r * 255);
    shifted[i + 1] = (unsigned char)(g * 255);
    shifted[i + 2] = (unsigned char)(b * 255);
  }
}
