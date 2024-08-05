#include <iostream>
#include <vector>
std::vector<std::vector<bool>> dir_map;
std::vector<std::vector<bool>> is_det;
int rows, columns;
void dfs(int row, int column) {
    if (row<0||row>=rows||column<0||column>=columns||is_det[row][column]||!dir_map[row][column])
        return;
    is_det[row][column]=true;
    for (int ax=-1;ax<=1;ax++)
        for (int ay=-1;ay<=1;ay++)
            if (ax!=0||ay!=0)
                dfs(row+ax,column+ay);
}

int ans() {
    int counts = 0;
    for (int row=0;row<rows;row++) {
        std::string s;
        std::cin>>s;
        std::vector<bool> list_2;
        for (char c : s) 
            if (c=='@') 
                list_2.push_back(true);
            else if (c=='*')
                list_2.push_back(false);
        dir_map.push_back(list_2);
    }
    for (int i=0;i<rows;i++) {
        std::vector<bool> line(columns,false);
        is_det.push_back(line);
    }
    for (int row=0;row<rows;row++)
        for (int column=0;column<columns;column++)
            if (!is_det[row][column]&&dir_map[row][column]) {
                dfs(row,column);
                counts++;
            }
    dir_map.clear();
    is_det.clear();
    rows = 0;
    columns = 0;
    return counts;
}
int main() {
    while (true) {
        std::cin>>rows>>columns;
        if (rows==0||columns==0)
            break;
        std::cout<<ans()<<std::endl;
    }
    return 0;
}