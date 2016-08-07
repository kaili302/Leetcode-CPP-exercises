class Codec {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::ostringstream oss;
        if(root) serialize(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::istringstream iss{data};
        TreeNode* root=deserialize(iss);
        return root;
    }
    
private:
    void serialize(TreeNode* root, std::ostringstream &oss) {
        if (root==nullptr) {
            oss<<"# ";
            return ;
        }
        oss<<(root->val)<<' ';
        serialize(root->left, oss);
        serialize(root->right, oss);
        //delete root;
    }

    TreeNode* deserialize(std::istringstream &iss) {
        std::string val;
        if(!(iss>>val)||val=="#") {
            return nullptr;
        }
        TreeNode *pNode=new TreeNode{parseInt(val)};
        pNode->left=deserialize(iss);
        pNode->right=deserialize(iss);
        return pNode;
    }

    int parseInt(std::string &num) {
        int x;
        std::istringstream(num) >> x;
        return x;
    }
};