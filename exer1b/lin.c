int lin_root(double a1, double a0, double *r) {
  if (a1 == 0) {
    // TODO: replace with NAN
    *r = 0;
    return a0 == 0 ? 0 : -1;
  }

  *r = -a0 / a1;

  return 1;
}
