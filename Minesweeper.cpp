#include <cstdio>
#include <cstdlib>
#include <ctime>

const int BOARD_SIZE = 5;
const int NUM_MINES = 5;


char board[BOARD_SIZE][BOARD_SIZE];


void placeMines() {
    srand(time(NULL));
    for (int i = 0; i < NUM_MINES; ++i) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        if (board[row][col] == 'X') {
            
            --i;
        } else {
            board[row][col] = 'X';
        }
    }
}

void displayBoard() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int countAdjacentMines(int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE) {
                if (board[newRow][newCol] == 'X') {
                    ++count;
                }
            }
        }
    }
    return count;
}


void playGame() {
    int row, col;
    int remainingCells = BOARD_SIZE * BOARD_SIZE - NUM_MINES;
    
    while (remainingCells > 0) {
        displayBoard();
        printf("Satir ve sutun secin (ornegin, '1 2'): ");
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            printf("Gecersiz giris. Lutfen tekrar deneyin.\n");
            continue;
        }

        if (board[row][col] == 'X') {
            printf("Mayina bastiniz! Oyunu kaybettiniz.\n");
            return;
        } else {
            int minesAround = countAdjacentMines(row, col);
            board[row][col] = '0' + minesAround; 
            --remainingCells;
        }
    }

    printf("Tebrikler! Mayin tarlasini temizlediniz ve oyunu kazandiniz.\n");
}

int main() {
   
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = ' ';
        }
    }

    placeMines();
    playGame();

    return 0;
}
