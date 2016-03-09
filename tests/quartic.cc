#include <gtest/gtest.h>

extern "C" {
int rquartic_roots(double *a, double *r);
}

TEST(QuarticRootTest, Test_1) {
  double r[5];
  double a[] = {24, -22, -7, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(2.0, r[1], 2e-06);
  ASSERT_NEAR(1.0, r[2], 1e-06);
  ASSERT_NEAR(-3.0, r[3], 3e-06);
  ASSERT_NEAR(-4.0, r[4], 4e-06);
}

TEST(QuarticRootTest, Test_2) {
  double r[5];
  double a[] = {4, -12, 13, -6};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(2.0, r[1], 2e-06);
  ASSERT_NEAR(2.0, r[2], 2e-06);
  ASSERT_NEAR(1.0, r[3], 1e-06);
  ASSERT_NEAR(1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_3) {
  double r[5];
  double a[] = {8, -20, 18, -7};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(2.0, r[1], 2e-06);
  ASSERT_NEAR(2.0, r[2], 2e-06);
  ASSERT_NEAR(2.0, r[3], 2e-06);
  ASSERT_NEAR(1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_4) {
  double r[5];
  double a[] = {16, -32, 24, -8};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(2.0, r[1], 2e-06);
  ASSERT_NEAR(2.0, r[2], 2e-06);
  ASSERT_NEAR(2.0, r[3], 2e-06);
  ASSERT_NEAR(2.0, r[4], 2e-06);
}

TEST(QuarticRootTest, Test_5) {
  double r[5];
  double a[] = {0, -15, 23, -9};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(5.0, r[1], 5e-06);
  ASSERT_NEAR(3.0, r[2], 3e-06);
  ASSERT_NEAR(1.0, r[3], 1e-06);
  ASSERT_NEAR(0.0, r[4], 0.0);
}

TEST(QuarticRootTest, Test_6) {
  double r[5];
  double a[] = {-16, 0, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.0, r[1], 2e-06);
  ASSERT_NEAR(-2.0, r[2], 2e-06);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(2.0, r[4], 2e-06);
}

TEST(QuarticRootTest, Test_7) {
  double r[5];
  double a[] = {64, 0, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2.0, r[1], 2e-06);
  ASSERT_NEAR(2.0, r[2], 2e-06);
  ASSERT_NEAR(-2.0, r[3], 2e-06);
  ASSERT_NEAR(2.0, r[4], 2e-06);
}

TEST(QuarticRootTest, Test_8) {
  double r[5];
  double a[] = {-1, 0, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.0, r[1], 1e-06);
  ASSERT_NEAR(-1.0, r[2], 1e-06);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_9) {
  double r[5];
  double a[] = {1, 0, 2, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(1.0, r[2], 1e-06);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_10) {
  double r[5];
  double a[] = {1, 0, -2, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1.0, r[1], 1e-06);
  ASSERT_NEAR(1.0, r[2], 1e-06);
  ASSERT_NEAR(-1.0, r[3], 1e-06);
  ASSERT_NEAR(-1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_11) {
  double r[5];
  double a[] = {-1, 0, -2, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.553774, r[1], 1.553774e-06);
  ASSERT_NEAR(-1.553774, r[2], 1.553774e-06);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(0.6435943, r[4], 6.435943e-07);
}

TEST(QuarticRootTest, Test_12) {
  double r[5];
  double a[] = {24, -14, -13, 2};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(3.0, r[1], 3e-06);
  ASSERT_NEAR(1.0, r[2], 1e-06);
  ASSERT_NEAR(-2.0, r[3], 2e-06);
  ASSERT_NEAR(-4.0, r[4], 4e-06);
}

TEST(QuarticRootTest, Test_13) {
  double r[5];
  double a[] = {0, 0, 0, 2};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(-2.0, r[4], 2e-06);
}

TEST(QuarticRootTest, Test_14) {
  double r[5];
  double a[] = {0, 0, 0, -2};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(2.0, r[1], 2e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(0.0, r[4], 0.0);
}

TEST(QuarticRootTest, Test_15) {
  double r[5];
  double a[] = {0, 0, -4, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(2.0, r[1], 2e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(-2.0, r[4], 2e-06);
}

TEST(QuarticRootTest, Test_16) {
  double r[5];
  double a[] = {0, 0, 4, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(2.0, r[4], 2e-06);
}

TEST(QuarticRootTest, Test_17) {
  double r[5];
  double a[] = {0, 8, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(-2.0, r[2], 2e-06);
  ASSERT_NEAR(1.0, r[3], 1e-06);
  ASSERT_NEAR(1.732050808, r[4], 1.732051e-06);
}

TEST(QuarticRootTest, Test_18) {
  double r[5];
  double a[] = {0, -8, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.0, r[1], 2e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(-1.0, r[3], 1e-06);
  ASSERT_NEAR(1.732050808, r[4], 1.732051e-06);
}

TEST(QuarticRootTest, Test_19) {
  double r[5];
  double a[] = {1, 0, -10, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(3.14626436994197, r[1], 3.146264e-06);
  ASSERT_NEAR(0.317837245195782, r[2], 3.178372e-07);
  ASSERT_NEAR(-0.317837245195782, r[3], 3.178372e-07);
  ASSERT_NEAR(-3.14626436994197, r[4], 3.146264e-06);
}

TEST(QuarticRootTest, Test_20) {
  double r[5];
  double a[] = {0, -0.25, 1, -1.5};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.5, r[1], 5e-07);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(0.5, r[3], 5e-07);
  ASSERT_NEAR(0.5, r[4], 5e-07);
}

TEST(QuarticRootTest, Test_21) {
  double r[5];
  double a[] = {4, 0, 5, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(1.0, r[2], 1e-06);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(2.0, r[4], 2e-06);
}

TEST(QuarticRootTest, Test_22) {
  double r[5];
  double a[] = {4, 0, -5, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(2.0, r[1], 2e-06);
  ASSERT_NEAR(1.0, r[2], 1e-06);
  ASSERT_NEAR(-1.0, r[3], 1e-06);
  ASSERT_NEAR(-2.0, r[4], 2e-06);
}

TEST(QuarticRootTest, Test_23) {
  double r[5];
  double a[] = {1, 23, 4, 23};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0437273453936832, r[1], 4.372735e-08);
  ASSERT_NEAR(-22.8689848651196, r[2], 2.286898e-06);
  ASSERT_NEAR(-0.043643894743336, r[3], 4.364389e-08);
  ASSERT_NEAR(0.999047151265461, r[4], 9.990472e-07);
}

TEST(QuarticRootTest, Test_24) {
  double r[5];
  double a[] = {36, 24, 16, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-1.0, r[1], 1e-06);
  ASSERT_NEAR(2.236068, r[2], 2.236068e-06);
  ASSERT_NEAR(-1.0, r[3], 1e-06);
  ASSERT_NEAR(2.236068, r[4], 2.236068e-06);
}

TEST(QuarticRootTest, Test_25) {
  double r[5];
  double a[] = {1, 4, 6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(-1.0, r[1], 1e-06);
  ASSERT_NEAR(-1.0, r[2], 1e-06);
  ASSERT_NEAR(-1.0, r[3], 1e-06);
  ASSERT_NEAR(-1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_26) {
  double r[5];
  double a[] = {1, 4, 6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.3273528, r[1], 3.273528e-07);
  ASSERT_NEAR(2.482331, r[2], 2.482331e-06);
  ASSERT_NEAR(-0.3273528, r[3], 3.273528e-07);
  ASSERT_NEAR(0.2288055, r[4], 2.288055e-07);
}

TEST(QuarticRootTest, Test_27) {
  double r[5];
  double a[] = {1, 4, 6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2.27202, r[1], 2.27202e-06);
  ASSERT_NEAR(1.786151, r[2], 1.786151e-06);
  ASSERT_NEAR(-0.2720196, r[3], 2.720196e-07);
  ASSERT_NEAR(0.2138486, r[4], 2.138486e-07);
}

TEST(QuarticRootTest, Test_28) {
  double r[5];
  double a[] = {1, 4, 0, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.2374126, r[1], 2.374126e-07);
  ASSERT_NEAR(-4.212077, r[2], 4.212077e-06);
  ASSERT_NEAR(0.2247449, r[3], 2.247449e-07);
  ASSERT_NEAR(0.9744176, r[4], 9.744176e-07);
}

TEST(QuarticRootTest, Test_29) {
  double r[5];
  double a[] = {1, 4, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.2509922, r[1], 2.509922e-07);
  ASSERT_NEAR(-1.493359, r[2], 1.493359e-06);
  ASSERT_NEAR(0.8721754, r[3], 8.721754e-07);
  ASSERT_NEAR(1.381032, r[4], 1.381032e-06);
}

TEST(QuarticRootTest, Test_30) {
  double r[5];
  double a[] = {1, 4, 0, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(3.685544, r[1], 3.685544e-06);
  ASSERT_NEAR(1.334904, r[2], 1.334904e-06);
  ASSERT_NEAR(-0.2713304, r[3], 2.713304e-07);
  ASSERT_NEAR(-0.7491175, r[4], 7.491175e-07);
}

TEST(QuarticRootTest, Test_31) {
  double r[5];
  double a[] = {1, 4, -6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.1895911, r[1], 1.895911e-07);
  ASSERT_NEAR(-5.274511, r[2], 5.274511e-06);
  ASSERT_NEAR(0.7320508, r[3], 7.320508e-07);
  ASSERT_NEAR(0.68125, r[4], 6.8125e-07);
}

TEST(QuarticRootTest, Test_32) {
  double r[5];
  double a[] = {1, 4, -6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(1.903212, r[1], 1.903212e-06);
  ASSERT_NEAR(1.0, r[2], 1e-06);
  ASSERT_NEAR(-0.1939366, r[3], 1.939366e-07);
  ASSERT_NEAR(-2.709275, r[4], 2.709275e-06);
}

TEST(QuarticRootTest, Test_33) {
  double r[5];
  double a[] = {1, 4, -6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(5.027339, r[1], 5.027339e-06);
  ASSERT_NEAR(0.6681786, r[2], 6.681786e-07);
  ASSERT_NEAR(-0.1989124, r[3], 1.989124e-07);
  ASSERT_NEAR(-1.496606, r[4], 1.496606e-06);
}

TEST(QuarticRootTest, Test_34) {
  double r[5];
  double a[] = {1, 0, 6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.05221665, r[1], 5.221665e-08);
  ASSERT_NEAR(0.3959612, r[2], 3.959612e-07);
  ASSERT_NEAR(-2.052217, r[3], 2.052217e-06);
  ASSERT_NEAR(1.434411, r[4], 1.434411e-06);
}

TEST(QuarticRootTest, Test_35) {
  double r[5];
  double a[] = {1, 0, 6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(0.4142136, r[2], 4.142136e-07);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(2.414214, r[4], 2.414214e-06);
}

TEST(QuarticRootTest, Test_36) {
  double r[5];
  double a[] = {1, 0, 6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2.052217, r[1], 2.052217e-06);
  ASSERT_NEAR(1.434411, r[2], 1.434411e-06);
  ASSERT_NEAR(-0.05221665, r[3], 5.221665e-08);
  ASSERT_NEAR(0.3959612, r[4], 3.959612e-07);
}

TEST(QuarticRootTest, Test_37) {
  double r[5];
  double a[] = {1, 0, 0, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.6696315, r[1], 6.696315e-07);
  ASSERT_NEAR(-3.984188, r[2], 3.984188e-06);
  ASSERT_NEAR(0.3269099, r[3], 3.269099e-07);
  ASSERT_NEAR(0.51764, r[4], 5.1764e-07);
}

TEST(QuarticRootTest, Test_38) {
  double r[5];
  double a[] = {1, 0, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.7071068, r[1], 7.071068e-07);
  ASSERT_NEAR(0.7071068, r[2], 7.071068e-07);
  ASSERT_NEAR(-0.7071068, r[3], 7.071068e-07);
  ASSERT_NEAR(0.7071068, r[4], 7.071068e-07);
}

TEST(QuarticRootTest, Test_39) {
  double r[5];
  double a[] = {1, 0, 0, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.984188, r[1], 3.984188e-06);
  ASSERT_NEAR(0.6696315, r[2], 6.696315e-07);
  ASSERT_NEAR(-0.3269099, r[3], 3.269099e-07);
  ASSERT_NEAR(0.51764, r[4], 5.1764e-07);
}

TEST(QuarticRootTest, Test_40) {
  double r[5];
  double a[] = {1, 0, -6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(1.0, r[1], 1e-06);
  ASSERT_NEAR(0.5254276, r[2], 5.254276e-07);
  ASSERT_NEAR(-0.3691024, r[3], 3.691024e-07);
  ASSERT_NEAR(-5.156325, r[4], 5.156325e-06);
}

TEST(QuarticRootTest, Test_41) {
  double r[5];
  double a[] = {1, 0, -6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(2.414214, r[1], 2.414214e-06);
  ASSERT_NEAR(0.4142136, r[2], 4.142136e-07);
  ASSERT_NEAR(-0.4142136, r[3], 4.142136e-07);
  ASSERT_NEAR(-2.414214, r[4], 2.414214e-06);
}

TEST(QuarticRootTest, Test_42) {
  double r[5];
  double a[] = {1, 0, -6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(5.156325, r[1], 5.156325e-06);
  ASSERT_NEAR(0.3691024, r[2], 3.691024e-07);
  ASSERT_NEAR(-0.5254276, r[3], 5.254276e-07);
  ASSERT_NEAR(-1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_43) {
  double r[5];
  double a[] = {1, -4, 6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.2720196, r[1], 2.720196e-07);
  ASSERT_NEAR(0.2138486, r[2], 2.138486e-07);
  ASSERT_NEAR(-2.27202, r[3], 2.27202e-06);
  ASSERT_NEAR(1.786151, r[4], 1.786151e-06);
}

TEST(QuarticRootTest, Test_44) {
  double r[5];
  double a[] = {1, -4, 6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.3273528, r[1], 3.273528e-07);
  ASSERT_NEAR(0.2288055, r[2], 2.288055e-07);
  ASSERT_NEAR(-0.3273528, r[3], 3.273528e-07);
  ASSERT_NEAR(2.482331, r[4], 2.482331e-06);
}

TEST(QuarticRootTest, Test_45) {
  double r[5];
  double a[] = {1, -4, 6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(1.0, r[1], 1e-06);
  ASSERT_NEAR(1.0, r[2], 1e-06);
  ASSERT_NEAR(1.0, r[3], 1e-06);
  ASSERT_NEAR(1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_46) {
  double r[5];
  double a[] = {1, -4, 0, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(0.7491175, r[1], 7.491175e-07);
  ASSERT_NEAR(0.2713304, r[2], 2.713304e-07);
  ASSERT_NEAR(-1.334904, r[3], 1.334904e-06);
  ASSERT_NEAR(-3.685544, r[4], 3.685544e-06);
}

TEST(QuarticRootTest, Test_47) {
  double r[5];
  double a[] = {1, -4, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.493359, r[1], 1.493359e-06);
  ASSERT_NEAR(0.2509922, r[2], 2.509922e-07);
  ASSERT_NEAR(-0.8721754, r[3], 8.721754e-07);
  ASSERT_NEAR(1.381032, r[4], 1.381032e-06);
}

TEST(QuarticRootTest, Test_48) {
  double r[5];
  double a[] = {1, -4, 0, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.212077, r[1], 4.212077e-06);
  ASSERT_NEAR(0.2374126, r[2], 2.374126e-07);
  ASSERT_NEAR(-0.2247449, r[3], 2.247449e-07);
  ASSERT_NEAR(0.9744176, r[4], 9.744176e-07);
}

TEST(QuarticRootTest, Test_49) {
  double r[5];
  double a[] = {1, -4, -6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(1.496606, r[1], 1.496606e-06);
  ASSERT_NEAR(0.1989124, r[2], 1.989124e-07);
  ASSERT_NEAR(-0.6681786, r[3], 6.681786e-07);
  ASSERT_NEAR(-5.027339, r[4], 5.027339e-06);
}

TEST(QuarticRootTest, Test_50) {
  double r[5];
  double a[] = {1, -4, -6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(2.709275, r[1], 2.709275e-06);
  ASSERT_NEAR(0.1939366, r[2], 1.939366e-07);
  ASSERT_NEAR(-1.0, r[3], 1e-06);
  ASSERT_NEAR(-1.903212, r[4], 1.903212e-06);
}

TEST(QuarticRootTest, Test_51) {
  double r[5];
  double a[] = {1, -4, -6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.274511, r[1], 5.274511e-06);
  ASSERT_NEAR(0.1895911, r[2], 1.895911e-07);
  ASSERT_NEAR(-0.7320508, r[3], 7.320508e-07);
  ASSERT_NEAR(0.68125, r[4], 6.8125e-07);
}

TEST(QuarticRootTest, Test_52) {
  double r[5];
  double a[] = {0, 4, 6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(-2.0, r[2], 2e-06);
  ASSERT_NEAR(-1.0, r[3], 1e-06);
  ASSERT_NEAR(1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_53) {
  double r[5];
  double a[] = {0, 4, 6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(-0.6258168, r[2], 6.258168e-07);
  ASSERT_NEAR(0.3129084, r[3], 3.129084e-07);
  ASSERT_NEAR(2.508732, r[4], 2.508732e-06);
}

TEST(QuarticRootTest, Test_54) {
  double r[5];
  double a[] = {0, 4, 6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(-0.4883022, r[2], 4.883022e-07);
  ASSERT_NEAR(2.244151, r[3], 2.244151e-06);
  ASSERT_NEAR(1.776354, r[4], 1.776354e-06);
}

TEST(QuarticRootTest, Test_55) {
  double r[5];
  double a[] = {0, 4, 0, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(-4.22417, r[2], 4.22417e-06);
  ASSERT_NEAR(0.1120849, r[3], 1.120849e-07);
  ASSERT_NEAR(0.9666274, r[4], 9.666274e-07);
}

TEST(QuarticRootTest, Test_56) {
  double r[5];
  double a[] = {0, 4, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(-1.587401, r[2], 1.587401e-06);
  ASSERT_NEAR(0.7937005, r[3], 7.937005e-07);
  ASSERT_NEAR(1.37473, r[4], 1.37473e-06);
}

TEST(QuarticRootTest, Test_57) {
  double r[5];
  double a[] = {0, 4, 0, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(3.709275, r[1], 3.709275e-06);
  ASSERT_NEAR(1.193937, r[2], 1.193937e-06);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(-0.9032119, r[4], 9.032119e-07);
}

TEST(QuarticRootTest, Test_58) {
  double r[5];
  double a[] = {0, 4, -6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(-5.279877, r[2], 5.279877e-06);
  ASSERT_NEAR(0.6399385, r[3], 6.399385e-07);
  ASSERT_NEAR(0.5899763, r[4], 5.899763e-07);
}

TEST(QuarticRootTest, Test_59) {
  double r[5];
  double a[] = {0, 4, -6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(2.0, r[1], 2e-06);
  ASSERT_NEAR(0.7320508, r[2], 7.320508e-07);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(-2.732051, r[4], 2.732051e-06);
}

TEST(QuarticRootTest, Test_60) {
  double r[5];
  double a[] = {0, 4, -6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(5.034042, r[1], 5.034042e-06);
  ASSERT_NEAR(0.5134648, r[2], 5.134648e-07);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(-1.547507, r[4], 1.547507e-06);
}

TEST(QuarticRootTest, Test_61) {
  double r[5];
  double a[] = {0, 0, 6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(-2.0, r[3], 2e-06);
  ASSERT_NEAR(1.414214, r[4], 1.414214e-06);
}

TEST(QuarticRootTest, Test_62) {
  double r[5];
  double a[] = {0, 0, 6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(2.44949, r[4], 2.44949e-06);
}

TEST(QuarticRootTest, Test_63) {
  double r[5];
  double a[] = {0, 0, 6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(2.0, r[3], 2e-06);
  ASSERT_NEAR(1.414214, r[4], 1.414214e-06);
}

TEST(QuarticRootTest, Test_64) {
  double r[5];
  double a[] = {0, 0, 0, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(-4.0, r[4], 4e-06);
}

TEST(QuarticRootTest, Test_65) {
  double r[5];
  double a[] = {0, 0, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(0.0, r[4], 0.0);
}

TEST(QuarticRootTest, Test_66) {
  double r[5];
  double a[] = {0, 0, 0, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(4.0, r[1], 4e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(0.0, r[4], 0.0);
}

TEST(QuarticRootTest, Test_67) {
  double r[5];
  double a[] = {0, 0, -6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1.162278, r[1], 1.162278e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(-5.162278, r[4], 5.162278e-06);
}

TEST(QuarticRootTest, Test_68) {
  double r[5];
  double a[] = {0, 0, -6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(2.44949, r[1], 2.44949e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(-2.44949, r[4], 2.44949e-06);
}

TEST(QuarticRootTest, Test_69) {
  double r[5];
  double a[] = {0, 0, -6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(5.162278, r[1], 5.162278e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(-1.162278, r[4], 1.162278e-06);
}

TEST(QuarticRootTest, Test_70) {
  double r[5];
  double a[] = {0, -4, 6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.4883022, r[1], 4.883022e-07);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(-2.244151, r[3], 2.244151e-06);
  ASSERT_NEAR(1.776354, r[4], 1.776354e-06);
}

TEST(QuarticRootTest, Test_71) {
  double r[5];
  double a[] = {0, -4, 6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.6258168, r[1], 6.258168e-07);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(-0.3129084, r[3], 3.129084e-07);
  ASSERT_NEAR(2.508732, r[4], 2.508732e-06);
}

TEST(QuarticRootTest, Test_72) {
  double r[5];
  double a[] = {0, -4, 6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.0, r[1], 2e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(1.0, r[3], 1e-06);
  ASSERT_NEAR(1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_73) {
  double r[5];
  double a[] = {0, -4, 0, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(0.9032119, r[1], 9.032119e-07);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(-1.193937, r[3], 1.193937e-06);
  ASSERT_NEAR(-3.709275, r[4], 3.709275e-06);
}

TEST(QuarticRootTest, Test_74) {
  double r[5];
  double a[] = {0, -4, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.587401, r[1], 1.587401e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(-0.7937005, r[3], 7.937005e-07);
  ASSERT_NEAR(1.37473, r[4], 1.37473e-06);
}

TEST(QuarticRootTest, Test_75) {
  double r[5];
  double a[] = {0, -4, 0, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.22417, r[1], 4.22417e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(-0.1120849, r[3], 1.120849e-07);
  ASSERT_NEAR(0.9666274, r[4], 9.666274e-07);
}

TEST(QuarticRootTest, Test_76) {
  double r[5];
  double a[] = {0, -4, -6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(1.547507, r[1], 1.547507e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(-0.5134648, r[3], 5.134648e-07);
  ASSERT_NEAR(-5.034042, r[4], 5.034042e-06);
}

TEST(QuarticRootTest, Test_77) {
  double r[5];
  double a[] = {0, -4, -6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(2.732051, r[1], 2.732051e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(-0.7320508, r[3], 7.320508e-07);
  ASSERT_NEAR(-2.0, r[4], 2e-06);
}

TEST(QuarticRootTest, Test_78) {
  double r[5];
  double a[] = {0, -4, -6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.279877, r[1], 5.279877e-06);
  ASSERT_NEAR(0.0, r[2], 0.0);
  ASSERT_NEAR(-0.6399385, r[3], 6.399385e-07);
  ASSERT_NEAR(0.5899763, r[4], 5.899763e-07);
}

TEST(QuarticRootTest, Test_79) {
  double r[5];
  double a[] = {-1, 4, 6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.1892071, r[1], 1.892071e-07);
  ASSERT_NEAR(-2.189207, r[2], 2.189207e-06);
  ASSERT_NEAR(-1.0, r[3], 1e-06);
  ASSERT_NEAR(1.189207, r[4], 1.189207e-06);
}

TEST(QuarticRootTest, Test_80) {
  double r[5];
  double a[] = {-1, 4, 6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.1934913, r[1], 1.934913e-07);
  ASSERT_NEAR(-0.7934597, r[2], 7.934597e-07);
  ASSERT_NEAR(0.2999842, r[3], 2.999842e-07);
  ASSERT_NEAR(2.534462, r[4], 2.534462e-06);
}

TEST(QuarticRootTest, Test_81) {
  double r[5];
  double a[] = {-1, 4, 6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.1983854, r[1], 1.983854e-07);
  ASSERT_NEAR(-0.6279422, r[2], 6.279422e-07);
  ASSERT_NEAR(2.214778, r[3], 2.214778e-06);
  ASSERT_NEAR(1.76694, r[4], 1.76694e-06);
}

TEST(QuarticRootTest, Test_82) {
  double r[5];
  double a[] = {-1, 4, 0, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.236068, r[1], 2.36068e-07);
  ASSERT_NEAR(-4.236068, r[2], 4.236068e-06);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_83) {
  double r[5];
  double a[] = {-1, 4, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.2490384, r[1], 2.490384e-07);
  ASSERT_NEAR(-1.663252, r[2], 1.663252e-06);
  ASSERT_NEAR(0.7071068, r[3], 7.071068e-07);
  ASSERT_NEAR(1.383551, r[4], 1.383551e-06);
}

TEST(QuarticRootTest, Test_84) {
  double r[5];
  double a[] = {-1, 4, 0, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(3.732051, r[1], 3.732051e-06);
  ASSERT_NEAR(1.0, r[2], 1e-06);
  ASSERT_NEAR(0.2679492, r[3], 2.679492e-07);
  ASSERT_NEAR(-1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_85) {
  double r[5];
  double a[] = {-1, 4, -6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.4567864, r[1], 4.567864e-07);
  ASSERT_NEAR(-5.285214, r[2], 5.285214e-06);
  ASSERT_NEAR(0.4142136, r[3], 4.142136e-07);
  ASSERT_NEAR(0.4925857, r[4], 4.925857e-07);
}

TEST(QuarticRootTest, Test_86) {
  double r[5];
  double a[] = {-1, 4, -6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.074686, r[1], 2.074686e-06);
  ASSERT_NEAR(-2.753962, r[2], 2.753962e-06);
  ASSERT_NEAR(0.3396378, r[3], 3.396378e-07);
  ASSERT_NEAR(0.2442683, r[4], 2.442683e-07);
}

TEST(QuarticRootTest, Test_87) {
  double r[5];
  double a[] = {-1, 4, -6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.040693, r[1], 5.040693e-06);
  ASSERT_NEAR(-1.592503, r[2], 1.592503e-06);
  ASSERT_NEAR(0.2759051, r[3], 2.759051e-07);
  ASSERT_NEAR(0.2201158, r[4], 2.201158e-07);
}

TEST(QuarticRootTest, Test_88) {
  double r[5];
  double a[] = {-1, 0, 6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.3631133, r[1], 3.631133e-07);
  ASSERT_NEAR(-0.4820006, r[2], 4.820006e-07);
  ASSERT_NEAR(-1.940556, r[3], 1.940556e-06);
  ASSERT_NEAR(1.395653, r[4], 1.395653e-06);
}

TEST(QuarticRootTest, Test_89) {
  double r[5];
  double a[] = {-1, 0, 6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.402837, r[1], 4.02837e-07);
  ASSERT_NEAR(-0.402837, r[2], 4.02837e-07);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(2.482394, r[4], 2.482394e-06);
}

TEST(QuarticRootTest, Test_90) {
  double r[5];
  double a[] = {-1, 0, 6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.4820006, r[1], 4.820006e-07);
  ASSERT_NEAR(-0.3631133, r[2], 3.631133e-07);
  ASSERT_NEAR(1.940556, r[3], 1.940556e-06);
  ASSERT_NEAR(1.395653, r[4], 1.395653e-06);
}

TEST(QuarticRootTest, Test_91) {
  double r[5];
  double a[] = {-1, 0, 0, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.6012318, r[1], 6.012318e-07);
  ASSERT_NEAR(-4.015445, r[2], 4.015445e-06);
  ASSERT_NEAR(-0.2928932, r[3], 2.928932e-07);
  ASSERT_NEAR(0.5730856, r[4], 5.730856e-07);
}

TEST(QuarticRootTest, Test_92) {
  double r[5];
  double a[] = {-1, 0, 0, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.015445, r[1], 4.015445e-06);
  ASSERT_NEAR(-0.6012318, r[2], 6.012318e-07);
  ASSERT_NEAR(0.2928932, r[3], 2.928932e-07);
  ASSERT_NEAR(0.5730856, r[4], 5.730856e-07);
}

TEST(QuarticRootTest, Test_93) {
  double r[5];
  double a[] = {-1, 0, -6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.260303, r[1], 1.260303e-06);
  ASSERT_NEAR(-5.168192, r[2], 5.168192e-06);
  ASSERT_NEAR(-0.04605584, r[3], 4.605584e-08);
  ASSERT_NEAR(0.3891097, r[4], 3.891097e-07);
}

TEST(QuarticRootTest, Test_94) {
  double r[5];
  double a[] = {-1, 0, -6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.482394, r[1], 2.482394e-06);
  ASSERT_NEAR(-2.482394, r[2], 2.482394e-06);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(0.402837, r[4], 4.02837e-07);
}

TEST(QuarticRootTest, Test_95) {
  double r[5];
  double a[] = {-1, 0, -6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.168192, r[1], 5.168192e-06);
  ASSERT_NEAR(-1.260303, r[2], 1.260303e-06);
  ASSERT_NEAR(0.04605584, r[3], 4.605584e-08);
  ASSERT_NEAR(0.3891097, r[4], 3.891097e-07);
}

TEST(QuarticRootTest, Test_96) {
  double r[5];
  double a[] = {-1, -4, 6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.6279422, r[1], 6.279422e-07);
  ASSERT_NEAR(-0.1983854, r[2], 1.983854e-07);
  ASSERT_NEAR(-2.214778, r[3], 2.214778e-06);
  ASSERT_NEAR(1.76694, r[4], 1.76694e-06);
}

TEST(QuarticRootTest, Test_97) {
  double r[5];
  double a[] = {-1, -4, 6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.7934597, r[1], 7.934597e-07);
  ASSERT_NEAR(-0.1934913, r[2], 1.934913e-07);
  ASSERT_NEAR(-0.2999842, r[3], 2.999842e-07);
  ASSERT_NEAR(2.534462, r[4], 2.534462e-06);
}

TEST(QuarticRootTest, Test_98) {
  double r[5];
  double a[] = {-1, -4, 6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.189207, r[1], 2.189207e-06);
  ASSERT_NEAR(-0.1892071, r[2], 1.892071e-07);
  ASSERT_NEAR(1.0, r[3], 1e-06);
  ASSERT_NEAR(1.189207, r[4], 1.189207e-06);
}

TEST(QuarticRootTest, Test_99) {
  double r[5];
  double a[] = {-1, -4, 0, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(1.0, r[1], 1e-06);
  ASSERT_NEAR(-0.2679492, r[2], 2.679492e-07);
  ASSERT_NEAR(-1.0, r[3], 1e-06);
  ASSERT_NEAR(-3.732051, r[4], 3.732051e-06);
}

TEST(QuarticRootTest, Test_100) {
  double r[5];
  double a[] = {-1, -4, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.663252, r[1], 1.663252e-06);
  ASSERT_NEAR(-0.2490384, r[2], 2.490384e-07);
  ASSERT_NEAR(-0.7071068, r[3], 7.071068e-07);
  ASSERT_NEAR(1.383551, r[4], 1.383551e-06);
}

TEST(QuarticRootTest, Test_101) {
  double r[5];
  double a[] = {-1, -4, 0, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.236068, r[1], 4.236068e-06);
  ASSERT_NEAR(-0.236068, r[2], 2.36068e-07);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(1.0, r[4], 1e-06);
}

TEST(QuarticRootTest, Test_102) {
  double r[5];
  double a[] = {-1, -4, -6, 4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.592503, r[1], 1.592503e-06);
  ASSERT_NEAR(-5.040693, r[2], 5.040693e-06);
  ASSERT_NEAR(-0.2759051, r[3], 2.759051e-07);
  ASSERT_NEAR(0.2201158, r[4], 2.201158e-07);
}

TEST(QuarticRootTest, Test_103) {
  double r[5];
  double a[] = {-1, -4, -6, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.753962, r[1], 2.753962e-06);
  ASSERT_NEAR(-2.074686, r[2], 2.074686e-06);
  ASSERT_NEAR(-0.3396378, r[3], 3.396378e-07);
  ASSERT_NEAR(0.2442683, r[4], 2.442683e-07);
}

TEST(QuarticRootTest, Test_104) {
  double r[5];
  double a[] = {-1, -4, -6, -4};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.285214, r[1], 5.285214e-06);
  ASSERT_NEAR(-0.4567864, r[2], 4.567864e-07);
  ASSERT_NEAR(-0.4142136, r[3], 4.142136e-07);
  ASSERT_NEAR(0.4925857, r[4], 4.925857e-07);
}

TEST(QuarticRootTest, Test_105) {
  double r[5];
  double a[] = {0, 1e-100, -1e+170, 1e+150};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(4, num_roots);
  ASSERT_NEAR(1e+20, r[1], 1e+13);
  ASSERT_NEAR(1e-270, r[2], 1e-277);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(-1e+150, r[4], 1e+143);
}

TEST(QuarticRootTest, Test_106) {
  double r[5];
  double a[] = {2.5e-41, 0, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(5e-11, r[1], 5e-18);
  ASSERT_NEAR(5e-11, r[2], 5e-18);
  ASSERT_NEAR(-5e-11, r[3], 5e-18);
  ASSERT_NEAR(5e-11, r[4], 5e-18);
}

TEST(QuarticRootTest, Test_107) {
  double r[5];
  double a[] = {1e-33, 0, 0, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(3.976354e-08, r[1], 3.976354e-16);
  ASSERT_NEAR(3.976354e-08, r[2], 3.976354e-16);
  ASSERT_NEAR(-3.976354e-08, r[3], 3.976354e-16);
  ASSERT_NEAR(3.976354e-08, r[4], 3.976354e-16);
}

TEST(QuarticRootTest, Test_108) {
  double r[5];
  double a[] = {2.5e+299, 1e+200, 1e+100, 1e-300};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(5e+74, r[1], 5e+67);
  ASSERT_NEAR(5e+74, r[2], 5e+67);
  ASSERT_NEAR(-5e+74, r[3], 5e+67);
  ASSERT_NEAR(5e+74, r[4], 5e+67);
}

TEST(QuarticRootTest, Test_109) {
  double r[5];
  double a[] = {2.467401e+300, 0, 3.141593e+150, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(1.253314e+75, r[2], 1.253314e+68);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(1.253314e+75, r[4], 1.253314e+68);
}

TEST(QuarticRootTest, Test_110) {
  double r[5];
  double a[] = {-1e+300, 2e+200, -1e+100, 5e-300};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1e+75, r[1], 1e+68);
  ASSERT_NEAR(-1e+75, r[2], 1e+68);
  ASSERT_NEAR(5e+49, r[3], 5e+42);
  ASSERT_NEAR(1e+75, r[4], 1e+68);
}

TEST(QuarticRootTest, Test_111) {
  double r[5];
  double a[] = {1.12e+200, 0, 1.32e+100, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(4.462625e+49, r[1], 4.462625e+42);
  ASSERT_NEAR(9.269036e+49, r[2], 9.269036e+42);
  ASSERT_NEAR(-4.462625e+49, r[3], 4.462625e+42);
  ASSERT_NEAR(9.269036e+49, r[4], 9.269036e+42);
}

TEST(QuarticRootTest, Test_112) {
  double r[5];
  double a[] = {4.12e+215, 0, -3.63e+106, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(5.74466e+53, r[1], 5.74466e+46);
  ASSERT_NEAR(5.584453e+53, r[2], 5.584453e+46);
  ASSERT_NEAR(-5.74466e+53, r[3], 5.74466e+46);
  ASSERT_NEAR(5.584453e+53, r[4], 5.584453e+46);
}

TEST(QuarticRootTest, Test_113) {
  double r[5];
  double a[] = {5.31e-65, 0, 8.34e-198, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(6.036131e-17, r[1], 6.036131e-24);
  ASSERT_NEAR(6.036131e-17, r[2], 6.036131e-24);
  ASSERT_NEAR(-6.036131e-17, r[3], 6.036131e-24);
  ASSERT_NEAR(6.036131e-17, r[4], 6.036131e-24);
}

TEST(QuarticRootTest, Test_114) {
  double r[5];
  double a[] = {1e-306, 0, 1e-306, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2.236068e-77, r[1], 2.236068e-84);
  ASSERT_NEAR(2.236068e-77, r[2], 2.236068e-84);
  ASSERT_NEAR(-2.236068e-77, r[3], 2.236068e-84);
  ASSERT_NEAR(2.236068e-77, r[4], 2.236068e-84);
}

TEST(QuarticRootTest, Test_115) {
  double r[5];
  double a[] = {1e+306, 0, 1e+306, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.0, r[1], 0.0);
  ASSERT_NEAR(1.0, r[2], 1e-06);
  ASSERT_NEAR(0.0, r[3], 0.0);
  ASSERT_NEAR(1e+153, r[4], 1e+146);
}

TEST(QuarticRootTest, Test_116) {
  double r[5];
  double a[] = {1e+306, 0, 1e-306, 0};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2.236068e+76, r[1], 2.236068e+69);
  ASSERT_NEAR(2.236068e+76, r[2], 2.236068e+69);
  ASSERT_NEAR(-2.236068e+76, r[3], 2.236068e+69);
  ASSERT_NEAR(2.236068e+76, r[4], 2.236068e+69);
}

TEST(QuarticRootTest, Test_117) {
  double r[5];
  double a[] = {1e-40, 1, 1e-160, 1e+160};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2.154435e-67, r[1], 2.154435e-74);
  ASSERT_NEAR(-1e+160, r[2], 1e+153);
  ASSERT_NEAR(1.077217e-67, r[3], 1.077217e-74);
  ASSERT_NEAR(1.865795e-67, r[4], 1.865795e-74);
}

TEST(QuarticRootTest, Test_118) {
  double r[5];
  double a[] = {-1e+300, 0, 1e-300, 1e+300};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.0, r[1], 1e-06);
  ASSERT_NEAR(-1e+300, r[2], 1e+293);
  ASSERT_NEAR(-0.5, r[3], 5e-07);
  ASSERT_NEAR(0.8660254, r[4], 8.660254e-07);
}

TEST(QuarticRootTest, Test_119) {
  double r[5];
  double a[] = {-1e+300, 0, 0, 1e+300};
  int num_roots = rquartic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.0, r[1], 1e-06);
  ASSERT_NEAR(-1e+300, r[2], 1e+293);
  ASSERT_NEAR(-0.5, r[3], 5e-07);
  ASSERT_NEAR(0.8660254, r[4], 8.660254e-07);
}

