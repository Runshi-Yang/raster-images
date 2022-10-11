#include "rotate.h"

void rotate(
    const std::vector<unsigned char> &input,
    const int width,
    const int height,
    const int num_channels,
    std::vector<unsigned char> &rotated)
{
  rotated.resize(height * width * num_channels);

  for (int row = 0; row < height; row++)
  {                              // loop through each row in the picture
    int rotated_col_index = row; // column index of the rotated image is row index of the input image
    for (int col = 0; col < width; col++)
    {                                                          // loop through each column of that row
      int rotated_row_index = width - col - 1;                 // row index of the rotated image is the column index of the input image counted from right to left
      for (int channel = 0; channel < num_channels; channel++) // write the the value from the input pixel to the corresponding pixel
      {
        rotated[num_channels * (height * rotated_row_index + rotated_col_index) + channel] = input[num_channels * (width * row + col) + channel];
      }
    }
  }
}
