/*****************************************************
>File Name: binary_search_tree.cpp
> Author: chenxiaoqiang
> mail: 916684703@qq.com
> Created Time: 二  3/ 5 18:47:33 2019
******************************************************/
#include <iostream>
#include <vector>

using namespace std;


typedef struct _Node{
    struct _Node * left;
    struct _Node * right;
    int val;

    _Node(int val):val(val){};
} TreeNode;


vector<TreeNode *> generate(int begin, int end){
    if (begin < end){
        return vector<TreeNode *>(1, NULL);
    }
    
    vector<TreeNode *> result;

    for (int i = begin; i <= end; i++){
        vector<TreeNode *> left = generate(begin, i-1);
	vector<TreeNode *> right = generate(i + 1, end);

	for(int i = 0; i < left.size(); i++){
	
	    for(int j = 0; j < right.size(); j++){
	        TreeNode * node = new TreeNode(i);
		node->left = left[i];
		node->right = right[j];
		result.push_back(node);
	    }
	
	}
    
    }

    return result;

}

vector<TreeNode *> generateTreeNodes(int val){
    vector<TreeNode *> result = generate(1, val);
    return result;
}

int main(int argc, char * argv[]){
    int i = 5;
    vector<TreeNode *> result =  generateTreeNodes(i);
    return 0;
}
