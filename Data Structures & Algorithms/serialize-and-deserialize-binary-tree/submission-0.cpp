class Codec {
public:

    void encode(TreeNode* root, string& s) {
        if (!root) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";
        encode(root->left, s);
        encode(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        encode(root, s);
        return s;
    }

    TreeNode* decode(stringstream& ss) {
        string x;
        getline(ss, x, ',');

        if (x == "#")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(x));
        root->left = decode(ss);
        root->right = decode(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
};