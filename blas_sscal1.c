#ifdef USE_OPEN_BLAS
#include <cblas.h>
#else // USE_OPEN_BLAS
#include <Accelerate/Accelerate.h>
#endif // USE_OPEN_BLAS

void sscal1(float factor, float *vec, int vec_size)
{
    cblas_sscal(vec_size, factor, vec, 1);
}

void sscal_scopy(float factor, float *in, float *out, int vec_size)
{
    cblas_scopy(vec_size, in, 1, out, 1);
    cblas_sscal(vec_size, factor, out, 1);
}
