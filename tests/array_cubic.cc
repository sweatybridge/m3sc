#include <gtest/gtest.h>

extern "C" {
int rcubic_roots(double *a, double *r);
}

TEST(CubicRootTest, Test_1) {
  double r[4];
  double a[] = {6, -5, -2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(3, r[1], 3e-05);
  ASSERT_NEAR(1, r[2], 1e-05);
  ASSERT_NEAR(-2, r[3], 2e-05);
}

TEST(CubicRootTest, Test_2) {
  double r[4];
  double a[] = {-13, 9, 3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1, r[1], 1e-05);
  ASSERT_NEAR(-2, r[2], 2e-05);
  ASSERT_NEAR(3, r[3], 3e-05);
}

TEST(CubicRootTest, Test_3) {
  double r[4];
  double a[] = {-1, -1, 1};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r[1], 1e-05);
  ASSERT_NEAR(-1, r[2], 1e-05);
  ASSERT_NEAR(-1, r[3], 1e-05);
}

TEST(CubicRootTest, Test_4) {
  double r[4];
  double a[] = {30, -11, -4};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(5, r[1], 5e-05);
  ASSERT_NEAR(2, r[2], 2e-05);
  ASSERT_NEAR(-3, r[3], 3e-05);
}

TEST(CubicRootTest, Test_5) {
  double r[4];
  double a[] = {-5, 3, 1};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1, r[1], 1e-05);
  ASSERT_NEAR(-1, r[2], 1e-05);
  ASSERT_NEAR(2, r[3], 2e-05);
}

TEST(CubicRootTest, Test_6) {
  double r[4];
  double a[] = {-2, -1, 2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1, r[1], 1e-05);
  ASSERT_NEAR(-1, r[2], 1e-05);
  ASSERT_NEAR(-2, r[3], 2e-05);
}

TEST(CubicRootTest, Test_7) {
  double r[4];
  double a[] = {125, 75, 15};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(-5, r[1], 5e-05);
  ASSERT_NEAR(-5, r[2], 5e-05);
  ASSERT_NEAR(-5, r[3], 5e-05);
}

TEST(CubicRootTest, Test_8) {
  double r[4];
  double a[] = {6, -5, -2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(3, r[1], 3e-05);
  ASSERT_NEAR(1, r[2], 1e-05);
  ASSERT_NEAR(-2, r[3], 2e-05);
}

TEST(CubicRootTest, Test_9) {
  double r[4];
  double a[] = {-27, 27, -9};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(3, r[1], 3e-05);
  ASSERT_NEAR(3, r[2], 3e-05);
  ASSERT_NEAR(3, r[3], 3e-05);
}

TEST(CubicRootTest, Test_10) {
  double r[4];
  double a[] = {-64, 0, 0};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(4, r[1], 4e-05);
  ASSERT_NEAR(-2, r[2], 2e-05);
  ASSERT_NEAR(3.4641016151377544, r[3], 3.46410161514e-05);
}

TEST(CubicRootTest, Test_11) {
  double r[4];
  double a[] = {64, 0, 0};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-4, r[1], 4e-05);
  ASSERT_NEAR(2, r[2], 2e-05);
  ASSERT_NEAR(3.4641016151377544, r[3], 3.46410161514e-05);
}

TEST(CubicRootTest, Test_12) {
  double r[4];
  double a[] = {0, 2, -3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(2, r[1], 2e-05);
  ASSERT_NEAR(1, r[2], 1e-05);
  ASSERT_NEAR(0, r[3], 0.0);
}

TEST(CubicRootTest, Test_13) {
  double r[4];
  double a[] = {-9, 9, -1};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1, r[1], 1e-05);
  ASSERT_NEAR(0, r[2], 0.0);
  ASSERT_NEAR(3, r[3], 3e-05);
}

TEST(CubicRootTest, Test_14) {
  double r[4];
  double a[] = {4, -7, 2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1, r[1], 1e-05);
  ASSERT_NEAR(1, r[2], 1e-05);
  ASSERT_NEAR(-4, r[3], 4e-05);
}

TEST(CubicRootTest, Test_15) {
  double r[4];
  double a[] = {-37, 27, 9};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1, r[1], 1e-05);
  ASSERT_NEAR(-5, r[2], 5e-05);
  ASSERT_NEAR(3.4641016151377544, r[3], 3.46410161514e-05);
}

TEST(CubicRootTest, Test_16) {
  double r[4];
  double a[] = {-9, 5, 3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1, r[1], 1e-05);
  ASSERT_NEAR(-2, r[2], 2e-05);
  ASSERT_NEAR(2.2360679774997898, r[3], 2.2360679775e-05);
}

TEST(CubicRootTest, Test_17) {
  double r[4];
  double a[] = {7, -5, -3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(3.8284271247461898, r[1], 3.82842712475e-05);
  ASSERT_NEAR(1, r[2], 1e-05);
  ASSERT_NEAR(-1.8284271247461901, r[3], 1.82842712475e-05);
}

TEST(CubicRootTest, Test_18) {
  double r[4];
  double a[] = {8, 4, 2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-2, r[1], 2e-05);
  ASSERT_NEAR(0, r[2], 0.0);
  ASSERT_NEAR(2, r[3], 2e-05);
}

TEST(CubicRootTest, Test_19) {
  double r[4];
  double a[] = {8, 4, 0};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-1.3646556076560388, r[1], 1.36465560766e-05);
  ASSERT_NEAR(0.68232780382801939, r[2], 6.82327803828e-06);
  ASSERT_NEAR(2.3230827999945038, r[3], 2.32308279999e-05);
}

TEST(CubicRootTest, Test_20) {
  double r[4];
  double a[] = {8, 4, -2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-1.0873780253841527, r[1], 1.08737802538e-05);
  ASSERT_NEAR(1.5436890126920764, r[2], 1.54368901269e-05);
  ASSERT_NEAR(2.2302850160798746, r[3], 2.23028501608e-05);
}

TEST(CubicRootTest, Test_21) {
  double r[4];
  double a[] = {8, 0, 2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-2.9311424637535359, r[1], 2.93114246375e-05);
  ASSERT_NEAR(0.46557123187676813, r[2], 4.65571231877e-06);
  ASSERT_NEAR(1.5851039850308959, r[3], 1.58510398503e-05);
}

TEST(CubicRootTest, Test_22) {
  double r[4];
  double a[] = {8, 0, 0};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-2, r[1], 2e-05);
  ASSERT_NEAR(1, r[2], 1e-05);
  ASSERT_NEAR(1.7320508075688772, r[3], 1.73205080757e-05);
}

TEST(CubicRootTest, Test_23) {
  double r[4];
  double a[] = {8, 0, -2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-1.5097553324933854, r[1], 1.50975533249e-05);
  ASSERT_NEAR(1.7548776662466927, r[2], 1.75487766625e-05);
  ASSERT_NEAR(1.4897235332394885, r[3], 1.48972353324e-05);
}

TEST(CubicRootTest, Test_24) {
  double r[4];
  double a[] = {8, -4, 2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-3.6785735104283224, r[1], 3.67857351043e-05);
  ASSERT_NEAR(0.83928675521416118, r[2], 8.39286755214e-06);
  ASSERT_NEAR(1.2125814584143988, r[3], 1.21258145841e-05);
}

TEST(CubicRootTest, Test_25) {
  double r[4];
  double a[] = {8, -4, 0};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(-2.6494359144894921, r[1], 2.64943591449e-05);
  ASSERT_NEAR(1.3247179572447461, r[2], 1.32471795724e-05);
  ASSERT_NEAR(1.1245590241246024, r[3], 1.12455902412e-05);
}

TEST(CubicRootTest, Test_26) {
  double r[4];
  double a[] = {8, -4, -2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r[1], 2e-05);
  ASSERT_NEAR(2, r[2], 2e-05);
  ASSERT_NEAR(-2, r[3], 2e-05);
}

