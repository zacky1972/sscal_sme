#include <stdint.h>
#include <arm_neon.h>

void sscal1(float factor, float *vec, int vec_size)
{
    float32x4_t factor_vec = vdupq_n_f32((float32_t)factor);

    for (int i = 0; i < vec_size; i += 8) {
        float32x4_t vec_chunk1 = vld1q_f32(&vec[i]);
        float32x4_t vec_chunk2 = vld1q_f32(&vec[i + 4]);
        float32x4_t result1 = vmulq_f32(vec_chunk1, factor_vec);
        float32x4_t result2 = vmulq_f32(vec_chunk2, factor_vec);
        vst1q_f32(&vec[i], result1);
        vst1q_f32(&vec[i + 4], result2);
    }
}

void sscal_scopy(float factor, float *in, float *out, int vec_size)
{
    float32x4_t factor_vec = vdupq_n_f32((float32_t)factor);

    for (int i = 0; i < vec_size; i += 8) {
        float32x4_t vec_chunk1 = vld1q_f32(&in[i]);
        float32x4_t vec_chunk2 = vld1q_f32(&in[i + 4]);
        float32x4_t result1 = vmulq_f32(vec_chunk1, factor_vec);
        float32x4_t result2 = vmulq_f32(vec_chunk2, factor_vec);
        vst1q_f32(&out[i], result1);
        vst1q_f32(&out[i + 4], result2);
    }
}
