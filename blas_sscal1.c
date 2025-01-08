#ifdef USE_OPEN_BLAS
#include <cblas.h>
#else // USE_OPEN_BLAS
#include <Accelerate/Accelerate.h>
#endif // USE_OPEN_BLAS

void sscal1(float factor, float *vec, int vec_size)
{
    cblas_sscal(vec_size, factor, vec, 1);
}
