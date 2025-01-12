#include <stdint.h>
#include <arm_neon.h>

void sscal1(float factor, float *vec, int vec_size)
{
    float32x4_t factor_vec = vdupq_n_f32((float32_t)factor);

    for (int i = 0; i < vec_size; i += 32) {
        float32x4_t vec_chunk1 = vld1q_f32(&vec[i]);
        float32x4_t vec_chunk2 = vld1q_f32(&vec[i + 4]);
        float32x4_t vec_chunk3 = vld1q_f32(&vec[i + 8]);
        float32x4_t vec_chunk4 = vld1q_f32(&vec[i + 12]);
        float32x4_t vec_chunk5 = vld1q_f32(&vec[i + 16]);
        float32x4_t vec_chunk6 = vld1q_f32(&vec[i + 20]);
        float32x4_t vec_chunk7 = vld1q_f32(&vec[i + 24]);
        float32x4_t vec_chunk8 = vld1q_f32(&vec[i + 28]);
        float32x4_t result1 = vmulq_f32(vec_chunk1, factor_vec);
        float32x4_t result2 = vmulq_f32(vec_chunk2, factor_vec);
        float32x4_t result3 = vmulq_f32(vec_chunk3, factor_vec);
        float32x4_t result4 = vmulq_f32(vec_chunk4, factor_vec);
        float32x4_t result5 = vmulq_f32(vec_chunk5, factor_vec);
        float32x4_t result6 = vmulq_f32(vec_chunk6, factor_vec);
        float32x4_t result7 = vmulq_f32(vec_chunk7, factor_vec);
        float32x4_t result8 = vmulq_f32(vec_chunk8, factor_vec);
        vst1q_f32(&vec[i], result1);
        vst1q_f32(&vec[i + 4], result2);
        vst1q_f32(&vec[i + 8], result3);
        vst1q_f32(&vec[i + 12], result4);
        vst1q_f32(&vec[i + 16], result5);
        vst1q_f32(&vec[i + 20], result6);
        vst1q_f32(&vec[i + 24], result7);
        vst1q_f32(&vec[i + 28], result8);
    }
}

void sscal_scopy(float factor, float *in, float *out, int vec_size)
{
    float32x4_t factor_vec = vdupq_n_f32((float32_t)factor);

    for (int i = 0; i < vec_size; i += 32) {
        float32x4_t vec_chunk1 = vld1q_f32(&in[i]);
        float32x4_t vec_chunk2 = vld1q_f32(&in[i + 4]);
        float32x4_t vec_chunk3 = vld1q_f32(&in[i + 8]);
        float32x4_t vec_chunk4 = vld1q_f32(&in[i + 12]);
        float32x4_t vec_chunk5 = vld1q_f32(&in[i + 16]);
        float32x4_t vec_chunk6 = vld1q_f32(&in[i + 20]);
        float32x4_t vec_chunk7 = vld1q_f32(&in[i + 24]);
        float32x4_t vec_chunk8 = vld1q_f32(&in[i + 28]);
        float32x4_t result1 = vmulq_f32(vec_chunk1, factor_vec);
        float32x4_t result2 = vmulq_f32(vec_chunk2, factor_vec);
        float32x4_t result3 = vmulq_f32(vec_chunk3, factor_vec);
        float32x4_t result4 = vmulq_f32(vec_chunk4, factor_vec);
        float32x4_t result5 = vmulq_f32(vec_chunk5, factor_vec);
        float32x4_t result6 = vmulq_f32(vec_chunk6, factor_vec);
        float32x4_t result7 = vmulq_f32(vec_chunk7, factor_vec);
        float32x4_t result8 = vmulq_f32(vec_chunk8, factor_vec);
        vst1q_f32(&out[i], result1);
        vst1q_f32(&out[i + 4], result2);
        vst1q_f32(&out[i + 8], result3);
        vst1q_f32(&out[i + 12], result4);
        vst1q_f32(&out[i + 16], result5);
        vst1q_f32(&out[i + 20], result6);
        vst1q_f32(&out[i + 24], result7);
        vst1q_f32(&out[i + 28], result8);
    }
}
