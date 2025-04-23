//dotandanino@gmail.com
#include "SquareMat.hpp"
using namespace matrix;
SquareMat::SquareMat(int n,double initVal){
    if(n<=0){
        throw std::invalid_argument("n must be positive number");
    }
    this->n= n;
    this->mat = new double*[n];
    for(int i=0;i<n;i++){
        this->mat[i]=new double[n];
        for(int j=0;j<n;j++){
            this->mat[i][j]=initVal;
        }
    }
}
SquareMat::SquareMat(const SquareMat& other){
    this->n=other.n;
    this->mat = new double*[n];
    for(int i=0;i<n;i++){
        this->mat[i]=new double[n];
        for(int j=0;j<n;j++){
            this->mat[i][j]=other.mat[i][j];
        }
    }
}
SquareMat::~SquareMat(){
    for(int i=0;i<this->n;i++){
        delete[] this->mat[i];
    }
    delete[] this->mat;
}
//mat1 = mat2 + mat3
SquareMat SquareMat::operator+(const SquareMat& other){
    if(this->n!=other.n){
        throw std::invalid_argument("matrix sizes have to be the same");
    }
    SquareMat toReturn(*this);
    for (int i = 0; i < this->n; i++)
    {
        for(int j=0;j< this->n;j++){
            toReturn.mat[i][j]+=other.mat[i][j];
        }
    }
    return toReturn;
}
//SquareMat mat1(4,4);
//SquareMat mat2(3,5);
//mat1 = mat2;

SquareMat& SquareMat::operator=(const SquareMat& other){

    if (this==&other)
        return *this;
    if(this->n == other.n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                this->mat[i][j]=other.mat[i][j];
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            delete[] this->mat[i];
        }
        delete[] this->mat;
        this->n = other.n;
        this->mat = new double*[n];
        for(int i=0;i<n;i++){
            this->mat[i]=new double[n];
            for(int j=0;j<n;j++){
                this->mat[i][j]=other.mat[i][j];
            }
        }
    }
    return *this;
}

SquareMat SquareMat::operator-(){
    SquareMat toReturn(this->n);
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            toReturn.mat[i][j]=-this->mat[i][j];   
        }
    }
    return toReturn;
}

SquareMat SquareMat::operator-(const SquareMat& other){
    if(this->n!=other.n){
        throw std::invalid_argument("matrix sizes have to be the same");
    }
    SquareMat toReturn(*this);
    for (int i = 0; i < this->n; i++)
    {
        for(int j=0;j< this->n;j++){
            toReturn.mat[i][j]-=other.mat[i][j];
        }
    }
    return toReturn;
}

SquareMat SquareMat::operator*(const SquareMat& other){
    if(this->n!=other.n){
        throw std::invalid_argument("matrix sizes have to be the same");
    }
    SquareMat toReturn(this->n);
    for (int i = 0; i < this->n; i++)
    {
        for(int j=0;j<other.n;j++){
            for(int k=0;k<this->n;k++){
                toReturn.mat[i][j]+=((this->mat[i][k])*(other.mat[k][j]));
            }
        }
    }
    return toReturn;
}

SquareMat SquareMat::operator*(double scalar){
    SquareMat toReturn(*this);
    for (int i = 0; i < this->n ; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            toReturn.mat[i][j]*=scalar;
        }
    }
    return toReturn;
}

SquareMat matrix::operator*(double scalar,SquareMat& mat){
    return mat*scalar;
}

SquareMat SquareMat::operator%(const SquareMat& other){
    if(this->n!=other.n){
        throw std::invalid_argument("matrix sizes have to be the same");
    }
    SquareMat toReturn(*this);
    for (int i = 0; i < this->n; i++)
    {
        for(int j=0;j< this->n;j++){
            toReturn.mat[i][j]*=other.mat[i][j];
        }
    }
    return toReturn;
}

SquareMat SquareMat::operator%(int scalar){
    SquareMat toReturn(*this);
    for (int i = 0; i < this->n; i++)
    {
        for(int j=0;j< this->n;j++){
            toReturn.mat[i][j]=fmod(this->mat[i][j],scalar);
        }
    }
    return toReturn;
}

SquareMat SquareMat::operator/(double scalar){
    SquareMat toReturn(*this);
    for (int i = 0; i < this->n; i++)
    {
        for(int j=0;j< this->n;j++){
            toReturn.mat[i][j]/=scalar;
        }
    }
    return toReturn;
}

