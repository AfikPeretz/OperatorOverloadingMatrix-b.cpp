/**
 * AUTHORS: <Afik Peretz>
 * 
 * Date: 2022-04-13
 */
#include "Matrix.hpp"
using namespace zich;


Matrix::Matrix (const vector<double> &arr, int row, int column){
    if (row<=0 || column<=0 || arr.size() != row*column ){
        throw invalid_argument("bad input");
    }
    this->row = row;
    this->column = column;
    this->matrix.resize((size_t)row);
    size_t k = 0;
    for (size_t i = 0; i < row; i++){
        for (size_t j = 0; j < column; j++){
            this->matrix[i].push_back(arr[k]);
            k++;
        }
    }
}


Matrix::Matrix (int row, int column){
    if (row<=0 || column<=0){
        throw invalid_argument("bad input");
    }
    this->row = row;
    this->column = column;
    this->matrix.resize((unsigned long)row, vector<double>((unsigned long)column));
}


Matrix::Matrix (const Matrix &a){
    if (a.row<=0 || a.column<=0){
        throw invalid_argument("bad input");
    }
    this->column = a.column;
    this->row = a.row;
    this->matrix.resize((size_t)a.row);
    for (size_t i = 0; i < a.row; i++){
        for (size_t j = 0; j < a.column; j++){
            this->matrix[i].push_back(a.matrix[i][j]);
        }
    }
}




Matrix Matrix::operator+ (const Matrix &a){
    if (a.row != this->row || a.column  != this->column || a.row<= 0 || a.column <= 0){
        throw invalid_argument("It is not possible to add between the matrices according to the laws of mathematics");
    }
    Matrix result{this->row, this->column};
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < this->column; j++){
            result.matrix[i][j] = this->matrix[i][j] + a.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator+ (){
    Matrix result{this->row, this->column};
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < this->column; j++){
                result.matrix[i][j] = +1*this->matrix[i][j];
        }
    }
    return result;
}


Matrix Matrix::operator- (const Matrix &a){
    if (a.row != this->row || a.column  != this->column || a.row<= 0 || a.column <= 0){
        throw invalid_argument("It is not possible to add between the matrices according to the laws of mathematics");
    }
    Matrix result{this->row, this->column};
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < this->column; j++){
            result.matrix[i][j] = this->matrix[i][j] - a.matrix[i][j];
        }
    }
    return result;
}


Matrix Matrix::operator- (){
    Matrix result{this->row, this->column};
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < this->column; j++){
                result.matrix[i][j] = -1*this->matrix[i][j];
        }
    }
    return result;
}


Matrix Matrix::operator* (const Matrix &a){
    if (this->column != a.row || a.row<=0 || a.column <= 0 ){
        throw invalid_argument("It is not possible to multiply between the 2 matrices according to the rules of mathematics");
    }
    Matrix result{this->row, a.column};
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < a.column; j++){
            double sumofcell = 0;
            for (size_t k = 0; k < this->column; k++){
                sumofcell += this->matrix[i][k] * a.matrix[k][j];
            }
            result.matrix[i][j] = sumofcell;
        }
    }
    return result;
}

Matrix &Matrix::operator++ (){
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < this->column; j++){
            this->matrix[i][j] = this->matrix[i][j] + 1;
        }
    }
    return (*this);
}


Matrix Matrix::operator++ (int){
    Matrix result = (*this);
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < this->column; j++){
            this->matrix[i][j] = this->matrix[i][j] + 1;
        }
    }
    return result;
}


Matrix& Matrix::operator-- (){
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < this->column; j++){
            this->matrix[i][j] = this->matrix[i][j] - 1;
        }
    }
    return (*this);
}


Matrix Matrix::operator-- (int){
    Matrix result = (*this);
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < this->column; j++){
            this->matrix[i][j] = this->matrix[i][j] - 1;
        }
    }
    return result;
}


Matrix Matrix::operator+= (const Matrix &a){
    if (a.row != this->row || a.column  != this->column || a.row<= 0 || a.column <= 0){
        throw invalid_argument("It is not possible to add between the matrices according to the laws of mathematics");
    }
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < this->column; j++){
            this->matrix[i][j] = this->matrix[i][j] + a.matrix[i][j];
        }
    }
    return *this;
}



Matrix Matrix::operator-= (const Matrix &a)
{
    if (a.row != this->row || a.column  != this->column || a.row<= 0 || a.column <= 0){
        throw invalid_argument("It is not possible to add between the matrices according to the laws of mathematics");
    }
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < this->column; j++){
            this->matrix[i][j] = this->matrix[i][j] - a.matrix[i][j];
        }
    }
    return *this;
}



