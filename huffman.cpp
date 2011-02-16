#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <huffman_tree.h>


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




Node *huffmanTree(std::priority_queue<InnerNode*,std::vector<InnerNode*>,IsSymbolLess> & symbols)
{
  std::priority_queue<InnerNode*> combinedNodes;
  InnerNode *node = new InnerNode(0);
  while(symbols.size())
    {
      
    }
}


Node *huffmanTree(std::vector<unsigned char>& indices, 
		  std::vector<unsigned char>& codes)
{
  std::vector<unsigned char>::iterator it = indices.begin(),e = indices.end();
  std::priority_queue<InnerNode*,std::vector<InnerNode*>,IsSymbolLess> symbols;
  for(;it!=e;++it)
    {
      LeafNode *node = new LeafNode(codes[*it],*it);
      symbols.push(node);
    }

  return huffmanTree(symbols);
}


int main(int argc, char *argv[])
{
  std::vector<unsigned char> codes(256,0);
  std::vector<unsigned char> indices;

  std::ifstream ifs("huffman.cpp",std::ifstream::in);
  while (ifs.good())
    {
      unsigned char code = (unsigned char)ifs.get();
      if (codes[code]>0)
	{
	  indices.push_back(code);
	}
      codes[code]++;
    }

  huffmanTree(indices,codes);



  
  ifs.close();
  return 0;
  
}