SquareMat SquareMat::operator^(int scalar){
    if(scalar<0){
        throw std::invalid_argument("the scalar cant be negative");
    }

    SquareMat toReturn(this->n);
    for (int i = 0; i < this->n; i++)
    {
        toReturn.mat[i][i]=1;
        //the other values initialized to 0 at the constructor
    }
    for (int i = 0; i < scalar; i++)
    {
        toReturn*=(*this);
    }
    return toReturn;
    
}

SquareMat SquareMat::operator++(int dummy_flag_for_postfix_increment){//n++
    SquareMat toReturn(*this);
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            this->mat[i][j]++;
        }
    }
    return toReturn;
    
}

SquareMat& SquareMat::operator++(){//++n
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            this->mat[i][j]++;
        }
    }
    return *this;
}

SquareMat SquareMat::operator--(int dummy_flag_for_postfix_increment){//n--
    SquareMat toReturn(*this);
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            this->mat[i][j]--;
        }
    }
    return toReturn;
    
}

SquareMat& SquareMat::operator--(){//--n
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            this->mat[i][j]--;
        }
    }
    return *this;
}

SquareMat SquareMat::operator~(){
    SquareMat transposeMat(this->n,this->n);
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            transposeMat[j][i]=this->mat[i][j];
        }
    }
    return transposeMat;
}

double* SquareMat::operator[](int index){
    if(index<0||this->n<=index){
        throw std::invalid_argument("The index must be bewteen 0 to rows -1");
    }
    return this->mat[index];
}

bool SquareMat::operator==(const SquareMat& other){
    double sum=0;
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            sum+=this->mat[i][j];
        }
    }
    for (int i = 0; i <other.n; i++)
    {
        for (int j = 0; j < other.n; j++)
        {
            sum-=other.mat[i][j];
        }
    }
    return sum==0;
}

bool SquareMat::operator!=(const SquareMat& other){
    return !(*this==other);
}

bool SquareMat::operator<=(const SquareMat& other){
    return((*this)<other || (*this)==other);
}

bool SquareMat::operator<(const SquareMat& other){
    return !((*this)>=other);
}
bool SquareMat::operator>=(const SquareMat& other){
    return((*this)>other || (*this)==other);
}

bool SquareMat::operator>(const SquareMat& other){
    double sum=0;
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            sum+=this->mat[i][j];
        }
    }
    for (int i = 0; i <other.n; i++)
    {
        for (int j = 0; j < other.n; j++)
        {
            sum-=other.mat[i][j];
        }
    }
    return sum>0;
}

double SquareMat::operator!(){
    if(this->n==1){
        return mat[0][0];
    }
    if(this->n==2){
        return(mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0]);
    }
    SquareMat temp(this->n-1,this->n-1);
    double det=0;
    for(int k=0;k<this->n;k++){
        for(int i=1;i<this->n;i++){
            for(int j=0;j<this->n;j++){
                if(k<j){
                    temp[i-1][j-1]=mat[i][j];
                }
                if(k>j){
                    temp[i-1][j]=mat[i][j];
                }
            }
        }
        double tempSum=!temp*mat[0][k];
        if(k%2==0){
            det+=tempSum;
        }
        else{
            det-=tempSum;
        }
    }
    return det;
}

SquareMat SquareMat::operator%=(const SquareMat& other){
    *this = (*this)%other;
    return (*this);
}

SquareMat SquareMat::operator%=(int scalar){
    *this=*this%scalar;
    return(*this);
}

SquareMat SquareMat::operator*=(const SquareMat& other){
    *this =( (*this)*other);
    return (*this);
}

SquareMat SquareMat::operator*=(double scalar){
    *this = (*this)*scalar;
    return (*this);
}

SquareMat SquareMat::operator-=(const SquareMat& other){
    *this = (*this) - other;
    return (*this);
}

SquareMat SquareMat::operator/=(const double scalar){
    *this = (*this)/scalar;
    return (*this);
}

SquareMat SquareMat::operator+=(const SquareMat& other){
    *this = (*this)+other;
    return (*this);
}

std::ostream& matrix::operator<< (std::ostream& output, const SquareMat& mat){
    for(int i=0;i<mat.n;i++){
        for(int j=0;j<mat.n;j++){
            output<<mat.mat[i][j]<<" ";
        }
        output<<std::endl;
    }
    return output;
}

int SquareMat::getN(){
    return this->n;
}