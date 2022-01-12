#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;												//次數 
	cin>>T;
	int q = 0;
	for (int i = 0 ; i < T ; i++)
	{
		if (q != 0)
			cout<<endl;
		int n , m;										//row , col 
		cin>>n>>m;
		char ch[n][m];									//字元格 
		for (int j = 0 ; j < n ; j++)
		{
			for (int k = 0 ; k < m ; k++)
			{
				cin>>ch[j][k];
				ch[j][k] = tolower(ch[j][k]);			//字元格轉小寫 
			}
		}
		int t;
		cin>>t;											//t個測資 
		cin.ignore();
		int space = 0;
		for(int j = 0 ; j < t ; j++)					
		{
			string str;									//欲搜尋之字串 
			getline(cin , str);
			for(int k = 0 ; k < str.size() ; k++)
				str[k] = tolower(str[k]);				//字串轉小寫 
			int y , z , count = 0;
			for (int k = 0 ; k < n ; k++)
			{
				for (int s = 0 ; s < m ; s++)
				{
					if (str[0] == ch[k][s])				//判斷字串的第一個字在字元格中出現位置 
					{
						y = k ; z = s;					//紀錄位置 
														//從字串開始由各方向找 
						for (int x = 0 ; x < str.size() ; x++)//下
						{
							if (str[x] == ch[y][z])
							{
								if (y >= n)
									break;
								y++;
								count++;
							}
							else
								break;
						}
						if (count == str.size())		//如果count和字串長度相等 
						{
							cout<<k+1<<' '<<s+1<<endl;	//輸出答案 
							break;						//跳脫迴圈 
						}
						y = k ; z = s;					//歸位 
						count = 0;
						for (int x = 0 ; x < str.size() ; x++)//上 
						{
							if (str[x] == ch[y][z])
							{
								if (y < 0)
									break;
								y--;
								count++;
							}
							else
								break;
						}
						if (count == str.size())
						{
							cout<<k+1<<' '<<s+1<<endl;
							break;
						}
						y = k ; z = s;
						count = 0;
						for (int x = 0 ; x < str.size() ; x++)//右 
						{
							if (str[x] == ch[y][z])
							{
								if (z >= m)
									break;
								z++;
								count++;
							}
							else
								break;
						}
						if (count == str.size())
						{
							cout<<k+1<<' '<<s+1<<endl;
							break;
						}
						y = k ; z = s;
						count = 0;
						for (int x = 0 ; x < str.size() ; x++)//左 
						{
							if (str[x] == ch[y][z])
							{
								if (z < 0)
									break;
								z--;
								count++;
							}
							else
								break;
						}
						if (count == str.size())
						{
							cout<<k+1<<' '<<s+1<<endl;
							break;
						}
						y = k ; z = s;
						count = 0;
						for (int x = 0 ; x < str.size() ; x++)//右下 
						{
							if (str[x] == ch[y][z])
							{
								if(y >= n || z >= m)
									break;
								y++;
								z++;
								count++;
							}
							else
								break;
						}
						if (count == str.size())
						{
							cout<<k+1<<' '<<s+1<<endl;
							break;
						}
						y = k ; z = s;
						count = 0;
						for (int x = 0 ; x < str.size() ; x++)//左 下 
						{
							if (str[x] == ch[y][z])
							{
								if (y >= n || z < 0)
									break;
								y++;
								z--;
								count++;
							}
							else
								break;
						}
						if (count == str.size())
						{
							cout<<k+1<<' '<<s+1<<endl;
							break;
						}
						y = k ; z = s;
						count = 0;
						for (int x = 0 ; x < str.size() ; x++)//左上 
						{
							if (str[x] == ch[y][z])
							{
								if (y < 0 || z < 0)
									break;
								y--;
								z--;
								count++;
							}
							else
								break;
						}
						if (count == str.size())
						{
							break;
						}
						y = k ; z = s;
						count = 0;
						for (int x = 0 ; x < str.size() ; x++)//右上 
						{
							if (str[x] == ch[y][z])
							{
								if (y < 0 || z >= m)
									break;
								y--;
								z++;
								count++;
							}
							else
								break;
						}
						if (count == str.size())
						{
							cout<<k+1<<' '<<s+1<<endl;
							break;
						}
						count = 0;
					}
					if (count == str.size())
					break;
				}
				if (count == str.size())
					break;
			}
			space++;
			if (space == t-1)
				continue;
		}
		q++;
	}
}
