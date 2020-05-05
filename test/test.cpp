// Антон0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <windows.h>
#include "math.h"
#include <ctime>
#include "windows.h"
#include "conio.h"
#include "string"
#include "vector"
#include "fstream"
#include <iomanip>

using namespace std;

void strassign(char *&str,int i)
{
	char *str1;
	str1=new char[i];
	for(int o=0;o<i;o++)
	str1[o]='y';
	str1[i]=0;
	str=str1;	
}
void strprint(char *str)
{
	cout<<str;
}
void strcopy(char *str,char *&str1)
{
	char *str2;
	strassign(str2,strlen(str));
	for (int o=0;o<strlen(str)+1;o++)
	str2[o]=str[o];
	str1=str2;
}

void strsum(char *str,char *str1,char *&str2)
{
	char *str3;
	strassign(str3,strlen(str)+strlen(str1));
	for (int o=0;o<strlen(str);o++)
	str3[o]=str[o];
	for (int o=0;o<strlen(str1)+1;o++)
	str3[o+strlen(str)]=str1[o];
	str2=str3;
}

char* strpushback(char *str,char a)
{
	char *str1;
	strassign(str1,strlen(str)+1);
	strcopy(str,str1);
	str1[strlen(str)]=a;
	str1[strlen(str)+1]=0;
	return str1;
}

void dmasassign(int **&mas,int a,int b)
{
	int **mas1;
	mas1=new int* [a];

	for(int o=0;o<a;o++)
		mas1[o]=new int[b];

	for(int i=0;i<a;i++)
		for(int o=0;o<b;o++)
		mas1[i][o]=1;

	mas=mas1;
}
void dmasprint(int **mas,int a,int b)
{
	for(int i=0;i<a;i++)
	{
		for(int o=0;o<b;o++)
		cout<<mas[i][o]<<' ';
		cout<<' '<<endl;
	}
}
void dmasclear (int **&mas,int a)
{
	for(int i=0;i<a;i++)
		delete []mas[i];
		delete []mas;
}
void dmascopy (int **mas,int **&mas1,int a,int b)
{
	int **mas2;
	dmasassign(mas2,a,b);
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			mas2[i][j]=mas[i][j];
	mas1=mas2;
}
void dmasline (int **&mas,int a,int b)
{
	int **mas2;
	
	dmasassign(mas2,a+1,b);
	
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			mas2[i][j]=mas[i][j];

	dmasprint(mas2,a,b);

	for(int j=0;j<b;j++)
		mas2[a][j]=2;

	mas=mas2;
}

void dmaserase (int **&mas,int a,int b,int c)
{
	int **mas2;
	dmasassign(mas2,a-1,b);
	for(int i=0;i<a-1;i++)
		if(i<c-1) 
		mas2[i]=mas[i];
		else
		mas2[i]=mas[i+1];
	mas=mas2;
}

struct Node 
{
	Node *next;
	int val;
};


void printlist(Node *node)
{
	cout<<node->val<<endl;
	while(node->next!=NULL)
	{
		node=node->next;
		cout<<node->val<<endl;
	}
}

void clearlist(Node *node)
{
    Node *node1;
    while(true)
    {
        node1=node;
        if(node->next==NULL) 
        {
			delete(node1);
			break;
        }
        node=node->next;
        delete(node1);
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
Node *next=NULL;
Node *node;
node=new Node();
node->next=NULL;
node->val=1;
Node *temp=new Node();
temp->next=node;
temp->val=2;
node=temp;
Node *temp1=new Node();
temp1->next=node;
temp1->val=3;
node=temp1;
printlist(node);
clearlist(node);


_getch();
}












