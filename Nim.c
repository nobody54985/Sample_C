#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEAP_SIZE 10

// Tạo số lượng viên sỏi cho mỗi đống sỏi
void generateHeaps(int heaps[], int size) {
    for (int i = 0; i < size; i++) {
        heaps[i] = rand() % MAX_HEAP_SIZE + 1; // Random tu 1 -> MAX_HEAP_SIZE
        // rand(): random so tu nhien, % MAX_HEAP_SIZE: lay phan du
    }
}

// Thông báo trạng thái đống sỏi còn lại.
void printHeaps(int heaps[], int size) {
    printf("Trạng thái các đống sỏi bây giờ:");
    for (int i = 0; i < size; i++) {
        printf("%d ", heaps[i]);
    }
    printf("\n");
}

// Mô phỏng người chơi.
void playerTurn(int heaps[], int size) {
    int heapIndex, numStones;
    printf("Mời bạn chọn thứ tự đống sỏi và số lượng sỏi bốc ra (vd:1 3 lấy 3 viên sỏi từ đống 1): ");
    scanf("%d %d", &heapIndex, &numStones);

    // Vi array bắt đầu từ 0 chứ không phải 1, nên giảm xún 1
    heapIndex--;

    // Kiêm tra số đống sỏi và số lượng sỏi muốn bốc có hợp lệ không
    if (heapIndex >= 0 && heapIndex < size
     && numStones <= heaps[heapIndex] && numStones > 0) {
        heaps[heapIndex] -= numStones;
    } else {
        printf("Cú pháp chưa đúng, Xin hãy nhập lại!!! \n");

        // Người chơi chọn lại
        playerTurn(heaps, size);
    }
}

// Mô phỏng máy chơi bằng random
void computerTurn(int heaps[], int size) {
    int heapIndex = rand() % size; // Random chọn đống sỏi
    
    // Nếu đống sỏi random đã hết, tìm đống sỏi còn viên sỏi
    while (heaps[heapIndex] == 0) {
        heapIndex = (heapIndex + 1) % size;
    }

    int numStones = rand() % heaps[heapIndex] + 1; // Random chọn số lượng viên sỏi
    heaps[heapIndex] -= numStones;
    printf("Máy sẽ bốc %d viên sỏi từ  đống %d. \n", numStones, heapIndex + 1);
}

// Kiem tra còn lại sỏi hay không.
int isGameOver(int heaps[], int size) {
    for (int i = 0; i < size; i++) {
        if (heaps[i] > 0) {
            return 0; // 0: false
        }
    }
    return 1; // 1: true
}

int main() {
    srand(time(NULL));
    int heapCount;

    // 1- Số đống sỏi nhập từ bàn phím
    printf("Nhập số đống sỏi để bắt đầu trò chơi:");
    scanf("%d", &heapCount);
    
    int heaps[heapCount];
    // 2- Số lượng viên sỏi trong mỗi đống được sinh ra ngẫu nhiên
    generateHeaps(heaps, heapCount);

    // 3- Random người hay máy đi trước 
    int playerFirst = rand() % 2; // random 0 or 1
    int currentPlayer = playerFirst;

    // Toán tử 3 ngôi
    // playerFirst random = 1 -> true, random 0 -> flase
    printf(playerFirst ? "Bạn sẽ chơi trước." : "Máy sẽ chơi trước.");
    
    // 4- Kiem tra va choi
    while (!isGameOver(heaps, heapCount)) {
        // Thông báo trạng thái đống sỏi còn lại.
        printHeaps(heaps, heapCount);

        // Play
        if (currentPlayer) {
            playerTurn(heaps, heapCount);
            printf("\n");
        } else {
            computerTurn(heaps, heapCount);
            printf("\n");
        }

        // Đổi lượt chơi
        currentPlayer = !currentPlayer;
    }
    
    // 5- Thong bao ket qua cuoi cung
    printf(currentPlayer ? "Máy wins! \n" : "Bạn wins! \n");
    printf("Bravo!!! Bravo!!!");
    return 0;
}
