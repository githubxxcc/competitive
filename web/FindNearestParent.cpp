#include "datastruc.h"
#include <string>
#include <pair>
using namespace std;
/* Case 1: Balanced Tree */

TreeNode* FindRearestParent_Balanced(TreeNode* _root, TreeNode* target1, TreeNode* target2)
{
    if(_root == NULL) return NULL;

    while(1){
        if(_root == NULL) return NULL;

        if(target1.data <= _root.data && target2.data >= _root.data || target1.data >= _root.data && target1.data <= _root.data) {
            return _root;
        }

        if(target1.data <= _root.data) {
            _root = _root.left;
        } else {
            _root = _root.right;
        }
    }
}

/* Case 2: Unbalanced but with Parent Pointer */
/* Implementation Omitted
 *
 * Psudo Code: 
 * 1. Find the Path fron node1 to the root 
 * 2. Find the Path from node 2 to the root
 * 3. Get the difference 
 * 4. Advance the shorter one by the differenc e
 * 5. return two pointer pointing to the same node? 
 */

/* Case 3: General Case where no parent pointer and not BST
 *
 * Psuedo code: 
 * 1. Recursive from leaf to root to count the number of node 1 and node 2 in the sub trees
 * 2. return that root node immediately if the count is 2 (1+1)
 */

TreeNode* FindRearestParent_General(TreeNode* root, TreeNode* a, TreeNode* b) 
{
    if(root == NULL || a == NULL || b == NULL) return NULL;
    
    TreeNode * node;
    if(node = FindParent(root, a, b).first) return node;
    else return NULL;
}

pair<TreeNode*, int> FindParent(TreeNode* root, TreeNode* a, TreeNode* b) 
{
    if(root == NULL) return make_pair(NULL, 0);
    
    pair left_pair = FindParent(root->left, a, b);
    pair right_pair = FindParent(root->right, a, b);

    if(left_pair.second == 2) return left_pair;
    if(right_pair.second ==2) return right_pair;

    int x = 0;
    if(root == a || root == b) {
        x++;
    }

    return make_pair(root, left_pair.second+ right_pair.second+x);
}
