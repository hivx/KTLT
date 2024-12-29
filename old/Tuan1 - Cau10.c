#include <stdio.h>
void allocate_mem(int ***A, int n){
    *A= (int*) malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        *(*A+i)= (int*) malloc(n * sizeof(int));
    }
}
void NhapMaTran(int **A, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", *(A+i)+j);
        }
    }
}
void XuatMaTran(int **A, int n){
	for(int i = 0; i<n ; i++){
      for(int j = 0; j<n ; j++){
         printf("%d ",*(*(A+i)+j));
		} printf("\n");
	}
}
void free_mem(int **A, int n){
    for(int i=0; i<n; i++){
        free(*(A+i));
    }
    free(A);
}
void Tong(int **A, int **B, int **C, int n){
   for(int i = 0; i<n ; i++)
   for(int j = 0; j<n ; j++)
      *(*(C+i)+j) = *(*(A+i)+j)+*(*(B+i)+j);
}
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


