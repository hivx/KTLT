#include <stdio.h>
#include <conio.h>
#include <string.h>
int i,j, t;
char ds[100][30];
char *ptr[100], *tmp;
void pressAnyKey();
void NhapSV(int n){
	for(i=0; i<n; i++){
		printf("Nhap thong tin cua sinh vien thu %d: ",i+1);
		fflush(stdin); gets(ds[i]);
		ptr[i] = ds + i;
	} printf("Ban da nhap thanh cong!\n");
}
void inSV(int n){
	printf("danh sach sinh vien\n");
	for ( i=0; i<n ;i++)
	printf("Sinh vien thu %d : %s\n", i+1, ptr[i]);
}
void pressAnyKey() {
    printf("Bam phim bat ky de tiep tuc!");
    getch();
    system("cls");
}
int main(){
    int key, n;
        printf(" De2_6__IT3040_20211\n");
        printf(" Chu Van Hieu - 20194046 - 710822\n");
		printf("\nNhap so sinh vien: "); scanf("%d",&n);

    while(1==1) {
        printf(" De2_6__IT3040_20211\n");
        printf(" Chu Van Hieu - 20194046 - 710822\n");
		printf("**   CHUONG TRINH QUAN LY HOC PHI  **\n");
		printf("**1. Nhap cac sinh  vien, va mon hoc   **\n");
		printf("**2. In ds sinh vien va hoc phi cac mon**\n");
		printf("**0. Thoat                        **\n");
		printf("******************************************\n");
		printf("**        Nhap lua chon cua ban         **\n");
		scanf("%d\n",&key);
		switch (key){
			case 1:
				printf("Ban da chon nhap ds sinh vien!\n");
				NhapSV(n);
				pressAnyKey();
				break;
			case 2:
				printf("Ban da chon xuat DS sinh vien, !\n");
				inSV(n);
				pressAnyKey();
				break;
			case 0:
				break; return 0;
			default:
				break;
		}
	}
}


