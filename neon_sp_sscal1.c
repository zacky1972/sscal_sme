#include <stdint.h>
#include <arm_neon.h>

void sscal1(float factor, float *vec, int vec_size)
{
    float32x4_t factor_vec = vdupq_n_f32((float32_t)factor);

    int i;
    float32x4_t vec_chunk, result;

    i = 0;
    vec_chunk = vld1q_f32(&vec[i]);

    i += 4;
    result = vmulq_f32(vec_chunk, factor_vec);
    vec_chunk = vld1q_f32(&vec[i]);

    for (i += 4; i < vec_size;) {
        vst1q_f32(&vec[i - 8], result);
        result = vmulq_f32(vec_chunk, factor_vec);
        vec_chunk = vld1q_f32(&vec[i]);
        i += 4;
    }

    vst1q_f32(&vec[i - 8], result);
    result = vmulq_f32(vec_chunk, factor_vec);
    i += 4;
    vst1q_f32(&vec[i - 8], result);
}

void sscal_scopy(float factor, float *in, float *out, int vec_size)
{
    float32x4_t factor_vec = vdupq_n_f32((float32_t)factor);

    int i;
    float32x4_t vec_chunk, result;

    i = 0;
    vec_chunk = vld1q_f32(&in[i]);

    i += 4;
    result = vmulq_f32(vec_chunk, factor_vec);
    vec_chunk = vld1q_f32(&in[i]);

    for (i += 4; i < vec_size;) {
        vst1q_f32(&out[i - 8], result);
        result = vmulq_f32(vec_chunk, factor_vec);
        vec_chunk = vld1q_f32(&in[i]);
        i += 4;
    }

    vst1q_f32(&out[i - 8], result);
    result = vmulq_f32(vec_chunk, factor_vec);
    i += 4;
    vst1q_f32(&out[i - 8], result);
}
