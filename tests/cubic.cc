#include <gtest/gtest.h>

extern "C" {
int rcubic_roots(double a2, double a1, double a0, double *r1, double *r2, double *r3);
}

TEST(CubicTest, Official) {
  double r1, r2, r3;
  int num_roots;

  num_roots = rcubic_roots(3, 3, 1, &r1, &r2, &r3);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(-1, r1, 1e-07);
  ASSERT_NEAR(-1, r2, 1e-07);
  ASSERT_NEAR(-1, r3, 1e-07);

  num_roots = rcubic_roots(-3, 3, -1, &r1, &r2, &r3);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(1, r2, 1e-07);
  ASSERT_NEAR(1, r3, 1e-07);

  num_roots = rcubic_roots(-4, -11, 30, &r1, &r2, &r3);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(5, r1, 1e-07);
  ASSERT_NEAR(2, r2, 1e-07);
  ASSERT_NEAR(-3, r3, 1e-07);

  num_roots = rcubic_roots(1, 3, -5, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(-1, r2, 1e-07);
  ASSERT_NEAR(2, r3, 1e-07);

  num_roots = rcubic_roots(2, -1, -2, &r1, &r2, &r3);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(-1, r2, 1e-07);
  ASSERT_NEAR(-2, r3, 1e-07);

  num_roots = rcubic_roots(1, -1, -1, &r1, &r2, &r3);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(-1, r2, 1e-07);
  ASSERT_NEAR(-1, r3, 1e-07);

  num_roots = rcubic_roots(15, 75, 125, &r1, &r2, &r3);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(-5, r1, 1e-07);
  ASSERT_NEAR(-5, r2, 1e-07);
  ASSERT_NEAR(-5, r3, 1e-07);

  num_roots = rcubic_roots(-2, -5, 6, &r1, &r2, &r3);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(3, r1, 1e-07);
  ASSERT_NEAR(1, r2, 1e-07);
  ASSERT_NEAR(-2, r3, 1e-07);

  num_roots = rcubic_roots(3, 9, -13, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(-2, r2, 1e-07);
  ASSERT_NEAR(3, r3, 1e-07);

  num_roots = rcubic_roots(-9, 27, -27, &r1, &r2, &r3);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(3, r1, 1e-07);
  ASSERT_NEAR(3, r2, 1e-07);
  ASSERT_NEAR(3, r3, 1e-07);

  num_roots = rcubic_roots(0, 0, -64, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(4, r1, 1e-07);
  ASSERT_NEAR(-2, r2, 1e-07);
  ASSERT_NEAR(3.4641016151377546, r3, 1e-07);

  num_roots = rcubic_roots(0, 0, 64, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-4, r1, 1e-07);
  ASSERT_NEAR(2, r2, 1e-07);
  ASSERT_NEAR(3.4641016151377546, r3, 1e-07);

  num_roots = rcubic_roots(-3, 2, 0, &r1, &r2, &r3);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(2, r1, 1e-07);
  ASSERT_NEAR(1, r2, 1e-07);
  ASSERT_NEAR(0, r3, 1e-07);

  num_roots = rcubic_roots(-1, 9, -9, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);
  ASSERT_NEAR(3, r3, 1e-07);

  num_roots = rcubic_roots(2, -7, 4, &r1, &r2, &r3);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(1, r2, 1e-07);
  ASSERT_NEAR(-4, r3, 1e-07);

  num_roots = rcubic_roots(2, 4, 8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-2.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(2.00000000000000000, r3, 1e-07);

  num_roots = rcubic_roots(0, 4, 8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-1.36465560765603870, r1, 1e-07);
  ASSERT_NEAR(0.68232780382801938, r2, 1e-07);
  ASSERT_NEAR(2.32308279999450390, r3, 1e-07);

  num_roots = rcubic_roots(-2, 4, 8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-1.08737802538415270, r1, 1e-07);
  ASSERT_NEAR(1.54368901269207640, r2, 1e-07);
  ASSERT_NEAR(2.23028501607987470, r3, 1e-07);

  num_roots = rcubic_roots(2, 0, 8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-2.93114246375353600, r1, 1e-07);
  ASSERT_NEAR(0.46557123187676813, r2, 1e-07);
  ASSERT_NEAR(1.58510398503089580, r3, 1e-07);

  num_roots = rcubic_roots(0, 0, 8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-2.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(1.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(1.73205080756887730, r3, 1e-07);

  num_roots = rcubic_roots(-2, 0, 8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-1.50975533249338540, r1, 1e-07);
  ASSERT_NEAR(1.75487766624669280, r2, 1e-07);
  ASSERT_NEAR(1.48972353323948850, r3, 1e-07);

  num_roots = rcubic_roots(2, -4, 8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-3.67857351042832230, r1, 1e-07);
  ASSERT_NEAR(0.83928675521416113, r2, 1e-07);
  ASSERT_NEAR(1.21258145841439880, r3, 1e-07);

  num_roots = rcubic_roots(0, -4, 8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-2.64943591448949200, r1, 1e-07);
  ASSERT_NEAR(1.32471795724474600, r2, 1e-07);
  ASSERT_NEAR(1.12455902412460250, r3, 1e-07);

  num_roots = rcubic_roots(-2, -4, 8, &r1, &r2, &r3);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(2.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(-2.00000000000000000, r3, 1e-07);

  num_roots = rcubic_roots(2, 4, 0, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(-1.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(1.73205080756887730, r3, 1e-07);

  num_roots = rcubic_roots(0, 4, 0, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(2.00000000000000000, r3, 1e-07);

  num_roots = rcubic_roots(-2, 4, 0, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(1.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(1.73205080756887730, r3, 1e-07);

  num_roots = rcubic_roots(2, 0, 0, &r1, &r2, &r3);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(-2.00000000000000000, r3, 1e-07);

  num_roots = rcubic_roots(0, 0, 0, &r1, &r2, &r3);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r3, 1e-07);

  num_roots = rcubic_roots(-2, 0, 0, &r1, &r2, &r3);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r3, 1e-07);

  num_roots = rcubic_roots(0, -4, 0, &r1, &r2, &r3);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(2.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(-2.00000000000000000, r3, 1e-07);

  num_roots = rcubic_roots(2, 4, -8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1.08737802538415270, r1, 1e-07);
  ASSERT_NEAR(-1.54368901269207640, r2, 1e-07);
  ASSERT_NEAR(2.23028501607987470, r3, 1e-07);

  num_roots = rcubic_roots(0, 4, -8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1.36465560765603870, r1, 1e-07);
  ASSERT_NEAR(-0.68232780382801938, r2, 1e-07);
  ASSERT_NEAR(2.32308279999450390, r3, 1e-07);

  num_roots = rcubic_roots(-2, 4, -8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(2.00000000000000000, r3, 1e-07);

  num_roots = rcubic_roots(2, 0, -8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1.50975533249338540, r1, 1e-07);
  ASSERT_NEAR(-1.75487766624669280, r2, 1e-07);
  ASSERT_NEAR(1.48972353323948850, r3, 1e-07);

  num_roots = rcubic_roots(0, 0, -8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(-1.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(1.73205080756887730, r3, 1e-07);

  num_roots = rcubic_roots(-2, 0, -8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2.93114246375353600, r1, 1e-07);
  ASSERT_NEAR(-0.46557123187676813, r2, 1e-07);
  ASSERT_NEAR(1.58510398503089580, r3, 1e-07);

  num_roots = rcubic_roots(2, -4, -8, &r1, &r2, &r3);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(-2.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(-2.00000000000000000, r3, 1e-07);

  num_roots = rcubic_roots(0, -4, -8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2.64943591448949200, r1, 1e-07);
  ASSERT_NEAR(-1.32471795724474600, r2, 1e-07);
  ASSERT_NEAR(1.12455902412460250, r3, 1e-07);

  num_roots = rcubic_roots(-2, -4, -8, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(3.67857351042832230, r1, 1e-07);
  ASSERT_NEAR(-0.83928675521416113, r2, 1e-07);
  ASSERT_NEAR(1.21258145841439880, r3, 1e-07);

  num_roots = rcubic_roots(2, -4, 0, &r1, &r2, &r3);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1.23606797749978970, r1, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(-3.23606797749978970, r3, 1e-07);

  num_roots = rcubic_roots(-2, -4, 0, &r1, &r2, &r3);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(3.23606797749978970, r1, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(-1.23606797749978970, r3, 1e-07);

  num_roots = rcubic_roots(1, 1e300, 1e300, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-1, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);
  ASSERT_NEAR(1e150, r3, 1e+143);

  num_roots = rcubic_roots(1, 1, 1e300, &r1, &r2, &r3);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-1e100, r1, 1e+93);
  ASSERT_NEAR(.5e100, r2, 5e+92);
  ASSERT_NEAR(.86602540378443865e100, r3, 8.66025403784e+92);

  // slow convergence with newton method
//  num_roots = rcubic_roots(1, 1e300, 1, &r1, &r2, &r3);
//  ASSERT_EQ(1, num_roots);
//  ASSERT_NEAR(-1e-300, r1, 1e-07);
//  ASSERT_NEAR(-0.5, r2, 1e-07);
//  ASSERT_NEAR(1e150, r3, 1e+143);

  num_roots = rcubic_roots(0, 0, 0, &r1, &r2, &r3);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0.00000000000000000, r1, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r2, 1e-07);
  ASSERT_NEAR(0.00000000000000000, r3, 1e-07);
}
