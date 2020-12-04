#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include <windows.h>
#include <conio.h>
#include<time.h>
#include<stdio.h>
using namespace std;
#define row 10
#define col 10
int score = 0;
int cnt = 0;
vector<vector<bool> >state(row, vector<bool>(col, false));
vector<vector<int> >nums(row, vector<int>(col, 0));
void display()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (!state[i][j])
            cout << nums[i][j] << " ";
            else cout << "  ";
        }
        cout << endl;
    }
    cout << "your score is :" << score << endl;
}
void initgame()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            state[i][j] = false;
            nums[i][j] = rand() % 3;
        }

    }
    display();
}
bool isvalid(int x, int y)
{
    if (x < 0 || x >= row || y < 0 || y >= col || state[x][y])return false;
    return true;
}
bool isgameover()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int target = nums[i][j];
            int x = i;
            int y = j;
            if (!isvalid(i, j))return false;
            if ((isvalid(x + 1, y) && nums[x + 1][y] == target) || (isvalid(x - 1, y) && nums[x - 1][y] == target) || 
                (isvalid(x, y + 1) && nums[x][y + 1] == target) || (isvalid(x, y - 1) && nums[x][y - 1] == target))
                return false;
        }
    }
    return true;
}
void dfs(int x, int y,int target)
{
    if (!isvalid(x, y))return;
    if (nums[x][y] != target)return;
    state[x][y] = true;
    cnt++;
    dfs(x+1,y,target);
    dfs(x-1,y,target);
    dfs(x,y+1,target);
    dfs(x,y-1,target);
}
void adjustment()
{
    for (int j = 0; j < col; j++)
    {
        vector<int>tmp;
        for (int i = row-1; i >=0; --i)
        {
            if (!state[i][j])tmp.push_back(nums[i][j]);

        }
        int r = row - 1;
        for (int i = 0; i < tmp.size(); i++)
        {
            nums[r][j] = tmp[i];
            state[r][j] = false;
            r--;
        }
        for (; r >= 0; r--)
        {
            state[r][j] = true;
        }
    }
}
void playgame()
{
    int x, y;
    while (cin >> x >> y)
    {
        if(!isvalid(x,y))continue;
        int target = nums[x][y];
        cnt = 0;
        if ((isvalid(x + 1, y) && nums[x + 1][y] == target) || (isvalid(x - 1, y) && nums[x - 1][y] == target) || \
            (isvalid(x, y + 1) && nums[x][y + 1] == target) || (isvalid(x, y - 1) && nums[x][y - 1] == target))
        dfs(x,y,target);
        score += target*cnt;
        adjustment();
        display();
        if (isgameover())
        {
            cout << "gameover" << endl;
            break;
        }
    }
}
int main()
{
    
    initgame();
    playgame();
    cin.get();
    return 0;
}
