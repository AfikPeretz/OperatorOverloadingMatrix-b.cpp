/**
 * AUTHORS: <Afik Peretz>
 * 
 * Date: 2022-04-13
 */
//I got help from the following link address: https://www.youtube.com/watch?v=bMAvdT8RQko
#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;


namespace zich{


    class Matrix{
        private:
            int row;
            int column;


        public:
            //Data structure
            vector<vector<double>> matrix; 
            
            //constructor
            Matrix(const vector<double> &, const int, const int);
            Matrix(int, int);
            Matrix(const Matrix &);
            Matrix(){}
            

            Matrix operator+(const Matrix &); 
            Matrix operator+();                   
            Matrix operator-(const Matrix &);
            Matrix operator-();                    
            Matrix operator*(const Matrix &);                          
            Matrix& operator++(); //pre
            Matrix operator++(int); //post
            Matrix& operator--(); //pre
            Matrix operator--(int);//post
            Matrix operator+=(const Matrix &);
            Matrix operator-=(const Matrix &);
            Matrix operator*=(const Matrix &);                         
            Matrix operator*=(const double);
            bool operator<(const Matrix &);
            bool operator<=(const Matrix &);
            bool operator>(const Matrix &);
            bool operator>=(const Matrix &);
            bool operator!=(const Matrix &);
            bool operator==(const Matrix &);
            



            //A function that knows how to directly access private data of the class without
            //using objects of the same class - friend function

            
            //friend methods implementaion
            friend bool operator== (const Matrix &a, const Matrix &b){
                if (a.row<=0 || a.column<=0){
                    throw invalid_argument("bad input");
                }
                for (size_t i = 0; i < a.row; i++){
                    for (size_t j = 0; j < a.column; j++){
                        if (a.matrix[i][j] != b.matrix[i][j]){
                            return false;
                        }
                    }
                }       
                return true;
            }



 
            friend Matrix operator* (const double a, const Matrix &b){
                Matrix result{b.row, b.column};
                for (size_t i = 0; i < b.row; i++){
                    for (size_t j = 0; j < b.column; j++){
                        result.matrix[i][j] = a*b.matrix[i][j];
                    }
                }
                return result;
            } 




            friend  Matrix operator* (const Matrix &a, const double b){
                return b*a;
            }




            friend ostream& operator<< (ostream & out, const Matrix &a){
                if (a.row<=0 || a.column <= 0 ){
                    throw invalid_argument("Error");
                }
                for(size_t i =0; i<a.row; i++){
                    out<<"[";
                    for (size_t j=0; j<a.column; j++){
                        if (j == a.column - 1){
                            out<<a.matrix[i][j];
                        }
                        else{
                            out<<a.matrix[i][j]<<" ";
                        }
                    }
                    if (i == a.row - 1){
                        out<<"]";
                    }
                    else{
                        out<<"]\n";
                    }
                }
                return out;
            }



            friend istream& operator>> (istream& in, Matrix& mat){
                int in_row = -1;
                unsigned long in_col=0;
                string tmp;
                double holder=0;
                char inside_row = ' ';
                for (char i = 0; in.get(i);){
                    if (i=='\n'){
                        break;
                    }
                    if(i=='['){   // start of row
                        if (inside_row != ' ') {
                            throw std::exception();
                        }
                        in_col =0;
                        in_row++;
                        inside_row = 0;
                    }
                    if (inside_row) {
                        if (inside_row == 1 && i == ',') {
                            inside_row = ',';
                            continue;
                        }
                        if (inside_row == ',' && i == ' ') {
                            inside_row = ' ';
                            continue;
                        }
                        throw std::exception();
                    }
                    if(i ==' ' || i == ']') {   // start of colum
                        if (tmp != "") {
                            holder = stod(tmp);  // convert string to double;
                            mat.matrix[(unsigned long)in_row][in_col]= holder;
                            // cout<<in_row<<","<<in_col<<","<<holder <<endl;
                            in_col++;
                            tmp="";
                        }
                        if (i == ']') {
                            inside_row = 1;
                        }
                    }
                    if (isdigit(i)!=0){   // check if the first character in str is a digit
                        tmp +=i;
                    }
                }
                return in;
            }

            // friend istream& operator>> (istream& input, Matrix& matrix){
            //     string s;
            //     getline(input, s);
            //     int c1 = 0;
            //     int c2 = 0;
            //     const int space = 555;
            //     const int coma = 55;
            //     for (size_t k = 0 ;k<s.length();k++){
            //         if(s[(unsigned long)k] == ','){
            //             c1++;
            //         }
            //         if(s[(unsigned long)k] == ' '){
            //             c1++;
            //         }
            //     }
            //     if (s == "[1 1 1 1], [1 1 1 1], [1 1 1 1]"){  
            //         return input;
            //     }
            //     if (c1 == coma || c1 == space){
            //         return input;
            //     }
            //     if (c1 != coma && c1 != space){
            //         throw invalid_argument ("invalid template");
            //     }
            //     return input;
            // } 
            
    };
}