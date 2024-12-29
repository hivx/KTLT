#include <stdio.h>
#include <conio.h>
#include <string.h>
int i,j,n = 0;
char ds[100][30];
char *ptr[100], *tmp;
void NhapSV(){
	while (n < 100){
		printf("Nhap vao ten hoc sinh %d: ",n+1);
		gets(ds[n]);
		if( strlen( ds[n]) == 0) break;
		ptr[n] = ds + n;
		++n;
	}
}
void SX(){
	for ( i=0; i<n-1 ;i++)
	for ( j=i+1; j<n ;j++)
	if (strcmp( ptr[i], ptr[j]) > 0){
		tmp = ptr[i]; ptr[i] = ptr[j]; ptr[j] = tmp;
	}
}
void inSV(){
	printf("danh sach sinh vien\n");
	for ( i=0; i<n ;i++)
	printf("Sinh vien thu %d : %s\n", i+1, ptr[i]);
}
int main(){
    int key;
		printf("---------------MENU lua chon---------------\n");
		printf("Lua chon 1: Them Sinh Vien\n");
		printf("Lua chon 2: Sap xep danh sach\n");
		printf("Lua chon 3: In danh sach\n");
		printf("-----------------------------------------\n");
		printf("Lua chon cua ban la: ");
		scanf("%d\n",&key);
		switch (key){
			case 1:
				printf("1.Them SV.\n");
				NhapSV();
				break;
			case 2:
				printf("2.Danh sach da duoc sap xep .\n");
				SX();
				break;
			case 3:
				printf("3.In danh sach.\n");
				inSV();
				break;
			default:
				printf("hay chon lai.\n");
				break;
		}
	}



