#include "reflect.h"

void reflect(
    const std::vector<unsigned char> &input,
    const int width,
    const int height,
    const int num_channels,
    std::vector<unsigned char> &reflected)
{
  reflected.resize(width * height * num_channels);
  for (int i = 0; i < height; i++) // loop through each row in the picture
  {
    int j = 0;
    while (j <= width - 1 - j) // loop through each pixel in a row, do not stop until reach the middle of the row
    {
      for (int channel = 0; channel < num_channels; channel++) // swap the values of the symmetric positions
      {
        reflected[num_channels * (width * i + j) + channel] = input[num_channels * (width * i + width - 1 - j) + channel];
        reflected[num_channels * (width * i + width - 1 - j) + channel] = input[num_channels * (width * i + j) + channel];
      }
      j++;
    }
  }
}
