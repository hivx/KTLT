#include <iostream>
#include <conio.h>
 int main()
 {
	 int M,N;
	 int *A = NULL,*B = NULL,*C = NULL;
	 clrscr();
	 printf(“\n Nhap so dong cua ma tran: “); scanf(“%d”,&M);
	 printf(“\n Nhap so cot cua ma tran: “); 	 scanf(“%d”,&N);
 	//C?p phát vùng nh? cho ma tr?n A
	 if (!AllocMatrix(&A,M,N))
	 {
		 printf(“\n Khong con du bo nho! “);
		 return 1;
	 }
	//C?p phát vùng nh? cho ma tr?n B
	 if (!AllocMatrix(&B,M,N))
	 {
		 printf(“\n Khong con du bo nho! “);
		 FreeMatrix(A);//Gi?i phóng vùng nh? A
		 return 1;
	 }
	 	 //C?p phát vùng nh? cho ma tr?n C
	 if (!AllocMatrix(&C,M,N))
	 {
		 printf(“\n Khong con du bo nho! “);
		 FreeMatrix(A);//Gi?i phóng vùng nh? A
		 FreeMatrix(B);//Gi?i phóng vùng nh? B
		 return 1;
	 }
	 printf(“\n Nhap ma tran thu 1 “);
	 InputMatrix(A,M,N,'A');
	 printf(“\n Nhap ma tran thu 2 “);
	 InputMatrix(B,M,N,'B');
	 clrscr();
        printf(“\n Ma tran thu 1“);
	 DisplayMatrix(A,M,N);
	 printf(“\n Ma tran thu 2“);
	 DisplayMatrix(B,M,N);
	 AddMatrix(A,B,C,M,N);
	 printf(“\n Tong hai ma tran“);
	 DisplayMatrix(C,M,N);
	 FreeMatrix(A);//Gi?i phóng vùng nh? A
	 FreeMatrix(B);//Gi?i phóng vùng nh? B
	 FreeMatrix(C);//Gi?i phóng vùng nh? C
	 return 0;
 }
//C?ng hai ma tr?n
	 void AddMatrix(int *A,int *B,int*C,int M,int N)
	 {
		 for(int I=0;I<M*N;++I)
		 C[I] = A[I] + B[I];
	 }
	 //C?p phát vùng nh? cho ma tr?n
	 int AllocMatrix(int **A,int M,int N)   // chú ý : **
	 {
		 *A = new int [M*N];
		 if (*A == NULL)
		 return 0;
		 return 1;
	 }
	 //Gi?i phóng vùng nh?
	 void FreeMatrix(int *A)
	 {
		 if (A!=NULL)
		 delete [] A;
	 }
	//Nh?p các giá tr? c?a ma tr?n
	 void InputMatrix(int *A,int M,int N,char Symbol)
	 {
		 for(int I=0;I<M;++I)
		 for(int J=0;J<N;++J)
		{
			 printf(“\n  $c [%d][%d] = “,Symbol,I,J]);
			scanf(“%d”,&A[I*N+J]);
		}
	}
	 //Hi?n th? ma tr?n
	 void DisplayMatrix(int *A,int M,int N)
	 {
		 for(int I=0;I<M;++I)
		 {
		       for(int J=0;J<N;++J)
		       	 printf(“ %7d”,A[I*N+J]);
		 printf(“\n “);
		 }
	 }
