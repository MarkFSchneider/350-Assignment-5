#include <cstddef>
using namespace std;

template <class T>
class TreeNode
{
public:
  int key;
  T data;

  TreeNode *left;
  TreeNode *right;

  TreeNode()
  {
    left = NULL;
    right = NULL;
  }
  TreeNode(int k, T d)
  {
    left = NULL;
    right = NULL;
    key = k;
    data = d;
  }
  virtual ~TreeNode()
  {

  }


};
