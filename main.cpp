#include <iostream>
using namespace std;
#include "Matrix.cpp"
#include "Matrix.hpp"
using namespace zich;

int main(){
    cout << "Welcome to the matrix calculator!" << endl;
    cout << "Supported operations: " << endl
         << "1. mat + mat" << endl
         << "2. mat - mat" << endl
         << "3. mat * mat" << endl
         << "4. scalar * mat" << endl
         << "5. mat--" << endl
         << "6. mat++" << endl
         << "7. mat > mat" << endl
         << "8. mat < mat" << endl
         << "9. mat => mat" << endl
         << "10. mat <= mat" << endl
         << "11. mat != mat" << endl
         << "12. mat == mat" << endl;
    vector<double> v1 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<double> v2 = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    Matrix a(v1, 3, 3);
    Matrix b(v2, 3, 3);
    Matrix c(v1, 3, 3);
    Matrix d(v2, 3, 3);
    Matrix e(v1, 3, 3);
    Matrix f(v2, 3, 3);
    Matrix g(v1, 3, 3);
    Matrix h(v2, 3, 3);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Examples:" << endl;
    cout << "matrix a:" << endl;
    cout << a << endl;
    cout << endl;
    cout << "matrix b:" << endl;
    cout << b << endl;
    cout << endl;
    cout << "a+b:" << endl;
    cout << (a+b) << endl;
    cout << endl;
    cout << "a-b:" << endl;
    cout << (a-b) << endl;
    cout << endl;
    cout << "a*b:" << endl;
    cout << (c*d) << endl;
    cout << endl;
    cout << "2*a:" << endl;
    cout << (2*a) << endl;
    cout << endl;
    cout << "--a:" << endl;
    cout << (--e) << endl;
    cout << endl;
    cout << "++a:" << endl;
    cout << (++g) << endl;
    cout << endl;
    cout << "a > b:" << endl;
    cout << (a > b) << endl;
    cout << endl;
    cout << "a < b:" << endl;
    cout << (a < b) << endl;
    cout << endl;
    cout << "a >= b:" << endl;
    cout << (a >= b) << endl;
    cout << endl;
    cout << "a <= b:" << endl;
    cout << (a <= b) << endl;
    cout << endl;
    cout << "a!=b:" << endl;
    cout << (a!=b) << endl;
    cout << endl;
    cout << "a==b:" << endl;
    cout << (a==b) << endl;
    cout << endl;

    // vector<double> unit_matrix = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    // istream in = "[1 1 1 ],[1 1 1], [1 1 1]\n";
    // Matrix mat1(unit_matrix,3,3);
    // in >> mat1;
    // cout<<mat1<<endl;
}