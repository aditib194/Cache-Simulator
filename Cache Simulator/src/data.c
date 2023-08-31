#include <data.h>
#include <stdio.h>
#include <stdlib.h>

int convertCharToNumber(char ch) {
  if (ch >= '0' && ch <= '9') {
    return ch - '0';
  } else if (ch >= 'A' && ch <= 'F') {
    return ch - 'A' + 10;
  } else {
    return -1;
  }
}

char convertNumberToChar(int n) {
  if (n >= 0 && n <= 9) {
    return n + '0';
  } else if (n >= 10 && n <= 15) {
    return n - 10 + 'A';
  } else {
    return 0;
  }
}

Data convert_to_base_n(Data src, unsigned char n) {
  Data new_data;
  new_data.data = NULL;
  // TODO
  return new_data;
}

int convert_to_int(Data src) {
  // TODO
  return 0;
}

Data left_shift(Data src, int n) {
  Data new_data;
  // TODO
  return new_data;
}

Data right_shift(Data src, int n) {
  Data new_data;
  // TODO
  return new_data;
}
