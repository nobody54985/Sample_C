#include <stdio.h>

// ham xuat mang
void xuatMang(int arr[], int n) {
	int i;
	
    printf("\nMang: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

// sap xep mang
void mergeAndSort(int A[], int *n, int B[], int *m) {
    int i, j, k;

    for (i = 0; i < *n; i++) {
        for (j = 0; j < *m && B[j] < A[i]; j++);

        for (k = *m; k > j; k--) {
            B[k] = B[k - 1];
        }

        B[j] = A[i];
        (*m)++;
    }
}

int main() {
    int i ,n, m;

    printf("Nhap kich thuoc cua mang A: ");
    scanf("%d", &n);

    int A[n];
    printf("Nhap cac phan tu cua mang A:\n");
    for (i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    printf("Nhap kich thuoc cua mang B: ");
    scanf("%d", &m);

    int B[m];
    printf("Nhap cac phan tu cua mang B:\n");
    for (i = 0; i < m; i++) {
        printf("B[%d] = ", i);
        scanf("%d", &B[i]);
    }

    xuatMang(A, n);
    xuatMang(B, m);

	// call ham sort
    mergeAndSort(A, &n, B, &m);

    printf("\nMang B sau khi noi voi A va sap xep tang dan: ");
    xuatMang(B, m);

    return 0;
}
