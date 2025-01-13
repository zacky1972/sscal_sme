#include <stdint.h>
#include <arm_sme.h>

__arm_locally_streaming
__arm_new("za")
void sscal1(float factor, float *vec, int vec_size)
{
    svfloat32_t factor_vec = svdup_f32((float32_t)factor);

    const uint64_t load = svcntw();
    const uint64_t store = svcntw() * 3;

    int i;
    svbool_t mask1, mask2, mask3, mask4;
    svfloat32_t vec_chunk, result;

    i = 0;
    mask1 = svwhilelt_b32((uint64_t)i, (uint64_t)vec_size);
    
    i += svcntw();
    vec_chunk = svld1_f32(mask1, &vec[i - load]);
    mask2 = svwhilelt_b32((uint64_t)i, (uint64_t)vec_size);

    i += svcntw();
    result = svmul_f32_m(mask1, vec_chunk, factor_vec);
    vec_chunk = svld1_f32(mask2, &vec[i - load]);
    mask3 = svwhilelt_b32((uint64_t)i, (uint64_t)vec_size);

    for (i += svcntw(); i < vec_size;) {
        svst1_f32(mask1, &vec[i - store], result); 
        result = svmul_f32_m(mask2, vec_chunk, factor_vec);
        vec_chunk = svld1_f32(mask3, &vec[i - load]);
        mask4 = svwhilelt_b32((uint64_t)i, (uint64_t)vec_size);
        i += svcntw();
    }

    svst1_f32(mask2, &vec[i - store], result); 
    result = svmul_f32_m(mask3, vec_chunk, factor_vec);
    vec_chunk = svld1_f32(mask4, &vec[i - load]);

    i += svcntw();
    svst1_f32(mask3, &vec[i - store], result); 
    result = svmul_f32_m(mask4, vec_chunk, factor_vec);

    i += svcntw();
    svst1_f32(mask4, &vec[i - store], result); 
}

__arm_locally_streaming
__arm_new("za")
void sscal_scopy(float factor, float *in, float *out, int vec_size)
{
    svfloat32_t factor_vec = svdup_f32((float32_t)factor);

    const uint64_t load = svcntw();
    const uint64_t store = svcntw() * 3;

    int i;
    svbool_t mask1, mask2, mask3, mask4;
    svfloat32_t vec_chunk, result;

    i = 0;
    mask1 = svwhilelt_b32((uint64_t)i, (uint64_t)vec_size);
    
    i += svcntw();
    vec_chunk = svld1_f32(mask1, &in[i - load]);
    mask2 = svwhilelt_b32((uint64_t)i, (uint64_t)vec_size);

    i += svcntw();
    result = svmul_f32_m(mask1, vec_chunk, factor_vec);
    vec_chunk = svld1_f32(mask2, &in[i - load]);
    mask3 = svwhilelt_b32((uint64_t)i, (uint64_t)vec_size);

    for (i += svcntw(); i < vec_size;) {
        svst1_f32(mask1, &out[i - store], result); 
        result = svmul_f32_m(mask2, vec_chunk, factor_vec);
        vec_chunk = svld1_f32(mask3, &in[i - load]);
        mask4 = svwhilelt_b32((uint64_t)i, (uint64_t)vec_size);
        i += svcntw();
    }

    svst1_f32(mask2, &out[i - store], result); 
    result = svmul_f32_m(mask3, vec_chunk, factor_vec);
    vec_chunk = svld1_f32(mask4, &in[i - load]);

    i += svcntw();
    svst1_f32(mask3, &out[i - store], result); 
    result = svmul_f32_m(mask4, vec_chunk, factor_vec);

    i += svcntw();
    svst1_f32(mask4, &out[i - store], result); 
}
