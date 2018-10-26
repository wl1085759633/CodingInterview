#include<cstdio>

void ReorderArray1(int* pData, unsigned int length){
    if(pData == nullptr || length == 0){
        printf("输入为空\n");
        return;
    }
    int begin = 0;
    int end = length - 1;
    while(begin < end){
        //begin找偶数
        while(begin < end && (pData[begin] & 0x1) != 0)
            begin++;
        //end找奇数
        while(end > begin && (pData[end] & 0x1) == 0)
            end--;
        //交换奇偶数
        if(begin < end){
            int tmp = pData[begin];
            pData[begin] = pData[end];
            pData[end] = tmp;
        }
    }
}

void ReorderArray2(int* pData, unsigned int length, bool (*func)(int)){
    if(pData == nullptr || length == 0){
        printf("输入为空\n");
        return;
    }
    int* pBegin = pData;
    int* pEnd = pData + length - 1;
    while(pBegin < pEnd){
        while(pBegin < pEnd && !func(*pBegin))
            pBegin++;
        while(pBegin < pEnd && func(*pEnd))
            pEnd--;
        if(pBegin < pEnd){
            int tmp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = tmp;
        }
    }
}

bool isEven(int n){
    return (n & 0x1) == 0;
}

void PrintArray(int numbers[], int length)
{
    if(length < 0)
        return;

    for(int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void test(char* name, int* pData, unsigned int length){
    //测试方法1
    printf("测试方法1\n");
    printf("%s start!\n", name);
    ReorderArray1(pData, length);
    PrintArray(pData, length);
    printf("%s end!\n", name);

    //测试方法2
    printf("测试方法2\n");
    printf("%s start!\n", name);
    ReorderArray2(pData, length, isEven);
    PrintArray(pData, length);
    printf("%s end!\n", name);
}

//测试奇数偶数交替出现
void test1(){
    int nums[] = {1, 2, 3, 4, 5, 6};
    test("test1", nums, sizeof(nums) / sizeof(int));
}

//测试所有偶数都出现在奇数前面
void test2(){
    int nums[] = {6, 8, 1, 3, 5};
    test("test2", nums, sizeof(nums) / sizeof(int));
}

//测试所有奇数出现在偶数前面
void test3(){
    int nums[] = {1, 3, 5, 6, 8};
    test("test3", nums, sizeof(nums) / sizeof(int));
}

//测试只包含一个数字的数组
void test4(){
    int nums[] = {1};
    test("test4", nums, sizeof(nums) / sizeof(int));
}

//测试空指针
void test5(){
    test("test5", nullptr, 0);
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    getchar();
    return 0;
}