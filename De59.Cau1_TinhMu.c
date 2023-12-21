#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double result;

    // Nhap gia tri tu ban phim
    printf("Nhap gia tri cua n (n <= 2000): ");
    scanf("%d", &n);

    // Kiem tra dieu kien
    if (n < 0 || n > 2000) {
        printf("Gia tri cua n khong hop le. Vui long nhap lai.\n");
        return 1; 
    }	

    // Tính 2^n
    result = pow(2, n);

    // In ket qua
    printf("2^%d = %.0lf\n", n, result);

    return 0;
}
