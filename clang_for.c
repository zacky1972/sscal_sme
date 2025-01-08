void sscal1(float factor, float *vec, int vec_size)
{
    for(int i = 0; i < vec_size; i++) {
        vec[i] *= factor;
    }
}

void sscal_scopy(float factor, float *in, float *out, int vec_size)
{
    for(int i = 0; i < vec_size; i++) {
        out[i] = in[i] * factor; 
    }
}