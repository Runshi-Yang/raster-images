#include "demosaic.h"

void demosaic(
    const std::vector<unsigned char> &bayer,
    const int &width,
    const int &height,
    std::vector<unsigned char> &rgb)
{
  rgb.resize(width * height * 3);

  for (int row = 0; row < height; row++) // loop through the rows of the mosaiced image
  {
    for (int col = 0; col < width; col++) // loop through the columns of the that row
    {
      int index = width * row + col;        // index of the pixel of the mosaiced image
      int channel = !(row % 2) + (col % 2); // color channel of the pixel of the mosaiced image

      // indexes of 8 neighbouring pixels
      int top_left_index = index - (width + 1),
          top_index = index - width,
          top_right_index = index - (width - 1),
          left_index = index - 1,
          right_index = index + 1,
          bottom_left_index = index + (width - 1),
          bottom_index = index + width,
          bottom_right_index = index + (width + 1);

      int r, g, b;
      if (channel == 0)
      {
        r = bayer[index];
        if (row == 0) // the selected pixel is on the first row
        {
          if (col == 0) // the selected pixel is on the top left conner of the image
          {
            g = (bayer[right_index] + bayer[bottom_index]) / 2;
            b = bayer[bottom_right_index];
          }
          else if (col == width - 1) // the selected pixel is on the top right conner of the image
          {
            g = (bayer[left_index] + bayer[bottom_index]) / 2;
            b = bayer[bottom_left_index];
          }
          else // the selected pixel is in the middle of the first row
          {
            g = (bayer[left_index] + bayer[right_index] + bayer[bottom_index]) / 3;
            b = (bayer[bottom_left_index] + bayer[bottom_right_index]) / 2;
          }
        }
        else if (row == height - 1) // the selected pixel is on the last row
        {
          if (col == 0) // the selected pixel is on the bootom left conner of the image
          {
            g = (bayer[right_index] + bayer[top_index]) / 2;
            b = bayer[top_right_index];
          }
          else if (col == width - 1) // the selected pixel is on the bottom right conner of the image
          {
            g = (bayer[left_index] + bayer[top_index]) / 2;
            b = bayer[top_left_index];
          }
          else // the selected pixel is in the middle of the last row
          {
            g = (bayer[left_index] + bayer[right_index] + bayer[top_index]) / 3;
            b = (bayer[top_left_index] + bayer[top_right_index]) / 2;
          }
        }
        else // the selected pixel is on the middle row
        {
          if (col == 0) // the selected pixel is on the left of the row
          {
            g = (bayer[right_index] + bayer[top_index] + bayer[bottom_index]) / 3;
            b = (bayer[top_right_index] + bayer[bottom_right_index]) / 2;
          }
          else if (col == width - 1) // the selected pixel is on the right of the row
          {
            g = (bayer[left_index] + bayer[top_index] + bayer[bottom_index]) / 3;
            b = (bayer[top_left_index] + bayer[bottom_left_index]) / 2;
          }
          else // the selected pixel is in the middle of the row
          {
            g = (bayer[left_index] + bayer[right_index] + bayer[top_index] + bayer[bottom_index]) / 4;
            b = (bayer[top_left_index] + bayer[top_right_index] + bayer[bottom_left_index] + bayer[bottom_right_index]) / 4;
          }
        }
      }
      else if (channel == 1)
      {
        g = bayer[index];
        if (row == 0) // the selected pixel is on the first row
        {
          if (col == 0) // the selected pixel is on the top left conner of the image
          {
            r = bayer[right_index];
            b = bayer[bottom_index];
          }
          else if (col == width - 1) // the selected pixel is on the top right conner of the image
          {
            r = bayer[left_index];
            b = bayer[bottom_index];
          }
          else // the selected pixel is in the middle of the first row
          {
            r = (bayer[left_index] + bayer[right_index]) / 2;
            b = bayer[bottom_index];
          }
        }
        else if (row == height - 1) // the selected pixel is on the last row
        {
          if (col == 0) // the selected pixel is on the bootom left conner of the image
          {
            r = bayer[right_index];
            b = bayer[top_index];
          }
          else if (col == width - 1) // the selected pixel is on the bottom right conner of the image
          {
            r = bayer[left_index];
            b = bayer[top_index];
          }
          else // the selected pixel is in the middle of the last row
          {
            r = (bayer[left_index] + bayer[right_index]) / 2;
            b = bayer[top_index];
          }
        }
        else // the selected pixel is on the middle row
        {
          if (col == 0) // the selected pixel is on the left of the row
          {
            r = bayer[right_index];
            b = (bayer[top_index] + bayer[bottom_index]) / 2;
          }
          else if (col == width - 1) // the selected pixel is on the right of the row
          {
            r = bayer[left_index];
            b = (bayer[top_index] + bayer[bottom_index]) / 2;
          }
          else // the selected pixel is in the middle of the row
          {
            if (row % 2)
            {
              b = (bayer[top_index] + bayer[bottom_index]) / 2;
              r = (bayer[left_index] + bayer[right_index]) / 2;
            }
            else
            {
              r = (bayer[top_index] + bayer[bottom_index]) / 2;
              b = (bayer[left_index] + bayer[right_index]) / 2;
            }
          }
        }
      }
      else
      {
        b = bayer[index];
        if (row == 0) // the selected pixel is on the first row
        {
          if (col == 0) // the selected pixel is on the top left conner of the image
          {
            g = (bayer[right_index] + bayer[bottom_index]) / 2;
            r = bayer[bottom_right_index];
          }
          else if (col == width - 1) // the selected pixel is on the top right conner of the image
          {
            g = (bayer[left_index] + bayer[bottom_index]) / 2;
            r = bayer[bottom_left_index];
          }
          else // the selected pixel is in the middle of the first row
          {
            g = (bayer[left_index] + bayer[right_index] + bayer[bottom_index]) / 3;
            r = (bayer[bottom_left_index] + bayer[bottom_right_index]) / 2;
          }
        }
        else if (row == height - 1) // the selected pixel is on the last row
        {
          if (col == 0) // the selected pixel is on the bootom left conner of the image
          {
            g = (bayer[right_index] + bayer[top_index]) / 2;
            r = bayer[top_right_index];
          }
          else if (col == width - 1) // the selected pixel is on the bottom right conner of the image
          {
            g = (bayer[left_index] + bayer[top_index]) / 2;
            r = bayer[top_left_index];
          }
          else // the selected pixel is in the middle of the last row
          {
            g = (bayer[left_index] + bayer[right_index] + bayer[top_index]) / 3;
            r = (bayer[top_left_index] + bayer[top_right_index]) / 2;
          }
        }
        else // the selected pixel is on the middle row
        {
          if (col == 0) // the selected pixel is on the left of the row
          {
            g = (bayer[right_index] + bayer[top_index] + bayer[bottom_index]) / 3;
            r = (bayer[top_right_index] + bayer[bottom_right_index]) / 2;
          }
          else if (col == width - 1) // the selected pixel is on the right of the row
          {
            g = (bayer[left_index] + bayer[top_index] + bayer[bottom_index]) / 3;
            b = (bayer[top_left_index] + bayer[bottom_left_index]) / 2;
          }
          else // the selected pixel is in the middle of the row
          {
            g = (bayer[left_index] + bayer[right_index] + bayer[top_index] + bayer[bottom_index]) / 4;
            r = (bayer[top_left_index] + bayer[top_right_index] + bayer[bottom_left_index] + bayer[bottom_right_index]) / 4;
          }
        }
      }

      rgb[3 * index] = r;
      rgb[3 * index + 1] = g;
      rgb[3 * index + 2] = b;
    }
  }
}