/*
	name��Ӣ���ʵ�v3.0. 
	time��2023/09/04
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
        printf("���ݿ�������⣬�޷��������ݿ�");
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
    	Sleep(2000); 
    	system("cls"); 
    	cout<<"+------------------------------------------------------------+"<<endl;
    	Sleep(100);
		cout<<"|                          #���˵�#                          |"<<endl;
		Sleep(100);
		cout<<"|                 Ӣ���ʵ�    v3.0                           |"<<endl;
		Sleep(100);
    	cout<<"|             [����]    1 -- �����˳��ʵ�                    |"<<endl;
    	Sleep(100);
    	cout<<"|             [����]    2 -- �鿴��Ʒ��Ϣ                    |"<<endl;
		Sleep(100); 
		cout<<"|             [����]    3 -- �����ʷ��¼                    |"<<endl; 
		Sleep(100); 
		cout<<"+------------------------------------------------------------+"<<endl;
		Sleep(100); 
    	cout<<"|���棺                                                      |"<<endl;
    	Sleep(100);
    	cout<<"|������־��                                                  |"<<endl; 
    	Sleep(100);
		cout<<"|>>3.0ȫ�°汾���Ż��û�����,ȫ����дUI                      |"<<endl;
		Sleep(100); 
		cout<<"+------------------------------------------------------------+"<<endl; 
        flag = 1;
        printf(">>������:\n");
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
			cout<<"*����*"<<endl;
			Sleep(1000);
			cout<<">>��ӭ��ʹ��Ӣ���ʵ�"<<endl;
			Sleep(1000);
			cout<<">>�汾��v3.0"<<endl;
			Sleep(3500);
			cout <<">>ʱ�䣺2023/09/04"<<endl; 
			system("cls");
		} 
		if (strcmp(s, "3") == 0)
        {
            system("cls"); 
        }
        else
        {
            i = Binary_Seareh(s);
            if (i == 0)
            {
                printf("��Ǹ�����ݿ���û�иõ��ʣ���ȷ����������\n");
                printf("\n");
            }
            else
            {
                if (flag == 0)
                {
                    printf("\n");
                    printf("�������Ӧ���� '%s' : %s", s, c[i]);
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
    printf("�ټ�!\n");
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
