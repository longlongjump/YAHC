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

 
  struct InnerNode
  {
  private:
    nodePtr left,right;
    
  public:
    int frequency;
  InnerNode(int frequency):frequency(frequency)
    {
    }

    virtual ~InnerNode()
      {} 

    virtual void addBit(int bit)
    {
      bits.addBit(bit);
      left->addBit(bit);
      right->addBit(bit);
    }

    virtual void setLeft(nodePtr node)
    {
      left = node;
    }    

    virtual void setRight(nodePtr node)
    {
      right = node; 
    }
  };

  struct LeafNode: public InnerNode
  {

    streamBits bits;
    unsigned char code;
  public:
  LeafNode(int frequency, unsigned char code):InnerNode(frequency),
      bit_to_set(0)
      code(code),
      
    {
    }
    virtual ~LeafNode()
      {}
  };

Node *huffmanTree(std::vector<unsigned char>& indices, 
		  std::vector<unsigned char>& codes);

}//namespace huffman


#endif
