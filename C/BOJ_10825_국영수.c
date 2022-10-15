#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[9];
    int kor, eng, mat;
} student;

int score_compare(int a, int b)
{
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

int compare(const void *a, const void *b) // 1 -> change, -1 -> not change, 0 -> -
{
    student s1 = *(student*)a;
    student s2 = *(student*)b;

    if (s1.kor == s2.kor && s1.eng == s2.eng && s1.mat == s2.mat)
        return strcmp(s1.name, s2.name);
    else if (s1.kor == s2.kor && s1.eng == s2.eng)
        return score_compare(s1.mat, s2.mat) * (-1);
    else if (s1.kor == s2.kor)
        return score_compare(s1.eng, s2.eng);
    return score_compare(s1.kor, s2.kor) * (-1);
}

int main()
{
    int num;
    student* arr;

    scanf("%d", &num);
    arr = (student*)malloc(sizeof(student) * num);
    for (int i = 0; i < num; i++) {
        scanf("%s %d %d %d", &arr[i].name, &arr[i].kor, &arr[i].eng, &arr[i].mat);
    }
    qsort(arr, num, sizeof(student), compare);
    for (int i = 0; i < num; i++) {
        printf("%s\n", arr[i].name);
    }
    free(arr);
    
    return 0;
}