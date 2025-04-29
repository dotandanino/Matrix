//dotandanino@gmail.com
#include "row.hpp"
using namespace matrix;

row::row(int n,double* arr){
    this->size=n;
    this->items=arr;//we want every change on the row to change the real arr
}
double& row::operator[](int index){
    if(index<0||this->size<=index){
        throw std::invalid_argument("The index must be bewteen 0 to cols -1");
    }
    return items[index];
}