#include <stdbool.h>

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int m = matSize;
    int n = matColSize[0];
    int shift = k % n;

    for (int i = 0; i < m; i++) {
        if (shift == 0) continue;

        for (int j = 0; j < n; j++) {
            int newIndex;

            if (i % 2 == 0) {
                // Even row → left shift
                newIndex = (j + shift) % n;
            } else {
                // Odd row → right shift
                newIndex = (j - shift + n) % n;
            }

            if (mat[i][j] != mat[i][newIndex]) {
                return false;
            }
        }
    }

    return true;
}
