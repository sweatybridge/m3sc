# Scientific Computation
M3SC coursework implemented in C with tests written in C++ using [gTest](https://github.com/google/googletest).
This project is now open source because the original course is no longer being taught at Imperial College London (it's replaced by a similar course that uses Python).

```
m3sc
├── exer0            // trivial demo programs for exploring different data types in C
├── exer1a
│   ├── prog_1.c     // naive quadratic solver
│   ├── prog_2.c     // using prog_1 to calculate planetary radius
│   ├── prog_3.c     // handle floating point limits in prog_1
│   └── mastery.c    // quadratic solver for complex numbers
├── exer1b
│   ├── lin.c        // refactored linear root solver
│   ├── quad.c       // fully functional quadratic solver
│   ├── cubic.c      // reduced cubic solver using Newton-Rapheson method
│   ├── prog_1.c     // demo program for quad.c
│   ├── prog_2.c     // demo program for cubic.c
│   ├── prog_4.c     // using cubic.c to solve Van der Waals equation
│   ├── prog_4.c     // demo program for date and time printing
│   └── mastery.c    // reduced cubic solver for complex numbers
├── exer1c
│   ├── array.c      // previous solvers passing array as arguments
│   ├── quartic.c    // reduced quartic solver with a few unhandled edge cases
│   ├── prog_1.c     // demo program for array.c
│   ├── prog_2.c     // demo program for quartic.c
│   ├── prog_3.c     // using quartic.c to calculate satelite position above Earth's surface
│   └── mastery.c    // reduced quartic solver for complex numbers
├── exer2
│   ├── solve_linear.c // Gaussian elimination without pivoting and LU decomposition
│   ├── prog_1.c     // demo program for Gaussian elimination (with timing)
│   ├── prog_3.c     // demo program for efficiently solving banded matrices
│   ├── prog_5.c     // Poisson's equation solver for 1D (with timeout and smoothing)
│   ├── prog_6.c     // Poisson's equation solver for 2D (with timeout and smoothing)
│   └── mastery.c    // Poisson's equation solver for 3D (with timeout and smoothing)
├── exer3
│   ├── dst.c        // fast real discrete sine transform by STU factorization
│   ├── sfactors.c   // reduce computational cost of U_N by caching
│   ├── prog_1.c     // demo program for sfactors.c
│   ├── prog_4.c     // demo program for dst.c for N = 2^n and N = 3 * 2^n (with timing)
│   ├── prog_5.c     // using dst.c to solve finite difference approxmiation to Poisson's equation (2D)
│   └── mastery.c    // dst.c for N = 5 * 2^n
└── tests            // all tests depend on gtest
```
## Build
```
mkdir build
cd build
cmake ..
make
```
