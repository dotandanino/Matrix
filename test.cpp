//dotandanino@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "SquareMat.hpp"
using namespace matrix;


TEST_SUITE("SquareMat"){
    TEST_CASE("Constructor"){
        SUBCASE("negative n"){
            CHECK_THROWS_WITH(SquareMat(-1,3),"n must be positive number");
        }
        SUBCASE("init value"){
            CHECK_NOTHROW(SquareMat s(2,2));
            SquareMat s(2,2);
            CHECK(s[0][0]==2);
            CHECK(s[1][0]==2);
            CHECK(s[0][1]==2);
            CHECK(s[1][1]==2);
        }
        SUBCASE("Check Copy Constructor"){
            SquareMat s(2,2);
            SquareMat s2(s);
            s[0][0]=0;
            CHECK(s[0][0]!=s2[0][0]);
            CHECK(s[0][0]==0);
            CHECK(s[1][0]==2);
            CHECK(s[0][1]==2);
            CHECK(s[1][1]==2);

            CHECK(s2[0][0]==2);
            CHECK(s2[1][0]==2);
            CHECK(s2[0][1]==2);
            CHECK(s2[1][1]==2);
        }
    }
    TEST_CASE("="){
        SquareMat s1(3,5);
        SquareMat s2(2,2);
        SquareMat s3(6,4);
        s1=s2;
        s3=s1;
        CHECK(s1[0][0]==2);
        CHECK(s1[0][0]==s2[0][0]);
        CHECK(s3[0][0]==s2[0][0]);

        CHECK(s1[0][1]==2);
        CHECK(s1[0][1]==s2[0][1]);
        CHECK(s3[0][1]==s2[0][1]);

        CHECK(s3[1][0]==2);
        CHECK(s1[1][0]==s2[1][0]);
        CHECK(s3[1][0]==s2[1][0]);

        CHECK(s1[1][1]==2);
        CHECK(s1[1][1]==s2[1][1]);
        CHECK(s3[1][1]==s2[1][1]);
    }
    TEST_CASE("+"){
        SUBCASE("Different size"){
            SquareMat s1(3,5);
            SquareMat s2(2,2);
            CHECK_THROWS_WITH(s1+s2,"matrix sizes have to be the same");
        }
        SUBCASE("work"){
            SquareMat s1(2,5);
            s1[1][0]=1;
            SquareMat s2(2,3);
            s2[0][0]=7;
            SquareMat s3=s1+s2;
            CHECK(s3[0][0]==12);
            CHECK(s3[0][1]==8);
            CHECK(s3[1][0]==4);
            CHECK(s3[1][1]==8);
        }
    }
    TEST_CASE("-"){
        SUBCASE("Different size"){
            SquareMat s1(3,5);
            SquareMat s2(2,2);
            CHECK_THROWS_WITH(s1-s2,"matrix sizes have to be the same");
        }
        SUBCASE("work"){
            SquareMat s1(2,3);
            SquareMat s2(2,5);
            SquareMat s3=s2-s1;
            CHECK(s3[0][0]==2);
            CHECK(s3[0][1]==2);
            CHECK(s3[1][0]==2);
            CHECK(s3[1][1]==2);
        }
    }
    TEST_CASE("*"){
        SUBCASE("Different size"){
            SquareMat s1(1,5);
            SquareMat s2(2,2);
            CHECK_THROWS_WITH(s1*s2,"matrix sizes have to be the same");
        }
        SUBCASE("work"){
            SquareMat s1(2,5);
            s1[1][0]=1;
            SquareMat s2(2,3);
            s2[0][0]=7;
            SquareMat s3=s1*s2;
            CHECK(s3[0][0]==50);
            CHECK(s3[0][1]==30);
            CHECK(s3[1][0]==22);
            CHECK(s3[1][1]==18);
        }
    }
    TEST_CASE("- unari"){
        SquareMat s1(3);
        s1[0][0]=2;
        s1[0][1]=1;
        s1[0][2]=3;
        s1[1][0]=5;
        s1[1][1]=7;
        s1[1][2]=8;
        SquareMat s2=-s1;
        CHECK(s1[0][0]==2);
        CHECK(s1[0][1]==1);
        CHECK(s1[0][2]==3);
        CHECK(s1[1][0]==5);
        CHECK(s1[1][1]==7);
        CHECK(s1[1][2]==8);

    }
    TEST_CASE("mat * scalar"){
        SUBCASE("work"){
            SquareMat s1(3,1);
            SquareMat s2 = s1*3.5;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    CHECK(s2[i][j]==3.5);
                }
            }
        }

    }
    TEST_CASE("scalar * mat"){
        SquareMat s1(3,1);
        SquareMat s2 = 3.5*s1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                CHECK(s2[i][j]==3.5);
            }
        }
    }
    TEST_CASE("% items multipication"){
        SquareMat s1(6,3);
        SquareMat s2(6,5);
        SquareMat s3=s1%s2;
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                CHECK(s3[i][j]==15);
            }
        }

    }
    TEST_CASE("modulu(%)"){
        SUBCASE("INETGERS"){
            SquareMat s1(2,3);
            s1[0][1]=2;
            s1[1][0]=4;
            SquareMat s3=s1%2;
            CHECK(s3[0][0]==1);
            CHECK(s3[0][1]==0);
            CHECK(s3[1][0]==0);
            CHECK(s3[1][1]==1);
        }
        SUBCASE("negative"){
            SquareMat s1(2,3);
            s1[0][1]=-2;
            s1[1][0]=-4;
            SquareMat s3=s1%2;
            CHECK(s3[0][0]==1);
            CHECK(s3[0][1]==0);
            CHECK(s3[1][0]==0);
            CHECK(s3[1][1]==1);
        }
        SUBCASE("INETGERS"){
            SquareMat s1(2,3.3);
            s1[0][1]=2.2;
            s1[1][0]=4.5;
            SquareMat s3=s1%2;
            CHECK(s3[0][0]==doctest::Approx(1.3));
            CHECK(s3[0][1]==doctest::Approx(0.2));
            CHECK(s3[1][0]==doctest::Approx(0.5));
            CHECK(s3[1][1]==doctest::Approx(1.3));
        }
    }
    TEST_CASE("/"){
        SquareMat mat(3);
        mat[0][0] = 6.0;
        mat[0][1] = -3.0;
        mat[0][2] = 9.0;

        mat[1][0] = 0.0;
        mat[1][1] = 4.5;
        mat[1][2] = -1.5;

        mat[2][0] = 2.0;
        mat[2][1] = -8.0;
        mat[2][2] = 10.0;

        SquareMat result = mat / 2.0;

        CHECK(result[0][0] == doctest::Approx(3.0));
        CHECK(result[0][1] == doctest::Approx(-1.5));
        CHECK(result[0][2] == doctest::Approx(4.5));
        CHECK(result[1][0] == doctest::Approx(0.0));
        CHECK(result[1][1] == doctest::Approx(2.25));
        CHECK(result[1][2] == doctest::Approx(-0.75));
        CHECK(result[2][0] == doctest::Approx(1.0));
        CHECK(result[2][1] == doctest::Approx(-4.0));
        CHECK(result[2][2] == doctest::Approx(5.0));
    }
    TEST_CASE("^"){
        SUBCASE("ZERO") {
            SquareMat mat(3);
            mat[0][0] = 2; mat[0][1] = 3; mat[0][2] = 1;
            mat[1][0] = 0; mat[1][1] = 1; mat[1][2] = 4;
            mat[2][0] = 5; mat[2][1] = 2; mat[2][2] = 2;
    
            SquareMat result = mat ^ 0;
            for (int i = 0; i < 3; ++i){
                for (int j = 0; j < 3; ++j){
                    if(i==j){
                        CHECK(result[i][j]==1);
                    }
                    else{
                        CHECK(result[i][j]==0);
                    }
                }
            }
        }
        SUBCASE("POSITIVE POWER") {
            SquareMat mat(2);
            mat[0][0] = 1; mat[0][1] = 2;
            mat[1][0] = 3; mat[1][1] = 4;
            //in this way to look like the matrix
            SquareMat result = mat ^ 2;
            CHECK(result[0][0] == 7);
            CHECK(result[0][1] == 10);
            CHECK(result[1][0] == 15);
            CHECK(result[1][1] == 22);
        }
        SUBCASE("Error"){
            SquareMat mat(2, 1);
            CHECK_THROWS_WITH(mat^-1,"the scalar cant be negative");
        }
    }
    TEST_CASE("n++"){
        SquareMat mat(2, 1);
        SquareMat before = mat++;
        CHECK(before[0][0] == 1);
        CHECK(before[0][1] == 1);
        CHECK(before[1][0] == 1);
        CHECK(before[1][1] == 1);

        CHECK(mat[0][0] == 2);
        CHECK(mat[0][1] == 2);
        CHECK(mat[1][0] == 2);
        CHECK(mat[1][1] == 2);
    }
    TEST_CASE("++n"){
        SquareMat mat(2, 1);
        SquareMat& result = ++mat;
        CHECK(result[0][0] == 2);
        CHECK(result[0][1] == 2);
        CHECK(result[1][0] == 2);
        CHECK(result[1][1] == 2);
        CHECK(&result == &mat);//make sure result is reference to mat
    }
    TEST_CASE("n--"){
        SquareMat mat(2, 3);
        SquareMat before = mat--;
        CHECK(before[0][0] == 3);
        CHECK(before[0][1] == 3);
        CHECK(before[1][0] == 3);
        CHECK(before[1][1] == 3);

        CHECK(mat[0][0] == 2);
        CHECK(mat[0][1] == 2);
        CHECK(mat[1][0] == 2);
        CHECK(mat[1][1] == 2);
    }
    TEST_CASE("--n"){
        SquareMat mat(2, 5);
        SquareMat& result = --mat;
        CHECK(result[0][0] == 4);
        CHECK(result[0][1] == 4);
        CHECK(result[1][0] == 4);
        CHECK(result[1][1] == 4);
        CHECK(&result == &mat);//make sure result is reference to mat
    }
    TEST_CASE("~"){
        SquareMat mat(3);
        mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
        mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;
        mat[2][0] = 7; mat[2][1] = 8; mat[2][2] = 9;
    
        SquareMat transposed = ~mat;
    
        CHECK(transposed[0][0] == 1);
        CHECK(transposed[0][1] == 4);
        CHECK(transposed[0][2] == 7);
        CHECK(transposed[1][0] == 2);
        CHECK(transposed[1][1] == 5);
        CHECK(transposed[1][2] == 8);
        CHECK(transposed[2][0] == 3);
        CHECK(transposed[2][1] == 6);
        CHECK(transposed[2][2] == 9);
    }
    TEST_CASE("[]"){
        SquareMat mat(2);
        mat[0][0] = 5;
        mat[1][1] = 10;

        CHECK(mat[0][0] == 5);
        CHECK(mat[1][1] == 10);

        SUBCASE("NEGATIVE INDEX") {
            CHECK_THROWS_WITH(mat[-1],"The index must be bewteen 0 to rows -1");
        }

        SUBCASE("OUT OF BOUNDS INDEX") {
            CHECK_THROWS_WITH(mat[2],"The index must be bewteen 0 to rows -1");
        }
    }
    TEST_CASE("== and !="){
        SquareMat a(2);
        a[0][0] = 1; a[0][1] = 2;
        a[1][0] = 3; a[1][1] = 4;

        SquareMat b(2);
        b[0][0] = 2; b[0][1] = 2;
        b[1][0] = 2; b[1][1] = 4;

        SquareMat c(2);
        c[0][0] = 0; c[0][1] = 1;
        c[1][0] = 1; c[1][1] = 1;

        CHECK(a == b);
        CHECK_FALSE(a != b);

        CHECK(a != c);
        CHECK_FALSE(a == c);
    }
    TEST_CASE("compare"){
        SquareMat a(2);
        a[0][0] = 1; a[0][1] = 2;
        a[1][0] = 3; a[1][1] = 4;
    
        SquareMat b(2);
        b[0][0] = 1; b[0][1] = 1;
        b[1][0] = 2; b[1][1] = 2;
    
        SquareMat c(2);
        c[0][0] = 5; c[0][1] = 0;
        c[1][0] = 0; c[1][1] = 5;
    
        CHECK(a > b);
        CHECK(b < a);
    
        CHECK(a >= c);
        CHECK(a <= c);
    
        CHECK_FALSE(a < b);
        CHECK_FALSE(b > a);
        CHECK_FALSE(a != c);
    }
    TEST_CASE("!"){
        SUBCASE("1x1 matrix"){
            SquareMat a(1);
            a[0][0] = 7;
            CHECK((!a) == doctest::Approx(7.0));
        }
        SUBCASE("2x2 matrix") {
            SquareMat mat(2);
            mat[0][0] = 1; mat[0][1] = 2;
            mat[1][0] = 3; mat[1][1] = 4;
    
            double det = !mat;
            CHECK(det == doctest::Approx(-2.0));
        }
    
        SUBCASE("3x3 matrix") {
            SquareMat mat(3);
            mat[0][0] = 6; mat[0][1] = 1; mat[0][2] = 1;
            mat[1][0] = 4; mat[1][1] = -2; mat[1][2] = 5;
            mat[2][0] = 2; mat[2][1] = 8; mat[2][2] = 7;
    
            // דטרמיננטה ידועה = -306
            double det = !mat;
            CHECK(det == doctest::Approx(-306.0));
        }
    }
    TEST_CASE("%= matrix"){
        SquareMat a(2);
        a[0][0] = 5; a[0][1] = 6;
        a[1][0] = 7; a[1][1] = 8;

        SquareMat b(2);
        b[0][0] = 2; b[0][1] = 3;
        b[1][0] = 4; b[1][1] = 5;

        a %= b;

        CHECK(a[0][0] == 10);
        CHECK(a[0][1] == 18);
        CHECK(a[1][0] == 28);
        CHECK(a[1][1] == 40);
    }
    TEST_CASE("%= scalar"){
        SquareMat a(2);
        a[0][0] = 5; a[0][1] = 6;
        a[1][0] = 7; a[1][1] = 8;

        a %= 3;

        CHECK(a[0][0] == 2); // 5 % 3
        CHECK(a[0][1] == 0); // 6 % 3
        CHECK(a[1][0] == 1); // 7 % 3
        CHECK(a[1][1] == 2); // 8 % 3
    }
    TEST_CASE("*= matrix"){
        SquareMat a(2);
        a[0][0] = 1; a[0][1] = 2;
        a[1][0] = 3; a[1][1] = 4;
        SquareMat b = a;
        a *= b;
        CHECK(a[0][0] == 7);
        CHECK(a[0][1] == 10);
        CHECK(a[1][0] == 15);
        CHECK(a[1][1] == 22);
    }
    TEST_CASE("*= scalar"){
        SquareMat a(2, 3);
        a *= 2;
        CHECK(a[0][0] == 6);
        CHECK(a[0][1] == 6);
        CHECK(a[1][0] == 6);
        CHECK(a[1][1] == 6);
    }
    TEST_CASE("-= matrix"){
        SquareMat a(2);
        a[0][0] = 5; a[0][1] = 6;
        a[1][0] = 7; a[1][1] = 8;

        SquareMat b(2);
        b[0][0] = 2; b[0][1] = 3;
        b[1][0] = 4; b[1][1] = 5;
        a -= b;

        CHECK(a[0][0] == 3);
        CHECK(a[0][1] == 3);
        CHECK(a[1][0] == 3);
        CHECK(a[1][1] == 3);
    }
    TEST_CASE("/= scalar"){
        SquareMat a(2);
        a[0][0] = 4; a[0][1] = 6;
        a[1][0] = 8; a[1][1] = 10;
        a /= 2;
        CHECK(a[0][0] == 2);
        CHECK(a[0][1] == 3);
        CHECK(a[1][0] == 4);
        CHECK(a[1][1] == 5);
    }
    TEST_CASE("+= matrix"){
        SquareMat a(2);
        a[0][0] = 1; a[0][1] = 2;
        a[1][0] = 3; a[1][1] = 4;

        SquareMat b(2);
        b[0][0] = 2; b[0][1] = 3;
        b[1][0] = 4; b[1][1] = 5;

        a += b;

        CHECK(a[0][0] == 3);
        CHECK(a[0][1] == 5);
        CHECK(a[1][0] == 7);
        CHECK(a[1][1] == 9);
    }
    TEST_CASE("print- <<"){
        SquareMat a(2);
        a[0][0] = 1; a[0][1] = 2;
        a[1][0] = 3; a[1][1] = 4;

        std::ostringstream oss;
        oss << a;

        std::string output = oss.str();
        
        CHECK(output == "1 2 \n3 4 \n");
    }
    
}