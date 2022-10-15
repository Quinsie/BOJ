#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y)
{
    int temp;
    if (y > x){
        temp = x;
        x = y;
        y = temp;
    }
    while (y != 0){
        temp = x;
        x = y;
        y = temp % y;
    }
    return x;
}

void aliquot_arr(int num, int* arr, int len)
{
    int pos = 0;
    for (int i = 1; i * i <= num; i++){
        if (i * i == num){
            arr[pos] = i;
            break;
        }
        if (num % i == 0){
            arr[pos] = i;
            arr[len - pos - 1] = num / i;
            pos++;
        }
    }
}

int ali_count(int num)
{
    int count = 0;
    for (int i = 1; i * i <= num; i++){
        if (i * i == num){
            count += 1;
            break;
        }
        if (num % i == 0) count += 2;
    }
    return count;
}

int main()
{
    int num, temp, gcd_num, count;
    scanf("%d %d", &num, &gcd_num);
    for (int i = 1; i < num; i++){
        scanf("%d", &temp);
        gcd_num = gcd(gcd_num, temp);
    }
    count = ali_count(gcd_num);
    int* arr = (int*)malloc(count * sizeof(int));
    aliquot_arr(gcd_num, arr, count);
    for (int i = 0; i < count; i++) printf("%d\n", arr[i]);
    return 0;
}