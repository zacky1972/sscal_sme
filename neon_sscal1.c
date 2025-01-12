#include <stdint.h>
#include <arm_neon.h>

void sscal1(float factor, float *vec, int vec_size)
{
    float32x4_t factor_vec = vdupq_n_f32((float32_t)factor);

    for (int i = 0; i < vec_size; i += 4) {
        float32x4_t vec_chunk = vld1q_f32(&vec[i]);
        float32x4_t result = vmulq_f32(vec_chunk, factor_vec);
        vst1q_f32(&vec[i], result);
    }
}

void sscal_scopy(float factor, float *in, float *out, int vec_size)
{
    float32x4_t factor_vec = vdupq_n_f32((float32_t)factor);

    for (int i = 0; i < vec_size; i += 4) {
        float32x4_t vec_chunk = vld1q_f32(&in[i]);
        float32x4_t result = vmulq_f32(vec_chunk, factor_vec);
        vst1q_f32(&out[i], result);
    }
}
