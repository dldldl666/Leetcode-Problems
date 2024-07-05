class Solution {
    public String convert(String s, int numRows) {
        int numCols = s.length() / 2 + 2;
        char[][] allChar= new char[numRows][numCols];
        int curRow = 0;
        int curCol = 0;
        int count = 0;
        if (numRows == 1){
            return s;
        }
        for (int i = 0; i< numRows; i++){
            for (int j = 0; j < numCols; j++){
                allChar[i][j] = ' ';
            }
        }
        while (count < s.length()){
            while(curRow < numRows && count < s.length()){
                allChar[curRow][curCol] = s.charAt(count);
                count++;
                curRow++;
            }
            if (count == s.length()){
                break;
            }
            //这时curRow = numRows
            curRow--;
            while(curRow > 1 && count < s.length()){
                allChar[--curRow][++curCol] = s.charAt(count);
                count++;
            }
            if (count == s.length()){
                break;
            }
            curRow--;
            curCol++;
        }
        String ans = new String();
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                if (allChar[i][j] != ' '){
                    ans += allChar[i][j];
                }
            }
        }
        return ans;
    }
}// 虽然独立地过了，但是占用内存和所需时间都比较多，抽空看看答案

class Solution1Right {
    public String convert(String s, int numRows) {
        int n = s.length(), r = numRows;
        if (r == 1 || r >= n) {
            return s;
        }
        int t = r * 2 - 2;
        int c = (n + t - 1) / t * (r - 1);
        char[][] mat = new char[r][c];
        for (int i = 0, x = 0, y = 0; i < n; ++i) {
            mat[x][y] = s.charAt(i);
            if (i % t < r - 1) {
                ++x; // 向下移动
            } else {
                --x;
                ++y; // 向右上移动
            }
        }
        StringBuffer ans = new StringBuffer();
        for (char[] row : mat) {
            for (char ch : row) {
                if (ch != 0) {
                    ans.append(ch);
                }
            }
        }
        return ans.toString();
    }
}//标准答案的二维矩阵解法，比我的更严谨和简洁，只是改变了移动的方向，非常聪明

// 标答二： 压缩矩阵空间，因为每一次添加都会添加到已有元素的右边，所以只需要创建numRows个行向量就行了
class Solution2Right {
    public String convert(String s, int numRows) {
        int n = s.length(), r = numRows;
        if (r == 1 || r >= n) {
            return s;
        }
        StringBuffer[] mat = new StringBuffer[r];
        for (int i = 0; i < r; ++i) {
            mat[i] = new StringBuffer();
        }
        for (int i = 0, x = 0, t = r * 2 - 2; i < n; ++i) {
            mat[x].append(s.charAt(i));
            if (i % t < r - 1) {
                ++x;
            } else {
                --x;
            }
        }
        StringBuffer ans = new StringBuffer();
        for (StringBuffer row : mat) {
            ans.append(row);
        }
        return ans.toString();
    }
}
