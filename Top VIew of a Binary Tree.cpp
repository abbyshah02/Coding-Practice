/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//Structure of binary tree
/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    map<int,int> consideredNodes;
    queue<pair<struct Node*,int>> q;
    
    
    if(root == NULL)
        return;
    
    q.push(make_pair(root,0));
    
    while(!q.empty())
    {
       
        pair<Node*, int> p = q.front();
        struct Node *n = p.first;
        int val = p.second;
        
        q.pop();
        if(consideredNodes.find(val) == consideredNodes.end())
        {
            consideredNodes[val] = n->data; 
           // cout << val << "+++";
            cout << n->data << " ";
        }
            
        if(n->left != NULL)
        {
            q.push(make_pair(n->left,val-1));
        }
        if(n->right != NULL)
        {
            q.push(make_pair(n->right,val+1));
        }
        
        
        
       
    }
    
    
 /*   for(map<int,int>::iterator it = consideredNodes.begin(); it != consideredNodes.end(); it++)
    {
        if(it==consideredNodes.end())
            cout << it->second ;
        
        
        cout << it->second << " ";
    }*/
    
 
  
}