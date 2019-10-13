#include "fraction.h"
#include <cstring>
#include <sstream>

fractions::fractions(): arr{0, 0} {}
fractions::fractions(int a, int b): arr{a, b} {}

int fractions::get(int i){
  return arr[i];
}
void fractions::set(int i){
  std::cin >> arr[i];
}

fractions& fractions::operator+= (const fractions& dr){
  fractions tmp;
  tmp.arr[0] = (arr[0] * dr.arr[1]) + (arr[1] * dr.arr[0]);
  tmp.arr[1] = arr[1] * dr.arr[1];
  if(arr[1] == 0){
    tmp.arr[0] = dr.arr[0];
    tmp.arr[1] = dr.arr[1];
  }
  if(dr.arr[1] == 0){
    tmp.arr[0] = arr[0];
    tmp.arr[1] = arr[1];
  }
  arr[0] = tmp.arr[0];
  arr[1] = tmp.arr[1];
  return *this;
}
fractions& fractions::operator-= (const fractions& dr){
  fractions tmp;
  tmp.arr[0] = (arr[0] * dr.arr[1]) - (arr[1] * dr.arr[0]);
  tmp.arr[1] = arr[1] * dr.arr[1];
  if(arr[1] == 0){
    tmp.arr[0] = -dr.arr[0];
    tmp.arr[1] = dr.arr[1];
  }
  if(dr.arr[1] == 0){
    tmp.arr[0] = arr[0];
    tmp.arr[1] = arr[1];
  }
  arr[0] = tmp.arr[0];
  arr[1] = tmp.arr[1];
  return *this;
}
fractions& fractions::operator*= (const fractions& dr){
  for(int i = 0; i < 2; i++)
    {
      this->arr[i] = arr[i] * dr.arr[i];
    }
  return *this;
}
fractions& fractions::operator/= (const fractions& dr){
  fractions tmp;
  tmp.arr[0] = arr[0] * dr.arr[1];
  tmp.arr[1] = arr[1] * dr.arr[0];
  arr[0] = tmp.arr[0];
  arr[1] = tmp.arr[1];
  return *this;
}

fractions fractions::operator+ (const fractions& dr) const{
  fractions result = *this;
  result += dr;
  result._reduce(result);
  return result;  
}
fractions fractions::operator- (const fractions& dr) const{
  fractions result = *this;
  result -= dr;
  result._reduce(result);
  return result;
}
fractions fractions::operator* (const fractions& dr) const{
  fractions result = *this;
  result *= dr;
  result._reduce(result);
  return result;
}
fractions fractions::operator/ (const fractions& dr) const{
  fractions result = *this;
  result /= dr;
  result._reduce(result);
  return result;
}
fractions fractions::_reduce(fractions& res) const{
  fractions result{};
  if(res.arr[1] == 0)
    res.arr[0] = 0;
  if(res.arr[0] == 0)
    res.arr[1] =0;
  if(res.arr[0] >= res.arr[1])
    {
      if(res.arr[1] > 0){
	for(int i = res.arr[1]; i > 1; i--)
	  {
	    if(res.arr[0] % i == 0 && res.arr[1] % i == 0)
	      {
		res.arr[0] = res.arr[0] / i;
		res.arr[1] = res.arr[1] / i;
	      }
	  }
      }
      else{
	for(int i = res.arr[1]; i < -1; i++)
	  {
	    if(res.arr[0] % i == 0 && res.arr[1] % i == 0)
	      {
		res.arr[0] = res.arr[0] / (-i);
		res.arr[1] = res.arr[1] / (-i);
	      }
	  }
      }
    }
  
  if (res.arr[0] < res.arr[1])
    {
      if(res.arr[0] > 0)
	{
	  for(int i = res.arr[0]; i > 1; i--)
	    {
	      if(res.arr[0] % i == 0 && res.arr[1] % i == 0)
		{
		  res.arr[0] = res.arr[0] / i;
		  res.arr[1] = res.arr[1] / i;
		}
	    }
	}
      else{
	for(int i = res.arr[0]; i < -1; i++)
	    {
	      if(res.arr[0] % i == 0 && res.arr[1] % i == 0)
		{
		  res.arr[0] = res.arr[0] / (-i);
		  res.arr[1] = res.arr[1] / (-i);
		}
	    }
      }
    }
  return result; 
}
void fractions::operator== (const fractions& dr) const{
  if(arr[1] * dr.arr[1] != 0){
    if ((arr[0] * dr.arr[1]) < (dr.arr[0] * arr[1])){
      std::cout << "Первая дробь меньше\n";
    }
    else if ((arr[0] * dr.arr[1]) > (dr.arr[0] * arr[1])){
      std::cout << "Первая дробь больше\n";
    }
    else{
      std::cout << "Дроби равны\n";
    }
  }
  else{
    if(arr[1] == dr.arr[1]){
      std::cout << "Дроби равны\n";
    }
    if(arr[1] == 0 && dr.arr[1] != 0){
      if(dr.arr[0] > 0)
	std::cout << "Первая дробь меньше\n";
      else
	std::cout << "Первая дробь больше\n";
    }
    if(arr[1] != 0 && dr.arr[1] == 0){
      if(arr[0] < 0)
	std::cout << "Первая дробь меньше\n";
      else
	std::cout << "Первая дробь больше\n";
    }
  }
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
