/*
	name：英汉词典v2.0
	time：2023/09/01
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
    int i, n, m, j, k, t;
    int flag;
    char s[99], ss[99];
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
    while (1)
    {
 		cout << "请输入你要查找的单词:" << endl;
        flag = 1;
        printf(">>请输入:");
        printf("\n");
        cin >> s;
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
                    system("cls");
                }
                else
                {
                    printf("\n");
                    printf(" '%s' is %s\n", s, c[i]);
                    printf("\n");
                    system("pause");
                    system("cls");
                }
                printf("\n");
            }
		}
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
