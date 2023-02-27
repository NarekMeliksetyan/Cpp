int **transpose(const int *const *m, unsigned rows, unsigned cols)
{
    int **tr = new int *[cols];
    tr[0] = new int[rows * cols];
    for (int i = 1; i < cols; ++i)
        tr[i] = tr[i - 1] + rows;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            tr[j][i] = m[i][j];

    return tr;
}