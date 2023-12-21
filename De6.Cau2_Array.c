#include <stdio.h>

// ham nhap mang
void nhapMang(int arr[], int n) {
	int i;
    printf("Nhap mang:\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

// ham xuat mang
void xuatMang(int arr[], int n) {
	int i;
    printf("Mang sau khi xoa phan tu:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ham de xoa phan tu co chi so K
void xoaPhanTu(int arr[], int *n, int k) {
    if (k < 0 || k >= *n) {
        printf("Chi so K khong hop le.\n");
        return;
    }

    // Di chuyen cac phan tu tu k+1 den n-1 , de len vi tri K
    int i;
    for (i = k; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // giam kich thuoc cua mang di 1
    (*n)--;
}

int main() {
    int n, k;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int A[n];
    nhapMang(A, n);

    printf("Nhap chi so k can xoa: ");
    scanf("%d", &k);

    // xoa phan tu
    xoaPhanTu(A, &n, k);

    // xuat mang
    xuatMang(A, n);

    return 0;
}
