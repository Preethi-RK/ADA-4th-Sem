/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int level, long long levelSum[]) {
    if (root == NULL)
        return;

    // Add the value of the current node to the sum of its level
    levelSum[level] += root->val;

    // Recursively traverse the left and right subtrees
    dfs(root->left, level + 1, levelSum);
    dfs(root->right, level + 1, levelSum);
}

// Function to find the kth largest level sum in the binary tree
long long kthLargestLevelSum(struct TreeNode* root, int k) {
    if (root == NULL)
        return -1; // If the tree is empty

    // Initialize an array to store the sum of nodes at each level
    long long* levelSum = (long long*)calloc(1000, sizeof(long long));

    // Perform DFS to calculate the sum of nodes at each level
    dfs(root, 0, levelSum);

    // Find the kth largest level sum
    long long* levelSums = (long long*)malloc(1000 * sizeof(long long)); // Dynamically allocate array
    int numLevels = 0;
    for (int i = 0; i < 1000 && levelSum[i] != 0; ++i) {
        levelSums[numLevels++] = levelSum[i];
    }

    // Sort the level sums in descending order (bubble sort)
    for (int i = 0; i < numLevels - 1; ++i) {
        for (int j = i + 1; j < numLevels; ++j) {
            if (levelSums[i] < levelSums[j]) {
                long long temp = levelSums[i];
                levelSums[i] = levelSums[j];
                levelSums[j] = temp;
            }
        }
    }

    // Return the kth largest level sum if it exists
    if (k <= numLevels) {
        return levelSums[k - 1];
    }
    else {
        return -1; // If there are fewer than k levels in the tree
    }
}
