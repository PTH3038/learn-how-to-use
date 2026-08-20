#include <stdio.h>
int sudoku(int a[9][9], short int pssblt[9][9]) {
	int X = 0;
	//
	//
	//
	// Tim so chi co 1 bit duoc bat
	for (int i = 0; i < 9; i ++) {
		for (int j = 0; j < 9; j ++) {
			int bit_one_counter = 0;
			int vitri = 0;
			short int conchay = pssblt[i][j];
			while (conchay != 0) {
				if (conchay & 1) {
					bit_one_counter ++;
				}
				if (bit_one_counter > 1) {
					break;
				}
				conchay = conchay >> 1;
				vitri ++;
			}
			if (bit_one_counter > 1) {
				continue;
			}
			//
			//
			//
			// Neu so do chua dc dien, dien vao va ghi nhan thay doi (X = 1)
			if (a[i][j] != vitri) {
				a[i][j] = vitri;
				X = 1;	
			}
			//
			//
			//
			// Thay doi bit cua cac o trong tren cung hang, cot va o 3x3
			for (int cot = 0; cot < 9; cot ++) {
				if(a[i][cot] == 0) {
					pssblt[i][cot] = pssblt[i][cot] & (511 ^ (1 << (vitri-1)));
				}
			}
			for (int hang = 0; hang < 9; hang ++) {
				if(a[hang][j] == 0) {
					pssblt[hang][j] = pssblt[hang][j] & (511 ^ (1 << (vitri-1)));
				}
			}
			for (int hang = (i/3)*3; hang < (i/3)*3 + 3; hang ++) {
				for (int cot = (j/3)*3; cot < (j/3)*3 + 3; cot ++) {
					if (a[hang][cot] == 0) {
						pssblt[hang][cot] = pssblt[hang][cot] & (511 ^ (1 << (vitri-1)));
					}
				}
			}
			//
			//
			//
		}
	}
	return X;
}
//
//
//
// Ham kiem tra de bai co sai k
int sudoku_checker(int a[9][9]) {
	int row_checker[9] = {0};
	int col_checker[9] = {0};
	int box_checker[9] = {0};
	for (int i = 0; i < 9; i ++) {
		for (int j = 0; j < 9; j ++) {
			int val = a[i][j];
			if (val != 0) {
				if (row_checker[i] & (1 << (val-1)) || col_checker[j] & (1 << (val-1)) || box_checker[(i/3)*3 + j/3] & (1 << (val-1))) {
					return 0;
				}
				row_checker[i] = row_checker[i] | (1 << (val-1));
				col_checker[j] = col_checker[j] | (1 << (val-1));
				box_checker[(i/3)*3 + j/3] = box_checker[(i/3)*3 + j/3] | (1 << (val-1));
			}
		}
	}
	return 1;
}
//
//
//
// Ham in sudoku nhin cho dep
void printf_sudoku(int a[9][9]) {
	for (int i = 0; i < 9; i ++) {
		for (int j = 0; j < 9; j ++) {
			if ((j+1) % 3 == 0 && j != 8) {
				printf("%2d |", a[i][j]);
			}
			else {
				printf("%2d", a[i][j]);
			}
			if ((i == 2 && j == 8) || (i == 5 && j == 8) ) {
				printf("\n");
				for (int k = 0; k < 11; k ++) {
					if (k == 3 || k == 7) {
						printf("-+");
					}
					else if (k == 8) {
						printf("---");
					}
					else {
						printf("--");
					}
				}
			}	
		}
		printf("\n");
	}	
}
//
//
//
//
int main() {
	short int pssblt[9][9];
	int a[9][9];
	for (int i = 0; i < 9; i ++) {
		for (int j = 0; j < 9; j ++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] < 0 || a[i][j] >= 10) {
				printf("Chuong trinh k nhan gia tri am hoac lon hon 9");
				return 0;
			}
			if (a[i][j] != 0) {
				pssblt[i][j] = 1 << (a[i][j]-1);
			}
			else {
				pssblt[i][j] = 511;
			}
		}
	}
	//
	//
	//
	// In sudoku luc chua giai
	printf_sudoku(a);
	//
	//
	//
	// Check xem de bai co sai k
	if (sudoku_checker(a) == 0) {
		printf(" De bai sai");
		return 0;
	}
	//
	//
	//
	// Lap ham bien doi hang cho den khi khong co phan tu nao dc dien them vao o trong nua
	int changed = sudoku (a, pssblt);
	do {
		changed = sudoku(a, pssblt);
	} while (changed == 1);
	//
	//
	//
	// Dem so so 0, vi khong con phan tu nao dc dien them => neu zero_counter != 0 thi de bai co chua tham so
	int zero_counter = 0;
	for (int i = 0; i < 9; i ++) {
			for (int j = 0; j < 9; j ++) {
				if (a[i][j] == 0) {
					zero_counter ++;
				}
			}
		if (zero_counter != 0) {
			printf(" De sai hoac khong giai duoc bang phuong phap nay");
			return 0;
		}
	}
	//
	//
	//
	// In sudoku da giai
	printf("\n Solving . . .\n \n");
	printf_sudoku(a);
	//
	//
	//
	return 0;
}