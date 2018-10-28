#include<cstdio>

void PrintCicle(int** numbers, int columns, int rows, int start){
    //从左往右打印一行
    int endx = columns - start - 1;
    int endy = rows - start - 1;
    for(int i = start; i <= endx; i++){
        printf("%d ", numbers[start][i]);
    }
    //从上往下打印一列
    if(endy > start){
        for(int i = start + 1; i <= endy; i++){
            printf("%d ", numbers[i][endx]);
        }
    }
    //从右往左打印一行
    if((endx > start) && (endy > start)){
        for(int i = endx - 1; i >= start; i--){
            printf("%d ", numbers[endy][i]);
        }
    }
    //从下往上打印一列
    if(((endy - start) > 1) && endx > start){
        for(int i = endy - 1; i > start; i--){
            printf("%d ", numbers[i][start]);
        }
    }

}

void PrintMatrix(int** numbers, int columns, int rows){
    if(numbers == nullptr || columns <= 0 || rows <= 0)
        return;
    int start = 0;
    while(columns > 2 * start && rows > 2 * start){
        //打印一圈
        PrintCicle(numbers, columns, rows, start);
        start++;
    }
}

void test(int columns, int rows){
    printf("test begin:%d columns, %d rows.\n", columns, rows);
    if(columns < 1 || rows < 1)
        return;
    
    int** numbers = new int*[rows];
    for(int i = 0; i < rows; i++){
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j){
            numbers[i][j] = i * columns + j + 1;
        }
    }
    PrintMatrix(numbers, columns, rows);
    printf("\n");

    for(int i = 0; i < rows; i++)
        delete[] (int*)numbers[i];
    delete[] numbers;
}

int main(int argc, char* argv[]){
    test(1, 1);
    test(2, 2);
    test(4, 4);
    test(5, 5);
    test(1, 5);
    test(5, 1);
    getchar();
    return 0;
}