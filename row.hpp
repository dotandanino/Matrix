//dotandanino@gmail.com
#ifndef ROW_HPP
#define ROW_HPP
#include <iostream>
namespace matrix{
    class row{
        double* items;
        int size;
        public:
            row(int n,double* arr);
            double& operator[](int index);
    };
}
#endif