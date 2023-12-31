/*
	name：英汉词典v4.0 
	time：2023/09/04
*/

#include <bits/stdc++.h>
#include <windows.h> 
#include <conio.h> 

using namespace std;
int w = 0;
char e[9999][999], c[9999][999];
int Binary_Seareh(char p[999]);
int main()
{
    int i, n, m, j, k, t, cidian;
    int flag;
    char s[99], ss[99];
    xuanze:
    cout << "请选择数据库文件：" << endl;
	cout << "【1】英汉词典1" << endl; 
	cout << "【2】英汉词典2" << endl;
	cin >> cidian; 
	if (cidian == 1) {
		FILE* fp;
    fp = fopen("dictionary.txt", "r");
    if (fp == NULL)
    {
        printf("数据库存在问题，无法访问数据库");
        exit(0);
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s%s", e[w], c[w]);
            w++;
        }
        fclose(fp);
    }
	}
	if (cidian == 2) {
		FILE* fp;
    fp = fopen("niujin.txt", "r");
    if (fp == NULL)
    {
        printf("数据库存在问题，无法访问数据库");
        exit(0);
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s%s", e[w], c[w]);
            w++;
        }
        fclose(fp);
    }
	}
    while (1)
    {
    	system("cls"); 
    	cout<<"<词典"<<cidian<<">"<<endl;  
    	cout<<"+------------------------------------------------------------+"<<endl;
		cout<<"|                          #主菜单#                          |"<<endl;
		cout<<"|                 英汉词典    v4.0                           |"<<endl;
    	cout<<"|             [操作]    1 -- 即刻退出词典                    |"<<endl;
    	cout<<"|             [操作]    2 -- 查看产品信息                    |"<<endl;
		cout<<"|             [操作]    3 -- 清楚历史记录                    |"<<endl;
		cout<<"|             [操作]    4 -- 更换词典文件                    |"<<endl; 
		cout<<"+------------------------------------------------------------+"<<endl;
    	cout<<"|公告：如果此词典库不可用，请更换词典！                      |"<<endl;
    	cout<<"|更新日志：                                                  |"<<endl; 
		cout<<"|>> 4.0全新版本，优化用户体验,增加了一个词典数据库！         |"<<endl;
		cout<<"|>> 全面提升程序响应和运行速度……                           |"<<endl; 
		cout<<"+------------------------------------------------------------+"<<endl; 
        flag = 1;
        printf(">>请输入:\n");
        printf("\n");
        cin>>s;
        int x = 0, m = -1;
        while (s[x] != '\0')
        {
            if (s[x] != ' ' && m != -1)
            {
                s[m] = s[x];
                m++;
            }
            else if (s[x] == ' ' && m == -1)
            {
                m = x;
            }
            x++;
        }
        if (m != -1)
        {
            s[m] = '\0';
        }
        t = strlen(s);
        for (i = 0; i < t; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 32;
                flag = 0;
            }
        }
		if(strcmp(s,"1") == 0)
		{
			break; 
    	}
		
        if(strcmp(s,"2") == 0)
		{
			cout<<"*关于*"<<endl;
			Sleep(1000);
			cout<<">>欢迎您使用英汉词典"<<endl;
			Sleep(1000);
			cout<<">>版本：v3.0"<<endl;
			Sleep(3500);
			cout <<">>时间：2023/09/04"<<endl; 
			system("cls");
		} 
		if (strcmp(s, "3") == 0)
        {
            system("cls"); 
        }
        if (strcmp(s, "4") == 0)
        {
            goto xuanze;
        }
        else
        {
            i = Binary_Seareh(s);
            if (i == 0)
            {
                printf("抱歉，数据库里没有该单词，请确保输入无误！\n");
                printf("\n");
            }
            else
            {
                if (flag == 0)
                {
                    printf("\n");
                    printf("这个单词应该是 '%s' : %s", s, c[i]);
                    printf("\n");
                    system("pause");
                }
                else
                {
                    printf("\n");
                    printf(" '%s' is %s\n", s, c[i]);
                    printf("\n");
                    system("pause");
                }
                printf("\n");
            }
        }
	}
    printf("再见!\n");
	Sleep(1500); 
}
int Binary_Seareh(char p[999])
{
    int low = 0, mid, high = w - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (strcmp(e[mid], p) == 0)
        {
            return mid; 
        }
        if (strcmp(e[mid], p) > 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}
