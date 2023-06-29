// maximun depth of tree
/* [5]----root
  [3]  [7]----level 1
[1][4]  [6][9] -----level 2

answer: 3 
*/
int maxdepth(tree *root){
    int hr,hl;
    if(root == NULL)
        return 0;
    else{
        hr = maxdepth(root -> right);
        hl = maxdepth(root -> left);
    }

    if(hr > hl){
        
        return hr+1;
        }
    else{
        
        return hl+1;
        }      
}