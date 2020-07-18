/*   Ceil    */
int Ceil(TreeNode *root, int x)
{
	if(!root)
		return -1;
	if(root->val==x)
		return root->val
	else if(root->val<x)
		return Ceil(root->right, x);
	int ceil = Ceil(root->left, x);
	return ceil>=input ? ceil : root->val;
}


/*  Floor   */
int Floor(TreeNode *root, int x)
{
	if(!root)
		return -1;
	if(root->val==x)
		return root->val
	else if(root->val>x)
		return Floor(root->left, x);
	int floor = Floor(root->right, x);
	return floor<=input ? floor : root->val;
}
