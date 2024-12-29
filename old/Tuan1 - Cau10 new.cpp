#include <stdio.h>
//Chu_Van_Hieu_20194046
//cap phat bo nho
void allocate_mem(int ***A, int n){
    *A= new int *[n];
    for(int i=0; i<n; i++){
        *(*A+i)= new int [n];
    }
}
//khoi tao bo nho
void NhapMaTran(int **A, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", *(A+i)+j);
        }
    }
}
//in ra man hinh
void XuatMaTran(int **A, int n){
	for(int i = 0; i<n ; i++){
      for(int j = 0; j<n ; j++){
         printf("%d ",*(*(A+i)+j));
		} printf("\n");
	}
}
//xoa bo nho da cap phat
void free_mem(int **A, int n){
    for(int i=0; i<n; i++){
       delete[] *(A+i);
    }
    delete[] A;
}
//tinh tong
void Tong(int **A, int **B, int **C, int n){
   for(int i = 0; i<n ; i++)
   for(int j = 0; j<n ; j++)
      *(*(C+i)+j) = *(*(A+i)+j)+*(*(B+i)+j);
}
//tinh tich
void Tich(int **A, int **B, int **C, int n){
   for(int i = 0; i<n ; i++)
   for(int k = 0; k<n ; k++){
      *(*(C+i)+k) = 0;
      for(int j = 0; j<n ; j++)
         *(*(C+i)+k) = *(*(C+i)+k) + *(*(A+i)+j) * *(*(B+j)+k);
   }
}
int main(){
   int **A,**B,**C, n;
   scanf("%d",&n);
   allocate_mem(&A, n);
   allocate_mem(&B, n);
   allocate_mem(&C, n);
   NhapMaTran(A,n);
   NhapMaTran(B,n);
   Tong(A,B,C,n);
   XuatMaTran(C,n);
   Tich(A,B,C,n);
   XuatMaTran(C,n);
   free_mem(A, n);
   free_mem(B, n);
   free_mem(C, n);
   return 0;
}






