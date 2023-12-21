#include <stdio.h>

int main() {
    int n, m;
    printf("Nhap so hang cua ma tran: ");
    scanf("%d", &n);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &m);

    int a[100][100];
    int h1 = 0, h2 = n - 1, c1 = 0, c2 = m - 1;
    int dem = 1;

    while (h1 <= h2 && c1 <= c2) {
        // Xay dung canh tren: hang h1 tu cot c1 => c2
        int i;
        for (i = c1; i <= c2; i++) {
            a[h1][i] = dem;
            ++dem;
        }
        // Tang h1 de xay dung canh ben phai, cot c2 tu hang h1 toi hang h2
        ++h1;
        for (i = h1; i <= h2; i++) {
            a[i][c2] = dem;
            ++dem;
        }
        // giam c2 de xay dung canh duoi, hang h2 tu c2 => cot c1
        --c2;
        if (h1 <= h2) {
            for (i = c2; i >= c1; i--) {
                a[h2][i] = dem;
                ++dem;
            }
        }
        // giam h2 de xay dung canh ben trai, cot c1 tu hang h2 toi hang c1
        --h2;
        if (c1 <= c2) {
            for (i = h2; i >= h1; i--) {
                a[i][c1] = dem;
                ++dem;
            }
        }
        // Tang c1
        ++c1;
    }

    int i,j;
    printf("Ma tran %dx%d:\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

