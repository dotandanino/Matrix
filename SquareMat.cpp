//dotandanino@gmail.com
#include "SquareMat.hpp"
using namespace matrix;
//constructor
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
//copy constructor
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
//destructor
SquareMat::~SquareMat(){
    for(int i=0;i<this->n;i++){
        delete[] this->mat[i];
    }
    delete[] this->mat;
}
//mat1 + mat2
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
// mat2 = -mat1;
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
// mat1 - mat2;
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
// mat1* mat2;
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
// mat* scalar;
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
// scalar * mat;
SquareMat matrix::operator*(double scalar,SquareMat& mat){
    return mat*scalar;
}
// mat1 % mat2; multiply every two items in the same position.
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
// mat%scalar
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
// mat/scalar;
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
// mat ^ scalar
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
//mat++
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
//++mat
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
//mat--
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
//--mat;
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

//~mat; -transpose 
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
//mat[i]; in use for getting acsses to mat[i][j]
row SquareMat::operator[](int index){
    if(index<0||this->n<=index){
        throw std::invalid_argument("The index must be bewteen 0 to rows -1");
    }
    return row (this->n,this->mat[index]);
}
//mat1==mat2'
// matrix will be equals if the sum of their items are the same;
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
// mat1!=mat2;
bool SquareMat::operator!=(const SquareMat& other){
    return !(*this==other);
}
// mat1<=mat2;
bool SquareMat::operator<=(const SquareMat& other){
    return((*this)<other || (*this)==other);
}
// mat1<mat2;
bool SquareMat::operator<(const SquareMat& other){
    return !((*this)>=other);
}
// mat1>=mat2;
bool SquareMat::operator>=(const SquareMat& other){
    return((*this)>other || (*this)==other);
}
// mat1>mat2;
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
// !mat; - calculate the det of the matrix using recursive call to smaller matrix
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

//mat1%=mat2;
SquareMat SquareMat::operator%=(const SquareMat& other){
    *this = (*this)%other;
    return (*this);
}
//mat1%=scalar;
SquareMat SquareMat::operator%=(int scalar){
    *this=*this%scalar;
    return(*this);
}
//mat1*=mat2;
SquareMat SquareMat::operator*=(const SquareMat& other){
    *this =( (*this)*other);
    return (*this);
}
//mat1*=scalar;
SquareMat SquareMat::operator*=(double scalar){
    *this = (*this)*scalar;
    return (*this);
}
//mat1-=mat2;
SquareMat SquareMat::operator-=(const SquareMat& other){
    *this = (*this) - other;
    return (*this);
}
//mat1/=mat2;
SquareMat SquareMat::operator/=(const double scalar){
    *this = (*this)/scalar;
    return (*this);
}
//mat1+=mat2;
SquareMat SquareMat::operator+=(const SquareMat& other){
    *this = (*this)+other;
    return (*this);
}
//cout<<"matrix is"<<mat;
std::ostream& matrix::operator<< (std::ostream& output, const SquareMat& mat){
    for(int i=0;i<mat.n;i++){
        for(int j=0;j<mat.n;j++){
            output<<mat.mat[i][j]<<" ";
        }
        output<<std::endl;
    }
    return output;
}
//mat.getN();
int SquareMat::getN(){
    return this->n;
}