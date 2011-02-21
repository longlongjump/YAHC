#include "huffman_tree.h"
#include <queue>


struct IsSymbolLess
{
  bool operator()(huffman::nodePtr first, huffman::nodePtr second)
  {
    return first->frequency > second->frequency;
  }
};

typedef std::priority_queue<huffman::nodePtr,std::vector<huffman::nodePtr>,IsSymbolLess>  node_queue_t;
typedef std::vector<huffman::leafPtr> leaf_vector_t;


huffman::nodePtr huffmanTree(leaf_vector_t &symbols)
{
  std::priority_queue<huffman::nodePtr,std::vector<huffman::nodePtr>,IsSymbolLess> combinedNodes;
  huffman::nodePtr node(new huffman::InnerNode(0));
  
  if (combinedNodes.size())
    {
      node->setLeft(combinedNodes.top());
      combinedNodes.pop();
    }
  if (combinedNodes.size())
    {
      node->setRight(combinedNodes.top());
      combinedNodes.pop();
    }

  combinedNodes.push(node);

  while(combinedNodes.size())
    {
      
      combinedNodes.pop();
    }
  return huffman::nodePtr();
}



huffman::nodePtr huffman::huffmanTree(std::vector<unsigned char>& codes)
{
  std::vector<unsigned char>::iterator it = codes.begin(),e = codes.end();
  leaf_vector_t symbols;
  for(;it!=e;++it)
    {
      if (*it==0)
	continue;
      huffman::LeafNode *node = new huffman::LeafNode(*it,std::distance(codes.begin(),it));
      symbols.push_back(leafPtr(node));
    }

  node_queue_t queue(symbols.begin(),symbols.end());
  //leaf_queue_t queue = symbols;

  return ::huffmanTree(symbols);
}
