#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX_HEAPS 10
#define MAX_STONES 10

// Draw graph
void drawHeaps(int heaps[], int size) {
    cleardevice(); // clear terminal
    setbkcolor(DARKGRAY); //set backgroup

    for (int i = 0; i < size; i++) {
    	setcolor(RED); // set color for stone
    	
        char heapLabel[2];
        sprintf(heapLabel, "%d", i+1); // output the number of heaps
        outtextxy(50 + i * 55 - 5, getmaxy() - 8, heapLabel); // output stone

		setcolor(YELLOW);
        
        // draw circle based on xy coordinates
        for (int j = 0; j < heaps[i]; j++) {
            int radius = 10;
            int x = 50 + i * 55;
            int y = getmaxy() - (j * 20 + radius * 3);
            circle(x, y, radius);
        }
    }
}

// Generate the number stone of heads
void generateHeaps(int heaps[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        heaps[i] = rand() % MAX_STONES + 1;
    }
}

// Simulates how to players play
void playerTurn(int heaps[], int size) {
    int heapIndex, numStones;
    
    printf("Please pick number of heaps and stone (Ex: 1 3 will pick 3stone from heap 1):");
    scanf("%d %d", &heapIndex, &numStones);

    // because array start from -1, decrease 1
    heapIndex--;

    // Validate
    if (heapIndex >= 0 && heapIndex < size
     && numStones <= heaps[heapIndex] && numStones > 0) {
        heaps[heapIndex] -= numStones;
    } else {
        printf("Invalid number.\n");

        // Re-enter
        playerTurn(heaps, size);
    }
}

// Simulates how to computer play by random
// tong XOR = 0 chung minh ban dang trong trang thai can bang cua tro choi
// nguoi tiep theo choi se pha vo trang thai can bang
void computerTurn(int heaps[], int size) {
    int totalXor = 0;
    
    // tinh tong XOR cua tat ca cac dong soi
    for (int i = 0; i < size; i++) {
        totalXor ^= heaps[i];
    }
    
    
    for (int i = 0; i < size; i++) {
        if ((heaps[i] ^ totalXor) < heaps[i]) { // xac dinh xem may co the lay 1 so stone from head i de tao ra tong XOR moi hay k
            int remove = heaps[i] - (heaps[i] ^ totalXor); // neu tim thay se cap nhat lai so soi moi dong
            heaps[i] -= remove;
            printf("Computer will pick %d stone from heaps %d.\n", remove, i + 1);
            return;
        }
    }
    // neu khong tim duoc nuoc di thang, lay 1 vien da tu heaps k rong
    for (int i = 0; i < size; i++) {
        if (heaps[i] > 0) {
            heaps[i]--;
            printf("Computer will pick 1 stone from heaps %d.\n", i + 1);
            return;
        }
    }
}

// Check gameover
int isGameOver(int heaps[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        if(heaps[i] > 0){
        	return 0; //O: still stones to play
		}
    }
    return 1;
}

int main() {
	int heapCount, mode;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

	printf("==================================WELLCOME==================================\n");
	printf("NIM Information!!!\n");
	printf("1 : Player vs Player\n");
	printf("2 : Computer vs Player\n");
	printf("----------------------------------------------------------------------------\n");
	
	printf("Please choose mode (1 or 2):");
    scanf("%d", &mode);
    
    // Validate
	if(mode <= 0 || mode > 2) {
    printf("Invalid mode. Please enter again: ", MAX_HEAPS);
    scanf("%d", &heapCount);
	}
	
	// 1- So dong soi nhap tu ban phim
    printf("\n");
    printf("Enter the number of heaps for start game:");
    scanf("%d", &heapCount);
    
    // Validate
    if(heapCount <= 0 || heapCount > MAX_HEAPS) {
    printf("Invalid number of heaps. It must be between 1 and %d. Please enter again: ", MAX_HEAPS);
    scanf("%d", &heapCount);
	}
	
	 int heaps[MAX_HEAPS];
    // 2- So vien soi duoc sinh ra ngau nhien
    // Create stone for each heap
    generateHeaps(heaps, heapCount);
    // Draw graph
    drawHeaps(heaps, heapCount);
    
    // 3- Randome player or computer first
    int playerFirst = rand() % 2; // random 0 or 1
    int currentPlayer = playerFirst;
    
    // playerFirst random = 1 -> true, random 0 -> flase
    printf(playerFirst ? "Random play: layer first\n" : "Random play: Computer first\n");
    
    // 4- Check and play
    while (!isGameOver(heaps, heapCount)) {

		drawHeaps(heaps, heapCount);
		
        if (currentPlayer) {
			playerTurn(heaps, heapCount);
			
			// if gameover will show last line
			if(isGameOver(heaps, heapCount)){
				outtextxy(50, 50, "Congras, you win!");
				printf("Congras, you win!");
			}
        }
        else{
			computerTurn(heaps, heapCount);
			
			if(isGameOver(heaps, heapCount)){
				outtextxy(50, 50, "Sorry, you lose!");
				printf("Sorry, you lose!");
			}
        }
        
        // Change turn play
        currentPlayer = !currentPlayer;
    }

    getch();
    closegraph();
    return 0;
}
