/* Check if a binary tree is a full binary tree */

#include <queue>
using namespace std;

/* 
 *1. get nodes into a queue one by one (the same layer) 
  2. when there is a node which is NULL, if there is subsequent nodes that are not null, return false 
 */

bool IsFullBT(BT* tree)
{
    queue que;
    if(tree.root == NULL) {
        return true;
    }
    
    que.push(tree.root);
    Node * node;

    while(node = que.front()) {
        que.push(node.left);
        que.push(node.right);
        que.pop();
    }

    //encountering a NULL; cannot simply return !que.empty() since NULL also takes up one space
    while(!que.empty()) {
        if(que.front() != NULL) return false;
        que.pop();
    }
    return true;
}
