#include "../utils/common.hpp"
#include "./binary_tree.cpp"

vector<int> vec; // 初始化列表，用于保存遍历过程中访问的节点值

// 层序遍历
// 使用队列实现
vector<int> levelOrder(TreeNode *root)
{

    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        // 将node指向根节点
        TreeNode *node = queue.front();

        // 队首出列，表示队列中指向根节点的指针出列
        queue.pop();

        vec.push_back(node->val); // 保存出列的节点值

        // 虽然队首出列了，但是node仍指向根节点，因此可以访问子树
        if (node->left != nullptr)
            queue.push(node->left);
        if (node->right != nullptr)
            queue.push(node->right);
    }
    return vec;
}

// 前序遍历
void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    // 访问优先级: 根节点->左子树->右子树
    vec.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}
// 中序遍历
void inOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    // 访问优先级: 左子树->根节点->右子树
    inOrder(root->left);
    vec.push_back(root->val);
    inOrder(root->right);
}
// 后序遍历
void postOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    // 访问优先级: 左子树->右子树->根节点
    postOrder(root->left);
    postOrder(root->right);
    vec.push_back(root->val);
}

int main()
{

    return 0;
}