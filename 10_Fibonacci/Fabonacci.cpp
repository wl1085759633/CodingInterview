#include<cstdio>
#include<cassert>
long long fibonacci1(unsigned int n){
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    
    return fibonacci1(n-1) + fibonacci1(n-2);
}

long long fibonacci2(unsigned int n){
    int result[2] = {0, 1};
    if(n < 2){
        return  result[n];
    }

    int fab_minus_one = result[1];
    int fab_minus_two = result[0];
    int fab_n = fab_minus_one + fab_minus_two;
    for(int i = 2; i <= n; i++){
        fab_n = fab_minus_one + fab_minus_two;
        fab_minus_two = fab_minus_one;
        fab_minus_one = fab_n;
    }

    return fab_n;
}
struct Matrix2By2{
    Matrix2By2(
        long long m00 = 0,
        long long m01 = 0,
        long long m10 = 0,
        long long m11 = 0
    ):m_00(m00), m_01(m01), m_10(m10), m_11(m11){}

    long long m_00, m_01, m_10, m_11;
};

Matrix2By2 MatrixMultiply(const Matrix2By2& matrix1, const Matrix2By2& matrix2){
    return Matrix2By2(
    matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
    matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
    matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
    matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11
    );
}

Matrix2By2 MatrixPower(unsigned int n){
    assert(n > 0);

    Matrix2By2 matrix;
    if(n == 1)
    {
        matrix = Matrix2By2(1, 1, 1, 0);
    }
    else if(n % 2 == 0){
        matrix = MatrixPower(n / 2);
        matrix = MatrixMultiply(matrix, matrix);
    }
    else if(n % 2 == 1){
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
    }

    return matrix;
}

long long fibonacci3(unsigned n){
    
    int result[2] = {0, 1};
    if(n < 2)
        return result[n];
    
    Matrix2By2 PowerNminus2 = MatrixPower(n - 1);
    return PowerNminus2.m_00;
}

int main(int args, char** argv){
    printf("%lld\n", fibonacci3(100));
    getchar();
    return 0;
}