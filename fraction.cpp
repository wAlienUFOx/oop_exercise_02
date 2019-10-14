#include "fraction.h"
#include <cstring>
#include <sstream>
#include <algorithm>

fractions::fractions(): arr{0, 0} {}
fractions::fractions(int a, int b): arr{a, b} {}

fractions& fractions::operator+= (const fractions& dr){
  fractions tmp;
  tmp.arr[0] = (arr[0] * dr.arr[1]) + (arr[1] * dr.arr[0]);
  tmp.arr[1] = arr[1] * dr.arr[1];
  tmp._reduce();
  arr[0] = tmp.arr[0];
  arr[1] = tmp.arr[1];
  return *this;
}
fractions& fractions::operator-= (const fractions& dr){
  fractions tmp;
  tmp.arr[0] = (arr[0] * dr.arr[1]) - (arr[1] * dr.arr[0]);
  tmp.arr[1] = arr[1] * dr.arr[1];
  tmp._reduce();
  arr[0] = tmp.arr[0];
  arr[1] = tmp.arr[1];
  return *this;
}
fractions& fractions::operator*= (const fractions& dr){
  fractions tmp;
  tmp.arr[0] = arr[0] * dr.arr[0];
  tmp.arr[1] = arr[1] * dr.arr[1];
  tmp._reduce();
  arr[0] = tmp.arr[0];
  arr[1] = tmp.arr[1];
  return *this;
}
fractions& fractions::operator/= (const fractions& dr){
  fractions tmp;
  tmp.arr[0] = arr[0] * dr.arr[1];
  tmp.arr[1] = arr[1] * dr.arr[0];
  tmp._reduce();
  arr[0] = tmp.arr[0];
  arr[1] = tmp.arr[1];
  return *this;
}

fractions fractions::operator+ (const fractions& dr) const{
  fractions result = *this;
  result += dr;
  return result;  
}
fractions fractions::operator- (const fractions& dr) const{
  fractions result = *this;
  result -= dr;
  return result;
}
fractions fractions::operator* (const fractions& dr) const{
  fractions result = *this;
  result *= dr;
  return result;
}
fractions fractions::operator/ (const fractions& dr) const{
  fractions result = *this;
  result /= dr;
  return result;
}
fractions fractions::_reduce() {
  int g = std::__gcd(arr[0], arr[1]);
  arr[0] /= g;
  arr[1] /= g; 
  return *this;
}
bool fractions::operator> (const fractions& dr) const{
  return ((arr[0] * dr.arr[1]) > (dr.arr[0] * arr[1]));
}
bool fractions::operator< (const fractions& dr) const{
  return ((arr[0] * dr.arr[1]) < (dr.arr[0] * arr[1]));
}
bool fractions::operator== (const fractions& dr) const{
  return ((arr[0] * dr.arr[1]) == (dr.arr[0] * arr[1]));
}

fractions operator ""_d(const char* str, size_t size){   //[5:9]
  std::istringstream is(str);
    char tmp;
    int c, z;
    is >> tmp >> c >> tmp >> z;
    return {c, z};
}


std::istream& operator>> (std::istream& in, fractions& dr){
  in >> dr.arr[0] >> dr.arr [1];
  return in;
}
std::ostream& operator<< (std::ostream& out, const fractions& dr){
  out << dr.arr[0] << '/' << dr.arr[1];
  return out;
}
