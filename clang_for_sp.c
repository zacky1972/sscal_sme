void sscal1(float factor, float *vec, int vec_size)
{
    int i;
    float chunk;
    float result;

    i = 0;
    chunk = vec[i];

    i++;
    result = chunk * factor;
    chunk = vec[i];

    for (i++; i < vec_size;) {
        vec[i - 2] = result;
        result = chunk * factor;
        chunk = vec[i];
        i++;
    }

    vec[i - 2] = result;
    result = chunk * factor;
    i++;

    vec[i - 2] = result;
}

void sscal_scopy(float factor, float *in, float *out, int vec_size)
{
    int i;
    float chunk;
    float result;

    i = 0;
    chunk = in[i];

    i++;
    result = chunk * factor;
    chunk = in[i];

    for (i++; i < vec_size;) {
        out[i - 2] = result;
        result = chunk * factor;
        chunk = in[i];
        i++;
    }

    out[i - 2] = result;
    result = chunk * factor;
    i++;

    out[i - 2] = result;
}