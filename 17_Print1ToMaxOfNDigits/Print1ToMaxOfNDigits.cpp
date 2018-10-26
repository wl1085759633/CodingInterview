#include<cstdio>
#include<exception>
#include<cstring>
#include<iostream>

using namespace std;

bool Increase(char* number){
    int length = strlen(number);
    bool overflow = false;
    int c = 0;
    for(int i = length - 1; i >= 0; i--){
        int tmp = c + number[i] - '0';
        if(i == length - 1)
            tmp++;
        if(tmp > 9){
            if(i == 0)
                overflow = true;
            else{
                tmp = 0;
                c = 1;
                number[i] = '0' + tmp;
            }
        }
        else{
            number[i] = '0' + tmp;
            break;
        }
    }
    return overflow;
}

void PrintNumber(char* number){
    bool isbegin0 = true;
    int length = strlen(number);

    for(int i = 0; i < length; ++i){
        if(isbegin0 && number[i] != '0')
            isbegin0 = false;
        if(!isbegin0){
            printf("%c", number[i]);
        }
    }
    printf("\t");
}

void print_1_to_max_of_ndigits_solution1(int n){
    if(n <= 0)
        printf("invalid input!\n");
    char* number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';
    while(!Increase(number)){
        PrintNumber(number);
    }
    delete[] number;
}

void print_recursively(char* number, int length, int index){
    if(index == length - 1){
        PrintNumber(number);
        return;
    }

    for(int i = 0; i < 10; i++){
        number[index + 1] = i + '0';
        print_recursively(number, length, index+1);
    }
}

void print_1_to_max_of_ndigits_solution2(int n){
    if(n <= 0){
        logic_error ex("Invalid input!\n");
        throw std::exception(ex);
    }

    char* number = new char[n+1];
    number[n] = '\0';

    for(int i = 0; i < 10; i++){
        number[0] = i + '0';
        print_recursively(number, n, 0);
    }

    delete[] number;
}
void test(int n){
    printf("%d start!\n", n);
    //print_1_to_max_of_ndigits_solution1(n);
    print_1_to_max_of_ndigits_solution2(n);
    printf("end!\n");
}

int main(int argc, char** argv)
{
   // test(1);
   // test(2);
    //test(3);
    test(0);
    test(-1);
    getchar();
    return 0;
}