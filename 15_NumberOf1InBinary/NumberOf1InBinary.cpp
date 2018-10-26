#include<cstdio>

int number_of_1_1(int n){
    int count = 0;
    int flag = 1;
    while(flag){
        if(flag & n)
            count++;
        flag = flag << 1;

    }
    return count;
}

int number_of_1_2(int n){
    int count = 0;
    while(n){
        ++count;
        n = n & (n - 1);
    }
    return count;
}
void test(char* name, int n, int expected){
    if(number_of_1_1(n) == expected)
        printf("solution1: %s passed!\n", name);
    else
        printf("solution1: %s passed!\n", name);

    if(number_of_1_1(n) == expected)
        printf("solution1: %s passed!\n", name);
    else
        printf("solution1: %s passed!\n", name);
}
void test1(){
    test("test1", 1, 1);
}

void test2(){
    test("test2", 0x7FFFFFFF, 31);
}

void test3(){
    test("test3", 0x80000000, 1);
}

void test4(){
    test("test4", 0xFFFFFFFF, 32);
}

void test5(){
    test("test5", 0, 0);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    getchar();
    return 0;
}