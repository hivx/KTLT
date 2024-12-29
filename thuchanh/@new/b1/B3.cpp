// Bài tập 3
// Viết chương trình yêu cầu nhập giá trị cho 3 biến số nguyên x, y, z kiểu int. 
// Sau đó sử dụng duy nhất một con trỏ để cộng giá trị của mỗi biến thêm 100.

#include <stdio.h>
int main()
{
    int x, y, z;
    int *ptr;
    scanf("%d %d %d", &x, &y, &z);
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);

    /*****************
    # YOUR CODE HERE #
    *****************/
    int tmp = 100;
    ptr = &tmp;
    
    x += *ptr;
    y += *ptr;
    z += *ptr;
    
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    return 0;
} 