//dotandanino@gmail.com
#include "SquareMat.hpp"
using namespace matrix;
int main(){
    SquareMat s1(3,1);
    SquareMat s2(3,2);
    SquareMat s3(3,4);
    std::cout<<"init to"<<std::endl;
    std::cout<<"s1"<<std::endl<<s1;
    std::cout<<"s2"<<std::endl<<s2;
    std::cout<<"s3"<<std::endl<<s3;

    s3=s1+s2;
    std::cout<<"s3=s1+s2"<<std::endl;
    std::cout<<"s1"<<std::endl<<s1;
    std::cout<<"s2"<<std::endl<<s2;
    std::cout<<"s3"<<std::endl<<s3;
    std::cout<<std::endl;

    s3=s2-s1;
    std::cout<<"s3=s2-s1"<<std::endl;
    std::cout<<"s1"<<std::endl<<s1;
    std::cout<<"s2"<<std::endl<<s2;
    std::cout<<"s3"<<std::endl<<s3;
    std::cout<<std::endl;

    s3=-s3;
    std::cout<<"s3= -s3"<<std::endl;
    std::cout<<"s3"<<std::endl<<s3;
    std::cout<<std::endl;

    s3=s1*s2;
    std::cout<<"s3 = s1*s2"<<std::endl;
    std::cout<<"s1"<<std::endl<<s1;
    std::cout<<"s2"<<std::endl<<s2;
    std::cout<<"s3"<<std::endl<<s3;
    std::cout<<std::endl;


    s3=s1*4;
    std::cout<<"s3 = s1*4"<<std::endl;
    std::cout<<"s1"<<std::endl<<s1;
    std::cout<<"s3"<<std::endl<<s3;
    std::cout<<std::endl;

    s3=4*s1;
    std::cout<<"s3 = 4*s1"<<std::endl;
    std::cout<<"s1"<<std::endl<<s1;
    std::cout<<"s3"<<std::endl<<s3;
    std::cout<<std::endl;

    SquareMat s4=s3%s2;
    std::cout<<"s4 = s2%ss4"<<std::endl;
    std::cout<<"s2"<<std::endl<<s2;
    std::cout<<"s3"<<std::endl<<s3;
    std::cout<<"s4"<<std::endl<<s4;
    std::cout<<std::endl;


    s3=s2%3;
    std::cout<<"s3=s2%s3"<<std::endl;
    std::cout<<"s2"<<std::endl<<s2;
    std::cout<<"s3"<<std::endl<<s3;
    std::cout<<std::endl;

    s2=s1/3;
    std::cout<<"s2=s1/3;"<<std::endl;
    std::cout<<"s1"<<std::endl<<s1;
    std::cout<<"s2"<<std::endl<<s2;
    std::cout<<std::endl;

    s3=s2^2;
    std::cout<<"s3 = s2^2"<<std::endl;
    std::cout<<"s2"<<std::endl<<s2;
    std::cout<<"s3"<<std::endl<<s3;
    std::cout<<std::endl;
    
    std::cout<<"s3++"<<std::endl;
    std::cout<<"s3"<<std::endl<<s3<<std::endl<<"s3++"<<s3++<<"s3 now:"<<std::endl<<s3<<std::endl;

    std::cout<<"++s3"<<std::endl<<(++s3)<<std::endl;


    std::cout<<"s3--"<<std::endl;
    std::cout<<"s3"<<std::endl<<s3<<std::endl<<"s3--"<<s3--<<"s3 now:"<<std::endl<<s3<<std::endl;

    std::cout<<"--s3"<<std::endl<<(++s3)<<std::endl;

    std::cout<<"we will change the matrix before the transpose"<<std::endl;
    s3[0][0]=1;s3[0][1]=2;s3[0][2]=3;
    s3[1][0]=4;s3[1][1]=5;s3[1][2]=6;
    s3[2][0]=7;s3[2][1]=8;s3[2][2]=9;
    std::cout<<"s2=~s3"<<std::endl;
    s2=~s3;
    std::cout<<"s3"<<std::endl<<s3;
    std::cout<<"s2"<<std::endl<<s2;
    std::cout<<std::endl;

    std::cout<<"s3[0][1] is: "<<s3[0][1]<<std::endl;

    SquareMat A(4,2.5);
    SquareMat B(2,4);
    SquareMat C(4,1);
    std::cout<<"A"<<std::endl<<A;
    std::cout<<"B"<<std::endl<<B;
    std::cout<<"C"<<std::endl<<C;

    std::cout<<"A==B"<<(A==B)<<std::endl;
    std::cout<<"A==C"<<(A==C)<<std::endl;
    std::cout<<"C==B"<<(C==B)<<std::endl;

    std::cout<<"A!=B"<<(A!=B)<<std::endl;
    std::cout<<"A!=C"<<(A!=C)<<std::endl;
    std::cout<<"C!=B"<<(C!=B)<<std::endl;

    std::cout<<"A<=B"<<(A<=B)<<std::endl;
    std::cout<<"A<=C"<<(A<=C)<<std::endl;
    std::cout<<"C<=B"<<(C<=B)<<std::endl;

    std::cout<<"A>=B"<<(A>=B)<<std::endl;
    std::cout<<"A>=C"<<(A>=C)<<std::endl;
    std::cout<<"C>=B"<<(C>=B)<<std::endl;

    std::cout<<"A<B"<<(A<B)<<std::endl;
    std::cout<<"A<C"<<(A<C)<<std::endl;
    std::cout<<"C<B"<<(C<B)<<std::endl;

    std::cout<<"A>B"<<(A>B)<<std::endl;
    std::cout<<"A>C"<<(A>C)<<std::endl;
    std::cout<<"C>B"<<(C>B)<<std::endl;
    std::cout<<std::endl;
    s1[0][0]=0;
    s2[0][0]=0;
    s3[0][0]=0;
    std::cout<<"the det of the matrix are:"<<std::endl;
    std::cout<<"s1"<<std::endl<<s1<<"det "<<!s1<<std::endl;
    std::cout<<"s2"<<std::endl<<s2<<"det"<<!s2<<std::endl;
    std::cout<<"s3"<<std::endl<<s3<<"det"<<!s3<<std::endl;
}