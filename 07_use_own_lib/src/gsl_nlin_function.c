/*
  File:   gsl_nlin_function.c
  Author: lflrsilva

*/

#include <stdio.h>
#include <stdlib.h>
#include <gsl_errno.h>
#include <gsl_math.h>
#include <gsl_roots.h>
// Included my routines header
#include "gsl_routines.h"

int main(void) {
    
    int i, status, maxIter = 100;
    double x_lo = 0.0, x_hi = 5.0;
    double root, answer = sqrt(5.0);
    double abstol = 1.e-8;
    double reltol = 1.e-5;

    // Choosing non-linear solver
    // Info: gsl_root_fsolver  - bounded methods 
    //       options : gsl_root_fsolver_bisection
    //                 gsl_root_fsolver_falsepos
    //                 gsl_root_fsolver_brent
    //
    //       gsl_root_fdfsolver - gradient based methods
    //       options : gsl_root_fdfsolver_newton
    //                 gsl_root_fdfsolver_secant
    //                 gsl_root_fdfsolver_steffenson
    const gsl_root_fsolver_type* T = gsl_root_fsolver_bisection;

    // Allocating memory to execute specified solver
    // Info: gsl_root_fsolver   - bounded methods
    //       gsl_root_fdfsolver - gradient based methods
    gsl_root_fsolver* s = gsl_root_fsolver_alloc(T);

    // Function and parameters
    gsl_function F;
    struct my_f_params parametros = {1.0, 0.0, -5.0};

    F.function = &my_f;
    F.params   = &parametros;

    // Intialise solver data set
    // gsl_root_fsolver_set
    // (
    //     gsl_root_fsolver * s,
    //     gsl_function * F,
    //     double x_lower,
    //     double x_upper
    //  )    
    gsl_root_fsolver_set(s, &F, x_lo, x_hi);

    printf ("s is a '%s' solver\n", gsl_root_fsolver_name(s));

    // Let's go!
    i = 0;
    root   = 0.0;
    status = 0;
    
    printf("%5d %5d [%.7f, %.7f] %.7f %+.7f %.7f\n",
               i, status, x_lo, x_hi, root, root-answer, x_hi-x_lo);

    do
    {
        i++;

        // solver iteration
        status = gsl_root_fsolver_iterate(s);

        // checking root
        root   = gsl_root_fsolver_root(s);

        // new bounded limits
        x_lo   = gsl_root_fsolver_x_lower(s);
        x_hi   = gsl_root_fsolver_x_upper(s);

        // checking convergence
        status = gsl_root_test_interval(x_lo, x_hi, abstol, reltol);
        
        if (status == GSL_SUCCESS)
        {
             printf("Convergence achieved!\n");
        }

        printf("%5d %5d [%.7f, %.7f] %.7f %+.7f %.7f\n",
                   i, status, x_lo, x_hi, root, root-answer, x_hi-x_lo);
    }
    while (status == GSL_CONTINUE && i < maxIter);

    //- free memory, please
    gsl_root_fsolver_free(s);

    return (EXIT_SUCCESS);
}
