#ifndef D_FRACTIONS_H
#define D_FRACTIONS_H

#include <iostream>

struct fractions{
  fractions();
  fractions(int a, int b);

  int get(int i);
  void set(int i);

  fractions& operator+= (const fractions& dr);
  fractions& operator-= (const fractions& dr);
  fractions& operator*= (const fractions& dr);
  fractions& operator/= (const fractions& dr);
  fractions operator+ (const fractions& dr) const;
  fractions operator- (const fractions& dr) const;
  fractions operator* (const fractions& dr) const;
  fractions operator/ (const fractions& dr) const;
  fractions _reduce (fractions& res) const;
  bool operator> (const fractions& dr) const;
  bool operator< (const fractions& dr) const;
  bool operator== (const fractions& dr) const;
  friend std::istream& operator>> (std::istream& in, fractions& dr);
  friend std::ostream& operator<< (std::ostream& out, const fractions& dr);	

public:
  int arr[2];

};

fractions operator ""_d(const char* str, size_t size);


#endif
