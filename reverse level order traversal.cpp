// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1# 

vector<int> result;

int height(Node *root){
    if(!root) return 0;
    
    int lheight = height(root->left);
    int rheight = height(root->right);
    
    if(lheight >= rheight) return lheight + 1;
    else return rheight + 1;
}

void currentlevel(Node *root, int level){
    if(!root) return; 
    
    if(level == 1) result.push_back(root->data);
    else if(level > 1){
        currentlevel(root->left, level-1);
        currentlevel(root->right, level-1);
        
    }
}


void levelorder(Node *root){
    int h = height(root);
    
    for(int i=h; i>= 1; i--){
        currentlevel(root, i);
    }
}


vector<int> reverseLevelOrder(Node *root)
{   
    levelorder(root);
    
    return result;
}
