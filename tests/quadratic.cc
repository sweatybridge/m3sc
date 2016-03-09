#include <gtest/gtest.h>

extern "C" {
int quad_roots(double a2, double a1, double a0, double *r1, double *r2);
}

TEST(QuadraticTest, Official) {
  double r1, r2;
  int num_roots;

  num_roots = quad_roots(2, 6, 4, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1, r1, 1e-07);
  ASSERT_NEAR(-2, r2, 1e-07);

  num_roots = quad_roots(2, 4, 6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-1, r1, 1e-07);
  ASSERT_NEAR(1.4142135623731, r2, 1e-07);

  num_roots = quad_roots(4, -4, 1, &r1, &r2);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0.5, r1, 1e-07);
  ASSERT_NEAR(0.5, r2, 1e-07);

  num_roots = quad_roots(2, -6, 4, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r1, 1e-07);
  ASSERT_NEAR(1, r2, 1e-07);

  num_roots = quad_roots(2, -4, 10, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(2, r2, 1e-07);

  num_roots = quad_roots(2, -12, 18, &r1, &r2);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(3, r1, 1e-07);
  ASSERT_NEAR(3, r2, 1e-07);

  num_roots = quad_roots(0, 2, 1, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-0.5, r2, 1e-07);

  num_roots = quad_roots(0, 2, 0, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(0, 0, 0, &r1, &r2);
  ASSERT_EQ(-2, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(0, 0, 2, &r1, &r2);
  ASSERT_EQ(-3, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(1, 0, 9, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(3, r2, 1e-07);

  num_roots = quad_roots(1, 0, -9, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3, r1, 1e-07);
  ASSERT_NEAR(-3, r2, 1e-07);

  num_roots = quad_roots(1, 100000000, -1, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1e-08, r1, 1e-07);
  ASSERT_NEAR(-100000000, r2, 10.0);

  num_roots = quad_roots(1, 100000000, 1, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1e-08, r1, 1e-07);
  ASSERT_NEAR(-100000000, r2, 10.0);

  num_roots = quad_roots(1, -100000000, -1, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(100000000, r1, 10.0);
  ASSERT_NEAR(-1e-08, r2, 1e-07);

  num_roots = quad_roots(1, -100000000, 1, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(100000000, r1, 10.0);
  ASSERT_NEAR(1e-08, r2, 1e-07);

  num_roots = quad_roots(4, 2, 6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.25, r1, 1e-07);
  ASSERT_NEAR(1.19895788082818, r2, 1e-07);

  num_roots = quad_roots(2, 2, 6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.5, r1, 1e-07);
  ASSERT_NEAR(1.6583123951777, r2, 1e-07);

  num_roots = quad_roots(0, 2, 6, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-3, r2, 1e-07);

  num_roots = quad_roots(-2, 2, 6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.30277563773199, r1, 1e-07);
  ASSERT_NEAR(-1.30277563773199, r2, 1e-07);

  num_roots = quad_roots(-4, 2, 6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5, r1, 1e-07);
  ASSERT_NEAR(-1, r2, 1e-07);

  num_roots = quad_roots(4, 1, 6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.125, r1, 1e-07);
  ASSERT_NEAR(1.21834929310112, r2, 1e-07);

  num_roots = quad_roots(2, 1, 6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.25, r1, 1e-07);
  ASSERT_NEAR(1.71391365010026, r2, 1e-07);

  num_roots = quad_roots(0, 1, 6, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-6, r2, 1e-07);

  num_roots = quad_roots(-2, 1, 6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r1, 1e-07);
  ASSERT_NEAR(-1.5, r2, 1e-07);

  num_roots = quad_roots(-4, 1, 6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.35610722522451, r1, 1e-07);
  ASSERT_NEAR(-1.10610722522451, r2, 1e-07);

  num_roots = quad_roots(4, 0, 6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(1.22474487139159, r2, 1e-07);

  num_roots = quad_roots(2, 0, 6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(1.73205080756888, r2, 1e-07);

  num_roots = quad_roots(0, 0, 6, &r1, &r2);
  ASSERT_EQ(-3, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, 0, 6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.73205080756888, r1, 1e-07);
  ASSERT_NEAR(-1.73205080756888, r2, 1e-07);

  num_roots = quad_roots(-4, 0, 6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.22474487139159, r1, 1e-07);
  ASSERT_NEAR(-1.22474487139159, r2, 1e-07);

  num_roots = quad_roots(4, -1, 6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.125, r1, 1e-07);
  ASSERT_NEAR(1.21834929310112, r2, 1e-07);

  num_roots = quad_roots(2, -1, 6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.25, r1, 1e-07);
  ASSERT_NEAR(1.71391365010026, r2, 1e-07);

  num_roots = quad_roots(0, -1, 6, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(6, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, -1, 6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5, r1, 1e-07);
  ASSERT_NEAR(-2, r2, 1e-07);

  num_roots = quad_roots(-4, -1, 6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.10610722522451, r1, 1e-07);
  ASSERT_NEAR(-1.35610722522451, r2, 1e-07);

  num_roots = quad_roots(4, -2, 6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.25, r1, 1e-07);
  ASSERT_NEAR(1.19895788082818, r2, 1e-07);

  num_roots = quad_roots(2, -2, 6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.5, r1, 1e-07);
  ASSERT_NEAR(1.6583123951777, r2, 1e-07);

  num_roots = quad_roots(0, -2, 6, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(3, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, -2, 6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.30277563773199, r1, 1e-07);
  ASSERT_NEAR(-2.30277563773199, r2, 1e-07);

  num_roots = quad_roots(-4, -2, 6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(-1.5, r2, 1e-07);

  num_roots = quad_roots(4, 2, 3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.25, r1, 1e-07);
  ASSERT_NEAR(0.82915619758885, r2, 1e-07);

  num_roots = quad_roots(2, 2, 3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.5, r1, 1e-07);
  ASSERT_NEAR(1.11803398874989, r2, 1e-07);

  num_roots = quad_roots(0, 2, 3, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-1.5, r2, 1e-07);

  num_roots = quad_roots(-2, 2, 3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.8228756555323, r1, 1e-07);
  ASSERT_NEAR(-0.822875655532295, r2, 1e-07);

  num_roots = quad_roots(-4, 2, 3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.151387818866, r1, 1e-07);
  ASSERT_NEAR(-0.651387818865997, r2, 1e-07);

  num_roots = quad_roots(4, 1, 3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.125, r1, 1e-07);
  ASSERT_NEAR(0.85695682505013, r2, 1e-07);

  num_roots = quad_roots(2, 1, 3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.25, r1, 1e-07);
  ASSERT_NEAR(1.19895788082818, r2, 1e-07);

  num_roots = quad_roots(0, 1, 3, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-3, r2, 1e-07);

  num_roots = quad_roots(-2, 1, 3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5, r1, 1e-07);
  ASSERT_NEAR(-1, r2, 1e-07);

  num_roots = quad_roots(-4, 1, 3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(-0.75, r2, 1e-07);

  num_roots = quad_roots(4, 0, 3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0.866025403784439, r2, 1e-07);

  num_roots = quad_roots(2, 0, 3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(1.22474487139159, r2, 1e-07);

  num_roots = quad_roots(0, 0, 3, &r1, &r2);
  ASSERT_EQ(-3, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, 0, 3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.22474487139159, r1, 1e-07);
  ASSERT_NEAR(-1.22474487139159, r2, 1e-07);

  num_roots = quad_roots(-4, 0, 3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.866025403784439, r1, 1e-07);
  ASSERT_NEAR(-0.866025403784439, r2, 1e-07);

  num_roots = quad_roots(4, -1, 3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.125, r1, 1e-07);
  ASSERT_NEAR(0.85695682505013, r2, 1e-07);

  num_roots = quad_roots(2, -1, 3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.25, r1, 1e-07);
  ASSERT_NEAR(1.19895788082818, r2, 1e-07);

  num_roots = quad_roots(0, -1, 3, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(3, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, -1, 3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(-1.5, r2, 1e-07);

  num_roots = quad_roots(-4, -1, 3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.75, r1, 1e-07);
  ASSERT_NEAR(-1, r2, 1e-07);

  num_roots = quad_roots(4, -2, 3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.25, r1, 1e-07);
  ASSERT_NEAR(0.82915619758885, r2, 1e-07);

  num_roots = quad_roots(2, -2, 3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.5, r1, 1e-07);
  ASSERT_NEAR(1.11803398874989, r2, 1e-07);

  num_roots = quad_roots(0, -2, 3, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(1.5, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, -2, 3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.822875655532295, r1, 1e-07);
  ASSERT_NEAR(-1.8228756555323, r2, 1e-07);

  num_roots = quad_roots(-4, -2, 3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.651387818865997, r1, 1e-07);
  ASSERT_NEAR(-1.151387818866, r2, 1e-07);

  num_roots = quad_roots(4, 2, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-0.5, r2, 1e-07);

  num_roots = quad_roots(2, 2, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-1, r2, 1e-07);

  num_roots = quad_roots(0, 2, 0, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, 2, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-4, 2, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.5, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(4, 1, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-0.25, r2, 1e-07);

  num_roots = quad_roots(2, 1, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-0.5, r2, 1e-07);

  num_roots = quad_roots(0, 1, 0, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, 1, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.5, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-4, 1, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.25, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(4, 0, 0, &r1, &r2);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(2, 0, 0, &r1, &r2);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(0, 0, 0, &r1, &r2);
  ASSERT_EQ(-2, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, 0, 0, &r1, &r2);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-4, 0, 0, &r1, &r2);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(4, -1, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.25, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(2, -1, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.5, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(0, -1, 0, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, -1, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-0.5, r2, 1e-07);

  num_roots = quad_roots(-4, -1, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-0.25, r2, 1e-07);

  num_roots = quad_roots(4, -2, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.5, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(2, -2, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(0, -2, 0, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, -2, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-1, r2, 1e-07);

  num_roots = quad_roots(-4, -2, 0, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-0.5, r2, 1e-07);

  num_roots = quad_roots(4, 2, -3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.651387818865997, r1, 1e-07);
  ASSERT_NEAR(-1.151387818866, r2, 1e-07);

  num_roots = quad_roots(2, 2, -3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.822875655532295, r1, 1e-07);
  ASSERT_NEAR(-1.8228756555323, r2, 1e-07);

  num_roots = quad_roots(0, 2, -3, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(1.5, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, 2, -3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.5, r1, 1e-07);
  ASSERT_NEAR(1.11803398874989, r2, 1e-07);

  num_roots = quad_roots(-4, 2, -3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.25, r1, 1e-07);
  ASSERT_NEAR(0.82915619758885, r2, 1e-07);

  num_roots = quad_roots(4, 1, -3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.75, r1, 1e-07);
  ASSERT_NEAR(-1, r2, 1e-07);

  num_roots = quad_roots(2, 1, -3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(-1.5, r2, 1e-07);

  num_roots = quad_roots(0, 1, -3, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(3, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, 1, -3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.25, r1, 1e-07);
  ASSERT_NEAR(1.19895788082818, r2, 1e-07);

  num_roots = quad_roots(-4, 1, -3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.125, r1, 1e-07);
  ASSERT_NEAR(0.85695682505013, r2, 1e-07);

  num_roots = quad_roots(4, 0, -3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.866025403784439, r1, 1e-07);
  ASSERT_NEAR(-0.866025403784439, r2, 1e-07);

  num_roots = quad_roots(2, 0, -3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.22474487139159, r1, 1e-07);
  ASSERT_NEAR(-1.22474487139159, r2, 1e-07);

  num_roots = quad_roots(0, 0, -3, &r1, &r2);
  ASSERT_EQ(-3, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, 0, -3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(1.22474487139159, r2, 1e-07);

  num_roots = quad_roots(-4, 0, -3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0.866025403784439, r2, 1e-07);

  num_roots = quad_roots(4, -1, -3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(-0.75, r2, 1e-07);

  num_roots = quad_roots(2, -1, -3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5, r1, 1e-07);
  ASSERT_NEAR(-1, r2, 1e-07);

  num_roots = quad_roots(0, -1, -3, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-3, r2, 1e-07);

  num_roots = quad_roots(-2, -1, -3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.25, r1, 1e-07);
  ASSERT_NEAR(1.19895788082818, r2, 1e-07);

  num_roots = quad_roots(-4, -1, -3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.125, r1, 1e-07);
  ASSERT_NEAR(0.85695682505013, r2, 1e-07);

  num_roots = quad_roots(4, -2, -3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.151387818866, r1, 1e-07);
  ASSERT_NEAR(-0.651387818865997, r2, 1e-07);

  num_roots = quad_roots(2, -2, -3, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.8228756555323, r1, 1e-07);
  ASSERT_NEAR(-0.822875655532295, r2, 1e-07);

  num_roots = quad_roots(0, -2, -3, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-1.5, r2, 1e-07);

  num_roots = quad_roots(-2, -2, -3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.5, r1, 1e-07);
  ASSERT_NEAR(1.11803398874989, r2, 1e-07);

  num_roots = quad_roots(-4, -2, -3, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.25, r1, 1e-07);
  ASSERT_NEAR(0.82915619758885, r2, 1e-07);

  num_roots = quad_roots(4, 2, -6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r1, 1e-07);
  ASSERT_NEAR(-1.5, r2, 1e-07);

  num_roots = quad_roots(2, 2, -6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.30277563773199, r1, 1e-07);
  ASSERT_NEAR(-2.30277563773199, r2, 1e-07);

  num_roots = quad_roots(0, 2, -6, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(3, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, 2, -6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.5, r1, 1e-07);
  ASSERT_NEAR(1.6583123951777, r2, 1e-07);

  num_roots = quad_roots(-4, 2, -6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.25, r1, 1e-07);
  ASSERT_NEAR(1.19895788082818, r2, 1e-07);

  num_roots = quad_roots(4, 1, -6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.10610722522451, r1, 1e-07);
  ASSERT_NEAR(-1.35610722522451, r2, 1e-07);

  num_roots = quad_roots(2, 1, -6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5, r1, 1e-07);
  ASSERT_NEAR(-2, r2, 1e-07);

  num_roots = quad_roots(0, 1, -6, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(6, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, 1, -6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.25, r1, 1e-07);
  ASSERT_NEAR(1.71391365010026, r2, 1e-07);

  num_roots = quad_roots(-4, 1, -6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.125, r1, 1e-07);
  ASSERT_NEAR(1.21834929310112, r2, 1e-07);

  num_roots = quad_roots(4, 0, -6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.22474487139159, r1, 1e-07);
  ASSERT_NEAR(-1.22474487139159, r2, 1e-07);

  num_roots = quad_roots(2, 0, -6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.73205080756888, r1, 1e-07);
  ASSERT_NEAR(-1.73205080756888, r2, 1e-07);

  num_roots = quad_roots(0, 0, -6, &r1, &r2);
  ASSERT_EQ(-3, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(0, r2, 1e-07);

  num_roots = quad_roots(-2, 0, -6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(1.73205080756888, r2, 1e-07);

  num_roots = quad_roots(-4, 0, -6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(1.22474487139159, r2, 1e-07);

  num_roots = quad_roots(4, -1, -6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.35610722522451, r1, 1e-07);
  ASSERT_NEAR(-1.10610722522451, r2, 1e-07);

  num_roots = quad_roots(2, -1, -6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r1, 1e-07);
  ASSERT_NEAR(-1.5, r2, 1e-07);

  num_roots = quad_roots(0, -1, -6, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-6, r2, 1e-07);

  num_roots = quad_roots(-2, -1, -6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.25, r1, 1e-07);
  ASSERT_NEAR(1.71391365010026, r2, 1e-07);

  num_roots = quad_roots(-4, -1, -6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.125, r1, 1e-07);
  ASSERT_NEAR(1.21834929310112, r2, 1e-07);

  num_roots = quad_roots(4, -2, -6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5, r1, 1e-07);
  ASSERT_NEAR(-1, r2, 1e-07);

  num_roots = quad_roots(2, -2, -6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.30277563773199, r1, 1e-07);
  ASSERT_NEAR(-1.30277563773199, r2, 1e-07);

  num_roots = quad_roots(0, -2, -6, &r1, &r2);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r1, 1e-07);
  ASSERT_NEAR(-3, r2, 1e-07);

  num_roots = quad_roots(-2, -2, -6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.5, r1, 1e-07);
  ASSERT_NEAR(1.6583123951777, r2, 1e-07);

  num_roots = quad_roots(-4, -2, -6, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.25, r1, 1e-07);
  ASSERT_NEAR(1.19895788082818, r2, 1e-07);

  num_roots = quad_roots(1e-200, -3.02e-199, 6e-200, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(30, r1, 1e-07);
  ASSERT_NEAR(0.2, r2, 1e-07);

  num_roots = quad_roots(1e-100, -3.02e-99, 6e-100, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(30, r1, 1e-07);
  ASSERT_NEAR(0.2, r2, 1e-07);

  num_roots = quad_roots(1, -30.2, 6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(30, r1, 1e-07);
  ASSERT_NEAR(0.2, r2, 1e-07);

  num_roots = quad_roots(1e+100, -3.02e+101, 6e+100, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(30, r1, 1e-07);
  ASSERT_NEAR(0.2, r2, 1e-07);

  num_roots = quad_roots(1e+200, -3.02e+201, 6e+200, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(30, r1, 1e-07);
  ASSERT_NEAR(0.2, r2, 1e-07);

  num_roots = quad_roots(1e-200, 2.98e-199, -6e-200, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.2, r1, 1e-07);
  ASSERT_NEAR(-30, r2, 1e-07);

  num_roots = quad_roots(1e-100, 2.98e-99, -6e-100, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.2, r1, 1e-07);
  ASSERT_NEAR(-30, r2, 1e-07);

  num_roots = quad_roots(1, 29.8, -6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.2, r1, 1e-07);
  ASSERT_NEAR(-30, r2, 1e-07);

  num_roots = quad_roots(1e+100, 2.98e+101, -6e+100, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.2, r1, 1e-07);
  ASSERT_NEAR(-30, r2, 1e-07);

  num_roots = quad_roots(1e+200, 2.98e+201, -6e+200, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.2, r1, 1e-07);
  ASSERT_NEAR(-30, r2, 1e-07);

  num_roots = quad_roots(1e-200, 3.02e-199, 6e-200, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.2, r1, 1e-07);
  ASSERT_NEAR(-30, r2, 1e-07);

  num_roots = quad_roots(1e-100, 3.02e-99, 6e-100, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.2, r1, 1e-07);
  ASSERT_NEAR(-30, r2, 1e-07);

  num_roots = quad_roots(1, 30.2, 6, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.2, r1, 1e-07);
  ASSERT_NEAR(-30, r2, 1e-07);

  num_roots = quad_roots(1e+100, 3.02e+101, 6e+100, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.2, r1, 1e-07);
  ASSERT_NEAR(-30, r2, 1e-07);

  num_roots = quad_roots(1e+200, 3.02e+201, 6e+200, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.2, r1, 1e-07);
  ASSERT_NEAR(-30, r2, 1e-07);

  num_roots = quad_roots(1e-200, -5.0003e-198, 1.5e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r1, 1e-07);
  ASSERT_NEAR(0.03, r2, 1e-07);

  num_roots = quad_roots(1e-100, -5.0003e-98, 1.5e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r1, 1e-07);
  ASSERT_NEAR(0.03, r2, 1e-07);

  num_roots = quad_roots(1, -500.03, 15, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r1, 1e-07);
  ASSERT_NEAR(0.03, r2, 1e-07);

  num_roots = quad_roots(1e+100, -5.0003e+102, 1.5e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r1, 1e-07);
  ASSERT_NEAR(0.03, r2, 1e-07);

  num_roots = quad_roots(1e+200, -5.0003e+202, 1.5e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r1, 1e-07);
  ASSERT_NEAR(0.03, r2, 1e-07);

  num_roots = quad_roots(1e-200, 4.9997e-198, -1.5e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.03, r1, 1e-07);
  ASSERT_NEAR(-500, r2, 1e-07);

  num_roots = quad_roots(1e-100, 4.9997e-98, -1.5e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.03, r1, 1e-07);
  ASSERT_NEAR(-500, r2, 1e-07);

  num_roots = quad_roots(1, 499.97, -15, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.03, r1, 1e-07);
  ASSERT_NEAR(-500, r2, 1e-07);

  num_roots = quad_roots(1e+100, 4.9997e+102, -1.5e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.03, r1, 1e-07);
  ASSERT_NEAR(-500, r2, 1e-07);

  num_roots = quad_roots(1e+200, 4.9997e+202, -1.5e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.03, r1, 1e-07);
  ASSERT_NEAR(-500, r2, 1e-07);

  num_roots = quad_roots(1e-200, 5.0003e-198, 1.5e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.03, r1, 1e-07);
  ASSERT_NEAR(-500, r2, 1e-07);

  num_roots = quad_roots(1e-100, 5.0003e-98, 1.5e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.03, r1, 1e-07);
  ASSERT_NEAR(-500, r2, 1e-07);

  num_roots = quad_roots(1, 500.03, 15, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.03, r1, 1e-07);
  ASSERT_NEAR(-500, r2, 1e-07);

  num_roots = quad_roots(1e+100, 5.0003e+102, 1.5e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.03, r1, 1e-07);
  ASSERT_NEAR(-500, r2, 1e-07);

  num_roots = quad_roots(1e+200, 5.0003e+202, 1.5e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.03, r1, 1e-07);
  ASSERT_NEAR(-500, r2, 1e-07);

  num_roots = quad_roots(1e-200, -7.000004e-197, 2.8e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7000, r1, 1e-07);
  ASSERT_NEAR(0.004, r2, 1e-07);

  num_roots = quad_roots(1e-100, -7.000004e-97, 2.8e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7000, r1, 1e-07);
  ASSERT_NEAR(0.004, r2, 1e-07);

  num_roots = quad_roots(1, -7000.004, 28, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7000, r1, 1e-07);
  ASSERT_NEAR(0.004, r2, 1e-07);

  num_roots = quad_roots(1e+100, -7.000004e+103, 2.8e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7000, r1, 1e-07);
  ASSERT_NEAR(0.004, r2, 1e-07);

  num_roots = quad_roots(1e+200, -7.000004e+203, 2.8e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7000, r1, 1e-07);
  ASSERT_NEAR(0.004, r2, 1e-07);

  num_roots = quad_roots(1e-200, 6.999996e-197, -2.8e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.004, r1, 1e-07);
  ASSERT_NEAR(-7000, r2, 1e-07);

  num_roots = quad_roots(1e-100, 6.999996e-97, -2.8e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.004, r1, 1e-07);
  ASSERT_NEAR(-7000, r2, 1e-07);

  num_roots = quad_roots(1, 6999.996, -28, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.004, r1, 1e-07);
  ASSERT_NEAR(-7000, r2, 1e-07);

  num_roots = quad_roots(1e+100, 6.999996e+103, -2.8e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.004, r1, 1e-07);
  ASSERT_NEAR(-7000, r2, 1e-07);

  num_roots = quad_roots(1e+200, 6.999996e+203, -2.8e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.004, r1, 1e-07);
  ASSERT_NEAR(-7000, r2, 1e-07);

  num_roots = quad_roots(1e-200, 7.000004e-197, 2.8e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.004, r1, 1e-07);
  ASSERT_NEAR(-7000, r2, 1e-07);

  num_roots = quad_roots(1e-100, 7.000004e-97, 2.8e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.004, r1, 1e-07);
  ASSERT_NEAR(-7000, r2, 1e-07);

  num_roots = quad_roots(1, 7000.004, 28, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.004, r1, 1e-07);
  ASSERT_NEAR(-7000, r2, 1e-07);

  num_roots = quad_roots(1e+100, 7.000004e+103, 2.8e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.004, r1, 1e-07);
  ASSERT_NEAR(-7000, r2, 1e-07);

  num_roots = quad_roots(1e+200, 7.000004e+203, 2.8e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.004, r1, 1e-07);
  ASSERT_NEAR(-7000, r2, 1e-07);

  num_roots = quad_roots(1e-200, -9.00000005e-196, 4.5e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(90000, r1, 0.009);
  ASSERT_NEAR(0.0005, r2, 1e-07);

  num_roots = quad_roots(1e-100, -9.00000005e-96, 4.5e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(90000, r1, 0.009);
  ASSERT_NEAR(0.0005, r2, 1e-07);

  num_roots = quad_roots(1, -90000.0005, 45, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(90000, r1, 0.009);
  ASSERT_NEAR(0.0005, r2, 1e-07);

  num_roots = quad_roots(1e+100, -9.00000005e+104, 4.5e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(90000, r1, 0.009);
  ASSERT_NEAR(0.0005, r2, 1e-07);

  num_roots = quad_roots(1e+200, -9.00000005e+204, 4.5e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(90000, r1, 0.009);
  ASSERT_NEAR(0.0005, r2, 1e-07);

  num_roots = quad_roots(1e-200, 8.99999995e-196, -4.5e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0005, r1, 1e-07);
  ASSERT_NEAR(-90000, r2, 0.009);

  num_roots = quad_roots(1e-100, 8.99999995e-96, -4.5e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0005, r1, 1e-07);
  ASSERT_NEAR(-90000, r2, 0.009);

  num_roots = quad_roots(1, 89999.9995, -45, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0005, r1, 1e-07);
  ASSERT_NEAR(-90000, r2, 0.009);

  num_roots = quad_roots(1e+100, 8.99999995e+104, -4.5e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0005, r1, 1e-07);
  ASSERT_NEAR(-90000, r2, 0.009);

  num_roots = quad_roots(1e+200, 8.99999995e+204, -4.5e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0005, r1, 1e-07);
  ASSERT_NEAR(-90000, r2, 0.009);

  num_roots = quad_roots(1e-200, 9.00000005e-196, 4.5e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0005, r1, 1e-07);
  ASSERT_NEAR(-90000, r2, 0.009);

  num_roots = quad_roots(1e-100, 9.00000005e-96, 4.5e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0005, r1, 1e-07);
  ASSERT_NEAR(-90000, r2, 0.009);

  num_roots = quad_roots(1, 90000.0005, 45, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0005, r1, 1e-07);
  ASSERT_NEAR(-90000, r2, 0.009);

  num_roots = quad_roots(1e+100, 9.00000005e+104, 4.5e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0005, r1, 1e-07);
  ASSERT_NEAR(-90000, r2, 0.009);

  num_roots = quad_roots(1e+200, 9.00000005e+204, 4.5e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0005, r1, 1e-07);
  ASSERT_NEAR(-90000, r2, 0.009);

  num_roots = quad_roots(1e-200, -1.10000000006e-194, 6.6e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1100000, r1, 0.11);
  ASSERT_NEAR(6e-05, r2, 1e-07);

  num_roots = quad_roots(1e-100, -1.10000000006e-94, 6.6e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1100000, r1, 0.11);
  ASSERT_NEAR(6e-05, r2, 1e-07);

  num_roots = quad_roots(1, -1100000.00006, 66, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1100000, r1, 0.11);
  ASSERT_NEAR(6e-05, r2, 1e-07);

  num_roots = quad_roots(1e+100, -1.10000000006e+106, 6.6e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1100000, r1, 0.11);
  ASSERT_NEAR(6e-05, r2, 1e-07);

  num_roots = quad_roots(1e+200, -1.10000000006e+206, 6.6e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1100000, r1, 0.11);
  ASSERT_NEAR(6e-05, r2, 1e-07);

  num_roots = quad_roots(1e-200, 1.09999999994e-194, -6.6e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(6e-05, r1, 1e-07);
  ASSERT_NEAR(-1100000, r2, 0.11);

  num_roots = quad_roots(1e-100, 1.09999999994e-94, -6.6e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(6e-05, r1, 1e-07);
  ASSERT_NEAR(-1100000, r2, 0.11);

  num_roots = quad_roots(1, 1099999.99994, -66, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(6e-05, r1, 1e-07);
  ASSERT_NEAR(-1100000, r2, 0.11);

  num_roots = quad_roots(1e+100, 1.09999999994e+106, -6.6e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(6e-05, r1, 1e-07);
  ASSERT_NEAR(-1100000, r2, 0.11);

  num_roots = quad_roots(1e+200, 1.09999999994e+206, -6.6e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(6e-05, r1, 1e-07);
  ASSERT_NEAR(-1100000, r2, 0.11);

  num_roots = quad_roots(1e-200, 1.10000000006e-194, 6.6e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-6e-05, r1, 1e-07);
  ASSERT_NEAR(-1100000, r2, 0.11);

  num_roots = quad_roots(1e-100, 1.10000000006e-94, 6.6e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-6e-05, r1, 1e-07);
  ASSERT_NEAR(-1100000, r2, 0.11);

  num_roots = quad_roots(1, 1100000.00006, 66, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-6e-05, r1, 1e-07);
  ASSERT_NEAR(-1100000, r2, 0.11);

  num_roots = quad_roots(1e+100, 1.10000000006e+106, 6.6e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-6e-05, r1, 1e-07);
  ASSERT_NEAR(-1100000, r2, 0.11);

  num_roots = quad_roots(1e+200, 1.10000000006e+206, 6.6e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-6e-05, r1, 1e-07);
  ASSERT_NEAR(-1100000, r2, 0.11);

  num_roots = quad_roots(1e-200, -1.3000000000007e-193, 9.1e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(13000000, r1, 1.3);
  ASSERT_NEAR(7e-06, r2, 1e-07);

  num_roots = quad_roots(1e-100, -1.3000000000007e-93, 9.1e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(13000000, r1, 1.3);
  ASSERT_NEAR(7e-06, r2, 1e-07);

  num_roots = quad_roots(1, -13000000.000007, 91, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(13000000, r1, 1.3);
  ASSERT_NEAR(7e-06, r2, 1e-07);

  num_roots = quad_roots(1e+100, -1.3000000000007e+107, 9.1e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(13000000, r1, 1.3);
  ASSERT_NEAR(7e-06, r2, 1e-07);

  num_roots = quad_roots(1e+200, -1.3000000000007e+207, 9.1e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(13000000, r1, 1.3);
  ASSERT_NEAR(7e-06, r2, 1e-07);

  num_roots = quad_roots(1e-200, 1.2999999999993e-193, -9.1e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7e-06, r1, 1e-07);
  ASSERT_NEAR(-13000000, r2, 1.3);

  num_roots = quad_roots(1e-100, 1.2999999999993e-93, -9.1e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7e-06, r1, 1e-07);
  ASSERT_NEAR(-13000000, r2, 1.3);

  num_roots = quad_roots(1, 12999999.999993, -91, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7e-06, r1, 1e-07);
  ASSERT_NEAR(-13000000, r2, 1.3);

  num_roots = quad_roots(1e+100, 1.2999999999993e+107, -9.1e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7e-06, r1, 1e-07);
  ASSERT_NEAR(-13000000, r2, 1.3);

  num_roots = quad_roots(1e+200, 1.2999999999993e+207, -9.1e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7e-06, r1, 1e-07);
  ASSERT_NEAR(-13000000, r2, 1.3);

  num_roots = quad_roots(1e-200, 1.3000000000007e-193, 9.1e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-7e-06, r1, 1e-07);
  ASSERT_NEAR(-13000000, r2, 1.3);

  num_roots = quad_roots(1e-100, 1.3000000000007e-93, 9.1e-99, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-7e-06, r1, 1e-07);
  ASSERT_NEAR(-13000000, r2, 1.3);

  num_roots = quad_roots(1, 13000000.000007, 91, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-7e-06, r1, 1e-07);
  ASSERT_NEAR(-13000000, r2, 1.3);

  num_roots = quad_roots(1e+100, 1.3000000000007e+107, 9.1e+101, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-7e-06, r1, 1e-07);
  ASSERT_NEAR(-13000000, r2, 1.3);

  num_roots = quad_roots(1e+200, 1.3000000000007e+207, 9.1e+201, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-7e-06, r1, 1e-07);
  ASSERT_NEAR(-13000000, r2, 1.3);

  num_roots = quad_roots(1e-200, -1.50000000000001e-192, 1.2e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(150000000, r1, 15.0);
  ASSERT_NEAR(8e-07, r2, 1e-07);

  num_roots = quad_roots(1e-100, -1.50000000000001e-92, 1.2e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(150000000, r1, 15.0);
  ASSERT_NEAR(8e-07, r2, 1e-07);

  num_roots = quad_roots(1, -150000000.000001, 120, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(150000000, r1, 15.0);
  ASSERT_NEAR(8e-07, r2, 1e-07);

  num_roots = quad_roots(1e+100, -1.50000000000001e+108, 1.2e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(150000000, r1, 15.0);
  ASSERT_NEAR(8e-07, r2, 1e-07);

  num_roots = quad_roots(1e+200, -1.50000000000001e+208, 1.2e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(150000000, r1, 15.0);
  ASSERT_NEAR(8e-07, r2, 1e-07);

  num_roots = quad_roots(1e-200, 1.49999999999999e-192, -1.2e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(8e-07, r1, 1e-07);
  ASSERT_NEAR(-150000000, r2, 15.0);

  num_roots = quad_roots(1e-100, 1.49999999999999e-92, -1.2e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(8e-07, r1, 1e-07);
  ASSERT_NEAR(-150000000, r2, 15.0);

  num_roots = quad_roots(1, 149999999.999999, -120, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(8e-07, r1, 1e-07);
  ASSERT_NEAR(-150000000, r2, 15.0);

  num_roots = quad_roots(1e+100, 1.49999999999999e+108, -1.2e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(8e-07, r1, 1e-07);
  ASSERT_NEAR(-150000000, r2, 15.0);

  num_roots = quad_roots(1e+200, 1.49999999999999e+208, -1.2e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(8e-07, r1, 1e-07);
  ASSERT_NEAR(-150000000, r2, 15.0);

  num_roots = quad_roots(1e-200, 1.50000000000001e-192, 1.2e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-8e-07, r1, 1e-07);
  ASSERT_NEAR(-150000000, r2, 15.0);

  num_roots = quad_roots(1e-100, 1.50000000000001e-92, 1.2e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-8e-07, r1, 1e-07);
  ASSERT_NEAR(-150000000, r2, 15.0);

  num_roots = quad_roots(1, 150000000.000001, 120, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-8e-07, r1, 1e-07);
  ASSERT_NEAR(-150000000, r2, 15.0);

  num_roots = quad_roots(1e+100, 1.50000000000001e+108, 1.2e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-8e-07, r1, 1e-07);
  ASSERT_NEAR(-150000000, r2, 15.0);

  num_roots = quad_roots(1e+200, 1.50000000000001e+208, 1.2e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-8e-07, r1, 1e-07);
  ASSERT_NEAR(-150000000, r2, 15.0);

  num_roots = quad_roots(1e-200, -1.7e-191, 1.53e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1700000000, r1, 170.0);
  ASSERT_NEAR(9e-08, r2, 1e-07);

  num_roots = quad_roots(1e-100, -1.7e-91, 1.53e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1700000000, r1, 170.0);
  ASSERT_NEAR(9e-08, r2, 1e-07);

  num_roots = quad_roots(1, -1700000000, 153, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1700000000, r1, 170.0);
  ASSERT_NEAR(9e-08, r2, 1e-07);

  num_roots = quad_roots(1e+100, -1.7e+109, 1.53e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1700000000, r1, 170.0);
  ASSERT_NEAR(9e-08, r2, 1e-07);

  num_roots = quad_roots(1e+200, -1.7e+209, 1.53e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1700000000, r1, 170.0);
  ASSERT_NEAR(9e-08, r2, 1e-07);

  num_roots = quad_roots(1e-200, 1.7e-191, -1.53e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9e-08, r1, 1e-07);
  ASSERT_NEAR(-1700000000, r2, 170.0);

  num_roots = quad_roots(1e-100, 1.7e-91, -1.53e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9e-08, r1, 1e-07);
  ASSERT_NEAR(-1700000000, r2, 170.0);

  num_roots = quad_roots(1, 1700000000, -153, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9e-08, r1, 1e-07);
  ASSERT_NEAR(-1700000000, r2, 170.0);

  num_roots = quad_roots(1e+100, 1.7e+109, -1.53e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9e-08, r1, 1e-07);
  ASSERT_NEAR(-1700000000, r2, 170.0);

  num_roots = quad_roots(1e+200, 1.7e+209, -1.53e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9e-08, r1, 1e-07);
  ASSERT_NEAR(-1700000000, r2, 170.0);

  num_roots = quad_roots(1e-200, 1.7e-191, 1.53e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-9e-08, r1, 1e-07);
  ASSERT_NEAR(-1700000000, r2, 170.0);

  num_roots = quad_roots(1e-100, 1.7e-91, 1.53e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-9e-08, r1, 1e-07);
  ASSERT_NEAR(-1700000000, r2, 170.0);

  num_roots = quad_roots(1, 1700000000, 153, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-9e-08, r1, 1e-07);
  ASSERT_NEAR(-1700000000, r2, 170.0);

  num_roots = quad_roots(1e+100, 1.7e+109, 1.53e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-9e-08, r1, 1e-07);
  ASSERT_NEAR(-1700000000, r2, 170.0);

  num_roots = quad_roots(1e+200, 1.7e+209, 1.53e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-9e-08, r1, 1e-07);
  ASSERT_NEAR(-1700000000, r2, 170.0);

  num_roots = quad_roots(1e-200, -1.9e-190, 1.9e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(19000000000, r1, 1900.0);
  ASSERT_NEAR(1e-08, r2, 1e-07);

  num_roots = quad_roots(1e-100, -1.9e-90, 1.9e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(19000000000, r1, 1900.0);
  ASSERT_NEAR(1e-08, r2, 1e-07);

  num_roots = quad_roots(1, -19000000000, 190, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(19000000000, r1, 1900.0);
  ASSERT_NEAR(1e-08, r2, 1e-07);

  num_roots = quad_roots(1e+100, -1.9e+110, 1.9e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(19000000000, r1, 1900.0);
  ASSERT_NEAR(1e-08, r2, 1e-07);

  num_roots = quad_roots(1e+200, -1.9e+210, 1.9e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(19000000000, r1, 1900.0);
  ASSERT_NEAR(1e-08, r2, 1e-07);

  num_roots = quad_roots(1e-200, 1.9e-190, -1.9e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1e-08, r1, 1e-07);
  ASSERT_NEAR(-19000000000, r2, 1900.0);

  num_roots = quad_roots(1e-100, 1.9e-90, -1.9e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1e-08, r1, 1e-07);
  ASSERT_NEAR(-19000000000, r2, 1900.0);

  num_roots = quad_roots(1, 19000000000, -190, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1e-08, r1, 1e-07);
  ASSERT_NEAR(-19000000000, r2, 1900.0);

  num_roots = quad_roots(1e+100, 1.9e+110, -1.9e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1e-08, r1, 1e-07);
  ASSERT_NEAR(-19000000000, r2, 1900.0);

  num_roots = quad_roots(1e+200, 1.9e+210, -1.9e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1e-08, r1, 1e-07);
  ASSERT_NEAR(-19000000000, r2, 1900.0);

  num_roots = quad_roots(1e-200, 1.9e-190, 1.9e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1e-08, r1, 1e-07);
  ASSERT_NEAR(-19000000000, r2, 1900.0);

  num_roots = quad_roots(1e-100, 1.9e-90, 1.9e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1e-08, r1, 1e-07);
  ASSERT_NEAR(-19000000000, r2, 1900.0);

  num_roots = quad_roots(1, 19000000000, 190, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1e-08, r1, 1e-07);
  ASSERT_NEAR(-19000000000, r2, 1900.0);

  num_roots = quad_roots(1e+100, 1.9e+110, 1.9e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1e-08, r1, 1e-07);
  ASSERT_NEAR(-19000000000, r2, 1900.0);

  num_roots = quad_roots(1e+200, 1.9e+210, 1.9e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1e-08, r1, 1e-07);
  ASSERT_NEAR(-19000000000, r2, 1900.0);

  num_roots = quad_roots(1e-200, -2.1e-189, 2.31e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(210000000000, r1, 21000.0);
  ASSERT_NEAR(1.1e-09, r2, 1e-07);

  num_roots = quad_roots(1e-100, -2.1e-89, 2.31e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(210000000000, r1, 21000.0);
  ASSERT_NEAR(1.1e-09, r2, 1e-07);

  num_roots = quad_roots(1, -210000000000, 231, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(210000000000, r1, 21000.0);
  ASSERT_NEAR(1.1e-09, r2, 1e-07);

  num_roots = quad_roots(1e+100, -2.1e+111, 2.31e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(210000000000, r1, 21000.0);
  ASSERT_NEAR(1.1e-09, r2, 1e-07);

  num_roots = quad_roots(1e+200, -2.1e+211, 2.31e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(210000000000, r1, 21000.0);
  ASSERT_NEAR(1.1e-09, r2, 1e-07);

  num_roots = quad_roots(1e-200, 2.1e-189, -2.31e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1e-09, r1, 1e-07);
  ASSERT_NEAR(-210000000000, r2, 21000.0);

  num_roots = quad_roots(1e-100, 2.1e-89, -2.31e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1e-09, r1, 1e-07);
  ASSERT_NEAR(-210000000000, r2, 21000.0);

  num_roots = quad_roots(1, 210000000000, -231, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1e-09, r1, 1e-07);
  ASSERT_NEAR(-210000000000, r2, 21000.0);

  num_roots = quad_roots(1e+100, 2.1e+111, -2.31e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1e-09, r1, 1e-07);
  ASSERT_NEAR(-210000000000, r2, 21000.0);

  num_roots = quad_roots(1e+200, 2.1e+211, -2.31e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1e-09, r1, 1e-07);
  ASSERT_NEAR(-210000000000, r2, 21000.0);

  num_roots = quad_roots(1e-200, 2.1e-189, 2.31e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.1e-09, r1, 1e-07);
  ASSERT_NEAR(-210000000000, r2, 21000.0);

  num_roots = quad_roots(1e-100, 2.1e-89, 2.31e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.1e-09, r1, 1e-07);
  ASSERT_NEAR(-210000000000, r2, 21000.0);

  num_roots = quad_roots(1, 210000000000, 231, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.1e-09, r1, 1e-07);
  ASSERT_NEAR(-210000000000, r2, 21000.0);

  num_roots = quad_roots(1e+100, 2.1e+111, 2.31e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.1e-09, r1, 1e-07);
  ASSERT_NEAR(-210000000000, r2, 21000.0);

  num_roots = quad_roots(1e+200, 2.1e+211, 2.31e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.1e-09, r1, 1e-07);
  ASSERT_NEAR(-210000000000, r2, 21000.0);

  num_roots = quad_roots(1e-200, -2.3e-188, 2.76e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2300000000000, r1, 230000.0);
  ASSERT_NEAR(1.2e-10, r2, 1e-07);

  num_roots = quad_roots(1e-100, -2.3e-88, 2.76e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2300000000000, r1, 230000.0);
  ASSERT_NEAR(1.2e-10, r2, 1e-07);

  num_roots = quad_roots(1, -2300000000000, 276, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2300000000000, r1, 230000.0);
  ASSERT_NEAR(1.2e-10, r2, 1e-07);

  num_roots = quad_roots(1e+100, -2.3e+112, 2.76e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2300000000000, r1, 230000.0);
  ASSERT_NEAR(1.2e-10, r2, 1e-07);

  num_roots = quad_roots(1e+200, -2.3e+212, 2.76e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2300000000000, r1, 230000.0);
  ASSERT_NEAR(1.2e-10, r2, 1e-07);

  num_roots = quad_roots(1e-200, 2.3e-188, -2.76e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.2e-10, r1, 1e-07);
  ASSERT_NEAR(-2300000000000, r2, 230000.0);

  num_roots = quad_roots(1e-100, 2.3e-88, -2.76e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.2e-10, r1, 1e-07);
  ASSERT_NEAR(-2300000000000, r2, 230000.0);

  num_roots = quad_roots(1, 2300000000000, -276, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.2e-10, r1, 1e-07);
  ASSERT_NEAR(-2300000000000, r2, 230000.0);

  num_roots = quad_roots(1e+100, 2.3e+112, -2.76e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.2e-10, r1, 1e-07);
  ASSERT_NEAR(-2300000000000, r2, 230000.0);

  num_roots = quad_roots(1e+200, 2.3e+212, -2.76e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.2e-10, r1, 1e-07);
  ASSERT_NEAR(-2300000000000, r2, 230000.0);

  num_roots = quad_roots(1e-200, 2.3e-188, 2.76e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.2e-10, r1, 1e-07);
  ASSERT_NEAR(-2300000000000, r2, 230000.0);

  num_roots = quad_roots(1e-100, 2.3e-88, 2.76e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.2e-10, r1, 1e-07);
  ASSERT_NEAR(-2300000000000, r2, 230000.0);

  num_roots = quad_roots(1, 2300000000000, 276, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.2e-10, r1, 1e-07);
  ASSERT_NEAR(-2300000000000, r2, 230000.0);

  num_roots = quad_roots(1e+100, 2.3e+112, 2.76e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.2e-10, r1, 1e-07);
  ASSERT_NEAR(-2300000000000, r2, 230000.0);

  num_roots = quad_roots(1e+200, 2.3e+212, 2.76e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.2e-10, r1, 1e-07);
  ASSERT_NEAR(-2300000000000, r2, 230000.0);

  num_roots = quad_roots(1e-200, -2.5e-187, 3.25e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(25000000000000, r1, 2500000.0);
  ASSERT_NEAR(1.3e-11, r2, 1e-07);

  num_roots = quad_roots(1e-100, -2.5e-87, 3.25e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(25000000000000, r1, 2500000.0);
  ASSERT_NEAR(1.3e-11, r2, 1e-07);

  num_roots = quad_roots(1, -25000000000000, 325, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(25000000000000, r1, 2500000.0);
  ASSERT_NEAR(1.3e-11, r2, 1e-07);

  num_roots = quad_roots(1e+100, -2.5e+113, 3.25e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(25000000000000, r1, 2500000.0);
  ASSERT_NEAR(1.3e-11, r2, 1e-07);

  num_roots = quad_roots(1e+200, -2.5e+213, 3.25e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(25000000000000, r1, 2500000.0);
  ASSERT_NEAR(1.3e-11, r2, 1e-07);

  num_roots = quad_roots(1e-200, 2.5e-187, -3.25e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.3e-11, r1, 1e-07);
  ASSERT_NEAR(-25000000000000, r2, 2500000.0);

  num_roots = quad_roots(1e-100, 2.5e-87, -3.25e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.3e-11, r1, 1e-07);
  ASSERT_NEAR(-25000000000000, r2, 2500000.0);

  num_roots = quad_roots(1, 25000000000000, -325, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.3e-11, r1, 1e-07);
  ASSERT_NEAR(-25000000000000, r2, 2500000.0);

  num_roots = quad_roots(1e+100, 2.5e+113, -3.25e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.3e-11, r1, 1e-07);
  ASSERT_NEAR(-25000000000000, r2, 2500000.0);

  num_roots = quad_roots(1e+200, 2.5e+213, -3.25e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.3e-11, r1, 1e-07);
  ASSERT_NEAR(-25000000000000, r2, 2500000.0);

  num_roots = quad_roots(1e-200, 2.5e-187, 3.25e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.3e-11, r1, 1e-07);
  ASSERT_NEAR(-25000000000000, r2, 2500000.0);

  num_roots = quad_roots(1e-100, 2.5e-87, 3.25e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.3e-11, r1, 1e-07);
  ASSERT_NEAR(-25000000000000, r2, 2500000.0);

  num_roots = quad_roots(1, 25000000000000, 325, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.3e-11, r1, 1e-07);
  ASSERT_NEAR(-25000000000000, r2, 2500000.0);

  num_roots = quad_roots(1e+100, 2.5e+113, 3.25e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.3e-11, r1, 1e-07);
  ASSERT_NEAR(-25000000000000, r2, 2500000.0);

  num_roots = quad_roots(1e+200, 2.5e+213, 3.25e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.3e-11, r1, 1e-07);
  ASSERT_NEAR(-25000000000000, r2, 2500000.0);

  num_roots = quad_roots(1e-200, -2.7e-186, 3.78e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(270000000000000, r1, 27000000.0);
  ASSERT_NEAR(1.4e-12, r2, 1e-07);

  num_roots = quad_roots(1e-100, -2.7e-86, 3.78e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(270000000000000, r1, 27000000.0);
  ASSERT_NEAR(1.4e-12, r2, 1e-07);

  num_roots = quad_roots(1, -270000000000000, 378, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(270000000000000, r1, 27000000.0);
  ASSERT_NEAR(1.4e-12, r2, 1e-07);

  num_roots = quad_roots(1e+100, -2.7e+114, 3.78e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(270000000000000, r1, 27000000.0);
  ASSERT_NEAR(1.4e-12, r2, 1e-07);

  num_roots = quad_roots(1e+200, -2.7e+214, 3.78e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(270000000000000, r1, 27000000.0);
  ASSERT_NEAR(1.4e-12, r2, 1e-07);

  num_roots = quad_roots(1e-200, 2.7e-186, -3.78e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.4e-12, r1, 1e-07);
  ASSERT_NEAR(-270000000000000, r2, 27000000.0);

  num_roots = quad_roots(1e-100, 2.7e-86, -3.78e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.4e-12, r1, 1e-07);
  ASSERT_NEAR(-270000000000000, r2, 27000000.0);

  num_roots = quad_roots(1, 270000000000000, -378, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.4e-12, r1, 1e-07);
  ASSERT_NEAR(-270000000000000, r2, 27000000.0);

  num_roots = quad_roots(1e+100, 2.7e+114, -3.78e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.4e-12, r1, 1e-07);
  ASSERT_NEAR(-270000000000000, r2, 27000000.0);

  num_roots = quad_roots(1e+200, 2.7e+214, -3.78e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.4e-12, r1, 1e-07);
  ASSERT_NEAR(-270000000000000, r2, 27000000.0);

  num_roots = quad_roots(1e-200, 2.7e-186, 3.78e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.4e-12, r1, 1e-07);
  ASSERT_NEAR(-270000000000000, r2, 27000000.0);

  num_roots = quad_roots(1e-100, 2.7e-86, 3.78e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.4e-12, r1, 1e-07);
  ASSERT_NEAR(-270000000000000, r2, 27000000.0);

  num_roots = quad_roots(1, 270000000000000, 378, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.4e-12, r1, 1e-07);
  ASSERT_NEAR(-270000000000000, r2, 27000000.0);

  num_roots = quad_roots(1e+100, 2.7e+114, 3.78e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.4e-12, r1, 1e-07);
  ASSERT_NEAR(-270000000000000, r2, 27000000.0);

  num_roots = quad_roots(1e+200, 2.7e+214, 3.78e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.4e-12, r1, 1e-07);
  ASSERT_NEAR(-270000000000000, r2, 27000000.0);

  num_roots = quad_roots(1e-200, -2.9e-185, 4.35e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.9e+15, r1, 290000000.0);
  ASSERT_NEAR(1.5e-13, r2, 1e-07);

  num_roots = quad_roots(1e-100, -2.9e-85, 4.35e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.9e+15, r1, 290000000.0);
  ASSERT_NEAR(1.5e-13, r2, 1e-07);

  num_roots = quad_roots(1, -2.9e+15, 435, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.9e+15, r1, 290000000.0);
  ASSERT_NEAR(1.5e-13, r2, 1e-07);

  num_roots = quad_roots(1e+100, -2.9e+115, 4.35e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.9e+15, r1, 290000000.0);
  ASSERT_NEAR(1.5e-13, r2, 1e-07);

  num_roots = quad_roots(1e+200, -2.9e+215, 4.35e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.9e+15, r1, 290000000.0);
  ASSERT_NEAR(1.5e-13, r2, 1e-07);

  num_roots = quad_roots(1e-200, 2.9e-185, -4.35e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5e-13, r1, 1e-07);
  ASSERT_NEAR(-2.9e+15, r2, 290000000.0);

  num_roots = quad_roots(1e-100, 2.9e-85, -4.35e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5e-13, r1, 1e-07);
  ASSERT_NEAR(-2.9e+15, r2, 290000000.0);

  num_roots = quad_roots(1, 2.9e+15, -435, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5e-13, r1, 1e-07);
  ASSERT_NEAR(-2.9e+15, r2, 290000000.0);

  num_roots = quad_roots(1e+100, 2.9e+115, -4.35e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5e-13, r1, 1e-07);
  ASSERT_NEAR(-2.9e+15, r2, 290000000.0);

  num_roots = quad_roots(1e+200, 2.9e+215, -4.35e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5e-13, r1, 1e-07);
  ASSERT_NEAR(-2.9e+15, r2, 290000000.0);

  num_roots = quad_roots(1e-200, 2.9e-185, 4.35e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.5e-13, r1, 1e-07);
  ASSERT_NEAR(-2.9e+15, r2, 290000000.0);

  num_roots = quad_roots(1e-100, 2.9e-85, 4.35e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.5e-13, r1, 1e-07);
  ASSERT_NEAR(-2.9e+15, r2, 290000000.0);

  num_roots = quad_roots(1, 2.9e+15, 435, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.5e-13, r1, 1e-07);
  ASSERT_NEAR(-2.9e+15, r2, 290000000.0);

  num_roots = quad_roots(1e+100, 2.9e+115, 4.35e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.5e-13, r1, 1e-07);
  ASSERT_NEAR(-2.9e+15, r2, 290000000.0);

  num_roots = quad_roots(1e+200, 2.9e+215, 4.35e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.5e-13, r1, 1e-07);
  ASSERT_NEAR(-2.9e+15, r2, 290000000.0);

  num_roots = quad_roots(1e-200, -3.1e-184, 4.96e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.1e+16, r1, 3100000000.0);
  ASSERT_NEAR(1.6e-14, r2, 1e-07);

  num_roots = quad_roots(1e-100, -3.1e-84, 4.96e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.1e+16, r1, 3100000000.0);
  ASSERT_NEAR(1.6e-14, r2, 1e-07);

  num_roots = quad_roots(1, -3.1e+16, 496, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.1e+16, r1, 3100000000.0);
  ASSERT_NEAR(1.6e-14, r2, 1e-07);

  num_roots = quad_roots(1e+100, -3.1e+116, 4.96e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.1e+16, r1, 3100000000.0);
  ASSERT_NEAR(1.6e-14, r2, 1e-07);

  num_roots = quad_roots(1e+200, -3.1e+216, 4.96e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.1e+16, r1, 3100000000.0);
  ASSERT_NEAR(1.6e-14, r2, 1e-07);

  num_roots = quad_roots(1e-200, 3.1e-184, -4.96e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.6e-14, r1, 1e-07);
  ASSERT_NEAR(-3.1e+16, r2, 3100000000.0);

  num_roots = quad_roots(1e-100, 3.1e-84, -4.96e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.6e-14, r1, 1e-07);
  ASSERT_NEAR(-3.1e+16, r2, 3100000000.0);

  num_roots = quad_roots(1, 3.1e+16, -496, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.6e-14, r1, 1e-07);
  ASSERT_NEAR(-3.1e+16, r2, 3100000000.0);

  num_roots = quad_roots(1e+100, 3.1e+116, -4.96e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.6e-14, r1, 1e-07);
  ASSERT_NEAR(-3.1e+16, r2, 3100000000.0);

  num_roots = quad_roots(1e+200, 3.1e+216, -4.96e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.6e-14, r1, 1e-07);
  ASSERT_NEAR(-3.1e+16, r2, 3100000000.0);

  num_roots = quad_roots(1e-200, 3.1e-184, 4.96e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.6e-14, r1, 1e-07);
  ASSERT_NEAR(-3.1e+16, r2, 3100000000.0);

  num_roots = quad_roots(1e-100, 3.1e-84, 4.96e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.6e-14, r1, 1e-07);
  ASSERT_NEAR(-3.1e+16, r2, 3100000000.0);

  num_roots = quad_roots(1, 3.1e+16, 496, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.6e-14, r1, 1e-07);
  ASSERT_NEAR(-3.1e+16, r2, 3100000000.0);

  num_roots = quad_roots(1e+100, 3.1e+116, 4.96e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.6e-14, r1, 1e-07);
  ASSERT_NEAR(-3.1e+16, r2, 3100000000.0);

  num_roots = quad_roots(1e+200, 3.1e+216, 4.96e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.6e-14, r1, 1e-07);
  ASSERT_NEAR(-3.1e+16, r2, 3100000000.0);

  num_roots = quad_roots(1e-200, -3.3e-183, 5.61e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.3e+17, r1, 33000000000.0);
  ASSERT_NEAR(1.7e-15, r2, 1e-07);

  num_roots = quad_roots(1e-100, -3.3e-83, 5.61e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.3e+17, r1, 33000000000.0);
  ASSERT_NEAR(1.7e-15, r2, 1e-07);

  num_roots = quad_roots(1, -3.3e+17, 561, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.3e+17, r1, 33000000000.0);
  ASSERT_NEAR(1.7e-15, r2, 1e-07);

  num_roots = quad_roots(1e+100, -3.3e+117, 5.61e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.3e+17, r1, 33000000000.0);
  ASSERT_NEAR(1.7e-15, r2, 1e-07);

  num_roots = quad_roots(1e+200, -3.3e+217, 5.61e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.3e+17, r1, 33000000000.0);
  ASSERT_NEAR(1.7e-15, r2, 1e-07);

  num_roots = quad_roots(1e-200, 3.3e-183, -5.61e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.7e-15, r1, 1e-07);
  ASSERT_NEAR(-3.3e+17, r2, 33000000000.0);

  num_roots = quad_roots(1e-100, 3.3e-83, -5.61e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.7e-15, r1, 1e-07);
  ASSERT_NEAR(-3.3e+17, r2, 33000000000.0);

  num_roots = quad_roots(1, 3.3e+17, -561, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.7e-15, r1, 1e-07);
  ASSERT_NEAR(-3.3e+17, r2, 33000000000.0);

  num_roots = quad_roots(1e+100, 3.3e+117, -5.61e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.7e-15, r1, 1e-07);
  ASSERT_NEAR(-3.3e+17, r2, 33000000000.0);

  num_roots = quad_roots(1e+200, 3.3e+217, -5.61e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.7e-15, r1, 1e-07);
  ASSERT_NEAR(-3.3e+17, r2, 33000000000.0);

  num_roots = quad_roots(1e-200, 3.3e-183, 5.61e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.7e-15, r1, 1e-07);
  ASSERT_NEAR(-3.3e+17, r2, 33000000000.0);

  num_roots = quad_roots(1e-100, 3.3e-83, 5.61e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.7e-15, r1, 1e-07);
  ASSERT_NEAR(-3.3e+17, r2, 33000000000.0);

  num_roots = quad_roots(1, 3.3e+17, 561, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.7e-15, r1, 1e-07);
  ASSERT_NEAR(-3.3e+17, r2, 33000000000.0);

  num_roots = quad_roots(1e+100, 3.3e+117, 5.61e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.7e-15, r1, 1e-07);
  ASSERT_NEAR(-3.3e+17, r2, 33000000000.0);

  num_roots = quad_roots(1e+200, 3.3e+217, 5.61e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.7e-15, r1, 1e-07);
  ASSERT_NEAR(-3.3e+17, r2, 33000000000.0);

  num_roots = quad_roots(1e-200, -3.5e-182, 6.3e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.5e+18, r1, 3.5e+11);
  ASSERT_NEAR(1.8e-16, r2, 1e-07);

  num_roots = quad_roots(1e-100, -3.5e-82, 6.3e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.5e+18, r1, 3.5e+11);
  ASSERT_NEAR(1.8e-16, r2, 1e-07);

  num_roots = quad_roots(1, -3.5e+18, 630, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.5e+18, r1, 3.5e+11);
  ASSERT_NEAR(1.8e-16, r2, 1e-07);

  num_roots = quad_roots(1e+100, -3.5e+118, 6.3e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.5e+18, r1, 3.5e+11);
  ASSERT_NEAR(1.8e-16, r2, 1e-07);

  num_roots = quad_roots(1e+200, -3.5e+218, 6.3e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.5e+18, r1, 3.5e+11);
  ASSERT_NEAR(1.8e-16, r2, 1e-07);

  num_roots = quad_roots(1e-200, 3.5e-182, -6.3e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.8e-16, r1, 1e-07);
  ASSERT_NEAR(-3.5e+18, r2, 3.5e+11);

  num_roots = quad_roots(1e-100, 3.5e-82, -6.3e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.8e-16, r1, 1e-07);
  ASSERT_NEAR(-3.5e+18, r2, 3.5e+11);

  num_roots = quad_roots(1, 3.5e+18, -630, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.8e-16, r1, 1e-07);
  ASSERT_NEAR(-3.5e+18, r2, 3.5e+11);

  num_roots = quad_roots(1e+100, 3.5e+118, -6.3e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.8e-16, r1, 1e-07);
  ASSERT_NEAR(-3.5e+18, r2, 3.5e+11);

  num_roots = quad_roots(1e+200, 3.5e+218, -6.3e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.8e-16, r1, 1e-07);
  ASSERT_NEAR(-3.5e+18, r2, 3.5e+11);

  num_roots = quad_roots(1e-200, 3.5e-182, 6.3e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.8e-16, r1, 1e-07);
  ASSERT_NEAR(-3.5e+18, r2, 3.5e+11);

  num_roots = quad_roots(1e-100, 3.5e-82, 6.3e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.8e-16, r1, 1e-07);
  ASSERT_NEAR(-3.5e+18, r2, 3.5e+11);

  num_roots = quad_roots(1, 3.5e+18, 630, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.8e-16, r1, 1e-07);
  ASSERT_NEAR(-3.5e+18, r2, 3.5e+11);

  num_roots = quad_roots(1e+100, 3.5e+118, 6.3e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.8e-16, r1, 1e-07);
  ASSERT_NEAR(-3.5e+18, r2, 3.5e+11);

  num_roots = quad_roots(1e+200, 3.5e+218, 6.3e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.8e-16, r1, 1e-07);
  ASSERT_NEAR(-3.5e+18, r2, 3.5e+11);

  num_roots = quad_roots(1e-200, -3.7e-181, 7.03e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.7e+19, r1, 3.7e+12);
  ASSERT_NEAR(1.9e-17, r2, 1e-07);

  num_roots = quad_roots(1e-100, -3.7e-81, 7.03e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.7e+19, r1, 3.7e+12);
  ASSERT_NEAR(1.9e-17, r2, 1e-07);

  num_roots = quad_roots(1, -3.7e+19, 703, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.7e+19, r1, 3.7e+12);
  ASSERT_NEAR(1.9e-17, r2, 1e-07);

  num_roots = quad_roots(1e+100, -3.7e+119, 7.03e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.7e+19, r1, 3.7e+12);
  ASSERT_NEAR(1.9e-17, r2, 1e-07);

  num_roots = quad_roots(1e+200, -3.7e+219, 7.03e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.7e+19, r1, 3.7e+12);
  ASSERT_NEAR(1.9e-17, r2, 1e-07);

  num_roots = quad_roots(1e-200, 3.7e-181, -7.03e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.9e-17, r1, 1e-07);
  ASSERT_NEAR(-3.7e+19, r2, 3.7e+12);

  num_roots = quad_roots(1e-100, 3.7e-81, -7.03e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.9e-17, r1, 1e-07);
  ASSERT_NEAR(-3.7e+19, r2, 3.7e+12);

  num_roots = quad_roots(1, 3.7e+19, -703, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.9e-17, r1, 1e-07);
  ASSERT_NEAR(-3.7e+19, r2, 3.7e+12);

  num_roots = quad_roots(1e+100, 3.7e+119, -7.03e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.9e-17, r1, 1e-07);
  ASSERT_NEAR(-3.7e+19, r2, 3.7e+12);

  num_roots = quad_roots(1e+200, 3.7e+219, -7.03e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.9e-17, r1, 1e-07);
  ASSERT_NEAR(-3.7e+19, r2, 3.7e+12);

  num_roots = quad_roots(1e-200, 3.7e-181, 7.03e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.9e-17, r1, 1e-07);
  ASSERT_NEAR(-3.7e+19, r2, 3.7e+12);

  num_roots = quad_roots(1e-100, 3.7e-81, 7.03e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.9e-17, r1, 1e-07);
  ASSERT_NEAR(-3.7e+19, r2, 3.7e+12);

  num_roots = quad_roots(1, 3.7e+19, 703, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.9e-17, r1, 1e-07);
  ASSERT_NEAR(-3.7e+19, r2, 3.7e+12);

  num_roots = quad_roots(1e+100, 3.7e+119, 7.03e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.9e-17, r1, 1e-07);
  ASSERT_NEAR(-3.7e+19, r2, 3.7e+12);

  num_roots = quad_roots(1e+200, 3.7e+219, 7.03e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.9e-17, r1, 1e-07);
  ASSERT_NEAR(-3.7e+19, r2, 3.7e+12);

  num_roots = quad_roots(1e-200, -3.9e-180, 7.8e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.9e+20, r1, 3.9e+13);
  ASSERT_NEAR(2e-18, r2, 1e-07);

  num_roots = quad_roots(1e-100, -3.9e-80, 7.8e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.9e+20, r1, 3.9e+13);
  ASSERT_NEAR(2e-18, r2, 1e-07);

  num_roots = quad_roots(1, -3.9e+20, 780, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.9e+20, r1, 3.9e+13);
  ASSERT_NEAR(2e-18, r2, 1e-07);

  num_roots = quad_roots(1e+100, -3.9e+120, 7.8e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.9e+20, r1, 3.9e+13);
  ASSERT_NEAR(2e-18, r2, 1e-07);

  num_roots = quad_roots(1e+200, -3.9e+220, 7.8e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.9e+20, r1, 3.9e+13);
  ASSERT_NEAR(2e-18, r2, 1e-07);

  num_roots = quad_roots(1e-200, 3.9e-180, -7.8e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2e-18, r1, 1e-07);
  ASSERT_NEAR(-3.9e+20, r2, 3.9e+13);

  num_roots = quad_roots(1e-100, 3.9e-80, -7.8e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2e-18, r1, 1e-07);
  ASSERT_NEAR(-3.9e+20, r2, 3.9e+13);

  num_roots = quad_roots(1, 3.9e+20, -780, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2e-18, r1, 1e-07);
  ASSERT_NEAR(-3.9e+20, r2, 3.9e+13);

  num_roots = quad_roots(1e+100, 3.9e+120, -7.8e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2e-18, r1, 1e-07);
  ASSERT_NEAR(-3.9e+20, r2, 3.9e+13);

  num_roots = quad_roots(1e+200, 3.9e+220, -7.8e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2e-18, r1, 1e-07);
  ASSERT_NEAR(-3.9e+20, r2, 3.9e+13);

  num_roots = quad_roots(1e-200, 3.9e-180, 7.8e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2e-18, r1, 1e-07);
  ASSERT_NEAR(-3.9e+20, r2, 3.9e+13);

  num_roots = quad_roots(1e-100, 3.9e-80, 7.8e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2e-18, r1, 1e-07);
  ASSERT_NEAR(-3.9e+20, r2, 3.9e+13);

  num_roots = quad_roots(1, 3.9e+20, 780, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2e-18, r1, 1e-07);
  ASSERT_NEAR(-3.9e+20, r2, 3.9e+13);

  num_roots = quad_roots(1e+100, 3.9e+120, 7.8e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2e-18, r1, 1e-07);
  ASSERT_NEAR(-3.9e+20, r2, 3.9e+13);

  num_roots = quad_roots(1e+200, 3.9e+220, 7.8e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2e-18, r1, 1e-07);
  ASSERT_NEAR(-3.9e+20, r2, 3.9e+13);

  num_roots = quad_roots(1e-200, -4.1e-179, 8.61e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.1e+21, r1, 4.1e+14);
  ASSERT_NEAR(2.1e-19, r2, 1e-07);

  num_roots = quad_roots(1e-100, -4.1e-79, 8.61e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.1e+21, r1, 4.1e+14);
  ASSERT_NEAR(2.1e-19, r2, 1e-07);

  num_roots = quad_roots(1, -4.1e+21, 861, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.1e+21, r1, 4.1e+14);
  ASSERT_NEAR(2.1e-19, r2, 1e-07);

  num_roots = quad_roots(1e+100, -4.1e+121, 8.61e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.1e+21, r1, 4.1e+14);
  ASSERT_NEAR(2.1e-19, r2, 1e-07);

  num_roots = quad_roots(1e+200, -4.1e+221, 8.61e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.1e+21, r1, 4.1e+14);
  ASSERT_NEAR(2.1e-19, r2, 1e-07);

  num_roots = quad_roots(1e-200, 4.1e-179, -8.61e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.1e-19, r1, 1e-07);
  ASSERT_NEAR(-4.1e+21, r2, 4.1e+14);

  num_roots = quad_roots(1e-100, 4.1e-79, -8.61e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.1e-19, r1, 1e-07);
  ASSERT_NEAR(-4.1e+21, r2, 4.1e+14);

  num_roots = quad_roots(1, 4.1e+21, -861, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.1e-19, r1, 1e-07);
  ASSERT_NEAR(-4.1e+21, r2, 4.1e+14);

  num_roots = quad_roots(1e+100, 4.1e+121, -8.61e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.1e-19, r1, 1e-07);
  ASSERT_NEAR(-4.1e+21, r2, 4.1e+14);

  num_roots = quad_roots(1e+200, 4.1e+221, -8.61e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.1e-19, r1, 1e-07);
  ASSERT_NEAR(-4.1e+21, r2, 4.1e+14);

  num_roots = quad_roots(1e-200, 4.1e-179, 8.61e-198, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2.1e-19, r1, 1e-07);
  ASSERT_NEAR(-4.1e+21, r2, 4.1e+14);

  num_roots = quad_roots(1e-100, 4.1e-79, 8.61e-98, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2.1e-19, r1, 1e-07);
  ASSERT_NEAR(-4.1e+21, r2, 4.1e+14);

  num_roots = quad_roots(1, 4.1e+21, 861, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2.1e-19, r1, 1e-07);
  ASSERT_NEAR(-4.1e+21, r2, 4.1e+14);

  num_roots = quad_roots(1e+100, 4.1e+121, 8.61e+102, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2.1e-19, r1, 1e-07);
  ASSERT_NEAR(-4.1e+21, r2, 4.1e+14);

  num_roots = quad_roots(1e+200, 4.1e+221, 8.61e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2.1e-19, r1, 1e-07);
  ASSERT_NEAR(-4.1e+21, r2, 4.1e+14);

  num_roots = quad_roots(1e-300, 1e-300, 1e-300, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.5, r1, 1e-07);
  ASSERT_NEAR(0.866025403784439, r2, 1e-07);

  num_roots = quad_roots(1, 1e+200, 1, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1e-200, r1, 1e-07);
  ASSERT_NEAR(-1e+200, r2, 1e+193);

  num_roots = quad_roots(1e+75, 1e+155, 2e+90, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2e-65, r1, 1e-07);
  ASSERT_NEAR(-1e+80, r2, 1e+73);

  num_roots = quad_roots(1e-200, -30, 2.09e+202, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.9e+201, r1, 1.9e+194);
  ASSERT_NEAR(1.1e+201, r2, 1.1e+194);

  num_roots = quad_roots(1, -1.1e+201, 33, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1e+201, r1, 1.1e+194);
  ASSERT_NEAR(3e-200, r2, 1e-07);

  num_roots = quad_roots(1e-200, -11, 3.3e-199, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1e+201, r1, 1.1e+194);
  ASSERT_NEAR(3e-200, r2, 1e-07);

  num_roots = quad_roots(1e+300, -3e+300, 2e+300, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r1, 1e-07);
  ASSERT_NEAR(1, r2, 1e-07);

  num_roots = quad_roots(1e-300, -3e-300, 2e-300, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r1, 1e-07);
  ASSERT_NEAR(1, r2, 1e-07);

  num_roots = quad_roots(3, 1000000000, 5, &r1, &r2);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-5e-09, r1, 1e-07);
  ASSERT_NEAR(-333333333.333333, r2, 33.3333333333);

  num_roots = quad_roots(1e+307, 4e+307, 4e+307, &r1, &r2);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(-2, r1, 1e-07);
  ASSERT_NEAR(-2, r2, 1e-07);

  num_roots = quad_roots(-1e-307, 3e-307, -5e-307, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1.5, r1, 1e-07);
  ASSERT_NEAR(1.6583123951777, r2, 1e-07);

  num_roots = quad_roots(-3.445234324e+300, -2.2355438452e+300, -4.243558408525e+303, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.324440028596441, r1, 1e-07);
  ASSERT_NEAR(35.0943458330746, r2, 1e-07);

  num_roots = quad_roots(3.445234324e+305, 2.2355438452e+304, 4.243558408525e+303, &r1, &r2);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.0324440028596441, r1, 1e-07);
  ASSERT_NEAR(0.106134680412575, r2, 1e-07);
}
