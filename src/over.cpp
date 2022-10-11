#include "over.h"

void over(
    const std::vector<unsigned char> &A,
    const std::vector<unsigned char> &B,
    const int &width,
    const int &height,
    std::vector<unsigned char> &C)
{
  /*
   * Formulas obtained from
   * https://en.wikipedia.org/wiki/Alpha_compositing
   * Notice that With premultiplied alpha,
   * the RGB components represent the emission of the object or pixel, and the alpha represents the occlusion.
   */
  C.resize(A.size());
  for (int i = 0; i < width * height * 4; i += 4)
  {
    double alpha_A = A[i + 3] / 255.0, alpha_B = B[i + 3] / 255.0;

    // alpha value of the ith pixel
    C[i + 3] = (unsigned char)((alpha_A + alpha_B * (1 - alpha_A)) * 255);

    // rgb values of the ith pixel
    for (int channel = 0; channel < 3; channel++)
    {
      C[i + channel] = (unsigned char)((double)A[i + channel] * alpha_A + (double)B[i + channel] * alpha_B * (1 - alpha_A));
    }
  }
}