Matrix Matrix::operator*= (const Matrix &a){
    if (this->column != a.row || a.row<=0 || a.column <= 0 ){
        throw invalid_argument("It is not possible to multiply between the 2 matrices according to the rules of mathematics");
    }
    Matrix result{this->row, a.column};
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < a.column; j++){
            double sumofcell = 0;
            for (size_t k = 0; k < this->column; k++){
                sumofcell += this->matrix[i][k] * a.matrix[k][j];
            }
            result.matrix[i][j] = sumofcell;
        }
    }

    this->row = result.row;
    this->column = result.column;
    this->matrix = result.matrix;

    return (*this);
}



Matrix Matrix::operator*= (const double b){
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < this->column; j++){
            this->matrix[i][j] = b * this->matrix[i][j];
        }
    }
    return (*this);
}


bool Matrix::operator< (const Matrix &a){
    if (a.row != this->row || a.column  != this->column){
        throw invalid_argument("Error <");
    }
    bool ans = true;
    double currentsum = 0;
    double sumofA = 0;
    for (size_t i = 0; i < a.row; i++){
        for (size_t j = 0; j < a.column; j++){
            currentsum = currentsum + this->matrix[i][j];
        }
    }
    for (size_t i = 0; i < a.row; i++){
        for (size_t j = 0; j < a.column; j++){
            sumofA = sumofA + a.matrix[i][j];
        }
    }
    if (currentsum < sumofA){
        return ans;
    }
    return !ans;
}



bool Matrix::operator<= (const Matrix &a){
    if (a.row != this->row || a.column  != this->column){
        throw invalid_argument("Error <=");
    }
    bool ans = true;
    double currentsum = 0;
    double sumofA = 0;
    for (size_t i = 0; i < this->row; i++){
        for (size_t j = 0; j < this->column; j++){
            currentsum = currentsum + this->matrix[i][j];
        }
    }
    for (size_t i = 0; i < a.row; i++){
        for (size_t j = 0; j < a.column; j++){
            sumofA = sumofA + a.matrix[i][j];
        }
    }
    if (currentsum <= sumofA){
        return ans;
    }
    return !ans;
}



bool Matrix::operator> (const Matrix &a){
    if (a.row != this->row || a.column  != this->column){
        throw invalid_argument("Error >");
    }
    bool ans = true;
    double currentsum = 0;
    double sumofA = 0;
    for (size_t i = 0; i < a.row; i++){
        for (size_t j = 0; j < a.column; j++){
            currentsum = currentsum + this->matrix[i][j];
        }
    }
    for (size_t i = 0; i < a.row; i++){
        for (size_t j = 0; j < a.column; j++){
            sumofA = sumofA + a.matrix[i][j];
        }
    }
    if (currentsum > sumofA){
        return ans;
    }
    return !ans;
}



bool Matrix::operator>= (const Matrix &a){
    if (a.row != this->row || a.column  != this->column){
        throw invalid_argument("Error >=");
    }
    bool ans = true;
    double currentsum = 0;
    double sumofA = 0;
    for (size_t i = 0; i < a.row; i++){
        for (size_t j = 0; j < a.column; j++){
            currentsum = currentsum + this->matrix[i][j];
        }
    }
    for (size_t i = 0; i < a.row; i++){
        for (size_t j = 0; j < a.column; j++){
            sumofA = sumofA + a.matrix[i][j];
        }
    }
    if (currentsum >= sumofA){
        return ans;
    }
    return !ans;
}



bool Matrix::operator!= (const Matrix &a){
    if (a.row != this->row || a.column  != this->column){
        throw invalid_argument("Error !=");
    }
    bool ans = true;
    for (size_t i = 0; i < a.row; i++){
        for (size_t j = 0; j < a.column; j++){
            if (this->matrix[i][j] != a.matrix[i][j]){
                return ans;
            }
        }
    }
    return !ans;
}


bool Matrix::operator== (const Matrix &a){
    if (a.row != this->row || a.column  != this->column){
        throw invalid_argument("Error ==");
    }
    bool ans = true;
    for (size_t i = 0; i < a.row; i++){
        for (size_t j = 0; j < a.column; j++){
            if (this->matrix[i][j] != a.matrix[i][j]){
                return !ans;
            }
        }
    }
    return ans;
}








