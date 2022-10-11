#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
    const std::vector<unsigned char> &rgb,
    const int &width,
    const int &height,
    std::vector<unsigned char> &bayer)
{
  bayer.resize(width * height);

  for (int row = 0; row < height; row++) // loop through the rows of the input picture
  {
    for (int col = 0; col < width; col++) // loop through the columns of the row
    {
      int index = width * row + col;           // the index of the pixel of the output image
      int channel = !(row % 2) + (col % 2);    // the color channel for the pixel of the output image
      bayer[index] = rgb[3 * index + channel]; // copy the channel value from the rgb pixel to the pixel of the output image
    }
  }
}
