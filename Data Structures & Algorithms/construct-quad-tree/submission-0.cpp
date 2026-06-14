/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

// class Solution {
// public:
//     Node* construct(vector<vector<int>>& grid) {
//         if(allchildrensame(grid)){
//             Node* node = new Node(grid[0][0],true);
//             return node;
//         }
//         vector<vector<int>>toplef(grid.size()/2, vector<int>(grid[0].size()/2));
//         vector<vector<int>>topright(grid.size()/2, vector<int>(grid[0].size()/2));
//         vector<vector<int>>botlef(grid.size()/2, vector<int>(grid[0].size()/2));
//         vector<vector<int>>botright(grid.size()/2, vector<int>(grid[0].size()/2));
//         for(int i=0; i<grid.size()/2; i++){
//             for(int j=0; j<grid[0].size()/2; j++){
//                 toplef[i][j]=grid[i][j];
//             }
//         }
//         for(int i=grid.size()/2; i<grid.size(); i++){
//             for(int j=0; j<grid[0].size()/2; j++){
//                 botlef[i][j]=grid[i][j];
//             }
//         }
//         for(int i=0; i<grid.size()/2; i++){
//             for(int j=grid[0].size()/2; j<grid[0].size(); j++){
//                 topright[i][j]=grid[i][j];
//             }
//         }
//         for(int i=grid.size()/2; i<grid.size(); i++){
//             for(int j=grid[0].size()/2; j<grid[0].size(); j++){
//                 botright[i][j]=grid[i][j];
//             }
//         }
//         return new Node(grid[0][0],false,construct(toplef),construct(topright),construct(botlef),construct(botright));
//     }
//     bool allchildrensame(vector<vector<int>>& grid){
//         int a = grid[0][0];
//         for(int i=0; i<grid.size(); i++){
//             for(int j=0; j<grid[0].size(); j++){
//                 if(grid[i][j]!=a)return false;
//             }
//         }
//         return true;
//     }
// };


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructHelper(grid, 0, 0, grid.size());
    }

private:
    Node* constructHelper(const vector<vector<int>>& grid, int r, int c, int length) {
        if (allCellsSame(grid, r, c, length)) {
            return new Node(grid[r][c] == 1, true);
        }

        int half = length / 2;
        Node* topLeft = constructHelper(grid, r, c, half);
        Node* topRight = constructHelper(grid, r, c + half, half);
        Node* bottomLeft = constructHelper(grid, r + half, c, half);
        Node* bottomRight = constructHelper(grid, r + half, c + half, half);

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    bool allCellsSame(const vector<vector<int>>& grid, int r, int c, int length) {
        int firstVal = grid[r][c];
        for (int i = r; i < r + length; ++i) {
            for (int j = c; j < c + length; ++j) {
                if (grid[i][j] != firstVal) {
                    return false;
                }
            }
        }
        return true;
    }
};