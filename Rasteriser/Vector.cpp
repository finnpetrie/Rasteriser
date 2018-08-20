//
//  Vector.cpp
//  Rasteriser
//
//  Created by Finn Petrie on 7/08/18.
//  Copyright © 2018 Finn Petrie. All rights reserved.
//

#include <stdio.h>
#include "Vector.hpp"
#include <assert.h>


Vector::Vector(size_t n, double x, double y, double z) : Matrix(1, n, x, y, z){
}

Vector::Vector(size_t n, double x, double y, double z, double w) : Matrix(1, n, x, y, z, w){

}

Vector::Vector(double x, double y, double z) : Matrix(1, 3, x, y, z){

}
Vector::Vector() : Matrix(1,3, 0,0,0){
    
}

Vector::Vector(size_t n) : Matrix(1, 3){
    
}
//functional
double Vector::dot(const Vector& v){
    assert(mat.size() == v.mat.size());
    double sum = 0;
    for(unsigned int t = 0; t < mat.size(); ++t){
        sum += mat[t] * v.mat[t];
    }
    return sum;
}
/** not functional - possibly something to do with const correctness*/
double Vector::magnitude(){
    double mag = 0;
    for(int i =0 ; i < rows*columns; ++i){
        mag += mat[i]*mat[i];
    }
    return sqrt(mag);
    
}

const Vector Vector::cross(const Vector& v){
    assert(mat.size() == v.mat.size());
    const Vector product(v.columns, (mat[1]*v.mat[2] - mat[2]*v.mat[1]), (mat[2]*v.mat[0] - mat[0]*v.mat[2]), (mat[0]*v.mat[1] - mat[1]*v.mat[0]));
    return product;
}

Vector operator-(const Vector &lhs){
    Vector result(lhs.rows*lhs.columns);
    for(int i = 0; i < lhs.rows*lhs.columns; ++i){
        result.mat[i] = -lhs.mat[i];
    }
    return result;
}
void Vector::print(){
    Matrix::print();
}

double Vector::getElement(int i, int j){
    return Matrix::getElement(i, j);
}

Vector operator/(const Vector &lhs, double scalar){
    Vector result(lhs.rows*lhs.columns);
    for(int i =0 ; i < lhs.rows*lhs.columns; ++i){
        result.mat[i] = lhs.mat[i]/scalar;
    }
    return result;
}

Vector operator*(double scalar, const Vector &rhs){
    Vector result(rhs.rows*rhs.columns);
    for(int i =0 ; i < rhs.rows*rhs.columns; ++i){
        result.mat[i] = rhs.mat[i]*scalar;
    }
    return result;
}
Vector operator*(const Vector &lhs, double scalar){
    return scalar*lhs;
}

Vector operator+(const Vector &lhs, const Vector &rhs){
    assert(rhs.mat.size() == lhs.mat.size());
    Vector result(rhs.rows*rhs.columns);
    for(int i = 0; i < rhs.rows*rhs.columns; ++i){
        result.mat[i] = lhs.mat[i] + rhs.mat[i];
        
    }
    return result;
}

Vector operator-(const Vector &lhs, const Vector &rhs){
    assert(lhs.mat.size() == rhs.mat.size());
    Vector result(rhs.rows*rhs.columns);
    for(int i = 0; i < rhs.rows*rhs.columns; ++i){
        result.mat[i] = lhs.mat[i] - rhs.mat[i];
        
    }
    return result;
}


//Vector Vector::operator*(Vector &n){
//   return Matrix::operator*(n);
//}
