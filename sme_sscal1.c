#include <stdint.h>
#include <arm_sme.h>

__arm_locally_streaming
__arm_new("za")
void sscal1(float factor, float *vec, int vec_size)
{
    // Duplicate scalar across all lanes
    svfloat32_t factor_vec = svdup_f32((float32_t)factor);

    // Loop over the vector in chunks of vector size
    // svcntw() gives the number of elements per register
    for (int i = 0; i < vec_size; i += svcntw()) {
        svbool_t mask = svwhilelt_b32((uint64_t)i, (uint64_t)vec_size);

        // Load the vector chunk into an SVE register
        svfloat32_t vec_chunk = svld1_f32(mask, &vec[i]);

        // Perform element-wise multiplication
        svfloat32_t result = svmul_f32_m(mask, vec_chunk, factor_vec);
        
        // Store the result back into memory
        svst1_f32(mask, &vec[i], result);   
    }
}
