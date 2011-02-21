#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <boost/shared_ptr.hpp>
#include <vector>
#include <bitset>


namespace huffman
{

  class streamBits
  {
  public:
    std::bitset<256> bits;
    int bit_to_set;
  public:
    void addBit(int bit)
    {
      bits.set(bit_to_set,bit);
    }
  };

  class InnerNode;
  typedef boost::shared_ptr<InnerNode> nodePtr;
  
  class LeafNode;
  typedef boost::shared_ptr<LeafNode> leafPtr;

 
  struct InnerNode
  {
  public:
    nodePtr left,right;
    int frequency;
    streamBits bits;

  InnerNode(int frequency):frequency(frequency)
    {
    }

    virtual ~InnerNode()
      {} 

    virtual void addBit(int bit)
    {
      bits.addBit(bit);
      if (hasLeftNode())
	{
	  left->addBit(bit);
	}
      if (hasRightNode())
	{
	  right->addBit(bit);
	}
    }

    bool hasLeftNode()
    {
      return left;
    }

    bool hasRightNode()
    {
      return right;
    }

    virtual void setLeft(nodePtr node)
    {
      frequency+=node->frequency;
      left = node;
    }    

    virtual void setRight(nodePtr node)
    {
      frequency+=node->frequency;
      right = node; 
    }
  };

  struct LeafNode: public InnerNode
  {
    unsigned char code;
  public:
  LeafNode(int frequency, unsigned char code):InnerNode(frequency),
      code(code)
    {
    }
    virtual ~LeafNode()
      {}
  };

  nodePtr  huffmanTree(std::vector<unsigned char>& codes);

}//namespace huffman


#endif
