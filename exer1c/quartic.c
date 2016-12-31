#include <math.h>

int doubleEqual(double a, double b);
int quad_roots(double *a, double *r);
int rcubic_roots(double *a, double *r);
void swap(double *a, double *b);
void bubbleSort(double *root, int size);

// PRE: roots are sorted
int countReal(double *r) {
  if (r[1] == r[2] && r[2] == r[3] && r[3] == r[4]) {
    return 1;
  } else if ((r[1] == r[2] && r[2] == r[3])
      || (r[2] == r[3] && r[3] == r[4])) {
    return 1;
  } else if (r[1] == r[2] && r[3] == r[4]) {
    return 2;
  } else if (r[1] == r[2] || r[2] == r[3] || r[3] == r[4]) {
    return 3;
  } else {
    return 4;
  }
}

int rquartic_roots(double *a, double *root) {
  if (a[0] == 0) {
    // cubic equation
    int num_roots = rcubic_roots(a + 1, root + 1);
    root[1] = 0;
    if (num_roots == 0) {
      // 1 real root, 2 complex, could be repeated
      if (root[1] < root[2]) {
        swap(&root[1], &root[2]);
      }
      return 2;
    } else {
      bubbleSort(root + 1, 4);
      return countReal(root);
    }
  } else if (a[3] == 0 && a[2] == 0 && a[1] == 0) {
    // roots of unity
    if (a[0] <= 0) {
      // 2 real roots
      root[1] = sqrt(sqrt(-a[0]));
      root[2] = -root[1];
      // complex roots
      root[3] = 0;
      root[4] = root[1];
      return 2;
    } else {
      // no real roots
      root[1] = sqrt(sqrt(a[0])) / sqrt(2.);
      root[2] = root[1];
      // complex root 2
      root[3] = -root[1];
      root[4] = root[1];
      return 0;
    }
  } else if (a[3] == 0 && a[1] == 0) {
    // quadratic equation
    double coeff[] = {a[0], a[2], 1.0};
    int num_roots = quad_roots(coeff, root + 2);
    if (num_roots > 0) {
      // x^2 = r[3] or x^2 = r[4]
      if (root[3] >= 0 && root[4] >= 0) {
        // r3 > r4 since quad_root is descending
        // 4 real roots
        root[1] = sqrt(root[3]);
        root[2] = sqrt(root[4]);
        root[3] = -root[2];
        root[4] = -root[1];
        return root[1] == root[2] ? 3 : 4;
      } else if (root[3] < 0 && root[4] < 0) {
        // two complex roots
        root[1] = 0;
        root[2] = sqrt(-root[3]);
        root[3] = 0;
        root[4] = sqrt(-root[4]);
        return 0;
      } else {
        // r[3] > 0, r[4] <= 0
        // two real, one complex
        root[1] = sqrt(root[3]);
        root[2] = -sqrt(root[3]);
        root[3] = 0;
        root[4] = sqrt(-root[4]);
        return 2;
      }
    } else {
      // x^2 = r[3] +- r[4] * I
      // two complex roots
      if (root[3] >= 0) {
        // avoids subtracting nearly equal numbers
        root[1] = sqrt((sqrt(root[3] * root[3] + root[4] * root[4]) + root[3]) / 2);
        root[2] = root[4] / 2 / root[1];
      } else {
        // r[3] < 0
        root[2] = sqrt((sqrt(root[3] * root[3] + root[4] * root[4]) - root[3]) / 2);
        root[1] = root[4] / 2 / root[2];
      }
      root[3] = -root[1];
      root[4] = root[2];
      return 0;
    }
  } else {
    double b[3];
    b[2] = -a[2];
    // TODO: overflow
    b[1] = a[1] * a[3] - 4 * a[0];
    // TODO: overflow
    b[0] = 4 * a[0] * a[2] - a[1] * a[1] - a[0] * a[3] * a[3];

    rcubic_roots(b, root);
    // TODO: special case when num_roots == 2

    double p[3], q[3];

    // {(+,+),(-,-)}
    p[2] = 1.0;
    p[1] = a[3] / 2. + sqrt(a[3] * a[3] / 4. + root[1] - a[2]);
    p[0] = root[1] / 2. + sqrt(root[1] * root[1] / 4. - a[0]);
    q[2] = 1.0;
    q[1] = a[3] / 2. - sqrt(a[3] * a[3] / 4. + root[1] - a[2]);
    q[0] = root[1] / 2. - sqrt(root[1] * root[1] / 4. - a[0]);

    if (!doubleEqual(q[1] * p[0], a[1] - p[1] * q[0])) {
      // use {(+,-),(-,+)}
      p[2] = 1.0;
      p[1] = a[3] / 2. + sqrt(a[3] * a[3] / 4. + root[1] - a[2]);
      p[0] = root[1] / 2. - sqrt(root[1] * root[1] / 4. - a[0]);
      q[2] = 1.0;
      q[1] = a[3] / 2. - sqrt(a[3] * a[3] / 4. + root[1] - a[2]);
      q[0] = root[1] / 2. + sqrt(root[1] * root[1] / 4. - a[0]);
    }

    int num_roots_q1 = quad_roots(p, root);
    int num_roots_q2 = quad_roots(q, root + 2);

    if (num_roots_q1 == 0 && num_roots_q2 == 0) {
      // two complex roots
      if (root[1] < root[3]) {
        swap(&root[1], &root[3]);
        swap(&root[2], &root[4]);
      }
      return 0;
    } else if (num_roots_q1 > 0 && num_roots_q2 > 0) {
      bubbleSort(root + 1, 4);
      return countReal(root);
    } else {
      if (num_roots_q1 == 0) {
        swap(&root[1], &root[3]);
        swap(&root[2], &root[4]);
      }
      return 2;
    }
  }
}