TEST(CubicRootTest, Test_27) {
  double r[4];
  double a[] = {0, 4, 2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(-1, r[2], 1e-05);
  ASSERT_NEAR(1.7320508075688772, r[3], 1.73205080757e-05);
}

TEST(CubicRootTest, Test_28) {
  double r[4];
  double a[] = {0, 4, 0};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(0, r[2], 0.0);
  ASSERT_NEAR(2, r[3], 2e-05);
}

TEST(CubicRootTest, Test_29) {
  double r[4];
  double a[] = {0, 4, -2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(1, r[2], 1e-05);
  ASSERT_NEAR(1.7320508075688772, r[3], 1.73205080757e-05);
}

TEST(CubicRootTest, Test_30) {
  double r[4];
  double a[] = {0, 0, 2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(0, r[2], 0.0);
  ASSERT_NEAR(-2, r[3], 2e-05);
}

TEST(CubicRootTest, Test_31) {
  double r[4];
  double a[] = {0, 0, 0};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(1, num_roots);
  ASSERT_NEAR(0, r[1], 0.0);
  ASSERT_NEAR(0, r[2], 0.0);
  ASSERT_NEAR(0, r[3], 0.0);
}

TEST(CubicRootTest, Test_32) {
  double r[4];
  double a[] = {0, 0, -2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r[1], 2e-05);
  ASSERT_NEAR(0, r[2], 0.0);
  ASSERT_NEAR(0, r[3], 0.0);
}

TEST(CubicRootTest, Test_33) {
  double r[4];
  double a[] = {0, -4, 0};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(2, r[1], 2e-05);
  ASSERT_NEAR(0, r[2], 0.0);
  ASSERT_NEAR(-2, r[3], 2e-05);
}

TEST(CubicRootTest, Test_34) {
  double r[4];
  double a[] = {-8, 4, 2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1.0873780253841527, r[1], 1.08737802538e-05);
  ASSERT_NEAR(-1.5436890126920764, r[2], 1.54368901269e-05);
  ASSERT_NEAR(2.2302850160798746, r[3], 2.23028501608e-05);
}

TEST(CubicRootTest, Test_35) {
  double r[4];
  double a[] = {-8, 4, 0};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1.3646556076560388, r[1], 1.36465560766e-05);
  ASSERT_NEAR(-0.68232780382801939, r[2], 6.82327803828e-06);
  ASSERT_NEAR(2.3230827999945038, r[3], 2.32308279999e-05);
}

TEST(CubicRootTest, Test_36) {
  double r[4];
  double a[] = {-8, 4, -2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2, r[1], 2e-05);
  ASSERT_NEAR(0, r[2], 0.0);
  ASSERT_NEAR(2, r[3], 2e-05);
}

TEST(CubicRootTest, Test_37) {
  double r[4];
  double a[] = {-8, 0, 2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(1.5097553324933854, r[1], 1.50975533249e-05);
  ASSERT_NEAR(-1.7548776662466927, r[2], 1.75487766625e-05);
  ASSERT_NEAR(1.4897235332394885, r[3], 1.48972353324e-05);
}

TEST(CubicRootTest, Test_38) {
  double r[4];
  double a[] = {-8, 0, 0};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2, r[1], 2e-05);
  ASSERT_NEAR(-1, r[2], 1e-05);
  ASSERT_NEAR(1.7320508075688772, r[3], 1.73205080757e-05);
}

TEST(CubicRootTest, Test_39) {
  double r[4];
  double a[] = {-8, 0, -2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2.9311424637535359, r[1], 2.93114246375e-05);
  ASSERT_NEAR(-0.46557123187676813, r[2], 4.65571231877e-06);
  ASSERT_NEAR(1.5851039850308959, r[3], 1.58510398503e-05);
}

TEST(CubicRootTest, Test_40) {
  double r[4];
  double a[] = {-8, -4, 2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2, r[1], 2e-05);
  ASSERT_NEAR(-2, r[2], 2e-05);
  ASSERT_NEAR(-2, r[3], 2e-05);
}

TEST(CubicRootTest, Test_41) {
  double r[4];
  double a[] = {-8, -4, 0};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(2.6494359144894921, r[1], 2.64943591449e-05);
  ASSERT_NEAR(-1.3247179572447461, r[2], 1.32471795724e-05);
  ASSERT_NEAR(1.1245590241246024, r[3], 1.12455902412e-05);
}

TEST(CubicRootTest, Test_42) {
  double r[4];
  double a[] = {-8, -4, -2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(0, num_roots);
  ASSERT_NEAR(3.6785735104283224, r[1], 3.67857351043e-05);
  ASSERT_NEAR(-0.83928675521416118, r[2], 8.39286755214e-06);
  ASSERT_NEAR(1.2125814584143988, r[3], 1.21258145841e-05);
}

TEST(CubicRootTest, Test_43) {
  double r[4];
  double a[] = {0, -4, 2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1.2360679774997898, r[1], 1.2360679775e-05);
  ASSERT_NEAR(0, r[2], 0.0);
  ASSERT_NEAR(-3.2360679774997898, r[3], 3.2360679775e-05);
}

TEST(CubicRootTest, Test_44) {
  double r[4];
  double a[] = {0, -4, -2};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(3.2360679774997898, r[1], 3.2360679775e-05);
  ASSERT_NEAR(0, r[2], 0.0);
  ASSERT_NEAR(-1.2360679774997898, r[3], 1.2360679775e-05);
}

TEST(CubicRootTest, Test_45) {
  double r[4];
  double a[] = {-35, 132.366666666667, -52.6333333333333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(50, r[1], 0.0005);
  ASSERT_NEAR(2.3333333333333335, r[2], 2.33333333333e-05);
  ASSERT_NEAR(0.29999999999999999, r[3], 3e-06);
}

TEST(CubicRootTest, Test_46) {
  double r[4];
  double a[] = {35, -102.366666666667, -47.9666666666667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(50, r[1], 0.0005);
  ASSERT_NEAR(0.29999999999999999, r[2], 3e-06);
  ASSERT_NEAR(-2.3333333333333335, r[3], 2.33333333333e-05);
}

TEST(CubicRootTest, Test_47) {
  double r[4];
  double a[] = {35, -130.966666666667, 47.3666666666667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(2.3333333333333335, r[1], 2.33333333333e-05);
  ASSERT_NEAR(0.29999999999999999, r[2], 3e-06);
  ASSERT_NEAR(-50, r[3], 0.0005);
}

TEST(CubicRootTest, Test_48) {
  double r[4];
  double a[] = {-35, 100.966666666667, 52.0333333333333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(0.29999999999999999, r[1], 3e-06);
  ASSERT_NEAR(-2.3333333333333335, r[2], 2.33333333333e-05);
  ASSERT_NEAR(-50, r[3], 0.0005);
}

TEST(CubicRootTest, Test_49) {
  double r[4];
  double a[] = {35, 100.966666666667, -52.0333333333333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(50, r[1], 0.0005);
  ASSERT_NEAR(2.3333333333333335, r[2], 2.33333333333e-05);
  ASSERT_NEAR(-0.29999999999999999, r[3], 3e-06);
}

TEST(CubicRootTest, Test_50) {
  double r[4];
  double a[] = {-35, -130.966666666667, -47.3666666666667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(50, r[1], 0.0005);
  ASSERT_NEAR(-0.29999999999999999, r[2], 3e-06);
  ASSERT_NEAR(-2.3333333333333335, r[3], 2.33333333333e-05);
}

TEST(CubicRootTest, Test_51) {
  double r[4];
  double a[] = {-35, -102.366666666667, 47.9666666666667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(2.3333333333333335, r[1], 2.33333333333e-05);
  ASSERT_NEAR(-0.29999999999999999, r[2], 3e-06);
  ASSERT_NEAR(-50, r[3], 0.0005);
}

TEST(CubicRootTest, Test_52) {
  double r[4];
  double a[] = {35, 132.366666666667, 52.6333333333333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(-0.29999999999999999, r[1], 3e-06);
  ASSERT_NEAR(-2.3333333333333335, r[2], 2.33333333333e-05);
  ASSERT_NEAR(-50, r[3], 0.0005);
}

TEST(CubicRootTest, Test_53) {
  double r[4];
  double a[] = {-326.666666666667, 5514.72444444444, -1171.39333333333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1166.6666666666667, r[1], 0.0116666666667);
  ASSERT_NEAR(4.666666666666667, r[2], 4.66666666667e-05);
  ASSERT_NEAR(0.059999999999999998, r[3], 6e-07);
}

TEST(CubicRootTest, Test_54) {
  double r[4];
  double a[] = {326.666666666667, -5374.72444444444, -1162.06};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1166.6666666666667, r[1], 0.0116666666667);
  ASSERT_NEAR(0.059999999999999998, r[2], 6e-07);
  ASSERT_NEAR(-4.666666666666667, r[3], 4.66666666667e-05);
}

TEST(CubicRootTest, Test_55) {
  double r[4];
  double a[] = {326.666666666667, -5514.16444444444, 1161.94};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(4.666666666666667, r[1], 4.66666666667e-05);
  ASSERT_NEAR(0.059999999999999998, r[2], 6e-07);
  ASSERT_NEAR(-1166.6666666666667, r[3], 0.0116666666667);
}

TEST(CubicRootTest, Test_56) {
  double r[4];
  double a[] = {-326.666666666667, 5374.16444444444, 1171.27333333333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(0.059999999999999998, r[1], 6e-07);
  ASSERT_NEAR(-4.666666666666667, r[2], 4.66666666667e-05);
  ASSERT_NEAR(-1166.6666666666667, r[3], 0.0116666666667);
}

TEST(CubicRootTest, Test_57) {
  double r[4];
  double a[] = {326.666666666667, 5374.16444444444, -1171.27333333333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1166.6666666666667, r[1], 0.0116666666667);
  ASSERT_NEAR(4.666666666666667, r[2], 4.66666666667e-05);
  ASSERT_NEAR(-0.059999999999999998, r[3], 6e-07);
}

TEST(CubicRootTest, Test_58) {
  double r[4];
  double a[] = {-326.666666666667, -5514.16444444444, -1161.94};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1166.6666666666667, r[1], 0.0116666666667);
  ASSERT_NEAR(-0.059999999999999998, r[2], 6e-07);
  ASSERT_NEAR(-4.666666666666667, r[3], 4.66666666667e-05);
}

TEST(CubicRootTest, Test_59) {
  double r[4];
  double a[] = {-326.666666666667, -5374.72444444444, 1162.06};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(4.666666666666667, r[1], 4.66666666667e-05);
  ASSERT_NEAR(-0.059999999999999998, r[2], 6e-07);
  ASSERT_NEAR(-1166.6666666666667, r[3], 0.0116666666667);
}

TEST(CubicRootTest, Test_60) {
  double r[4];
  double a[] = {326.666666666667, 5514.72444444444, 1171.39333333333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(-0.059999999999999998, r[1], 6e-07);
  ASSERT_NEAR(-4.666666666666667, r[2], 4.66666666667e-05);
  ASSERT_NEAR(-1166.6666666666667, r[3], 0.0116666666667);
}

TEST(CubicRootTest, Test_61) {
  double r[4];
  double a[] = {-1764, 176610.084, -21008.41};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(21000, r[1], 0.21);
  ASSERT_NEAR(8.4000000000000004, r[2], 8.4e-05);
  ASSERT_NEAR(0.01, r[3], 1e-07);
}

TEST(CubicRootTest, Test_62) {
  double r[4];
  double a[] = {1764, -176190.084, -20991.61};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(21000, r[1], 0.21);
  ASSERT_NEAR(0.01, r[2], 1e-07);
  ASSERT_NEAR(-8.4000000000000004, r[3], 8.4e-05);
}

TEST(CubicRootTest, Test_63) {
  double r[4];
  double a[] = {1764, -176609.916, 20991.59};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(8.4000000000000004, r[1], 8.4e-05);
  ASSERT_NEAR(0.01, r[2], 1e-07);
  ASSERT_NEAR(-21000, r[3], 0.21);
}

TEST(CubicRootTest, Test_64) {
  double r[4];
  double a[] = {-1764, 176189.916, 21008.39};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(0.01, r[1], 1e-07);
  ASSERT_NEAR(-8.4000000000000004, r[2], 8.4e-05);
  ASSERT_NEAR(-21000, r[3], 0.21);
}

TEST(CubicRootTest, Test_65) {
  double r[4];
  double a[] = {1764, 176189.916, -21008.39};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(21000, r[1], 0.21);
  ASSERT_NEAR(8.4000000000000004, r[2], 8.4e-05);
  ASSERT_NEAR(-0.01, r[3], 1e-07);
}

TEST(CubicRootTest, Test_66) {
  double r[4];
  double a[] = {-1764, -176609.916, -20991.59};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(21000, r[1], 0.21);
  ASSERT_NEAR(-0.01, r[2], 1e-07);
  ASSERT_NEAR(-8.4000000000000004, r[3], 8.4e-05);
}

TEST(CubicRootTest, Test_67) {
  double r[4];
  double a[] = {-1764, -176190.084, 20991.61};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(8.4000000000000004, r[1], 8.4e-05);
  ASSERT_NEAR(-0.01, r[2], 1e-07);
  ASSERT_NEAR(-21000, r[3], 0.21);
}

TEST(CubicRootTest, Test_68) {
  double r[4];
  double a[] = {1764, 176610.084, 21008.41};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(-0.01, r[1], 1e-07);
  ASSERT_NEAR(-8.4000000000000004, r[2], 8.4e-05);
  ASSERT_NEAR(-21000, r[3], 0.21);
}

TEST(CubicRootTest, Test_69) {
  double r[4];
  double a[] = {-6930, 4620495.021, -330014.0015};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(330000, r[1], 3.3);
  ASSERT_NEAR(14, r[2], 0.00014);
  ASSERT_NEAR(0.0015, r[3], 1.5e-08);
}

TEST(CubicRootTest, Test_70) {
  double r[4];
  double a[] = {6930, -4619505.021, -329986.0015};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(330000, r[1], 3.3);
  ASSERT_NEAR(0.0015, r[2], 1.5e-08);
  ASSERT_NEAR(-14, r[3], 0.00014);
}

TEST(CubicRootTest, Test_71) {
  double r[4];
  double a[] = {6930, -4620494.979, 329985.9985};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(14, r[1], 0.00014);
  ASSERT_NEAR(0.0015, r[2], 1.5e-08);
  ASSERT_NEAR(-330000, r[3], 3.3);
}

TEST(CubicRootTest, Test_72) {
  double r[4];
  double a[] = {-6930, 4619504.979, 330013.9985};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(0.0015, r[1], 1.5e-08);
  ASSERT_NEAR(-14, r[2], 0.00014);
  ASSERT_NEAR(-330000, r[3], 3.3);
}

TEST(CubicRootTest, Test_73) {
  double r[4];
  double a[] = {6930, 4619504.979, -330013.9985};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(330000, r[1], 3.3);
  ASSERT_NEAR(14, r[2], 0.00014);
  ASSERT_NEAR(-0.0015, r[3], 1.5e-08);
}

TEST(CubicRootTest, Test_74) {
  double r[4];
  double a[] = {-6930, -4620494.979, -329985.9985};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(330000, r[1], 3.3);
  ASSERT_NEAR(-0.0015, r[2], 1.5e-08);
  ASSERT_NEAR(-14, r[3], 0.00014);
}

TEST(CubicRootTest, Test_75) {
  double r[4];
  double a[] = {-6930, -4619505.021, 329986.0015};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(14, r[1], 0.00014);
  ASSERT_NEAR(-0.0015, r[2], 1.5e-08);
  ASSERT_NEAR(-330000, r[3], 3.3);
}

TEST(CubicRootTest, Test_76) {
  double r[4];
  double a[] = {6930, 4620495.021, 330014.0015};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(-0.0015, r[1], 1.5e-08);
  ASSERT_NEAR(-14, r[2], 0.00014);
  ASSERT_NEAR(-330000, r[3], 3.3);
}

TEST(CubicRootTest, Test_77) {
  double r[4];
  double a[] = {-22022, 104867667.671287, -4766688.66687667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(4766666.666666667, r[1], 47.6666666667);
  ASSERT_NEAR(22, r[2], 0.00022);
  ASSERT_NEAR(0.00021000000000000001, r[3], 2.1e-09);
}

TEST(CubicRootTest, Test_78) {
  double r[4];
  double a[] = {22022, -104865665.671287, -4766644.66687667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(4766666.666666667, r[1], 47.6666666667);
  ASSERT_NEAR(0.00021000000000000001, r[2], 2.1e-09);
  ASSERT_NEAR(-22, r[3], 0.00022);
}

TEST(CubicRootTest, Test_79) {
  double r[4];
  double a[] = {22022, -104867667.662047, 4766644.66645667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(22, r[1], 0.00022);
  ASSERT_NEAR(0.00021000000000000001, r[2], 2.1e-09);
  ASSERT_NEAR(-4766666.666666667, r[3], 47.6666666667);
}

TEST(CubicRootTest, Test_80) {
  double r[4];
  double a[] = {-22022, 104865665.662047, 4766688.66645667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(0.00021000000000000001, r[1], 2.1e-09);
  ASSERT_NEAR(-22, r[2], 0.00022);
  ASSERT_NEAR(-4766666.666666667, r[3], 47.6666666667);
}

TEST(CubicRootTest, Test_81) {
  double r[4];
  double a[] = {22022, 104865665.662047, -4766688.66645667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(4766666.666666667, r[1], 47.6666666667);
  ASSERT_NEAR(22, r[2], 0.00022);
  ASSERT_NEAR(-0.00021000000000000001, r[3], 2.1e-09);
}

TEST(CubicRootTest, Test_82) {
  double r[4];
  double a[] = {-22022, -104867667.662047, -4766644.66645667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(4766666.666666667, r[1], 47.6666666667);
  ASSERT_NEAR(-0.00021000000000000001, r[2], 2.1e-09);
  ASSERT_NEAR(-22, r[3], 0.00022);
}

TEST(CubicRootTest, Test_83) {
  double r[4];
  double a[] = {-22022, -104865665.671287, 4766644.66687667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(22, r[1], 0.00022);
  ASSERT_NEAR(-0.00021000000000000001, r[2], 2.1e-09);
  ASSERT_NEAR(-4766666.666666667, r[3], 47.6666666667);
}

TEST(CubicRootTest, Test_84) {
  double r[4];
  double a[] = {22022, 104867667.671287, 4766688.66687667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(-0.00021000000000000001, r[1], 2.1e-09);
  ASSERT_NEAR(-22, r[2], 0.00022);
  ASSERT_NEAR(-4766666.666666667, r[3], 47.6666666667);
}

TEST(CubicRootTest, Test_85) {
  double r[4];
  double a[] = {-60060, 2145001820.00092, -65000033.000028};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(65000000, r[1], 650.0);
  ASSERT_NEAR(33, r[2], 0.00033);
  ASSERT_NEAR(2.8e-05, r[3], 2.8e-10);
}

TEST(CubicRootTest, Test_86) {
  double r[4];
  double a[] = {60060, -2144998180.00092, -64999967.000028};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(65000000, r[1], 650.0);
  ASSERT_NEAR(2.8e-05, r[2], 2.8e-10);
  ASSERT_NEAR(-33, r[3], 0.00033);
}

TEST(CubicRootTest, Test_87) {
  double r[4];
  double a[] = {60060, -2145001819.99908, 64999966.999972};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(33, r[1], 0.00033);
  ASSERT_NEAR(2.8e-05, r[2], 2.8e-10);
  ASSERT_NEAR(-65000000, r[3], 650.0);
}

TEST(CubicRootTest, Test_88) {
  double r[4];
  double a[] = {-60060, 2144998179.99908, 65000032.999972};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(2.8e-05, r[1], 2.8e-10);
  ASSERT_NEAR(-33, r[2], 0.00033);
  ASSERT_NEAR(-65000000, r[3], 650.0);
}

TEST(CubicRootTest, Test_89) {
  double r[4];
  double a[] = {60060, 2144998179.99908, -65000032.999972};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(65000000, r[1], 650.0);
  ASSERT_NEAR(33, r[2], 0.00033);
  ASSERT_NEAR(-2.8e-05, r[3], 2.8e-10);
}

TEST(CubicRootTest, Test_90) {
  double r[4];
  double a[] = {-60060, -2145001819.99908, -64999966.999972};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(65000000, r[1], 650.0);
  ASSERT_NEAR(-2.8e-05, r[2], 2.8e-10);
  ASSERT_NEAR(-33, r[3], 0.00033);
}

TEST(CubicRootTest, Test_91) {
  double r[4];
  double a[] = {-60060, -2144998180.00092, 64999967.000028};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(33, r[1], 0.00033);
  ASSERT_NEAR(-2.8e-05, r[2], 2.8e-10);
  ASSERT_NEAR(-65000000, r[3], 650.0);
}

TEST(CubicRootTest, Test_92) {
  double r[4];
  double a[] = {60060, 2145001820.00092, 65000033.000028};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(-2.8e-05, r[1], 2.8e-10);
  ASSERT_NEAR(-33, r[2], 0.00033);
  ASSERT_NEAR(-65000000, r[3], 650.0);
}

TEST(CubicRootTest, Test_93) {
  double r[4];
  double a[] = {-145860, 40516669726.6668, -850000047.66667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(850000000, r[1], 8500.0);
  ASSERT_NEAR(47.666666666666664, r[2], 0.000476666666667);
  ASSERT_NEAR(3.5999999999999998e-06, r[3], 3.6e-11);
}

TEST(CubicRootTest, Test_94) {
  double r[4];
  double a[] = {145860, -40516663606.6668, -849999952.333337};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(850000000, r[1], 8500.0);
  ASSERT_NEAR(3.5999999999999998e-06, r[2], 3.6e-11);
  ASSERT_NEAR(-47.666666666666664, r[3], 0.000476666666667);
}

TEST(CubicRootTest, Test_95) {
  double r[4];
  double a[] = {145860, -40516669726.6665, 849999952.33333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(47.666666666666664, r[1], 0.000476666666667);
  ASSERT_NEAR(3.5999999999999998e-06, r[2], 3.6e-11);
  ASSERT_NEAR(-850000000, r[3], 8500.0);
}

TEST(CubicRootTest, Test_96) {
  double r[4];
  double a[] = {-145860, 40516663606.6665, 850000047.666663};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(3.5999999999999998e-06, r[1], 3.6e-11);
  ASSERT_NEAR(-47.666666666666664, r[2], 0.000476666666667);
  ASSERT_NEAR(-850000000, r[3], 8500.0);
}

TEST(CubicRootTest, Test_97) {
  double r[4];
  double a[] = {145860, 40516663606.6665, -850000047.666663};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(850000000, r[1], 8500.0);
  ASSERT_NEAR(47.666666666666664, r[2], 0.000476666666667);
  ASSERT_NEAR(-3.5999999999999998e-06, r[3], 3.6e-11);
}

TEST(CubicRootTest, Test_98) {
  double r[4];
  double a[] = {-145860, -40516669726.6665, -849999952.33333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(850000000, r[1], 8500.0);
  ASSERT_NEAR(-3.5999999999999998e-06, r[2], 3.6e-11);
  ASSERT_NEAR(-47.666666666666664, r[3], 0.000476666666667);
}

TEST(CubicRootTest, Test_99) {
  double r[4];
  double a[] = {-145860, -40516663606.6668, 849999952.333337};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(47.666666666666664, r[1], 0.000476666666667);
  ASSERT_NEAR(-3.5999999999999998e-06, r[2], 3.6e-11);
  ASSERT_NEAR(-850000000, r[3], 8500.0);
}

TEST(CubicRootTest, Test_100) {
  double r[4];
  double a[] = {145860, 40516669726.6668, 850000047.66667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(-3.5999999999999998e-06, r[1], 3.6e-11);
  ASSERT_NEAR(-47.666666666666664, r[2], 0.000476666666667);
  ASSERT_NEAR(-850000000, r[3], 8500.0);
}

TEST(CubicRootTest, Test_101) {
  double r[4];
  double a[] = {-323323, 718495560400.556, -10766666733.4};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(10766666666.666668, r[1], 107666.666667);
  ASSERT_NEAR(66.733333333333334, r[2], 0.000667333333333);
  ASSERT_NEAR(4.4999999999999998e-07, r[3], 4.5e-12);
}

TEST(CubicRootTest, Test_102) {
  double r[4];
  double a[] = {323323, -718495550710.556, -10766666599.9333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(10766666666.666668, r[1], 107666.666667);
  ASSERT_NEAR(4.4999999999999998e-07, r[2], 4.5e-12);
  ASSERT_NEAR(-66.733333333333334, r[3], 0.000667333333333);
}

TEST(CubicRootTest, Test_103) {
  double r[4];
  double a[] = {323323, -718495560400.556, 10766666599.9333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(66.733333333333334, r[1], 0.000667333333333);
  ASSERT_NEAR(4.4999999999999998e-07, r[2], 4.5e-12);
  ASSERT_NEAR(-10766666666.666668, r[3], 107666.666667);
}

TEST(CubicRootTest, Test_104) {
  double r[4];
  double a[] = {-323323, 718495550710.556, 10766666733.4};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(4.4999999999999998e-07, r[1], 4.5e-12);
  ASSERT_NEAR(-66.733333333333334, r[2], 0.000667333333333);
  ASSERT_NEAR(-10766666666.666668, r[3], 107666.666667);
}

TEST(CubicRootTest, Test_105) {
  double r[4];
  double a[] = {323323, 718495550710.556, -10766666733.4};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(10766666666.666668, r[1], 107666.666667);
  ASSERT_NEAR(66.733333333333334, r[2], 0.000667333333333);
  ASSERT_NEAR(-4.4999999999999998e-07, r[3], 4.5e-12);
}

TEST(CubicRootTest, Test_106) {
  double r[4];
  double a[] = {-323323, -718495560400.556, -10766666599.9333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(10766666666.666668, r[1], 107666.666667);
  ASSERT_NEAR(-4.4999999999999998e-07, r[2], 4.5e-12);
  ASSERT_NEAR(-66.733333333333334, r[3], 0.000667333333333);
}

TEST(CubicRootTest, Test_107) {
  double r[4];
  double a[] = {-323323, -718495550710.556, 10766666599.9333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(66.733333333333334, r[1], 0.000667333333333);
  ASSERT_NEAR(-4.4999999999999998e-07, r[2], 4.5e-12);
  ASSERT_NEAR(-10766666666.666668, r[3], 107666.666667);
}

TEST(CubicRootTest, Test_108) {
  double r[4];
  double a[] = {323323, 718495560400.556, 10766666733.4};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(-4.4999999999999998e-07, r[1], 4.5e-12);
  ASSERT_NEAR(-66.733333333333334, r[2], 0.000667333333333);
  ASSERT_NEAR(-10766666666.666668, r[3], 107666.666667);
}

TEST(CubicRootTest, Test_109) {
  double r[4];
  double a[] = {-665665, 12103000007315, -133000000091};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(133000000000, r[1], 1330000.0);
  ASSERT_NEAR(91, r[2], 0.00091);
  ASSERT_NEAR(5.5000000000000003e-08, r[3], 5.5e-13);
}

TEST(CubicRootTest, Test_110) {
  double r[4];
  double a[] = {665665, -12102999992685, -132999999909};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(133000000000, r[1], 1330000.0);
  ASSERT_NEAR(5.5000000000000003e-08, r[2], 5.5e-13);
  ASSERT_NEAR(-91, r[3], 0.00091);
}

TEST(CubicRootTest, Test_111) {
  double r[4];
  double a[] = {665665, -12103000007315, 132999999909};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(91, r[1], 0.00091);
  ASSERT_NEAR(5.5000000000000003e-08, r[2], 5.5e-13);
  ASSERT_NEAR(-133000000000, r[3], 1330000.0);
}

TEST(CubicRootTest, Test_112) {
  double r[4];
  double a[] = {-665665, 12102999992685, 133000000091};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(5.5000000000000003e-08, r[1], 5.5e-13);
  ASSERT_NEAR(-91, r[2], 0.00091);
  ASSERT_NEAR(-133000000000, r[3], 1330000.0);
}

TEST(CubicRootTest, Test_113) {
  double r[4];
  double a[] = {665665, 12102999992685, -133000000091};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(133000000000, r[1], 1330000.0);
  ASSERT_NEAR(91, r[2], 0.00091);
  ASSERT_NEAR(-5.5000000000000003e-08, r[3], 5.5e-13);
}

TEST(CubicRootTest, Test_114) {
  double r[4];
  double a[] = {-665665, -12103000007315, -132999999909};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(133000000000, r[1], 1330000.0);
  ASSERT_NEAR(-5.5000000000000003e-08, r[2], 5.5e-13);
  ASSERT_NEAR(-91, r[3], 0.00091);
}

TEST(CubicRootTest, Test_115) {
  double r[4];
  double a[] = {-665665, -12102999992685, 132999999909};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(91, r[1], 0.00091);
  ASSERT_NEAR(-5.5000000000000003e-08, r[2], 5.5e-13);
  ASSERT_NEAR(-133000000000, r[3], 1330000.0);
}

TEST(CubicRootTest, Test_116) {
  double r[4];
  double a[] = {665665, 12103000007315, 133000000091};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(-5.5000000000000003e-08, r[1], 5.5e-13);
  ASSERT_NEAR(-91, r[2], 0.00091);
  ASSERT_NEAR(-133000000000, r[3], 1330000.0);
}

TEST(CubicRootTest, Test_117) {
  double r[4];
  double a[] = {-1289288, 195346666677293, -1610000000121.33};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1610000000000, r[1], 16100000.0);
  ASSERT_NEAR(121.33333333333333, r[2], 0.00121333333333);
  ASSERT_NEAR(6.6000000000000004e-09, r[3], 6.6e-14);
}

TEST(CubicRootTest, Test_118) {
  double r[4];
  double a[] = {1289288, -195346666656041, -1609999999878.67};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1610000000000, r[1], 16100000.0);
  ASSERT_NEAR(6.6000000000000004e-09, r[2], 6.6e-14);
  ASSERT_NEAR(-121.33333333333333, r[3], 0.00121333333333);
}

TEST(CubicRootTest, Test_119) {
  double r[4];
  double a[] = {1289288, -195346666677293, 1609999999878.67};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(121.33333333333333, r[1], 0.00121333333333);
  ASSERT_NEAR(6.6000000000000004e-09, r[2], 6.6e-14);
  ASSERT_NEAR(-1610000000000, r[3], 16100000.0);
}

TEST(CubicRootTest, Test_120) {
  double r[4];
  double a[] = {-1289288, 195346666656041, 1610000000121.33};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(6.6000000000000004e-09, r[1], 6.6e-14);
  ASSERT_NEAR(-121.33333333333333, r[2], 0.00121333333333);
  ASSERT_NEAR(-1610000000000, r[3], 16100000.0);
}

TEST(CubicRootTest, Test_121) {
  double r[4];
  double a[] = {1289288, 195346666656041, -1610000000121.33};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1610000000000, r[1], 16100000.0);
  ASSERT_NEAR(121.33333333333333, r[2], 0.00121333333333);
  ASSERT_NEAR(-6.6000000000000004e-09, r[3], 6.6e-14);
}

TEST(CubicRootTest, Test_122) {
  double r[4];
  double a[] = {-1289288, -195346666677293, -1609999999878.67};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(1610000000000, r[1], 16100000.0);
  ASSERT_NEAR(-6.6000000000000004e-09, r[2], 6.6e-14);
  ASSERT_NEAR(-121.33333333333333, r[3], 0.00121333333333);
}

TEST(CubicRootTest, Test_123) {
  double r[4];
  double a[] = {-1289288, -195346666656041, 1609999999878.67};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(121.33333333333333, r[1], 0.00121333333333);
  ASSERT_NEAR(-6.6000000000000004e-09, r[2], 6.6e-14);
  ASSERT_NEAR(-1610000000000, r[3], 16100000.0);
}

TEST(CubicRootTest, Test_124) {
  double r[4];
  double a[] = {1289288, 195346666677293, 1610000000121.33};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(-6.6000000000000004e-09, r[1], 6.6e-14);
  ASSERT_NEAR(-121.33333333333333, r[2], 0.00121333333333);
  ASSERT_NEAR(-1610000000000, r[3], 16100000.0);
}

TEST(CubicRootTest, Test_125) {
  double r[4];
  double a[] = {-2372066.66666667, 3.04111111112606e+15, -19166666666825.3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(19166666666666.668, r[1], 191666666.667);
  ASSERT_NEAR(158.66666666666666, r[2], 0.00158666666667);
  ASSERT_NEAR(7.7999999999999999e-10, r[3], 7.8e-15);
}

TEST(CubicRootTest, Test_126) {
  double r[4];
  double a[] = {2372066.66666667, -3.04111111109616e+15, -19166666666508};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(19166666666666.668, r[1], 191666666.667);
  ASSERT_NEAR(7.7999999999999999e-10, r[2], 7.8e-15);
  ASSERT_NEAR(-158.66666666666666, r[3], 0.00158666666667);
}

TEST(CubicRootTest, Test_127) {
  double r[4];
  double a[] = {2372066.66666667, -3.04111111112606e+15, 19166666666508};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(158.66666666666666, r[1], 0.00158666666667);
  ASSERT_NEAR(7.7999999999999999e-10, r[2], 7.8e-15);
  ASSERT_NEAR(-19166666666666.668, r[3], 191666666.667);
}

TEST(CubicRootTest, Test_128) {
  double r[4];
  double a[] = {-2372066.66666667, 3.04111111109616e+15, 19166666666825.3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(7.7999999999999999e-10, r[1], 7.8e-15);
  ASSERT_NEAR(-158.66666666666666, r[2], 0.00158666666667);
  ASSERT_NEAR(-19166666666666.668, r[3], 191666666.667);
}

TEST(CubicRootTest, Test_129) {
  double r[4];
  double a[] = {2372066.66666667, 3.04111111109616e+15, -19166666666825.3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(19166666666666.668, r[1], 191666666.667);
  ASSERT_NEAR(158.66666666666666, r[2], 0.00158666666667);
  ASSERT_NEAR(-7.7999999999999999e-10, r[3], 7.8e-15);
}

TEST(CubicRootTest, Test_130) {
  double r[4];
  double a[] = {-2372066.66666667, -3.04111111112606e+15, -19166666666508};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(19166666666666.668, r[1], 191666666.667);
  ASSERT_NEAR(-7.7999999999999999e-10, r[2], 7.8e-15);
  ASSERT_NEAR(-158.66666666666666, r[3], 0.00158666666667);
}

TEST(CubicRootTest, Test_131) {
  double r[4];
  double a[] = {-2372066.66666667, -3.04111111109616e+15, 19166666666508};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(158.66666666666666, r[1], 0.00158666666667);
  ASSERT_NEAR(-7.7999999999999999e-10, r[2], 7.8e-15);
  ASSERT_NEAR(-19166666666666.668, r[3], 191666666.667);
}

TEST(CubicRootTest, Test_132) {
  double r[4];
  double a[] = {2372066.66666667, 3.04111111112606e+15, 19166666666825.3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(-7.7999999999999999e-10, r[1], 7.8e-15);
  ASSERT_NEAR(-158.66666666666666, r[2], 0.00158666666667);
  ASSERT_NEAR(-19166666666666.668, r[3], 191666666.667);
}

TEST(CubicRootTest, Test_133) {
  double r[4];
  double a[] = {-4176900, 4.59000000000205e+16, -225000000000204};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(3, num_roots);
  ASSERT_NEAR(225000000000000, r[1], 2250000000.0);
  ASSERT_NEAR(204, r[2], 0.00204);
  ASSERT_NEAR(9.0999999999999996e-11, r[3], 9.1e-16);
}

TEST(CubicRootTest, Test_134) {
  double r[4];
  double a[] = {-4.5, 30.09, -50.6};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(50, r[1], 0.0005);
  ASSERT_NEAR(0.29999999999999999, r[2], 3e-06);
  ASSERT_NEAR(0.29999999999999999, r[3], 3e-06);
}

TEST(CubicRootTest, Test_135) {
  double r[4];
  double a[] = {4.5, -29.91, 49.4};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.29999999999999999, r[1], 3e-06);
  ASSERT_NEAR(0.29999999999999999, r[2], 3e-06);
  ASSERT_NEAR(-50, r[3], 0.0005);
}

TEST(CubicRootTest, Test_136) {
  double r[4];
  double a[] = {-4.5, -29.91, -49.4};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(50, r[1], 0.0005);
  ASSERT_NEAR(-0.29999999999999999, r[2], 3e-06);
  ASSERT_NEAR(-0.29999999999999999, r[3], 3e-06);
}

TEST(CubicRootTest, Test_137) {
  double r[4];
  double a[] = {4.5, 30.09, 50.6};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.29999999999999999, r[1], 3e-06);
  ASSERT_NEAR(-0.29999999999999999, r[2], 3e-06);
  ASSERT_NEAR(-50, r[3], 0.0005);
}

TEST(CubicRootTest, Test_138) {
  double r[4];
  double a[] = {750, 2470, -99.7};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(50, r[1], 0.0005);
  ASSERT_NEAR(50, r[2], 0.0005);
  ASSERT_NEAR(-0.29999999999999999, r[3], 3e-06);
}

TEST(CubicRootTest, Test_139) {
  double r[4];
  double a[] = {-750, 2530, -100.3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(50, r[1], 0.0005);
  ASSERT_NEAR(50, r[2], 0.0005);
  ASSERT_NEAR(0.29999999999999999, r[3], 3e-06);
}

TEST(CubicRootTest, Test_140) {
  double r[4];
  double a[] = {750, 2530, 100.3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.29999999999999999, r[1], 3e-06);
  ASSERT_NEAR(-50, r[2], 0.0005);
  ASSERT_NEAR(-50, r[3], 0.0005);
}

TEST(CubicRootTest, Test_141) {
  double r[4];
  double a[] = {-750, 2470, 99.7};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.29999999999999999, r[1], 3e-06);
  ASSERT_NEAR(-50, r[2], 0.0005);
  ASSERT_NEAR(-50, r[3], 0.0005);
}

TEST(CubicRootTest, Test_142) {
  double r[4];
  double a[] = {-4.2, 140.0036, -1166.78666666667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1166.6666666666667, r[1], 0.0116666666667);
  ASSERT_NEAR(0.059999999999999998, r[2], 6e-07);
  ASSERT_NEAR(0.059999999999999998, r[3], 6e-07);
}

TEST(CubicRootTest, Test_143) {
  double r[4];
  double a[] = {4.2, -139.9964, 1166.54666666667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.059999999999999998, r[1], 6e-07);
  ASSERT_NEAR(0.059999999999999998, r[2], 6e-07);
  ASSERT_NEAR(-1166.6666666666667, r[3], 0.0116666666667);
}

TEST(CubicRootTest, Test_144) {
  double r[4];
  double a[] = {-4.2, -139.9964, -1166.54666666667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1166.6666666666667, r[1], 0.0116666666667);
  ASSERT_NEAR(-0.059999999999999998, r[2], 6e-07);
  ASSERT_NEAR(-0.059999999999999998, r[3], 6e-07);
}

TEST(CubicRootTest, Test_145) {
  double r[4];
  double a[] = {4.2, 140.0036, 1166.78666666667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.059999999999999998, r[1], 6e-07);
  ASSERT_NEAR(-0.059999999999999998, r[2], 6e-07);
  ASSERT_NEAR(-1166.6666666666667, r[3], 0.0116666666667);
}

TEST(CubicRootTest, Test_146) {
  double r[4];
  double a[] = {81666.6666666667, 1360971.11111111, -2333.27333333333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1166.6666666666667, r[1], 0.0116666666667);
  ASSERT_NEAR(1166.6666666666667, r[2], 0.0116666666667);
  ASSERT_NEAR(-0.059999999999999998, r[3], 6e-07);
}

TEST(CubicRootTest, Test_147) {
  double r[4];
  double a[] = {-81666.6666666667, 1361251.11111111, -2333.39333333333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1166.6666666666667, r[1], 0.0116666666667);
  ASSERT_NEAR(1166.6666666666667, r[2], 0.0116666666667);
  ASSERT_NEAR(0.059999999999999998, r[3], 6e-07);
}

TEST(CubicRootTest, Test_148) {
  double r[4];
  double a[] = {81666.6666666667, 1361251.11111111, 2333.39333333333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.059999999999999998, r[1], 6e-07);
  ASSERT_NEAR(-1166.6666666666667, r[2], 0.0116666666667);
  ASSERT_NEAR(-1166.6666666666667, r[3], 0.0116666666667);
}

TEST(CubicRootTest, Test_149) {
  double r[4];
  double a[] = {-81666.6666666667, 1360971.11111111, 2333.27333333333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.059999999999999998, r[1], 6e-07);
  ASSERT_NEAR(-1166.6666666666667, r[2], 0.0116666666667);
  ASSERT_NEAR(-1166.6666666666667, r[3], 0.0116666666667);
}

TEST(CubicRootTest, Test_150) {
  double r[4];
  double a[] = {-2.1, 420.0001, -21000.02};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21000, r[1], 0.21);
  ASSERT_NEAR(0.01, r[2], 1e-07);
  ASSERT_NEAR(0.01, r[3], 1e-07);
}

TEST(CubicRootTest, Test_151) {
  double r[4];
  double a[] = {2.1, -419.9999, 20999.98};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.01, r[1], 1e-07);
  ASSERT_NEAR(0.01, r[2], 1e-07);
  ASSERT_NEAR(-21000, r[3], 0.21);
}

TEST(CubicRootTest, Test_152) {
  double r[4];
  double a[] = {-2.1, -419.9999, -20999.98};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21000, r[1], 0.21);
  ASSERT_NEAR(-0.01, r[2], 1e-07);
  ASSERT_NEAR(-0.01, r[3], 1e-07);
}

TEST(CubicRootTest, Test_153) {
  double r[4];
  double a[] = {2.1, 420.0001, 21000.02};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.01, r[1], 1e-07);
  ASSERT_NEAR(-0.01, r[2], 1e-07);
  ASSERT_NEAR(-21000, r[3], 0.21);
}

TEST(CubicRootTest, Test_154) {
  double r[4];
  double a[] = {4410000, 440999580, -41999.99};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21000, r[1], 0.21);
  ASSERT_NEAR(21000, r[2], 0.21);
  ASSERT_NEAR(-0.01, r[3], 1e-07);
}

TEST(CubicRootTest, Test_155) {
  double r[4];
  double a[] = {-4410000, 441000420, -42000.01};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(21000, r[1], 0.21);
  ASSERT_NEAR(21000, r[2], 0.21);
  ASSERT_NEAR(0.01, r[3], 1e-07);
}

TEST(CubicRootTest, Test_156) {
  double r[4];
  double a[] = {4410000, 441000420, 42000.01};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.01, r[1], 1e-07);
  ASSERT_NEAR(-21000, r[2], 0.21);
  ASSERT_NEAR(-21000, r[3], 0.21);
}

TEST(CubicRootTest, Test_157) {
  double r[4];
  double a[] = {-4410000, 440999580, 41999.99};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.01, r[1], 1e-07);
  ASSERT_NEAR(-21000, r[2], 0.21);
  ASSERT_NEAR(-21000, r[3], 0.21);
}

TEST(CubicRootTest, Test_158) {
  double r[4];
  double a[] = {-0.7425, 990.00000225, -330000.003};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(330000, r[1], 3.3);
  ASSERT_NEAR(0.0015, r[2], 1.5e-08);
  ASSERT_NEAR(0.0015, r[3], 1.5e-08);
}

TEST(CubicRootTest, Test_159) {
  double r[4];
  double a[] = {0.7425, -989.99999775, 329999.997};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0015, r[1], 1.5e-08);
  ASSERT_NEAR(0.0015, r[2], 1.5e-08);
  ASSERT_NEAR(-330000, r[3], 3.3);
}

TEST(CubicRootTest, Test_160) {
  double r[4];
  double a[] = {-0.7425, -989.99999775, -329999.997};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(330000, r[1], 3.3);
  ASSERT_NEAR(-0.0015, r[2], 1.5e-08);
  ASSERT_NEAR(-0.0015, r[3], 1.5e-08);
}

TEST(CubicRootTest, Test_161) {
  double r[4];
  double a[] = {0.7425, 990.00000225, 330000.003};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0015, r[1], 1.5e-08);
  ASSERT_NEAR(-0.0015, r[2], 1.5e-08);
  ASSERT_NEAR(-330000, r[3], 3.3);
}

TEST(CubicRootTest, Test_162) {
  double r[4];
  double a[] = {163350000, 108899999010, -659999.9985};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(330000, r[1], 3.3);
  ASSERT_NEAR(330000, r[2], 3.3);
  ASSERT_NEAR(-0.0015, r[3], 1.5e-08);
}

TEST(CubicRootTest, Test_163) {
  double r[4];
  double a[] = {-163350000, 108900000990, -660000.0015};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(330000, r[1], 3.3);
  ASSERT_NEAR(330000, r[2], 3.3);
  ASSERT_NEAR(0.0015, r[3], 1.5e-08);
}

TEST(CubicRootTest, Test_164) {
  double r[4];
  double a[] = {163350000, 108900000990, 660000.0015};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.0015, r[1], 1.5e-08);
  ASSERT_NEAR(-330000, r[2], 3.3);
  ASSERT_NEAR(-330000, r[3], 3.3);
}

TEST(CubicRootTest, Test_165) {
  double r[4];
  double a[] = {-163350000, 108899999010, 659999.9985};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.0015, r[1], 1.5e-08);
  ASSERT_NEAR(-330000, r[2], 3.3);
  ASSERT_NEAR(-330000, r[3], 3.3);
}

TEST(CubicRootTest, Test_166) {
  double r[4];
  double a[] = {-0.21021, 2002.0000000441, -4766666.66708667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4766666.666666667, r[1], 47.6666666667);
  ASSERT_NEAR(0.00021000000000000001, r[2], 2.1e-09);
  ASSERT_NEAR(0.00021000000000000001, r[3], 2.1e-09);
}

TEST(CubicRootTest, Test_167) {
  double r[4];
  double a[] = {0.21021, -2001.9999999559, 4766666.66624667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.00021000000000000001, r[1], 2.1e-09);
  ASSERT_NEAR(0.00021000000000000001, r[2], 2.1e-09);
  ASSERT_NEAR(-4766666.666666667, r[3], 47.6666666667);
}

TEST(CubicRootTest, Test_168) {
  double r[4];
  double a[] = {-0.21021, -2001.9999999559, -4766666.66624667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4766666.666666667, r[1], 47.6666666667);
  ASSERT_NEAR(-0.00021000000000000001, r[2], 2.1e-09);
  ASSERT_NEAR(-0.00021000000000000001, r[3], 2.1e-09);
}

TEST(CubicRootTest, Test_169) {
  double r[4];
  double a[] = {0.21021, 2002.0000000441, 4766666.66708667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.00021000000000000001, r[1], 2.1e-09);
  ASSERT_NEAR(-0.00021000000000000001, r[2], 2.1e-09);
  ASSERT_NEAR(-4766666.666666667, r[3], 47.6666666667);
}

TEST(CubicRootTest, Test_170) {
  double r[4];
  double a[] = {4771433333.33333, 22721111109109.1, -9533333.33312333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4766666.666666667, r[1], 47.6666666667);
  ASSERT_NEAR(4766666.666666667, r[2], 47.6666666667);
  ASSERT_NEAR(-0.00021000000000000001, r[3], 2.1e-08);
}

TEST(CubicRootTest, Test_171) {
  double r[4];
  double a[] = {-4771433333.33333, 22721111113113.1, -9533333.33354333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4766666.666666667, r[1], 47.6666666667);
  ASSERT_NEAR(4766666.666666667, r[2], 47.6666666667);
  ASSERT_NEAR(0.00021000000000000001, r[3], 2.1e-08);
}

TEST(CubicRootTest, Test_172) {
  double r[4];
  double a[] = {4771433333.33333, 22721111113113.1, 9533333.33354333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-0.00021000000000000001, r[1], 2.1e-08);
  ASSERT_NEAR(-4766666.666666667, r[2], 47.6666666667);
  ASSERT_NEAR(-4766666.666666667, r[3], 47.6666666667);
}

TEST(CubicRootTest, Test_173) {
  double r[4];
  double a[] = {-4771433333.33333, 22721111109109.1, 9533333.33312333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(0.00021000000000000001, r[1], 2.1e-08);
  ASSERT_NEAR(-4766666.666666667, r[2], 47.6666666667);
  ASSERT_NEAR(-4766666.666666667, r[3], 47.6666666667);
}

TEST(CubicRootTest, Test_174) {
  double r[4];
  double a[] = {-0.05096, 3640.00000000078, -65000000.000056};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(65000000, r[1], 650.0);
  ASSERT_NEAR(2.8e-05, r[2], 2.8e-10);
  ASSERT_NEAR(2.8e-05, r[3], 2.8e-10);
}

TEST(CubicRootTest, Test_175) {
  double r[4];
  double a[] = {0.05096, -3639.99999999922, 64999999.999944};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.8e-05, r[1], 2.8e-10);
  ASSERT_NEAR(2.8e-05, r[2], 2.8e-10);
  ASSERT_NEAR(-65000000, r[3], 650.0);
}

TEST(CubicRootTest, Test_176) {
  double r[4];
  double a[] = {-0.05096, -3639.99999999922, -64999999.999944};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(65000000, r[1], 650.0);
  ASSERT_NEAR(-2.8e-05, r[2], 2.8e-10);
  ASSERT_NEAR(-2.8e-05, r[3], 2.8e-10);
}

TEST(CubicRootTest, Test_177) {
  double r[4];
  double a[] = {0.05096, 3640.00000000078, 65000000.000056};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2.8e-05, r[1], 2.8e-10);
  ASSERT_NEAR(-2.8e-05, r[2], 2.8e-10);
  ASSERT_NEAR(-65000000, r[3], 650.0);
}

TEST(CubicRootTest, Test_178) {
  double r[4];
  double a[] = {118300000000, 4.22499999999636e+15, -129999999.999972};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(65000000, r[1], 650.0);
  ASSERT_NEAR(65000000, r[2], 650.0);
  ASSERT_NEAR(-2.8e-05, r[3], 2.8e-10);
}

TEST(CubicRootTest, Test_179) {
  double r[4];
  double a[] = {-118300000000, 4.22500000000364e+15, -130000000.000028};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(65000000, r[1], 650.0);
  ASSERT_NEAR(65000000, r[2], 650.0);
  ASSERT_NEAR(2.8e-05, r[3], 2.8e-10);
}

TEST(CubicRootTest, Test_180) {
  double r[4];
  double a[] = {118300000000, 4.22500000000364e+15, 130000000.000028};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-2.8e-05, r[1], 2.8e-10);
  ASSERT_NEAR(-65000000, r[2], 650.0);
  ASSERT_NEAR(-65000000, r[3], 650.0);
}

TEST(CubicRootTest, Test_181) {
  double r[4];
  double a[] = {-118300000000, 4.22499999999636e+15, 129999999.999972};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2.8e-05, r[1], 2.8e-10);
  ASSERT_NEAR(-65000000, r[2], 650.0);
  ASSERT_NEAR(-65000000, r[3], 650.0);
}

TEST(CubicRootTest, Test_182) {
  double r[4];
  double a[] = {-0.011016, 6120.00000000001, -850000000.000007};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(850000000, r[1], 8500.0);
  ASSERT_NEAR(3.5999999999999998e-06, r[2], 3.6e-11);
  ASSERT_NEAR(3.5999999999999998e-06, r[3], 3.6e-11);
}

TEST(CubicRootTest, Test_183) {
  double r[4];
  double a[] = {0.011016, -6119.99999999999, 849999999.999993};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.5999999999999998e-06, r[1], 3.6e-11);
  ASSERT_NEAR(3.5999999999999998e-06, r[2], 3.6e-11);
  ASSERT_NEAR(-850000000, r[3], 8500.0);
}

TEST(CubicRootTest, Test_184) {
  double r[4];
  double a[] = {-0.011016, -6119.99999999999, -849999999.999993};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(850000000, r[1], 8500.0);
  ASSERT_NEAR(-3.5999999999999998e-06, r[2], 3.6e-11);
  ASSERT_NEAR(-3.5999999999999998e-06, r[3], 3.6e-11);
}

TEST(CubicRootTest, Test_185) {
  double r[4];
  double a[] = {0.011016, 6120.00000000001, 850000000.000007};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-3.5999999999999998e-06, r[1], 3.6e-11);
  ASSERT_NEAR(-3.5999999999999998e-06, r[2], 3.6e-11);
  ASSERT_NEAR(-850000000, r[3], 8500.0);
}

TEST(CubicRootTest, Test_186) {
  double r[4];
  double a[] = {2601000000000, 7.22499999999994e+17, -1700000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(850000000, r[1], 8500.0);
  ASSERT_NEAR(850000000, r[2], 8500.0);
  ASSERT_NEAR(-3.5999999999999998e-06, r[3], 3.6e-11);
}

TEST(CubicRootTest, Test_187) {
  double r[4];
  double a[] = {-2601000000000, 7.22500000000006e+17, -1700000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(850000000, r[1], 8500.0);
  ASSERT_NEAR(850000000, r[2], 8500.0);
  ASSERT_NEAR(3.5999999999999998e-06, r[3], 3.6e-11);
}

TEST(CubicRootTest, Test_188) {
  double r[4];
  double a[] = {2601000000000, 7.22500000000006e+17, 1700000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-3.5999999999999998e-06, r[1], 3.6e-11);
  ASSERT_NEAR(-850000000, r[2], 8500.0);
  ASSERT_NEAR(-850000000, r[3], 8500.0);
}

TEST(CubicRootTest, Test_189) {
  double r[4];
  double a[] = {-2601000000000, 7.22499999999994e+17, 1700000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.5999999999999998e-06, r[1], 3.6e-11);
  ASSERT_NEAR(-850000000, r[2], 8500.0);
  ASSERT_NEAR(-850000000, r[3], 8500.0);
}

TEST(CubicRootTest, Test_190) {
  double r[4];
  double a[] = {-0.00218025, 9690, -10766666666.6667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(10766666666.666668, r[1], 107666.666667);
  ASSERT_NEAR(4.4999999999999998e-07, r[2], 4.5e-12);
  ASSERT_NEAR(4.4999999999999998e-07, r[3], 4.5e-12);
}

TEST(CubicRootTest, Test_191) {
  double r[4];
  double a[] = {0.00218025, -9690, 10766666666.6667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.4999999999999998e-07, r[1], 4.5e-12);
  ASSERT_NEAR(4.4999999999999998e-07, r[2], 4.5e-12);
  ASSERT_NEAR(-10766666666.666668, r[3], 107666.666667);
}

TEST(CubicRootTest, Test_192) {
  double r[4];
  double a[] = {-0.00218025, -9690, -10766666666.6667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(10766666666.666668, r[1], 107666.666667);
  ASSERT_NEAR(-4.4999999999999998e-07, r[2], 4.5e-12);
  ASSERT_NEAR(-4.4999999999999998e-07, r[3], 4.5e-12);
}

TEST(CubicRootTest, Test_193) {
  double r[4];
  double a[] = {0.00218025, 9690, 10766666666.6667};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-4.4999999999999998e-07, r[1], 4.5e-12);
  ASSERT_NEAR(-4.4999999999999998e-07, r[2], 4.5e-12);
  ASSERT_NEAR(-10766666666.666668, r[3], 107666.666667);
}

TEST(CubicRootTest, Test_194) {
  double r[4];
  double a[] = {52164500000000, 1.15921111111111e+20, -21533333333.3333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(10766666666.666668, r[1], 107666.666667);
  ASSERT_NEAR(10766666666.666668, r[2], 107666.666667);
  ASSERT_NEAR(-4.4999999999999998e-07, r[3], 4.5e-12);
}

TEST(CubicRootTest, Test_195) {
  double r[4];
  double a[] = {-52164500000000, 1.15921111111111e+20, -21533333333.3333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(10766666666.666668, r[1], 107666.666667);
  ASSERT_NEAR(10766666666.666668, r[2], 107666.666667);
  ASSERT_NEAR(4.4999999999999998e-07, r[3], 4.5e-12);
}

TEST(CubicRootTest, Test_196) {
  double r[4];
  double a[] = {52164500000000, 1.15921111111111e+20, 21533333333.3333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-4.4999999999999998e-07, r[1], 4.5e-12);
  ASSERT_NEAR(-10766666666.666668, r[2], 107666.666667);
  ASSERT_NEAR(-10766666666.666668, r[3], 107666.666667);
}

TEST(CubicRootTest, Test_197) {
  double r[4];
  double a[] = {-52164500000000, 1.15921111111111e+20, 21533333333.3333};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(4.4999999999999998e-07, r[1], 4.5e-12);
  ASSERT_NEAR(-10766666666.666668, r[2], 107666.666667);
  ASSERT_NEAR(-10766666666.666668, r[3], 107666.666667);
}

TEST(CubicRootTest, Test_198) {
  double r[4];
  double a[] = {-0.000402325, 14630, -133000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(133000000000, r[1], 1330000.0);
  ASSERT_NEAR(5.5000000000000003e-08, r[2], 5.5e-13);
  ASSERT_NEAR(5.5000000000000003e-08, r[3], 5.5e-13);
}

TEST(CubicRootTest, Test_199) {
  double r[4];
  double a[] = {0.000402325, -14630, 133000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.5000000000000003e-08, r[1], 5.5e-13);
  ASSERT_NEAR(5.5000000000000003e-08, r[2], 5.5e-13);
  ASSERT_NEAR(-133000000000, r[3], 1330000.0);
}

TEST(CubicRootTest, Test_200) {
  double r[4];
  double a[] = {-0.000402325, -14630, -133000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(133000000000, r[1], 1330000.0);
  ASSERT_NEAR(-5.5000000000000003e-08, r[2], 5.5e-13);
  ASSERT_NEAR(-5.5000000000000003e-08, r[3], 5.5e-13);
}

TEST(CubicRootTest, Test_201) {
  double r[4];
  double a[] = {0.000402325, 14630, 133000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-5.5000000000000003e-08, r[1], 5.5e-13);
  ASSERT_NEAR(-5.5000000000000003e-08, r[2], 5.5e-13);
  ASSERT_NEAR(-133000000000, r[3], 1330000.0);
}

TEST(CubicRootTest, Test_202) {
  double r[4];
  double a[] = {972895000000000, 1.7689e+22, -266000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(133000000000, r[1], 1330000.0);
  ASSERT_NEAR(133000000000, r[2], 1330000.0);
  ASSERT_NEAR(-5.5000000000000003e-08, r[3], 5.5e-13);
}

TEST(CubicRootTest, Test_203) {
  double r[4];
  double a[] = {-972895000000000, 1.7689e+22, -266000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(133000000000, r[1], 1330000.0);
  ASSERT_NEAR(133000000000, r[2], 1330000.0);
  ASSERT_NEAR(5.5000000000000003e-08, r[3], 5.5e-13);
}

TEST(CubicRootTest, Test_204) {
  double r[4];
  double a[] = {972895000000000, 1.7689e+22, 266000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-5.5000000000000003e-08, r[1], 5.5e-13);
  ASSERT_NEAR(-133000000000, r[2], 1330000.0);
  ASSERT_NEAR(-133000000000, r[3], 1330000.0);
}

TEST(CubicRootTest, Test_205) {
  double r[4];
  double a[] = {-972895000000000, 1.7689e+22, 266000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(5.5000000000000003e-08, r[1], 5.5e-13);
  ASSERT_NEAR(-133000000000, r[2], 1330000.0);
  ASSERT_NEAR(-133000000000, r[3], 1330000.0);
}

TEST(CubicRootTest, Test_206) {
  double r[4];
  double a[] = {-7.01316e-05, 21252, -1610000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1610000000000, r[1], 16100000.0);
  ASSERT_NEAR(6.6000000000000004e-09, r[2], 6.6e-14);
  ASSERT_NEAR(6.6000000000000004e-09, r[3], 6.6e-14);
}

TEST(CubicRootTest, Test_207) {
  double r[4];
  double a[] = {7.01316e-05, -21252, 1610000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(6.6000000000000004e-09, r[1], 6.6e-14);
  ASSERT_NEAR(6.6000000000000004e-09, r[2], 6.6e-14);
  ASSERT_NEAR(-1610000000000, r[3], 16100000.0);
}

TEST(CubicRootTest, Test_208) {
  double r[4];
  double a[] = {-7.01316e-05, -21252, -1610000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1610000000000, r[1], 16100000.0);
  ASSERT_NEAR(-6.6000000000000004e-09, r[2], 6.6e-14);
  ASSERT_NEAR(-6.6000000000000004e-09, r[3], 6.6e-14);
}

TEST(CubicRootTest, Test_209) {
  double r[4];
  double a[] = {7.01316e-05, 21252, 1610000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-6.6000000000000004e-09, r[1], 6.6e-14);
  ASSERT_NEAR(-6.6000000000000004e-09, r[2], 6.6e-14);
  ASSERT_NEAR(-1610000000000, r[3], 16100000.0);
}

TEST(CubicRootTest, Test_210) {
  double r[4];
  double a[] = {1.710786e+16, 2.5921e+24, -3220000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1610000000000, r[1], 16100000.0);
  ASSERT_NEAR(1610000000000, r[2], 16100000.0);
  ASSERT_NEAR(-6.6000000000000004e-09, r[3], 6.6e-14);
}

TEST(CubicRootTest, Test_211) {
  double r[4];
  double a[] = {-1.710786e+16, 2.5921e+24, -3220000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1610000000000, r[1], 16100000.0);
  ASSERT_NEAR(1610000000000, r[2], 16100000.0);
  ASSERT_NEAR(6.6000000000000004e-09, r[3], 6.6e-14);
}

TEST(CubicRootTest, Test_212) {
  double r[4];
  double a[] = {1.710786e+16, 2.5921e+24, 3220000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-6.6000000000000004e-09, r[1], 6.6e-14);
  ASSERT_NEAR(-1610000000000, r[2], 16100000.0);
  ASSERT_NEAR(-1610000000000, r[3], 16100000.0);
}

TEST(CubicRootTest, Test_213) {
  double r[4];
  double a[] = {-1.710786e+16, 2.5921e+24, 3220000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(6.6000000000000004e-09, r[1], 6.6e-14);
  ASSERT_NEAR(-1610000000000, r[2], 16100000.0);
  ASSERT_NEAR(-1610000000000, r[3], 16100000.0);
}

TEST(CubicRootTest, Test_214) {
  double r[4];
  double a[] = {-1.1661e-05, 29900, -19166666666666.7};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(19166666666666.668, r[1], 191666666.667);
  ASSERT_NEAR(7.7999999999999999e-10, r[2], 7.8e-15);
  ASSERT_NEAR(7.7999999999999999e-10, r[3], 7.8e-15);
}

TEST(CubicRootTest, Test_215) {
  double r[4];
  double a[] = {1.1661e-05, -29900, 19166666666666.7};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.7999999999999999e-10, r[1], 7.8e-15);
  ASSERT_NEAR(7.7999999999999999e-10, r[2], 7.8e-15);
  ASSERT_NEAR(-19166666666666.668, r[3], 191666666.667);
}

TEST(CubicRootTest, Test_216) {
  double r[4];
  double a[] = {-1.1661e-05, -29900, -19166666666666.7};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(19166666666666.668, r[1], 191666666.667);
  ASSERT_NEAR(-7.7999999999999999e-10, r[2], 7.8e-15);
  ASSERT_NEAR(-7.7999999999999999e-10, r[3], 7.8e-15);
}

TEST(CubicRootTest, Test_217) {
  double r[4];
  double a[] = {1.1661e-05, 29900, 19166666666666.7};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-7.7999999999999999e-10, r[1], 7.8e-15);
  ASSERT_NEAR(-7.7999999999999999e-10, r[2], 7.8e-15);
  ASSERT_NEAR(-19166666666666.668, r[3], 191666666.667);
}

TEST(CubicRootTest, Test_218) {
  double r[4];
  double a[] = {2.86541666666667e+17, 3.67361111111111e+26, -38333333333333.3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(19166666666666.668, r[1], 191666666.667);
  ASSERT_NEAR(19166666666666.668, r[2], 191666666.667);
  ASSERT_NEAR(-7.7999999999999999e-10, r[3], 7.8e-15);
}

TEST(CubicRootTest, Test_219) {
  double r[4];
  double a[] = {-2.86541666666667e+17, 3.67361111111111e+26, -38333333333333.3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(19166666666666.668, r[1], 191666666.667);
  ASSERT_NEAR(19166666666666.668, r[2], 191666666.667);
  ASSERT_NEAR(7.7999999999999999e-10, r[3], 7.8e-15);
}

TEST(CubicRootTest, Test_220) {
  double r[4];
  double a[] = {2.86541666666667e+17, 3.67361111111111e+26, 38333333333333.3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-7.7999999999999999e-10, r[1], 7.8e-15);
  ASSERT_NEAR(-19166666666666.668, r[2], 191666666.667);
  ASSERT_NEAR(-19166666666666.668, r[3], 191666666.667);
}

TEST(CubicRootTest, Test_221) {
  double r[4];
  double a[] = {-2.86541666666667e+17, 3.67361111111111e+26, 38333333333333.3};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(7.7999999999999999e-10, r[1], 7.8e-15);
  ASSERT_NEAR(-19166666666666.668, r[2], 191666666.667);
  ASSERT_NEAR(-19166666666666.668, r[3], 191666666.667);
}

TEST(CubicRootTest, Test_222) {
  double r[4];
  double a[] = {-1.863225e-06, 40950, -225000000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(225000000000000, r[1], 2250000000.0);
  ASSERT_NEAR(9.0999999999999996e-11, r[2], 9.1e-16);
  ASSERT_NEAR(9.0999999999999996e-11, r[3], 9.1e-16);
}

TEST(CubicRootTest, Test_223) {
  double r[4];
  double a[] = {1.863225e-06, -40950, 225000000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9.0999999999999996e-11, r[1], 9.1e-16);
  ASSERT_NEAR(9.0999999999999996e-11, r[2], 9.1e-16);
  ASSERT_NEAR(-225000000000000, r[3], 2250000000.0);
}

TEST(CubicRootTest, Test_224) {
  double r[4];
  double a[] = {-1.863225e-06, -40950, -225000000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(225000000000000, r[1], 2250000000.0);
  ASSERT_NEAR(-9.0999999999999996e-11, r[2], 9.1e-16);
  ASSERT_NEAR(-9.0999999999999996e-11, r[3], 9.1e-16);
}

TEST(CubicRootTest, Test_225) {
  double r[4];
  double a[] = {1.863225e-06, 40950, 225000000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-9.0999999999999996e-11, r[1], 9.1e-16);
  ASSERT_NEAR(-9.0999999999999996e-11, r[2], 9.1e-16);
  ASSERT_NEAR(-225000000000000, r[3], 2250000000.0);
}

TEST(CubicRootTest, Test_226) {
  double r[4];
  double a[] = {4.606875e+18, 5.0625e+28, -450000000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(225000000000000, r[1], 2250000000.0);
  ASSERT_NEAR(225000000000000, r[2], 2250000000.0);
  ASSERT_NEAR(-9.0999999999999996e-11, r[3], 9.1e-16);
}

TEST(CubicRootTest, Test_227) {
  double r[4];
  double a[] = {-4.606875e+18, 5.0625e+28, -450000000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(225000000000000, r[1], 2250000000.0);
  ASSERT_NEAR(225000000000000, r[2], 2250000000.0);
  ASSERT_NEAR(9.0999999999999996e-11, r[3], 9.1e-16);
}

TEST(CubicRootTest, Test_228) {
  double r[4];
  double a[] = {4.606875e+18, 5.0625e+28, 450000000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-9.0999999999999996e-11, r[1], 9.1e-16);
  ASSERT_NEAR(-225000000000000, r[2], 2250000000.0);
  ASSERT_NEAR(-225000000000000, r[3], 2250000000.0);
}

TEST(CubicRootTest, Test_229) {
  double r[4];
  double a[] = {-4.606875e+18, 5.0625e+28, 450000000000000};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(9.0999999999999996e-11, r[1], 9.1e-16);
  ASSERT_NEAR(-225000000000000, r[2], 2250000000.0);
  ASSERT_NEAR(-225000000000000, r[3], 2250000000.0);
}

TEST(CubicRootTest, Test_230) {
  double r[4];
  double a[] = {-2.877525e-07, 54810, -2.61e+15};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2610000000000000, r[1], 26100000000.0);
  ASSERT_NEAR(1.0499999999999999e-11, r[2], 1.05e-16);
  ASSERT_NEAR(1.0499999999999999e-11, r[3], 1.05e-16);
}

TEST(CubicRootTest, Test_231) {
  double r[4];
  double a[] = {2.877525e-07, -54810, 2.61e+15};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.0499999999999999e-11, r[1], 1.05e-16);
  ASSERT_NEAR(1.0499999999999999e-11, r[2], 1.05e-16);
  ASSERT_NEAR(-2610000000000000, r[3], 26100000000.0);
}

TEST(CubicRootTest, Test_232) {
  double r[4];
  double a[] = {-2.877525e-07, -54810, -2.61e+15};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2610000000000000, r[1], 26100000000.0);
  ASSERT_NEAR(-1.0499999999999999e-11, r[2], 1.05e-16);
  ASSERT_NEAR(-1.0499999999999999e-11, r[3], 1.05e-16);
}

TEST(CubicRootTest, Test_233) {
  double r[4];
  double a[] = {2.877525e-07, 54810, 2.61e+15};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.0499999999999999e-11, r[1], 1.05e-16);
  ASSERT_NEAR(-1.0499999999999999e-11, r[2], 1.05e-16);
  ASSERT_NEAR(-2610000000000000, r[3], 26100000000.0);
}

TEST(CubicRootTest, Test_234) {
  double r[4];
  double a[] = {7.152705e+19, 6.8121e+30, -5.22e+15};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2610000000000000, r[1], 26100000000.0);
  ASSERT_NEAR(2610000000000000, r[2], 26100000000.0);
  ASSERT_NEAR(-1.0499999999999999e-11, r[3], 1.05e-16);
}

TEST(CubicRootTest, Test_235) {
  double r[4];
  double a[] = {-7.152705e+19, 6.8121e+30, -5.22e+15};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(2610000000000000, r[1], 26100000000.0);
  ASSERT_NEAR(2610000000000000, r[2], 26100000000.0);
  ASSERT_NEAR(1.0499999999999999e-11, r[3], 1.05e-16);
}

TEST(CubicRootTest, Test_236) {
  double r[4];
  double a[] = {7.152705e+19, 6.8121e+30, 5.22e+15};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.0499999999999999e-11, r[1], 1.05e-16);
  ASSERT_NEAR(-2610000000000000, r[2], 26100000000.0);
  ASSERT_NEAR(-2610000000000000, r[3], 26100000000.0);
}

TEST(CubicRootTest, Test_237) {
  double r[4];
  double a[] = {-7.152705e+19, 6.8121e+30, 5.22e+15};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.0499999999999999e-11, r[1], 1.05e-16);
  ASSERT_NEAR(-2610000000000000, r[2], 26100000000.0);
  ASSERT_NEAR(-2610000000000000, r[3], 26100000000.0);
}

TEST(CubicRootTest, Test_238) {
  double r[4];
  double a[] = {-4.3152e-08, 71920, -2.99666666666667e+16};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(29966666666666668, r[1], 2.99666666667e+11);
  ASSERT_NEAR(1.1999999999999999e-12, r[2], 1.2e-17);
  ASSERT_NEAR(1.1999999999999999e-12, r[3], 1.2e-17);
}

TEST(CubicRootTest, Test_239) {
  double r[4];
  double a[] = {4.3152e-08, -71920, 2.99666666666667e+16};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1999999999999999e-12, r[1], 1.2e-17);
  ASSERT_NEAR(1.1999999999999999e-12, r[2], 1.2e-17);
  ASSERT_NEAR(-29966666666666668, r[3], 2.99666666667e+11);
}

TEST(CubicRootTest, Test_240) {
  double r[4];
  double a[] = {-4.3152e-08, -71920, -2.99666666666667e+16};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(29966666666666668, r[1], 2.99666666667e+11);
  ASSERT_NEAR(-1.1999999999999999e-12, r[2], 1.2e-17);
  ASSERT_NEAR(-1.1999999999999999e-12, r[3], 1.2e-17);
}

TEST(CubicRootTest, Test_241) {
  double r[4];
  double a[] = {4.3152e-08, 71920, 2.99666666666667e+16};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.1999999999999999e-12, r[1], 1.2e-17);
  ASSERT_NEAR(-1.1999999999999999e-12, r[2], 1.2e-17);
  ASSERT_NEAR(-29966666666666668, r[3], 2.99666666667e+11);
}

TEST(CubicRootTest, Test_242) {
  double r[4];
  double a[] = {1.07760133333333e+21, 8.98001111111111e+32, -5.99333333333333e+16};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(29966666666666668, r[1], 2.99666666667e+11);
  ASSERT_NEAR(29966666666666668, r[2], 2.99666666667e+11);
  ASSERT_NEAR(-1.1999999999999999e-12, r[3], 1.2e-17);
}

TEST(CubicRootTest, Test_243) {
  double r[4];
  double a[] = {-1.07760133333333e+21, 8.98001111111111e+32, -5.99333333333333e+16};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(29966666666666668, r[1], 2.99666666667e+11);
  ASSERT_NEAR(29966666666666668, r[2], 2.99666666667e+11);
  ASSERT_NEAR(1.1999999999999999e-12, r[3], 1.2e-17);
}

TEST(CubicRootTest, Test_244) {
  double r[4];
  double a[] = {1.07760133333333e+21, 8.98001111111111e+32, 5.99333333333333e+16};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.1999999999999999e-12, r[1], 1.2e-17);
  ASSERT_NEAR(-29966666666666668, r[2], 2.99666666667e+11);
  ASSERT_NEAR(-29966666666666668, r[3], 2.99666666667e+11);
}

TEST(CubicRootTest, Test_245) {
  double r[4];
  double a[] = {-1.07760133333333e+21, 8.98001111111111e+32, 5.99333333333333e+16};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.1999999999999999e-12, r[1], 1.2e-17);
  ASSERT_NEAR(-29966666666666668, r[2], 2.99666666667e+11);
  ASSERT_NEAR(-29966666666666668, r[3], 2.99666666667e+11);
}

TEST(CubicRootTest, Test_246) {
  double r[4];
  double a[] = {-6.307136e-09, 92752, -3.41e+17};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.41e+17, r[1], 3.41e+12);
  ASSERT_NEAR(1.36e-13, r[2], 1.36e-18);
  ASSERT_NEAR(1.36e-13, r[3], 1.36e-18);
}

TEST(CubicRootTest, Test_247) {
  double r[4];
  double a[] = {6.307136e-09, -92752, 3.41e+17};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.36e-13, r[1], 1.36e-18);
  ASSERT_NEAR(1.36e-13, r[2], 1.36e-18);
  ASSERT_NEAR(-3.41e+17, r[3], 3.41e+12);
}

TEST(CubicRootTest, Test_248) {
  double r[4];
  double a[] = {-6.307136e-09, -92752, -3.41e+17};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.41e+17, r[1], 3.41e+12);
  ASSERT_NEAR(-1.36e-13, r[2], 1.36e-18);
  ASSERT_NEAR(-1.36e-13, r[3], 1.36e-18);
}

TEST(CubicRootTest, Test_249) {
  double r[4];
  double a[] = {6.307136e-09, 92752, 3.41e+17};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.36e-13, r[1], 1.36e-18);
  ASSERT_NEAR(-1.36e-13, r[2], 1.36e-18);
  ASSERT_NEAR(-3.41e+17, r[3], 3.41e+12);
}

TEST(CubicRootTest, Test_250) {
  double r[4];
  double a[] = {1.5814216e+22, 1.16281e+35, -6.82e+17};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.41e+17, r[1], 3.41e+12);
  ASSERT_NEAR(3.41e+17, r[2], 3.41e+12);
  ASSERT_NEAR(-1.36e-13, r[3], 1.36e-18);
}

TEST(CubicRootTest, Test_251) {
  double r[4];
  double a[] = {-1.5814216e+22, 1.16281e+35, -6.82e+17};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(3.41e+17, r[1], 3.41e+12);
  ASSERT_NEAR(3.41e+17, r[2], 3.41e+12);
  ASSERT_NEAR(1.36e-13, r[3], 1.36e-18);
}

TEST(CubicRootTest, Test_252) {
  double r[4];
  double a[] = {1.5814216e+22, 1.16281e+35, 6.82e+17};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(-1.36e-13, r[1], 1.36e-18);
  ASSERT_NEAR(-3.41e+17, r[2], 3.41e+12);
  ASSERT_NEAR(-3.41e+17, r[3], 3.41e+12);
}

TEST(CubicRootTest, Test_253) {
  double r[4];
  double a[] = {-1.5814216e+22, 1.16281e+35, 6.82e+17};
  int num_roots = rcubic_roots(a, r);
  ASSERT_EQ(2, num_roots);
  ASSERT_NEAR(1.36e-13, r[1], 1.36e-18);
  ASSERT_NEAR(-3.41e+17, r[2], 3.41e+12);
  ASSERT_NEAR(-3.41e+17, r[3], 3.41e+12);
}
