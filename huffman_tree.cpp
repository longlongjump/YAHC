#include <huffman_tree.h>
#include <queue>

struct IsSymbolLess
{
  bool operator()(nodePtr first,nodePtr second)
  {
    return first->frequency > second->frequency;
  }
};

typedef std::priority_queue<nodePtr,std::vector<nodePtr>,IsSymbolLess>  node_queue_t;

huffman::nodePtr huffman::huffmanTree(node_queue_t & symbols)
{
  std::priority_queue<nodePtr> combinedNodes;
  InnerNode *node = new InnerNode(0);
  while(symbols.size())
    {
      
    }
}


huffman::nodePtr huffman::huffmanTree(std::vector<unsigned char>& indices, 
			  std::vector<unsigned char>& codes)
{
  std::vector<unsigned char>::iterator it = indices.begin(),e = indices.end();
  node_queue_t symbols;
  for(;it!=e;++it)
    {
      LeafNode *node = new LeafNode(codes[*it],*it);
      symbols.push(node);
    }

  return huffmanTree(symbols);
}
