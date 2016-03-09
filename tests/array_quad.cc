#include <gtest/gtest.h>

extern "C" {
int quad_roots(double *a, double *r);
}

TEST(QuadraticRootTest, Test_1) {
  double r[3];
  double a[] = {5, 6, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1, r[1], 1e-07);
  ASSERT_NEAR(-5, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_2) {
  double r[3];
  double a[] = {6, 5, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2, r[1], 1e-07);
  ASSERT_NEAR(-3, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_3) {
  double r[3];
  double a[] = {4, -6, 2};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r[1], 1e-07);
  ASSERT_NEAR(1, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_4) {
  double r[3];
  double a[] = {1, -4, 4};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0.5, r[1], 1e-07);
  ASSERT_NEAR(0.5, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_5) {
  double r[3];
  double a[] = {10, -4, 2};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1, r[1], 1e-07);
  ASSERT_NEAR(2, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_6) {
  double r[3];
  double a[] = {0, 7, 2};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(-3.5, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_7) {
  double r[3];
  double a[] = {0, 0, 2};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(0, r[2], 0.0);
}

TEST(QuadraticRootTest, Test_8) {
  double r[3];
  double a[] = {3, 1, 0};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(-3, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_9) {
  double r[3];
  double a[] = {3, 2, 0};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(-1.5, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_10) {
  double r[3];
  double a[] = {0, 2, 0};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(-1, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(0, r[2], 0.0);
}

TEST(QuadraticRootTest, Test_11) {
  double r[3];
  double a[] = {0, 0, 0};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(-2, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(0, r[2], 0.0);
}

TEST(QuadraticRootTest, Test_12) {
  double r[3];
  double a[] = {2, 0, 0};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(-3, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(0, r[2], 0.0);
}

TEST(QuadraticRootTest, Test_13) {
  double r[3];
  double a[] = {8, 0, 2};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(2, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_14) {
  double r[3];
  double a[] = {-8, 0, 2};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r[1], 1e-07);
  ASSERT_NEAR(-2, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_15) {
  double r[3];
  double a[] = {3, -1000000000, 2};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500000000, r[1], 50.0);
  ASSERT_NEAR(3e-09, r[2], 3e-16);
}

TEST(QuadraticRootTest, Test_16) {
  double r[3];
  double a[] = {-3, -1000000000, 2};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500000000, r[1], 50.0);
  ASSERT_NEAR(-3e-09, r[2], 3e-16);
}

TEST(QuadraticRootTest, Test_17) {
  double r[3];
  double a[] = {3, 1000000000, 2};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-3e-09, r[1], 3e-16);
  ASSERT_NEAR(-500000000, r[2], 50.0);
}

TEST(QuadraticRootTest, Test_18) {
  double r[3];
  double a[] = {-3, 1000000000, 2};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3e-09, r[1], 3e-16);
  ASSERT_NEAR(-500000000, r[2], 50.0);
}

TEST(QuadraticRootTest, Test_19) {
  double r[3];
  double a[] = {-3e-199, 4.9994e-198, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.06, r[1], 1e-07);
  ASSERT_NEAR(-500, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_20) {
  double r[3];
  double a[] = {-3e-99, 4.9994e-98, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.06, r[1], 1e-07);
  ASSERT_NEAR(-500, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_21) {
  double r[3];
  double a[] = {-30, 499.94, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.06, r[1], 1e-07);
  ASSERT_NEAR(-500, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_22) {
  double r[3];
  double a[] = {-3e+101, 4.9994e+102, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.06, r[1], 1e-07);
  ASSERT_NEAR(-500, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_23) {
  double r[3];
  double a[] = {-3e+201, 4.9994e+202, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.06, r[1], 1e-07);
  ASSERT_NEAR(-500, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_24) {
  double r[3];
  double a[] = {3e-199, -5.0006e-198, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r[1], 1e-07);
  ASSERT_NEAR(0.06, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_25) {
  double r[3];
  double a[] = {3e-99, -5.0006e-98, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r[1], 1e-07);
  ASSERT_NEAR(0.06, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_26) {
  double r[3];
  double a[] = {30, -500.06, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r[1], 1e-07);
  ASSERT_NEAR(0.06, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_27) {
  double r[3];
  double a[] = {3e+101, -5.0006e+102, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r[1], 1e-07);
  ASSERT_NEAR(0.06, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_28) {
  double r[3];
  double a[] = {3e+201, -5.0006e+202, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r[1], 1e-07);
  ASSERT_NEAR(0.06, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_29) {
  double r[3];
  double a[] = {-3e-199, -4.9994e-198, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r[1], 1e-07);
  ASSERT_NEAR(-0.06, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_30) {
  double r[3];
  double a[] = {-3e-99, -4.9994e-98, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r[1], 1e-07);
  ASSERT_NEAR(-0.06, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_31) {
  double r[3];
  double a[] = {-30, -499.94, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r[1], 1e-07);
  ASSERT_NEAR(-0.06, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_32) {
  double r[3];
  double a[] = {-3e+101, -4.9994e+102, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r[1], 1e-07);
  ASSERT_NEAR(-0.06, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_33) {
  double r[3];
  double a[] = {-3e+201, -4.9994e+202, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(500, r[1], 1e-07);
  ASSERT_NEAR(-0.06, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_34) {
  double r[3];
  double a[] = {1.05e-198, -5.00000021e-196, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(50000, r[1], 1e-07);
  ASSERT_NEAR(0.0021, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_35) {
  double r[3];
  double a[] = {1.05e-98, -5.00000021e-96, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(50000, r[1], 1e-07);
  ASSERT_NEAR(0.0021, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_36) {
  double r[3];
  double a[] = {105, -50000.0021, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(50000, r[1], 1e-07);
  ASSERT_NEAR(0.0021, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_37) {
  double r[3];
  double a[] = {1.05e+102, -5.00000021e+104, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(50000, r[1], 1e-07);
  ASSERT_NEAR(0.0021, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_38) {
  double r[3];
  double a[] = {1.05e+202, -5.00000021e+204, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(50000, r[1], 1e-07);
  ASSERT_NEAR(0.0021, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_39) {
  double r[3];
  double a[] = {-1.05e-198, 4.99999979e-196, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0021, r[1], 1e-07);
  ASSERT_NEAR(-50000, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_40) {
  double r[3];
  double a[] = {-1.05e-98, 4.99999979e-96, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0021, r[1], 1e-07);
  ASSERT_NEAR(-50000, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_41) {
  double r[3];
  double a[] = {-105, 49999.9979, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0021, r[1], 1e-07);
  ASSERT_NEAR(-50000, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_42) {
  double r[3];
  double a[] = {-1.05e+102, 4.99999979e+104, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0021, r[1], 1e-07);
  ASSERT_NEAR(-50000, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_43) {
  double r[3];
  double a[] = {-1.05e+202, 4.99999979e+204, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0021, r[1], 1e-07);
  ASSERT_NEAR(-50000, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_44) {
  double r[3];
  double a[] = {1.05e-198, 5.00000021e-196, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0021, r[1], 1e-07);
  ASSERT_NEAR(-50000, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_45) {
  double r[3];
  double a[] = {1.05e-98, 5.00000021e-96, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0021, r[1], 1e-07);
  ASSERT_NEAR(-50000, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_46) {
  double r[3];
  double a[] = {105, 50000.0021, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0021, r[1], 1e-07);
  ASSERT_NEAR(-50000, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_47) {
  double r[3];
  double a[] = {1.05e+102, 5.00000021e+104, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0021, r[1], 1e-07);
  ASSERT_NEAR(-50000, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_48) {
  double r[3];
  double a[] = {1.05e+202, 5.00000021e+204, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0021, r[1], 1e-07);
  ASSERT_NEAR(-50000, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_49) {
  double r[3];
  double a[] = {-5.6e-199, 9.99999999944e-195, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.6e-05, r[1], 1e-07);
  ASSERT_NEAR(-1000000, r[2], 0.1);
}

TEST(QuadraticRootTest, Test_50) {
  double r[3];
  double a[] = {-5.6e-99, 9.99999999944e-95, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.6e-05, r[1], 1e-07);
  ASSERT_NEAR(-1000000, r[2], 0.1);
}

TEST(QuadraticRootTest, Test_51) {
  double r[3];
  double a[] = {-56, 999999.999944, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.6e-05, r[1], 1e-07);
  ASSERT_NEAR(-1000000, r[2], 0.1);
}

TEST(QuadraticRootTest, Test_52) {
  double r[3];
  double a[] = {-5.6e+101, 9.99999999944e+105, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.6e-05, r[1], 1e-07);
  ASSERT_NEAR(-1000000, r[2], 0.1);
}

TEST(QuadraticRootTest, Test_53) {
  double r[3];
  double a[] = {-5.6e+201, 9.99999999944e+205, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.6e-05, r[1], 1e-07);
  ASSERT_NEAR(-1000000, r[2], 0.1);
}

TEST(QuadraticRootTest, Test_54) {
  double r[3];
  double a[] = {5.6e-199, -1.000000000056e-194, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1000000, r[1], 0.1);
  ASSERT_NEAR(5.6e-05, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_55) {
  double r[3];
  double a[] = {5.6e-99, -1.000000000056e-94, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1000000, r[1], 0.1);
  ASSERT_NEAR(5.6e-05, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_56) {
  double r[3];
  double a[] = {56, -1000000.000056, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1000000, r[1], 0.1);
  ASSERT_NEAR(5.6e-05, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_57) {
  double r[3];
  double a[] = {5.6e+101, -1.000000000056e+106, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1000000, r[1], 0.1);
  ASSERT_NEAR(5.6e-05, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_58) {
  double r[3];
  double a[] = {5.6e+201, -1.000000000056e+206, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1000000, r[1], 0.1);
  ASSERT_NEAR(5.6e-05, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_59) {
  double r[3];
  double a[] = {-5.6e-199, -9.99999999944e-195, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1000000, r[1], 0.1);
  ASSERT_NEAR(-5.6e-05, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_60) {
  double r[3];
  double a[] = {-5.6e-99, -9.99999999944e-95, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1000000, r[1], 0.1);
  ASSERT_NEAR(-5.6e-05, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_61) {
  double r[3];
  double a[] = {-56, -999999.999944, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1000000, r[1], 0.1);
  ASSERT_NEAR(-5.6e-05, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_62) {
  double r[3];
  double a[] = {-5.6e+101, -9.99999999944e+105, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1000000, r[1], 0.1);
  ASSERT_NEAR(-5.6e-05, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_63) {
  double r[3];
  double a[] = {-5.6e+201, -9.99999999944e+205, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1000000, r[1], 0.1);
  ASSERT_NEAR(-5.6e-05, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_64) {
  double r[3];
  double a[] = {-1.8e-199, 1.4285714285713e-193, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.26e-06, r[1], 1.26e-13);
  ASSERT_NEAR(-14285714.2857143, r[2], 1.42857142857);
}

TEST(QuadraticRootTest, Test_65) {
  double r[3];
  double a[] = {-1.8e-99, 1.4285714285713e-93, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.26e-06, r[1], 1.26e-13);
  ASSERT_NEAR(-14285714.2857143, r[2], 1.42857142857);
}

TEST(QuadraticRootTest, Test_66) {
  double r[3];
  double a[] = {-18, 14285714.285713, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.26e-06, r[1], 1.26e-13);
  ASSERT_NEAR(-14285714.2857143, r[2], 1.42857142857);
}

TEST(QuadraticRootTest, Test_67) {
  double r[3];
  double a[] = {-1.8e+101, 1.4285714285713e+107, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.26e-06, r[1], 1.26e-13);
  ASSERT_NEAR(-14285714.2857143, r[2], 1.42857142857);
}

TEST(QuadraticRootTest, Test_68) {
  double r[3];
  double a[] = {-1.8e+201, 1.4285714285713e+207, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.26e-06, r[1], 1.26e-13);
  ASSERT_NEAR(-14285714.2857143, r[2], 1.42857142857);
}

TEST(QuadraticRootTest, Test_69) {
  double r[3];
  double a[] = {1.8e-199, -1.42857142857155e-193, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(14285714.2857143, r[1], 1.42857142857);
  ASSERT_NEAR(1.26e-06, r[2], 1.26e-13);
}

TEST(QuadraticRootTest, Test_70) {
  double r[3];
  double a[] = {1.8e-99, -1.42857142857155e-93, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(14285714.2857143, r[1], 1.42857142857);
  ASSERT_NEAR(1.26e-06, r[2], 1.26e-13);
}

TEST(QuadraticRootTest, Test_71) {
  double r[3];
  double a[] = {18, -14285714.2857155, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(14285714.2857143, r[1], 1.42857142857);
  ASSERT_NEAR(1.26e-06, r[2], 1.26e-13);
}

TEST(QuadraticRootTest, Test_72) {
  double r[3];
  double a[] = {1.8e+101, -1.42857142857155e+107, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(14285714.2857143, r[1], 1.42857142857);
  ASSERT_NEAR(1.26e-06, r[2], 1.26e-13);
}

TEST(QuadraticRootTest, Test_73) {
  double r[3];
  double a[] = {1.8e+201, -1.42857142857155e+207, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(14285714.2857143, r[1], 1.42857142857);
  ASSERT_NEAR(1.26e-06, r[2], 1.26e-13);
}

TEST(QuadraticRootTest, Test_74) {
  double r[3];
  double a[] = {-1.8e-199, -1.4285714285713e-193, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(14285714.2857143, r[1], 1.42857142857);
  ASSERT_NEAR(-1.26e-06, r[2], 1.26e-13);
}

TEST(QuadraticRootTest, Test_75) {
  double r[3];
  double a[] = {-1.8e-99, -1.4285714285713e-93, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(14285714.2857143, r[1], 1.42857142857);
  ASSERT_NEAR(-1.26e-06, r[2], 1.26e-13);
}

TEST(QuadraticRootTest, Test_76) {
  double r[3];
  double a[] = {-18, -14285714.285713, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(14285714.2857143, r[1], 1.42857142857);
  ASSERT_NEAR(-1.26e-06, r[2], 1.26e-13);
}

TEST(QuadraticRootTest, Test_77) {
  double r[3];
  double a[] = {-1.8e+101, -1.4285714285713e+107, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(14285714.2857143, r[1], 1.42857142857);
  ASSERT_NEAR(-1.26e-06, r[2], 1.26e-13);
}

TEST(QuadraticRootTest, Test_78) {
  double r[3];
  double a[] = {-1.8e+201, -1.4285714285713e+207, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(14285714.2857143, r[1], 1.42857142857);
  ASSERT_NEAR(-1.26e-06, r[2], 1.26e-13);
}

TEST(QuadraticRootTest, Test_79) {
  double r[3];
  double a[] = {-1.2e-199, 4.76190476190476e-192, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.52e-08, r[1], 2.52e-15);
  ASSERT_NEAR(-476190476.190476, r[2], 47.619047619);
}

TEST(QuadraticRootTest, Test_80) {
  double r[3];
  double a[] = {-1.2e-99, 4.76190476190476e-92, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.52e-08, r[1], 2.52e-15);
  ASSERT_NEAR(-476190476.190476, r[2], 47.619047619);
}

TEST(QuadraticRootTest, Test_81) {
  double r[3];
  double a[] = {-12, 476190476.190476, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.52e-08, r[1], 2.52e-15);
  ASSERT_NEAR(-476190476.190476, r[2], 47.619047619);
}

TEST(QuadraticRootTest, Test_82) {
  double r[3];
  double a[] = {-1.2e+101, 4.76190476190476e+108, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.52e-08, r[1], 2.52e-15);
  ASSERT_NEAR(-476190476.190476, r[2], 47.619047619);
}

TEST(QuadraticRootTest, Test_83) {
  double r[3];
  double a[] = {-1.2e+201, 4.76190476190476e+208, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.52e-08, r[1], 2.52e-15);
  ASSERT_NEAR(-476190476.190476, r[2], 47.619047619);
}

TEST(QuadraticRootTest, Test_84) {
  double r[3];
  double a[] = {1.2e-199, -4.76190476190476e-192, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(476190476.190476, r[1], 47.619047619);
  ASSERT_NEAR(2.52e-08, r[2], 2.52e-15);
}

TEST(QuadraticRootTest, Test_85) {
  double r[3];
  double a[] = {1.2e-99, -4.76190476190476e-92, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(476190476.190476, r[1], 47.619047619);
  ASSERT_NEAR(2.52e-08, r[2], 2.52e-15);
}

TEST(QuadraticRootTest, Test_86) {
  double r[3];
  double a[] = {12, -476190476.190476, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(476190476.190476, r[1], 47.619047619);
  ASSERT_NEAR(2.52e-08, r[2], 2.52e-15);
}

TEST(QuadraticRootTest, Test_87) {
  double r[3];
  double a[] = {1.2e+101, -4.76190476190476e+108, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(476190476.190476, r[1], 47.619047619);
  ASSERT_NEAR(2.52e-08, r[2], 2.52e-15);
}

TEST(QuadraticRootTest, Test_88) {
  double r[3];
  double a[] = {1.2e+201, -4.76190476190476e+208, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(476190476.190476, r[1], 47.619047619);
  ASSERT_NEAR(2.52e-08, r[2], 2.52e-15);
}

TEST(QuadraticRootTest, Test_89) {
  double r[3];
  double a[] = {-1.2e-199, -4.76190476190476e-192, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(476190476.190476, r[1], 47.619047619);
  ASSERT_NEAR(-2.52e-08, r[2], 2.52e-15);
}

TEST(QuadraticRootTest, Test_90) {
  double r[3];
  double a[] = {-1.2e-99, -4.76190476190476e-92, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(476190476.190476, r[1], 47.619047619);
  ASSERT_NEAR(-2.52e-08, r[2], 2.52e-15);
}

TEST(QuadraticRootTest, Test_91) {
  double r[3];
  double a[] = {-12, -476190476.190476, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(476190476.190476, r[1], 47.619047619);
  ASSERT_NEAR(-2.52e-08, r[2], 2.52e-15);
}

TEST(QuadraticRootTest, Test_92) {
  double r[3];
  double a[] = {-1.2e+101, -4.76190476190476e+108, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(476190476.190476, r[1], 47.619047619);
  ASSERT_NEAR(-2.52e-08, r[2], 2.52e-15);
}

TEST(QuadraticRootTest, Test_93) {
  double r[3];
  double a[] = {-1.2e+201, -4.76190476190476e+208, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(476190476.190476, r[1], 47.619047619);
  ASSERT_NEAR(-2.52e-08, r[2], 2.52e-15);
}

TEST(QuadraticRootTest, Test_94) {
  double r[3];
  double a[] = {-1e-199, 2.16450216450216e-190, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.62e-10, r[1], 4.62e-17);
  ASSERT_NEAR(-21645021645.0216, r[2], 2164.5021645);
}

TEST(QuadraticRootTest, Test_95) {
  double r[3];
  double a[] = {-1e-99, 2.16450216450216e-90, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.62e-10, r[1], 4.62e-17);
  ASSERT_NEAR(-21645021645.0216, r[2], 2164.5021645);
}

TEST(QuadraticRootTest, Test_96) {
  double r[3];
  double a[] = {-10, 21645021645.0216, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.62e-10, r[1], 4.62e-17);
  ASSERT_NEAR(-21645021645.0216, r[2], 2164.5021645);
}

TEST(QuadraticRootTest, Test_97) {
  double r[3];
  double a[] = {-1e+101, 2.16450216450216e+110, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.62e-10, r[1], 4.62e-17);
  ASSERT_NEAR(-21645021645.0216, r[2], 2164.5021645);
}

TEST(QuadraticRootTest, Test_98) {
  double r[3];
  double a[] = {-1e+201, 2.16450216450216e+210, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.62e-10, r[1], 4.62e-17);
  ASSERT_NEAR(-21645021645.0216, r[2], 2164.5021645);
}

TEST(QuadraticRootTest, Test_99) {
  double r[3];
  double a[] = {1e-199, -2.16450216450216e-190, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21645021645.0216, r[1], 2164.5021645);
  ASSERT_NEAR(4.62e-10, r[2], 4.62e-17);
}

TEST(QuadraticRootTest, Test_100) {
  double r[3];
  double a[] = {1e-99, -2.16450216450216e-90, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21645021645.0216, r[1], 2164.5021645);
  ASSERT_NEAR(4.62e-10, r[2], 4.62e-17);
}

TEST(QuadraticRootTest, Test_101) {
  double r[3];
  double a[] = {10, -21645021645.0216, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21645021645.0216, r[1], 2164.5021645);
  ASSERT_NEAR(4.62e-10, r[2], 4.62e-17);
}

TEST(QuadraticRootTest, Test_102) {
  double r[3];
  double a[] = {1e+101, -2.16450216450216e+110, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21645021645.0216, r[1], 2164.5021645);
  ASSERT_NEAR(4.62e-10, r[2], 4.62e-17);
}

TEST(QuadraticRootTest, Test_103) {
  double r[3];
  double a[] = {1e+201, -2.16450216450216e+210, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21645021645.0216, r[1], 2164.5021645);
  ASSERT_NEAR(4.62e-10, r[2], 4.62e-17);
}

TEST(QuadraticRootTest, Test_104) {
  double r[3];
  double a[] = {-1e-199, -2.16450216450216e-190, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21645021645.0216, r[1], 2164.5021645);
  ASSERT_NEAR(-4.62e-10, r[2], 4.62e-17);
}

TEST(QuadraticRootTest, Test_105) {
  double r[3];
  double a[] = {-1e-99, -2.16450216450216e-90, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21645021645.0216, r[1], 2164.5021645);
  ASSERT_NEAR(-4.62e-10, r[2], 4.62e-17);
}

TEST(QuadraticRootTest, Test_106) {
  double r[3];
  double a[] = {-10, -21645021645.0216, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21645021645.0216, r[1], 2164.5021645);
  ASSERT_NEAR(-4.62e-10, r[2], 4.62e-17);
}

TEST(QuadraticRootTest, Test_107) {
  double r[3];
  double a[] = {-1e+101, -2.16450216450216e+110, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21645021645.0216, r[1], 2164.5021645);
  ASSERT_NEAR(-4.62e-10, r[2], 4.62e-17);
}

TEST(QuadraticRootTest, Test_108) {
  double r[3];
  double a[] = {-1e+201, -2.16450216450216e+210, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21645021645.0216, r[1], 2164.5021645);
  ASSERT_NEAR(-4.62e-10, r[2], 4.62e-17);
}

TEST(QuadraticRootTest, Test_109) {
  double r[3];
  double a[] = {-9.23076923076923e-200, 1.16550116550117e-188, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.92e-12, r[1], 7.92e-19);
  ASSERT_NEAR(-1165501165501.17, r[2], 116550.11655);
}

TEST(QuadraticRootTest, Test_110) {
  double r[3];
  double a[] = {-9.23076923076923e-100, 1.16550116550117e-88, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.92e-12, r[1], 7.92e-19);
  ASSERT_NEAR(-1165501165501.17, r[2], 116550.11655);
}

TEST(QuadraticRootTest, Test_111) {
  double r[3];
  double a[] = {-9.23076923076923, 1165501165501.17, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.92e-12, r[1], 7.92e-19);
  ASSERT_NEAR(-1165501165501.17, r[2], 116550.11655);
}

TEST(QuadraticRootTest, Test_112) {
  double r[3];
  double a[] = {-9.23076923076923e+100, 1.16550116550117e+112, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.92e-12, r[1], 7.92e-19);
  ASSERT_NEAR(-1165501165501.17, r[2], 116550.11655);
}

TEST(QuadraticRootTest, Test_113) {
  double r[3];
  double a[] = {-9.23076923076923e+200, 1.16550116550117e+212, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.92e-12, r[1], 7.92e-19);
  ASSERT_NEAR(-1165501165501.17, r[2], 116550.11655);
}

TEST(QuadraticRootTest, Test_114) {
  double r[3];
  double a[] = {9.23076923076923e-200, -1.16550116550117e-188, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1165501165501.17, r[1], 116550.11655);
  ASSERT_NEAR(7.92e-12, r[2], 7.92e-19);
}

TEST(QuadraticRootTest, Test_115) {
  double r[3];
  double a[] = {9.23076923076923e-100, -1.16550116550117e-88, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1165501165501.17, r[1], 116550.11655);
  ASSERT_NEAR(7.92e-12, r[2], 7.92e-19);
}

TEST(QuadraticRootTest, Test_116) {
  double r[3];
  double a[] = {9.23076923076923, -1165501165501.17, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1165501165501.17, r[1], 116550.11655);
  ASSERT_NEAR(7.92e-12, r[2], 7.92e-19);
}

TEST(QuadraticRootTest, Test_117) {
  double r[3];
  double a[] = {9.23076923076923e+100, -1.16550116550117e+112, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1165501165501.17, r[1], 116550.11655);
  ASSERT_NEAR(7.92e-12, r[2], 7.92e-19);
}

TEST(QuadraticRootTest, Test_118) {
  double r[3];
  double a[] = {9.23076923076923e+200, -1.16550116550117e+212, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1165501165501.17, r[1], 116550.11655);
  ASSERT_NEAR(7.92e-12, r[2], 7.92e-19);
}

TEST(QuadraticRootTest, Test_119) {
  double r[3];
  double a[] = {-9.23076923076923e-200, -1.16550116550117e-188, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1165501165501.17, r[1], 116550.11655);
  ASSERT_NEAR(-7.92e-12, r[2], 7.92e-19);
}

TEST(QuadraticRootTest, Test_120) {
  double r[3];
  double a[] = {-9.23076923076923e-100, -1.16550116550117e-88, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1165501165501.17, r[1], 116550.11655);
  ASSERT_NEAR(-7.92e-12, r[2], 7.92e-19);
}

TEST(QuadraticRootTest, Test_121) {
  double r[3];
  double a[] = {-9.23076923076923, -1165501165501.17, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1165501165501.17, r[1], 116550.11655);
  ASSERT_NEAR(-7.92e-12, r[2], 7.92e-19);
}

TEST(QuadraticRootTest, Test_122) {
  double r[3];
  double a[] = {-9.23076923076923e+100, -1.16550116550117e+112, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1165501165501.17, r[1], 116550.11655);
  ASSERT_NEAR(-7.92e-12, r[2], 7.92e-19);
}

TEST(QuadraticRootTest, Test_123) {
  double r[3];
  double a[] = {-9.23076923076923e+200, -1.16550116550117e+212, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1165501165501.17, r[1], 116550.11655);
  ASSERT_NEAR(-7.92e-12, r[2], 7.92e-19);
}

TEST(QuadraticRootTest, Test_124) {
  double r[3];
  double a[] = {-9e-200, 6.99300699300699e-187, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.287e-13, r[1], 1.287e-20);
  ASSERT_NEAR(-69930069930069.9, r[2], 6993006.99301);
}

TEST(QuadraticRootTest, Test_125) {
  double r[3];
  double a[] = {-9e-100, 6.99300699300699e-87, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.287e-13, r[1], 1.287e-20);
  ASSERT_NEAR(-69930069930069.9, r[2], 6993006.99301);
}

TEST(QuadraticRootTest, Test_126) {
  double r[3];
  double a[] = {-9, 69930069930069.9, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.287e-13, r[1], 1.287e-20);
  ASSERT_NEAR(-69930069930069.9, r[2], 6993006.99301);
}

TEST(QuadraticRootTest, Test_127) {
  double r[3];
  double a[] = {-9e+100, 6.99300699300699e+113, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.287e-13, r[1], 1.287e-20);
  ASSERT_NEAR(-69930069930069.9, r[2], 6993006.99301);
}

TEST(QuadraticRootTest, Test_128) {
  double r[3];
  double a[] = {-9e+200, 6.99300699300699e+213, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.287e-13, r[1], 1.287e-20);
  ASSERT_NEAR(-69930069930069.9, r[2], 6993006.99301);
}

TEST(QuadraticRootTest, Test_129) {
  double r[3];
  double a[] = {9e-200, -6.99300699300699e-187, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(69930069930069.9, r[1], 6993006.99301);
  ASSERT_NEAR(1.287e-13, r[2], 1.287e-20);
}

TEST(QuadraticRootTest, Test_130) {
  double r[3];
  double a[] = {9e-100, -6.99300699300699e-87, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(69930069930069.9, r[1], 6993006.99301);
  ASSERT_NEAR(1.287e-13, r[2], 1.287e-20);
}

TEST(QuadraticRootTest, Test_131) {
  double r[3];
  double a[] = {9, -69930069930069.9, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(69930069930069.9, r[1], 6993006.99301);
  ASSERT_NEAR(1.287e-13, r[2], 1.287e-20);
}

TEST(QuadraticRootTest, Test_132) {
  double r[3];
  double a[] = {9e+100, -6.99300699300699e+113, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(69930069930069.9, r[1], 6993006.99301);
  ASSERT_NEAR(1.287e-13, r[2], 1.287e-20);
}

TEST(QuadraticRootTest, Test_133) {
  double r[3];
  double a[] = {9e+200, -6.99300699300699e+213, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(69930069930069.9, r[1], 6993006.99301);
  ASSERT_NEAR(1.287e-13, r[2], 1.287e-20);
}

TEST(QuadraticRootTest, Test_134) {
  double r[3];
  double a[] = {-9e-200, -6.99300699300699e-187, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(69930069930069.9, r[1], 6993006.99301);
  ASSERT_NEAR(-1.287e-13, r[2], 1.287e-20);
}

TEST(QuadraticRootTest, Test_135) {
  double r[3];
  double a[] = {-9e-100, -6.99300699300699e-87, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(69930069930069.9, r[1], 6993006.99301);
  ASSERT_NEAR(-1.287e-13, r[2], 1.287e-20);
}

TEST(QuadraticRootTest, Test_136) {
  double r[3];
  double a[] = {-9, -69930069930069.9, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(69930069930069.9, r[1], 6993006.99301);
  ASSERT_NEAR(-1.287e-13, r[2], 1.287e-20);
}

TEST(QuadraticRootTest, Test_137) {
  double r[3];
  double a[] = {-9e+100, -6.99300699300699e+113, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(69930069930069.9, r[1], 6993006.99301);
  ASSERT_NEAR(-1.287e-13, r[2], 1.287e-20);
}

TEST(QuadraticRootTest, Test_138) {
  double r[3];
  double a[] = {-9e+200, -6.99300699300699e+213, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(69930069930069.9, r[1], 6993006.99301);
  ASSERT_NEAR(-1.287e-13, r[2], 1.287e-20);
}

TEST(QuadraticRootTest, Test_139) {
  double r[3];
  double a[] = {-9.05882352941176e-200, 4.52488687782805e-185, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.002e-15, r[1], 2.002e-22);
  ASSERT_NEAR(-4.52488687782805e+15, r[2], 452488687.783);
}

TEST(QuadraticRootTest, Test_140) {
  double r[3];
  double a[] = {-9.05882352941176e-100, 4.52488687782805e-85, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.002e-15, r[1], 2.002e-22);
  ASSERT_NEAR(-4.52488687782805e+15, r[2], 452488687.783);
}

TEST(QuadraticRootTest, Test_141) {
  double r[3];
  double a[] = {-9.05882352941176, 4.52488687782805e+15, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.002e-15, r[1], 2.002e-22);
  ASSERT_NEAR(-4.52488687782805e+15, r[2], 452488687.783);
}

TEST(QuadraticRootTest, Test_142) {
  double r[3];
  double a[] = {-9.05882352941177e+100, 4.52488687782805e+115, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.002e-15, r[1], 2.002e-22);
  ASSERT_NEAR(-4.52488687782805e+15, r[2], 452488687.783);
}

TEST(QuadraticRootTest, Test_143) {
  double r[3];
  double a[] = {-9.05882352941177e+200, 4.52488687782805e+215, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.002e-15, r[1], 2.002e-22);
  ASSERT_NEAR(-4.52488687782805e+15, r[2], 452488687.783);
}

TEST(QuadraticRootTest, Test_144) {
  double r[3];
  double a[] = {9.05882352941176e-200, -4.52488687782805e-185, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.52488687782805e+15, r[1], 452488687.783);
  ASSERT_NEAR(2.002e-15, r[2], 2.002e-22);
}

TEST(QuadraticRootTest, Test_145) {
  double r[3];
  double a[] = {9.05882352941176e-100, -4.52488687782805e-85, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.52488687782805e+15, r[1], 452488687.783);
  ASSERT_NEAR(2.002e-15, r[2], 2.002e-22);
}

TEST(QuadraticRootTest, Test_146) {
  double r[3];
  double a[] = {9.05882352941176, -4.52488687782805e+15, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.52488687782805e+15, r[1], 452488687.783);
  ASSERT_NEAR(2.002e-15, r[2], 2.002e-22);
}

TEST(QuadraticRootTest, Test_147) {
  double r[3];
  double a[] = {9.05882352941177e+100, -4.52488687782805e+115, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.52488687782805e+15, r[1], 452488687.783);
  ASSERT_NEAR(2.002e-15, r[2], 2.002e-22);
}

TEST(QuadraticRootTest, Test_148) {
  double r[3];
  double a[] = {9.05882352941177e+200, -4.52488687782805e+215, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.52488687782805e+15, r[1], 452488687.783);
  ASSERT_NEAR(2.002e-15, r[2], 2.002e-22);
}

TEST(QuadraticRootTest, Test_149) {
  double r[3];
  double a[] = {-9.05882352941176e-200, -4.52488687782805e-185, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.52488687782805e+15, r[1], 452488687.783);
  ASSERT_NEAR(-2.002e-15, r[2], 2.002e-22);
}

TEST(QuadraticRootTest, Test_150) {
  double r[3];
  double a[] = {-9.05882352941176e-100, -4.52488687782805e-85, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.52488687782805e+15, r[1], 452488687.783);
  ASSERT_NEAR(-2.002e-15, r[2], 2.002e-22);
}

TEST(QuadraticRootTest, Test_151) {
  double r[3];
  double a[] = {-9.05882352941176, -4.52488687782805e+15, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.52488687782805e+15, r[1], 452488687.783);
  ASSERT_NEAR(-2.002e-15, r[2], 2.002e-22);
}

TEST(QuadraticRootTest, Test_152) {
  double r[3];
  double a[] = {-9.05882352941177e+100, -4.52488687782805e+115, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.52488687782805e+15, r[1], 452488687.783);
  ASSERT_NEAR(-2.002e-15, r[2], 2.002e-22);
}

TEST(QuadraticRootTest, Test_153) {
  double r[3];
  double a[] = {-9.05882352941177e+200, -4.52488687782805e+215, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.52488687782805e+15, r[1], 452488687.783);
  ASSERT_NEAR(-2.002e-15, r[2], 2.002e-22);
}

TEST(QuadraticRootTest, Test_154) {
  double r[3];
  double a[] = {-9.29721362229102e-200, 3.09597523219814e-183, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.003e-17, r[1], 3.003e-24);
  ASSERT_NEAR(-3.09597523219814e+17, r[2], 30959752322.0);
}

TEST(QuadraticRootTest, Test_155) {
  double r[3];
  double a[] = {-9.29721362229102e-100, 3.09597523219814e-83, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.003e-17, r[1], 3.003e-24);
  ASSERT_NEAR(-3.09597523219814e+17, r[2], 30959752322.0);
}

TEST(QuadraticRootTest, Test_156) {
  double r[3];
  double a[] = {-9.29721362229102, 3.09597523219814e+17, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.003e-17, r[1], 3.003e-24);
  ASSERT_NEAR(-3.09597523219814e+17, r[2], 30959752322.0);
}

TEST(QuadraticRootTest, Test_157) {
  double r[3];
  double a[] = {-9.29721362229102e+100, 3.09597523219814e+117, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.003e-17, r[1], 3.003e-24);
  ASSERT_NEAR(-3.09597523219814e+17, r[2], 30959752322.0);
}

TEST(QuadraticRootTest, Test_158) {
  double r[3];
  double a[] = {-9.29721362229102e+200, 3.09597523219814e+217, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.003e-17, r[1], 3.003e-24);
  ASSERT_NEAR(-3.09597523219814e+17, r[2], 30959752322.0);
}

TEST(QuadraticRootTest, Test_159) {
  double r[3];
  double a[] = {9.29721362229102e-200, -3.09597523219814e-183, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.09597523219814e+17, r[1], 30959752322.0);
  ASSERT_NEAR(3.003e-17, r[2], 3.003e-24);
}

TEST(QuadraticRootTest, Test_160) {
  double r[3];
  double a[] = {9.29721362229102e-100, -3.09597523219814e-83, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.09597523219814e+17, r[1], 30959752322.0);
  ASSERT_NEAR(3.003e-17, r[2], 3.003e-24);
}

TEST(QuadraticRootTest, Test_161) {
  double r[3];
  double a[] = {9.29721362229102, -3.09597523219814e+17, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.09597523219814e+17, r[1], 30959752322.0);
  ASSERT_NEAR(3.003e-17, r[2], 3.003e-24);
}

TEST(QuadraticRootTest, Test_162) {
  double r[3];
  double a[] = {9.29721362229102e+100, -3.09597523219814e+117, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.09597523219814e+17, r[1], 30959752322.0);
  ASSERT_NEAR(3.003e-17, r[2], 3.003e-24);
}

TEST(QuadraticRootTest, Test_163) {
  double r[3];
  double a[] = {9.29721362229102e+200, -3.09597523219814e+217, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.09597523219814e+17, r[1], 30959752322.0);
  ASSERT_NEAR(3.003e-17, r[2], 3.003e-24);
}

TEST(QuadraticRootTest, Test_164) {
  double r[3];
  double a[] = {-9.29721362229102e-200, -3.09597523219814e-183, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.09597523219814e+17, r[1], 30959752322.0);
  ASSERT_NEAR(-3.003e-17, r[2], 3.003e-24);
}

TEST(QuadraticRootTest, Test_165) {
  double r[3];
  double a[] = {-9.29721362229102e-100, -3.09597523219814e-83, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.09597523219814e+17, r[1], 30959752322.0);
  ASSERT_NEAR(-3.003e-17, r[2], 3.003e-24);
}

TEST(QuadraticRootTest, Test_166) {
  double r[3];
  double a[] = {-9.29721362229102, -3.09597523219814e+17, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.09597523219814e+17, r[1], 30959752322.0);
  ASSERT_NEAR(-3.003e-17, r[2], 3.003e-24);
}

TEST(QuadraticRootTest, Test_167) {
  double r[3];
  double a[] = {-9.29721362229102e+100, -3.09597523219814e+117, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.09597523219814e+17, r[1], 30959752322.0);
  ASSERT_NEAR(-3.003e-17, r[2], 3.003e-24);
}

TEST(QuadraticRootTest, Test_168) {
  double r[3];
  double a[] = {-9.29721362229102e+200, -3.09597523219814e+217, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.09597523219814e+17, r[1], 30959752322.0);
  ASSERT_NEAR(-3.003e-17, r[2], 3.003e-24);
}

TEST(QuadraticRootTest, Test_169) {
  double r[3];
  double a[] = {-9.6594427244582e-200, 2.21141088014153e-181, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.368e-19, r[1], 4.368e-26);
  ASSERT_NEAR(-2.21141088014153e+19, r[2], 2.21141088014e+12);
}

TEST(QuadraticRootTest, Test_170) {
  double r[3];
  double a[] = {-9.6594427244582e-100, 2.21141088014153e-81, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.368e-19, r[1], 4.368e-26);
  ASSERT_NEAR(-2.21141088014153e+19, r[2], 2.21141088014e+12);
}

TEST(QuadraticRootTest, Test_171) {
  double r[3];
  double a[] = {-9.6594427244582, 2.21141088014153e+19, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.368e-19, r[1], 4.368e-26);
  ASSERT_NEAR(-2.21141088014153e+19, r[2], 2.21141088014e+12);
}

TEST(QuadraticRootTest, Test_172) {
  double r[3];
  double a[] = {-9.6594427244582e+100, 2.21141088014153e+119, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.368e-19, r[1], 4.368e-26);
  ASSERT_NEAR(-2.21141088014153e+19, r[2], 2.21141088014e+12);
}

TEST(QuadraticRootTest, Test_173) {
  double r[3];
  double a[] = {-9.6594427244582e+200, 2.21141088014153e+219, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.368e-19, r[1], 4.368e-26);
  ASSERT_NEAR(-2.21141088014153e+19, r[2], 2.21141088014e+12);
}

TEST(QuadraticRootTest, Test_174) {
  double r[3];
  double a[] = {9.6594427244582e-200, -2.21141088014153e-181, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.21141088014153e+19, r[1], 2.21141088014e+12);
  ASSERT_NEAR(4.368e-19, r[2], 4.368e-26);
}

TEST(QuadraticRootTest, Test_175) {
  double r[3];
  double a[] = {9.6594427244582e-100, -2.21141088014153e-81, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.21141088014153e+19, r[1], 2.21141088014e+12);
  ASSERT_NEAR(4.368e-19, r[2], 4.368e-26);
}

TEST(QuadraticRootTest, Test_176) {
  double r[3];
  double a[] = {9.6594427244582, -2.21141088014153e+19, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.21141088014153e+19, r[1], 2.21141088014e+12);
  ASSERT_NEAR(4.368e-19, r[2], 4.368e-26);
}

TEST(QuadraticRootTest, Test_177) {
  double r[3];
  double a[] = {9.6594427244582e+100, -2.21141088014153e+119, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.21141088014153e+19, r[1], 2.21141088014e+12);
  ASSERT_NEAR(4.368e-19, r[2], 4.368e-26);
}

TEST(QuadraticRootTest, Test_178) {
  double r[3];
  double a[] = {9.6594427244582e+200, -2.21141088014153e+219, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.21141088014153e+19, r[1], 2.21141088014e+12);
  ASSERT_NEAR(4.368e-19, r[2], 4.368e-26);
}

TEST(QuadraticRootTest, Test_179) {
  double r[3];
  double a[] = {-9.6594427244582e-200, -2.21141088014153e-181, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.21141088014153e+19, r[1], 2.21141088014e+12);
  ASSERT_NEAR(-4.368e-19, r[2], 4.368e-26);
}

TEST(QuadraticRootTest, Test_180) {
  double r[3];
  double a[] = {-9.6594427244582e-100, -2.21141088014153e-81, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.21141088014153e+19, r[1], 2.21141088014e+12);
  ASSERT_NEAR(-4.368e-19, r[2], 4.368e-26);
}

TEST(QuadraticRootTest, Test_181) {
  double r[3];
  double a[] = {-9.6594427244582, -2.21141088014153e+19, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.21141088014153e+19, r[1], 2.21141088014e+12);
  ASSERT_NEAR(-4.368e-19, r[2], 4.368e-26);
}

TEST(QuadraticRootTest, Test_182) {
  double r[3];
  double a[] = {-9.6594427244582e+100, -2.21141088014153e+119, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.21141088014153e+19, r[1], 2.21141088014e+12);
  ASSERT_NEAR(-4.368e-19, r[2], 4.368e-26);
}

TEST(QuadraticRootTest, Test_183) {
  double r[3];
  double a[] = {-9.6594427244582e+200, -2.21141088014153e+219, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.21141088014153e+19, r[1], 2.21141088014e+12);
  ASSERT_NEAR(-4.368e-19, r[2], 4.368e-26);
}

TEST(QuadraticRootTest, Test_184) {
  double r[3];
  double a[] = {-1.01144164759725e-199, 1.634521085322e-179, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(6.188e-21, r[1], 6.188e-28);
  ASSERT_NEAR(-1.634521085322e+21, r[2], 1.63452108532e+14);
}

TEST(QuadraticRootTest, Test_185) {
  double r[3];
  double a[] = {-1.01144164759725e-99, 1.634521085322e-79, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(6.188e-21, r[1], 6.188e-28);
  ASSERT_NEAR(-1.634521085322e+21, r[2], 1.63452108532e+14);
}

TEST(QuadraticRootTest, Test_186) {
  double r[3];
  double a[] = {-10.1144164759725, 1.634521085322e+21, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(6.188e-21, r[1], 6.188e-28);
  ASSERT_NEAR(-1.634521085322e+21, r[2], 1.63452108532e+14);
}

TEST(QuadraticRootTest, Test_187) {
  double r[3];
  double a[] = {-1.01144164759725e+101, 1.634521085322e+121, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(6.188e-21, r[1], 6.188e-28);
  ASSERT_NEAR(-1.634521085322e+21, r[2], 1.63452108532e+14);
}

TEST(QuadraticRootTest, Test_188) {
  double r[3];
  double a[] = {-1.01144164759725e+201, 1.634521085322e+221, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(6.188e-21, r[1], 6.188e-28);
  ASSERT_NEAR(-1.634521085322e+21, r[2], 1.63452108532e+14);
}

TEST(QuadraticRootTest, Test_189) {
  double r[3];
  double a[] = {1.01144164759725e-199, -1.634521085322e-179, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.634521085322e+21, r[1], 1.63452108532e+14);
  ASSERT_NEAR(6.188e-21, r[2], 6.188e-28);
}

TEST(QuadraticRootTest, Test_190) {
  double r[3];
  double a[] = {1.01144164759725e-99, -1.634521085322e-79, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.634521085322e+21, r[1], 1.63452108532e+14);
  ASSERT_NEAR(6.188e-21, r[2], 6.188e-28);
}

TEST(QuadraticRootTest, Test_191) {
  double r[3];
  double a[] = {10.1144164759725, -1.634521085322e+21, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.634521085322e+21, r[1], 1.63452108532e+14);
  ASSERT_NEAR(6.188e-21, r[2], 6.188e-28);
}

TEST(QuadraticRootTest, Test_192) {
  double r[3];
  double a[] = {1.01144164759725e+101, -1.634521085322e+121, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.634521085322e+21, r[1], 1.63452108532e+14);
  ASSERT_NEAR(6.188e-21, r[2], 6.188e-28);
}

TEST(QuadraticRootTest, Test_193) {
  double r[3];
  double a[] = {1.01144164759725e+201, -1.634521085322e+221, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.634521085322e+21, r[1], 1.63452108532e+14);
  ASSERT_NEAR(6.188e-21, r[2], 6.188e-28);
}

TEST(QuadraticRootTest, Test_194) {
  double r[3];
  double a[] = {-1.01144164759725e-199, -1.634521085322e-179, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.634521085322e+21, r[1], 1.63452108532e+14);
  ASSERT_NEAR(-6.188e-21, r[2], 6.188e-28);
}

TEST(QuadraticRootTest, Test_195) {
  double r[3];
  double a[] = {-1.01144164759725e-99, -1.634521085322e-79, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.634521085322e+21, r[1], 1.63452108532e+14);
  ASSERT_NEAR(-6.188e-21, r[2], 6.188e-28);
}

TEST(QuadraticRootTest, Test_196) {
  double r[3];
  double a[] = {-10.1144164759725, -1.634521085322e+21, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.634521085322e+21, r[1], 1.63452108532e+14);
  ASSERT_NEAR(-6.188e-21, r[2], 6.188e-28);
}

TEST(QuadraticRootTest, Test_197) {
  double r[3];
  double a[] = {-1.01144164759725e+101, -1.634521085322e+121, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.634521085322e+21, r[1], 1.63452108532e+14);
  ASSERT_NEAR(-6.188e-21, r[2], 6.188e-28);
}

TEST(QuadraticRootTest, Test_198) {
  double r[3];
  double a[] = {-1.01144164759725e+201, -1.634521085322e+221, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.634521085322e+21, r[1], 1.63452108532e+14);
  ASSERT_NEAR(-6.188e-21, r[2], 6.188e-28);
}

TEST(QuadraticRootTest, Test_199) {
  double r[3];
  double a[] = {-1.06434782608696e-199, 1.24223602484472e-177, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(8.568e-23, r[1], 8.568e-30);
  ASSERT_NEAR(-1.24223602484472e+23, r[2], 1.24223602484e+16);
}

TEST(QuadraticRootTest, Test_200) {
  double r[3];
  double a[] = {-1.06434782608696e-99, 1.24223602484472e-77, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(8.568e-23, r[1], 8.568e-30);
  ASSERT_NEAR(-1.24223602484472e+23, r[2], 1.24223602484e+16);
}

TEST(QuadraticRootTest, Test_201) {
  double r[3];
  double a[] = {-10.6434782608696, 1.24223602484472e+23, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(8.568e-23, r[1], 8.568e-30);
  ASSERT_NEAR(-1.24223602484472e+23, r[2], 1.24223602484e+16);
}

TEST(QuadraticRootTest, Test_202) {
  double r[3];
  double a[] = {-1.06434782608696e+101, 1.24223602484472e+123, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(8.568e-23, r[1], 8.568e-30);
  ASSERT_NEAR(-1.24223602484472e+23, r[2], 1.24223602484e+16);
}

TEST(QuadraticRootTest, Test_203) {
  double r[3];
  double a[] = {-1.06434782608696e+201, 1.24223602484472e+223, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(8.568e-23, r[1], 8.568e-30);
  ASSERT_NEAR(-1.24223602484472e+23, r[2], 1.24223602484e+16);
}

TEST(QuadraticRootTest, Test_204) {
  double r[3];
  double a[] = {1.06434782608696e-199, -1.24223602484472e-177, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.24223602484472e+23, r[1], 1.24223602484e+16);
  ASSERT_NEAR(8.568e-23, r[2], 8.568e-30);
}

TEST(QuadraticRootTest, Test_205) {
  double r[3];
  double a[] = {1.06434782608696e-99, -1.24223602484472e-77, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.24223602484472e+23, r[1], 1.24223602484e+16);
  ASSERT_NEAR(8.568e-23, r[2], 8.568e-30);
}

TEST(QuadraticRootTest, Test_206) {
  double r[3];
  double a[] = {10.6434782608696, -1.24223602484472e+23, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.24223602484472e+23, r[1], 1.24223602484e+16);
  ASSERT_NEAR(8.568e-23, r[2], 8.568e-30);
}

TEST(QuadraticRootTest, Test_207) {
  double r[3];
  double a[] = {1.06434782608696e+101, -1.24223602484472e+123, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.24223602484472e+23, r[1], 1.24223602484e+16);
  ASSERT_NEAR(8.568e-23, r[2], 8.568e-30);
}

TEST(QuadraticRootTest, Test_208) {
  double r[3];
  double a[] = {1.06434782608696e+201, -1.24223602484472e+223, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.24223602484472e+23, r[1], 1.24223602484e+16);
  ASSERT_NEAR(8.568e-23, r[2], 8.568e-30);
}

TEST(QuadraticRootTest, Test_209) {
  double r[3];
  double a[] = {-1.06434782608696e-199, -1.24223602484472e-177, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.24223602484472e+23, r[1], 1.24223602484e+16);
  ASSERT_NEAR(-8.568e-23, r[2], 8.568e-30);
}

TEST(QuadraticRootTest, Test_210) {
  double r[3];
  double a[] = {-1.06434782608696e-99, -1.24223602484472e-77, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.24223602484472e+23, r[1], 1.24223602484e+16);
  ASSERT_NEAR(-8.568e-23, r[2], 8.568e-30);
}

TEST(QuadraticRootTest, Test_211) {
  double r[3];
  double a[] = {-10.6434782608696, -1.24223602484472e+23, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.24223602484472e+23, r[1], 1.24223602484e+16);
  ASSERT_NEAR(-8.568e-23, r[2], 8.568e-30);
}

TEST(QuadraticRootTest, Test_212) {
  double r[3];
  double a[] = {-1.06434782608696e+101, -1.24223602484472e+123, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.24223602484472e+23, r[1], 1.24223602484e+16);
  ASSERT_NEAR(-8.568e-23, r[2], 8.568e-30);
}

TEST(QuadraticRootTest, Test_213) {
  double r[3];
  double a[] = {-1.06434782608696e+201, -1.24223602484472e+223, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.24223602484472e+23, r[1], 1.24223602484e+16);
  ASSERT_NEAR(-8.568e-23, r[2], 8.568e-30);
}

TEST(QuadraticRootTest, Test_214) {
  double r[3];
  double a[] = {-1.12347826086957e-199, 9.66183574879227e-176, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1628e-24, r[1], 1.1628e-31);
  ASSERT_NEAR(-9.66183574879227e+24, r[2], 9.66183574879e+17);
}

TEST(QuadraticRootTest, Test_215) {
  double r[3];
  double a[] = {-1.12347826086957e-99, 9.66183574879227e-76, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1628e-24, r[1], 1.1628e-31);
  ASSERT_NEAR(-9.66183574879227e+24, r[2], 9.66183574879e+17);
}

TEST(QuadraticRootTest, Test_216) {
  double r[3];
  double a[] = {-11.2347826086957, 9.66183574879227e+24, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1628e-24, r[1], 1.1628e-31);
  ASSERT_NEAR(-9.66183574879227e+24, r[2], 9.66183574879e+17);
}

TEST(QuadraticRootTest, Test_217) {
  double r[3];
  double a[] = {-1.12347826086957e+101, 9.66183574879227e+124, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1628e-24, r[1], 1.1628e-31);
  ASSERT_NEAR(-9.66183574879227e+24, r[2], 9.66183574879e+17);
}

TEST(QuadraticRootTest, Test_218) {
  double r[3];
  double a[] = {-1.12347826086957e+201, 9.66183574879227e+224, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1628e-24, r[1], 1.1628e-31);
  ASSERT_NEAR(-9.66183574879227e+24, r[2], 9.66183574879e+17);
}

TEST(QuadraticRootTest, Test_219) {
  double r[3];
  double a[] = {1.12347826086957e-199, -9.66183574879227e-176, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9.66183574879227e+24, r[1], 9.66183574879e+17);
  ASSERT_NEAR(1.1628e-24, r[2], 1.1628e-31);
}

TEST(QuadraticRootTest, Test_220) {
  double r[3];
  double a[] = {1.12347826086957e-99, -9.66183574879227e-76, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9.66183574879227e+24, r[1], 9.66183574879e+17);
  ASSERT_NEAR(1.1628e-24, r[2], 1.1628e-31);
}

TEST(QuadraticRootTest, Test_221) {
  double r[3];
  double a[] = {11.2347826086957, -9.66183574879227e+24, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9.66183574879227e+24, r[1], 9.66183574879e+17);
  ASSERT_NEAR(1.1628e-24, r[2], 1.1628e-31);
}

TEST(QuadraticRootTest, Test_222) {
  double r[3];
  double a[] = {1.12347826086957e+101, -9.66183574879227e+124, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9.66183574879227e+24, r[1], 9.66183574879e+17);
  ASSERT_NEAR(1.1628e-24, r[2], 1.1628e-31);
}

TEST(QuadraticRootTest, Test_223) {
  double r[3];
  double a[] = {1.12347826086957e+201, -9.66183574879227e+224, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9.66183574879227e+24, r[1], 9.66183574879e+17);
  ASSERT_NEAR(1.1628e-24, r[2], 1.1628e-31);
}

TEST(QuadraticRootTest, Test_224) {
  double r[3];
  double a[] = {-1.12347826086957e-199, -9.66183574879227e-176, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9.66183574879227e+24, r[1], 9.66183574879e+17);
  ASSERT_NEAR(-1.1628e-24, r[2], 1.1628e-31);
}

TEST(QuadraticRootTest, Test_225) {
  double r[3];
  double a[] = {-1.12347826086957e-99, -9.66183574879227e-76, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9.66183574879227e+24, r[1], 9.66183574879e+17);
  ASSERT_NEAR(-1.1628e-24, r[2], 1.1628e-31);
}

TEST(QuadraticRootTest, Test_226) {
  double r[3];
  double a[] = {-11.2347826086957, -9.66183574879227e+24, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9.66183574879227e+24, r[1], 9.66183574879e+17);
  ASSERT_NEAR(-1.1628e-24, r[2], 1.1628e-31);
}

TEST(QuadraticRootTest, Test_227) {
  double r[3];
  double a[] = {-1.12347826086957e+101, -9.66183574879227e+124, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9.66183574879227e+24, r[1], 9.66183574879e+17);
  ASSERT_NEAR(-1.1628e-24, r[2], 1.1628e-31);
}

TEST(QuadraticRootTest, Test_228) {
  double r[3];
  double a[] = {-1.12347826086957e+201, -9.66183574879227e+224, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9.66183574879227e+24, r[1], 9.66183574879e+17);
  ASSERT_NEAR(-1.1628e-24, r[2], 1.1628e-31);
}

TEST(QuadraticRootTest, Test_229) {
  double r[3];
  double a[] = {-1.18804597701149e-199, 7.66283524904215e-174, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5504e-26, r[1], 1.5504e-33);
  ASSERT_NEAR(-7.66283524904215e+26, r[2], 7.66283524904e+19);
}

TEST(QuadraticRootTest, Test_230) {
  double r[3];
  double a[] = {-1.18804597701149e-99, 7.66283524904215e-74, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5504e-26, r[1], 1.5504e-33);
  ASSERT_NEAR(-7.66283524904215e+26, r[2], 7.66283524904e+19);
}

TEST(QuadraticRootTest, Test_231) {
  double r[3];
  double a[] = {-11.8804597701149, 7.66283524904215e+26, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5504e-26, r[1], 1.5504e-33);
  ASSERT_NEAR(-7.66283524904215e+26, r[2], 7.66283524904e+19);
}

TEST(QuadraticRootTest, Test_232) {
  double r[3];
  double a[] = {-1.18804597701149e+101, 7.66283524904215e+126, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5504e-26, r[1], 1.5504e-33);
  ASSERT_NEAR(-7.66283524904215e+26, r[2], 7.66283524904e+19);
}

TEST(QuadraticRootTest, Test_233) {
  double r[3];
  double a[] = {-1.18804597701149e+201, 7.66283524904215e+226, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.5504e-26, r[1], 1.5504e-33);
  ASSERT_NEAR(-7.66283524904215e+26, r[2], 7.66283524904e+19);
}

TEST(QuadraticRootTest, Test_234) {
  double r[3];
  double a[] = {1.18804597701149e-199, -7.66283524904215e-174, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.66283524904215e+26, r[1], 7.66283524904e+19);
  ASSERT_NEAR(1.5504e-26, r[2], 1.5504e-33);
}

TEST(QuadraticRootTest, Test_235) {
  double r[3];
  double a[] = {1.18804597701149e-99, -7.66283524904215e-74, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.66283524904215e+26, r[1], 7.66283524904e+19);
  ASSERT_NEAR(1.5504e-26, r[2], 1.5504e-33);
}

TEST(QuadraticRootTest, Test_236) {
  double r[3];
  double a[] = {11.8804597701149, -7.66283524904215e+26, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.66283524904215e+26, r[1], 7.66283524904e+19);
  ASSERT_NEAR(1.5504e-26, r[2], 1.5504e-33);
}

TEST(QuadraticRootTest, Test_237) {
  double r[3];
  double a[] = {1.18804597701149e+101, -7.66283524904215e+126, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.66283524904215e+26, r[1], 7.66283524904e+19);
  ASSERT_NEAR(1.5504e-26, r[2], 1.5504e-33);
}

TEST(QuadraticRootTest, Test_238) {
  double r[3];
  double a[] = {1.18804597701149e+201, -7.66283524904215e+226, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.66283524904215e+26, r[1], 7.66283524904e+19);
  ASSERT_NEAR(1.5504e-26, r[2], 1.5504e-33);
}

TEST(QuadraticRootTest, Test_239) {
  double r[3];
  double a[] = {-1.18804597701149e-199, -7.66283524904215e-174, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.66283524904215e+26, r[1], 7.66283524904e+19);
  ASSERT_NEAR(-1.5504e-26, r[2], 1.5504e-33);
}

TEST(QuadraticRootTest, Test_240) {
  double r[3];
  double a[] = {-1.18804597701149e-99, -7.66283524904215e-74, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.66283524904215e+26, r[1], 7.66283524904e+19);
  ASSERT_NEAR(-1.5504e-26, r[2], 1.5504e-33);
}

TEST(QuadraticRootTest, Test_241) {
  double r[3];
  double a[] = {-11.8804597701149, -7.66283524904215e+26, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.66283524904215e+26, r[1], 7.66283524904e+19);
  ASSERT_NEAR(-1.5504e-26, r[2], 1.5504e-33);
}

TEST(QuadraticRootTest, Test_242) {
  double r[3];
  double a[] = {-1.18804597701149e+101, -7.66283524904215e+126, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.66283524904215e+26, r[1], 7.66283524904e+19);
  ASSERT_NEAR(-1.5504e-26, r[2], 1.5504e-33);
}

TEST(QuadraticRootTest, Test_243) {
  double r[3];
  double a[] = {-1.18804597701149e+201, -7.66283524904215e+226, 1e+200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.66283524904215e+26, r[1], 7.66283524904e+19);
  ASSERT_NEAR(-1.5504e-26, r[2], 1.5504e-33);
}

TEST(QuadraticRootTest, Test_244) {
  double r[3];
  double a[] = {4, 5, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.833333333333333, r[1], 1e-07);
  ASSERT_NEAR(0.799305253885453, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_245) {
  double r[3];
  double a[] = {4, 5, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1, r[1], 1e-07);
  ASSERT_NEAR(-4, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_246) {
  double r[3];
  double a[] = {4, 5, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.70156211871642, r[1], 1e-07);
  ASSERT_NEAR(-0.701562118716424, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_247) {
  double r[3];
  double a[] = {4, 5, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.25733395755292, r[1], 1e-07);
  ASSERT_NEAR(-0.590667290886255, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_248) {
  double r[3];
  double a[] = {4, 2, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.333333333333333, r[1], 1e-07);
  ASSERT_NEAR(1.10554159678513, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_249) {
  double r[3];
  double a[] = {4, 2, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-1, r[1], 1e-07);
  ASSERT_NEAR(1.73205080756888, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_250) {
  double r[3];
  double a[] = {4, 2, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.23606797749979, r[1], 1e-07);
  ASSERT_NEAR(-1.23606797749979, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_251) {
  double r[3];
  double a[] = {4, 2, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.535183758488, r[1], 1e-07);
  ASSERT_NEAR(-0.86851709182133, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_252) {
  double r[3];
  double a[] = {4, -1, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.166666666666667, r[1], 1e-07);
  ASSERT_NEAR(1.14260910006684, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_253) {
  double r[3];
  double a[] = {4, -1, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.5, r[1], 1e-07);
  ASSERT_NEAR(1.93649167310371, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_254) {
  double r[3];
  double a[] = {4, -1, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.56155281280883, r[1], 1e-07);
  ASSERT_NEAR(-2.56155281280883, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_255) {
  double r[3];
  double a[] = {4, -1, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r[1], 1e-07);
  ASSERT_NEAR(-1.33333333333333, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_256) {
  double r[3];
  double a[] = {4, -4, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.666666666666667, r[1], 1e-07);
  ASSERT_NEAR(0.942809041582063, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_257) {
  double r[3];
  double a[] = {4, -4, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(2, r[1], 1e-07);
  ASSERT_NEAR(2, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_258) {
  double r[3];
  double a[] = {4, -4, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.82842712474619, r[1], 1e-07);
  ASSERT_NEAR(-4.82842712474619, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_259) {
  double r[3];
  double a[] = {4, -4, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.666666666666667, r[1], 1e-07);
  ASSERT_NEAR(-2, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_260) {
  double r[3];
  double a[] = {1, 5, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.232408120756002, r[1], 1e-07);
  ASSERT_NEAR(-1.43425854591066, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_261) {
  double r[3];
  double a[] = {1, 5, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.20871215252208, r[1], 1e-07);
  ASSERT_NEAR(-4.79128784747792, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_262) {
  double r[3];
  double a[] = {1, 5, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.19258240356725, r[1], 1e-07);
  ASSERT_NEAR(-0.192582403567252, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_263) {
  double r[3];
  double a[] = {1, 5, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.84712708838304, r[1], 1e-07);
  ASSERT_NEAR(-0.18046042171637, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_264) {
  double r[3];
  double a[] = {1, 2, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.333333333333333, r[1], 1e-07);
  ASSERT_NEAR(0.471404520791032, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_265) {
  double r[3];
  double a[] = {1, 2, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(-1, r[1], 1e-07);
  ASSERT_NEAR(-1, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_266) {
  double r[3];
  double a[] = {1, 2, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.41421356237309, r[1], 1e-07);
  ASSERT_NEAR(-0.414213562373095, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_267) {
  double r[3];
  double a[] = {1, 2, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r[1], 1e-07);
  ASSERT_NEAR(-0.333333333333333, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_268) {
  double r[3];
  double a[] = {1, -1, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.166666666666667, r[1], 1e-07);
  ASSERT_NEAR(0.552770798392567, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_269) {
  double r[3];
  double a[] = {1, -1, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.5, r[1], 1e-07);
  ASSERT_NEAR(0.866025403784439, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_270) {
  double r[3];
  double a[] = {1, -1, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.618033988749895, r[1], 1e-07);
  ASSERT_NEAR(-1.61803398874989, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_271) {
  double r[3];
  double a[] = {1, -1, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.434258545910665, r[1], 1e-07);
  ASSERT_NEAR(-0.767591879243998, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_272) {
  double r[3];
  double a[] = {1, -4, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r[1], 1e-07);
  ASSERT_NEAR(0.333333333333333, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_273) {
  double r[3];
  double a[] = {1, -4, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.73205080756888, r[1], 1e-07);
  ASSERT_NEAR(0.267949192431123, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_274) {
  double r[3];
  double a[] = {1, -4, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.23606797749979, r[1], 1e-07);
  ASSERT_NEAR(-4.23606797749979, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_275) {
  double r[3];
  double a[] = {1, -4, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.21525043702153, r[1], 1e-07);
  ASSERT_NEAR(-1.54858377035486, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_276) {
  double r[3];
  double a[] = {-2, 5, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.333333333333333, r[1], 1e-07);
  ASSERT_NEAR(-2, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_277) {
  double r[3];
  double a[] = {-2, 5, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.372281323269014, r[1], 1e-07);
  ASSERT_NEAR(-5.37228132326901, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_278) {
  double r[3];
  double a[] = {-2, 5, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.56155281280883, r[1], 1e-07);
  ASSERT_NEAR(0.43844718719117, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_279) {
  double r[3];
  double a[] = {-2, 5, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r[1], 1e-07);
  ASSERT_NEAR(0.666666666666667, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_280) {
  double r[3];
  double a[] = {-2, 2, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.548583770354863, r[1], 1e-07);
  ASSERT_NEAR(-1.21525043702153, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_281) {
  double r[3];
  double a[] = {-2, 2, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.732050807568877, r[1], 1e-07);
  ASSERT_NEAR(-2.73205080756888, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_282) {
  double r[3];
  double a[] = {-2, 2, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1, r[1], 1e-07);
  ASSERT_NEAR(1, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_283) {
  double r[3];
  double a[] = {-2, 2, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.333333333333333, r[1], 1e-07);
  ASSERT_NEAR(0.74535599249993, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_284) {
  double r[3];
  double a[] = {-2, -1, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r[1], 1e-07);
  ASSERT_NEAR(-0.666666666666667, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_285) {
  double r[3];
  double a[] = {-2, -1, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r[1], 1e-07);
  ASSERT_NEAR(-1, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_286) {
  double r[3];
  double a[] = {-2, -1, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.5, r[1], 1e-07);
  ASSERT_NEAR(1.3228756555323, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_287) {
  double r[3];
  double a[] = {-2, -1, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.166666666666667, r[1], 1e-07);
  ASSERT_NEAR(0.799305253885453, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_288) {
  double r[3];
  double a[] = {-2, -4, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.72075922005613, r[1], 1e-07);
  ASSERT_NEAR(-0.387425886722793, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_289) {
  double r[3];
  double a[] = {-2, -4, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.44948974278318, r[1], 1e-07);
  ASSERT_NEAR(-0.449489742783178, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_290) {
  double r[3];
  double a[] = {-2, -4, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.585786437626905, r[1], 1e-07);
  ASSERT_NEAR(-3.41421356237309, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_291) {
  double r[3];
  double a[] = {-2, -4, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.666666666666667, r[1], 1e-07);
  ASSERT_NEAR(0.471404520791032, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_292) {
  double r[3];
  double a[] = {-5, 5, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.703257409548815, r[1], 1e-07);
  ASSERT_NEAR(-2.36992407621548, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_293) {
  double r[3];
  double a[] = {-5, 5, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.854101966249684, r[1], 1e-07);
  ASSERT_NEAR(-5.85410196624968, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_294) {
  double r[3];
  double a[] = {-5, 5, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.61803398874989, r[1], 1e-07);
  ASSERT_NEAR(1.38196601125011, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_295) {
  double r[3];
  double a[] = {-5, 5, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.833333333333333, r[1], 1e-07);
  ASSERT_NEAR(0.986013297183269, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_296) {
  double r[3];
  double a[] = {-5, 2, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r[1], 1e-07);
  ASSERT_NEAR(-1.66666666666667, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_297) {
  double r[3];
  double a[] = {-5, 2, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.44948974278318, r[1], 1e-07);
  ASSERT_NEAR(-3.44948974278318, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_298) {
  double r[3];
  double a[] = {-5, 2, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1, r[1], 1e-07);
  ASSERT_NEAR(2, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_299) {
  double r[3];
  double a[] = {-5, 2, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.333333333333333, r[1], 1e-07);
  ASSERT_NEAR(1.24721912892465, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_300) {
  double r[3];
  double a[] = {-5, -1, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.46837494598444, r[1], 1e-07);
  ASSERT_NEAR(-1.13504161265111, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_301) {
  double r[3];
  double a[] = {-5, -1, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.79128784747792, r[1], 1e-07);
  ASSERT_NEAR(-1.79128784747792, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_302) {
  double r[3];
  double a[] = {-5, -1, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.5, r[1], 1e-07);
  ASSERT_NEAR(2.17944947177034, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_303) {
  double r[3];
  double a[] = {-5, -1, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.166666666666667, r[1], 1e-07);
  ASSERT_NEAR(1.2801909579781, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_304) {
  double r[3];
  double a[] = {-5, -4, 3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.11963298118022, r[1], 1e-07);
  ASSERT_NEAR(-0.786299647846891, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_305) {
  double r[3];
  double a[] = {-5, -4, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5, r[1], 1e-07);
  ASSERT_NEAR(-1, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_306) {
  double r[3];
  double a[] = {-5, -4, -1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-2, r[1], 1e-07);
  ASSERT_NEAR(1, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_307) {
  double r[3];
  double a[] = {-5, -4, -3};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.666666666666667, r[1], 1e-07);
  ASSERT_NEAR(1.10554159678513, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_308) {
  double r[3];
  double a[] = {2.09e+202, -30, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.9e+201, r[1], 1.9e+194);
  ASSERT_NEAR(1.1e+201, r[2], 1.1e+194);
}

TEST(QuadraticRootTest, Test_309) {
  double r[3];
  double a[] = {33, -1.1e+201, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1e+201, r[1], 1.1e+194);
  ASSERT_NEAR(3e-200, r[2], 3e-207);
}

TEST(QuadraticRootTest, Test_310) {
  double r[3];
  double a[] = {3.3e-199, -11, 1e-200};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1e+201, r[1], 1.1e+194);
  ASSERT_NEAR(3e-200, r[2], 3e-207);
}

TEST(QuadraticRootTest, Test_311) {
  double r[3];
  double a[] = {2e+300, -3e+300, 1e+300};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r[1], 1e-07);
  ASSERT_NEAR(1, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_312) {
  double r[3];
  double a[] = {2e-300, -3e-300, 1e-300};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r[1], 1e-07);
  ASSERT_NEAR(1, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_313) {
  double r[3];
  double a[] = {1e-300, 1e-300, 1e-300};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.5, r[1], 1e-07);
  ASSERT_NEAR(0.866025403784439, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_314) {
  double r[3];
  double a[] = {1, 1e+200, 1};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1e-200, r[1], 1e-207);
  ASSERT_NEAR(-1e+200, r[2], 1e+193);
}

TEST(QuadraticRootTest, Test_315) {
  double r[3];
  double a[] = {2e+90, 1e+155, 1e+75};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2e-65, r[1], 2e-72);
  ASSERT_NEAR(-1e+80, r[2], 1e+73);
}

TEST(QuadraticRootTest, Test_316) {
  double r[3];
  double a[] = {1.7976931348623157E+308, 8.98846567431158e+307, 1.7976931348623157E+308};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.25, r[1], 1e-07);
  ASSERT_NEAR(0.968245836551854, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_317) {
  double r[3];
  double a[] = {1e+307, 1e+307, -1e+307};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.61803398874989, r[1], 1e-07);
  ASSERT_NEAR(-0.618033988749895, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_318) {
  double r[3];
  double a[] = {1e-100, 1e+107, 1e-100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1e-207, r[1], 1e-214);
  ASSERT_NEAR(-1e+207, r[2], 1e+200);
}

TEST(QuadraticRootTest, Test_319) {
  double r[3];
  double a[] = {-1e+307, 1e+307, -1e+307};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0.5, r[1], 1e-07);
  ASSERT_NEAR(0.86602540378443, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_320) {
  double r[3];
  double a[] = {3e+307, 5, 3e+307};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-8.33333333333333e-308, r[1], 8.33333333221e-315);
  ASSERT_NEAR(1, r[2], 1e-07);
}

TEST(QuadraticRootTest, Test_321) {
  double r[3];
  double a[] = {4e-307, 2e-200, 3e-307};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2e-107, r[1], 2e-114);
  ASSERT_NEAR(-6.66666666666667e+106, r[2], 6.66666666667e+99);
}

TEST(QuadraticRootTest, Test_322) {
  double r[3];
  double a[] = {7e+200, 5e+297, 2e+307};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.4e-97, r[1], 1.4e-104);
  ASSERT_NEAR(-2.5e-10, r[2], 2.5e-17);
}

TEST(QuadraticRootTest, Test_323) {
  double r[3];
  double a[] = {9.48075190810918e+153, 1.7976931348623157E+308, 1.34078079299426e+154};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-5.2738433074315e-155, r[1], 5.27384330743e-162);
  ASSERT_NEAR(-1.34078079299426e+154, r[2], 1.34078079299e+147);
}

TEST(QuadraticRootTest, Test_324) {
  double r[3];
  double a[] = {1.34078079299426e+154, 1.7976931348623157E+308, 7.74100151759516e+153};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-7.45834073120021e-155, r[1], 7.4583407312e-162);
  ASSERT_NEAR(-2.32230045527855e+154, r[2], 2.32230045528e+147);
}

TEST(QuadraticRootTest, Test_325) {
  double r[3];
  double a[] = {7.74100151759516e+153, 1.7976931348623157E+308, 9.48075190810918e+153};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-4.30607502886639e-155, r[1], 4.30607502887e-162);
  ASSERT_NEAR(-1.89615038162184e+154, r[2], 1.89615038162e+147);
}

TEST(QuadraticRootTest, Test_326) {
  double r[3];
  double a[] = {1e+300, 1e+200, 1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-5e+99, r[1], 5e+92);
  ASSERT_NEAR(8.66025403784439e+99, r[2], 8.66025403784e+92);
}

TEST(QuadraticRootTest, Test_327) {
  double r[3];
  double a[] = {1e+300, 1e+200, -1e+100};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.61803398874989e+100, r[1], 1.61803398875e+93);
  ASSERT_NEAR(-6.18033988749895e+99, r[2], 6.1803398875e+92);
}

TEST(QuadraticRootTest, Test_328) {
  double r[3];
  double a[] = {1e+308, 1e+308, 1e+308};
  int num_roots = quad_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-0.5, r[1], 1e-07);
  ASSERT_NEAR(0.866025403784439, r[2], 1e-07);
}

