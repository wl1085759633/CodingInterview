#include<iostream>
#include<cstdio>
#include<exception>
using namespace std;

int sequence_find(int* array, int start, int end){
    int result = array[start];
    for(int i = start + 1; i <= end; i++){
        if(array[i] < result){
            result = array[i];
            break;
        }
    }
    return result;
}

int MinNumber(int* array, int length){
    if(array == NULL || length <= 0){
        logic_error ex("Invalid Input");
        throw std::exception(ex);
    }

    int index1 = 0;
    int index2 = length-1;
    int mid_index = index1;
    while(array[index1] >= array[index2]){
        if(index2 - index1 == 1){
            mid_index = index2;
            break;
        }

        mid_index = (index1 + index2) / 2;
        if(array[index1] == array[index2] && array[mid_index] == array[index1])
            return sequence_find(array, index1, index2);
        if(array[mid_index] >= array[index1])
            index1 = mid_index;
        else if(array[mid_index] <= array[index2])
            index2 = mid_index;
    }
    return array[mid_index];
}

void test(char* name, int* array, int length, int antipate){
    int result = MinNumber(array, length);
    if(result == antipate)
        printf("%s passed!\n", name);
    else
        printf("%s failed!\n", name);
}

void test1(){
     int array[] = {4, 5, 1, 2, 3};
     test("test1", array, 5, 1);
}

void test2(){
     int array[] = {4, 4, 1, 2, 2};
     test("test2", array, 5, 1);
}

void test3(){
     int array[] = {1, 2, 3};
     test("test3", array, 3, 1);
}

void test4(){
     int array[] = {1};
     test("test4", array, 1, 1);
}

void test5(){
     int array[1];
     test("test5", NULL, 5, 1);
}

void test6(){
     int array[] = {1, 0, 1, 1, 1};
     test("test6", array, 5, 0);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    //test5();
    test6();
    getchar();
    return 0;
}