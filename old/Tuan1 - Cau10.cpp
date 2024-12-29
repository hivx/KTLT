#include <stdio.h>
#define max 100
void NhapMaTran(int ***A, int n){
	int i,j;
    *A= (int*) malloc(i * sizeof(int));
    for(int k=0; k<i; k++){
        *(*A+i)=new int [j];
    }
}
void XuatMaTran(int **A, int n){
	int i,j;
	for(i = 0; i<n ; i++){
      for(j = 0; j<n ; j++){
         printf("%d ",*(A+i)+j);
		} printf("\n");
	}
}
void Tong(int **A, int **B, int **C, int n){
   int i,j;
   for(i = 0; i<n ; i++)
   for(j = 0; j<n ; j++)
      *(*(C+i)+j) = *(*(A+i)+j)+*(*(B+i)+j);
}
void Tich(int **A, int **B, int **C, int n){
   int i,j,k;
   for(i = 0; i<n ; i++)
   for(k = 0; k<n ; k++){
      C[i][k] = 0;
      for(j = 0; j<n ; j++)
         *(*(C+i)+k) = *(*(C+i)+k) + *(*(A+i)+j) * *(*(B+i)+k);
   }
}
int main(){
   int **A,**B, **C, n;
   scanf("%d",&n);
   NhapMaTran(A,n);
   NhapMaTran(B,n);
   Tong(A,B,C,n);
   XuatMaTran(C,n);
   Tich(A,B,C,n);
   XuatMaTran(C,n);
}


