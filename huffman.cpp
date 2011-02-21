#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <queue>
#include <algorithm>
#include "huffman_tree.h"


struct Symbol
{
  unsigned char code;
  int frequency;
};


inline
std::ostream& operator << (std::ostream& strm, const Symbol&symbol)
{
  strm << symbol.frequency << "/" << symbol.code << "/";
  return strm;
}





struct Analyzer
{
public:
  Analyzer(std::vector<unsigned char> &codes):
    codes(codes)
  {}
  
  void operator()(unsigned char code)
  {
      codes[code]++;
  }
public:
  std::vector<unsigned char> &codes;
};



int main(int argc, char *argv[])
{
  std::vector<unsigned char> codes(256,0);

  std::ifstream ifs("huffman.cpp",std::ifstream::in);
  std::istream_iterator<unsigned char> it(ifs);
  std::istream_iterator<unsigned char> e;
  std::for_each(it,e,Analyzer(codes));


  huffman::huffmanTree(codes);

  return 0;
}
