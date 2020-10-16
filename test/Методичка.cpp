// изменение типизированного файла. конкретной его записи

// const в с++ где можно поставить и зачем

// что такое статик где и как используется

// дружественный класс

// командная строка

// ключевое слово operator
// ключевое слово fiend
// - до сих пор нет четкого понимания отличия & и * в параметрах функции
// Замечание по уроку с Камилой. Лучше сначала давать цикл while, потом for.
// Найти альтернативные программы для удаленного доступа, помниматься в какомто хакере они были

//Еще несколько замечаний не по теме. Если внутри объекта происходит динамическое выделение памяти, то нужно помнить о правиле трех: 
//деструктор (чтобы освобождать память при уничтожении объекта), 
//копирующий конструктор и 
//оператор присваивания (чтобы производить глубокое копирование объекта при необходимости). 
//Несоблюдение этого правило чревато массой неприятностей. См. литературу.

//#include "stdafx.h"
// подключение mysql
//#include "my_global.h"

#include <process.h>

#include "mysql.h"
#include "my_global.h"


#include <sstream> //to_string

#include <vector>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>

#include <iostream>
#include <fstream>
#include <conio.h>
#include "windows.h"
#include <math.h>
#include <string>

#include <algorithm>

#include <stdio.h>

#include <stdlib.h> 
#include <io.h> 
#include <time.h> 

#include <direct.h> // для mkdir
#include <sys/stat.h> // для stat проверка существования файла или папки

//#include <filesystem> C++2017

#define _USE_MATH_DEFINES

#include <cmath>
#include <ctime>

#include <iomanip>// setprecision, setw


#include "my_lib.h"
#include "curl/curl.h"

#pragma comment(lib,"curllib.lib")    

using namespace std;

int anyFunc()
{
    return 7;
}
 


int opz(string str)
{
	stack <int> stk;

    for (int i = 0; i < str.size(); i++)
    {

        if (isdigit(str[i]))
        {
			stk.push(str[i]-48);
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*'  || str[i] == '/')
        {
			int a, b;

			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();

			if (str[i] == '+')
				a = b + a;
			else if (str[i] == '-')
				a = b - a;
			else if (str[i] == '*')
				a = b * a;
			else if (str[i] == '/')
				a = b / a;

			stk.push(a);
        }
	}
	return stk.top();
}


bool isNumber(char Symbol)
{
    if (Symbol >= '0' && Symbol <= '9')
        return true;

    return false;
}

struct StringAndCount
{
	string str;
	int count;
};

struct status { //status - password and online
    string password;
    bool online;
};

struct Lesson {
    int begin;
    int end;
};

enum OTDEL
{
	OCHNO, ZAOCHNO, VECHER
};

struct Student
{
	string name; // ФИО
	int vozrast; // возраст
	int rost;// рост в см
	int ocenki[5]; // оценки по пяти предметам
	float stip;// размер стипендии
	string data_post;// дата поступления
	OTDEL otdel;// отделение
};


template <typename T>
string to_string(T val)
{
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

void gotoxy( int x, int y )
{
	COORD p = { x, y };
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
}

// rand от a до b  rnd
int rand(int a, int b)
{
	//static int first = true;
	//if (first)
	//{
	//	srand(time(NULL));
	//	first = false;
	//}
	return (a + rand()%(b-a+1));
}

string getCurrentTime()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	//string curr_date = to_string(st.wDay) + "." + to_string(st.wMonth) + "." + to_string(st.wYear);
	string curr_date = to_string(st.wHour) + "." + to_string(st.wMinute) + "." + to_string(st.wSecond);
	return curr_date;
}


bool isAnagramm(string word1, string word2)
{
	map <char,int> map1;
	map <char,int> map2;

	for (int i = 0; i < word1.length(); i++)
	{
		map1[word1[i]]++; 
	}

	for (int i = 0; i < word2.length(); i++)
	{
		map2[word2[i]]++; 
	}

	if (map1 == map2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool asc(int a, int b)
{
    return a > b; // меняем местами, если первый элемент оказывается больше второго
}

void sort(vector <int> &vec, bool (*compFunc)(int, int))
{
	int tmp;

	for(int i = 0; i < vec.size()-1; i++) // i - номер прохода
	{            
		for(int j = 0; j < vec.size()-1-i; j++) // внутренний цикл прохода
		{     
			if (asc(vec[j], vec[j+1]))
			{
				tmp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = tmp;
			}
		}
	}
}

void vecFunc1(int &a)
{
    cout << a << " ";
}

void vecFunc2(int &a)
{
    a++;
}

void for_each(vector <int> &vec, void (*vecFunc)(int&))
{
	for (int i = 0; i < vec.size(); i++)
	{
		vecFunc(vec[i]);
	}
}

int getInteger()
{
    std::cout << "Enter an integer: ";
    int a;
    std::cin >> a;
    return a;
}
 
char getOperation()
{
    char op;
 
    do
    {   
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    }
    while (op!='+' && op!='-' && op!='*' && op!='/');
 
    return op;
}
 
int add(int a, int b)
{
    return a + b;
}
 
int subtract(int a, int b)
{
    return a - b;
}
 
int multiply(int a, int b)
{
    return a * b;
}
 
int divide(int a, int b)
{
    return a / b;
}
 
typedef int (*arithmeticFcn)(int, int);
 
arithmeticFcn getArithmeticFcn(char op)
{
	switch (op)
	{
	default: // функцией по умолчанию будет add()
	case '+': return add;
	case '-': return subtract;
	case '*': return multiply;
	case '/': return divide;
	}
}
 
typedef bool (*testFnc)(string);


bool test1(string str)
{
	cout << "test1";
    return 1;
}

bool test2(string str)
{
	cout << "test2";
    return 1;
}

void sort(vector <int> &vec)
{
	int tmp;

	for(int i = 0; i < vec.size()-1; i++) // i - номер прохода
	{            
		for(int j = 0; j < vec.size()-1-i; j++) // внутренний цикл прохода
		{     
			if (vec[j] > vec[j+1])
			{
				tmp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = tmp;
			}
		}
	}
}


void sort(vector <Lesson> &vec, int a, int b)
{
	Lesson tmp;
	for(int i = a; i < b-1; i++) 
	{
		for(int j = a; j < b-1; j++) 
		{
			if (vec[j].end > vec[j+1].end)
			{
				tmp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = tmp;
			}
		}
	}
}



void sort(vector <Lesson> &vec)
{
	Lesson tmp;

	for(int i = 0; i < vec.size()-1; i++) // i - номер прохода
	{            
		for(int j = 0; j < vec.size()-1-i; j++) // внутренний цикл прохода
		{     
			if (vec[j].begin > vec[j+1].begin)
			{
				tmp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = tmp;
			}
		}
	}

	for(int i = 0; i < vec.size()-1; i++) // i - номер прохода
	{            
		for(int j = 0; j < vec.size()-1-i; j++) // внутренний цикл прохода
		{     
			if (vec[j].end > vec[j+1].end && vec[j].begin == vec[j+1].begin)
			{
				tmp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = tmp;
			}
		}
	}

}

int d6()
{
    int z = 0;
    z = rand() % 5 + 1;
    return z;
}


void sort(vector <StringAndCount> &vec)
{
	StringAndCount tmp;

	for(int i = 0; i < vec.size()-1; i++) // i - номер прохода
	{            
		for(int j = 0; j < vec.size()-1-i; j++) // внутренний цикл прохода
		{     
			if (vec[j].count < vec[j+1].count)
			{
				tmp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = tmp;
			}
		}
	}
}


string trim(string str1)
{
	//string str1 = "   привет    как дела ?    ";	// для сохранения строки
	//string str1 = "а      ";	// для сохранения строки
	string str2;	// для сохранения строки
	
	int a = 0;
	for (a = 0; a < str1.length(); a++)
	{
		if (str1[a] != ' ')
			break;
	}

	int b = 0;
	for (b = str1.length() - 1; b >= 0; b--)
	{
		if (str1[b] != ' ')
			break;
	}

	for (int i = a; i < b+1; i++)
	{
		str2 += str1[i];
	}

	return str2;
}

int isPow2(int n)
{
	int x = 1;
	while (x < n)
	{
		x = 2*x;
	}

	if (x == n)
		return 1;
	else
		return 0;
}

int prost(int x)
{
	int i = 2;

	if (x == 1)
		return 1;

	while (x % i != 0)
	{
		i++;
	}

	if (x != i)
		return 0;
	else
		return 1;
}

bool isSqr(int n)
{
	int x = 0;
	bool f = 0;

	while (x * x < n)
	{
		x++;
	}	

	if (x * x == n)
	{
		return 1;	
	}

	return 0;	
}


struct Menu
{
	private:

	public:

		int x,y;
		int color;
		int select_item;
		int count_items;
		string * items;

		Menu(int n)
		{
			select_item = 0;
			items = new string [n];
			count_items = 0;
		};

		~Menu()
		{
			delete [] items;
		};

		void add(string str)
		{
			items[count_items] = str;		
			count_items++;
		}

		void show()
		{
			int lx = x;
			int ly = y;
			for(int i=0; i < count_items; i++)
			{
				gotoxy(lx,ly);
				cout << items[i];
				cout << endl;
				ly++;
			}
			gotoxy(x,y + select_item);
		}

		void prev()
		{
			if (select_item > 0)
				select_item--;
			gotoxy(x,y + select_item);
		}

		void next()
		{
			if (select_item < count_items-1)
				select_item++;
			gotoxy(x,y + select_item);
		}
};

string toUpper(string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}


bool isSort(vector <int> & vec)
{
	const int n = 5;

	for (int i = 0; i < vec.size()-1; i++)
	{
		if (vec[i] > vec[i+1])
		{
			return 0;
		}
	}

	return 1;
}

bool isSort(vector < vector <int> > map)
{
	gotoxy(0,6);
	int size = map.size()-1;
	int x = 0;
	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (x < map[j][i])
			{
				x = map[j][i];
			}
			else
			{
				return 0;
			}
		}
	}
	return 1;
}


void print(vector <int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;	
}

void print(deque <int> deq)
{
	for (int i = 0; i < deq.size(); i++)
	{
		cout << deq[i] << " ";
	}
	cout << endl;	
}

struct Task
{
	int id;
	int tact;
};

void pushTask(deque <Task> &deq, int x, int y)
{
	static int id = 0;
	Task t;
	t.id = id;
	t.tact = rand(x, y);
	deq.push_back(t);
	id++;
}

void print(deque <Task> deq, int x, int y, string str)
{
	gotoxy(x,y); cout << str; y++;
	for (int i = 0; i < deq.size(); i++)
	{
		gotoxy(x,y);
		cout << setw(3) << deq[i].id << " " << deq[i].tact;
		y++;
	}
	//cout << endl;	
}


void printVec2(vector <int> vec1, vector <int> vec2)
{
	for (int i = 0; i < vec1.size(); i++)
	{
		//if (vec2[i] == 0) continue;
		cout /*<< vec1[i] << ":"*/<< vec2[i] << " ";
	}
	cout << endl;	
}

void print(vector <string> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
	cout << endl;	
}


void print(queue <int> que)
{
	while(!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;	
}



void validSemicolon(vector <string> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].empty())
		{
			continue;		
		}

		if (vec[i][0] == '{' || vec[i][0] == '}' || vec[i][0] == '#')
		{
			continue;		
		}

		if (vec[i].substr(0,2) == "if")
		{
			if ((int)vec[i].find('=') != -1 && (int)vec[i].find(">=") == -1 && (int)vec[i].find("<=") == -1)
			{
				int p = (int)vec[i].find('=');
				if (vec[i][p+1] != '=')
				{
					cout << "стр. " << i << " вместо двойного равно (==) используется одинарное"<< endl;
				}
			}

			continue;		
		}

		if (vec[i].substr(0,2) == "//")
		{
			continue;		
		}

		if (vec[i].substr(0,4) == "else")
		{
			continue;		
		}

		if (vec[i].substr(0,8) == "int main")
		{
			continue;		
		}

		if (vec[i][vec[i].length()-1] != ';')
		{
			cout << "стр. " << i << "в конце строки пропущена точка с запятой"<< endl;
		}
	}
	cout << endl;	
}

int sumVector(vector <int> vec)
{
	int s = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		s += vec[i];
	}
	return s;
}

int sumVector2(const vector <int> & vec)
{
	int s = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		s += vec[i];
	}
	return s;
}

template <typename T>
void print(set <T> st)
{
	for(set <T>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

long long int sqr(long long int x)
{
	return x*x;
}

struct Command
{
	string type;
	string word1;
	string word2;
};

template <typename T>
bool find(vector <T> vec, T x)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (x == vec[i])
		{
			return 1;
		}
	}
	return 0;
}



int find(vector <StringAndCount> vec, string str)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (str == vec[i].str)
		{
			return i;
		}
	}
	return -1;
}

// Поиск элемента в двумерном векторе
bool find(vector < vector <int> > vec, int x)
{
	for (int i = 0; i < vec.size(); i++){
		for (int j = 0; j < vec.size(); j++){
			if (x == vec[i][j]){
				return 1;
			}
		}
	}
	return 0;
}

void printVec(const vector <vector<int>> &vec, int sw)
{
	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = 0; j < vec[i].size(); j++)
		{
			cout << setw(sw) << vec[i][j] << " ";
		}
		cout << endl;
	}	
}

void initVecRand(vector <vector<int>> &vec)
{
	for(int i = 0; i < rand(3,5); i++)
	{
		vector<int> temp;

		for(int j = 0; j < rand(3,5); j++)
		{
			temp.push_back(rand(0,9));
		}

		vec.push_back(temp);
	}
}

void initVecRand(vector <int> &vec)
{
	for(int j = 0; j < rand(100,200); j++)
	{
		vec.push_back(rand(0,9));
	}
}

void initVec(vector <vector<int>> &vec, int n, int x)
{
	vec.clear();
	for(int i = 0; i < n; i++)
	{
		vector<int> temp;
		for(int j = 0; j < n; j++)
		{
			temp.push_back(x);
		}
		vec.push_back(temp);
	}
}

void initVec123(vector <vector<int>> &vec, int n)
{
	int x = 1;
	vec.clear();
	for(int i = 0; i < n; i++)
	{
		vector<int> temp;
		for(int j = 0; j < n; j++)
		{
			temp.push_back(x);
			x++;
		}
		vec.push_back(temp);
	}
}

void fillVecRand(vector <vector<int>> &vec, int d1, int d2)
{
	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = 0; j < vec.size(); j++)
		{
			vec[i][j] = rand(d1,d2);
		}
	}
}

void sort(vector <vector<int>> &vec)
{
	int temp = 0;
	for(int i=0;i<vec.size();i++)             // SORT ARRAY
	{
		for(int j=0;j<vec.size();j++)            // для каждого элемента
		{
			for(int k=0;k<vec.size();k++)     // бежим по массиву
			{
				for(int s=0;s<vec.size();s++)
				{
					if(vec[i][j]<vec[k][s])          // сравниваем элементы
					{ 
						temp = vec[i][j];           // и если надо, меняем
						vec[i][j] = vec[k][s];   
						vec[k][s] = temp;
					}
				}
			}
		}
	}
}

void shiftVec(vector <vector<int>> &vec)
{
	int temp = vec.back().back();
	for(int i=vec.size()-1;i>=1;i--)             
	{
		for(int j=vec.size()-1;j>=1;j--)
		{
			vec[i][j] = vec[i][j-1];   
		}
		vec[i][0] = vec[i-1][vec.size()-1];
	}
	for(int j=vec.size()-1;j>=1;j--)
	{
		vec[0][j] = vec[0][j-1];   
	}
	vec[0][0] = temp;
}



void deleteMin(vector <vector<int>> &vec, int n)
{

	for(int i=0;i < n; i++)             // SORT ARRAY
	{
		int min = vec[0][0];
		int ii = 0,jj = 0;
		for(int i=0;i<vec.size();i++)             // SORT ARRAY
		{
			for(int j=0;j<vec[i].size();j++)            // для каждого элемента
			{
				if(vec[i][j]<min)          // сравниваем элементы
				{ 
					min = vec[i][j];
					ii = i;
					jj = j;
				}
			}
		}

		swap(vec[ii][jj],vec.back().back());
		vec.back().pop_back();
		if (vec.back().empty())
		{
			vec.pop_back();
		}
	}
}

void deleteMaksStrok(vector <vector<int>>&vec)
{
    vector <int> vec1;
    vector <int> peremen;
    int a = 0, s=0, f=0, max, imax;
	
	max = vec[0][0];
	imax = 0;

    for(int i = 0; i < vec.size(); i++)
    {
        for(int u =0; u < vec.size();u++)
        {
            s = s + vec[i][u];
        }
        vec1.push_back(s);

		if (s > max)
		{
			max = s;
			imax = i;
		}
		s = 0;
    }
	vec[imax] = vec.back();
    vec.pop_back();
}


void initVecRand(vector <vector<int>> &vec, int n, int x)
{
	for(int i = 0; i < n; i++)
	{
		vector <int> temp;

		for(int j = 0; j < n; j++)
		{
			temp.push_back(x);
		}

		vec.push_back(temp);
	}
}

void fillUniqueRand(vector <vector<int>> &vec, int d1, int d2)
{
	for(int i = 0; i < vec.size(); i++)	{
		for(int j = 0; j < vec[i].size(); )		{
			int x = rand(d1,d2);
			if (!find(vec, x))
			{
				vec[i][j] = x;
				j++;
			}
		}
	}
}

int countUnique(vector <vector<int>> &vec)
{
	vector <int> temp;
	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = 0; j < vec.size(); j++)
		{
			if (!find(temp, vec[i][j]))
			{
				temp.push_back(vec[i][j]);
			}
		}
	}
	return temp.size();
}



template <typename T>
bool isIntersect(set <T> st1, set <T> st2)
{
	for(set <T>::iterator it = st1.begin(); it != st1.end(); it++)
	{
		set <T> :: iterator found = st2.find(*it);

		if (found == st2.end())
		{
			return false;
		}
	}
	return true;
}

string getWord(string &str)
{
	static int a = 0;

	if (a >= str.length())
	{
		a = 0;
		return "";
	}
	
	if (a == 0)
	{
		a = str.find(' ');
		int t = a;
		a = a + 3;
		return str.substr(0, t);
	}

	int b = str.find(',');
	if (b == -1)
	{
		int t = a;
		a = str.length();
		return str.substr(t, str.length()-t);
	}
	else
	{
		str[b] = ' ';
		int t = a;
		a = b+2;
		return str.substr(t, b-t);
	}

}

#define DEBUG 0

const size_t BUF_SIZE = 5000000;
char wr_buf[BUF_SIZE+1];  // char*   wr_buf[BUF_SIZE+1];
size_t wr_index=0;


enum ConsoleColor
{
	BLACK         = 0,
	BLUE          = 1,
	GREEN         = 2,
	CYAN          = 3,
	RED           = 4,
	MAGENTA       = 5,
	BROWN         = 6,
	LIGHT_GRAY    = 7,
	DARKGRAY      = 8,
	LIGHT_BLUE    = 9,
	LIGHT_GREEN   = 10,
	LIGHT_CYAN    = 11,
	LIGHT_RED     = 12,
	LIGHT_MAGENTA = 13,
	YELLOW        = 14,
	WHITE         = 15
};



struct SPoint
{
    int x;
    int y;
	int dir;
	int val;
};


class Point
{
public:
    int x;
    int y;
	int dir;
	int val;
};


//template <class T>
template <typename T>
void printAdr(T val)
{
    cout << &val;
}


template<class Type>
Type _min(Type a, Type b) {
    if (a < b) {
        return a;
    }
    return b;
}

template<>
string _min(string a, string b){
    if(a.size() < b.size()){
        return a;
    }
    return b;
}


int distanceBetweenPoints(SPoint p0, SPoint p1)
{
	float a = abs(p0.x - p1.x);
	float b = abs(p0.y - p1.y);
	return sqrt(a*a + b*b);
}

#define ElementCount(x) (sizeof(x)/sizeof(x[0]))

string create_path_old(string s)
{
	char path[MAX_PATH];
	GetModuleFileNameA(NULL, path, sizeof(path) / sizeof(path[0]));

	// удаляем символы от конца до первого слеша
	for (int i = strlen(path); i>0; i--)
	{
		if (path[i] != '\\')
			path[i] = 0;
		else
			break;
	}

	// конкатенация строк
	strcat_s(path,s.c_str());

	string str = string(path);

	return str;
}

string getPathApp()
{
	// более универсальный но сложный
	//char path[MAX_PATH];
	//GetModuleFileNameA(NULL, path, sizeof(path) / sizeof(path[0]));

	//более простой
	char path[256];
	GetModuleFileNameA(NULL, path, 256);

	string str(path);

	// удаляем символы от конца до первого слеша
	// короткий способ проф
	str.erase(str.find_last_of("\\"));

	//// длинный способ
	//// удаляем символы от конца до первого слеша
	//for (int i = str.length()-1; i>0; i--)
	//{
	//	if (path[i] == '\\')
	//	{
	//		//str.erase();
	//		str.erase(i+1);
	//		//path[i] = 0;
	//		break;
	//	}
	//}


	return str;
}

int sum(int x, int y) // заголовок функции
{
	int z = 0;
	z = x + y;
	return z;
}

enum ECmd {mov, adddd, mul, call, ret, end};

struct SCommand
{
	ECmd cmd;
	int val;

};

void printStr(char s[])
{
	for (int i = 0; i < strlen(s); i++)
	{
		cout << s[i] << " ";
		s[i] = 'f';
	}
}

void reduce(float &f)
{
	f = f * 85.0 / 100.0;
}

void inc(int *p, int n)
{
	for (int i = 0; i < n; i++)
	{
		(*p)++;
		p++;
	}
}


void sort(int *vec, int n)
{
	int tmp;

	for(int i = 0; i < n-1; i++) // i - номер прохода
	{            
		for(int j = 0; j < n-1-i; j++) // внутренний цикл прохода
		{     
			if (*(vec+j) > *(vec + j+1))
			{
				tmp = *(vec + j + 1);
				*(vec + j) = *(vec + j + 1);
				*(vec + j + 1) = tmp;
			}
		}
	}
}

void showMas(int *p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(p+i);
	}
}

int strlen1(char *s)
{
	//int n;
	//for (n = 0; *s != '\0'; s++)
	//	n++;

	int n = 0;
	while (*s != '\0')
	{
		s++;
		n++;
	}

	return n;
}

void assign(char *&str, int n, char ch)
{
	char * temp;
	temp = new char[n+1];

	for(int i = 0; i < n; i++)
	{
		temp[i] = ch;
	}
	
	temp[n]=0;
	str = temp;	
}

void strcopy(char *&str1, char str2[])
{
	char * temp;
	temp = new char[strlen(str2) + 1];

	for(int i = 0; i < strlen(str2); i++)
	{
		temp[i] = str2[i];
	}
	
	temp[strlen(str2)] = 0;

	str1 = temp;
}

void strcat(char *&str1, char *str2)
{
	char * temp;
	temp = new char[strlen(str1) + strlen(str2) + 1];

	for(int i = 0; i < strlen(str1); i++)
	{
		temp[i] = str1[i];
	}

	for(int i = 0; i < strlen(str2); i++)
	{
		temp[i+strlen(str1)] = str2[i];
	}
	
	temp[strlen(str1) + strlen(str2)] = 0;

	str1 = temp;
}

char * addsymbol(char *str1, char ch)
{
	char * temp;
	int n = strlen(str1);
	temp = new char[n + 2];

	for(int i = 0; i < n; i++)
	{
		temp[i] = str1[i];
	}

	temp[n] = ch;
	temp[n+1] = 0;

	return temp;
}


char* strerase(char *str1, int n)
{
	char * temp;
	temp = new char[n + 1];

	for(int i = 0; i < n; i++)
	{
		temp[i] = str1[i];
	}

	temp[n] = 0;

	return temp;
}

void copystr1(char *s1, char *s2)
{
	int n = 0;
	while (*s1 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
}

bool strcmp1(char *s1, char *s2)
{
	int n = 0;
	bool eq = true; 

	while (*s1 != '\0')
	{
		if ( *s1 != *s2)
		{
			eq = false; 
			break;
		}
		s1++;
		s2++;
	}
	return eq;
}

void strcat1(char *s1, const char *s2)
{
	int n = 0;

	s1 = s1 + strlen(s2);

	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

void showStudentInfo(vector <Student> vec)
{
	cout << " " << left << setw(7) << "Name" 
						<< setw(9) << "Date" 
						<< setw(4) << "Age"
						<< setw(6) << "Rost"
						<< setw(5) << "Stip"
						<< setw(5) << "Ball";
	cout << endl << " " << "----------------------------------------" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << " " << left << setw(7) << vec[i].name 
							<< setw(9) << vec[i].data_post 
							<< setw(4) << vec[i].vozrast
							<< setw(6) << vec[i].rost
							<< setw(5) << vec[i].stip;

		for (int j = 0; j < 5; j++)
		{
			cout << left << setw(2) << vec[i].ocenki[j]; 

		}	

		cout << endl;
	}	
}

void showRect()
{
	
}

set <int> mulSet(set <int> set1, set <int> set2)
{
    set <int> st;

	for(set <int>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		set <int> :: iterator found = set2.find(*it);

		if (found != set2.end())
		{
			st.insert(*it);
		}
	}
	return st;
}

set <int> subSet(set <int> set1, set <int> set2)
{
    set <int> st;

	for(set <int>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		set <int> :: iterator found = set2.find(*it);

		if (found == set2.end())
		{
			st.insert(*it);
		}
	}
	return st;
}

set <int> addSet(set <int> set1, set <int> set2)
{
    set <int> st(set1);

	for(set <int>::iterator it = set2.begin(); it != set2.end(); it++)
	{
		st.insert(*it);
	}
	return st;
}


void quickSortR(int a[], int N) 
{
// На входе - массив a[], a[N] - его последний элемент.

  int i = 0, j = N-1; 		// поставить указатели на исходные места
  int temp, p;

  p = a[ N/2 ];		// центральный элемент

  // процедура разделения
  do 
  {
    while ( a[i] < p ) i++;
    while ( a[j] > p ) j--;

    if (i <= j) {
      temp = a[i]; a[i] = a[j]; a[j] = temp;
      i++; j--;
    }
  } while ( i<=j );


  // рекурсивные вызовы, если есть, что сортировать 
  if ( j > 0 ) quickSortR(a, j);
  if ( N > i ) quickSortR(a+i, N-i);
}

void quicksort(int *mas, int first, int last)
{
	int mid, count;
	int f=first, l=last;
	mid=mas[(f+l) / 2]; //вычисление опорного элемента
	do
	{
	while (mas[f]<mid) f++;
	while (mas[l]>mid) l--;
	if (f<=l) //перестановка элементов
	{
	count=mas[f];
	mas[f]=mas[l];
	mas[l]=count;
	f++;
	l--;
	}
	} while (f<l);
	if (first<l) quicksort(mas, first, l);
	if (f<last) quicksort(mas, f, last);
}

// Функция быстрой сортировки
void quickSort(int *numbers, int left, int right)
{
  int pivot; // разрешающий элемент
  int l_hold = left; //левая граница
  int r_hold = right; // правая граница
  pivot = numbers[left];
  while (left < right) // пока границы не сомкнутся
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    
	if (left != right) // если границы не сомкнулись
    {
      numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо 
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу вправо 
    }
  }

  numbers[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    quickSort(numbers, left, pivot - 1);
  if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}

const int MAXSTACK = 2048;

void qSortI(int a[], long size) 
{

  long i, j;   			// указатели, участвующие в разделении
  
  long left, right;  		// границы сортируемого в цикле фрагмента

  long left_stack[MAXSTACK], right_stack[MAXSTACK]; // стек запросов
                        // каждый запрос задается парой значений,
                        // а именно: левой(left_stack) и правой(right_stack) 
                        // границами промежутка

  long stackpos = 1;   	// текущая позиция стека
  long middle_pos;            // середина массива
  int pivot;              // опорный элемент
  int temp; 

  left_stack[1] = 0;
  right_stack[1] = size-1;

  //{11, 3, 14, 16, 7};

  do {
 
    // Взять границы left и right текущего массива из стека.
    left = left_stack[ stackpos ];
    right = right_stack[ stackpos ];
    stackpos--;

    do {
      // Шаг 1. Разделение по элементу pivot

      middle_pos = ( left + right ) / 2;
      i = left; j = right; pivot = a[middle_pos];

      do 
	  {
        while ( a[i] < pivot ) i++; // ищем символ больше чем пивот
        while ( pivot < a[j] ) j--; // ищем символ меньше чем пивот

        if ( i <= j ) 
		{
          temp = a[i]; a[i] = a[j]; a[j] = temp;
          i++; j--;
        }
      } while ( i <= j );

	 // for (int i = 0; i < size; i++)
	 // {
		//cout << a[i] << " ";
	 // }
	 //cout << endl;

      // Сейчас указатель i указывает на начало правого подмассива,
      // j - на конец левого (см. иллюстрацию выше), left ? j ? i ? right.
      // Возможен случай, когда указатель i или j выходит за границу массива

      // Шаги 2, 3. Отправляем большую часть в стек  и двигаем left,right

      if ( i < middle_pos ) {     // правая часть больше

        if ( i < right ) //  если в ней больше 1 элемента - нужно 
		{     
          stackpos++;       //  сортировать, запрос в стек
          left_stack[ stackpos ] = i;
          right_stack[ stackpos ] = right;
        }
        right = j;             //  следующая итерация разделения
                            //  будет работать с левой частью

      } else {       	    // левая часть больше

        if ( j > left ) { 
          stackpos++;
          left_stack[ stackpos ] = left;
          right_stack[ stackpos ] = j;
        }
        left = i;
      }

    } while ( left < right );        // пока в меньшей части более 1 элемента

  } while ( stackpos != 0 );    // пока есть запросы в стеке
}

struct LR
{
	int left;
	int right;
};
          
void quickSort3(vector <int> & mas) 
{

	int size = mas.size();

	int i = 0, j = 0;
	int left = 0, right = 0;

	stack <int> stk;

	stk.push(0);
	stk.push(size-1);

	do
	{
		right = stk.top();
		stk.pop();
		left = stk.top();
		stk.pop();

		i = left;
		j = right;

		int pivot = (left + right) / 2;
		int pivot_value = mas[pivot];

		do
		{
			// найти элемент больше pivot
			while(mas[i] < pivot_value) 
				i++;
			// найти элемент меньше pivot
			while(mas[j] > pivot_value) 
				j--;

			// <= для того чтобы индекс встали на нужные места для вставки их в стек
			if (i <= j)
			{
				swap(mas[i], mas[j]);
				i++;
				j--;
			}
		}
		while(i < j);// <= для того чтобы индекс встали на нужные места для вставки их в стек

		if (i < right)
		{
			stk.push(i);
			stk.push(right);
		}

		if (left < j)
		{
			stk.push(left);
			stk.push(j);
		}

	} while (!stk.empty());
}

void quickSort2(int mas[], int size) 
{

	int i = 0, j = 0;
	int left = 0, right = 0;

	stack <int> stk;

	stk.push(0);
	stk.push(size-1);

	do
	{
		right = stk.top();
		stk.pop();
		left = stk.top();
		stk.pop();

		i = left;
		j = right;

		int pivot = (left + right) / 2;
		int pivot_value = mas[pivot];

		do
		{
			// найти элемент больше pivot
			while(mas[i] < pivot_value) 
				i++;
			// найти элемент меньше pivot
			while(mas[j] > pivot_value) 
				j--;

									cout << endl;
									cout << "i = " << i << " " << " j = " << j << endl;

			// <= для того чтобы индекс встали на нужные места для вставки их в стек
			if (i <= j)
			{
				cout << "swap(mas[i], mas[j]) mas[i] = " << mas[i] << " " << " mas[j] = " << mas[j] << endl;
				swap(mas[i], mas[j]);
				i++;
				j--;
			}

									for(int i = 0; i < size; i++) // внутренний цикл прохода
									{
										cout << mas[i] << " ";
									}
									cout << endl;
		}
		while(i <= j);// <= для того чтобы индекс встали на нужные места для вставки их в стек

		if (i < right)
		{
			stk.push(i);
			stk.push(right);
			cout << "push i = " << i << " " << " right = " << right << endl;
		}

		if (left < j)
		{
			stk.push(left);
			stk.push(j);
			cout << "push left = " << left << " " << " j = " << j << endl;
		}

	} while (!stk.empty());
}

void quickSortVec(vector <int> & mas) 
{

	int size = mas.size();

	int i = 0, j = 0;
	int left = 0, right = 0;

	stack <int> stk;

	stk.push(0);
	stk.push(size-1);

	do
	{
		right = stk.top();
		stk.pop();
		left = stk.top();
		stk.pop();

		i = left;
		j = right;

		int pivot = (left + right) / 2;

		do
		{
			// найти элемент больше pivot
			while(mas[i] < mas[pivot]) 
			{
				i++;
			}
			// найти элемент меньше pivot
			while(mas[j] > mas[pivot]) 
			{
				j--;
			}
			// <= для того чтобы индекс встали на нужные места для вставки их в стек
			if (i <= j)
			{
				swap(mas[i], mas[j]);
				i++;
				j--;
			}

		}
		while(i <= j);// <= для того чтобы индекс встали на нужные места для вставки их в стек

		if (i < right)
		{
			stk.push(i);
			stk.push(right);

		}

		if (left < j)
		{
			stk.push(left);
			stk.push(j);
		}

	} while (!stk.empty());
}








//   i     j
//4, 8, 3, 1
//l  ^     r
//
//   i     j
//4, 1, 3, 8
//l  ^     r

void quickSort(int mas[], int size) 
{
	int i = 0, j = 0;
	int left = 0, right = 0;

	stack <int> stk;

	stk.push(0);
	stk.push(size-1);

	do
	{
		right = stk.top();
		stk.pop();
		left = stk.top();
		stk.pop();

		i = left;
		j = right;

		int pivot = (left + right) / 2;
		int pivot_value = mas[pivot];

		do
		{
			// найти элемент больше pivot
			while(mas[i] < pivot_value) 
			{
				i++;
			}
			// найти элемент меньше pivot
			while(mas[j] > pivot_value) 
			{
				j--;
			}

			// <= для того чтобы индекс встали на нужные места для вставки их в стек
			if (i <= j)
			{
				swap(mas[i], mas[j]);
				i++;
				j--;
			}
		}
		while(i <= j);// <= для того чтобы индекс встали на нужные места для вставки их в стек

		if (i < right)
		{
			stk.push(i);
			stk.push(right);
		}

		if (left < j)
		{
			stk.push(left);
			stk.push(j);
		}

	} while (!stk.empty());
}



























	//cout << endl;
	//cout << i << " " << j << endl;

	//for(int i = 0; i < size; i++) // внутренний цикл прохода
	//{
	//	cout << mas[i] << " ";
	//}
	//} while (true);}

void recur(int n)
{
    //if (n == 1)
    //    return 1;
    //return fact(n-1)*n;

	//if(n == 1)
	//	return 1;
 //   return fact(n-1)*n;


	//for(s = 0; s < 4; s++)
	//{
	//	for(e = 0; e < 4; e++)
	//	{
	//		for(n = 0; n < 4; n++)
	//		{
	//			for(m = 0; m < 4; m++)
	//			{
	//				cout << s << e << n << m << endl;
	//			}
	//		}
	//	}
	//}

}

void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBitmap)
{
    HBITMAP hbm, hOldbm;
    HDC hMemDC;
    BITMAP bm;
    POINT ptSize, ptOrg;

    hMemDC = CreateCompatibleDC(hdc);

    hOldbm = (HBITMAP)SelectObject(hMemDC, hBitmap);

    if (hOldbm)
    {
            SetMapMode(hMemDC, GetMapMode(hdc));

            GetObject(hBitmap, sizeof(BITMAP), (LPSTR) &bm);

            ptSize.x = bm.bmWidth;  // ГёГЁГ°ГЁГ*Г*
            ptSize.y = bm.bmHeight; // ГўГ»Г±Г®ГІГ*

			DPtoLP(hdc, &ptSize, 1);

            ptOrg.x = 0;
            ptOrg.y = 0;

            DPtoLP(hMemDC, &ptOrg, 1);

            BitBlt(hdc, x, y, ptSize.x, ptSize.y,
                    hMemDC, ptOrg.x, ptOrg.y, SRCCOPY);

            SelectObject(hMemDC, hOldbm);
    }

    DeleteDC(hMemDC);
}

int x = 0;
int y = 0;

void print()
{
	HBITMAP hBitmap;
	PAINTSTRUCT ps;    
 
	HWND hwnd = GetConsoleWindow();
	HDC hdc;
	hdc=GetWindowDC(hwnd);
 
    hBitmap = (HBITMAP)LoadImage(NULL, "pica.bmp", IMAGE_BITMAP, 32, 32, LR_LOADFROMFILE);
 
 
    InvalidateRect(hwnd,NULL,TRUE);
 
 
                hdc=BeginPaint(hwnd,&ps);
                DrawBitmap(hdc, x, y ,hBitmap);
                EndPaint(hwnd,&ps);
	x = x + 32;
}

void showPoint(SPoint p)
{
	gotoxy(p.x, p.y);
	cout << '*';
}

void hidePoint(SPoint p)
{
	gotoxy(p.x, p.y);
	cout << ' ';
}

void move(SPoint &p)
{
	switch(p.dir)
	{
	case 0: 
		p.x++; 
		if (p.x > 79)
			p.x = 79;
		break;
	case 1: 
		p.y++; 
		if (p.y > 24)
			p.y = 24;
		break;
	case 2: 
		p.x--; 
		if (p.x < 0)
			p.x = 0;
		break;
	case 3: 
		p.y--; 
		if (p.y < 0)
			p.y = 0;
		break;
	}
}


struct SVolna
{
    int x;
    int y;
    int k;
};


struct MyPoint {float x,y;} O,A; //Наш тип данных
float R=100; //Длина отрезка

void swap (int & a, int & b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

void if_max_min()
{

//****************************************************************************************
// Деление чисел
//****************************************************************************************
	//int a, b;

	//cin >> a >> b;

	//if (a == 0 || b == 0)
	//{
	//	cout << "ERROR";
	//}
	//else if (a >= b)
	//{
	//	cout << a/b;
	//}
	//else
	//{
	//	cout << b/a;
	//}

//****************************************************************************************
// Номер среднего числа
//****************************************************************************************
	//int a, b, c;
	//cin >> a >> b >> c;
	//if      (b <= a && a <= c || c <= a && a <= b)
	//{
	//	cout << 1;
	//}
	//else if (a <= b && b <= c || a <= b && b <= c)
	//{
	//	cout << 2;
	//}
	//else 
	//{
	//	cout << 3;
	//}

//****************************************************************************************
// Хотя бы одна пара
//****************************************************************************************
	//int a, b, c;

	//cin >> a >> b >> c;

	//if (a == b || a == c || b == c)
	//{
	//	cout << 1;
	//}
	//else
	//{
	//	cout << 0;
	//}

//****************************************************************************************
// Сумма двух наибольших
//****************************************************************************************
	//int a, b, c;
	//int x, y, z;
	//cin >> a >> b >> c;
	//x = a + b;
	//y = a + c;
	//z = b + c;
	//if (x >= y && x >= z)
	//{
	//	cout << x;
	//}
	//else if (y >= x && y >= z)
	//{
	//	cout << y;
	//}
	//else if (z >= x && z >= y)
	//{
	//	cout << z;
	//}
}

void string_stroki()
{
//****************************************************************************************
// Максимальная строка
//****************************************************************************************
	//string mas[3] = {"privet", "kak", "dela"};
	//string max_str = mas[0];
	//for (int i = 0; i < 3; i++)
	//{
	//	if (mas[i] > max_str)
	//	{
	//		max_str = mas[i];
	//	}
	//}
	//cout << max_str;

//****************************************************************************************
// число в строку 
//****************************************************************************************

	//int x = 123; // остаток от целочисленного деления
	//int d = 0;
	//string str = "";

	//while (x > 0)
	//{
	//	d = x % 10;
	//	x = x/10;
	//	str = (char)(d+48) + str; 
	//}

	//cout << str << endl;

//****************************************************************************************
// Незначащие нули
//****************************************************************************************
	//int x = 123;
	//string str = to_string(x);
	//int len = str.length();
	//int a = 6;
	//for(int i = 0; i < a - len; i++)
	//{
	//	str = '0' + str;
	//}
	//cout << str;
//****************************************************************************************
// Выделение подстроки
//****************************************************************************************
	//string str1 = "asdfsd";
	//string str2 = "";
	//int a = 3;
	//int b = 5;
	//for(int i = 0; i < b && a+i < str1.length(); i++)
	//{
	//	str2 = str2 + str1[a+i];
	//}
	//cout << str2;
}

void line3(int x0, int y0, int x1, int y1)
{
	POINT op;
	
	HWND hWnd=GetConsoleWindow();//Функция GetConsoleWindow извлекает дескриптор окна, используемый консолью, связанной с вызывающим процессом.
	HDC hDC=GetDC(hWnd);//Функция GetDC извлекает дескриптор дисплейного контекста устройства (DC) для рабочей области заданного окна или для всего экрана.

	SelectObject(hDC,GetStockObject(WHITE_PEN));
	
    bool steep = abs(y1 - y0) > abs(x1 - x0); // Проверяем рост отрезка по оси икс и по оси игрек

    // Меняем систему координат, если угол наклона слишком большой
    if (steep)
    {
        swap(x0, y0); 
        swap(x1, y1);
    }

    // Если линия растёт справа налево, то меняем начало и конец отрезка местами
    if (x0 > x1)
    {
        swap(x0, x1);
        swap(y0, y1);
    }

    int dx = x1 - x0;
    int dy = abs(y1 - y0);

    int error = dx / 2; // Здесь используется оптимизация с умножением на dx, чтобы избавиться от лишних дробей
    int ystep = (y0 < y1) ? 1 : -1; // Выбираем направление роста координаты y
    int y = y0;
    for (int x = x0; x <= x1; x++)
    {
		SetPixel(hDC, x, y, RGB(255, 255, 0));

		error = error - dy;
        if (error < 0)
        {
            y = y + ystep;
            error = error + dx;
        }
    }
	ReleaseDC(hWnd,hDC);
}

void BresenhamLine(int x0, int y0, int x1, int y1)
{
    bool steep = abs(y1 - y0) > abs(x1 - x0); // Проверяем рост отрезка по оси икс и по оси игрек

    // Меняем систему координат, если угол наклона слишком большой
    if (steep)
    {
        swap(x0, y0); 
        swap(x1, y1);
    }

    // Если линия растёт справа налево, то меняем начало и конец отрезка местами
    if (x0 > x1)
    {
        swap(x0, x1);
        swap(y0, y1);
    }

    int dx = x1 - x0;
    int dy = abs(y1 - y0);

    int error = dx / 2; // Здесь используется оптимизация с умножением на dx, чтобы избавиться от лишних дробей
    int ystep = (y0 < y1) ? 1 : -1; // Выбираем направление роста координаты y
    int y = y0;
    for (int x = x0; x <= x1; x++)
    {
        gotoxy(steep ? y : x, steep ? x : y); // Не забываем вернуть координаты на место
		cout << '*';

        error = error - dy;
        if (error < 0)
        {
            y = y + ystep;
            error = error + dx;
        }
    }
}

//void line(int x0, int y0, int x1, int y1)
//{
//	int deltax = abs(x1 - x0);
//	int deltay = abs(y1 - y0);
//	
//	float error = 0;
//	float deltaerr = (float)deltay / deltax;
//	
//	int y = y0;
//	int diry = y1 - y0;
//
//	if (diry > 0)
//		diry = 1;
//	if (diry < 0)
//		diry = -1;
//
//	for (int x = x0; x <= x1; x++)
//	{
//		//gotoxy(x,y);
//		//cout << '*';
//		error = error + deltaerr;
//		cout << error << endl;
//		if (error >= 0.5)
//		{
//			y = y + diry;
//			error = error - 1.0;
//		}
//	}
//}



//вычислить коэффициент
//увеличить у если ошибка >= 0.5
//уменьшит ошибка на -1

//доработка
//если круче растет по y то меняем координаты местами

//куда растёт игрик
//если 


void line(int x0, int y0, int x1, int y1)
{
    bool steep = abs(y1 - y0) > abs(x1 - x0); // Проверяем рост отрезка по оси икс и по оси игрек

    // если по y растет сильнее то меняем систему координат
	// Меняем систему координат, если угол наклона слишком большой
    if (steep)
    {
        swap(x0, y0); 
        swap(x1, y1);
    }

    // Если линия растёт справа налево, то меняем начало и конец отрезка местами
    if (x0 > x1)
    {
        swap(x0, x1);
        swap(y0, y1);
    }

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    float error = 0; 
	float deltaerr = (float)dy / dx;
    int ystep = (y0 < y1) ? 1 : -1; // Выбираем направление роста координаты y
    int y = y0;
    
	for (int x = x0; x <= x1; x++)
    {
        gotoxy(steep ? y : x, steep ? x : y); // Не забываем вернуть координаты на место
		cout << '*';

		error = error + deltaerr;
		if (error >= 0.5)
        {
            y = y + ystep;
			error = error - 1.0;
        }

    }
}

/*Функция поворота отрезка*/
void rotate(float x0, float y0, float &x1, float &y1, float angle, int dir = 1)
{
	float dx=x1; //Запоминаем для следующих вычислений
	float dy=y1; //Запоминаем для следующих вычислений

	if (dir == 1) // по часовой стрелке
	{
		x1=x0+(dx-x0)*cos(angle*M_PI/180)-(dy-y0)*sin(angle*M_PI/180); //Поворот на angle градусов
		y1=y0+(dx-x0)*sin(angle*M_PI/180)+(dy-y0)*cos(angle*M_PI/180); //Поворот на angle градусов
	}
	else  // против часовой стрелке
	{
		x1=x0+(dx-x0)*cos(angle*M_PI/180)+(dy-y0)*sin(angle*M_PI/180); //Поворот на angle градусов
		y1=y0-(dx-x0)*sin(angle*M_PI/180)+(dy-y0)*cos(angle*M_PI/180); //Поворот на angle градусов
	}

	//BresenhamLine(x0,y0,x1,y1); //Выводим повернутую линию
	line(x0,y0,x1,y1); //Выводим повернутую линию
}

/*Функция поворота отрезка*/
void scale(float x0, float y0, float &x1, float &y1, float a, float b)
{
	//float dx=x1; //Запоминаем для следующих вычислений
	//float dy=y1; //Запоминаем для следующих вычислений

	x1=x1*a; //Поворот на angle градусов
	y1=y1*b; //Поворот на angle градусов

	BresenhamLine(x0,y0,x1,y1); //Выводим повернутую линию
}


int my_function(int *arr,int len, bool(*fn)(int,int))
{
    int res = arr[0];
 
    for(int i = 1; i < len; ++i)
        if(fn(res,arr[i]))
            res = arr[i];
 
    return res;
}
 
bool max_(int i, int j) 
{ 
	return i < j; 
}

bool min_(int i, int j) 
{ 
	return i > j; 
}

int min2(int i, int j) 
{ 
	if ( i >= j)
		return i;
	else
		return j;
}

//int sss = 0;
//
//void func1()
//{
//	sss++;
//	cout << sss << endl;
//	func1();
//}

void func3()
{
	cout << "Privet" << endl;
}

void func2()
{
	func3();
}

void func1()
{
	func2();
}



CRITICAL_SECTION cs;
int xxx = 7;
void Thread1( void* pParams )
{ 
	//int i, num = 0;

	//while ( 1 )
	//{ 
	//   for ( i = 0; i < 5; i++ ) 
	//	   a[ i ] = num;
	//   num++;
	//}

	int x = 0;
	int y = *((int *)pParams);
	while ( 1 )
	{
		//EnterCriticalSection( &cs );		
			//xxx = ;//rand() % 10;
			//gotoxy(0,y);
			//cout << "   ";
			gotoxy(0,y);
			cout << x;
			x++;
			Sleep(100);
		//LeaveCriticalSection( &cs );
		//Sleep(1);
	}
}

void Thread2( void* pParams )
{ 
	//int i, num = 0;

	//while ( 1 )
	//{ 
	//   for ( i = 0; i < 5; i++ ) 
	//	   a[ i ] = num;
	//   num++;
	//}

	static int y = 10;
	while ( 1 )
	{
		gotoxy(5,2);
		cout << y;
		y++;
		Sleep(500);
	}
}

string str;

void Thread3( void* pParams )
{ 

	int y = 10;
	while ( 1 )
	{
		Sleep(5000);

		if (!str.empty())
		{
			cout << str << endl;
		}
		else
		{
			cout << "no" << endl;
		}

	}
}

// Класс нашего умного указателя
template <typename T>
class smart_pointer 
{
    T *m_obj;
public:
    // Отдаем ему во владение некий объект
    smart_pointer(T *obj) : m_obj(obj)
    { }
    // По выходу из области видимости этот объект мы уничтожим
    ~smart_pointer() {
        delete m_obj;
    }
    // Перегруженные операторы<
    // Селектор. Позволяет обращаться к данным типа T посредством "стрелочки"
    T* operator->() { return m_obj; }
    // С помощью такого оператора мы можем разыменовать указатель и получить ссылку на
    // объект, который он хранит
    T& operator* () { return *m_obj; }
};

void loging(ofstream & f, string str)
{
	f << str;
}


//void show_ptr(int *p)// передача указателя по значению 
void show_ptr(int *&p)// передача указателя по ссылке
{
	cout << p;
	p++;
}

//const void show_tower(const vector <int> * tower)
//{
//	cout << ">>> ";
//
//	for (int i = 0; i < (*tower).size(); i++) 
//	{
//		cout << (*tower)[i] << " ";
//	}
//	cout << endl;
//}

void show_tower(vector <int> tower)
{
	cout << ">>> ";

	for (int i = 0; i < tower.size(); i++) 
	{
		cout << tower[i] << " ";
	}
	cout << endl;
}

bool moveDisk(vector <int> &tower1, vector <int> &tower2, int disk1,int disk2)
{
	bool res = true;

	if (disk1 == 100)
	{
		res = false;
	}
	else if (disk2 == 100)
	{
		tower1.pop_back();
		tower2.push_back(disk1);
	} 
	else if (disk1 < disk2)
	{
		tower1.pop_back();
		tower2.push_back(disk1);
	}
	else
	{
		res = false;
	}
	return res;
}

template <typename T>
class CTasks
{
public:
	vector <T> vec; // создаём пустой вектор типа int
	void push(T p)
	{
		vec.push_back(p); //добавление элемента в конец вектора
	}
	
	bool empty()
	{
		return vec.empty();		
	}

	void show()
	{
		for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
		{
			cout << vec[i] << endl;
		}
	}

	void work()
	{
		for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
		{

			cout << vec[i] << endl;

			// пока задание активно делаем действие
			if (vec[i] > 0)
			{
				vec[i]--;
			}

			else
			{
				// оптимизация удаления отработавщих заданий
				// если в векторе не менее двух элементов обмениваем местами текущий с последним
				if (vec.size()>=2)
				{
					int t = 0;
					t = vec[i];
					vec[i] = vec[vec.size() - 1];
					vec[vec.size() - 1] = t;
				}
			}

			//if (vec.empty())
			//	break;

			// удаление нулевых значений
			while (vec[vec.size() - 1] == 0)
			{
				vec.pop_back();
				if (vec.empty())
					break;
			}

			if (vec.empty())
				break; 

		}
	}
};


double diff_date(string d2,string d1)
{
	time_t now;

	struct tm data1 = {0}, data2 = {0};
	double seconds;

	time(&now);  /* get current time; same as: now = time(NULL)  */

	data1 = *localtime(&now);

	data1.tm_hour = 0; 
	data1.tm_min = 0; 
	data1.tm_sec = 0;

	data1.tm_year = atoi(d1.substr(6,4).c_str()) - 1900;
	data1.tm_mon = atoi(d1.substr(3,2).c_str());
	data1.tm_mday = atoi(d1.substr(0,2).c_str());

	data2.tm_hour = 0; 
	data2.tm_min = 0; 
	data2.tm_sec = 0;

	data2.tm_year = atoi(d2.substr(6,4).c_str()) - 1900;
	data2.tm_mon = atoi(d2.substr(3,2).c_str());
	data2.tm_mday = atoi(d2.substr(0,2).c_str());

	return difftime(mktime(&data2),mktime(&data1))/3600/24;
}


class A //интерфейс (протокол) класса A
{
	//открытая область данных
	public:
	A()
	{ //конструктор по умолчанию
		cout<<"Constructor A\n";
		//конструктор отработал
	}
	//функция-член FriendToB() будет использоваться как дружественная функция для класса B
	void FriendToB();
	void SomeFunction();
}; 

class B //интерфейс (протокол) класса B
{
//область закрытых данных
private:
	int i,j; //наши "подопытные" закрытые переменные;
	//если сможем обратиться к этим переменным
	//из дружественной функии FriendToB(), то "опыт удался"

//область открытых данных
public:
	B()
	{
		i=10; //произведем инициализацию
		j=17; 
		cout<<"Constructor B\n";
		//конструктор отработал
	}
	//укажем, что класс B имеет дружественную функцию, которая 
	//является функцией-членом класса A
	friend void A::FriendToB();
};

class C //интерфейс (протокол) класса C
{
//область закрытых данных
private:
	int k,n; //закрытые
//область открытых данных
public:
	C()
	{
		k=4; //начальная инициализация
		n=7;
		cout<<"\n\nConstructor C\n";
		//конструктор отработал
	}
	//укажем что ВСЕ функции-члены класса A, являются
	//дружественными для даного класса
	friend class A;
};

//действительно ли может функция-член одного
//класса обращаться к закрытым данным другого 
//класса. Давайте проверим!
void A::FriendToB()
{
	B example; //объявим экземпляр класса B
	cout<<"So, variables' value are:\n";
	//и произведем доступ к закрытым данным
	cout<<"example.i="<<example.i;
	cout<<"\nexample.j="<<example.j<<endl;
}


// все функции-члены класса A станут дружественными функциями для класса С
// данная функция имеет доступ к приватным переменным класса С

void A::SomeFunction()
{
	C temp; //объявим экземпляр класса С
	cout<<"And now we are testing friend class...\n";
	//и произведем доступ к закрытым данным
	cout<<"temp.k="<<temp.k;
	cout<<"\ntemp.n="<<temp.n<<endl;
}


class MyString
{
private:

	char * s;
	int len;

public:

	MyString():len(0)
	{
		s = new char[1];
		s[0] = 0;
	}

	// конструктор копирования
	MyString(const MyString &obj)
	{      
		//s = new char[len + 1];
		len = strlen(obj.s);
		s = new char[len + 1];
		strcpy(s,obj.s);
	}

	int length() const
	{
		return len;
	}

	MyString(int n)
	{
		s = new char[n+1];
		len = n;
	}

	void assign(const char * st)
	{
		delete [] s;
		len = strlen(st);
		s = new char[len + 1];
		strcpy(s,st);
	}

	friend ostream & operator<<(ostream & os, const MyString & str)
	{
		os << str.s;
		return os;
	}

	friend MyString /*&*/ operator + (const MyString & str1, const MyString & str2)
	{
		MyString * tmp = new MyString(str1.len + str2.len);

		strcpy(tmp->s,str1.s);
		strcat(tmp->s,str2.s);

		return * tmp;
	}

	//MyString /*&*/ operator + (const MyString & str2)
	//{
	//	MyString * tmp = new MyString(this->len + str2.len);

	//	strcpy(tmp->s,s);
	//	strcat(tmp->s,str2.s);

	//	return * tmp;
	//}

	//friend void operator << (ostream & os, const MyString & str)
	//{
	//	os << str.s;
	//}

	char & operator[](int n) 
	{
		return s[n];
	}

	MyString & operator = (const MyString &obj)
	{
		cout << "MyString & operator = " << endl;
		delete [] s;
		len = strlen(obj.s);
		s = new char[len + 1];
		strcpy(s,obj.s);
		return * this;
	}

	MyString & operator = (const char * st)
	{
		delete [] s;
		len = strlen(st);
		s = new char[len + 1];
		strcpy(s,st);
		return * this;
	}

	~MyString()
	{
		delete [] s;
	}
};

void any_func(MyString s)
{
	s;
}

MyString any_func()
{
	MyString s;
	s.assign("123");
	return s;
}

//ostream & operator << (ostream & os, const MyString & str)


class CAny
{
private:
    int x;
public:
    CAny(int p_x): x(p_x)
    {
    }
    void set_x(int p_x)
    {
		if (p_x >= 0)
		{
			x = p_x;
		}
		else
		{
			cout << "error" << endl;
		}


    }
    int get_x() const
    {
        cout << "произошел запрос к х" << endl;
		return x;
    }
};
 
// устанавливает цвет текста и фона в консоли
void setColor(int background, int text)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


string get_full_path()
{
	char path[260];
	GetModuleFileNameA(NULL, path, sizeof(path) / sizeof(path[0]));
	string str = path;

	string str2;
	int i = 0;
	for (i = str.size() - 1; i >= 0; i--) 
	{
		if (str[i] == '\\')
		{
			break;
		}
	}
	str2 = str.substr(0,i+1);


	return str2;
}

void puterror(char * str)
{
  fprintf(stderr, str);
  getch();
  exit(1);
}

void addd(char s[10])
{
	s[strlen(s)] = '4'; 
	s[strlen(s)] = 0;	 
}

// Базовый класс
class Base 
{
  public:
    Base() { cout << "Base::ctor()" << endl; }
    ~Base() { cout << "Base::dtor()" << endl; } 
    virtual void print() = 0;
};

// Вспомогательный класс
class Object  
{
  int * x;
  public:
    Object() 
	{ 
		cout << "Object::ctor()" << endl; 
		x = new int;

	}
   ~Object() 
   { 
	   cout << "Object::dtor()" << endl; 
	   delete x;
   }
};
 
// Производный класс
class Derived: public Base 
{
  int * x;
  public:
    Derived() { 
		cout << "Derived::ctor()" << endl; 
		x = new int;
	}
   ~Derived() { 
	   cout << "Derived::dtor()" << endl; 
	   delete x;
   }    
    void print() {}   
    Object  obj;
};


class SomeClass
{  
	public:

    int *x; // указатель на какой-либо участок памяти
 
	SomeClass() //  конструктор
	{
		x = new int;
		cout << "\nОбычный конструктор\n";
	}
	SomeClass(const SomeClass &obj)
	{      
		x = new int;
		*x = *obj.x;
		cout << "\nКонструктор копирования\n";
	}
	~SomeClass()   
	{
		delete x;
		cout << "\nДестркуктор\n";
	}
};

void funcShow(const SomeClass & object)
{
    //cout << "\nФункция принимает объект, как параметр\n";
}

SomeClass funcReturnObject()
{  
    SomeClass object;      
    //cout <<   "\nФункция возвращает объект\n";
    return object;
}

void threadFunction()
{
	cout << "поток";
}

enum KIND_HERO  
{
	WARR, MAG, ANCH
};

enum KIND_ARTEF  
{
	PUSTO = 0,
	MECH = 1, 
	LUK = 2, 
	POSOH = 3
};

struct SPlayer
{
	int x, y;

	int atack;
	int shild;
	int chanceHit;
	int hp;

	string name;
	int level;
	KIND_ARTEF artef[10];
	KIND_HERO kind;
	void show()
	{
		gotoxy(x,y);
		cout << '*';
	}
};

bool kick(SPlayer & p1, SPlayer & p2)
{
	int chanceHit = rand(1,100);
	cout << "(p = " << chanceHit << "%) ";

	if (chanceHit > p1.chanceHit)
	{
		p2.hp = p2.hp - p1.atack + p2.shild;
		return 1;
	}
	else
	{
		return 0;
	}
}

const void atack(const SPlayer & p1,const SPlayer & p2)
{
	if (p1.x+1 == p2.x)
	{
		cout << "Попал";
	}
}

void swap(string & s, int a, int b)
{
	char ch;
	ch = s[a];
	s[a] = s[b];
	s[b] = ch;
}

class AAA
{
public:
	int x,y;
	virtual void show()
	{
		cout << "AAA";
	};
};

class BBB : public AAA
{

public:

	int b;

	void show()
	{
		cout << "BBB";
	}
};

class CCC : public AAA
{
public:
	int c;
	void show()
	{
		cout << "CCC";
	}
};

int option (int a, int b, int c)
{

switch(c)
 {
    case 0:
		a = a + b;
	break;
	case 1:
		a = a - b;
	break;
	case 2:
		a = a * b;
	break;
	
 }	
return a;

}



class CMenu
{
	private:

	public:

		int x,y;
		int color;
		int select_item;
		int count_items;
		string * items;

		CMenu(int n)
		{
			select_item = 0;
			items = new string [n];
			count_items = 0;
		};

		~CMenu()
		{
			delete [] items;
		};

		void add(string str)
		{
			items[count_items] = str;		
			count_items++;
		}

		void show()
		{
			int lx = x;
			int ly = y;
			for(int i=0; i < count_items; i++)
			{
				gotoxy(lx,ly);
				cout << items[i];
				cout << endl;
				ly++;
			}
			gotoxy(x,y + select_item);
		}

		void prev()
		{
			if (select_item > 0)
				select_item--;
			gotoxy(x,y + select_item);
		}

		void next()
		{
			if (select_item < count_items-1)
				select_item++;
			gotoxy(x,y + select_item);
		}
};



string addNull(int x, int count)
{
	string str = to_string(x);
	int len = str.length();
	for(int i = 0; i < count - len; i++)
	{
		str = '0' + str;
	}
	return str;
}

//struct SNode //Структура с инфополями и адресным полем
//{
//	int val; //Инфополе. значения из x будут передаваться в список
//	SNode *next; //Адресное поле
//};

struct SNode //Структура с инфополями и адресным полем
{
	int val; //Инфополе. значения из x будут передаваться в список
	SNode *next; //Адресное поле
	SNode *pred; //Адресное поле
};

SNode * node = NULL;
SNode * head = NULL;
SNode * tail = NULL;

void add_node(int val)
{
	if (node == NULL)
	{
		node = new SNode();
		node->next = NULL;
		node->val = val;
		//first = node;
	}
	else 
	{
		SNode * temp = new SNode();
		temp->next = node;
		temp->val = val;
		node = temp;
	}
}

string delSigns(string str)
{
	string str2;
	for (int i = 0; i < str.length(); i++)
	{
		if (   str[i] == '!'
			|| str[i] == '*'
			|| str[i] == '?'
			|| str[i] == '#'
			|| str[i] == '\\'
			|| str[i] == '/'
			|| str[i] == ':'
			|| str[i] == '='
			|| str[i] == '<'
			|| str[i] == '>'
			)
		{
			continue;
		}
		else
		{
			str2 += str[i];
		}
	}
	return str2;
}

void add_node2(int val)
{
	if (node == NULL)
	{
		node = new SNode();
		node->next = NULL;
		node->val = val;
		head = node;
		//first = node;
	}
	else 
	{
		SNode * temp = new SNode();
		temp->next = node;
		temp->pred = NULL;
		node->pred = temp;
		temp->val = val;
		node = temp;
		tail = node;
	}
}

void print_list()
{
	//node = first;
	while (node->next != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << node->val << " ";
}

void print_list2()
{
	//node = tail;
	//while (node->next != NULL)
	//{
	//	cout << node->val << " ";
	//	node = node->next;
	//}
	//cout << node->val << " ";	
	
	node = head;
	while (node->pred != NULL)
	{
		cout << node->val << " ";
		node = node->pred;
	}
	cout << node->val << " ";
}

//****************************************************************************************
// Двусвязный двунаправленный список очередь
//****************************************************************************************
 
//template <typename T>
//class CList   //Создаем тип данных Список
//{
//	Node <T> *head; //Указатели на адреса начала списка и его конца
//	Node <T> *tail; //Указатели на адреса начала списка и его конца
//	Node <T> *top; //Указатели на адреса начала списка и его конца
//	int size;
//
//public:
//	CList():head(NULL),tail(NULL), top(NULL), size(0){}; //Инициализируем адреса как пустые
//
//	CList(int n):head(NULL),tail(NULL)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			add((T)0);
//			size++;
//		}
//	}; //Инициализируем адреса как пустые
//
//	void pop() 
//	{
//		if (size < 1) {
//			return;
//		}
//		Node <T> *temp = tail->prev;
//		delete tail;
//		top = nextTop;
//		size--;
//	}
//
//	void add(T x)
//	{
//	   Node <T> *temp=new Node <T>; //Выделение памяти под новый элемент структуры
//	   temp->next = NULL;  //Указываем, что изначально по следующему адресу пусто
//	   temp->x=x;//Записываем значение в структуру
//	 
//	   if (head!=NULL) //Если список не пуст
//	   {
//		   temp->prev=tail; //Указываем адрес на предыдущий элемент в соотв. поле
//		   tail->next=temp; //Указываем адрес следующего за хвостом элемента
//		   tail=temp; //Меняем адрес хвоста
//	   }
//	   else //Если список пустой
//	   {
//		   temp->prev=NULL; //Предыдущий элемент указывает в пустоту
//		   head=tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
//	   }
//       size++;
//
//	}
//
//
//	//int size()
//	//{
//	//	Node <T> *temp=tail;
//	//	int s = 0;
//	//	while (temp!=NULL) //Пока не встретится пустое значение
//	//	{
//	//		s++;
//	//		temp=temp->prev; //Указываем, что нужен адрес предыдущего элемента
//	//	}
//	//	return s;
//	//}
//
//	CList & operator = (const CList &obj)
//	{
//		//head = NULL;
//		//tail = NULL;
//
//		Node <T> *temp = obj.tail;
//
//		while (temp != NULL) //Пока не встретится пустое значение
//		{
//			add(temp->x);
//			temp = temp->prev;
//
//		}
//
//		return * this;
//	}
//
//	//перегрузка через метод
//	CList & operator + (CList list2)
//	{
//		Node <T> *temp2 = list2.tail;
//		Node <T> *temp1 = tail;
//
//		while (temp2 != NULL) //Пока не встретится пустое значение
//		{
//			temp1->x = temp1->x + temp2->x;
//
//			temp1 = temp1->prev;
//			temp2 = temp2->prev;
//
//
//		}
//
//		return * this;
//	}
//	~CList() //Деструктор
//	{   
//		while (head) //Пока по адресу на начало списка что-то есть
//		{
//			tail=head->next; //Резервная копия адреса следующего звена списка
//			delete head; //Очистка памяти от первого звена
//			head = tail; //Смена адреса начала на адрес следующего элемента
//		}
//	}
//
//	 void show()
//	 {
//	//ВЫВОДИМ СПИСОК С КОНЦА
//		 Node <T> *temp=tail;
//		  //Временный указатель на адрес последнего элемента
//		 while (temp!=NULL) //Пока не встретится пустое значение
//		 {
//			 cout<<temp->x<<" "; //Выводить значение на экран
//			 temp=temp->prev; //Указываем, что нужен адрес предыдущего элемента
//		 }
//		 cout<<"\n";
//	 
//	 ////ВЫВОДИМ СПИСОК С НАЧАЛА
//	 //    temp=head; //Временно указываем на адрес первого элемента
//	 //     while (temp!=NULL) //Пока не встретим пустое значение
//	 //    {
//		// cout<<temp->x<<" "; //Выводим каждое считанное значение на экран
//		// temp=temp->next; //Смена адреса на адрес следующего элемента
//	 //    }
//	 //    cout<<"\n";
//	 }
//};
 

template <typename T>
struct Node//Структура являющаяся звеном списка
{
	T x;//Значение x будет передаваться в список
	Node *next,*prev; //Указатели на адреса следующего и предыдущего элементов списка
};


template <typename T>
class CStack   //Создаем тип данных Список
{
	Node <T> *top; //Указатели на адреса начала списка и его конца
	int size;

public:
	CStack(): top(NULL), size(0){}; //Инициализируем адреса как пустые

	//CStack(int n)
	//{
	//	for (int i = 0; i < n; i++)
	//	{
	//		add((T)0);
	//		size++;
	//	}
	//}; //Инициализируем адреса как пустые

	void pop() 
	{
		if (size < 1) {
			return;
		}
		Node <T> *temp = top->next;
		delete top;
		top = temp;
		size--;
	}

	void add(T x)
	{
	   Node <T> *temp=new Node <T>; //Выделение памяти под новый элемент структуры
	   temp->next = NULL;  //Указываем, что изначально по следующему адресу пусто
	   temp->x = x;//Записываем значение в структуру
	 
	   if (top != NULL) //Если список не пуст
	   {
		   temp->next = top; //Указываем адрес на предыдущий элемент в соотв. поле
		   //tail->next=temp; //Указываем адрес следующего за хвостом элемента
		   top=temp; //Меняем адрес хвоста
	   }
	   else //Если список пустой
	   {
		   temp->next = NULL; //Предыдущий элемент указывает в пустоту
		   top = temp; //Голова=Хвост=тот элемент, что сейчас добавили
	   }
       size++;
	}


	// копирование стека в обратном порядке
	void copyFrom(const CStack &other) 
	{
		// условие для предотвращения копирования самого себя
		if (&other != this) 
		{
			// очистка текущего стека
			clear();

			// указывает на последний добавленный элемент новго стека
			Node <T> *last = NULL;     
			// для перемещения по внешнему стеку
			Node <T> *temp = other.top;

			while( temp != NULL) 
			{
				size++;
				// создаём и заполняем новый элеент
				Node <T> * node = new Node <T>;
				node->x = temp->x;

				// если в стеке уже есть элементы
				if (last != 0) 
				{
					// следующий из последнего указать на новый
					last->next = node;
				} 
				else 
				{
					// вершину указать на новый элемент
					// top уже больше не трогать.
					top = node;
				}
				// последний указать на очередной добавленный
				last = node;
				//
				temp = temp->next;
			}
			last->next = NULL;
		}
	}

	void clear() 
	{
		while (size != 0) {
			pop();
		}
	}

	CStack &operator=( CStack &other) 
	{
		copyFrom(other);
		return *this;
	}

	//перегрузка через метод
	CStack & operator + (CStack list2)
	{
		Node <T> *temp2 = list2.top;
		Node <T> *temp1 = top;

		while (temp2 != NULL) //Пока не встретится пустое значение
		{
			temp1->x = temp1->x + temp2->x;

			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return * this;
	}

	~CStack() //Деструктор
	{   
		while (head) //Пока по адресу на начало списка что-то есть
		{
			tail=head->next; //Резервная копия адреса следующего звена списка
			delete head; //Очистка памяти от первого звена
			head = tail; //Смена адреса начала на адрес следующего элемента
		}
	}

	 void show()
	 {
	//ВЫВОДИМ СПИСОК С КОНЦА
		 Node <T> *temp=top;
		  //Временный указатель на адрес последнего элемента
		 while (temp!=NULL) //Пока не встретится пустое значение
		 {
			 cout << temp->x << " "; //Выводить значение на экран
			 temp=temp->next; //Указываем, что нужен адрес предыдущего элемента
		 }
		 cout<<"\n";
	 
	 ////ВЫВОДИМ СПИСОК С НАЧАЛА
	 //    temp=head; //Временно указываем на адрес первого элемента
	 //     while (temp!=NULL) //Пока не встретим пустое значение
	 //    {
		// cout<<temp->x<<" "; //Выводим каждое считанное значение на экран
		// temp=temp->next; //Смена адреса на адрес следующего элемента
	 //    }
	 //    cout<<"\n";
	 }
};


 

void show(int * m) 
{
	for (int i = 0; i < 5; i++)
	{
		cout << m[i] << " ";
	}
}

void show2(int m[]) 
{
	for (int i = 0; i < 5; i++)
	{
		cout << m[i] << " ";
	}
}

void show3(int m[5]) 
{
	for (int i = 0; i < 5; i++)
	{
		cout << m[i] << " ";
	}
}



// возвращает очередной символ, считанный с клавиатуры, но не выводит этот символ на экран
int getch1()
{
	int ch = _getch();
	if (ch == 224)
		ch = _getch();
	return ch;
}

int * form (int & n)
{
	cin >> n;
	int * a = new int[n];
    for (int i = 0; i < n; i++)
	{
            a[i] = rand() % 10;

	}

	return a;
}


void print (int * a, int n)
{

    for (int i = 0; i < n; i++)
	{
            cout << a[i] << " ";

	}

}



template <typename T>
void x_x(T x)
{
	cout << x*x;
} 


//template < class T >
//class CList
//{
//public:
//	void show( const T & Element )
//	{
//		cout << Element;
//	};
// 
//};

struct SHero
{
public:
	int x;
	int y;
	int hp;
    int level;  
    float weight;  
	KIND_HERO kind;
    string name;
	int artef[5];
	SHero() : x(5), y(5){}
	// списки инициализации, список инициализации
	SHero(int x, int y) : x(x), y(y){}
};


void show(SHero & h)
{
	cout << h.name << endl;
	cout << h.hp << endl;
}

 //---------------------------------------------------------------------------
static size_t write_data(char *ptr, size_t size, size_t nmemb, char* data)
{
    if(data==NULL || wr_index + size*nmemb > BUF_SIZE) 
		return 0; // Если выход за размеры буфера - ошибка
 
    memcpy( &data[wr_index], ptr, size*nmemb);// дописываем данные в конец
    wr_index+= size*nmemb;  // изменяем  текущее положение
 
    return size*nmemb;
}

HPEN getPen(int iPEN_STYLE, int iPEN_SIZE, int iCOLORREF)
{
        return CreatePen(iPEN_STYLE, iPEN_SIZE, iCOLORREF);
}
 
BOOL SetPoint(HDC hDC, HPEN hPen, COORD PNT)
{
        EXTLOGPEN pINFO;
        GetObject(hPen,sizeof(EXTLOGPEN),&pINFO);
        SelectObject(hDC,hPen);
        return Ellipse
        (
                hDC,
                PNT.X - pINFO.elpWidth,
                PNT.Y + pINFO.elpWidth, 
                PNT.X + pINFO.elpWidth,
                PNT.Y - pINFO.elpWidth
        );
}
 
BOOL PlotLine(HDC hDC, HPEN hPen, COORD BGN, COORD END)
{
        SelectObject(hDC,hPen);
        MoveToEx(hDC,BGN.X,BGN.Y,NULL);
        return LineTo(  hDC,END.X,END.Y);
}
 
BOOL PlotRect(HDC hDC, HPEN hPen, COORD BGN, COORD END)
{
    SelectObject(hDC,hPen);
    return Rectangle(hDC,BGN.X, BGN.Y, END.X, END.Y);
}
 
BOOL  PlotCirc(HDC hDC, HPEN hPen, COORD BGN, COORD END)
{
    SelectObject(hDC,hPen);
    return Ellipse(hDC,BGN.X, BGN.Y, END.X, END.Y);
}
 
COORD setCordScale(COORD POS, RECT pRECT)
{
        if(POS.X == 0)
                POS.X = 1;
        if(POS.Y == 0)
                POS.Y = 1;
 
        int nROWS = 25;
        int nCOLS = 80;
 
        double CX = (pRECT.right - pRECT.left)/nCOLS;
        double CY = (pRECT.bottom - pRECT.top)/nROWS;
 
        //ГЏГ°ГЁ ГІГҐГЄГ±ГІГ®ГўГ®Г¬ Г°ГҐГ¦ГЁГ¬ГҐ(text mode) ГЅГЄГ°Г*Г*  Г¤ГҐГ«ГЁГІГ±Гї  Г*Г*  ГїГ·ГҐГ©ГЄГЁ
    //(80  ГЁГ«ГЁ 40 ГЄГ®Г«Г®Г*Г®ГЄ Гў ГёГЁГ°ГЁГ*Гі ГЁ 25 Г±ГІГ°Г®ГЄ Гў ГўГ»Г±Г®ГІГі)
        POS.X *= CX;
        POS.Y *= CY;
 
        int xBORDER = GetSystemMetrics(SM_CXBORDER);//ГГЁГ°ГЁГ*Г* ГЈГ°Г*Г*ГЁГ¶Г» Г®ГЄГ*Г*
        int yBORDER = GetSystemMetrics(SM_CYMENU);  //Г‚Г»Г±Г®ГІГ* Г§Г*ГЈГ®Г«Г®ГўГЄГ* Г®ГЄГ*Г* ~= ГўГ»Г±Г®ГІГҐ Г±ГІГ°Г®ГЄ Г¬ГҐГ*Гѕ
        int xDRAG       = GetSystemMetrics(SM_CXDRAG);  //Г—ГЁГ±Г«Г® ГЇГЁГЄГ±ГҐГ«ГҐГ© Г*Г* ГЈГ®Г°ГЁГ§ Г¤Г°Г®Г¦ГҐГ*ГЁГҐ Г¬Г»ГёГЁ
        int yDRAG       = GetSystemMetrics(SM_CYDRAG);  //Г—ГЁГ±Г«Г® ГЇГЁГЄГ±ГҐГ«ГҐГ© Г*Г* ГўГҐГ°ГІГЁГЄ Г¤Г°Г®Г¦ГҐГ*ГЁГҐ Г¬Г»ГёГЁ
 
        POS.X += xBORDER + xDRAG;//ГГЁГ°ГЁГ*Г* ГЈГ°Г*Г*ГЁГ¶Г» Г®ГЄГ*Г* + Г·ГЁГ±Г«Г® ГЇГЁГЄГ±ГҐГ«ГҐГ© Г*Г* Г¤Г°Г®Г¦ГҐГ*ГЁГҐ Г¬Г»ГёГЁ
        POS.Y += yBORDER + yDRAG;
        return POS;
}

const int   arabar[]  = {  1,   4,    5,   9,    10,  40,  50,   90,  100, 400,  500, 900,  1000};
const char *romanar[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
 
char * arab2roman(unsigned short int arab) 
{
    static char roman[80];

	int xxx = sizeof(arabar);
	int xx = sizeof(int);

    const int m = sizeof(arabar)/sizeof(int)-1, arabmax=arabar[m];
    const char romanmax=romanar[m][0];
    int i, n;
    if(!arab) {
		*roman=0;
		return roman;
    }
    i=0;
    while(arab>arabmax) {
		roman[i++] = romanmax;
		arab      -= arabmax;
    }
    n=m;
    while(arab > 0) {
		if(arab >= arabar[n]) {
			roman[i++] = romanar[n][0];
			// если число нечётное, добавить ещё один символ
			if(n&1)
				roman[i++] = romanar[n][1];
			arab -= arabar[n];
		} else
				n--;
    }
    roman[i]=0;
    return roman;
}

unsigned short int roman2arab(char *roman) 
{
        const int m = sizeof(arabar)/sizeof(int)-1;
        unsigned short int arab;
        int len, n, i, pir;
        len=strlen(roman);

        arab=0;
        n=m;
        i=0;
        while(n >= 0 && i < len) {
                pir=n&1;
                if(roman[i] == romanar[n][0] && (!pir || roman[i+1] == romanar[n][1])) {
                        arab += arabar[n];
                        i    += 1+pir;
                } else
                        n--;
        }
        return arab;
}

// передача массива по ссылке
void del_space(char * str1)
{

	//char str1[] = "привет как дела?";	// для сохранения строки
	//char str2[128] = "";	// для сохранения строки
	
	//cout << "Введите текст латиницей (не больше 128 символов):\n";
	//cin.getline(ourStr, 128);
 
	int p1 = 0;	// счетчик символов
	int p2 = 0;	// счетчик символов

	while (str1[p1] != '\0')
	{
		if (str1[p1] == ' ')
		{
			str1[p1] = '*';
		}
		p1++;
	}
}
// возведение в квадрат, передача параметра по ссылке
void x_x1(int & x)
{
	x = x * x;
}

void byVal(int x)
{
	x = 5;
}

void byRef(int &x)
{
	x = 5;
}

// возведение в квадрат, передача параметра по значению
void x_x2(int & x)
{
	x = x * x;
}

void x_x3(int * x) //передаём указатель
{
   *x = (*x) * (*x); // указатель необходимо разыменовывать,
   // чтобы получить доступ к значению переменной
}

void print_arr(double **A, int N)
{ 
	cout << endl;
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout.width(5);
			cout << A[i][j];
		}
		cout << endl;
	}
	//getch();
}


int matrix_treygoln_vid(double **M, int N)
{
	int i,j,k;
	double temp;

	for (k = 0; k < N; k++) 
	{
		for (i = k+1; i < N; i++) 
		{
			temp = M[i][k] / M[k][k];

			for (j = 0; j < N; j++) 
			{
				M[i][j] = M[i][j] - temp * M[k][j];
			}
		}
	}
	
	int det = 1;
    
	for (i = 0; i < N; i++)
    {
        det = det*M[i][i];
	}
	
	return det;
}



void inversion(double **A, int N)
{
    double temp;
 
	// выделение динамической памяти под двумерный динамический массив
    double **E = new double* [N];
 
    for (int i = 0; i < N; i++)
        E[i] = new double [N];
 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            E[i][j] = 0.0;
 
            if (i == j)
                E[i][j] = 1.0;
        }
 
    for (int k = 0; k < N; k++)
    {
        temp = A[k][k];
 
        for (int j = 0; j < N; j++)
        {
            A[k][j] = A[k][j] / temp;
            E[k][j] = E[k][j] / temp;

			print_arr(A, N);

		}
 

        for (int i = k + 1; i < N; i++)
        {
            temp = A[i][k];
 
            for (int j = 0; j < N; j++)
            {
                A[i][j] = A[i][j] - A[k][j] * temp;
                E[i][j] = E[i][j] - E[k][j] * temp;

				print_arr(A, N);
            }
        }
    }
 
	cout << "------------------";

    for (int j = N - 1; j > 0; j--)
    {

        for (int i = j - 1; i >= 0; i--)
        {
			double temp = A[i][j];

            for (int k = N-1; k >= 0; k--)
            {

                A[i][k] = A[i][k] - A[j][k] * temp;
                E[i][k] = E[i][k] - E[j][k] * temp;

			}

			print_arr(A, N);
        }
    }

   // for (int k = N - 1; k > 0; k--)
   // {
   //     for (int i = k - 1; i >= 0; i--)
   //     {
   //         temp = A[i][k];
 
   //         for (int j = 0; j < N; j++)
   //         {
   //             A[i][j] -= A[k][j] * temp;
   //             E[i][j] -= E[k][j] * temp;

			//	print_arr(A, N);

			//}
   //     }
   // }
 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = E[i][j];
 
    for (int i = 0; i < N; i++)
        delete [] E[i];
 
    delete [] E;
}



void mouse(const MOUSE_EVENT_RECORD *Event)
{
	static int press_left = 0;

	if ((press_left == 0) && (Event->dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED))
	{
		press_left = 1;
		//gotoxy( Event->dwMousePosition.X, Event->dwMousePosition.Y);
		cout << "*";
	}
	if ((press_left == 1) && (Event->dwButtonState & RIGHTMOST_BUTTON_PRESSED ))
	{
		press_left = 0;
		//gotoxy( Event->dwMousePosition.X, Event->dwMousePosition.Y);
		cout << "1";
	}
}

void keyboard(const KEY_EVENT_RECORD *Event)
{
	//cout << Event->wVirtualKeyCode << endl;
    if (Event->wVirtualKeyCode == VK_ESCAPE)
    {
        ExitProcess(0);
    }
}

//****************************************************************************************
// факториал рекурсия
//****************************************************************************************

int fact(int n)
{
    if (n == 1)
        return 1;

    return fact(n-1)*n;
}

int deg(int x, int n)
{
    if (n == 1)
        return x;
    return deg(x,n-1)*x;
}


int sumDigits(int x)
{
    if (x == 0)
        return 0;
    return sumDigits(x/10) + x%10;
}

int numDigits(int x)
{
    if (x == 0)
        return 0;
    return numDigits(x/10) + 1;
}

int sumRow123(int n)
{
    if (n == 0)
        return 0;
    return sumRow123(n-1) + n;
}

int Fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
	return Fibo(n-1) + Fibo(n-2);
}

int idxMaxInMas(int mas[], int n)
{
    if (n == 1)
        return 0;

	if (mas[n-1] > mas[idxMaxInMas(mas, n-1)])
		return n-1;
}

int maxInMas(int mas[], int n)
{
    if (n == 1)
        return mas[0];

	if (mas[n-1] > maxInMas(mas, n-1))
		return mas[n-1];
}

int idxMaxInVec(vector <int> vec)
{
	int x = vec[0];
	int idx = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > x)
		{
			x = vec[i];
			idx = i;
		}
	}

	return idx;
}

int digit_sum(string s)
{
	if (s.length() == 1)
	{
		if (s[0] == '1')
			return 1;
		else
			return 0;

	}
	if (s[s.length()-1] == '1')
	{
		s.erase( s.end() - 1 );			
		return 1 + digit_sum(s);
	} 
	else
	{
		s.erase( s.end() - 1 );			
		return 0 + digit_sum(s);
	}
}

//****************************************************************************************
// перегрузка оператора, примеры оформления классов
//****************************************************************************************
class CVector2D
{
public:

	int x;
	int y;

	// списки инициализации, список инициализации
	CVector2D(double x, double y) : x(x), y(y){}
	CVector2D(){
		x = 1;
		y = 0;
	}

	void show()
	{
		cout << x << " " << y << endl;
	}

	//friend CVector2D operator + (CVector2D & v1, CVector2D & v2) 
	//{
	//	return CVector2D(v1.x + v2.x, v1.y + v2.y);
	//}

	//унарная операция
	bool operator ! () 
	{
		if (x == 0 && y == 0)
			return true;
		else
			return false;
	}

	 //префикс инкремент
    //friend const CVector2D& operator ++ (CVector2D & vec)
    friend CVector2D& operator ++ (CVector2D & vec)
	{
		vec.x++;
		vec.y++;
		return vec;
	};
	
	//постфикс инкремент
    //friend const CVector2D operator ++ (CVector2D & vec, int)
    friend CVector2D operator ++ (CVector2D & vec, int)
	{
		vec.x--;
		vec.y--;
		return vec;
	};

	//перегрузка через дружественную функцию
	friend CVector2D operator + (CVector2D & v1, CVector2D & v2) 
	{
		return CVector2D(v1.x + v2.x, v1.y + v2.y);
	}

	//перегрузка через метод
	//CVector2D operator + (CVector2D v2)
	//{
	//	CVector2D vec;
	//	vec.x = v2.x + x;
	//	vec.y = v2.y + y;
	//	return vec;
	//}

	bool operator == (CVector2D v2)
	{
		if (v2.x == x && v2.y == y)
			return true;
		else 
			return false;
	}

}; 



class Integer
{
private:
    int value;
public:
    
	Integer(int i): value(i) {}

    void show() {
        cout << value;
    }

	//const Integer operator+(const Integer& rv) const 
	Integer operator + (Integer & rv) 
	{
        return (value + rv.value);
    }
};

//****************************************************************************************
// передача статического двумерного массива в функцию
//****************************************************************************************
void init_mas_10_10(int mas[10][10])
{
	for (int i=0; i<10; i++) 
	{
		for(int j=0; j<10; j++) 
		{
			mas[i][j]=5;
		} 
	}
}
//****************************************************************************************
// передача динамического массива в функцию
//****************************************************************************************
void init_din_mas(int *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = 5;
	}
}

struct DynMas
{
	int *mas;
	int n;
};

void printMas(DynMas mas)
{
	for (int i = 0; i < mas.n; i++)
	{
		cout << mas.mas[i] << " ";
	}
	cout << endl;
}

void incMas(int *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		(*mas)++;
		mas++;
	}
}

void printMas(int *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
}

void assign(DynMas &mas, int val)
{
	mas.mas = new int[mas.n];

	for (int i = 0; i < mas.n; i++)
	{
		mas.mas[i] = val;
	}
}

void push_back(DynMas &mas, int val)
{
	int *t = new int[mas.n+1];
	mas.n++;

	for (int i = 0; i < mas.n; i++)
	{
		t[i] = mas.mas[i];
	}

	t[mas.n-1] = val;

	delete [] mas.mas;
	mas.mas = t;	
}

void assign(int * &mas, int n, int val)
{
	mas = new int[n];

	for (int i = 0; i < n; i++)
	{
		mas[i] = val;
	}
}

void assign_rand(int * &mas, int n)
{
	mas = new int[n];

	for (int i = 0; i < n; i++)
	{
		mas[i] = rand(1,9);
	}
}

void push_back(int * &mas, int &n, int val)
{
	int *t = new int[n+1];
	n++;

	for (int i = 0; i < n; i++)
	{
		t[i] = mas[i];
	}

	t[n-1] = val;

	delete [] mas;
	mas = t;	
}

void pop_back(int * &mas, int &n)
{
	int *t = new int[n-1];
	n--;

	for (int i = 0; i < n; i++)
	{
		t[i] = mas[i];
	}

	delete [] mas;

	mas = t;	
}

//****************************************************************************************
// передача динамического двумерного массива в функцию
//****************************************************************************************

void clear(int **&mas, int n)
{
	for(int i=0; i<n; i++)
	{
	   delete[] mas[i];
	}
	delete[] mas;

	mas = NULL;

}

void assign(int **&mas, int n, int m, int x)
{
	if (mas != NULL)
		clear(mas,n);

	mas = new int*[n];

	for (int i = 0; i < n; i++)
	{
		mas[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mas[i][j] = x;
		}
	}
}

void print(int **mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mas[i][j];
		}
		cout << endl;
	}
}

void copy(int **&mas1, int **&mas2, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mas1[i][j] = mas2[i][j];
		}
	}
}

void push_back(int **&mas, int &n, int m, int x)
{
	int **temp = NULL;
	assign(temp, n+1, m, x);
	copy(temp, mas, n, m);
	n++;
	mas = temp;
}

void erase(int **&mas, int &n, int m, int row)
{
	int **temp = NULL;
	assign(temp, n-1, m, 0);

	for (int i = row; i < n-1; i++)
	{
		mas[i] = mas[i+1];
	}

	copy(temp, mas, n-1, m);

	mas = temp;

	n--;
}

void getMouseCoord(int &x, int &y)
{
    INPUT_RECORD console;
	HANDLE input  = GetStdHandle(STD_INPUT_HANDLE);

    DWORD n;
    ReadConsoleInput(input, &console, 1, &n);

	x = -1;
	y = -1;

    if (console.EventType == MOUSE_EVENT)
    {
		if (console.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			x = console.Event.MouseEvent.dwMousePosition.X;
			y = console.Event.MouseEvent.dwMousePosition.Y;
		}
		if (console.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
		{
			x = console.Event.MouseEvent.dwMousePosition.X;
			y = console.Event.MouseEvent.dwMousePosition.Y;
		}
    }
}

bool getClickCoord(int &x, int &y)
{
	bool res = false;

    INPUT_RECORD console;
	HANDLE input  = GetStdHandle(STD_INPUT_HANDLE);

    DWORD n;
    ReadConsoleInput(input, &console, 1, &n);

	x = -1;
	y = -1;

    if (console.EventType == MOUSE_EVENT)
    {
		if (console.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			x = console.Event.MouseEvent.dwMousePosition.X;
			y = console.Event.MouseEvent.dwMousePosition.Y;
			res = true;
		}
		if (console.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
		{
			x = console.Event.MouseEvent.dwMousePosition.X;
			y = console.Event.MouseEvent.dwMousePosition.Y;
			res = true;
		}
    }
	return res;
}

void selectWords (vector <string> & vec,string str)
{
    string save= "";
    int n = str.length();
    for(int i = 0; i < n; i++)
    {
        if((int)str[i] == 32)
        {
            vec.push_back(save);
            save = "";
        }
        else
        {
            save = save + str[i];
        }
    }
	
	if (!save.empty())
	{
		vec.push_back(save);
	}
}


int minOrMaxLen(vector <string> vec)
{
    int min = vec[0].length();
	int max = vec[0].length();
    int imin = 0;
	int imax = 0;
	int len = 0;
    
    for(int i =0;i < vec.size();i++){
        len = vec[i].length();

        if(len > max){
            max = len;
			imax = i;
        }
        if(len < min){
            min = len;
			imin = i;
        }
    }

    if(min == max)
        return 2;
    if(imin < imax)
        return 0;
	else
        return 1;
}

bool odinakovslova(string str)
{
    vector <string> vec;
    selectWords(vec,str);

    for(int i = 0;i < vec.size(); i++)
    {
        for(int j = 1+i; j < vec.size(); j++)
        {
            if(vec[i] == vec[j])
            {
                return 1;
            }
        }
    }
    return 0;
}


void chastota(string str)
{
    int a =0,f=0;
    
	vector <int> vec(256);

    for(int i=0;i< str.length();i++)
    {
        if(str[i] != 32)
        {
            vec[str[i]]++;
        }
    }

    for(int i =0;i < vec.size();i++)
    {
		if (vec[i] > 0)
	        cout << (char)i << " " << vec[i] << endl;
    }
}

string genPass()
{
	string pass = "";
	string symbols = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

	for(int i = 0; i < 12; i++)
	{
		int p = rand(0,symbols.length()-1);
		pass = pass + (char)symbols[p];
	}
	return pass;
}

//****************************************************************************************
// Цифры числа
//****************************************************************************************

int numDigitsInValue(int x)
{
	int d = 0;
	while (x > 0){
		x = x/10;
		d++;
	}
	return d;
}

int maxInVec(vector <vector<int>> vec)
{
	int max = 0;
	for(int i = 0; i < vec.size(); i++){
		for(int j = 0; j < vec[i].size(); j++){
			if (vec[i][j] > max){
				max = vec[i][j];
			}
		}
	}
	return max;
}

vector <int> greedy(vector <int> vec, int x)
{
	vector <int> res;

	for(int i = 0; i < vec.size(); i++)
	{        
		res.push_back(x / vec[i]);
		x = x % vec[i];
	}
	return res;
}

void pushPoint(stack <SPoint> &stk, int px, int py)
{
	SPoint p;
		p.x = px;
		p.y = py;
	stk.push(p);
}

void validAndMarkMask(int map[10][10], int px, int py, stack <SPoint> &stk)
{
	if (map[px][py] == 0)
	{
		pushPoint(stk, px, py);
	}
}

void workDeque(deque <Task> & deq1, deque <Task> & deq2)
{
	if (!deq1.empty())
	{
		if (deq1.front().tact > 0)
			deq1.front().tact--;
		if (deq1.front().tact == 0)
			deq1.pop_front();
		
	}
	else
	{
		if (!deq2.empty() && deq2.size() >= 2)
		{
			deq1.push_back(deq2.back());
			deq2.pop_back();
		}
	
	}
}

int main()
{
	setlocale(LC_ALL, "rus");


//****************************************************************************************
// 327.	Увеличить на 15%
//****************************************************************************************

	//srand(time(0));
	//float mas[15];

	//for(int i=0; i<15; i++)
	//{
	//	mas[i]=rand()%11+5;
	//	cout << mas[i] << " ";
	//}
	//cout << endl;

	//for (int i=0; i<15; i++)
	//{
	//	if (mas[i]<11)
	//	{
	//		mas[i]=mas[i]*1.15;
	//	}
	//}

	//for (int i=0; i<15; i++)
	//{
	//	cout << mas[i] << " ";
	//}

//****************************************************************************************
// Обработка массива
//****************************************************************************************

	//srand(time(0));
	//int mas[20];

	//for (int i=0; i<20; i++){
	//	mas[i]=rand()%20+1;
	//}

	//for (int i=0; i<20; i++)
	//{
	//	cout << mas[i] << " ";
	//}

	//cout << endl;

	//for (int i=0; i<20; i++)
	//{
	//	if(mas[i]%5==0)
	//	{
	//		mas[i]=0;
	//	}
	//	else if (mas[i]%2==0)
	//	{
	//		mas[i]=mas[i]/2;
	//	}
	//	else
	//	{
	//		mas[i]=mas[i]*2;
	//	}
	//}

	//for (int i=0; i<20; i++)
	//{
	//	cout << mas[i] << " ";
	//}

//****************************************************************************************
// Массив из n элементов по m
//****************************************************************************************

	//const int N=12;
	//int mas[N] = {1,2,3,4,5,6,7,8,9,10,11,12};
	//int m;
	//cin >> m;
	//for (int i=0; i<N; i++)
	//{
	//	cout << mas[i] << " ";
	//	if (mas[i]<10)
	//	{
	//		cout << " ";
	//	}
	//	if((i+1) % m == 0)
	//	{
	//		cout << endl;
	//	}
	//}	

	//cout << endl;
	//cout << endl;

//****************************************************************************************
//подключение мыши
//****************************************************************************************

 //   INPUT_RECORD console;
	//HANDLE input  = GetStdHandle(STD_INPUT_HANDLE);

 //   while (true)
 //   {
 //       DWORD n;
 //       ReadConsoleInput(input, &console, 1, &n);
 //       if (console.EventType == MOUSE_EVENT)
 //       {
	//		if (console.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
	//		{
	//			gotoxy(console.Event.MouseEvent.dwMousePosition.X, console.Event.MouseEvent.dwMousePosition.Y);
	//			cout << "L";
	//		}
	//		if (console.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
	//		{
	//			gotoxy(console.Event.MouseEvent.dwMousePosition.X, console.Event.MouseEvent.dwMousePosition.Y);
	//			cout << "R";
	//		}
 //       }
 //   }

//****************************************************************************************
// подключение мыши, получениие координат пиксела
//****************************************************************************************

//HWND hwnd = GetConsoleWindow();
// 
//    const unsigned pressedMask = 1u << sizeof(SHORT)* 8;
//    while(true)
//    {
//        const unsigned state = static_cast<unsigned>(GetKeyState(VK_LBUTTON));
//        if(pressedMask & state) // если нажата левая кнопка мыши
//        {
//            POINT cursorPos;
//            GetCursorPos(&cursorPos);
//            ScreenToClient(hwnd, &cursorPos);
// 
//            cout << "Click at " << cursorPos.x << "x and " << cursorPos.y << "y" << endl;
//            // Координаты относительно окна приложения, а не монитора
//            Sleep(100);
// 
//        }
//    }



//****************************************************************************************
//getMouseCoord
//****************************************************************************************
	//int x, y;

	//while (true)
 //   {
	//	getMouseCoord(x, y);
	//	if (x >=0 && y >= 0)
	//		cout << x << " " << y << " ";
	//}
//****************************************************************************************
// подключение мыши ctrl alt shift
//****************************************************************************************

	//INPUT_RECORD console;
	//HANDLE input  = GetStdHandle(STD_INPUT_HANDLE);

 //   while (true)
 //   {
 //       DWORD n;
 //       ReadConsoleInput(input, &console, 1, &n);

 //       if (console.EventType == KEY_EVENT)
 //       {
	//		if (console.Event.KeyEvent.bKeyDown)
	//		{
	//			if (console.Event.KeyEvent.wVirtualKeyCode == VK_SHIFT)
	//				cout << "Shift";
	//			if (console.Event.KeyEvent.wVirtualKeyCode == VK_CONTROL)
	//				cout << "Ctrl";
	//		}
 //       }

 //       if (console.EventType == MOUSE_EVENT)
	//	{
	//		if (console.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
	//		{
	//			cout << "L: " << console.Event.MouseEvent.dwMousePosition.X << " " << console.Event.MouseEvent.dwMousePosition.Y << endl;
	//		}
	//		if (console.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
	//		{
	//			cout << "R: " << console.Event.MouseEvent.dwMousePosition.X << " " << console.Event.MouseEvent.dwMousePosition.Y << endl;
	//		}
	//	}
 //   }


//****************************************************************************************
//Тестовая при приеме на работу
//Перечислите все проблемы, которые вы видите в данном коде:
//http://rsdn.ru/forum/other/4049447.all
//****************************************************************************************

//class Foo
//{
//public:
//    Foo(int j) { i=new int[j]; }
//    ~Foo() { delete i; }
//private:
//    int* i;
//};
//
//class Bar: Foo
//{
//public:
//    Bar(int j) { i=new char[j]; }
//    ~Bar() { delete i; }
//private:
//    char* i;
//};
//
//
//void main()
//{
//    Foo* f=new Foo(100);
//    Foo* b=new Bar(200);
//    *f=*b;
//    delete f;
//    delete b;
//}

//****************************************************************************************
//Тестовая при приеме на работу
//Напишите функцию, удаляющую последовательно дублирующиеся символы в строке: 
//(«AAA BBB ААА» -> «A B А»)
//****************************************************************************************

//#include <stdio.h>
// 
//void RemoveDups( char * pStr )
//{
//    const char * src = pStr;
//    char * dst = pStr;
// 
//    // Пока не дойдем до конца строки
//    while (*src)
//    {
//        // Записываем в pStr текущий символ, если указатели разные
//        if (dst != src)
//            *dst = *src;
// 
//        // Сдвигаем dst вправо
//        *dst++;
// 
//        // Пока не конец строки и следующий символ такой же
//        while ((*src + 1) && *(src + 1) == *src)
//        {
//            // Сдвигаем указатель src вправо
//            *src++;
//        }
//        *src++;
//    }
//    // Запишем ноль в конец строки
//    *dst = 0;
//}
// 
//int main()
//{
//    char s[] = "AAA BBB AAA";
//    RemoveDups(s);
//    printf("%s\n", s);
//    return 0;
//}

//****************************************************************************************
//Тестовая при приеме на работу
//Напишите функцию, которая принимает на вход знаковое целое число и печатает его 
//двоичное представление, не используя библиотечных классов или функций.
// !!! Изучить
//****************************************************************************************

//#include <stdio.h>
//#include <limits.h>
// 
//void BinaryPrint( long n )
//{
//    // Частный случай - n равно нулю
//    if (n == 0)
//    {
//        printf("0\n");
//        return;
//    }
// 
//    unsigned long mask = 1 << (sizeof(n) * 8 - 1);
// 
//    // Пропускаем бесполезные нули слева
//    int skipZero = 1;
// 
//    while (mask)
//    {
//        // Определим текущий бит
//        unsigned char c = (n & mask) ? 1 : 0;
// 
//        // Отключим пропуск нулей в дальнейшем
//        if (skipZero && c)
//            skipZero = 0;
// 
//        if (!skipZero)
//            printf("%d", c);
// 
//        // Сдвинем маску на один бит вправо
//        mask >>= 1;
//    }
//    printf("\n");
//}
// 
//int main()
//{
//    BinaryPrint(0);
//    BinaryPrint(1);
//    BinaryPrint(2);
//    BinaryPrint(-2);
//    BinaryPrint(-1);
//    BinaryPrint(LONG_MAX);
//    BinaryPrint(LONG_MIN);
//    return 0;
//}

//****************************************************************************************
//си строки Работа со строками
//****************************************************************************************
	//char s[10] = "12345";

	////for (int i = 0; i < strlen(s); i++)
	////{
	////	cout << s[i] << " " << (int)s[i] << endl;
	////}
	//printStr(s);

//****************************************************************************************
//Посимвольный вывод строки с пробелами
//****************************************************************************************

	//string s1;
	//cin >> s1;

	//for (int i = 0; i < s1.length(); i++)
	//{
	//	cout << s1[i] << " ";
	//}

//****************************************************************************************
// Удалить лишние пробелы в строке в начале и конце строки
//****************************************************************************************

	//string s = "  g   " ;
	//// пропускаем пробелы в начале строки
	//int i = 0;
	//for (i = 0; i < s.length(); i++)
	//{
	//	if (s[i] != ' ')
	//		break;
	//}

	//s.erase(0,i);

	//for (i = s.length() - 1; i >= 0; i--)
	//{
	//	if (s[i] != ' ')
	//		break;
	//}



//****************************************************************************************
// Удалить лишние пробелы в си строке
//****************************************************************************************
 
	//char str1[] = "   привет    как дела ? ";	// для сохранения строки
	//char str2[128] = "";	// для сохранения строки
	//
	////cout << "Введите текст латиницей (не больше 128 символов):\n";
	////cin.getline(ourStr, 128);
 //
	//int p1 = 0;	// счетчик символов
	//int p2 = 0;	// счетчик символов

	//// пропускаем пробелы в начале строки
	//while ((str1[p1] == ' ') && ((str1[p1] != '\0')))
	//{
	//	p1++;
	//}


	//while (str1[p1] != '\0')
	//{
	//	if (str1[p1] != ' ')
	//	{
	//		str2[p2] = str1[p1];
	//		p2++;
	//	}
	//	p1++;
	//}

	//str2[p2] = '\0';
 //
	//cout << str2;
 
//****************************************************************************************
// Избыточные пробелы
//****************************************************************************************
 
	//string str1 = "   привет    как дела ?    ";	// для сохранения строки
	//cout << trim(str1);


//****************************************************************************************
// Избыточные пробелы 2 через флаг
//****************************************************************************************

	//string str1 = "   привет    как дела ?    ";	// для сохранения строки
	//string str1 = "да      gf? ";	// для сохранения строки
	//string str2 = "";	// для сохранения строки
	//
	//str1 = trim(str1);

	//bool allowAddSpace = true;

	//for (int i = 0; i < str1.length(); i++)
	//{
	//	if (str1[i] != ' ')
	//	{
	//		str2 += str1[i];
	//		allowAddSpace = true;
	//	} 
	//	else if (str1[i] == ' ' && allowAddSpace)
	//	{
	//		str2 += str1[i];
	//		allowAddSpace = false;
	//	}
	//}
	//cout << str2;

//****************************************************************************************
// Избыточные пробелы 2 через два символа
//****************************************************************************************
 
	//string str1 = "   привет    как дела ?    ";	// для сохранения строки
	//string str1 = "aа  a?";	// для сохранения строки
	//string str2 = "";	// для сохранения строки
	//str1 = trim(str1);
	//str1 = str1+'\0';
	//for(int i = 0; i < str1.length()-1; i++)
	//{
	//	//cout << str1[i] << " " << (int)str1[i+1]<< endl;
	//	if (str1[i] != ' ' && str1[i+1] != ' ')
	//	{
	//		str2 = str2 + str1[i];
	//	}
	//	else if (str1[i] != ' ' && str1[i+1] == ' ')
	//	{
	//		str2 = str2 + str1[i];
	//		str2 = str2 + ' ';
	//	}
	//}

	//cout << str2;

//****************************************************************************************
// Заменить подряд идущие
//****************************************************************************************

	//string str1 = "aa bbb cc bbbb";	// для сохранения строки
	//string str2 = "";	// для сохранения строки
	//str2 += str1[0];
	//char ch = str1[0];
	//for (int i = 0; i < str1.length(); i++)
	//{
	//	if (str1[i] != ch)
	//	{
	//		str2 += str1[i];
	//		ch = str1[i];
	//	} 
	//}
	//cout << str2;



//Задача №317. Число сочетаний
//По данным натуральным n и k вычислите значение Cnk=n!/k!(n−k)! (число сочетаний из n элементов по k).
//Входные данные
//Вводятся 2 числа - n и k C(из n по k)=n!/(k!(n-k)!)
//Выходные данные
//Необходимо вывести  значение Cnk .
//Примеры
//входные данные 2 1
//выходные данные 2

	//int c = 0,n = 7, k = 3;
	//int nf = 1, kf = 1, nkf = 1;

	//for (int i = 1; i <= n; i++)
	//{
	//	nf = nf*i;
	//}

	//for (int i = 1; i <= k; i++)
	//{
	//	kf = kf*i;
	//}

	//for (int i = 1; i <= n-k; i++)
	//{
	//	nkf = nkf*i;
	//}

	//c = nf/(kf*nkf);
	//
	//cout << c << endl;

	//getch();
	//return 0;


//****************************************************************************************
// Факториал
//****************************************************************************************

	//int x = 1,n = 4;

	//for (int i = 1; i <= n; i++)
	//{
	//	x = x*i;
	//}

	//cout << x << endl;

//****************************************************************************************
// Сумма факториалов
//****************************************************************************************

	//int x = 1,n = 4;

	//int s = 0;

	//for (int i = 1; i <= n; i++)
	//{
	//	x = x*i;
	//	s = s + x;
	//}

	//cout << s << endl;

//****************************************************************************************
// Сумма факториалов 2
//****************************************************************************************

	//int x = 1,n = 15;

	//float s = 1;

	//for (int i = 1; i <= n; i++)
	//{
	//	x = x*i;
	//	s = s + 1.0/x;
	//}

	//cout << s << endl;

//****************************************************************************************
// Сумма факториалов 3
//****************************************************************************************

	//float x = 1,n = 1;
	//cin >> y;
	//cin >> n;
	//int d = 1;

	//float s = 1;

	//for (int i = 1; i <= n; i++)
	//{
	//	x = x*i;
	//	d = d*y;
	//	s = s + d/x;
	//}

	//cout << s << endl;

//****************************************************************************************
// Степень двойки 
// Напишите программу, вычисляющую 2^N.
//****************************************************************************************

	//unsigned int x = 1, y = 2, n = 34;

	//for (int i = 1; i <= n; i++)
	//{
	//	x = 2*x;
	//	cout << i << " " << x - 1 << endl;
	//}

	//getch();
	//return 0;

//****************************************************************************************
// Точная степень двойки
//****************************************************************************************

	//int x = 1, n = 0;
	//cin >> n;
	//while (x < n)
	//{
	//	x = 2*x;
	//}

	//if (x == n)
	//	cout << 1 << endl;
	//else
	//	cout << 0 << endl;

//****************************************************************************************
// Сумма степеней двойки
//****************************************************************************************

	//int x = 1, i = 0, n = 0;
	//int s = 0;
	//cin >> n;
	//while (i < n)
	//{
	//	x = 2*x;
	//	s = s + x;
	//	i++;
	//}

	//cout << s << endl;

//****************************************************************************************
// Точная степень двойки
//****************************************************************************************


	//cout << isPow2(2);
	//cout << isPow2(8);
	//cout << isPow2(9);


//****************************************************************************************
//Случайное число от A до B
//****************************************************************************************

	//int x, a = 90, b = 100;
	//for (int i = 0; i<=2000; i++)
	//{
	//	x = a + rand()%(b-a+1);
	//	cout << x << " ";
	//}
	//getch();
	//return 0;

//****************************************************************************************
//Передача массива как аргумент в функцию
//****************************************************************************************

	//char str1[] = "привет как дела?";	// для сохранения строки
	//del_space(str1);
	//cout << str1;
	//getch();
	//return 0;

//****************************************************************************************
//Удалить пробелы в строке
//****************************************************************************************
 
	//char str1[] = "привет как дела?";	// для сохранения строки
	//char str2[128] = "";	// для сохранения строки
	//
	////cout << "Введите текст латиницей (не больше 128 символов):\n";
	////cin.getline(ourStr, 128);
 //
	//int p1 = 0;	// счетчик символов
	//int p2 = 0;	// счетчик символов

	//while (str1[p1] != '\0')
	//{
	//	if (str1[p1] != ' ')
	//	{
	//		str2[p2] = str1[p1];
	//		p2++;
	//	}
	//	p1++;
	//}

	//str2[p2] = '\0';
 //
	//cout << str2;
 //
	//getch();
	//return 0;

//****************************************************************************************
//Определить длину строки
//****************************************************************************************
 
	//char str[128] = "привет как дела?";	// для сохранения строки
	//
	////cout << "Введите текст латиницей (не больше 128 символов):\n";
	////cin.getline(ourStr, 128);
 //
	//int size = 0;	// счетчик символов

	//while (str[size] != '\0')
	//{
	//	size++;
	//}
 //
	//cout << "Строка \"" << str << "\" состоит из "
	//	 << size << " символов!\n\n";
 //
	//getch();
	//return 0;

//****************************************************************************************
//Системы счисления. Из десятчиной в двоичную. Из двоичной в десятичную и т.д.
//****************************************************************************************

//****************************************************************************************
//Проверка гипотезы Сиракуз
//****************************************************************************************

//****************************************************************************************
//Простейший калькулятор
//Написать программу, в которой вводятся два операнда Х и Y и знак операции (+, –, /, *). 
//Вычислить результат Z в зависимости от знака. Предусмотреть реакции на возможный неверный знак 
//операции, а также на ввод Y=0 при делении. Организовать возможность многократных вычислений 
//без перезагрузки программа (т.е. построить цикл). 
//В качестве символа прекращения вычислений принять ‘0’.
//****************************************************************************************

//****************************************************************************************
//Требуется определить, сколько можно преобрести ручек (по цене 10 руб.), карандашей (5 руб.) 
//и ластиков (2 руб.) на 100 рублей. При этом всего предметов должно быть 30.
//****************************************************************************************

//****************************************************************************************
//Вводится число. Преобразовать его в другое число, цифры которого будут следовать в 
//обратном порядке по сравнению с введенным числом.
//****************************************************************************************


//****************************************************************************************
//Написать программу, подсчитывающую количество четных и нечетных цифр в числе.
//****************************************************************************************


//****************************************************************************************
//Генерация числовых рядов с циклом while.
//Выводить числовой ряд до тех пор пока сумму чисел ряда меньше N
//0 1 2 3 4 5 6 7 ...
//0 0 1 1 2 2 3 3 4 4 5 5 ...
//Числа Фиббоначи 0 1 1 2 3 5 8 13 21 ...
//****************************************************************************************

//****************************************************************************************
//Вывести на экран квадратик NxN, заполненный символом *
//0 1 2 3 4 5 6 7 ...
//0 0 1 1 2 2 3 3 4 4 5 5 ...
//Числа Фиббоначи 0 1 1 2 3 5 8 13 21 ...
//****************************************************************************************


//****************************************************************************************
//Генерация числовых рядов.
//0 1 2 3 4 5 6 7 ...
//0 0 1 1 2 2 3 3 4 4 5 5 ...
//Числа Фиббоначи 0 1 1 2 3 5 8 13 21 ...
//****************************************************************************************

	//float x = 1.00;
	//float y = 0.00;
	//float a = 1.00;

	//cout.width(3);
	////cout.precision(5);
	////cout.setprecision(2);

	//for (int i = 1; i <= 50; i = i + 1)
	//{
	//	cout << i << " ";

	//}

	//getch();
	//return 0;

//****************************************************************************************
//Вычисление факториала числа n!
//****************************************************************************************



//****************************************************************************************
//Вычислить сумму ряда чисел 1/1^2 + 1/2^2 + 1/3^2 + … + 1/n^2, где n определяется пользователем.
//****************************************************************************************


//****************************************************************************************
//Для каждого натурального числа в промежутке от m до n вывести все делители, 
//кроме единицы и самого числа. m и n вводятся с клавиатуры.
//****************************************************************************************

//****************************************************************************************
//Найти позицию в алфавите двух английских букв и количество символов между ними.
//Определить букву по ее позиции в алфавите.
//****************************************************************************************


//****************************************************************************************
//Угадать число, которое загадал пользователь, используя только инструкцию if-else.
//****************************************************************************************

//****************************************************************************************
//Пользователь вводит целое число. Определить является ли оно четным или нечетным.
//****************************************************************************************

	//int x = 3; // остаток от целочисленного деления
	//int modul = 9999; // деления по модулю
	//int ost = 0; // деления по модулю

	//ost = x % 2;

	//if (ost == 0)
	//	cout << "Chetnoe";
	//else 
	//	cout << "Ne Chetnoe";

	//cout << "ost = " << ost;

	//getch();
	//return 0;

//****************************************************************************************
//Пользователь вводит целое число. Определить является ли число простым.
//****************************************************************************************

	//int x = 253; // остаток от целочисленного деления
	//int modul = 9999; // деления по модулю
	//int ost = 0; // деления по модулю

	////x = 10/10;
	////cout << x;

	//getch();
	//return 0;


//****************************************************************************************
// Цифры числа
//****************************************************************************************

	//int x = 123; // остаток от целочисленного деления
	//int d = 0;
	//while (x > 0)
	//{
	//	d = x % 10;
	//	x = x/10;
	//	cout << d << " ";
	//}

//****************************************************************************************
// Все цифры нечетные?
//****************************************************************************************

	//int x = 235; 
	//int d = 0;
	//bool f = 1;
	//while (x > 0)
	//{
	//	d = x % 10;
	//	x = x/10;
	//	if (d % 2 == 0)
	//	{
	//		f = 0;
	//		break;
	//	}
	//}
	//cout << f;

//****************************************************************************************
// Цифры-делители
//****************************************************************************************

	//int x = 100; 
	//int d = 0;
	//int s = 0;
	//while (x > 0)
	//{
	//	d = x % 10;
	//	x = x/10;
	//	if (d != 0 && x % d == 0)
	//	{
	//		s++;
	//	}
	//}
	//cout << s;

//****************************************************************************************
// Цифры числа прямой порядок
//****************************************************************************************

	//int x = 123; // остаток от целочисленного деления
	//int d = 0;
	//int p = 1;
	//int s = 0;

	//while (x > 0)
	//{
	//	d = x % 10;

	//	s = s + d*p;
	//	p = p * 10;

	//	cout << d << " ";
	//	x = x/10;
	//}

	//cout << endl << s;

//****************************************************************************************
// Строку в число
//****************************************************************************************

	//char str[] = "123"; // остаток от целочисленного деления
	//int p = 1;
	//int s = 0;
	//for (int i = strlen(str)-1; i >=0; i--)
	//{
	//	s = s + (str[i]-48)*p;
	//	p = p * 10;
	//}
	//cout << s << endl;

//****************************************************************************************
//Пользователь вводит целое число. Вывести число наоборот, в обратном порядке
//****************************************************************************************

	//int x = 123; // остаток от целочисленного деления
	//int y = 0;
	//int modul = 9999; // деления по модулю
	//int ost = 0; // деления по модулю

	//int dig[15] = {0}; // деления по модулю

	//int c = 0;
	//int d = 1;

	//while (modul > 0)
	//{
	//	modul = x/10;
	//	ost = x%10;
	//	cout << ost << " ";
	//	x = modul;
	//	dig[c] = ost;
	//	c++;
	//	d = d * 10;
	//}

	//d = d / 10;

	//for (int i = 0; i < c; i++)
	//{
	//	y = dig[i]*d + y;
	//	d = d / 10;

	//}
	//
	//cout << "y = " << y;

	//getch();
	//return 0;

//****************************************************************************************
//В зависимости от того, в каких единицах измерения вводится значение, 
//перевести его в другие единицы измерения.
//В данном случае переводится объем информации (байты, килобайты, мегабайты и гигабайты).
//****************************************************************************************


//****************************************************************************************
//Сгенерировать случайные целое число, вещественное число, букву в диапазонах, 
//которые вводит пользователь.
//****************************************************************************************

//****************************************************************************************
//Вывести на экран действительное число в различных форматах представления
//****************************************************************************************


//****************************************************************************************
//Месячная выплата m по займу в s рублей на n лет под процент p вычисляется по формуле:
//m = (s * r * (1 + r)n) / (12 * ((1 + r)n – 1)), где r = p / 100.
//****************************************************************************************

//****************************************************************************************
//Сгенерировать случайное число, вывести на экран это число, а также сумму и произведение его цифр.
//****************************************************************************************

//****************************************************************************************
//Обменять значения двух переменных, используя третью (буферную) переменную.
//****************************************************************************************

//****************************************************************************************
//Вывести на экран введенные пользователем данные в полях шириной, заданной по умолчанию, 
//и полях шириной, определяемой пользователем.
//****************************************************************************************

//****************************************************************************************
//Требуется написать программу, вычисляющую значение функции у = f(x):
//у = x – 2, если x > 0,
//y = 0,     если x = 0,
//y = |x|,   если x < 0.
//****************************************************************************************

	//int x = -5;
	//int y = 0;

	//cout << "Input x: ";
	//cin >> x;

	//if (x > 0)
	//	y = x - 2;

	//if (x == 0)
	//	y = 0;

	//if (x < 0)
	//	y = abs(x);

	//cout << y;
	//
	//getch();
	//return 0;

//****************************************************************************************
//Вычислить значения следующих выражений. При этом найти область определения функций и обеспечить 
//необходимую реакцию программы на некорректные ситуации.
//y =(x^3+2ax+3)/((x-1)^3) + cos x^2/(a+2)
//****************************************************************************************

	//float x = 2;
	//float y = 0;
	//float a = 1;

	//y = (x*x*x + 2*a*x + 3) / ((x-1)*(x-1)*(x-1)) + cos(x*x)/(a+2);

	//cout << y;
	//
	//getch();
	//return 0;

//****************************************************************************************
//Дано число х. Вычислить y. Если число х принадлежит диапазону х [-10;0], то y=x^2; 
//если число х принадлежит диапазону х [0;1], то y=sin^2(x); 
//если число х принадлежит диапазону х [1;5], то y=ln(x^2); иначе y=x.
//****************************************************************************************

	//float x = 2.7183;
	//float x = 10;
	//float y = 0;
	//float a = 1;

	//y = log(x);
	//y = log10(x);

	//cout << y;
	//
	//getch();
	//return 0;

//****************************************************************************************
//Вычислить значение функции y=min + 2* min+b, определив и использовав функцию min, 
//которая равна минимальному числу среди вводимых:a,b.
//****************************************************************************************

//****************************************************************************************
//Составление таблиц значений функции
//Составить таблицу значений функции y = 5 - x2/2 на отрезке [-5; 5] с шагом 0.5.
//****************************************************************************************

//****************************************************************************************
//Составление таблиц значений функции
//Построить таблицу значений для функции y = x*x +1, на отрезке [1;5], с шагом 0,1
//****************************************************************************************

	//float x = 1.00;
	//float y = 0.00;
	//float a = 1.00;

	//cout.width(3);
	////cout.precision(5);
	////cout.setprecision(2);

	//for (int i = 0; i < 50; i++)
	//{
	//	y = x*x + 1.00;
	//	cout << x << " " << y << endl;
	//	x = x + 0.10;

	//}

	//getch();
	//return 0;

//****************************************************************************************
//Определить какое из трех, введенных пользователем, чисел максимальное и вывести его на экран.
//****************************************************************************************

//****************************************************************************************
//Определить среднее среди 3 чисел, которое больше 1 и меньше другого. Если все числа равны, 
//выводится ошибка. Если 2 равны – ошибка.
//****************************************************************************************

//****************************************************************************************
//Вводим три разные числа и надо найти максимальное но с выводом не числа а номера числа. 
//Например: вводим первое-1, второе-5, третье-2; вывод должен быть: наибольшее второе число.
//****************************************************************************************

//****************************************************************************************
//Напишите программу которая по введенному не более чем четырехзначному числу 
//будет выдавать сумму цифр этого числа
//****************************************************************************************

//****************************************************************************************
//Запись типа ‘a’..’z’ включает диапазон значений от символа ‘a’ до символа ‘z’ включительно.
//var ch: char;
//begin
//    write ('Введите символ:  ');
//    readln (ch);
//    case ch of
//        '0'..'9': write ('Это число');
//        'a'..'z','A'..'Z': write ('Это английская буква');
//        'а'..'я','А'..'Я': write ('Это русская буква')
//    end;
//readln
//end.

//****************************************************************************************
//Всем известна прямоугольная (декартова) система координат, 
//в которой две перпендикулярные оси делят плоскость на четверти. 
//В первую четверть попадают точки, у которых обе координаты (x и y) больше нуля. 
//Во вторую: x < 0, y > 0; третью: x < 0, y < 0; четвертую: x > 0, y < 0.
//****************************************************************************************


//****************************************************************************************
//Достаточно часто требуется построить на экране какую-нибудь двумерную таблицу. 
//Это можно реализовать с помощью двух циклов for. При этом один цикл должен быть вложен в другой.
//Допустим, нам требуется вывести на экран таблицу умножения.
//****************************************************************************************

	//char ch = '*';
	//for (int i = 0; i < 80; i++)
	//	cout << ch;
	//for (int i = 0; i < 22; i++)
	//	cout << ch << endl;

	//for (int i = 0; i < 80; i++)
	//	cout << ch;
	//
	//for (int i = 0; i < 23; i++)
	//{
	//	gotoxy(79,i);
	//	cout << ch;
	//}
	//
	//char hero = 2;
	//
	//int hero_x = 40;
	//int hero_y = 12;

	//int key = 0;

	//while (key != 27)
	//{
	//	
	//	gotoxy(hero_x,hero_y);
	//	cout << ' ';

	//	if (key == 75)
	//	{
	//		hero_x = hero_x - 1;		
	//	}

	//	if (key == 77)
	//	{
	//		hero_x = hero_x + 1;		
	//	}

	//	if (key == 72)
	//	{
	//		hero_y = hero_y - 1;		
	//	}

	//	if (key == 80)
	//	{
	//		hero_y = hero_y + 1;		
	//	}

	//	gotoxy(hero_x,hero_y);
	//	cout << hero;

	//	key = getch();

	//}

	//return 0;

// ***************************************************************************
//Ввести элементы одномерного массива размером 30 с использованием генератора случайных чисел в диапазоне [-10¸10]. 
//Вывести массив на экран по 6 элементов в строке. Найти:
// - среднее арифметическое значение элементов массива; 
// - максимальный элемент и его номер;
// - минимальный элемент и его номер;
// - произведение положительных элементов
// ***************************************************************************

	//int const kolvo_vershin = 5;

	//int mas[5][5]; 
	//float sred;
	//int max_element;
	//int nomer_max_element;
	//int min_element;
	//int nomer_min_element;
	//long proiz;
	//char chh;

	//printf("Начало\n");
	//printf("обнуление элементов массива\n");

	//while((chh = getch()) != 27)
	//{
//	srand(time(NULL));

	//	int count_road = 0;

	//	for(int i=0; i<5; i++)
	//	{
	//		for(int j=0; j<5; j++)
	//		{
	//			mas[i][j] = rand() % 2 ;
	//		}
	//	}

	//	for(int i=0; i<5-1; i++)
	//	{
	//		for(int j=i+1; j<5; j++)
	//		{
	//			if (mas[i][j] == 1)
	//			{
	//				//if ((mas[i][j] != mas[j][i]) && (i != j))
	//				{
	//					count_road++;
	//					//cout << "i = " << i << " j = " << j << " " << mas[i][j] << " " << count_road << endl;
	//				}
	//			}
	//		}
	//	}


	//	for(int i=1; i<5; i++)
	//	{
	//		for(int j=0; j<i; j++)
	//		{
	//			if (mas[i][j] == 1)
	//			{
	//				if (mas[i][j] != mas[j][i])
	//				{
	//					count_road++;
	//					//cout << "i = " << i << " j = " << j << " " << mas[i][j] << " " << count_road << endl;
	//				}
	//			}
	//		}
	//	}



	//	for(int i=0; i<5; i++)
	//	{
	//		for(int j=0; j<5; j++)
	//		{
	//			printf("%4d",mas[i][j]);
	//		}
	//		printf("\n");
	//	}
	//	
	//	//printf("Среднее арифметическое = %.3f \n", sred);
	//	printf("Максимальный элемент = %d \n", count_road);
	//	//printf("Номер максимального элемента = %d \n", nomer_max_element);
	//	//printf("Минимальный элемент = %d \n", min_element);
	//	//printf("Номер минимального элемента = %d \n", nomer_min_element);
	//	//printf("Произведение положительных элементов = %u \n", proiz);
	//}

	//return 1;
	

	//for(int i=1; i <= 400; i++)
	//{
	//	cout << rand() % (78-49) + 50 << "   " << rand() % (23) + 1 << endl;
	//}
	//
	//system("pause");
	//return 0;

//****************************************************************************************
// system("color FC")
//****************************************************************************************

	//2 - значение цвета фона, 0 - значение цвета текста
	//Расшифровка цветов:
	//0 = Black  8 = Gray
	//1 = Blue   9 = Light Blue
	//2 = Green  A = Light Green
	//3 = Aqua   B = Light Aqua
	//4 = Red    C = Light Red
	//5 = Purple D = Light Purple
	//6 = Yellow E = Light Yellow
	//7 = White  F = Bright White
	
	//system("color FC");
	//cout << "text";
	//system("color F1");
	//cout << "text";

	//set_color(15,1);
	//cout << "text";

	//set_color(15,4);
	//cout << "text";

//****************************************************************************************
// работа с stl списком list
//****************************************************************************************
 //
	//list <int> lst; // создём список с элементами типа int

	//// заносим элементы в начало списка
	////lst.push_front(3);
	////lst.push_front(2);
	////lst.push_front(1);

	//// заносим элементы в конец списка
	//lst.push_back(5);
	//lst.push_back(5);
	//lst.push_back(5);
	//lst.push_back(5);

	////cout << count(lst.begin(),lst.end(), 4);



 //   list<int>::iterator result = lst.begin();

	//while(true)
	//{
	//	result = adjacent_find(result, lst.end());
	// 
	//	if (result == lst.end()) 
	//	{
	//		break;
	//	} 
	//	else 
	//	{
	//		cout << "совпадение в позиции: " << distance(lst.begin(), result) << endl;
	//	}

	//	result++;
	//}

 //   std::vector<int> v1;
	//
	//v1.push_back(0);
	//v1.push_back(1);
	//v1.push_back(1);
	//v1.push_back(1);
	//v1.push_back(4);
	//v1.push_back(40);
	//v1.push_back(5);

 
	//// печатаем элементы с помощью итератора
	//for(list <int>::iterator iter = intList.begin(); iter != intList.end(); iter++)
	//	cout << *iter << " ";

	//for(list <int>::iterator iter = intList.begin(); iter != intList.end(); iter++)
	//{
	//	if (*iter == 3)
	//	{
	//		intList.erase(iter);
	//		break;
	//	}
	//}

	//cout << endl;

	//// печатаем элементы с помощью итератора
	//for(list <int>::iterator iter = intList.begin(); iter != intList.end(); iter++)
	//	cout << *iter << " ";

//****************************************************************************************
// работа с вектором через итератор
//****************************************************************************************

 //   vector<int> vec;

 //   for (int i=0; i < 5; i++)
	//{
 //       vec.push_back(i);
	//}
 //
 //   vector <int>::iterator it = vec.begin(); // объявляем итератор только для чтения

	//vec.insert(it,7);
	//it++;

	////vec.erase(it);

 //   for (it = vec.begin();it != vec.end(); it++) // пока итератор не достигнет конца
 //   {
	//	cout << *it << " "; // выводим значение элемента, на который указывает итератор
 //   }

//****************************************************************************************
// работа с вектором через итератор. Вывод вектора 2
//****************************************************************************************

	//vector<int> vec;

	//for (int i=0; i < 5; i++)
	//{
	//	vec.push_back(i);
	//}

	//vector <int>::iterator it;

	//for (it = vec.end()-1; it != vec.begin(); it--) // пока итератор не достигнет конца
	//{
	//	cout << *it << " "; // выводим значение элемента, на который указывает итератор
	//}
	//cout << *it << " "; // выводим значение элемента, на который указывает итератор

//****************************************************************************************
// работа с вектором через итератор. Добавить после первого.
//****************************************************************************************

 //   vector<int> vec;

 //   for (int i=1; i <=0; i++)
	//{
 //       vec.push_back(i);
	//}
 //
 //   vector <int>::iterator it = vec.begin(); // объявляем итератор только для чтения

	//if (!vec.empty())
	//{
	//	it++;
	//}
	//vec.insert(it,7);

	//for (it = vec.begin();it != vec.end(); it++) // пока итератор не достигнет конца
 //   {
	//	cout << *it << " "; // выводим значение элемента, на который указывает итератор
 //   }


//****************************************************************************************
// работа с вектором через итератор. Добавить предпоследний.
//****************************************************************************************

 //   vector<int> vec;

 //   for (int i=1; i <= 5; i++)
	//{
 //       vec.push_back(i);
	//}
 //
 //   vector <int>::iterator it = vec.end(); // объявляем итератор только для чтения

	//if (!vec.empty())
	//{
	//	it--;
	//	vec.insert(it,7);
	//}

	//for (it = vec.begin();it != vec.end(); it++) // пока итератор не достигнет конца
 //   {
	//	cout << *it << " "; // выводим значение элемента, на который указывает итератор
 //   }

//****************************************************************************************
// работа со списком через итератор. Вывод списка.
//****************************************************************************************

 //   list <int> lst;

 //   for (int i=0; i < 5; i++)
	//{
	//	lst.push_back(i);
	//}
 //
 //   list <int>::iterator it = lst.begin(); // объявляем итератор только для чтения

	//for (it = lst.begin();it != lst.end(); it++) // пока итератор не достигнет конца
 //   {
	//	cout << *it << " "; // выводим значение элемента, на который указывает итератор
 //   }


//****************************************************************************************
// работа с вектором через итератор. Удалить первый.
//****************************************************************************************

 //   vector<int> vec;

 //   for (int i=0; i < 0; i++)
	//{
 //       vec.push_back(i);
	//}
 //

//vector <int>::iterator it = vec.begin(); // объявляем итератор только для чтения
//if (!vec.empty())
//{
//	vec.erase(it);
//}

	//for (it = vec.begin();it != vec.end(); it++) // пока итератор не достигнет конца
 //   {
	//	cout << *it << " "; // выводим значение элемента, на который указывает итератор
 //   }

//****************************************************************************************
// работа с вектором через итератор. Удалить первый.
//****************************************************************************************

 //   vector<int> vec;

 //   for (int i=0; i < 5; i++)
	//{
 //       vec.push_back(i);
	//}
 //
 //   vector <int>::iterator it = vec.begin(); // объявляем итератор только для чтения

	//if (!vec.empty())
	//{
	//	vec.erase(it);
	//}

	//int x = 7;
	//bool find = 0;

	//for (it = vec.begin();it != vec.end(); it++) // пока итератор не достигнет конца
	//{
	//	if (x == *it)
	//	{
	//		find = 1;
	//	}
	//}

	//cout << find;

//****************************************************************************************
// Удалить чётные
//****************************************************************************************

	//srand(time(0));


 //   vector<int> vec;

	//vec.push_back(1);
	//vec.push_back(1);
	//vec.push_back(1);
	//vec.push_back(1);

 //   for (int i=0; i < 10; i++)
	//{
 //       vec.push_back(rand()%5);
	//}
 //
	//for (vector <int>::iterator it = vec.begin();it != vec.end(); it++) // пока итератор не достигнет конца
 //   {
	//	cout << *it << " "; // выводим значение элемента, на который указывает итератор
 //   }
	//cout << endl; 

	//for (vector <int>::iterator it = vec.begin(); it != vec.end();)
	//{
	//	if ((*it) % 2 == 0)
	//	{
	//		it = vec.erase(it);
	//	}
	//	else
	//	{
	//		it++;
	//	}
	//}

	//for (vector <int>::iterator it = vec.begin();it != vec.end(); it++) // пока итератор не достигнет конца
 //   {
	//	cout << *it << " "; // выводим значение элемента, на который указывает итератор
 //   }

//****************************************************************************************
// Добавить, удалить, просмотреть
//****************************************************************************************

	//int x = 0;

	//while(true)
	//{
	//	cout << "1. Добавление элемента в вектор" << endl;
	//	cout << "2. Удаление элемента из вектора" << endl;
	//	cout << "3. Вывод на экран содержимого вектора" << endl;
	//	cout << "Выберите пункт меню > " ;
	//	cin >> x;

	//	if (x == 0)
	//	{
	//		cout << "Выберите число > " ;
	//		cin >> x;
	//		vec.push_back(rand()%5);
	//	}
	//}

//****************************************************************************************
// Удалить меньшие 3 букв.
//****************************************************************************************

	//vector <string> vec;

	//vec.push_back("sasas");
	//vec.push_back("sas");
	//vec.push_back("ss");
	//vec.push_back("saasasasas");

 //
	//for (vector <string>::iterator it = vec.begin(); it != vec.end(); it++)
	//{
	//	if ((*it).length() <= 3)
	//	{
	//		vec.erase(it);
	//		it = vec.begin();
	//	}
	//}

	//for (vector <string>::iterator it = vec.begin();it != vec.end(); it++) // пока итератор не достигнет конца
 //   {
	//	cout << *it << " "; // выводим значение элемента, на который указывает итератор
 //   }





//****************************************************************************************
// работа с stl списком list
//****************************************************************************************
 //   list <int> sss {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 //   for (auto &i : sss) {
 //       std::cout << i << " ";
 //   }

	//for(list <int> :: iterator iter = sss.begin(); iter != sss.end(); iter++)
	//{
	//	if(iter == 2)          // На этом месте
	//		sss.erase();      // выдаешь ошибку при выполнении
	//}

	//List <int> list;

	//list.push_back(10);
	//list.push_back(20);
	//list.push_back(15);

	//list.erase();

	//list.print();

	//getch();

	//return 0;

	//integer iii = 111;
	//cout << iii;
	//return 0;

	//setlocale(LC_CTYPE, "rus");
	//setlocale(LC_ALL, "Rus");

//Есть один весомый недостаток у данных функций — они работают со шрифтом Lucida Console. 
//По умолчанию в консоли стоит шрифт Consolas. 
//Поэтому в командной строке необходимо настроить используемый шрифт. 
//Для этого открываем cmd, заходим в свойства, в закладке Шрифт выбираем Lucida Console
//SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
//SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	//string ss;
	//cin >> ss;
	//cout << ss;
	//system("pause");
	//return 0;

// ***************************************************************************
// очистка буфера cin
// ***************************************************************************

	// Не очищается поток после cin.clear()
	//cin.clear();//сброс битов ошибок входного стандартного потока
	//cin.sync();//очищение буфера стандартного ввода

// ***************************************************************************
// ascii таблица символов кодов
// ***************************************************************************
	//setlocale(LC_ALL, "C");

	//for(int i=0; i < 256; i++)
	//{
	//	unsigned char asciiChar = i;
	//	cout << i << " = " << asciiChar << " " << endl;
	//}
// ***************************************************************************
// работа с символами
// ***************************************************************************
	//char ch = 'a';
	//cout << (int)ch;
	//string str = "sss";
	//str[0] = ch;
	//cout << str;

	//char ch = 1;
	//cout << ch;

// ***************************************************************************
// работа с getch()
// ***************************************************************************

	//int ch = 0;

	//while(ch != 27)
	//{
	//	int ch = getch();
	//	cout << ch;
	//
	//}


	//float x = sqrt((float)(4*4 + 5*5));// извлечение квадратного корня
	//cout << x;

	//system("pause");
	//return 0;

	//cout<< sizeof(char) 
	//	<< sizeof(short) 
	//	<< sizeof(int) 
	//	<< sizeof(long) 
	//	<< sizeof(float) 
	//	<< sizeof(double) 
	//	<< sizeof(long long) 
	//	<< endl;

	//int vv = 7%4; // остаток от целочисленного деления
	//vv = 7/2; // деления по модулю

	//const int v = 465; // константа

	//cout << vv << endl;
	//float x, in, cm;
	//cout << "введите длину: ";
	//cin >> x >> vv; // вот такой бывает ввод

	//switch (ch) 
	//{
	//	case 'i':
	//		cm = x*fac;
	//	break;
	//	case 'c':
	//		cm = x;
	//	break;
	//	default:
	//		in = cm = 0;
	//	break;
	//}

	//v1 = rand() % 100;         // v1 in the range 0 to 99
	//v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
	//v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
	// ***************************************************************************
	// программа сложения двух чисел
	// ***************************************************************************
	//int a, b;
	//float f;
	//double d = 12.34234;
	//char ch = 'f';
	////bool b = true;

	//cout << "введите a:";
	//cin >> a;
	//cout << "введите b:";
	//cin >> b;

	//cout << " a + b = " << a + b << endl;
	// ***************************************************************************


	// ***************************************************************************
	// циклы
	//int b = 0;
	//for (int i = 1; i <= 1000; i++)
	//{
	//	b = b + 1;
	//}

	//int i = 0;

	//while (i < 2000)
	//{
	//	i++;
	//	b = b + i;
	//}

	//do {// выполняем цикл.
	//	i++;
	//	b += i;
	//} while (i < 1000); // пока выполняется условие.

	//cout << " b = " << b << endl;
	//getch();

	// ***************************************************************************
	// переводим градусы в кельвины
	// ***************************************************************************

	//int lower, upper, step;
	//float fahr,cels;

	//lower=0;
	//upper=300;
	//step=20;
	//fahr=lower;

	//while (fahr<=upper) 
	//{
	//   cels = (5.0/9.0)*(fahr-32.0); //вычисляем значение температуры по цельсию. 
	//							     //числа берем с нулем после точки, что бы они задавались как float
	//							     //а не как int, в противном случае операции будут произведены как 
	//							     //с целочисленными числами
	//							     //что приведе к неточным результатам из за округления до целых
	//   printf("%4.0f %6.2f\n",fahr,cels); //выводим результат на экран через печать форматной строки
	//   fahr = fahr + step;		     //увеличиваем значение переменной на шаг
	//}

	// ***************************************************************************
	// чтение с клавиатуры
	// ***************************************************************************

	//int c;
	//int eof = -1;

	//printf("Make input\n");

	//c = getchar(); 
	//putchar(c);
	//c = getchar(); 
	//putchar(c);

	//while (c != eof) {
	//	putchar(c);
	//	c=getchar();
	//}

	// ***************************************************************************
	// как работает функция putchar
	// ***************************************************************************

	//char c;
	//for (c = 'A' ; c <= 'Z' ; c++)
	//{
	//	putchar (c);
	//}
	// ***************************************************************************

	// ***************************************************************************
	// как работает функция getchar
	// ***************************************************************************
	//int c;
	//puts ("Enter text. Include a dot ('.') in a sentence to exit:");
	//do {
	//	c=getchar();
	//	puts (" Enter");
	//	putchar (c);
	//} while (c != '.');
	
	// ***************************************************************************
	// функция подсчета количества символов в файле
	// ***************************************************************************
	
	//int ch;
	//int c = 0;
	//
	//puts ("Enter text. Include a dot ('.') in a sentence to exit:");
	//ch = getchar();

	//while (ch != '.') 
	//{
	//	ch = getchar();
	//	putchar (ch);
	//	c++;
	//};

	//printf("%4d",c); //выводим результат на экран через печать форматной строки

	// ***************************************************************************
	// подсчитать, сколько каждой из цифр от 0 до 9 содержится в текстовом файле.
	// ***************************************************************************

	//int eof = -1;
	//int c; //для ввод символа
	//int mas[10]; //для подсчета количества обнаруженных в файле цифр. Для 0 индекс 0, для 1 - 1 и так далее до 9.
	//int i;

	//for(i=0; i<10; i++) //обнуление элементов массива
	//	mas[i]=0; 

	//printf("Input string and press <ENTER>\n");

	//c=getchar();

	//while(c != '.') 
	////while((c=getchar())!= eof) 
	//{
	//	putchar(c);
	//	if(c >= '0' && c <= '9')
	//	{
	//		c = c - '0';
	//		mas[c]++; //если нашли цифру, увеличим на 1 соответствующий счетчик
	//	}
	//	c=getchar();
	//};
	//
	//printf("Count of digits:\n");

	//for(i=0; i<10; i++)
	//{
	//	printf("digit: %d is count %d\n",i,mas[i]);
	//} 

	// ***************************************************************************
	//Ввести элементы одномерного массива размером 30 с использованием генератора случайных чисел в диапазоне [-10¸10]. 
	//Вывести массив на экран по 6 элементов в строке. Найти:
	// - среднее арифметическое значение элементов массива; 
	// - максимальный элемент и его номер;
	// - минимальный элемент и его номер;
	// - произведение положительных элементов
	// ***************************************************************************

	//int mas[30]; 
	//float sred;
	//int max_element;
	//int nomer_max_element;
	//int min_element;
	//int nomer_min_element;
	//long proiz;
	//char ch;

	//printf("Начало\n");
	//printf("обнуление элементов массива\n");

	//while((ch = getch()) != 27)
	//{
	//	srand(time(NULL));

	//	sred = 0;
	//	max_element = -999;
	//	nomer_max_element = 0;
	//	min_element = 999;
	//	nomer_min_element = 0;
	//	proiz = 1;

	//	for(int i=0; i<30; i++)
	//	{
	//		mas[i] = rand() % 21 - 10;
	//		sred = sred + mas[i];

	//		if (mas[i] > max_element)
	//		{
	//			max_element = mas[i];
	//			nomer_max_element = i + 1;
	//		}

	//		if (mas[i] < min_element)
	//		{
	//			min_element = mas[i];
	//			nomer_min_element = i + 1;
	//		}
	//		if (mas[i] > 0)
	//		{
	//			proiz = proiz * mas[i];
	//		}
	//	}

	//	sred = sred / 30;

	//	for(int i=0; i<5; i++)
	//	{
	//		for(int j=0; j<6; j++)
	//		{
	//			printf("%4d",mas[i*5+j+i]);
	//		}
	//		printf("\n");
	//	}
	//	
	//	printf("Среднее арифметическое = %.3f \n", sred);
	//	printf("Максимальный элемент = %d \n", max_element);
	//	printf("Номер максимального элемента = %d \n", nomer_max_element);
	//	printf("Минимальный элемент = %d \n", min_element);
	//	printf("Номер минимального элемента = %d \n", nomer_min_element);
	//	printf("Произведение положительных элементов = %u \n", proiz);
	//}
	// ***************************************************************************
	//Ввести элементы одномерного массива размером 15 через типизированную константу. 
	//Значения элементов массива:  -34, 11, 23, -7, 16, -3, -17, 0, 20, 9, 31, 27, -19, -5, -2. 
	//Вывести массив на экран по 5 элементов в строке. Найти:
	//- среднее арифметическое значение среди положительных и отрицательных элементов массива;
	//- максимальный элемент и его номер;
	// ***************************************************************************
	//int mas[] = {-34, 11, 23, -7, 16, -3, -17, 0, 20, 9, 31, 27, -19, -5, -2}; 
	//float sred_max;
	//int count_max;
	//int max_element;
	//int nomer_max_element;
	//char ch;

	//printf("Начало\n");

	//while((ch = getch()) != 27)
	//{
	//	sred_max = 0;
	//	max_element = -999;
	//	nomer_max_element = 0;
	//	count_max = 0;

	//	for(int i=0; i<15; i++)
	//	{

	//		if (mas[i] > 0)
	//		{
	//			sred_max = sred_max + mas[i];
	//			count_max++;
	//		}

	//		if (mas[i] > max_element)
	//		{
	//			max_element = mas[i];
	//			nomer_max_element = i + 1;
	//		}

	//	}

	//	sred_max = sred_max / count_max;

	//	for(int i=0; i<3; i++)
	//	{
	//		for(int j=0; j<5; j++)
	//		{
	//			printf("%4d",mas[i*4+j+i]);
	//		}
	//		printf("\n");
	//	}
	//	
	//	printf("Среднее арифметическое положительных = %.3f \n", sred_max);
	//	printf("Максимальный элемент = %d \n", max_element);
	//	printf("Номер максимального элемента = %d \n", nomer_max_element);
	//}
	// ***************************************************************************
	// Объявление массива строк
	// ***************************************************************************
	//string students[10] = {
	//		"Иванов", "Петров", "Сидоров",
	//		"Ахмедов", "Ерошкин", "Выхин",
	//		"Андеев", "Вин Дизель", "Картошкин", "Чубайс"};

	//cout << students[5] << endl; // Пытаемся вывести весь массив непосредственно
	// ***************************************************************************
	// Объявление массива строк
	// ***************************************************************************
 //   string valid_pass = "qwerty123";
 //   string user_pass;
	//cout << "Различие cin >> и getline(cin, <var>)" << endl;

	//cout << "Введите строку с пробелом: ";
	//cin >> user_pass;
	//cout << user_pass << endl;

	//cout << "Введите строку с пробелом: ";
 //   getline(cin, user_pass);
	//cout << user_pass << endl;

	// ***************************************************************************
	//Ввести элементы одномерного массива размером 20 как значения функции lgx для x от 1 до 20 с шагом 1 и 
	//вывести на экран в несколько строчек. Определить:
	//- количество элементов в диапазоне от 0 до 1;
	//- произведение элементов больших 1.
	// ***************************************************************************
	
	//float mas[20]; 
	//float x;

	//char ch;

	//printf("Начало\n");

	//while((ch = getch()) != 27)
	//{
	//	//count_max = 0;

	//	x = 1;

	//	for(int i=0; i<20; i++)
	//	{
	//		//mas[i] = log(x);
	//		mas[i] = log10(x);
	//		x = x + 1;

	//	}

	//	for(int i=0; i<4; i++)
	//	{
	//		for(int j=0; j<5; j++)
	//		{
	//			printf("log10:%2d %4.3f ",i*(5-1)+j+i+1, mas[i*(5-1)+j+i]);
	//		}
	//		printf("\n");
	//	}
	//	
	//	printf("\n");

	//}

// ***************************************************************************
// Денежный вклад
// ***************************************************************************

	//int n = 12;
	//float s = 1000;
	//float delta = 0;
	//int i = 0;
	//while (i < n)
	//{
	//	delta = s * 0.02;
	//	s = s + delta;
	//	cout << delta << " " << s << endl;
	//	i++;
	//}

// ***************************************************************************
// Числа Фибоначчи 
// ***************************************************************************

	//int n = 6;

	//int a = 0;
	//int b = 0;
	//int c = 1;

	//int i = 0;

	//cout << 0 << " ";

	//while (i < n-1)
	//{
	//	cout << c << " ";

	//	a = b;
	//	b = c;
	//	c = a + b;

	//	i++;
	//}


// ***************************************************************************
// Числа Фибоначчи 
// ***************************************************************************

	//int n = 6;

	//int a = 0;
	//int b = 0;
	//int c = 1;

	//int i = 0;

	//cout << 0 << " ";

	//while (i < n-1)
	//{
	//	cout << c << " ";

	//	a = b;
	//	b = c;
	//	c = a + b;

	//	i++;
	//}

// ***************************************************************************
// Золотое сечение
// ***************************************************************************

	//int n = 3;

	//int a = 0;
	//int b = 1;
	//int c = 1;

	//int i = 0;

	//while (i < n)
	//{
	//	cout << (float)c / b << " ";

	//	a = b;
	//	b = c;
	//	c = a + b;

	//	i++;
	//}

// ***************************************************************************
// Числа Фибоначчи не большие n
// ***************************************************************************

	//int n = 5;

	//int a = 0;
	//int b = 0;
	//int c = 1;

	//cout << 0 << " ";

	//while (c <= n)
	//{
	//	cout << c << " ";

	//	a = b;
	//	b = c;
	//	c = a + b;
	//}

// ***************************************************************************
// Число Фибоначчи? 
// ***************************************************************************

	//int n = 12;

	//int a = 0;
	//int b = 0;
	//int c = 1;

	//while (c < n)
	//{
	//	a = b;
	//	b = c;
	//	c = a + b;
	//}

	//if (n == c)
	//	cout << 1;
	//else
	//	cout << 0;


// ***************************************************************************
// Плюс минус 2
// ***************************************************************************

//int n = 6;
//
//int s = 0;
//int sign = 1;
//
//int i = 1;
//
//while (i <= n)
//{
//
//	s = s + sign * i;
//	sign = -sign;
//
//	i++;
//}
//
//cout << s << " ";

// ***************************************************************************
// Плюс минус 3
// ***************************************************************************

	//int n = 4;
	//int s = 2;
	//int sign = 1;
	//int x = 4;
	//int i = 1;
	//while (i < n)
	//{
	//	s = s + sign * x;
	//	x += 2;
	//	sign = -sign;
	//	i++;
	//}
	//cout << s << " ";

// ***************************************************************************
// 0101 первый вариант
// ***************************************************************************

	//int n = 5;
	//int i = 0;
	//while (i < n)
	//{
	//	cout << i % 2 << " ";
	//	i++;
	//}

// ***************************************************************************
// 0101 второй вариант
// ***************************************************************************

	//int n = 5;
	//int i = 0;
	//int b = 1;
	//while (i < n)
	//{
	//	b = !b;
	//	cout << b << " ";
	//	i++;
	//}

// ***************************************************************************
// 123
// ***************************************************************************
	//int n = 5;
	//int i = 0;
	//int b = 0;
	//while (i < n)
	//{
	//	cout << b + 1 << " ";
	//	b = (b + 1) % 3;
	//	i++;
	//}

// ***************************************************************************
// 123
// ***************************************************************************
	//int n = 7;
	//int i = 0;
	//int b = 1;
	//while (i < n)
	//{
	//	if (b > 3)
	//	{
	//		b = 1;
	//	}
	//	cout << b<< " ";
	//	b++;
	//	i++;
	//}

// ***************************************************************************
// 110
// ***************************************************************************
	//int n = 7;
	//int i = 0;
	//int b = 1;
	//while (i < n)
	//{
	//	if (b > 3)
	//	{
	//		b = 1;
	//	}
	//	if (b < 3)
	//		cout << 1 << " ";
	//	else
	//		cout << 0 << " ";
	//	b++;
	//	i++;
	//}

// ***************************************************************************
// Возрастает убывает
// ***************************************************************************

	//int n = 5;
	//int i = 1;
	//while (i <= n)
	//{
	//	cout << i << ":" << n - i + 1 << " ";
	//	i++;
	//}

// ***************************************************************************
// Золотое сечение
// ***************************************************************************

	//int n = 5;

	//int a = 1;
	//int b = 1;
	//int c = 1;

	//int i = 0;

	////cout << "1 ";
	//while (i < n)
	//{
	//	cout << (float)c/b << " ";

	//	a = b;
	//	b = c;
	//	c = a + b;

	//	i++;
	//}

// ***************************************************************************
//чисел ряда Фибоначчи не большие n
// ***************************************************************************

	//int x0, x1, x2;
	//int n = 5;
	//int ch;

	//cin >> n;

	//x0 = 1;
	//x1 = 1;
	//x2 = 1;

	//int i = 1;
	//int f = 0;

	//cout << "1 ";

	//while (x2 <= n)
	//{

	//	i++;

	//	cout << x2 << " ";

	//	if (x2 == n)
	//	{
	//		f = 1;
	//	}

	//	x0 = x1;
	//	x1 = x2;
	//	x2 = x0 + x1;

	//}

	//cout << endl;

	//if (f == 1)
	//{
	//	cout << i;
	//}
	//else
	//{
	//	cout << 0;
	//}


// ***************************************************************************
// Заполняем массив с клавиатуры и выводим его
// ***************************************************************************

    //int arr[10];

    //for (int i = 0; i < 10; i++) {
    //    cout << "[" << i + 1 << "]" << ": ";
    //    cin >> arr[i];
    //}

    //// И выводим заполненный массив.
    //cout << "\nВаш массив: ";

    //for (int i = 0; i < 10; ++i) {
    //    cout << arr[i] << " ";
    //}

    //cout << endl;

// ***************************************************************************
// коды клавиш, коды нажатых клавиш
// ***************************************************************************

	//int a = 0;
	//int i = 0;

	//while(a != 27)
	//{

	//	a = getch();
	//	cout << "Код клавишы = " << a << endl;          

	//}

	// ***************************************************************************
	//Написать программу, которая решает уравнение «ax+b=0» 
	//относительно x для любых чисел a и b, 
	//введенных с клавиатуры. Все числа считаются действительными. 
	// ***************************************************************************


	//float a,b,x;

	//char ch;

	//printf("Начало\n");

	//while((ch = getch()) != 27)
	//{
	//	//count_max = 0;

	//	x = 1;

	//	cout << "a: "; cin >> a; cout << endl;
	//	cout << "b: "; cin >> b; cout << endl;

	//	x = -b/a;

	//	cout << "x = -b/a = " << x << endl;

	//}

	// ***************************************************************************
	// алгоритм поиска номера первого из двух последовательных элементов 
	// в целочисленном массиве из 30 элементов, сумма которых максимальна 
	// (если таких пар несколько, то можно выбрать любую из них).
	// ***************************************************************************

	//int mas[30]; 
	//float sred;
	//int max_element;
	//int nomer_max_element;
	//int min_element;
	//int nomer_min_element;
	//long proiz;
	//char ch;

	//printf("Начало\n");
	//printf("обнуление элементов массива\n");

	//while((ch = getch()) != 27)
	//{
	//	//srand(time(NULL));

	//	sred = 0;
	//	max_element = -999;
	//	nomer_max_element = 0;
	//	min_element = 999;
	//	nomer_min_element = 0;
	//	proiz = 1;

	//	for(int i=0; i<5; i++)
	//	{
	//		mas[i] = rand() % 10;
	//	}

	//	for(int i=0; i<5; i++)
	//	{
	//		if ((mas[i] + mas[i+1]) > max_element)
	//		{
	//			max_element = mas[i] + mas[i+1];
	//			nomer_max_element = i+1;
	//		}

	//	}

	//	for(int j=0; j<5; j++)
	//	{
	//		printf("%4d",mas[j]);
	//	}
	//	printf("\n");
	//	
	//	//printf("Максимальный элемент = %d \n", max_element);
	//	printf("Номер максимального элемента = %d \n", nomer_max_element);
	//}

	// ***************************************************************************
	// метод string.compare()
	// ***************************************************************************

	//std::string str1 ("green apple");
	//std::string str2 ("red apple");

	//cout << str1.compare(str2) << endl;

	//if (str1.compare(str2) != 0)
	//	std::cout << str1 << " is not " << str2 << '\n';

	//if (str1.compare(6,5,"apple") == 0)
	//	std::cout << "still, " << str1 << " is an apple\n";

	//if (str2.compare(str2.size()-5,5,"apple") == 0)
	//	std::cout << "and " << str2 << " is also an apple\n";

	//if (str1.compare(6,5,str2,4,5) == 0)
	//	std::cout << "therefore, both are apples\n";

	//system("pause");
	//return 0;

// ***************************************************************************
// динамический массив, создание, добавление, удаление, вывод
// ***************************************************************************

	//int mas[5] = {1,2,3,4,5};

	//int n = 5;

	//incMas(mas,n);

	//printMas(mas,n);

// ***************************************************************************
// динамический массив, создание, добавление, удаление, вывод
// ***************************************************************************

	//int *mas;

	//int n = 5;

	////assign_rand(mas,n);
	//assign(mas,n, 5);

	//printMas(mas,n);

	//push_back(mas,n,7);
	//printMas(mas,n);

	//pop_back(mas,n);
	//printMas(mas,n);

	//pop_back(mas,n);
	//printMas(mas,n);

	//delete []mas;

// ***************************************************************************
// динамический массив структура, создание, добавление, удаление, вывод
// ***************************************************************************

	//DynMas mas;

	//mas.n = 5;

	//assign(mas,3);

	//printMas(mas);

	//push_back(mas,7);
	//printMas(mas);

	//pop_back(mas,n);
	//printMas(mas,n);

	//pop_back(mas,n);
	//printMas(mas,n);

	//delete []mas;

// ***************************************************************************
//указатель + неуказатель
// ***************************************************************************

//int *p;
//int x = 5;
//*p = 3;
//
//cout << "Сумма " << *p + x << endl;



// ***************************************************************************
// работа с указателями
// ***************************************************************************

 //   int num; // размер массива
 //   cout << "Enter integer value: ";
 //   cin >> num; // получение от пользователя размера массива

 //   int *mas = new int[num]; // Выделение памяти для массива

 //   for (int i = 0; i < num; i++) 
	//{
 //       // Заполнение массива и вывод значений его элементов
 //       mas[i] = i;
 //       cout << "Value of " << i << " element is " << mas[i] << endl;
 //   }
 //   delete [] mas; // очистка памяти

// ***************************************************************************
// простое считывание символов из файла
// ***************************************************************************

	//ifstream file_in("r:\\bib.txt");//создать input-file object тоесть файл ИЗ которого читать  

	//char ch;  

	//if (!file_in.is_open())
	//{
	//	cout<<"Файл не открыт. Программа завершена.\n";
	//	system("pause");
	//	return 0;
	//}
	//
	//int i = 0;

	//file_in.get(ch);//считать один символ из filename  

	//while (!file_in.eof())
	//{
	//	cout << ch;
	//	file_in.get(ch);//считать один символ из filename  
	//}

// ***************************************************************************
// библия статическая
// ***************************************************************************

	//ifstream file_in("r:\\bitie2.txt");//создать input-file object тоесть файл ИЗ которого читать  
	//ofstream file_out("r:\\log.txt");//output-file object, файл В который записывать  

	//char ch;  
	//string s = "";
	//SCountString mas_str[30000];

	////vector <string> vec;

	//if (!file_in.is_open())
	//{
	//	cout<<"Файл не открыт. Программа завершена.\n";
	//	system("pause");
	//	return 0;
	//}
	//
	//int i = 0;

	//while (!file_in.eof())
	//{
	//	// чтение очередного значения из потока F в переменную a
	//	file_in.get(ch);//считать один символ из filename  

	//	// пока специальные символы пропускаем их
	//	while (is_special_char(ch) && !file_in.eof())
	//	{
	//		file_in.get(ch);//считать один символ из filename  
	//	}
	//	
	//	// выделение ссылок на другие части писания заключенных в скобки
	//	if (ch == '(')
	//	{
	//		while (ch != ')')
	//		{
	//			if (file_in.eof())
	//			{
	//				cout << "существует незакрытая скобка" << endl;				
	//				break;
	//			}
	//			s = s + ch;
	//			file_in.get(ch);
	//		}
	//		
	//		if (!file_in.eof())
	//		{
	//			// закоментировал времено что исключить их из списка
	//			//s = s + ch;
	//			//mas_str[i].str = s;
	//			//mas_str[i].count = 1;
	//			//i++;
	//			s = "";
	//			continue;
	//		}
	//	}
	//	
	//	// до тех пор пока не появились специальные символы считываем буквы
	//	// и записываем в строку
	//	while (!is_special_char(ch) && !file_in.eof())
	//	{
	//		s = s + ch;
	//		file_in.get(ch);
	//	}

	//	// если строка является числом пропускаем её
	//	if (
	//		(is_int_digit(s) == 1)
	//          || (s.length() == 1)
	//	   )
	//	{
	//		s = "";
	//		continue;
	//	} 

	//	// записываем слово в массив в случае если такого в нём ещё нет 
	//	bool is_found = 0;
	//	for(int j=0; j<i; j++)
	//	{
	//		if (mas_str[j].str == s)
	//		{
	//			is_found = 1;
	//			mas_str[j].count++;
	//			break;
	//		}
	//	}
	//	if (is_found == 0)
	//	{
	//		mas_str[i].str = s;
	//		mas_str[i].count = 1;
	//		i++;
	//	}

	//	// перед очередным циклом обнуляем строку
	//	s = "";
	//}
	//
	//int num_of_elements = i;

	//int max_length_word = 0;
	//string str_max_word = "";

	//// сортировка массива по количеству повторений слов
	////for (int i = num_of_elements - 1; i >= 0; i--)
	////{
	////	for (int j = 0; j < i; j++)
	////	{
	////		if (mas_str[j].count > mas_str[j+1].count)
	////		{
	////			SCountString tmp = mas_str[j];
	////			mas_str[j] = mas_str[j + 1];
	////			mas_str[j + 1] = tmp;
	////		}
	////	}
	////}

	//// сортировка массива по строкам
	//for (int i = num_of_elements - 1; i >= 0; i--)
	//{
	//	for (int j = 0; j < i; j++)
	//	{
	//		if (mas_str[j].str.compare(mas_str[j+1].str) < 1)
	//		{
	//			SCountString tmp = mas_str[j];
	//			mas_str[j] = mas_str[j + 1];
	//			mas_str[j + 1] = tmp;
	//		}
	//	}
	//}

	//for(int i=0; i < num_of_elements; i++)
	//{

	//	if (mas_str[i].str.length() > max_length_word)
	//	{
	//		max_length_word = mas_str[i].str.length();
	//		str_max_word = mas_str[i].str;
	//	}

	//	file_out << i << " " << mas_str[i].str << " = " << mas_str[i].count<< endl;
	//}
	//
	////file_out << maxxx << endl;
	//cout << str_max_word << endl; //записать символ в filename

	//file_in.close();
	//file_out.close();


	// ***************************************************************************
	// библия динамическая
	// ***************************************************************************

	//ifstream file_in("r:\\bitie3.txt");//создать input-file object тоесть файл ИЗ которого читать  
	//ofstream file_out("r:\\log.txt");//output-file object, файл В который записывать  

	//char ch;  
	//string s = "";
	//SCountString *mas_str = new SCountString[100000];

	////vector <string> vec;

	//if (!file_in.is_open())
	//{
	//	cout<<"Файл не открыт. Программа завершена.\n";
	//	system("pause");
	//	return 0;
	//}
	//
	//int i = 0;

	//while (!file_in.eof())
	//{
	//	// чтение очередного значения из потока F в переменную a
	//	file_in.get(ch);//считать один символ из filename  

	//	// пока специальные символы пропускаем их
	//	while (is_special_char(ch) && !file_in.eof())
	//	{
	//		file_in.get(ch);//считать один символ из filename  
	//	}
	//	
	//	// выделение ссылок на другие части писания заключенных в скобки
	//	if (ch == '(')
	//	{
	//		while (ch != ')')
	//		{
	//			if (file_in.eof())
	//			{
	//				cout << "существует незакрытая скобка" << endl;				
	//				break;
	//			}
	//			s = s + ch;
	//			file_in.get(ch);
	//		}
	//		
	//		if (!file_in.eof())
	//		{
	//			// закоментировал времено что исключить их из списка
	//			//s = s + ch;
	//			//mas_str[i].str = s;
	//			//mas_str[i].count = 1;
	//			//i++;
	//			s = "";
	//			continue;
	//		}
	//	}
	//	
	//	// до тех пор пока не появились специальные символы считываем буквы
	//	// и записываем в строку
	//	while (!is_special_char(ch) && !file_in.eof())
	//	{
	//		s = s + ch;
	//		file_in.get(ch);
	//	}

	//	// если строка является числом пропускаем её
	//	if (
	//		(is_int_digit(s) == 1)
	//          || (s.length() == 1)
	//	   )
	//	{
	//		s = "";
	//		continue;
	//	} 

	//	// записываем слово в массив в случае если такого в нём ещё нет 
	//	bool is_found = 0;
	//	for(int j=0; j<i; j++)
	//	{
	//		if (mas_str[j].str == s)
	//		{
	//			is_found = 1;
	//			mas_str[j].count++;
	//			break;
	//		}
	//	}
	//	if (is_found == 0)
	//	{
	//		mas_str[i].str = s;
	//		mas_str[i].count = 1;
	//		i++;
	//	}

	//	// перед очередным циклом обнуляем строку
	//	s = "";
	//}
	//
	//int num_of_elements = i;

	//int max_length_word = 0;
	//string str_max_word = "";

	//// сортировка массива по количеству повторений слов
	////for (int i = num_of_elements - 1; i >= 0; i--)
	////{
	////	for (int j = 0; j < i; j++)
	////	{
	////		if (mas_str[j].count > mas_str[j+1].count)
	////		{
	////			SCountString tmp = mas_str[j];
	////			mas_str[j] = mas_str[j + 1];
	////			mas_str[j + 1] = tmp;
	////		}
	////	}
	////}

	//// сортировка массива по строкам
	//for (int i = num_of_elements - 1; i >= 0; i--)
	//{
	//	for (int j = 0; j < i; j++)
	//	{
	//		if (mas_str[j].str.compare(mas_str[j+1].str) < 1)
	//		{
	//			SCountString tmp = mas_str[j];
	//			mas_str[j] = mas_str[j + 1];
	//			mas_str[j + 1] = tmp;
	//		}
	//	}
	//}

	//for(int i=0; i < num_of_elements; i++)
	//{

	//	if (mas_str[i].str.length() > max_length_word)
	//	{
	//		max_length_word = mas_str[i].str.length();
	//		str_max_word = mas_str[i].str;
	//	}

	//	file_out << i << " " << mas_str[i].str << " = " << mas_str[i].count<< endl;
	//}
	//
	////file_out << maxxx << endl;
	//cout << str_max_word << endl; //записать символ в filename

	//file_in.close();
	//file_out.close();

	//delete [] mas_str;
	// ***************************************************************************
	// strtok example 
	// ***************************************************************************
	
	//char str[] ="- Это, ну строка для примера.";
	//char * pch;

	//printf ("Splitting \n string \"%s\" into tokens:\n",str);
	//pch = strtok (str," ,.-");

	//while (pch != NULL)
	//{
	//	printf ("%s\n",pch);
	//	pch = strtok (NULL, " ,.-");
	//}

	// ***************************************************************************
	// попытки считать файл по словам
	// ***************************************************************************

	//std::vector<std::string> vec;

	//std::ifstream in( "D:\\note.txt" );

	//if( in.good() ) {
	//	std::transform( std::istream_iterator<std::string>( in ), std::istream_iterator<std::string>(), std::back_inserter( vec ), []( std::string s ) {
	//	std::transform( s.begin(), s.end(), s.begin(), toupper );
	//	return s;
	//} );

	//std::sort( vec.begin(), vec.end() );

	//std::ofstream out( "D:\\note2.txt" );
	//if( out.is_open() )
	//	std::copy( vec.begin(), vec.end(), std::ostream_iterator<std::string>( out, "\n" ) );
	//}

 //   map < string, int > words;
 //   vector < string > vec;

 //   ifstream in( "D:\\note.txt", ios::in );
 //   ofstream out( "D:\\note2.txt", ios::out );
 //
 //   copy( istream_iterator < string >( in ), istream_iterator < string >(), inserter( vec, begin( vec ) ) );

 //   for_each( begin( vec ), end( vec ), [ & ]( string &s )
	//{ 
	//	words[ s ]++; 
	//} );

 //   for_each( begin( words ), end( words ), [ & ]( pair < string, int > p )
	//{ 
	//	out << p.first << " : " << p.second << endl; 
	//} );
 //
 //   in.close();
 //   out.close();

	// ***************************************************************************
	// рабочий пример с std::transform, не всё понятно
	// ***************************************************************************

	//std::vector<int> foo;
	//std::vector<int> bar;

	//// set some values:
	//for (int i=1; i<6; i++)
	//	foo.push_back (i*10);// foo: 10 20 30 40 50

	//bar.resize(foo.size());// allocate space

	//std::transform (foo.begin(), foo.end(), bar.begin(), op_increase);
	//									  // bar: 11 21 31 41 51

	//// std::plus adds together its two arguments:
	//std::transform (foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
	//									  // foo: 21 41 61 81 101

	//std::cout << "foo contains:";
	//for (std::vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
	//	std::cout << ' ' << *it;

	//std::cout << '\n';
	// ***************************************************************************

	// ***************************************************************************
	// библия через vector
	// ***************************************************************************

	//ifstream file_in("r:\\bitie.txt");//создать input-file object тоесть файл ИЗ которого читать  
	//ofstream file_out("r:\\log.txt");//output-file object, файл В который записывать  

	//char ch;  
	//string s = "";
	////SCountString *mas_str = new SCountString[100000];

	//vector <SCountString> vec;
	////SCountString vec_item;


	//if (!file_in.is_open())
	//{
	//	cout<<"Файл не открыт. Программа завершена.\n";
	//	system("pause");
	//	return 0;
	//}
	//
	//int i = 0;

	//while (!file_in.eof())
	//{
	//	// чтение очередного значения из потока F в переменную a
	//	file_in.get(ch);//считать один символ из filename  

	//	// пока специальные символы пропускаем их
	//	while (is_special_char(ch) && !file_in.eof())
	//	{
	//		file_in.get(ch);//считать один символ из filename  
	//	}
	//	
	//	// выделение ссылок на другие части писания заключенных в скобки
	//	if (ch == '(')
	//	{
	//		while (ch != ')')
	//		{
	//			if (file_in.eof())
	//			{
	//				cout << "существует незакрытая скобка" << endl;				
	//				break;
	//			}
	//			s = s + ch;
	//			file_in.get(ch);
	//		}
	//		
	//		if (!file_in.eof())
	//		{
	//			// закоментировал времено что исключить их из списка
	//			//s = s + ch;
	//			//mas_str[i].str = s;
	//			//mas_str[i].count = 1;
	//			//i++;
	//			s = "";
	//			continue;
	//		}
	//	}
	//	
	//	// до тех пор пока не появились специальные символы считываем буквы
	//	// и записываем в строку
	//	while (!is_special_char(ch) && !file_in.eof())
	//	{
	//		s = s + ch;
	//		file_in.get(ch);
	//	}

	//	// если строка является числом пропускаем её
	//	if (
	//		(is_int_digit(s) == 1)
	//          || (s.length() == 1)
	//	   )
	//	{
	//		s = "";
	//		continue;
	//	} 

	//	// ищем слово в массиве, если слово уже есть, новый элемент не добавляем, только увеличиваем счетчик 
	//	bool is_found = 0;

	//	//for(int j=0; j<i; j++)
	//	//{
	//	//	if (mas_str[j].str == s)
	//	//	{
	//	//		is_found = 1;
	//	//		mas_str[j].count++;
	//	//		
	//	//		break;
	//	//	}
	//	//}

	//	for(int i=0; i < vec.size(); i++)
	//	{
	//		if (vec[i].str == s)
	//		{
	//			is_found = 1;
	//			vec[i].count++;
	//			break;
	//		}
	//	}

	//	// записываем слово в массив в случае если такого в нём ещё нет 
	//	if (is_found == 0)
	//	{
	//		if (s != "")
	//		{
	//			SCountString tmp;
	//				tmp.count = 1;
	//				tmp.str = s;
	//			vec.push_back(tmp);
	//		}
	//	}
	//	// перед очередным циклом обнуляем строку
	//	s = "";
	//}

	//
	////int num_of_elements = i;

	//// сортировка массива по количеству повторений слов
	////for (int i = vec.size() - 1; i >= 0; i--)
	////{
	////	for (int j = 0; j < i; j++)
	////	{
	////		if (vec[j].count > vec[j+1].count)
	////		{
	////			SCountString tmp = vec[j];
	////			vec[j] = vec[j + 1];
	////			vec[j + 1] = tmp;
	////		}
	////	}
	////}

	//// сортировка массива по строкам
	//for (int i = vec.size() - 1; i >= 0; i--)
	//{
	//	for (int j = 0; j < i; j++)
	//	{
	//		if (vec[j].str.compare(vec[j+1].str) < 1)
	//		{
	//			SCountString tmp = vec[j];
	//			vec[j] = vec[j + 1];
	//			vec[j + 1] = tmp;
	//		}
	//	}
	//}

	//int max_length_word = 0;
	//string str_max_word = "";

	//for(int i=0; i < vec.size(); i++)
	//{

	//	if (vec[i].str.length() > max_length_word)
	//	{
	//		max_length_word = vec[i].str.length();
	//		str_max_word = vec[i].str;
	//	}

	//	file_out << i << " " << vec[i].str << " = " << vec[i].count<< endl;
	//}
	//
	////file_out << maxxx << endl;
	//cout << str_max_word << endl; //записать символ в filename

	//file_in.close();
	//file_out.close();

	// ***************************************************************************
	// библия через map
	// ***************************************************************************

	//ifstream file_in("r:\\bitie0.txt");//создать input-file object тоесть файл ИЗ которого читать  
	//ofstream file_out("r:\\log.txt");//output-file object, файл В который записывать  

	//char ch;  
	//string s = "";

	//vector <SCountString> vec;
	//map <string,int> words;

	//if (!file_in.is_open())
	//{
	//	cout<<"Файл не открыт. Программа завершена.\n";
	//	system("pause");
	//	return 0;
	//}
	//
	//int i = 0;

	//while (!file_in.eof())
	//{
	//	// чтение очередного значения из потока F в переменную a
	//	file_in.get(ch);//считать один символ из filename  

	//	// пока специальные символы пропускаем их
	//	while (is_special_char(ch) && !file_in.eof())
	//	{
	//		file_in.get(ch);//считать один символ из filename  
	//	}
	//	
	//	// выделение ссылок на другие части писания заключенных в скобки
	//	if (ch == '(')
	//	{
	//		while (ch != ')')
	//		{
	//			if (file_in.eof())
	//			{
	//				cout << "существует незакрытая скобка" << endl;				
	//				break;
	//			}
	//			s = s + ch;
	//			file_in.get(ch);
	//		}
	//		
	//		if (!file_in.eof())
	//		{
	//			// закоментировал времено что исключить их из списка
	//			//s = s + ch;
	//			//mas_str[i].str = s;
	//			//mas_str[i].count = 1;
	//			//i++;
	//			s = "";
	//			continue;
	//		}
	//	}
	//	
	//	// до тех пор пока не появились специальные символы считываем буквы
	//	// и записываем в строку
	//	while (!is_special_char(ch) && !file_in.eof())
	//	{
	//		s = s + ch;
	//		file_in.get(ch);
	//	}

	//	// если строка является числом пропускаем её
	//	if (
	//		(is_int_digit(s) == 1)
	//          || (s.length() == 1)
	//	   )
	//	{
	//		s = "";
	//		continue;
	//	} 

	//	// ищем слово в массиве, если слово уже есть, новый элемент не добавляем, только увеличиваем счетчик 
	//	bool is_found = 0;

	//	//for(int j=0; j<i; j++)
	//	//{
	//	//	if (mas_str[j].str == s)
	//	//	{
	//	//		is_found = 1;
	//	//		mas_str[j].count++;
	//	//		
	//	//		break;
	//	//	}
	//	//}

	//	for(int i=0; i < vec.size(); i++)
	//	{
	//		if (vec[i].str == s)
	//		{
	//			is_found = 1;
	//			vec[i].count++;
	//			break;
	//		}
	//	}

	//	// записываем слово в массив в случае если такого в нём ещё нет 
	//	if (is_found == 0)
	//	{
	//		if (s != "")
	//		{
	//			SCountString tmp;
	//				tmp.count = 1;
	//				tmp.str = s;
	//			vec.push_back(tmp);
	//		}
	//	}
	//	// перед очередным циклом обнуляем строку
	//	s = "";
	//}

	//
	////int num_of_elements = i;

	//// сортировка массива по количеству повторений слов
	////for (int i = vec.size() - 1; i >= 0; i--)
	////{
	////	for (int j = 0; j < i; j++)
	////	{
	////		if (vec[j].count > vec[j+1].count)
	////		{
	////			SCountString tmp = vec[j];
	////			vec[j] = vec[j + 1];
	////			vec[j + 1] = tmp;
	////		}
	////	}
	////}

	//// сортировка массива по строкам
	//for (int i = vec.size() - 1; i >= 0; i--)
	//{
	//	for (int j = 0; j < i; j++)
	//	{
	//		if (vec[j].str.compare(vec[j+1].str) < 1)
	//		{
	//			SCountString tmp = vec[j];
	//			vec[j] = vec[j + 1];
	//			vec[j + 1] = tmp;
	//		}
	//	}
	//}

	//int max_length_word = 0;
	//string str_max_word = "";

	//for(int i=0; i < vec.size(); i++)
	//{

	//	if (vec[i].str.length() > max_length_word)
	//	{
	//		max_length_word = vec[i].str.length();
	//		str_max_word = vec[i].str;
	//	}

	//	file_out << i << " " << vec[i].str << " = " << vec[i].count<< endl;
	//}
	//
	////file_out << maxxx << endl;
	//cout << str_max_word << endl; //записать символ в filename

	//file_in.close();
	//file_out.close();

// ***************************************************************************
// библия через map с итераторами   Частота слов
// ***************************************************************************

	//map <string, int> words;
	//string word;

	//ifstream in;
	//in.open("test.txt");

	//while (in >> word)
	//	words[word]++;

	//in.close();

	//int count=0;

	////ofstream out;
	////out.open("log.txt");

	//cout<<"Words count:"<<endl;

	//for (map <string,int>::iterator cur = words.begin(); cur != words.end(); cur++)
	//{
	//	cout << cur->first << ": " << cur->second << endl;
	//	count += cur->second;
	//}

	//cout<<"Words percenc:"<<endl;

	//for (map <string,int>::iterator cur = words.begin(); cur!=words.end(); cur++)
	//{
	//	cout << cur->first << ": " << cur->second *100.0 / count << "%" << endl;
	//}

	//out.close();

// ***************************************************************************
// Частота слов в файле
// ***************************************************************************

	//vector <StringAndCount> words;
	//string word;

	//ifstream file;
	//file.open("text.txt");

	//while (file.good())
	//{
	//	file >> word;

	//	word = toUpper(word);

	//	if (   word[word.length()-1] == ','
	//		|| word[word.length()-1] == '.'
	//	)
	//		word.erase(word.length()-1);

	//	int pos = find(words, word);
	//	if (pos >= 0)
	//		words[pos].count++;
	//	else{
	//		StringAndCount temp;
	//					   temp.str = word;
	//					   temp.count = 1;

	//		words.push_back(temp);
	//	}
	//}

	//file.close();
	//sort(words);
	//for (int i = 0; i < words.size(); i++)
	//	cout << words[i].str << " " << words[i].count << endl;
	//cout << endl;	

//****************************************************************************************
//Задача №112208. Остатки
//Напишите программу, которая вводит четыре натуральных числа (a, b, c и d) и находит 
//все пятизначные числа, которые при делении на a дают в остатке b , 
//а при делении на c дают в остатке d .
//Входные данные
//Первая входная строка содержит два натуральных числа, разделённые пробелами: a и b. Вторая строка 
//содержит натуральные числа c и d, также разделённые пробелом. Гарантируется, что 0 ≤ b ≤ a и 0 ≤ d ≤ c.
//Выходные данные
//Программа должна вывести в одну строчку через пробел все пятизначные натуральные числа, 
//которые при делении на a дают в остатке b, а при делении на c дают в остатке d . 
//Если таких чисел нет, программа должна вывести число -1.
//Примеры входные данные 133 125 134 111
//выходные данные 19809 37631 55453 73275 91097 
//****************************************************************************************

	//int a = 133, b = 125, c = 134, d = 111; 
	//int i = 0;

	//for (int i = 10000; i < 99999; i++)
	//{
	//	if ((i % a) == b && (i % c) == d)
	//		cout << i << " ";
	//}

	//getch();
	//return 0;

//****************************************************************************************
//Задача №112209. Делимость
//Напишите программу, которая вводит натуральные числа а и b и выводит на экран все натуральные 
//числа на отрезке [ a , b ] , делящиеся на каждую из своих цифр.
//Входные данные
//Входная строка содержит два натуральных числа – значения a и b , разделённых пробелами. 
//Гарантируется, что a ≤ b .
//Выходные данные
//Программа должна вывести в одну строчку все натуральные числа на отрезке [ a , b ] , 
//делящиеся на каждую из своих цифр. Числа разделяются пробелами.
//Примеры входные данные 10 20
//выходные данные 11 12 15
//****************************************************************************************

	//int a = 10, b = 20; 
	//int x = 0;

	//for (int x = a; x <= b; x++)
	//{
	//	int modul = 9999; // деления по модулю
	//	int ost = 0; // деления по модулю

	//	int xx = x;

	//	int is_delitel = 1;

	//	while (modul > 0)
	//	{
	//		modul = xx/10;

	//		ost = xx%10;

	//		if (ost != 0)
	//		{
	//			if (x % ost != 0)
	//				is_delitel = 0;
	//		}
	//		else
	//		{
	//			is_delitel = 0;
	//		}

	//		xx = modul;
	//	}

	//	if (is_delitel == 1)
	//		cout << "delitel = " << x << endl;

	//}

//****************************************************************************************
//Задача №112210. Числа Армстронга
//Натуральное число называется числом Армстронга, если сумма цифр числа, возведенных в K -ю степень 
//(где K – количество цифр в числе) равна самому числу. Например,
//153 = 1^3 + 5^3 + 3^3.
//Напишите программу, которая находит все числа Армстронга на отрезке [ a , b ] .
//Входные данные
//Входная строка содержит два натуральных числа – значения a и b , разделённых пробелами. 
//Гарантируется, что a ≤ b .
//Выходные данные
//Программа должна вывести в одну строчку все числа Армстронга на отрезке [ a , b ] , разделив их пробелами. 
//Если таких чисел нет, программа должна вывести число -1.
//Примеры
//входные данные 100 400
//выходные данные 153 370 371 
//входные данные 500 600
//выходные данные -1
//****************************************************************************************
	//int a = 100, b = 400; 
	//int x = 0;

	//for (int x = a; x <= b; x++)
	//{
	//	int modul = 9999; // деления по модулю
	//	int ost = 0; // деления по модулю
	//	int xx = x;
	//	int is_delitel = 1;
	//	int poww = 0;
	//	int sum1 = 1;
	//	int sum2 = 0;

	//	while (modul > 0)
	//	{
	//		modul = xx/10;
	//		poww++;
	//		xx = modul;
	//	}

	//	xx = x;		
	//	modul = 9999; // деления по модулю

	//	while (modul > 0)
	//	{
	//		modul = xx/10;

	//		ost = xx%10;

	//		for (int i = 0; i < poww; i++)
	//			sum1 = sum1*ost;

	//		sum2 = sum2 + sum1;
	//		sum1 = 1;
	//		xx = modul;
	//	}

	//	if (sum2 == x)
	//		cout << "Armstr = " << x << endl;
	//}

//****************************************************************************************
// форматированный вывод, формат, width #include <iomanip>
//****************************************************************************************

	//float mas[3][5]; 

	//for(int i = 0; i < 3; i++)
	//{
	//	for(int j = 0; j < 5; j++)
	//	{
	//		mas[i][j] = 15; //rand() % 20 ;
	//	}
	//}

	//for(int i = 0; i < 3; i++)
	//{
	//	for(int j = 0; j < 5; j++)
	//	{
	//		// первый способ
	//		//cout.width(6);
	//		//cout.precision(2);
	//		//cout.setf(ios::fixed);
	//		//cout << mas[i][j];
	//		
	//		/*cout.unsetf(ios::dec);
	//		cout.setf(ios::hex);*/
	//		 
	//		//cout.setf(ios::hex, ios::basefield);
	//		//cout << uppercase <<  std::hex << mas[i][j];

	//		// второй способ
	//		//cout  << setfill('0') << right << setw(7) << fixed << setprecision(2) << mas[i][j] << " ";
	//		cout  << fixed << setprecision(2) << mas[i][j] << " ";
	//		//cout  << right << setw(3) << mas[i][j] << "" << setw(3) << 7 << "";

	//	}
	//	cout << endl;
	//}
//****************************************************************************************
//Задача №112148. Разбить на цифры
//Напишите программу, которая вводит трёхзначное число и разбивает его на цифры. 
//Например, при вводе числа 123 программа должна вывести «1 2 3».
//Входные данные Входная строка содержит одно трёхзначное число.
//Выходные данные Программа должна вывести три цифры переданного ей числа, 
//начиная с первой, разделённые пробелами.
//Примеры входные данные 123
//выходные данные 1 2 3
//****************************************************************************************

	//int x = 123; // остаток от целочисленного деления
	//int y = 0;
	//int modul = 9999; // деления по модулю
	//int ost1 = 0; // деления по модулю
	//int ost2 = 0; // деления по модулю
	//int ost3 = 0; // деления по модулю

	//ost1 = x%10;
	//x = x/10;

	//ost2 = x%10;
	//x = x/10;

	//ost3 = x%10;
	//x = x/10;

	//
	//cout << ost3 << " " << ost2 << " " << ost1;


//****************************************************************************************
//Задача №112146. Круг
//Напишите программу, которая вводит радиус круга и вычисляет его площадь и длину окружности.
//Входные данные Входная строка содержит одно число - радиус круга.
//Выходные данные В первой строке должно быть выведена площадь круга, 
// а во второй строке - длина окружности. 
//Оба значения выводятся с тремя знаками в дробной части.
//Примеры входные данные 5
//выходные данные 78.540 31.416
//****************************************************************************************

	//float s = 0; // остаток от целочисленного деления
	//float l = 0; // остаток от целочисленного деления
	//float r = 5;
	//
	//s = M_PI * r * r;
	//l = 2*M_PI * r;

	//cout.precision(7);
	//cout.setf(ios::fixed);

	//cout << " " << s << " " << l;

//****************************************************************************************
//Задача №112149. Расстояние
//Напишите программу, которая вводит координаты двух точек на числовой оси и выводит расстояние между ними.
//Входные данные
//В первой строке вводятся через пробел координаты первой точки (сначала x -координата, потом y -координата), 
//во второй строке в том же порядке – координаты второй точки. Все координаты – вещественные числа.
//Выходные данные
//Программа должна вывести одно число: расстояние между точками с тремя знаками в дробной части.
//Примеры входные данные 1. 1. 2. 2.
//выходные данные 1.414
//****************************************************************************************

	//float x1 = 1; // остаток от целочисленного деления
	//float y1 = 1; // остаток от целочисленного деления
	//float x2 = 2; // остаток от целочисленного деления
	//float y2 = 2; // остаток от целочисленного деления
	//float l = 0;
	//
	//l = sqrt(pow((x2-x1),2) + pow((y2-y1),2));

	//cout.precision(7);
	//cout.setf(ios::fixed);

	//cout << l;


//****************************************************************************************
//Задача №112150. Степень x^y 
//Напишите программу, которая вводит два вещественных числа, x и y , и вычисляет значение x^y .
//Входные данные
//Входная строка содержит два вещественных числа, разделённых пробелом.
//Выходные данные
//Нужно вывести одно значение – x^y – с тремя знаками в дробной части.
//Примеры входные данные 1.23 4.56
//выходные данные 2.570
//****************************************************************************************

	//float x = 1.23; // остаток от целочисленного деления
	//float y = 4.56; // остаток от целочисленного деления
	//float z = 2; // остаток от целочисленного деления
	//
	//z = exp(y * log(x));

	//cout.precision(7);
	//cout.setf(ios::fixed);

	//cout << z;

//****************************************************************************************
//Задача №112152. Случайные вещественные
//Напишите программу, которая вводит два вещественных числа, a и b ( a < b ), и выводит 
//через пробел 5 случайных вещественных чисел в полуинтервале [ a , b ) .
//Входные данные
//Входная строка содержит два вещественных числа a и b , разделённых пробелом. 
//Гарантируется, что a < b .
//Выходные данные
//Нужно вывести в одной строке через пробел 5 случайных вещественных чисел в полуинтервале 
//[ a , b ) с тремя знаками в дробной части.
//Примеры входные данные 1.234 5.678
//выходные данные 1.234 1.373 5.060 2.134 2.447

//****************************************************************************************
// 598.	Случайные вещественные
//****************************************************************************************

	//float  x = 0;
	//for (int i = 0; i<10000; i++)
	//{
	//	x = (float)(rand()%1001) / 1000;
	//	//if (x == 1)
	//	{
	//		cout << x << endl;
	//	}
	//}

//****************************************************************************************
//Задача №112179. Римская система
//Напишите программу, которая выводит запись переданного ей числа в римской системе счисления. Используйте процедуру.
//Входные данные
//Входная строка содержит натуральное число N ( 1 ≤ N ≤ 3999 ).
//Выходные данные
//Программа должна вывести запись числа N в римской системе счисления.
//Примеры входные данные 1234
//выходные данные MCCXXXIV
//****************************************************************************************

	//cout << arab2roman(3234);

//****************************************************************************************
//Задача №112180. Восьмеричный код (10 цифр)
//Напишите программу, которая переводит переданное ей неотрицательное целое число в 
//10-значный восьмеричный код, сохранив лидирующие нули. Используйте процедуру.
//Входные данные
//Входная строка содержит неотрицательное целое число N ( 0 ≤ N < 8^10 ).
//Выходные данные
//Программа должна вывести 10-значный восьмеричный код переданного её числа, 
//сохранив лидирующие нули.
//Примеры входные данные 65
//выходные данные 0000000101
//****************************************************************************************

	//int x = 67; // остаток от целочисленного деления
	//int y = 0;
	//int modul = 9999; // деления по модулю
	//int ost = 0; // деления по модулю

	//int dig[15] = {0}; // деления по модулю

	//int c = 0;
	//int d = 1;

	//while (modul > 0)
	//{
	//	modul = x/8;
	//	ost = x%8;
	//	//cout << ost << " ";
	//	x = modul;
	//	dig[c] = ost;
	//	c++;
	//	d = d * 10;
	//}

	//d = d / 10;

	//for (int i = c-1; i >= 0; i--)
	//{
	//	y = dig[i]*d + y;
	//	d = d / 10;

	//}

	//cout.width(5);
	////cout.precision(7);
	//cout.setf(ios::fixed);
	//cout.fill('0');

	//cout << y;

//****************************************************************************************
//Определить что работает быстрее битовый сдвиг & или деление по остатку
//****************************************************************************************

	//int x = 3; // остаток от целочисленного деления
	//int chet = 0; // деления по модулю

	//unsigned int start_time =  clock(); // начальное время
	//for (int i = 0; i <= 4000000000; i++)
	//{
	//	//x = rand();
	//	//cout << (x&1);

	//	if ((i&1) == 0)
	//	{
	//		chet++;	
	//		//cout << x << " ";
	//	}
	//}


	//cout << chet << endl;
	//chet = 0;

	//unsigned int end_time = clock(); // конечное время
 //   unsigned int search_time = end_time - start_time; // искомое время
	//cout << search_time << endl;

	//start_time =  clock(); // начальное время

	//for (int i = 0; i <= 4000000000; i++)
	//{
	//	//x = rand();
	//	if ((i%2) == 0)//	{
	//		chet++;	
	//		//cout << x << " ";
	//	}
	//}

	//cout << chet << endl;
	//chet = 0;

	//end_time = clock(); // конечное время
 //   search_time = end_time - start_time; // искомое время

	//cout << search_time << endl;


	////cout << "ost = " << ost;

//****************************************************************************************
//Задача №2956. Симметричное число
//Дано четырехзначное число. Определите, является ли его десятичная запись симметричной. Если число симметричное, то выведите 1, иначе выведите любое другое целое число. Число может иметь меньше четырех знаков, тогда нужно считать, что его десятичная запись дополняется слева незначащими нулями.
//При решении этой задачи нельзя пользоваться условной инструкцией if и циклами
//Входные данные Вводится четырехзначное число.
//Выходные данные Выведите ответ на задачу.
//Примеры входные данные 2002
//выходные данные 1
//входные данные 2008
//выходные данные 37
//****************************************************************************************

	//int n = 1221;
	////получаем 3 и 4 цифры
	//int k = n % 100;
	////в n теперь 1 и 2 цифры
	//n = n / 100;
	////в K меняем цифры местами
	//k = k / 10 + k % 10 * 10;
	////если число симметрично (левая и перевернутая правая части равны ) то получается 1, иначе "другое число"
	//cout << (n - k + 1 );

//****************************************************************************************
//Решения системы линейных алгебраических уравнений методом Гаусса. 
//****************************************************************************************
	//double a[3][4]  = 
	//{
	//		{ 2,  1, -1,   8},
	//		{-6, -1,  2, -11},
	//		{-4,  1,  2,  -3}
	//};

	//double x[3];

	//int i,j,k;

	//double m;

	//for (k = 0; k < 3; k++) 
	//{
	//	for (i = k+1; i < 3; i++) 
	//	{
	//		m = a[i][k] / a[k][k];

	//		cout << m;

	//		for (j = 0; j < 4; j++) 
	//		{
	//			a[i][j] = a[i][j] - m * a[k][j];
	//		}
	//	}
	//	cout << endl;
	//}

	////cout.width(7);
	////cout.precision(2);
	////cout.setf(ios::fixed);

	//for (int i = 0; i < 3; i++) 
	//{
	//	for (int j = 0; j < 4; j++) 
	//	{
	//		//cout << a[i][j] << " ";
	//		printf("%7.2f ", a[i][j]);//выравнивание по правому краю ширина точность знаков после запятой
	//	}
	//	cout << endl;
	//}

	//double s;

	////double x1, x2, x0;
	////x2 =  a[2][3]                            / a[2][2];
	////x1 = (a[1][3] - a[1][2]*x2)              / a[1][1];
	////x0 = (a[0][3] - a[0][2]*x2 - a[0][1]*x1) / a[0][0];
	////cout << x0 << " " << x1 << " " << x2 << endl;

	//for (i = 3-1; i >= 0; i--) 
	//{
	//	s = a[i][3];

	//	for (j = 3-1; j > i; j--) 
	//	{
	//		s = s - a[i][j]*x[j];
	//	}

	//	x[i] = s/a[i][i];
	//}

	//for (int i = 0; i < 3; i++) 
	//{
	//	printf("%7.2f ", x[i]);//выравнивание по правому краю ширина точность знаков после запятой
	//}

//****************************************************************************************
//Вычисление определителя (детерминанта) матрицы, Приведение мартицы к треугольному виду
//****************************************************************************************

	//int N = 4;
 //
 //   //cout << "Enter N: ";
 //   //cin >> N;
 //
 //   double **matrix = new double *[N];
 //
 //   for (int i = 0; i < N; i++)
 //       matrix[i] = new double [N];
 //
 //   //for (int i = 0; i < N; i++)
 //   //    for (int j = 0; j < N; j++)
 //   //    {
 //   //        matrix[i][j] = rand()%4;
 //   //    }
 //
	////matrix[0][0] = 7; matrix[0][1] =  4;  matrix[0][2] =  9;
	////matrix[1][0] = 0; matrix[1][1] =  6;  matrix[1][2] = -3; 
	////matrix[2][0] = 4; matrix[2][1] = -10; matrix[2][2] = -4;

	//matrix[0][0] = -4; matrix[0][1] = -2;  matrix[0][2] = -7;  matrix[0][3] =  8;
	//matrix[1][0] =  2; matrix[1][1] =  7;  matrix[1][2] =  4;  matrix[1][3] =  9;
	//matrix[2][0] =  2; matrix[2][1] =  0; matrix[2][2] =   6;  matrix[2][3] =  -3;
	//matrix[3][0] =  6; matrix[3][1] =  4; matrix[3][2] = -10;  matrix[3][3] =  -4;

	//cout << matrix_treygoln_vid(matrix, N);

	//print_arr(matrix, N);

//****************************************************************************************
//Нахождение обратной матрицы. Обратная матрица
//****************************************************************************************

	//int N;
 //
 //   cout << "Enter N: ";
 //   cin >> N;
 //
 //   double **matrix = new double *[N];
 //
 //   for (int i = 0; i < N; i++)
 //       matrix[i] = new double [N];
 //
 //   for (int i = 0; i < N; i++)
 //       for (int j = 0; j < N; j++)
 //       {
 //           matrix[i][j] = rand()%4;
 //       }
 //
	//matrix[0][0] = 2; matrix[0][1] = 8; matrix[0][2] = 4;
	//matrix[1][0] = 2; matrix[1][1] = 4; matrix[1][2] = 2; 
	//matrix[2][0] = 2; matrix[2][1] = 2; matrix[2][2] = 4;

	//print_arr(matrix, N);

	//
	//inversion(matrix, N);
 //

	//print_arr(matrix, N);

 //   for (int i = 0; i < N; i++)
 //       delete [] matrix[i];
 //
 //   delete [] matrix;

//****************************************************************************************
//Описать процедуру Transp(AA, MM), выполняющую транспонирование (то есть зеркальное отражение 
//относительно главной диагонали) квадратной вещественной матрицы A порядка M. 
//Матрица A является входным и выходным параметром. 
//Используя эту процедуру, транспонировать данную матрицу A порядка M.
//****************************************************************************************
	//double a[4][4]  = 
	//{
	//		{ 2,  1, -1,   8},
	//		{-6, -1,  2, -11},
	//		{-4,  1,  2,  -3},
	//		{ 4,  3,  1,  -3}
	//};

	//int i,j;

	//double m;

	//for (i = 0; i < 4-1; i++) 
	//{
	//	for (j = 1+i; j < 4; j++) 
	//	{
	//		double m;
	//		m = a[i][j];
	//		a[i][j] = a[j][i] ;
	//		a[j][i] = m;
	//	}
	//} 

	//for (int i = 0; i < 4; i++) 
	//{
	//	for (int j = 0; j < 4; j++) 
	//	{
	//		//cout << a[i][j] << " ";
	//		printf("%7.2f ", a[i][j]);//выравнивание по правому краю ширина точность знаков после запятой
	//	}
	//	cout << endl;
	//}

//****************************************************************************************
// Обмен диагоналей
//****************************************************************************************
	//const int n = 4;
	//int a[n][n]  = 
	//{
	//		{ 2, 1, 1, 8},
	//		{ 6, 1, 2, 1},
	//		{ 4, 1, 2, 3},
	//		{ 4, 3, 1, 3}
	//};

	//for (int i = 0; i < n; i++) 
	//{
	//	int m;
	//	m = a[i][i];
	//	a[i][i] = a[i][n-1-i];
	//	a[i][n-1-i] = m;
	//} 

	//for (int i = 0; i < n; i++) 
	//{
	//	for (int j = 0; j < n; j++) 
	//	{
	//		cout << a[i][j] << " ";
	//	}
	//	cout << endl;
	//}


//****************************************************************************************
// Только два
//****************************************************************************************

	//const int n = 4;
	//int a[n][n]  = 
	//{
	//		{ 2, 1, 1, 8},
	//		{ 6, 1, 2, 1},
	//		{ 4, 1, 2, 3},
	//		{ 4, 3, 1, 3}
	//};

	//for (int i = 0; i < n; i++) 
	//{
	//	int m;
	//	m = a[i][i];
	//	a[i][i] = a[i][n-1-i];
	//	a[i][n-1-i] = m;
	//} 

	//for (int i = 0; i < n; i++) 
	//{
	//	for (int j = 0; j < n; j++) 
	//	{
	//		cout << a[i][j] << " ";
	//	}
	//	cout << endl;
	//}

//****************************************************************************************
//рисование синусоиды
//****************************************************************************************

	//POINT op;
	//
	//HWND hWnd=GetConsoleWindow();//Функция GetConsoleWindow извлекает дескриптор окна, используемый консолью, связанной с вызывающим процессом.
	//HDC hDC=GetDC(hWnd);//Функция GetDC извлекает дескриптор дисплейного контекста устройства (DC) для рабочей области заданного окна или для всего экрана.

	//// позволит узнать ширину окна
	////RECT rect;
	////GetClientRect(hWnd, &rect);
	//////Это ширина и высота консольного окна в ПИКСЕЛЯХ, но не в символах
	////int sh = rect.right- rect.left;
	////int vi = rect.bottom- rect.top;

	//// 640 на 300 пикселей

	//int   xx = 320, y;
	//float x = 0, step = -4*M_PI / 50;
	//
	////HPEN hPen = CreatePen ( PS_NULL , 1 , RGB ( 0 , 0 , 0 ) ) ;

	//SelectObject(hDC,GetStockObject(WHITE_PEN));
	//
	//while (true)
	//{
	//	x = 0;
	//	xx = 320;
	//		
	//	SelectObject(hDC,GetStockObject(WHITE_PEN));

	//	MoveToEx(hDC,320,0,&op);
	//	LineTo(hDC,320,300);
	//	MoveToEx(hDC,0,150,&op);
	//	LineTo(hDC,640,150);

	//	MoveToEx(hDC,320,150,&op);

	//	for (int i = 0; i <= 50; i++) 
	//	{

	//		y = sin(x)*70 + 150;

	//		SelectObject(hDC,GetStockObject(WHITE_PEN));
	//		SelectObject(hDC,GetStockObject(BLACK_BRUSH));
	//		//LineTo(hDC,xx,y);

	//		//rgbval = RGB(Int(256 * Rnd), Int(256 * Rnd), Int(256 * Rnd))
	//		SetPixel(hDC, xx, y, RGB(255, 255, 0));


	//		x = x + step;
	//		xx = xx + 5;
	//	
	//		//SelectObject(hDC,GetStockObject(WHITE_BRUSH));
	//		Ellipse(hDC,xx, y, xx+20, y+20);
	//		Sleep(100);

	//		SelectObject(hDC,GetStockObject(BLACK_PEN));
	//		//SelectObject(hDC,hPen);
	//		Ellipse(hDC,xx, y, xx+20, y+20);
	//	}

	//	//x = 0;
	//	//xx = 320;


	//	//MoveToEx(hDC,320,150,&op);
	//	//for (int i = 0; i <= 50; i++) 
	//	//{

	//	//	y = cos(x)*70 + 150;

	//	//	LineTo(hDC,xx,y);

	//	//	x = x + step;
	//	//	xx = xx + 5;

	//	//}

	//	//SelectObject(hDC,GetStockObject(WHITE_PEN));
	//	//Rectangle(hDC, 200, 100, 300, 200);

	//	//InvalidateRect (hWnd, NULL, FALSE);

	//}

	//ReleaseDC(hWnd,hDC);

//****************************************************************************************
//шарик в прямоуголнике
//****************************************************************************************

	//POINT op;
	//
	//HWND hWnd=GetConsoleWindow();//Функция GetConsoleWindow извлекает дескриптор окна, используемый консолью, связанной с вызывающим процессом.
	//HDC hDC=GetDC(hWnd);//Функция GetDC извлекает дескриптор дисплейного контекста устройства (DC) для рабочей области заданного окна или для всего экрана.

	//int  xx = 320, y;
	//float x = 0, step = -4*M_PI / 50;
	//
	////HPEN hPen = CreatePen ( PS_NULL , 1 , RGB ( 0 , 0 , 0 ) ) ;

	//SelectObject(hDC,GetStockObject(WHITE_PEN));
	//	x = 320;
	//	y = 150;
	//	int dir = 1;
	//
	//while (true)
	//{
	//	//xx = 320;
	//		
	//	SelectObject(hDC,GetStockObject(WHITE_PEN));
	//	SelectObject(hDC,GetStockObject(BLACK_BRUSH));

	//	Rectangle(hDC, 120, 20, 520, 280);

	//	MoveToEx(hDC,320,150,&op);

	//	//for (int i = 0; i <= 50; i++) 
	//	{

	//		

	//		//LineTo(hDC,xx,y);


	//		if ((x < 520-20) && (dir == 1))
	//		{
	//			x = x + 1;
	//		} else
	//		{
	//			dir = 0;
	//		}
	//		
	//		if ((x > 120) && (dir == 0))
	//		{
	//			x = x - 1;
	//		} else
	//		{
	//			dir = 1;
	//		}

	//		//if (dir == 1)
	//		//{
	//		//
	//		//}else{

	//		//	x = x - 1;
	//		//}

	//		SelectObject(hDC,GetStockObject(WHITE_PEN));
	//		SelectObject(hDC,GetStockObject(BLACK_BRUSH));
	//	
	//		//SelectObject(hDC,GetStockObject(WHITE_BRUSH));
	//		Ellipse(hDC,x, y, x+20, y+20);
	//		Sleep(5);

	//		SelectObject(hDC,GetStockObject(BLACK_PEN));
	//		//SelectObject(hDC,hPen);
	//		Ellipse(hDC,x, y, x+20, y+20);
	//	}


	//}

	//ReleaseDC(hWnd,hDC);

//****************************************************************************************
//рисование покруче
//****************************************************************************************
    //HWND hWnd = GetForegroundWindow();

    //HPEN    RPEN = getPen(PS_SOLID, 2, RED);
    //HPEN    GPEN = getPen(PS_SOLID, 2, GRN);
    //HPEN    BPEN = getPen(PS_SOLID, 2, BLU);
    //HPEN    WPEN = getPen(PS_SOLID, 3, WHT);

    //RECT    pRECT= {0};
    //COORD   POS  = {0};
    //COORD   BGN  = setCordScale(POS,pRECT);

    //GetWindowRect(hWnd,&pRECT);
    //HDC hDC = GetWindowDC(hWnd);

    //if(hDC)
    //{
    //    SetBkMode(hDC,TRANSPARENT);
    //    SetPoint (hDC, WPEN, BGN);
    //    POS.X = BGN.X + 50;
    //    POS.Y = BGN.Y + 100;
    //    
    //    PlotRect(hDC, BPEN, BGN, POS);
    //    PlotLine(hDC, RPEN, BGN, POS);
    //    SetPoint (hDC, WPEN, BGN);
 
    //    BGN = POS;
    //    POS.X = BGN.X + 100;
    //    POS.Y = BGN.Y + 100;
    //    PlotCirc(hDC, GPEN, BGN, POS);
    //}
//****************************************************************************************
//не проверял
//****************************************************************************************

	//HWND hWnd=GetConsoleWindow();
 //   HDC hDC=GetDC(hWnd);
 //
 //   RECT rect;
 //   GetClientRect(hWnd,&rect);
 //
 //   POINT oldPoint ;
 //   const float d = 0.1 ;
 //   const float min = -10.0f ;
 //   const float max = 10.0f ;
 //   const float multV = 20.0f ;
 //   const float multH = 10.0f ;
 //
 //   POINT center ;
 //   center.x = (rect.right-rect.left) / 2 ;
 //   center.y = (rect.bottom-rect.top) / 2 ;
 //
 //   HDC hBufferDC=CreateCompatibleDC(hDC);
 //   HBITMAP hBufferBmp=CreateBitmap(rect.right,rect.bottom,1,32,NULL);
 //   HBITMAP hBufferBmpOld=(HBITMAP)SelectObject(hBufferDC,hBufferBmp);
 //   FillRect(hBufferDC,&rect,(HBRUSH)GetStockObject(WHITE_BRUSH));    
 //
 //   HPEN hPen = CreatePen ( PS_SOLID , 1 , RGB ( 0 , 0 , 0 ) ) ;
 //   HPEN hOldPen = (HPEN)SelectObject(hBufferDC,hPen);  
 //   
 //   MoveToEx ( hBufferDC , center.x , 0 , &oldPoint ) ;
 //   LineTo ( hBufferDC , center.x , rect.bottom ) ;
 //   MoveToEx ( hBufferDC , 0 , center.y , &oldPoint ) ;
 //   LineTo ( hBufferDC , rect.right , center.y ) ;
 //
 //   hPen = CreatePen ( PS_SOLID , 1 , RGB ( 255 , 0 , 0 ) ) ;
 //   DeleteObject ( SelectObject(hBufferDC,hPen) ) ;
 //
 //   MoveToEx ( hBufferDC , multH * min + center.x , -multV * sin(min) + center.y , &oldPoint ) ;
 //   for ( float x = min+d ; x < max ; x+=d ) {
 //       float y = sin ( x ) ;
 //       LineTo ( hBufferDC , multH * x + center.x , -multV * y + center.y ) ;
 //   }
 //
 //   BitBlt(hDC,0,0,rect.right,rect.bottom,hBufferDC,0,0,SRCCOPY);
 //   DeleteObject ( SelectObject(hBufferDC,hOldPen) ) ;
 //   SelectObject(hBufferDC,hBufferBmpOld);
 //   DeleteObject(hBufferBmp);
 //   DeleteDC(hBufferDC);
 //   ReleaseDC(hWnd,hDC);
//****************************************************************************************
//вывод квадратика с окошком
//****************************************************************************************
	//int x = 0, y = 0;
	//int a = 20, b = 4;

	//while (y < a)
	//{
	//	while (x < a)
	//	{

	//		//if (x< a && y<b)
	//		//	cout << "*";
	//		//else if (y>=b && y < (a-b) && (x>=0 && x<b || x>(a-b-1) && x<a))
	//		//	cout << "*";
	//		//else if (x<a && y>(a-b-1))
	//		//	cout << "*";
	//		//else
	//		//	cout << " ";

	//		if   ((x< a && y<b)
	//		   || (y>=b && y < (a-b) && (x>=0 && x<b || x>(a-b-1) && x<a))
	//		   || (x<a  && y>(a-b-1)))
	//			cout << "*";
	//		else
	//			cout << " ";


	//		x++;
	//	}
	//	cout << endl;
	//	x = 0;
	//	y++;
	//}
//****************************************************************************************
//зациклить ввод данных
//****************************************************************************************

	//int x = 100;
	//while (x != 0)
	//{
	//	cin >> x;
	//	cout << x*x;
	//}
//****************************************************************************************
//Ладья 
//****************************************************************************************

	//int x1 = 4, y1 = 4;
	//int x2 = 4, y2 = 4;
	//
	//if (x1 == x2 || y1 == y2)
	//{
	//	cout << "бьёт";
	//}
//****************************************************************************************
//слон В одном ряду, в одном столбце, на одной диагонали
//****************************************************************************************

	//int x1 = 1, y1 = 4;
	//int x2 = 1, y2 = 4;
	//
	//if (abs(x1-x2) == abs(y1 - y2))
	//{
	//	cout << "бьёт";
	//}
//****************************************************************************************
//король Соседние точки 1
//****************************************************************************************

	//int x1 = 5, y1 = 5;
	//int x2 = 0, y2 = 0;

	//while (1)
	//{
	//	x2 = rand()%120;
	//	y2 = rand()%30;
	//	
	//	if (x1 == x2     && y1 + 1 == y2 ||
	//		x1 == x2     && y1 - 1 == y2 ||
	//		y1 == y2     && x1 + 1 == x2 ||
	//		y1 == y2     && x1 - 1 == x2 ||
	//		x1 == x2 + 1 && y1 + 1 == y2 ||
	//		x1 == x2 + 1 && y1 - 1 == y2 ||
	//		x1 == x2 - 1 && y1 + 1 == y2 ||
	//		x1 == x2 - 1 && y1 - 1 == y2
	//	   )
	//	{
	//		gotoxy(x2,y2);
	//		cout << "*";
	//	}
	//}

//****************************************************************************************
//король Соседние точки 2
//****************************************************************************************

	//int x1 = 1, y1 = 1;
	//int x2 = 1, y2 = 2;
	//int d = abs(x1-x2) + abs(y1-y2);
	//
	//if (d == 1 || d == 2)
	//{
	//	cout << "бьёт";
	//}


//****************************************************************************************
//конь
//****************************************************************************************

	//int x1 = 5, y1 = 5;
	//int x2 = 0, y2 = 0;

	//while (1)
	//{
	//	x2 = rand()%120;
	//	y2 = rand()%30;
	//	
	//	if (x1 + 1 == x2 && y1 + 2 == y2 ||
	//		x1 + 1 == x2 && y1 - 2 == y2 ||
	//		x1 - 1 == x2 && y1 + 2 == y2 ||
	//		x1 - 1 == x2 && y1 - 2 == y2 
	//		//y1 == y2     && x1 + 1 == x2 ||
	//		//y1 == y2     && x1 - 1 == x2 ||
	//		//x1 == x2 + 1 && y1 + 1 == y2 ||
	//		//x1 == x2 + 1 && y1 - 1 == y2 ||
	//		//x1 == x2 - 1 && y1 + 1 == y2 ||
	//		//x1 == x2 - 1 && y1 - 1 == y2
	//	   )
	//	{
	//		gotoxy(x2,y2);
	//		cout << "*";
	//	}
	//}



//****************************************************************************************
// пузырьковая сортировка на разных языках
//****************************************************************************************

//const int N = 5;
//int mas[N] = {11, 3, 14, 16, 7};
//int tmp;
//
//for(int i = 0; i < N-1; i++)
//{
//	for(int j = 0; j < N-1; j++)
//	{
//		if (mas[j] > mas[j+1])
//		{
//			tmp = mas[j];
//			mas[j] = mas[j+1];
//			mas[j+1] = tmp;
//		}
//	}
//}

//int [] mas = {11, 3, 14, 16, 7};
//int tmp;
//
//for(int i = 0; i < mas.length-1; i++)
//{
//    for(int j = 0; j < mas.length-1; j++)
//    {
//        if (mas[j] > mas[j+1])
//        {
//            tmp = mas[j];
//            mas[j] = mas[j+1];
//            mas[j+1] = tmp;
//        }
//    }
//}
//
//int[] mas = new int[] {11, 3, 14, 16, 7}; 
//int tmp;
//
//for(int i = 0; i < mas.Length-1; i++)
//{
//    for(int j = 0; j < mas.Length-1; j++)
//    {
//        if (mas[j] > mas[j+1])
//        {
//            tmp = mas[j];
//            mas[j] = mas[j+1];
//            mas[j+1] = tmp;
//        }
//    }
//}  


//****************************************************************************************
//Сортировка пузырьком
//****************************************************************************************
//о чём урок
//постановка задачи
//один из навыков разобраться с уже готовым алгоритмом
//упорядочить по убыванию, по возрастанию
//увеличить шрифт до 24 и делаем  7 5 3 1 8
//указываем сколько тактов 4, почему только 4 такта
//потому что сравнений четыре
//в конце цикла оказалось максимальное число
//количество сравнений и тактов будет уменьшаться потому что последний символ макс
//не смотря на то что массив отсортирован алгоритм об этом не знает
//сколько раз это должно повториться 4 раза N-1
//как вариант алгоритм можно делать по частям
//делаем сеачала только вложенный
// потом обрамляем внешним
// оптимизация алгоритма, другой набор данных
// добавить флажок чтобы отслеживал были обмены
// сортировка по убыванию
// 7 5 3 1 8
// 5-3-1-7-8 - 4 такта 
// 3-1-5-7 8 - 3 такта
// 1-3-5 7 8 - 2 такта 
// 1-3 5 7 8 - 1 такт

	//const int N = 5;

	//int mas[N] = {11, 3, 14, 16, 7};
	//int tmp;

	//for(int i = 0; i < N; i++) // внутренний цикл прохода
	//{
	//	cout << mas[i] << " ";
	//}
	//cout << endl;

	//for(int i = 0; i < N-1; i++) // внутренний цикл прохода
	//{
	//	bool f = 0;
	//	for(int j = 0; j < N-1; j++) // внутренний цикл прохода
	//	{
	//		if (mas[j] > mas[j+1])
	//		{
	//			tmp = mas[j];
	//			mas[j] = mas[j+1];
	//			mas[j+1] = tmp;
	//			f = 1;
	//		}
	//	}
	//	cout << endl;
	//	for(int i = 0; i < N; i++) // внутренний цикл прохода
	//	{
	//		cout << mas[i] << " ";
	//	}
	//	if (f == 0)
	//		break;
	//}


	//for(int i = 0; i < N-1; i++) // внутренний цикл прохода
	//{
	//	bool f = 0;
	//	for(int j = N-1; j > i; j--) // внутренний цикл прохода
	//	{
	//		if (mas[j] > mas[j-1])
	//		{
	//			tmp = mas[j];
	//			mas[j] = mas[j-1];
	//			mas[j-1] = tmp;
	//			f = 1;
	//		}
	//	}
	//	cout << endl;
	//	for(int i = 0; i < N; i++) // внутренний цикл прохода
	//	{
	//		cout << mas[i] << " ";
	//	}
	//	if (f == 0)
	//		break;
	//}


	//const int N = 5;

	//int arr[N] = {4,3,2,1,0};
	//int tmp;

	//for(int i = 0; i < N-1; i++) // i - номер прохода
	//{            
	//	for(int j = 0; j < N-1-i; j++) // внутренний цикл прохода
	//	{     
	//		if (arr[j] > arr[j+1])
	//		{
	//			tmp = arr[j];
	//			arr[j] = arr[j+1];
	//			arr[j+1] = tmp;
	//		}
	//	}
	//}

	//for(int i = 0; i < N; i++) // внутренний цикл прохода
	//{
	//	cout << arr[i] << " ";
	//}

//****************************************************************************************
//цвет текста и фона
//****************************************************************************************
	//cout << "ghdtn";
	//set_color(15,10);
	//cout << "ghdtn";

//****************************************************************************************
//цвет текста и фона
//****************************************************************************************

	//time_t timer = time(NULL);
	//printf("%s\n", ctime(&timer));

//****************************************************************************************
//работа с датой и временем, дата и время дата время
//****************************************************************************************
	// 1.
	//string data = __DATE__;

	//cout << data;

	//cout<<__DATE__<<endl<<__TIME__;



	// 2.
	//char dateStr [9];
	//char timeStr [9];
	//
	//_strdate( dateStr);

	//// дату в формате char to string
	//string s(dateStr);
	//cout << s;

	//printf( "Текущая дата: %s \n", dateStr);
	//_strtime( timeStr );
	//printf( "Текущее время: %s \n", timeStr);

	// 3.
	//SYSTEMTIME st;
	//GetLocalTime(&st);
	//cout << "Год:" << st.wYear << endl;
	//cout << "Месяц:" << st.wMonth << endl;
	//cout << "День:" << st.wDay << endl;
	//cout << "Час:" << st.wHour << endl;
	//cout << "Минута:" << st.wMinute << endl;
	//cout << "Секунда:" << st.wSecond << endl;

//****************************************************************************************
// вывод кодов символа в цикле
//****************************************************************************************
	
	//int ch = 0;

	//while (ch != 27) 
	//{
	//	while(!kbhit())// пока не нажата клавиша
	//	{}

	//	ch = getch();
	//	cout << ch << endl;
	//};

//****************************************************************************************
// 48.	Буфер клавиатуры
//****************************************************************************************
	
	//queue <int> que;

	//int ch = 0;

	//while (ch != 27) 
	//{
	//	while(!kbhit())// пока не нажата клавиша
	//	{
	//		if(!que.empty())
	//		{
	//			que.pop();
	//			print(que);
	//		}
	//		Sleep(500);
	//	}

	//	ch = getch();
	//	if (que.size() < 5)
	//		que.push(ch);
	//	else 
	//		cout << "full" << endl;
	//	print(que);
	//};

//****************************************************************************************
//Задача №3064. Длина последовательности
//Программа получает на вход последовательность целых неотрицательных чисел, каждое число записано в отдельной строке. 
//Последовательность завершается числом 0, при считывании которого программа должна закончить свою работу и вывести 
//количество членов последовательности (не считая завершающего числа 0).
//Числа, следующие за числом 0, считывать не нужно.
//Входные данные
//Вводится последовательность целых чисел, оканчивающаяся числом 0 (само число 0 в последовательность не входит).
//Выходные данные
//Выведите ответ на задачу.
//Примеры
//входные данные 1 7 9 0 5
//выходные данные 3
//****************************************************************************************

	//int x = 1;
	//int c = 0;

	//while (x != 0) 
	//{

	//	cin >> x;
	//	c++;

	//};

	//c--;

	//cout << c << endl;

//****************************************************************************************
// проверка на вхождение в область неравенство x >= y
//****************************************************************************************
	//int x = 1;
	//int y = 0;

	//cin >> x >> y;

	//if (x >= y) 
	//{

	//	cout << "1";

	//} else {

	//	cout << "0";
	//
	//};


//****************************************************************************************
// сравнение 2-х строк
//****************************************************************************************
	//string str1 = "привет";
	//string str2 = "привет";


	//bool is_equal = true;

	//for(int i = 0; i < str1.length(); i++)
	//{
	//	if (str1[i] != str2[i])
	//	{
	//		is_equal = false;
	//	}
	//}

	//if (is_equal == true)
	//{
	//	cout << true;
	//} else 
	//{
	//	cout << false;
	//}

//****************************************************************************************
// Арифметика
//****************************************************************************************

	//string str = "1+5-2+9";

	//int sum;

	//sum = str[0]-48;

	//for(int i = 1; i < str.length(); i+=2)
	//{
	//	if (str[i] == '+')
	//	{
	//		sum = sum + (str[i+1]-48);
	//	}
	//	else
	//	{
	//		sum = sum - (str[i+1]-48);
	//	}
	//}
	//
	//cout << sum << endl;


//****************************************************************************************
// Шифр Цезаря
//****************************************************************************************

	// крипт
	//string str1 = "XYZ";
	//string str2 = "";

	//for(int i = 0; i < str1.length(); i++)
	//{
	//	char ch = str1[i] + 3;
	//	if (ch > 90)
	//	{
	//		ch -= 26;
	//	}
	//	str2  += ch;
	//}
	//cout << str2;

	//// декрипт
	//str1 = "";

	//for(int i = 0; i < str2.length(); i++)
	//{
	//	char ch = str2[i] - 3;
	//	if (ch < 65)
	//	{
	//		ch += 26;
	//	}
	//	str1  += ch;
	//}
	//cout << str1;

//****************************************************************************************
// Гласные – согласные
//****************************************************************************************

	//string str = "AUOBC";
	//string str_glas = "AEIOU";

	//string str1;
	//string str2;


	//for(int i = 0; i < str.length(); i++)
	//{
	//	bool f = 0;

	//	for(int j = 0; j < str_glas.length(); j++)
	//	{
	//		if (str[i] == str_glas[j])
	//		{
	//			f = 1;
	//			break;
	//		}
	//	}

	//	if (f)
	//	{
	//		str1  += str[i];
	//	}
	//	else
	//	{
	//		str2  += str[i];
	//	}
	//}
	//
	//cout << str1 << endl;
	//cout << str2;

//****************************************************************************************
// Гласные – согласные 2
//****************************************************************************************

	//string str = "privet kak dela";
	//string str_glas = "AEIOU";

	//string str1;
	//string str2;

	//for(int i = 0; i < str.length(); i++)
	//{
	//	bool f = 0;

	//	int res = str_glas.find(str[i]); 

	//	if (res >= 0)
	//	{
	//		str1  += str[i];
	//	}
	//	else
	//	{
	//		str2  += str[i];
	//	}
	//}
	//
	//cout << str1 << endl;
	//cout << str2;

//****************************************************************************************
// Незначащие нули
//****************************************************************************************
	//int x = 123;
	//string str = to_string(x);
	//int len = str.length();
	//int a = 6;
	//for(int i = 0; i < a - len; i++)
	//{
	//	str = '0' + str;
	//}
	//cout << str;
//****************************************************************************************
// Поиск подстроки
//****************************************************************************************

	//string str = "sss p";
	//string s = "sp";

	//int pos = -1;

	//for(int i = 0; i < str.length() - s.length() + 1; i++)
	//{
	//	bool eq = 1;

	//	for(int j = 0; j < s.length(); j++)
	//	{
	//		if (s[j] != str.[i + j])
	//		{
	//			eq = 0;
	//			break;
	//		}
	//		
	//	}

	//	if (eq)
	//	{
	//		pos = i;
	//		break;
	//	}
	//}

	//
	//cout << pos << endl;

//****************************************************************************************
// количество слов в предложении
//****************************************************************************************
	//char str[] = "privet kak dela a";
	//int k = 0;
	//if (strlen(str) != 0)
	//	k = 1;
	//for(int i = 0; i < strlen(str); i++)
	//{
	//	if (str[i] == ' ')
	//	{
	//		k++;
	//	}
	//}
	//cout << k;

//****************************************************************************************
// Количество цифр
//****************************************************************************************
	
	//char str[] = "pri123";
	//int k = 0;
	//for(int i = 0; i < strlen(str); i++)
	//{
	//	if (str[i] >= 48 && str[i] <= 57)
	//	{
	//		k++;
	//	}
	//}
	//cout << k;

//****************************************************************************************
// Число или нет
//****************************************************************************************
	
	//char str[] = "123";
	//bool f = 1;
	//for(int i = 0; i < strlen(str); i++)
	//{
	//	if (isdigit(str[i]) == 0)
	//	{
	//		f = 0;
	//		break;
	//	}
	//}
	//cout << f;

	//cout << isdigit('0');
	//cout << isdigit('a');

//****************************************************************************************
// количество слов в предложении
//****************************************************************************************
	//string str1 = "privet kak dela a";
	//int k = 0;
	//for(int i = 0; i < str1.length(); i++)
	//{
	//	if (str1[i] == ' ')
	//	{
	//		k++;
	//	}
	//}
	//k++;
	//cout << k;
//****************************************************************************************
// Удвоенное d
//****************************************************************************************
	//int k = 0;

	//char str[] = "dd ba dd";

	//for(int i=0; i<strlen(str)-1; i++)
	//{
	//	if (str[i] == 'd' && str[i+1]=='d')
	//	{
	//		k = k + 1;
	//	}
	//}

	//cout << k << endl;
//****************************************************************************************
// Слова с буквы b
//****************************************************************************************
	//string str1 = "bprivet bkak bdela b";

	//int k = 0;

	//if (str1[0] == 'b')
	//{
	//	k++;
	//}

	//bool flag = false;

	//for(int i = 0; i < str1.length(); i++)
	//{
	//	if (flag)
	//	{
	//		if (str1[i] == 'b')
	//		{
	//			k++;
	//		}
	//		flag = false;
	//	}

	//	if (str1[i] == ' ')
	//	{
	//		flag = true;
	//	}
	//}

	//cout << k;

//****************************************************************************************
// Слова с буквы b два символа
//****************************************************************************************
	//int k = 0;

	//char str[] = "ba sss bas";

	//if (str[0] == 'b')
	//{
	//	k = 1;
	//}

	//for(int i=0; i<strlen(str)-1; i++)
	//{
	//	if (str[i] == ' ' && str[i+1]=='b')
	//	{
	//		k = k + 1;
	//	}
	//}

	//cout << k << endl;
//****************************************************************************************
// Первая буква – заглавная
//****************************************************************************************
	//string str1 = "bprivet bkak bdela b";
	//str1[0] = toupper(str1[0]);

	//bool flag = false;

	//for(int i = 0; i < str1.length(); i++)
	//{
	//	if (flag)
	//	{
	//		str1[i] = toupper(str1[i]);
	//		flag = false;
	//	}

	//	if (str1[i] == ' ')
	//	{
	//		flag = true;
	//	}
	//}
	//cout << str1;

//****************************************************************************************
// Первая буква – заглавная через два символа
//****************************************************************************************

	//string str = "bprivet bkak bdela b";

	//int n = 0;
	//n = strlen(str);

	//str[0] = tuupper(str[0]);		

	//for(int i = 1;i < n-1;i++)
	//{
	//	if((int)str[i] == 32 && (int)str[i+1] > 96)
	//	{
	//		str[i+1] = str[i+1] - 32; 
	//	}
	//}
	//if((int)str[n-1] > 96 && (int)str[n-2] == 32)
	//{
	//	str[n-1] = (int)str[n-1] - 32;
	//}

//****************************************************************************************
// Верхний регистр
//****************************************************************************************

	//char str[] = "bprivet bkak bdela b";
	//for(int i = 0; i < strlen(str); i++)
	//{
	//	str[i] = toupper(str[i]);
	//}
	//cout << str;

//****************************************************************************************
// Первая буква – заглавная через два символа
//****************************************************************************************

	//string str1 = "bprivet bkak bdela b";
	//str1[0] = toupper(str1[0]);

	//bool flag = false;

	//for(int i = 0; i < str1.length(); i++)
	//{
	//	if (flag)
	//	{
	//		str1[i] = toupper(str1[i]);
	//		flag = false;
	//	}

	//	if (str1[i] == ' ')
	//	{
	//		flag = true;
	//	}
	//}
	//cout << str1;

//****************************************************************************************
// Слова из четырёх букв
//****************************************************************************************
	//string str1 = "bpri bkak bdela b";
	//string s;
	//str1[0] = toupper(str1[0]);

	//bool flag = false;

	//for(int i = 0; i < str1.length(); i++)
	//{
	//	if (str1[i] == ' ')
	//	{
	//		cout << s << endl;
	//		s = "";
	//	}
	//	else
	//	{
	//		s = s + str1[i];
	//	}
	//}
	//
	//cout << s << endl;
//****************************************************************************************
// Количество слов и избыточные пробелы через флаг
//****************************************************************************************
	
	//string str1 = "    f   k fg  gg";
	//int k = 0;
	//bool firstLetter = 1;
	//for(int i = 0; i < str1.length(); i++)
	//{
	//	// если пришла буква и она первая в слове
	//	if (firstLetter && str1[i] != ' ')
	//	{
	//		k++;
	//		firstLetter = 0;
	//	}
	//	else 
	//	{
	//		firstLetter = 1;
	//	}
	//}
	//cout << k;

//****************************************************************************************
// Количество слов и избыточные пробелы через два символа
//****************************************************************************************

	//string str1 = "     rtt k fg  jj";
	//int k = 0;
	//if (str1[0] != ' ')
	//{
	//	k = 1;
	//}
	//for(int i = 0; i < str1.length()-1; i++)
	//{
	//	if (str1[i] == ' ' && str1[i+1] != ' ')
	//	{
	//		k++;
	//	}
	//}
	//cout << k;

//****************************************************************************************
// Самое длинное слово через счётчик
//****************************************************************************************
	//string str1 = " fgss";

	//int k = 0;
	//int max = 0;

	//for(int i = 0; i < str1.length(); i++){
	//	if (str1[i] != ' ')	{
	//		k++;
	//	}
	//	else{
	//		if (k > max)
	//			max = k;
	//		k = 0;
	//	}
	//}

	//if (k > max)
	//	max = k;

	//cout << max;

//****************************************************************************************
// Самое длинное слово через два символа
//****************************************************************************************
	//string str1 = "  h   ff ";

	//int k = 0;
	//int max = 0;

	//if (str1[0] != ' ')
	//{
	//	k = 1;
	//}

	//for(int i = 0; i < str1.length()-1; i++)
	//{

	//	if (str1[i] == ' ' && str1[i+1] != ' ')
	//	{
	//		k++;
	//	}
	//	else if (str1[i] != ' ' && str1[i+1] != ' ')
	//	{
	//		k++;
	//	}
	//	else if (str1[i] != ' ' && str1[i+1] == ' ')
	//	{
	//		if (k > max)
	//			max = k;
	//		k = 0;
	//	}
	//}
	//// проверка на случай два последних символа
	//if (k > max)
	//	max = k;

	//cout << max;
//****************************************************************************************
// Пять подряд символа ‘a’
//****************************************************************************************

	//string str = "haa aaaf";

	//int k = 1;
	//bool f = 0;

	//for(int i = 1; i < str.length(); i++)
	//{
	//	if (str[i] == 'a')
	//	{
	//		k++;
	//		if (k >= 5)
	//		{
	//			f = 1;
	//			break;
	//		}
	//	}
	//	else
	//	{
	//		k = 1;
	//	}

	//}
	//cout << f;

//****************************************************************************************
// Символы подряд один цикл
//****************************************************************************************

	//string str = "k kkdd";
	//int  k = 1;
	//int  n = 3;
	//bool f = 0;
	//char ch = str[0];
	//for(int i = 1; i < str.length(); i++){
	//	if (ch == str[i]){
	//		k++;

	//		if (k >= n){
	//			f = 1;
	//			break;
	//		}
	//	}
	//	else{
	//		ch = str[i];
	//		k = 1;
	//	}
	//}
	//cout << f;

//****************************************************************************************
// Символы подряд второй способ два цикла
//****************************************************************************************

	//string str = "hkkkkf";

	//char ch = str[0];
	//int k = 1;
	//bool f = 0;

	//for(int i = 0; i < str.length()-5; i++)
	//{
	//	for(int j = i; j < 5; j++)
	//	{
	//		if (str[i] == str[j])
	//		{
	//			k++;
	//		}
	//		else
	//		{
	//			k = 1;
	//			break;

	//		}
	//	}
	//	if (k == 5)
	//	{
	//		f = 1;
	//		break;
	//	}
	//}
	//cout << f;

//****************************************************************************************
// Избыточные пробелы
// Дана строка, Вам требуется преобразовать все идущие подряд пробелы в один.
//****************************************************************************************

	//string str1 = "      nz d urp lren s bwz  boom  t a   j    ho    vi   ";
	//string str2 = "";

	//int k = 0;

	//int i = 0;

	//while (str1[i] == ' ' && i < str1.length())
	//{
	//	i++;
	//}

	//for(i = i; i < str1.length(); i++)
	//{
	//	if (str1[i] == ' ')
	//	{
	//		str2 = str2 + str1[i];
	//		while (str1[i] == ' ' && i < str1.length())
	//		{
	//			i++;
	//		}
	//		i--;
	//	} else {
	//		str2 = str2 + str1[i];
	//	}
	//}

	//cout << str2;


//****************************************************************************************
// Избыточные пробелы
// через флаг
//****************************************************************************************

	//string str1 = "     ";
	//string str2 = "";

	//int f = 0;

	//int i = 0;
	//int a = 0;
	//int b = 0;

	//while (str1[i] == ' ' && i < str1.length())
	//{
	//	i++;
	//}
	//a = i;

	//i = str1.length() - 1;
	//while (str1[i] == ' ' && i >= 0)
	//{
	//	i--;
	//}
	//b = i;

	//for(i = a; i <=b; i++)
	//{
	//	if (str1[i] == ' ' && f == 0)
	//	{
	//		str2 = str2 + ' ';
	//		f = 1;
	//	}
	//	else if (str1[i] == ' ' && f == 1)
	//	{
	//		continue;
	//	}
	//	else 
	//	{
	//		f = 0;
	//		str2 = str2 + str1[i];
	//	}
	//}

	//cout << str2;

//****************************************************************************************
// Избыточные пробелы 2
// через пары не доделал, все случаи не отрабатывает
//****************************************************************************************

	//string str1 = "  nz gd";
	//string str2 = "";

	//int i = 0;
	//int a = 0;
	//int b = 0;

	//while (str1[i] == ' ' && i < str1.length())
	//{
	//	i++;
	//}
	//a = i;

	//i = str1.length() - 1;
	//while (str1[i] == ' ' && i >= 0)
	//{
	//	i--;
	//}
	//b = i;

	//for(int i = a; i <= b; i+=2)
	//{
	//	if (str1[i] == ' ' && str1[i+1] != ' ')
	//	{
	//		str2 = str2 + ' ';
	//		str2 = str2 + str1[i+1];
	//	}
	//	else if (str1[i] != ' ' && str1[i+1] != ' ')
	//	{
	//		str2 = str2 + str1[i];
	//		str2 = str2 + str1[i+1];
	//	}
	//	else if (str1[i] != ' ' && i+1 > b)
	//	{
	//		str2 = str2 + str1[i];
	//	}
	//	else if (str1[i] != ' ' && str1[i+1] == ' ')
	//	{
	//		str2 = str2 + str1[i];
	//		str2 = str2 + ' ';
	//	}
	//}

	//cout << str2;


//****************************************************************************************
// Избыточные пробелы 3
// через find и erase
// не пошло
//****************************************************************************************

	//string str1 = " nz    gd    ";
	//string str2 = "";

	//int i = 0;
	//int a = 0;
	//int b = 0;

	//while (true)
	//{
	//	int pos = (int)str1.find("  ");

	//	if (pos == -1)
	//	{
	//		break;
	//	}

	//	str1.erase(pos,2);
	//}

	//cout << str1;

//****************************************************************************************
// Удалить набор символов
//****************************************************************************************

	//string str1 = "Privet! Kak... dela?";
	//string str2 = "!?.";

	//int i = 0;
	//int a = 0;
	//int b = 0;

	//for(i = i; i < str2.length(); i++)
	//{
	//	int pos = 0;
	//	do
	//	{
	//		pos = (int)str1.find(str2[i]);

	//		if (pos != -1)
	//		{
	//			str1.erase(pos,1);
	//		}

	//	} while (pos != -1);
	//}

	//cout << str1;

//****************************************************************************************
// Количество  вхождений
//****************************************************************************************

	//string str = "ab ab abc";
	//cout << str.find("ab", 2); // find верёт 3
	//cout << str.find("ab", 4); // find верёт 6

	//string str1 = "ba aba bna";
	//string str2 = "ba";
	//int k = 0;
	//int pos = 0;
	//while (true)
	//{
	//	pos = (int)str1.find(str2, pos);
	//	if (pos == -1)
	//	{
	//		break;
	//	}
	//	else
	//	{
	//		pos++;
	//		k++;
	//	}
	//}
	//cout << k << endl;

//****************************************************************************************
// Случайный пароль
//****************************************************************************************

	//srand(time(0));

	//ofstream file;
	//file.open("test.txt");
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 
	//else
	//{
	//	vector <string> vec;

	//	vec.push_back("facebook");
	//	vec.push_back("vk1");
	//	vec.push_back("vk2");
	//	vec.push_back("job1738@mail.ru");
	//	vec.push_back("01738@mail.ru");
	//	vec.push_back("prog-cpp@mail.ru");
	//	vec.push_back("job1738@yandex.ru");
	//	vec.push_back("job1738@gmail.com");
	//	vec.push_back("job1738@rambler.ru");
	//	vec.push_back("ok.ru");
	//	vec.push_back("avito.ru");
	//	vec.push_back("skype");
	//	vec.push_back("discord");

	//	for(int i = 0; i < vec.size(); i++)
	//	{
	//		file << vec[i] << endl;		
	//		file << genPass() << endl;		
	//	}

	//	file.close();
	//}

//****************************************************************************************
// передача параметра по ссылке, по значению, по уазателю
//****************************************************************************************
	//int x = 2;
	//x_x1(x);
	//cout << x; 
	//x_x2(x);
	//cout << x; 
	//x_x3(&x);
	//cout << x; 

	//int x;
	//float x = (float)3/7;
	//printf("Переменная x = %.3f",x);
	//printf("%5d",20);
	//printf("%05d",20);

	//scanf("%d",&x);
	//cout << x;

	//int x = 3, y = 6;
	//int a,b,c;
	//float f,g;

 //   printf("\nКалькулятор:");
 //   //scanf("%d+%d", &x, &y);
	////scanf("%d%d%d", &a, &b, &c);
	//scanf("%f", &f);

	////cout << a << b << c;
	//cout << f;

	//printf("\n%d+%d=%d", x, y, x+y);

//****************************************************************************************
//Второй максимум
//****************************************************************************************

	//int x = 1;
	//int c = 0;
	//int m1 = -999;
	//int m2 = -999;

	//while (x != 0) 
	//{

	//	cin >> x;

	//	if (x > m1)
	//	{
	//		m2 = m1;
	//		m1 = x;

	//	}
	//	
	//};

	//cout << m1 << endl;
	//cout << m2 << endl;

//****************************************************************************************
// перегрузка оператора + при сложение векторов
//****************************************************************************************

	//CVector2D * v1 = new CVector2D(2,4);
	//CVector2D * v2 = new CVector2D(3,7);
	////CVector2D v1(2,4);
	////CVector2D v2(3,7);
	//*v1 = *v1 + *v2;
	////v1 = v1 + v2;
	//v1->show();
	//Integer x(5), y(12);
	//x = x + y;
	//x.show();

	//CVector2D v1, v2;
	////++v1;

	//cout << (v1 == v2);

	//++v2;

	//v1 = v1 + v2;

	//cout << v1.x << v1.y;


//****************************************************************************************
// вложенные циклы шахматка
//****************************************************************************************

	//int f = 1;

	//int N = 4;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (f == 1)
	//			cout << 1;
	//		else
	//			cout << 0;
	//		f = -f;
	//	}
	//	if (N%2 == 0)
	//		f = -f;
	//	cout << endl;
	//}

	//int f = 1;

	//int N = 4;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (f == 1)
	//			cout << 1;
	//		else
	//			cout << 0;
	//		f = -f;
	//	}
	//	if (N%2 == 0)
	//		f = -f;
	//	cout << endl;
	//}
//****************************************************************************************
// вложенные циклы 2
//****************************************************************************************
	//int N = 5;
	//float k = 1.00;

	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 1; j <= N; j++)
	//	{
	//		cout << setw(7) << fixed << setprecision(2) << k << setw(5) << "rs";
	//		k = k + 0.01;
	//	}
	//	cout << endl;
	//}
//****************************************************************************************
// вложенные циклы 3
//****************************************************************************************
	//int N = 9;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < i+1; j++)
	//	{
	//		cout << j+1;
	//	}
	//	cout << endl;
	//}


	//int N = 5;
	//int x = 1;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (j >= N-i-1)
	//		{
	//			cout << x;
	//			x = !x;
	//		}
	//		else
	//			cout << " ";
	//	}
	//	cout << endl;
	//}

//****************************************************************************************
// треугольник
// *
// **
// ***
// ****
// *****
//****************************************************************************************
	//int N = 5;
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < i+1; j++)
	//	{
	//			cout << "*";
	//	}
	//	cout << endl;
	//}
//****************************************************************************************
// треугольник 2
// *****
// ****
// ***
// **
// *
//****************************************************************************************
	//int N = 5;
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N - i; j++)
	//	{
	//			cout << "*";
	//	}
	//	cout << endl;
	//}

//****************************************************************************************
// треугольник 3
//     *
//    **
//   ***
//  ****
// *****
//****************************************************************************************
	//int N = 5;
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N - i - 1; j++)
	//	{
	//			cout << " ";
	//	}
	//	for (int j = 0; j < i + 1; j++)
	//	{
	//			cout << "*";
	//	}
	//	cout << endl;
	//}

//****************************************************************************************
// Квадрат-контур
//****************************************************************************************
	//int N = 5;

	//for (int i = 0; i < N; i++)
	//{
	//	cout << "*";
	//}
	//cout << endl;

	//for (int i = 1; i < N-1; i++)
	//{
	//	cout << "*";

	//	for (int j = 0; j < N-2; j++)
	//	{
	//		cout << " ";
	//	}
	//	
	//	cout << "*" << endl;
	//}

	//for (int i = 0; i < N; i++)
	//{
	//	cout << "*";
	//}

//****************************************************************************************
// Двойная рамка
//****************************************************************************************
	//int N = 6;

	//for (int i = 0; i < 2; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << "*";
	//	}
	//	cout << endl;
	//}

	//for (int i = 1; i < N-3; i++)
	//{
	//	cout << "**";

	//	for (int j = 0; j < N-4; j++)
	//	{
	//		cout << " ";
	//	}
	//	
	//	cout << "**" << endl;
	//}

	//for (int i = 0; i < 2; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << "*";
	//	}
	//	cout << endl;
	//}

//****************************************************************************************
// Рамка
//****************************************************************************************
	//int N = 3;
	//int M = 5;

	//for (int i = 0; i < N; i++)
	//{
	//	gotoxy(0,i);
	//	cout << "*";
	//	gotoxy(M-1,i);
	//	cout << "*";
	//}	
	//
	//for (int i = 0; i < M; i++)
	//{
	//	gotoxy(i,N-1);
	//	cout << "*";
	//	gotoxy(i,0);
	//	cout << "*";
	//}
//****************************************************************************************
// Диагональ
//****************************************************************************************
	//int N = 3;

	//cout << "*" << endl;

	//for (int i = 1; i < N; i++)
	//{
	//	for (int j = 0; j < i; j++)
	//	{
	//		cout << " ";
	//	}
	//	
	//	cout << "*" << endl;
	//}

	//for (int i = 0; i < N; i++)
	//{
	//	cout << "*";
	//}
	//cout << endl;


//****************************************************************************************
// Треугольник-контур
//****************************************************************************************
//*
//**
//* *
//*  *
//*****
//****************************************************************************************
	//int N = 5;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (j == 0 || j == i || i == N-1)
	//			cout << "*";
	//		else
	//			cout << " ";
	//	}
	//	cout << endl;
	//}

//****************************************************************************************
// Треугольник-контур
//****************************************************************************************
	//int N = 5;

	//cout << "*" << endl;

	//for (int i = 1; i < N-1; i++)
	//{
	//	cout << "*";

	//	for (int j = 0; j < i-1; j++)
	//	{
	//		cout << " ";
	//	}
	//	
	//	cout << "*" << endl;
	//}

	//for (int i = 0; i < N; i++)
	//{
	//	cout << "*";
	//}
	//cout << endl;

//****************************************************************************************
// Треугольник-контур 2
//****************************************************************************************
	//int N = 4;

	//for (int i = 0; i < N; i++)
	//{
	//	cout << "*";
	//}
	//cout << endl;

	//for (int i = 1; i < N; i++)
	//{
	//	for (int j = 0; j < i; j++)
	//	{
	//		cout << " ";
	//	}

	//	cout << "*";

	//	for (int j = 0; j < N-i-2; j++)
	//	{
	//		cout << " ";
	//	}
	//	
	//	if (i < N-1)
	//		cout << "*";

	//	cout << endl;
	//}
//****************************************************************************************
// Пирамида-контур
//****************************************************************************************
	//int N = 6;

	//for (int i = 0; i < N-1; i++)
	//{
	//	for (int j = 0; j < N-1-i; j++)
	//	{
	//		cout << " ";
	//	}

	//	cout << "*";

	//	for (int j = 0; j < 2*i-1; j++)
	//	{
	//		cout << " ";
	//	}
	//	
	//	if (i > 0)
	//		cout << "*";

	//	cout << endl;
	//}

	//for (int i = 0; i < 2*N-1; i++)
	//{
	//	cout << "*";
	//}
//****************************************************************************************
// Пирамида-контур второй способ
//****************************************************************************************
	//int N = 5;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N-1-i; j++)
	//	{
	//		cout << " ";
	//	}
	//	for (int j = 0; j < 2*i+1; j++)
	//	{
	//		if (j == 0 || j == 2*i || i == N-1)
	//			cout << "*";
	//		else
	//			cout << " ";
	//	}
	//	cout << endl;
	//}

//****************************************************************************************
// вложенные циклы пирамида треугольник
//****************************************************************************************
	//int N = 5;

	//for (int i = 0; i < N-1; i++)
	//{
	//	for (int j = 0; j < N-1-i; j++)
	//	{
	//		cout << " ";
	//	}
	//	
	//	cout << "*";

	//	if (i > 0)
	//	{
	//		for (int j = 0; j < 2*i-1; j++)
	//		{
	//			cout << " ";
	//		}
	//		cout << "*";
	//	}
	//	cout << endl;
	//}
	//for (int i = 0; i < 2*N-1; i++)
	//{
	//	cout << "*";
	//}

//****************************************************************************************
// пирамида 1
//****************************************************************************************
	
	//int N = 5;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N-i-1; j++)
	//	{
	//		cout << " ";
	//	}
	//	
	//	for (int j = 0; j < 2*i+1; j++)
	//	{
	//		cout << "*";
	//	}

	//	cout << endl;
	//}

//****************************************************************************************
// пирамида 2
//****************************************************************************************

	//int N = 5;

	//for (int i = 0; i < N/2+1; i++)
	//{
	//	for (int j = 0; j < i; j++)
	//	{
	//		cout << " ";
	//	}
	//	
	//	for (int j = 0; j < N - 2*i; j++)
	//	{
	//		cout << "*";
	//	}

	//	cout << endl;
	//}

//****************************************************************************************
// песочные часы
//****************************************************************************************

	//int N = 5;

	//for (int i = N; i > 0; i--)
	//{
	//	for (int j = 0; j < N-i; j++)
	//	{
	//		cout << " ";
	//	}
	//	
	//	for (int j = 0; j < 2*i-1; j++)
	//	{
	//		cout << "*";
	//	}

	//	cout << endl;
	//}

	//for (int i = 1; i < N; i++)
	//{
	//	for (int j = 0; j < N-i-1; j++)
	//	{
	//		cout << " ";
	//	}
	//	
	//	for (int j = 0; j < 2*i+1; j++)
	//	{
	//		cout << "*";
	//	}

	//	cout << endl;
	//}


//****************************************************************************************
// песочные часы массив, можно упростить конечно
//****************************************************************************************

	//const int N = 5;
	//int mas[N][N] = {0};

	//int y = 0;

	//for (int i = N; i > N/2; i--)
	//{
	//	int x = 0;

	//	for (int j = 0; j < N-i; j++)
	//	{
	//		x++;
	//	}
	//	
	//	for (int j = 0; j < N-2*y; j++)
	//	{
	//		mas[y][x] = 1;
	//		x++;
	//	}

	//	y++;

	//}

	//for (int i = 0; i < N/2; i++)
	//{
	//	int x = 0;

	//	for (int j = 0; j < N/2-i-1; j++)
	//	{
	//		x++;
	//	}

	//	for (int j = 0; j < (i+1)*2+1; j++)
	//	{
	//		mas[y][x] = 1;
	//		x++;
	//	}
	//	y++;

	//}

	//cout << endl;

	//for(int i=0;i<N;i++)
	//{
	//	for(int j=0;j<N;j++)
	//		cout << mas[i][j];
	//	cout << endl;
	//}


//****************************************************************************************
// 506.	Последовательное заполнение
//****************************************************************************************

	//const int N = 5;
	//int mas[N][N] = {0};
	//int x = 1;
	//for (int i = 0; i < N; i++)
	//	for (int j = 0; j < N; j++)	
	//		mas[i][j] = x++;

	//for(int i=0;i<N;i++)
	//{
	//	for(int j=0;j<N;j++)
	//	{
	//		cout << " ";
	//		if (mas[i][j] < 10)
	//			cout << "  ";
	//		else if (mas[i][j] < 100)
	//			cout << " ";
	//		cout  << mas[i][j];
	//	}
	//	cout << endl;
	//}



//****************************************************************************************
// двойная рамка
//****************************************************************************************
	//int N = 5;

	//for (int i = 0; i < N; i++)
	//	cout << "*";
	//cout << endl;
	//for (int i = 0; i < N; i++)
	//	cout << "*";
	//cout << endl;

	//for (int i = 0; i < N-2-2; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (j == 0 || j == 1 || j == N-2 || j == N-1)
	//			cout << "*";
	//		else
	//			cout << " ";
	//	}
	//	cout << endl;
	//}
	//for (int i = 0; i < N; i++)
	//	cout << "*";
	//cout << endl;
	//for (int i = 0; i < N; i++)
	//	cout << "*";
	//cout << endl;


	//for (int i = 0; i < N; i++)
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N-1-i; j++)
	//	{
	//		cout << " ";
	//	}
	//	for (int j = 0; j < 2*i+1; j++)
	//	{
	//		if (j == 0 || j == 2*i || i == N-1)
	//			cout << "*";
	//		else
	//			cout << " ";
	//	}
	//	cout << endl;
	//}
//****************************************************************************************
// НОД
//****************************************************************************************
	//int x = 12;
	//int y = 8;
	//int d = 1;

	//if (x>y)
	//	d=y;
	//else
	//	d=x;

	//while (d >= 1) 
	//{
	//	if (x%d == 0 && y%d == 0)
	//	{
	//		cout << d;
	//		break;
	//	}else
	//		d--;
	//	
	//};
//****************************************************************************************
// http запрос через curl
//****************************************************************************************

	//CURL *curl_handle;
 //   CURLcode res;
 //   
 //   memset(wr_buf,BUF_SIZE+1,0); // заполняем буфер нулями.
 //
 //   curl_handle = curl_easy_init();
 //   if (curl_handle)
 //   {
	//	curl_easy_setopt(curl_handle, CURLOPT_URL, "http://www.cyberforum.ru");

	//	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, wr_buf);
	//	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

	//	CURLcode res = curl_easy_perform(curl_handle);
	//	if(res == CURLE_OK)
	//	{
	//		printf("%s\n Done!",wr_buf); // выводим буфер в консоль.
	//	}
	//	else 
	//		printf( "curl_easy_perform() failed: %s\n", curl_easy_strerror(res) );
	//    
	//	curl_easy_cleanup(curl_handle);
 //   }

//****************************************************************************************
// для понимания работы статических функций
//****************************************************************************************
	//goto_center();

//****************************************************************************************
// цикл через goto
//****************************************************************************************
	//int i  = 0;
	//
	//mm:	if (i <= 5)
	//{
	//	cout << i;
	//	i++;
	//	goto mm;
	//}
//****************************************************************************************
// вычисление числа пи
//****************************************************************************************
	//int N = 70;
	//double x = 1;
	//double n = 1;

	//for (int i = 1; i < N; i++)
	//{
	//	//x = pow(((sqrt(2.00)-1)/sqrt(2.00)),1)*2;
	//	//x = pow(((sqrt(2.00)-1)/sqrt(2.00)),2)/pow(sqrt(2.00),2)*4;
	//	//cout << (sqrt(2.00)-1)/sqrt(2.00) << endl;
	//	//cout << pow(((sqrt(2.00)-1)/sqrt(2.00)),(double)i) << endl;
	//	x = x + pow(((sqrt(2.00)-1.00)/sqrt(2.00)),n)/pow(sqrt(2.00),n) * pow(2.00,n);
	//	cout << pow(((sqrt(2.00)-1.00)/sqrt(2.00)),n)/pow(sqrt(2.00),n) * pow(2.00,n) << endl;
	//	n = n + 1;
	//}

	//cout << x;


//****************************************************************************************
// максимум из двух чисел без использования if
//****************************************************************************************

	//int a = 19;
	//int b = 5;
	//cout << (a + b + abs(a - b)) / 2;

//****************************************************************************************
// сравнение строк, ввод пароля, конкатенация
//****************************************************************************************
//string str;
//cin >> str;
//if (str == "12345")
//{
//	cout << "1";
//}

	//cout << s1 + s1;
	//cout << s1.length();

	//char s1[11] = "12345";
	//char s2[7] = "";

	//cin >> s2;

	//if (strcmp(s1,s2) == 0) // Сравнение строк
	//	cout << "строки равны";
	//else
	//	cout << "строки не равны";


//****************************************************************************************
// исключения
//****************************************************************************************
 //   signal(SIGFPE, SIGFPEHandler);
	//int * mas = new int [1000000];
	//mas[999999] = 1111111;
	//cout << mas[999999];
	//delete [] mas;

	//int a=1,b = 0;
	//try
	//{
	//	if (b == 0)
	//		throw "ZERO";
	//	a = a/b;
	//}
	////catch(exception & exp)
	//catch(...)
	//{
	//	cout << "деление на ноль";
	//}

    //int a = 1, b = 0;
    //printf("%d\n", a/b);

//****************************************************************************************
// передача статического двумерного массива в функцию
//****************************************************************************************

	//int human[10][10],i,j;

	//init_mas_10_10(human);

//****************************************************************************************
// вывод кавычки на экран
//****************************************************************************************
	//cout << "\"";
//****************************************************************************************
// двумерный динамический массив c++, передача по ссылке двумерного динамического массива
//****************************************************************************************
	//int option, m, n;
	//n = 1;
	//m = 5;

	//int **mas = NULL;

	//assign(mas, n, m, 1);

	//push_back(mas, n, m, 2);
	//push_back(mas, n, m, 3);
	//push_back(mas, n, m, 4);

	//print(mas,n,m);

	//cout << endl;

	//erase(mas,n,m, 3);

	//print(mas,n,m);

	//clear(mas,n);


//****************************************************************************************
// длина строки си. Пример использования strlen
//****************************************************************************************

	//char str[] = "123456";
	//int L = strlen( str );

	//for ( int i = 0; i < L / 2; i++ )
	//{
	//	char tmp = str[i];
	//	str[i] = str[L - i - 1];
	//	str[L - i - 1] = tmp;
	//}

	//cout << str;

//****************************************************************************************
// Пример использования getline для си строк и string
//****************************************************************************************

	//Правильно делать константный указатель на изменяемую строку, указав размер сразу
	//char S[255] = "Hello"; // Указатель S менять нельзя, строку "Hello" можно
	//cin.getline( S, 255 ); // Не больше чем выделено на массив, на начало которого указывает S
	//cout << S;

	//string user_pass;
	//cout << "Введите строку с пробелом: ";
	//getline(cin, user_pass);
	//cout << user_pass << endl;

// ***************************************************************************
// чтение из файла ifstream, посимвольное чтение файла 1 способ
// ***************************************************************************

	//ifstream file("test.txt");//создать input-file object тоесть файл ИЗ которого читать  
	//
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	char ch;  
	//	while (file.get(ch))
	//	{
	//		cout << ch << " " << (int)ch << endl;
	//	}
	//	file.close();
	//}

// ***************************************************************************
// Первые N символов из файла
// ***************************************************************************

	//ifstream file("test.txt");//создать input-file object тоесть файл ИЗ которого читать  
	//
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	char ch; 
	//	int n;
	//	cin >> n;
	//	for (int i = n; i < n || file.get(ch); i++)
	//	{
	//		cout << ch << " ";
	//	}

	//	file.close();
	//}
	
// ***************************************************************************
// Первые N символов из файла
// ***************************************************************************

	//ifstream file("test.txt");//создать input-file object тоесть файл ИЗ которого читать  
	//
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	char ch; 
	//	int n;
	//	cin >> n;
	//	for (int i = n; i < n || file.get(ch); i++)
	//	{
	//		cout << ch << " ";
	//	}

	//	file.close();
	//}

// ***************************************************************************
// Количество слов в файле
// ***************************************************************************

	//ifstream file("test.txt");
	//
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	char ch; 
	//	int word = 0;

	//	bool firstLetter = true;

	//	while (file.get(ch))
	//	{
	//		if (isalpha(ch) && firstLetter)
	//		{
	//			word++;
	//			firstLetter = false;
	//		}

	//		if (ch == ' ' || (int)ch == 10)
	//		{
	//			firstLetter = true;
	//		} 
	//	}

	//	cout << word << " ";

	//	file.close();
	//}

// ***************************************************************************
// Количество различных букв в файле
// ***************************************************************************

	//ifstream file("test.txt");
	//
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	vector <int> vec;

	//	char ch; 

	//	while (file.get(ch))
	//	{
	//		if ((int)ch == 32 || (int)ch == 10)
	//			continue;

	//		if (!find(vec, (int)ch))
	//		{
	//			vec.push_back((int)ch);
	//		}
	//	}

	//	cout << vec.size();

	//	file.close();
	//}


	//for(int i = 0; i < vec.size(); i++)
	//{
	//}

// ***************************************************************************
// 643.	Пустой файл
// ***************************************************************************


	//ifstream file("test.txt");
	//
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	if (file.peek() == EOF) 
	//	{
	//		cout << "Empty\n"; // если первый символ конец файла
	//		file.close();

	//		ofstream ofile;
	//		ofile.open("test.txt");
	//		if (!ofile.is_open())
	//		{
	//			cout << "Unable to open file.\n";
	//			return 0;
	//		} 
	//		else
	//		{
	//			ofile << 5;
	//			ofile.close();
	//		}

	//	}
	//	else  
	//	{
	//		cout << "Not empty\n"; // если первый символ конец файла

	//		char ch;

	//		while (file.get(ch))
	//		{
	//			cout << ch << " " << (int)ch << endl;
	//		}


	//		file.close();

	//		ofstream ofile;
	//		ofile.open("test.txt");
	//		if (!ofile.is_open())
	//		{
	//			cout << "Unable to open file.\n";
	//			return 0;
	//		} 
	//		else
	//		{
	//			ofile.close();
	//		}
	//	}

	//}



// ***************************************************************************
// Дан текстовый файл. Найти количество абзацев в тексте, если абзацы отделяются 
// друг от друга одной или несколькими пустыми строками.
// ***************************************************************************

	//ifstream file("r:\\test1.txt");//создать input-file object тоесть файл ИЗ которого читать  
	//
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	char ch;  
	//	while (file.get(ch))
	//	{
	//		cout << /*ch <<*/ " " << (int)ch /*<< endl*/;
	//	}
	//	file.close();
	//}


// ***************************************************************************
// чтение из файла ifstream, посимвольное чтение файла 2 способ
// ***************************************************************************

	//ifstream file ("d:\\test\\log.txt");
	//char ch;
	//if (file.is_open())
	//{
	//	while ( file.good() )
	//	{
	//		file >> ch;
	//		cout << ch << " " << (int)ch << " ";
	//	}
	//	file.close();
	//}
	//else cout << "Unable to open file";

// ***************************************************************************
// чтение из файла ifstream, посимвольное чтение файла
// ***************************************************************************

	//ifstream file("r:\\test1.txt");//создать input-file object тоесть файл ИЗ которого читать  
	//
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	char ch;  
	//	while (file.get(ch))
	//	{
	//		cout << ch << " " << (int)ch << endl;
	//	}
	//	file.close();
	//}


//****************************************************************************************
// чтение строк из файла и запись их в массив строк, построковое чтение, минимальное
//****************************************************************************************

	//string line;
	//ifstream file ("test.txt");

	//int i = 0;

	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	while ( file.good() )
	//	{
	//		getline (file,line);
	//		cout << line << endl;
	//	}
	//	file.close();
	//}

//****************************************************************************************
// 626.	Максимальная длина строки в файле
//****************************************************************************************

	//string line;
	//ifstream file ("test.txt");

	//int max = 0;
	//string str;

	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	while ( file.good() )
	//	{
	//		getline (file,line);

	//		if (line.length() > max)
	//		{
	//			max = line.length();
	//			str = line;
	//		}
	//		cout << line << endl;
	//	}
	//	file.close();
	//	cout << str << endl;
	//}

//****************************************************************************************
// 628.	Олимпиада по информатике
//****************************************************************************************

	//string line;
	//ifstream fle ("olimp.txt");

	//int max = 0;
	//string str;

	//if (!fle.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{

	//	int sum09 = 0;
	//	int sum10 = 0;
	//	int sum11 = 0;

	//	int numRecords09 = 0;
	//	int numRecords10 = 0;
	//	int numRecords11 = 0;

	//	while (getline (fle,line))
	//	{
	//	
	//		cout << line << endl;

	//		string clas;
	//		string ball;
	//		int a = 0;
	//		int b = 0;

	//		a = line.find(' ');
	//		b = line.find(' ',a+1);

	//		clas = line.substr(a+1,b-a-1);
	//		ball = line.substr(b+1,line.length()-b);

	//		if (clas == "9")
	//		{
	//			numRecords09++;
	//			sum09 += atoi(ball.c_str());
	//		}
	//		else if (clas == "10")
	//		{
	//			numRecords10++;
	//			sum10 += atoi(ball.c_str());
	//		}
	//		else if (clas == "11")
	//		{
	//			numRecords11++;
	//			sum11 += atoi(ball.c_str());
	//		}

	//	}
	//	fle.close();
	//	cout << "09 " << (float)sum09 / numRecords09 << endl;
	//	cout << "10 " << (float)sum10 / numRecords10 << endl;
	//	cout << "11 " << (float)sum11 / numRecords11 << endl;
	//}

//****************************************************************************************
// 630.	Выравнивание текста из файла
//****************************************************************************************

	//string line;
	//ifstream fle ("olimp.txt");

	//int max = 0;
	//string str;

	//if (!fle.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	int numSpace = 0;
	//	int y = 0;
	//	int mode = 2;

	//	vector <string> vec;

	//	while (getline (fle,line))
	//	{
	//		vec.push_back(line);
	//	}
	//	fle.close();

	//	int ch = 0;

	//	while (true)
	//	{
	//		ch = _getch();
	//		system("cls");
	//		for (int i = 0; i < vec.size(); i++)
	//		{
	//			if (ch == '1')
	//			{
	//				cout << vec[i] << endl;
	//			}
	//			else if (ch == '2')
	//			{
	//				numSpace = (120 - vec[i].size()) / 2;
	//				gotoxy(numSpace, y);
	//				cout << vec[i] << endl;
	//				y++;
	//			}
	//			else if (ch == '3')
	//			{
	//				numSpace = 120 - vec[i].size();
	//				gotoxy(numSpace, y);
	//				cout << vec[i] << endl;
	//				y++;
	//			}
	//		}
	//		y = 0;
	//	}

	//}


//****************************************************************************************
// загрузка задач учёт учеников учет учеников
//****************************************************************************************

	//string line;
	//ifstream file ("task.txt");


	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	int i = 0;
	//	while ( file.good() )
	//	{
	//		//i++;

	//		//if (i >= 4)
	//		//	break;

	//		getline (file,line);
	//		cout << line << endl;

	//				ofstream file;

	//				line = delSigns(line);

	//				line += ".png";
	//				line = "pics\\" + line;
	//				file.open(line.c_str());
	//				if (!file.is_open())
	//				{
	//					cout << "Unable to open file.\n";
	//					system("pause");
	//					return 0;
	//				} 
	//				else
	//				{
	//					//file << "Privet! Kak dela?";
	//					file.close();
	//				}

	//	}
	//	file.close();
	//}

//****************************************************************************************
// чтение строк из файла и запись их в массив строк, построковое чтение
//****************************************************************************************

	//string line;
	//string lines[50];
	//ifstream myfile ("c:\\test.txt");

	//int i = 0;

	//if (myfile.is_open())
	//{
	//	while ( myfile.good() )
	//	{
	//		getline (myfile,line);
	//		//cout << line << endl;
	//		lines[i++] = line;
	//	}
	//	myfile.close();
	//}
	//else cout << "Unable to open file";

	//for(int j = 0; j < i; j++)
	//{
	//	cout << lines[j] << endl;
	//}

//****************************************************************************************
// построковое чтение, удаление последней строки
//****************************************************************************************

	//string line;
	//string lines[50];
	//ifstream myfile ("c:\\test.txt");

	//int i = 0;

	//if (myfile.is_open())
	//{
	//	while ( myfile.good() )
	//	{
	//		getline (myfile,line);
	//		//cout << line << endl;
	//		lines[i++] = line;
	//	}
	//	myfile.close();
	//}
	//else cout << "Unable to open file";

	//for(int j = 0; j < i; j++)
	//{
	//	cout << lines[j] << endl;
	//}

	//ofstream myfile2 ("c:\\test.txt");

	//if (myfile2.is_open())
	//{
	//	for(int j = 0; j < i-1; j++)
	//	{
	//		myfile2 << lines[j] << endl;
	//	}
	//	myfile2.close();
	//}

//****************************************************************************************
// поиск подстроки в файле
//****************************************************************************************

	//string line;
	//string lines[50];
	//ifstream myfile ("c:\\test.txt");

	//int i = 0;

	//if (myfile.is_open())
	//{
	//	while ( myfile.good() )
	//	{
	//		getline (myfile,line);
	//		//cout << line << endl;
	//		lines[i++] = line;
	//	}
	//	myfile.close();
	//}
	//else cout << "Unable to open file";

	//for(int j = 0; j < i; j++)
	//{
	//	//cout << lines[j] << endl;
	//	if (lines[j].find("ма") == string::npos)
	//		cout << "Строка не найдена";
	//	else
	//	{
	//		cout << "Строка найдена";
	//		break;
	//	}
	//}

//****************************************************************************************
// чтение типизированного файла, чтение чисел из файла, чтение из типизированного файла
//****************************************************************************************
//1
//4.4
//Миша
//2
//4.1
//Паша
//4
//3.7
//Лена

//ifstream file ("c:\\resources\\test.txt");
//
//int kurs;
//float avg;
//string name;
//
//if (file.is_open())
//{
//	while ( file.good() )
//	{
//		file >> kurs;
//		file >> avg;
//		file >> name;
//
//		cout << kurs << endl;
//		cout << avg << endl;
//		cout << name << endl;
//	}
//	file.close();
//}
//else cout << "Unable to open file";

//****************************************************************************************
// Сумма чисел по строкам в файле
//****************************************************************************************

	//ifstream file ("matrix.txt");

	//float f, s = 0, d = 0;

	//if (file.is_open())
	//{
	//	int n = 0;
	//	int m = 0;
	//	file >> n; file >> m;
	//	for (int i = 0; i < n && file.good(); i++)
	//	{
	//		int s = 0;
	//		
	//		for (int j = 0; j < m && file.good(); j++)
	//		{
	//			file >> x;
	//			s += x;
	//		}
	//		
	//		cout << s << " ";

	//	}
	//	file.close();
	//}

//else cout << "Unable to open file";

//****************************************************************************************
// Среднее арифметическое чисел из файла
//****************************************************************************************
//ifstream file ("float.txt");
//float f, s = 0, d = 0;
//if (file.is_open())
//{
//	while ( file.good() )
//	{
//		file >> f;
//		cout << f << endl;
//
//		s += f;
//		d++;
//
//	}
//	file.close();
//	cout << s / d << endl;
//}
//else cout << "Unable to open file";

//****************************************************************************************
// N-ое число файла
//****************************************************************************************

//ifstream file ("float.txt");
//
//float f, s = 0, d = 0;
//int n = 5;
//
//
//if (file.is_open())
//{
//	int i;
//	for(i = 0; i < n && file.good();i++)
//	{
//		file >> f;
//	}
//	file.close();
//	if (i == n)
//	{
//		cout << f << endl;
//	}
//	else
//	{
//		cout << "нету" << endl;
//	}
//}
//else cout << "Unable to open file";


//****************************************************************************************
// чтение файла студентов студенты
//****************************************************************************************

//ifstream file ("students.txt");
//
//string name;
//string date;
//int vozrast;
//int rost;
//float stip;
//int o1;
//int o2;
//int o3;
//int o4;
//int o5;
//
//vector <Student> vec;
//
//if (file.is_open())
//{
//	while ( file.good() )
//	{
//		file >> name;
//		file >> date;
//		file >> vozrast;
//		file >> rost;
//		file >> stip;
//		file >> o1;
//		file >> o2;
//		file >> o3;
//		file >> o4;
//		file >> o5;
//
//		Student student;
//
//		student.name = name;
//		student.data_post = date;
//		student.vozrast = vozrast;
//		student.rost = rost;
//		student.stip = stip;
//		student.ocenki[0] = o1;
//		student.ocenki[1] = o1;
//		student.ocenki[2] = o1;
//		student.ocenki[3] = o1;
//		student.ocenki[4] = o1;
//
//		vec.push_back(student);
//
//		//student.name = name;
//
//		//cout << name << endl;
//		//cout << date << endl;
//		//cout << age << endl;
//		//cout << rost << endl;
//		//cout << stip << endl;
//		//cout << o1 << endl;
//		//cout << o2 << endl;
//		//cout << o3 << endl;
//		//cout << o4 << endl;
//		//cout << o5 << endl;
//	}
//	file.close();
//	
//	int x = 0, y = 0;
//	int ch = 0;
//
//
//	showStudentInfo(vec);
//
//	while(true)
//	{
//		gotoxy(x, y);
//
//		int tx = x;
//		int ty = y;
//
//		ch = _getch();
//		if (ch == 224)
//		{
//			ch = _getch();
//		}
//
//		switch (ch)
//		{
//			case 77:// вправо
//				x++;
//			break;
//			case 75:// влево
//				x--;
//				break;
//			case 80:// вниз
//				y++;
//				break;
//			case 72:// вверх
//				y--;
//				break;
//			case 27:// esc
//
//				break;
//			case 13:// enter
//
//					system("cls");
//					
//
//					//gotoxy(40,0);
//					//cout << "last = " << last_task << endl;	
//
//					gotoxy(0,0);
//					//printVec(tasks2);
//		
//
//			break;
//		}
//
//
//		gotoxy(x,y);
//	}
//
//
//}
//else cout << "Unable to open file";

//****************************************************************************************
// 629.	Напоминание событий
//****************************************************************************************

	//ifstream file ("date.txt");

	//SYSTEMTIME st;
	//GetSystemTime(&st);
	//string curr_date;
	//
	//if (st.wMonth < 10)
	//	curr_date = to_string(st.wDay) + ".0" + to_string(st.wMonth) + "." + to_string(st.wYear);
	//else
	//	curr_date = to_string(st.wDay) + "." + to_string(st.wMonth) + "." + to_string(st.wYear);

	//string date = "";
	//string text = "";

	//if (file.is_open())
	//{
	//	while ( file.good() )
	//	{
	//		getline (file,date);
	//		getline (file,text);

	//		if (date == curr_date)
	//			cout << text;
	//	}
	//	file.close();
	//}
	//else cout << "Unable to open file";

//****************************************************************************************
// напоминалка органайзер 2
//****************************************************************************************

	//ifstream file ("d:\\test\\log2.txt");

	//SYSTEMTIME st;
	//GetSystemTime(&st);

	//int day = 0;
	//int month = 0;
	//int year = 0;
	//string text = "";

	//if (file.is_open())
	//{
	//	while ( file.good() )
	//	{
	//		file >> day;
	//		file >> month;
	//		file >> year;

	//		file >> text;
	//		
	//		if (day == st.wDay && month == st.wMonth && year == st.wYear)
	//			cout << text << endl;
	//	}
	//	file.close();
	//}
	//else cout << "Unable to open file";

//****************************************************************************************
// Сумма столбцов
//****************************************************************************************

//ifstream file ("c:\\resources\\test.txt");
//
//int kurs;
//float avg;
//string name;
//
//if (file.is_open())
//{
//	while ( file.good() )
//	{
//		file >> kurs;
//		file >> avg;
//		file >> name;
//
//		cout << kurs << endl;
//		cout << avg << endl;
//		cout << name << endl;
//	}
//	file.close();
//}
//else cout << "Unable to open file";


//****************************************************************************************
// Запись в файл ofstream. Открытие файла на запись.
//****************************************************************************************

//ofstream file;
//file.open("c:\\test.txt");
//if (!file.is_open())
//{
//	cout << "Unable to open file.\n";
//	system("pause");
//	return 0;
//} 
//else
//{
//	file << "Privet! Kak dela?";
//	file.close();
//}


//****************************************************************************************
// Запись в файл ofstream. Открытие файла на запись.
//****************************************************************************************

//ofstream file;
//file.open("test.txt");
//if (!file.is_open())
//{
//	cout << "Unable to open file.\n";
//	system("pause");
//	return 0;
//} 
//else
//{
//	//file << "Privet! Kak dela?";
//	file.close();
//}


//****************************************************************************************
// 207.	Сериализация десериализация словаря
//****************************************************************************************

	//map<string, set<string>> mp;
	//set<string> st;
	//
	//st.insert("abc");
	//st.insert("bcd");
	//st.insert("cde");

	//mp["111"] = st;
	//
	//st.insert("ss");
	//st.insert("ff");
	//mp["222"] = st;

	//ofstream file;
	//file.open("test.txt");
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 
	//else
	//{
	//	for (map<string, set<string>>::iterator it1 = mp.begin(); it1 != mp.end(); it1++)
	//	{
	//		for (set<string>::iterator it2 = (*it1).second.begin(); it2 != (*it1).second.end(); it2++)
	//		{
	//			file << *it2 << " ";
	//		}
	//		file << endl;
	//	}
	//	file.close();
	//}

//****************************************************************************************
// Проверка существования файла или папки
// #include <sys/stat.h> // для stat проверка существования файла или папки
//****************************************************************************************

	//struct stat buff;
	///* заполнение структуры типа stat */
	//При успешном заполнении структуры stat возвращается 0. В случае неудачи возвращается —1, 
	//а errno устанавливается в ENOENT.
	//cout << stat("c:\\temp", &buff);

//****************************************************************************************
// Создание папки 
// #include <direct.h> // для mkdir
//****************************************************************************************

	//первый способ
	//string makeDirCommand = "mkdir c:\\test";
	//system(makeDirCommand.c_str());

	//второй способ
	//int result;
	//result = mkdir("c:\\temp");
 //   if (result==0)
 //       printf("Каталог \\temp создан\n");
 //   else
 //       printf("Не могу создать каталог \\temp\n");

//****************************************************************************************
// Запись в папку в которой находиться exe файл Получение пути
//****************************************************************************************

	//string s = getPathApp() + "\\save";
	//
	//string makeDirCommand = "mkdir " + s;

	//system(makeDirCommand.c_str());

	//s = s + "\\test.txt";

	//ofstream file;
	//file.open(s.c_str());
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 
	//else
	//{
	//	file << "Privet! Kak dela?";
	//	file.close();
	//}

//****************************************************************************************
// Запись в конец файла дозапись, добавление в файл
//****************************************************************************************

	//ofstream file;
	//file.open("r:\\test1.txt", ios::app);
	//if (!file.is_open())
	//{
	//	cout<<"Файл не открыт. Программа завершена.\n";
	//	system("pause");
	//	return 0;
	//} 
	//else
	//{
	//	file << "helllllowwww!";
	//	file.close();
	//}
//****************************************************************************************
// Создание нескольких файлов
//****************************************************************************************

	//ofstream file;

	//for (int i = 0; i < 3; i++)
	//{
	//	//string fn = "d:\\testtt" + to_string(i) +".txt";
	//	//string fn = "";

	//	string fn = "r:\\testtt.txt";

	//	//fn = fn + "d:\\testtt" + (char)(i+48) + ".txt";

	//	fn[7] = (char)(i+48);

	//	cout << fn << endl;
	//	
	//	file.open(fn.c_str());
	//	if (!file.is_open())
	//	{
	//		cout<<"Файл не открыт. Программа завершена.\n";
	//		system("pause");
	//		return 0;
	//	} 
	//	else
	//	{
	//		file << "helllllowwww!";
	//		file.close();
	//	}
	//}
//****************************************************************************************
// Создание нескольких файлов
//****************************************************************************************

	//ofstream file;

	//SYSTEMTIME st;
	//GetLocalTime(&st);
	//cout << "Год:" << st.wYear << endl;
	//cout << "Месяц:" << st.wMonth << endl;
	//cout << "День:" << st.wDay << endl;
	//cout << "Час:" << st.wHour << endl;
	//cout << "Минута:" << st.wMinute << endl;
	//cout << "Секунда:" << st.wSecond << endl;

	//for (int i = 0; i < 3; i++)
	//{
	//	string fn = "d:\\testtt" + to_string(st.wHour) + to_string(st.wMinute) + to_string(st.wSecond) +".txt";
	//	//string fn = "";

	//	//string fn = "r:\\testtt.txt";

	//	////fn = fn + "d:\\testtt" + (char)(i+48) + ".txt";

	//	//fn[7] = (char)(i+48);

	//	cout << fn << endl;
	//	
	//	file.open(fn.c_str());
	//	if (!file.is_open())
	//	{
	//		cout<<"Файл не открыт. Программа завершена.\n";
	//		system("pause");
	//		return 0;
	//	} 
	//	else
	//	{
	//		file << "helllllowwww!";
	//		file.close();
	//	}
	//	Sleep(1000);
	//	GetLocalTime(&st);
	//}

//****************************************************************************************
// запись в типизированный файл
//****************************************************************************************

//ofstream file ("c:\\test.txt");
//
//if (!file.is_open())
//{
//	cout<<"Unable to open fout.\n";
//	system("pause");
//	return 0;
//}
//else 
//{
//	file << "Иванов" << endl;
//	file << 17 << endl;
//	file << 17.5 << endl;
//	file.close();
//}

//****************************************************************************************
// добавление в типизированный файл
//****************************************************************************************
	//ofstream myfile ("r:\\test.txt", ios::app);
	//string line;
	//int num;
	//float flo;


	//if (myfile.is_open())
	//{
	//	myfile << 100 << endl;
	//	myfile << 56.54 << endl;
	//	myfile << "вапвап" << endl;
	//	myfile << 100 << endl;
	//	myfile << 16.54 << endl;
	//	myfile << "вапвап" << endl;

	//	myfile.close();
	//}
	//else cout << "Unable to open file";

//****************************************************************************************
// 632.	Файл в верхний регистр
//****************************************************************************************

	//string text;
	//fstream file("test.txt",ios::in|ios::out);
	//if (!file) 
	//{	
	//	cerr << "Error in opening file !!!" << endl;
	//}
	//else   
	//{
	//	char ch;
	//	while (file.get(ch)) 
	//	{
	//		text += ch;
	//	}

	//	file.clear();      
	//	file.seekp(ios::beg);

	//	for(int i = 0;i < text.length(); i++)
	//	{
	//		file << (char)toupper(text[i]);
	//	}

	//	file.close();
	//}

//****************************************************************************************
// 645.	Заменить 0 на 1 в файле
//****************************************************************************************

	//string text;
	//fstream file("test.txt",ios::in|ios::out);
	//if (!file) 
	//{	
	//	cerr << "Error in opening file !!!" << endl;
	//}
	//else   
	//{
	//	char ch;
	//	while (file.get(ch)) 
	//	{
	//		text += ch;
	//	}

	//	file.clear();      
	//	file.seekp(ios::beg);

	//	for(int i = 0;i < text.length(); i++)
	//	{
	//		if (text[i] == '0')
	//		{
	//			file << '1';
	//		}
	//		else
	//		{
	//			file << (char)text[i];
	//		}
	//	}

	//	file.close();
	//}


//****************************************************************************************
// 645.	Заменить 0 на 1 в файле
//****************************************************************************************

	//fstream file("test.txt",ios::in|ios::out);
	//if (!file.is_open()) 
	//{	
	//	cout << "Error in opening file !!!" << endl;
	//}
	//else   
	//{
	//	// чтение
	//	char ch;
	//	while (file.get(ch)) 
	//	{
	//		cout << ch;
	//	}
	//	// запись
	//	file.clear();      
	//	file.seekp(ios::beg);
	//	file << "abc";
	//	file.close();
	//}

//****************************************************************************************
// 635.	Удалить пустые строки
//****************************************************************************************

	//vector <string> vec;
	//int x;

 //   ifstream file ("test.txt");
 //   char ch;
 //   string str;
 //   if (!file.is_open())
 //   {
 //       cout << "Unable to open file.\n";
 //       system("pause");
 //       return 0;
 //   }
 //   else
 //   {
	//	string line;
	//	while (file.good())
	//	{
	//		getline (file,line);
	//		if (line != "")
	//		{
	//			vec.push_back(line);
	//		}
	//	}
 //       file.close();
 //   }
 //   
	//ofstream ofile ("test.txt");
 //   if (!ofile.is_open())
 //   {
 //       cout << "Unable to open file.\n";
 //       system("pause");
 //       return 0;
 //   }
 //   else
 //   {
	//	// vec.size()-1 чтобы не помещать в файл последний endl
	//	// последняя строка записывается после цикла
	//	for (int i = 0; i < vec.size()-1; i++)
	//	{
	//		ofile << vec[i] << endl;
	//	}
	//	ofile << vec.back();
	//	ofile.close();
	//}

//****************************************************************************************
// 636.	Копирование файла
//****************************************************************************************

	//ofstream copyFile;

	//copyFile.open("copy.txt");
	////copyFile.open("28.jpg");
	//if (!copyFile.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 

	////ifstream file("test.txt");
	//ifstream file("foto2.jpg");
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}

	//char ch;  
	//int size = 0;  
	//while (file.get(ch))
	//{
	//	size++;
	//	if (size > 4000000)
	//	{
	//		cout << "Слишком большой файл" << endl;
	//		break;
	//	}
	//	copyFile << ch;
	//}
	//file.close();
	//copyFile.close();


//****************************************************************************************
// 636.	Копирование файла 2
//****************************************************************************************

	//ofstream copyFile;

	//copyFile.open("copy.txt", std::ios::binary);
	//if (!copyFile.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 

	/*ifstream file("test.txt", std::ios::binary);*///создать input-file object тоесть файл ИЗ которого читать  
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}

	//char ch;  
	//int size = 0;  
	//while (file.get(ch))
	//{
	//	size++;
	//	if (size > 4000000)
	//	{
	//		cout << "Слишком большой файл" << endl;
	//		break;
	//	}
	//	copyFile << ch;
	//}
	//file.close();
	//copyFile.close();



//****************************************************************************************
// 639.	Архивация файла построчно
//****************************************************************************************

	//ofstream ofile;

	//ofile.open("copy.txt", std::ios::binary);
	//if (!ofile.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 

	//ifstream file("test.txt");
	//if (!file.is_open()) 
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	cout << "Read: no" << endl;
	//}
	//else {
	//	string line;
	//	string boof;
	//	short line_size = '0';
	//	short counter = 1;

	//	while (file.good()) 
	//	{
	//		getline(file, line);
	//		if (line.empty()) {
	//			break;
	//		}
	//		line_size = line.size(); // string size;
	//		if (line_size - 1 > 0) 
	//		{
	//			char ch = line[0];
	//			for (int i = 1; i < line_size; i++) 
	//			{
	//				if (line[i] == ch) {
	//					counter++;
	//				}
	//				else 
	//				{
	//					boof += ch;
	//					boof += to_string(counter);
	//					counter = 1;
	//					ch = line[i];
	//					cout << boof << endl;
	//				}
	//			}
	//			boof += ch;
	//			boof += to_string(counter);
	//			cout << boof << endl;
	//		}
	//	}
	//	if (boof.size() > line_size) {
	//		boof = "";
	//	}
	//	file.close();
	//}

//****************************************************************************************
// 639.	Архивация файла посимвольно
//****************************************************************************************

	//ofstream ofile;

	//ofile.open("zip.txt", std::ios::binary);
	//if (!ofile.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 

	//ifstream file("test.txt");
	//if (!file.is_open()) 
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	cout << "Read: no" << endl;
	//}
	//else {
	//	string line;
	//	string boof;
	//	short line_size = '0';
	//	short count = 1;

	//	char ch;
	//	char save_ch;
	//	file.get(save_ch);

	//	while (file.get(ch)) 
	//	{
	//		if (ch == save_ch) {
	//			count++;
	//		}
	//		else 
	//		{
	//			boof += save_ch;
	//			boof += to_string(count);
	//			boof += '#';
	//			count = 1;
	//			save_ch = ch;
	//		}
	//	}
	//	boof += save_ch;
	//	boof += to_string(count);
	//	boof += '#';
	//	cout << boof << endl;
	//	ofile << boof;
	//	file.close();
	//	ofile.close();
	//}

//****************************************************************************************
// 640.	Разархивация файла
//****************************************************************************************

	//ofstream ofile;

	//ofile.open("unzip.txt", std::ios::binary);
	//if (!ofile.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 

	//ifstream file("zip.txt", std::ios::binary);
	//if (!file.is_open()) 
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	cout << "Read: no" << endl;
	//}
	//else {
	//	string line;
	//	string boof;
	//	short line_size = '0';
	//	short count = 1;

	//	char ch;
	//	char num_ch;
	//	string num_str;

	//	while (file.get(ch)) 
	//	{
	//		do
	//		{
	//			file.get(num_ch);
	//			num_str += num_ch;
	//		}while (num_ch != '#');

	//		for (int i = 0; i < atoi(num_str.c_str()); i++) 
	//		{
	//			boof += ch;
	//		}

	//		num_str = "";
	//	}
	//	//boof += save_ch;
	//	//boof += to_string(count);
	//	cout << boof << endl;
	//	ofile << boof;
	//	file.close();
	//	ofile.close();
	//}

//****************************************************************************************
// 
//****************************************************************************************
	if_max_min();
	//string_stroki();

//****************************************************************************************
// Удалить дубликаты вектор
//****************************************************************************************

	//vector <string> vec;

	//vec.push_back("sasas");
	//vec.push_back("sasas");
	//vec.push_back("ss");
	//vec.push_back("ss");
	//vec.push_back("ss");

	//for (vector <string>::iterator base = vec.begin(); base != vec.end(); base++)
	//{
	//	for (vector <string>::iterator it = base + 1; it != vec.end(); )
	//	{
	//		if (*base == *it)
	//		{
	//			it = vec.erase(it);
	//		}
	//		else
	//		{
	//			++it;
	//		}
	//	}	
	//}

	//for (vector <string>::iterator it = vec.begin();it != vec.end(); it++) // пока итератор не достигнет конца
 //   {
	//	cout << *it << " "; // выводим значение элемента, на который указывает итератор
 //   }

//****************************************************************************************
// Три перменных
//****************************************************************************************

	//bool a = 0;
	//bool b = 1;
	//bool c = 2;

	//cout << a << b << c;

//****************************************************************************************
// Тест на сложение
//****************************************************************************************

	//int x = 0;
	//int answer = 0;
	//int right = 0;
	//int wrong = 0;


	//while (true)
	//{
	//	x = rand() % 11;
	//	y = rand() % 11;

	//	cout << x << "+" << y << " = ";
	//	cin >> answer;

	//	if (answer == x + y)
	//	{
	//		right++;
	//	}
	//	else
	//	{
	//		wrong++;
	//	}
	//	cout << right << " " << wrong << endl;
	//}

//****************************************************************************************
// Тест на вычитание 
//****************************************************************************************

	//int x = 0;
	//int answer = 0;
	//int right = 0;
	//int wrong = 0;

	//while (true)
	//{
	//	x = rand() % 11;
	//	y = rand() % 11;

	//	if (x - y >= 0)
	//	{
	//		cout << x << "-" << y << " = ";
	//		cin >> answer;

	//		if (answer == x - y)
	//		{
	//			right++;
	//		}
	//		else
	//		{
	//			wrong++;
	//		}
	//		cout << right << " " << wrong << endl;
	//	}
	//}

//****************************************************************************************
// Сколько квадратов
//****************************************************************************************

	//int x;
	//int y;
	//cin >> x >> y;
	//cout << (x/5) * (y/5);

//****************************************************************************************
// Преобразование формата даты
//****************************************************************************************

	//string str1 = "11-07-2015";
	//string str2;
	//str2 = str1.substr(3,2) + "." + str1.substr(0,2) + "." + str1.substr(6,4);
	//cout << str2;

//****************************************************************************************
// Скидка
//****************************************************************************************

	//float x;
	//cin >> x;
	//if (x > 100)
	//{
	//	cout << "Вам предоставляется скидка 10% " << endl;
	//	x = x - x * 0.1;
	//	cout << "Сумма покупки с учётом скидки " << x;
	//}
	//else
	//{
	//	cout << "Скидка не предоставляется";
	//	x = x - x * 0.1;
	//	cout << "Сумма покупки" << x;
	//}

//****************************************************************************************
// Деление
//****************************************************************************************

//****************************************************************************************
// 	43.	Пока не чётный
//****************************************************************************************

	//srand(time(0));
	//
	//queue <int> que1;

	//que1.push(1);
	//que1.push(6);
	//que1.push(1);
	//que1.push(1);
	//que1.push(3);
	//que1.push(6);
	//que1.push(9);

	//while(!que1.empty() && (que1.front()%2 == 1 || que1.front()%3 == 0))
	//{
	//	que1.pop();
	//}

	//while(!que1.empty())
	//{
	//	cout << que1.front() << " ";
	//	que1.pop();
	//}



//****************************************************************************************
// 	44.	Объединить очереди
//****************************************************************************************

	//srand(time(0));
	//int b = 0;
	//float avg = 0;
	//
	//queue <int> que1,que2, que3;

	//que1.push(1);
	//que1.push(3);
	////que1.push(11);


	//que2.push(2);
	//que2.push(4);
	//que2.push(6);
	//que2.push(8);

	//while(!que1.empty() || !que2.empty())
	//{
	//	if (!que1.empty())
	//	{
	//		que3.push(que1.front());
	//		que1.pop();
	//	}

	//	if (!que2.empty())
	//	{
	//		que3.push(que2.front());
	//		que2.pop();
	//	}

	//}

	//while(!que3.empty())
	//{
	//	cout << que3.front() << " ";
	//	que3.pop();
	//}


//****************************************************************************************
// 	45.	Объединить очереди 2
//****************************************************************************************

	//srand(time(0));
	//int b = 0;
	//float avg = 0;
	//
	//queue <int> que1,que2, que3;

	//que1.push(1);
	//que1.push(2);
	//que1.push(5);
	//que1.push(5);
	//que1.push(9);

	//que2.push(1);
	//que2.push(3);
	//que2.push(8);

	//while(!que1.empty() && !que2.empty())
	//{
	//	if (!que1.empty() && !que2.empty())
	//	{
	//		if (que1.front() < que2.front())
	//		{
	//			que3.push(que1.front());
	//			que1.pop();
	//		}
	//		else
	//		{
	//			que3.push(que2.front());
	//			que2.pop();
	//		}
	//	}

	//	if (que1.empty() && !que2.empty())
	//	{
	//		que3.push(que2.front());
	//		que2.pop();
	//	}

	//	if (que2.empty() && !que1.empty())
	//	{
	//		que3.push(que1.front());
	//		que1.pop();
	//	}
	//}

	//while(!que3.empty())
	//{
	//	cout << que3.front() << " ";
	//	que3.pop();
	//}



//****************************************************************************************
// 	Очередь вещественных чисел
//****************************************************************************************

	//srand(time(0));
	//int b = 0;
	//float avg = 0;
	//
	//queue <float> que1,que2;

	//que1.push(7.8);
	//que1.push(4.8);
	//que1.push(3.9);
	//que1.push(2.4);

	//que2 = que1;

	//while(!que2.empty())
	//{
	//	avg=avg+que2.front();
	//	b++;
	//	que2.pop();
	//}

	//avg = avg / b;

	//while(que1.front() > avg)
	//{
	//	que2.push(que1.front());
	//	que1.pop();
	//}

	//que2.push(avg);

	//while(!que1.empty())
	//{
	//	que2.push(que1.front());
	//	que1.pop();
	//}

	//que1=que2;

	//while(!que1.empty())
	//{
	//	cout << que1.front() << " ";
	//	que1.pop();
	//}

//****************************************************************************************
// 	Дерево Число Исенбаева
//****************************************************************************************

	//const int N = 6;
	// 
	//map<string, int> mp;
	//string s[N][3];
 // 
	//s[0][0] = "A"; s[0][1] = "B"; s[0][2] = "C";
	//s[1][0] = "B"; s[1][1] = "E"; s[1][2] = "F";
	//s[2][0] = "C"; s[2][1] = "G"; s[2][2] = "H";
	//s[3][0] = "A"; s[3][1] = "C"; s[3][2] = "D";
	//s[4][0] = "E"; s[4][1] = "I"; s[4][2] = "J";
	//s[5][0] = "K"; s[5][1] = "L"; s[5][2] = "M";

	//mp.insert(pair<string,int>("A", 0));

	//for (int i = 0; i < N; i++)
	//{
	//	bool find = 0;
	//	int chi = 0;
	//	// ищем есть ли хоть один из очередной тройки фамилий в словаре
	//	// и запоминаем его число
	//	for (int j = 0; j < 3; j++)
	//	{
	//		map <string,int> :: iterator found = mp.find(s[i][j]);
	//		if (found != mp.end() && (*found).second != -1)
	//		{
	//			chi = (*found).second;
	//			find = 1;
	//			break;
	//		}
	//	}

	//	// если кто есть то помещаем тех кого нет с числом на 1 больше
	//	if (find)
	//	{
	//		for (int j = 0; j < 3; j++)
	//		{
	//			map <string,int> :: iterator found = mp.find(s[i][j]);
	//			if (found == mp.end())
	//			{
	//				mp.insert(pair<string,int>(s[i][j] , chi+1));
	//			}
	//		}
	//	}
	//	// если никого нет то помещаем всех с числом -1, что значит неопределенные
	//	else
	//	{
	//		for (int j = 0; j < 3; j++)
	//		{
	//			mp.insert(pair<string,int>(s[i][j] , -1));
	//		}
	//	}

	//}

	//for (map <string,int>::iterator cur = mp.begin(); cur!=mp.end(); cur++)
	//{
	//	cout << cur->first << ": " << cur->second << endl;
	//}

//****************************************************************************************
// 	Электронные часы 1
//****************************************************************************************
	//int x;
	//cin >> x;
	//cout << x/60 << " " << x%60;

//****************************************************************************************
// 	Электронные часы 2
//****************************************************************************************
	//int x;
	//cin >> x;
	//cout << x/3600 << " " << x%3600/60;

//****************************************************************************************
// 	Электронные часы 3
//****************************************************************************************
	//int x;
	//cin >> x;
	//cout << x/3600 << " " << x%3600/60 << " " << x%60;



//srand( time(0) );
//while (true)
//{
//	int a, b, c, d, k=0, l=0;
//	a=rand()%11;
//	b=rand()%a;
//	c=a-b;
//	cout << "Решите пример:" << a << "-" << b << endl;
//	cout << "Введите ответ :" << endl;
//	cin >> d;
//	if (c == d) {
//	  cout << "Решение верно" << endl;
//	  k++;
//	} else {
//	  cout << "Решение неверно" << endl;
//	  l++;
//	}
//}

	//srand(time(0));
	//const int N = 7;
	//int mas[N] = {0, 0, 0, 0, 0, 0, 0}, i = 0, a = 0;
	//while (i<=400){
	//	a = rand() % 7;
	//	if (a == 0 && mas[a + 1] == 0){
	//		mas[a] = 1;
	//		i++;
	//	}
	//	else if (a == N - 1 && mas[a-1]==0){
	//		mas[a] = 1;
	//		i++;
	//	}
	//	else if (mas[a+1] == 0 && mas[a-1]==0){
	//		mas[a] = 1;
	//		i++;
	//	}
	//	
	//}
	//for (int i = 0; i < N; i++){
	//	cout << mas[i];
	//}

//****************************************************************************************
// 	Минимум из трёх
//****************************************************************************************
	//int a, b, c;
	//cin >> a >> b >> c;
	//if (a <= b && a <= c)
	//	cout << a;
	//else if (b <= a && b <= c)
	//	cout << b;
	//else if (c <= a && c <= b)
	//	cout << c;

//****************************************************************************************
// 	Треугольник?
//****************************************************************************************
	//int x, y, z;
	//cin >> x >> y >> z;
	//if (x + y > z && x + z > y && y + z > x)
	//{
	//	cout << 1;
	//}
	//else
	//{
	//	cout << 0;
	//}

//****************************************************************************************
// 	Каждый третий
//****************************************************************************************
	//string str = "abcd abcd ab";
	//for (int i = 2; i < str.length(); i+=3){
	//	cout << str[i] << " ";
	//}

//****************************************************************************************
// 	Секунды, минуты. Что больше?
//****************************************************************************************

	//int a, b;
	//cin >> a >> b;
	//if (a * 60 > b)
	//	cout << a;
	//else if (a * 60 < b)
	//	cout << b;
	//else
	//	cout << "равны";

//****************************************************************************************
// 	Километры в час, метры в секунду
//****************************************************************************************

	//int a, b;
	//cin >> a >> b;
	//if (a * 1000 / 3600 > b)
	//	cout << a << " км/ч";
	//else if (a * 1000 / 3600 < b)
	//	cout << b << " м/с";
	//else
	//	cout << "равны";

//****************************************************************************************
// 	У какой фигуры площадь больше?
//****************************************************************************************

	//float a, b;
	//cin >> a >> b;
	//if (3.14 * a * a  > b * b)
	//	cout << 1 << endl;
	//else if (3.14 * a * a  < b * b)
	//	cout << 2 << endl;
	//else
	//	cout << "равны";


//****************************************************************************************
// 	Удалить вставить
//****************************************************************************************

	//list <string> intList; // создём список с элементами типа int

	//// заносим элементы в конец списка
	//intList.push_back("asas");
	//intList.push_back("dfdf");
	//intList.push_back("dewe");
	//intList.push_back("rtr");
	//intList.push_back("fghg");

	//intList.push_front(intList.back());


	////// печатаем элементы с помощью итератора
	////for(list <int>::iterator iter = intList.begin(); iter != intList.end(); iter++)
	////	cout << *iter << " ";

	////for(list <int>::iterator iter = intList.begin(); iter != intList.end(); iter++)
	////{
	////	if (*iter == 3)
	////	{
	////		intList.erase(iter);
	////		break;
	////	}
	////}

	////cout << endl;

	//// печатаем элементы с помощью итератора
	//for(list <string>::iterator iter = intList.begin(); iter != intList.end(); iter++)
	//	cout << *iter << " ";


	//int n = 5;
	//int i = 0;
	//int b = 1;
	//while (i < n)
	//{
	//	cout << i % 3 + 1 << " ";
	//	i++;
	//}

	//srand(time(0));
	//const int N = 7;
	//int mas[N] = { 0},  x = 0, i = 0;
	//bool f;
	//while(i<N){
	//	x = rand() % N + 1;
	//	for (int j = 0; j <= i; j++){
	//		if (mas[j] == x){
	//			break;
	//		}
	//		else if (j==i){
	//			mas[i] = x;
	//			i++;
	//			break;
	//		}
	//	}
	//}
	//for (int i = 0; i < N; i++){
	//	cout << mas[i];
	//}

	//const int N = 5;
	//int n, mas[N] = { 1, 2, 3, 4, 4};
	//bool f = 0;
	//for (int i = 0; i < N; i++){
	//	for (int j = 0; j <= i; j++){
	//		if (mas[i] == mas[j] && i!=j){
	//			f = 1;
	//		}
	//	}
	//}
	//cout << f;

//****************************************************************************************
// 	Найти число
//****************************************************************************************

	//for (int i = 1000; i < 9999; i++)
	//{
	//	if (i/1000 == i%1000/100 && i%100/10 == i%10)
	//	{
	//		if (isSqr(i))
	//			cout << i << endl; //;
	//	}
	//}

//****************************************************************************************
// 	Аутентификация и статистика
//****************************************************************************************

	//int ch = 0;

	//string pass = "";
	//bool authorized = 0;

	//vector <int> vec;

	//vec.assign(256,0);

	//ofstream file;
	//file.open("test.txt");
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 

	//int x = 0;

	//file << "Программа запущена " + getCurrentTime() << endl;

	//while(true)
	//{
	//	cout << "Введите пароль: " << endl;
	//	cin >> pass;

	//	if (pass == "0")
	//	{
	//		file << "Завершение работы программы " + getCurrentTime() << endl;
	//		break;
	//	}
	//	else if (pass == "123")
	//	{
	//		authorized = 1;
	//		file << "Вход в систему " + getCurrentTime() << endl;
	//		cout << "Вход в систему " + getCurrentTime() << endl;
	//	}
	//	else
	//	{
	//		file << "Неверный пароль " + getCurrentTime() << endl;
	//		cout << "Неверный пароль " + getCurrentTime()<< endl;
	//	}


	//	if (authorized)
	//	{
	//		while(ch != 27)
	//		{
	//			ch = _getch();

	//			vec[ch]++;

	//			cout << (char)ch << " - нажатый символ" << endl;
	//			file << (char)ch << " - нажатый символ" << endl;
	//		}
	//		file << "Выход из системы " + getCurrentTime() << endl;
	//		file << "Выход из системы " + getCurrentTime() << endl;
	//		authorized = 0;
	//	}
	//}

	//int idx = 0;
	//for (int i = 0; i < 5; i++)
	//{
	//	idx = idxMaxInVec(vec);

	//	file << (char)idx << " " << vec[idx] << endl;
	//	cout << (char)idx << " " << vec[idx] << endl;

	//	vec[idx] = 0;
	//}

	//file.close();

//****************************************************************************************
// 	Удалить нечётные элементы вектора
//****************************************************************************************

	//vector <int> vec;

	//vec.push_back(1);
	//vec.push_back(2);
	//vec.push_back(3);
	//vec.push_back(4);
	//vec.push_back(5);

	//int wp = 0;

	//for (int i = 0; i < vec.size(); i++) 
	//{
	//	if (vec[i] % 2 == 1) 
	//	{
	//		vec[i] = vec.back();
	//		vec.pop_back();
	//		i = -1;
	//	}
	//}

	//printVec(vec);

//****************************************************************************************
// 	Нечётные элементы
//****************************************************************************************

	//const int N=7;
	//int mas[N]={6, 3, 7, 9, 4, 5, 2};
	//int s=0, d=0;
	//for (int i=0; i<N; i++)
	//{
	//	if (mas[i]%2!=0)
	//	{
	//		s=s+mas[i];
	//		d++;
	//	}
	//}
	//cout << s/d;

//****************************************************************************************
// 	Удалить нечётные элементы вектора через resize
//****************************************************************************************
	//int wp = 0;
	//for (int i = 0; i < vec.size(); ++i) {
	//	if (vec[i] % 2 == 0) {
	//		vec[wp] = vec[i];
	//		wp++;
	//	}
	//}
	//vec.resize(wp);

//****************************************************************************************
// 	Лифт
//****************************************************************************************

	//float f, s = 0, d = 0;

	//vector <int> vec;

	//vec.push_back(50);
	//vec.push_back(50);
	//vec.push_back(55);
	//vec.push_back(66);
	//vec.push_back(80);
	//vec.push_back(80);
	//vec.push_back(100);

	//for(int i = 0; i < vec.size(); i++)
	//{        
	//	if ( x + vec[i] > 320)
	//		break;
	//	x = x + vec[i];
	//	cout << x << " " << i << endl; 
	//}

//****************************************************************************************
// 	Размен купюр (жадный алгоритм)
//****************************************************************************************

//	ifstream file ("money.txt");
//
//	float f, s = 0, d = 0;
//
//	vector <int> vec;
//
//	if (file.is_open())
//	{
//		while (file.good())
//		{
//			file >> x;
//			if (x == 0)
//			{
//				break;
//			}
//			vec.push_back(x);
//		}
//
//		while (file.good())
//		{
//			file >> x;
//			printVec2(vec, greedy(vec, x));
//
//		}
//
//		//cout << s << " ";		file.close();
//	}
//
//else cout << "Unable to open file";



//****************************************************************************************
// 	Сколько пар?
//****************************************************************************************
	
	//int N = 4;
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = i+1; j < N ; j++)
	//	{
	//			cout << i+1 << " " << j+1 << endl;
	//	}
	//	cout << endl;
	//}


//int a = 1;
//int b = 1;
//int x = 0;
//cin >> a;
//cin >> b;
//x = a;
//while (x <= b)
//{    
//   cout << x << " ";
//   x = x + 2 ; 
//}

//****************************************************************************************
// 	Константный итератор
//****************************************************************************************

	//vector<int> vec;

	//vec.push_back(1);
	//vec.push_back(2);
	//vec.push_back(4);
	//vec.push_back(1);
	//vec.push_back(4);

	//for (vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
	//{
	//	cout << *iter << " ";
	//	// так нельзя сделать, так как итератор константный
	//	//*iter = (*iter) * (*iter);
	//}

//****************************************************************************************
// 	Реверсивный итератор
//****************************************************************************************
	//vector<int> vec;

	//vec.push_back(1);
	//vec.push_back(2);
	//vec.push_back(4);
	//vec.push_back(1);
	//vec.push_back(4);
	//
	//for (vector<int>::reverse_iterator iter = vec.rbegin(); iter != vec.rend(); ++iter)
	//{
	//	cout << *iter << " ";
	//}


//int a = 1;
//int b = 1;
//int x = 0;
//cin >> a;
//cin >> b;
//x = a;
//while (x <= b)
//{    
//   cout << x << " ";
//   x = x + 2 ; 
//}



//****************************************************************************************
// 	файлы из текущей папки, файл конфигураций, сохранение файла
//****************************************************************************************

	//ifstream fileConfig("user.txt");
	//
	//string fileName;

	//if (!fileConfig.is_open())
	//{
	//	vector <string> vecFile;

	//	WIN32_FIND_DATA f;
	//	HANDLE h = FindFirstFile("./*", &f);
	//	
	//	if(h != INVALID_HANDLE_VALUE)
	//	{
	//		do
	//		{
	//			fileName = f.cFileName;
	//		
	//			if ((int)fileName.find(".cpp") != -1 && (int)fileName.find("stdafx") == -1)
	//			{
	//				vecFile.push_back(fileName);
	//			}

	//		} while(FindNextFile(h, &f));
	//	}
	//	else
	//	{
	//		cout << "Error opening directory" << endl;
	//	}

	//	if (vecFile.size() > 1)
	//	{
	//		print(vecFile);
	//		cout << "Выберите файл. Ваш выбор будет запомнен." << endl;

	//		int y = 0;
	//		int ch = 0;

	//		gotoxy(x, y);

	//		bool exit = 0;

	//		while(true)
	//		{
	//			int tx = x;
	//			int ty = y;

	//			ch = _getch();
	//			if (ch == 224)
	//			{
	//				ch = _getch();
	//			}

	//			switch (ch)
	//			{
	//				case 80:// вниз
	//					y++;
	//				break;
	//				case 72:// вверх
	//					y--;
	//				break;
	//				case 13:// enter
	//					
	//					fileName = vecFile[y];

	//					ofstream file ("user.txt");
	//					
	//					if (!file.is_open())
	//					{
	//						cout<<"Unable to open fout.\n";
	//						system("pause");
	//						return 0;
	//					}
	//					else 
	//					{
	//						file << fileName;
	//						file.close();
	//					}

	//					exit = 1;

	//				break;
	//			}

	//			if (exit) break;

	//			if (y < 0) y = 0;
	//			if (y > vecFile.size()-1) y = vecFile.size()-1;

	//			gotoxy(x, y);
	//		}
	//	}
	//}
	//else
	//{
	//	fileConfig >> fileName;
	//	fileConfig.close();
	//}


//****************************************************************************************
// 	файлы из текущей папки, файл конфигураций, сохранение файла
//****************************************************************************************


	//ifstream file("text.txt");
	//
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	vector <string> vec;

	//	string s;

	//	char ch; 
	//	while (file.get(ch))
	//	{
	//		if ((int)ch == 10)
	//		{
	//			s = trim(s);
	//			vec.push_back(s);
	//			s.clear();
	//		}
	//		else
	//		{
	//			if (ch == 32)
	//			{
	//				s += ch;
	//			}
	//			else if (ch != 32 && (int)ch != 9)
	//				s += ch;
	//		}
	//	}

	//	vec.push_back(s);

	//	print(vec);

	//	file.close();
	//}

//****************************************************************************************
// 	поиск максимума в векторе
//****************************************************************************************

	//srand(time(0));
	//int n = 100000;
	//vector <int> vec;
 //   vector <int>::iterator it = vec.begin(); 
	//for (int i = 0; i < n; i++)
	//{
	//	vec.push_back(rand());
	//}
	//int d = 0;
	//int max = vec[0];
	//for (int i = 0; i < n; i++)
	//{
	//	d++;
	//	if (vec[i] > max)
	//	{
	//		d++;
	//		max = vec[i];
	//	}
	//}
	//cout << n << " " << d << endl;

//****************************************************************************************
// 	поиск максимума в массиве
//****************************************************************************************

	//int mas[5] = {2,3,0,5,8};
	//
	//int max = mas[0];
	//for (int i = 0; i < 5; i++)
	//{
	//	if (mas[i] > max)
	//	{
	//		max = mas[i];
	//	}
	//}
	//
	//cout << max << endl;


//****************************************************************************************
// 	бинарный поиск
//****************************************************************************************

	//srand(time(0));


	//while (true)
	//{

	//	int n = 100000;
	//	vector <int> vec;

	//	for (int i = 0; i < n; i++)
	//	{
	//		vec.push_back(rand()%n);
	//	}

	//	//sort(vec);

	//	sort (vec.begin(), vec.end()); 

	//	//printVec(vec);

	//	int d = 0;
 //		int x = rand()%n;
	//	//cout << x << endl;
	//	int l = 0;
	//	int r = n-1;
	//	int m = 0;

	//	int find = 0;

	//	while (l <= r){
	//		d++;
	//		m = (l + r) / 2;
	//		if (vec[m] == x) {
	//			find = 1; //проверяем ключ со серединным элементом
	//			break;
	//		}
	//		if (vec[m] > x) 
	//			r = m - 1; // проверяем, какую часть нужно отбросить
	//		else 
	//			l = m + 1;
	//	}

	//	if (find){
	//		cout << "Найден " << endl;
	//	}
	//	else{
	//		cout << "Не найден " << endl;
	//	}

	//	cout << n << " " << d << " " << " " << log((float)n) / log(2.0) << endl;

	//	getch();
	//}

//****************************************************************************************
// 	Выделить слова
// 	Кто раньше?
//****************************************************************************************

 //   string str = "wee raa sss sss sdd";

 //   vector <string> vec;
 //   selectWords(vec, str);

	//print(vec);

	//cout << minOrMaxLen(vec) << endl;

//****************************************************************************************
// 	Одинаковые слова
//****************************************************************************************

    //string str = "a1c";
    //cout << odinakovslova(str);

//****************************************************************************************
// 	Одинаковые слова
//****************************************************************************************

    //string str = "abc ab abcd";
    //chastota(str);


//****************************************************************************************
// 	Минимальная сумма столбца
//****************************************************************************************

	//int const n = 2;
 //   int const m = 3;
 //   int mas[n][m] = 
 //   {
 //       {8,2,3},
 //       {4,5,0}
 //   };
 //   
	//int min = mas[0][0];
 //   int s = 0;
 //   int imin = 0;

 //   for(int i=0;i<m;i++)
 //   {
 //       for(int j=0;j<n;j++)
 //           s = s + mas[j][i];

 //       if(s < min)
 //       {
 //           min = s;
 //           imin = i;
 //       }
 //       s = 0;
 //   }
 //   cout << imin;


//****************************************************************************************
// 	Минимальная сумма столбца
//****************************************************************************************

	//int const n = 3;
 //   int mas[n][n] = 
 //   {
 //       {2,5,4},
 //       {5,8,7},
 //       {2,4,3}
 //   };

 //   float med1;
 //   float med2;

 //   int s = 0;
 //   int c = 0;

 //   for(int i=0;i<n;i++)
	//{
 //       s = s + mas[i][i];
	//}

 //   med1 = s/n;
 //   
	//s = 0;

 //   for(int i=n-1;i>=0;i--)
 //   {
 //       s = s + mas[c][i];
 //       c++;
 //   }

 //   med2 = s/n;

 //   cout << med1 << " " << med2;






//int const n = 3;
//    int mas[n][n] = 
//    {
//        {2,5,4},
//        {5,8,7},
//        {2,4,3}
//    };
//
//    float med1;
//    float med2;
//
//    int s = 0;
//    int c = 0;
//
//    for(int i=0;i<n;i++)
//	{
//        s = s + mas[i][i];
//	}
//
//    med1 = s/n;
//    
//	s = 0;
//
//    for(int i=n-1;i>=0;i--)
//    {
//        s = s + mas[c][i];
//        c++;
//    }
//
//    med2 = s/n;
//
//    cout << med1 << " " << med2;


//****************************************************************************************
// 	Система регистрации пользователей
//****************************************************************************************

	//struct status { //status - password and online
	//	string password;
	//	bool online = false;
	//};

	//vector <vector <string>> command; //user database
	//vector <string> q; //user database

	//q.push_back("register"); q.push_back("vasya");  q.push_back("12345"); command.push_back(q); q.clear();
	//q.push_back("vasya");    q.push_back("1234");                         command.push_back(q); q.clear();
	//q.push_back("login");    q.push_back("vasya");  q.push_back("12345"); command.push_back(q); q.clear();
	//q.push_back("login");    q.push_back("anakin"); q.push_back("qwe");   command.push_back(q); q.clear();
	//q.push_back("logout");   q.push_back("vasya");                        command.push_back(q); q.clear();
	//q.push_back("logout");   q.push_back("vasya");                        command.push_back(q); q.clear();

	//vector <Command> cmd;
	//Command temp;

//register alex qwe
//register sasha 12345
//rename sash vasya 
//rename sasha vasya 
//login vasya 1234
//login vasya 12345
//login anakin asd
//logout vasya
//logout vasya


	//temp.type  = "register";     temp.word1 = "alex";  temp.word2 = "qwe";	cmd.push_back(temp);
	//temp.type  = "register";     temp.word1 = "sasha"; temp.word2 = "12345";	cmd.push_back(temp);
	//temp.type  = "rename";       temp.word1 = "sash"; temp.word2 = "vasya";	cmd.push_back(temp);
	//temp.type  = "rename";       temp.word1 = "sash"; temp.word2 = "vasya";	cmd.push_back(temp);

	//temp.type  = "CHANGE_PASS";     temp.word1 = "user"; temp.word2 = "123";	cmd.push_back(temp);
	//temp.type  = "RENAME_LOGIN";    temp.word1 = "user"; temp.word2 = "admin";	cmd.push_back(temp);
	//temp.type  = "SHOW_PASS";		temp.word1 = "admin";				        cmd.push_back(temp);
	//temp.type  = "RENAME_LOGIN";	temp.word1 = "user"; temp.word2 = "admin";	cmd.push_back(temp);
	//temp.type  = "CHANGE_PASS";     temp.word1 = "USSR"; temp.word2 = "Moscow"; cmd.push_back(temp);
	//temp.type  = "SHOW_ALL";													cmd.push_back(temp);

 //   map <string, string> bd;
 //

 //   typedef std::map<std::string, status> db; // use this typedef for an iterator
	//map <string, status> database; //user database

 //   int n; 


	//for (int i = 0; i < command.size(); i++)
	//{
 //       string com, login, password; //command and login
 //       status query; //for status input
 //       //cin >> com;
	//	com = command[i][0];
 //       if (com == "register")
	//	{
 //           login = command[i][1];
 //           password = command[i][2];

 //           map <string, status>::iterator it = database.find(login); //returning an iterator

 //           if (it != database.end()) //each el from database is in [begin, end). it = database.end() means that there is no such element in db
	//		{ 
 //               cout << "fail: user already exists\n";
 //           }
 //           else 
	//		{
 //               database[login].password = password; // register
 //               cout << "success: new user added\n";
 //           }
 //       }
 //       //user can log in if he isn't online but he is registered
 //       else if (com == "login") 
	//	{
 //           login = command[i][1];
 //           password = command[i][2];

 //           map <string, status>::iterator it = database.find(login); //returning an iterator

 //           if (it != database.end())
	//		{
 //               if (password == database[login].password)
	//			{
 //                   if(!database[login].online)
	//				{
 //                       database[login].online = true;
 //                       cout << "success: user logged in\n";
 //                   }
 //                   else cout << "fail: already logged in\n";
 //               }
 //               else cout << "fail: incorrect password\n";
 //           }
 //           else cout << "fail: no such user\n";
 //       }
 //       //logout
 //       else if (com == "logout") 
	//	{
 //           login = command[i][1];

 //           if (database.find(login) == database.end()) 
	//			cout << "fail: no such user\n";
 //           else 
	//		{
 //               if (!database[login].online) 
	//				cout << "fail: already logged out\n";
 //               else {
 //
 //                   database[login].online = false;
 //                   cout << "success: user logged out\n";
 //               }
 //           }
 //       }
 //   }

 //   for (int i = 0; i < cmd.size(); i++) 
	//{
	//	if (cmd[i].type == "CHANGE_PASS") 
	//	{
	//		if (bd.find(cmd[i].word1) == bd.end()) 
	//		{
	//			cout << "Add new user" << endl;
	//		}
	//		else
	//		{
	//			cout << "CHANGE_PASS" << endl;
	//		}
	//		bd[cmd[i].word1] = cmd[i].word2;
 //       } 
	//	else if (cmd[i].type == "RENAME_LOGIN") 
	//	{
	//		if (cmd[i].word1 == cmd[i].word2)
	//		{
	//			cout << "Incorrect rename, skip" << endl;
	//			continue;
	//		}

	//		if (bd.find(cmd[i].word1) == bd.end()) 
	//		{
	//			cout << "Incorrect rename, skip" << endl;
	//			continue;
	//		}

	//		if (bd.find(cmd[i].word2) != bd.end()) 
	//		{
	//			cout << "Incorrect rename, skip" << endl;
	//			continue;
	//		}

	//		map <string,string>::iterator it = bd.find(cmd[i].word1);

	//		if (it == bd.end()) 
	//		{
	//			cout << "Add new" << endl;
	//		}
	//		else
	//		{
	//			string pass = (*it).second;
	//			bd.erase(it);
	//			bd[cmd[i].word2] = pass;

	//			cout << "RENAME_LOGIN from " << cmd[i].word1 << " to  " << cmd[i].word2 << endl;
	//		}
	//		bd[cmd[i].word1] = cmd[i].word2;
 //       } 
	//	else if (cmd[i].type == "SHOW_PASS") 
	//	{
	//		map <string,string>::iterator it = bd.find(cmd[i].word1);

	//		if (it == bd.end()) 
	//		{
	//			cout << "login not found" << endl;
	//			continue;
	//		}
	//		cout << it->first << ": " << it->second << endl;
	//	}
	//	else if (cmd[i].type == "SHOW_ALL") 
	//	{
	//		for (map <string,string>::iterator it = bd.begin(); it != bd.end(); it++)
	//		{
	//			cout << it->first << ": " << it->second << endl;
	//		}	
	//	}
 //   }

//****************************************************************************************
// 	Отсортирован или нет 2d
//****************************************************************************************

	//const int N = 3;
	//int map[N][N] = {
	//	{2,1,1},
	//	{1,1,1},
	//	{1,1,2}
	//};

	//int x = 0;

	//bool sort = 1;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (x <= map[i][j])
	//		{
	//			x = map[i][j];
	//		}
	//		else
	//		{
	//			sort = 0;
	//		}
	//	}
	//}

	//cout << sort;
	
//****************************************************************************************
// 	624.	Заявки на проведение занятий
//****************************************************************************************

//№	     1	2	3	4	5	6	7	8	9	10	11
//-------------------------------------------------------------
//Начало 5	0	12	5	3	8	2	3	6	1	8
//Конец	 9	6	14	7	8	12	13	5	10	4	11

	//vector <Lesson> vec;
	//Lesson les;

	//les.begin = 7;  les.end = 8;  vec.push_back(les);
	//les.begin = 5;  les.end = 9;  vec.push_back(les);
	//les.begin = 0;  les.end = 6;  vec.push_back(les);
	//les.begin = 12; les.end = 14; vec.push_back(les);
	//les.begin = 5;  les.end = 7;  vec.push_back(les);
	//les.begin = 3;  les.end = 8;  vec.push_back(les);
	//les.begin = 8;  les.end = 12; vec.push_back(les);
	//les.begin = 2;  les.end = 12; vec.push_back(les);
	//les.begin = 3;  les.end = 6;  vec.push_back(les);
	//les.begin = 6;  les.end = 10; vec.push_back(les);
	//les.begin = 1;  les.end = 4;  vec.push_back(les);
	//les.begin = 8;  les.end = 11; vec.push_back(les);

	//sort(vec);

	//for(int i = 0; i < vec.size(); i++)
	//{        
	//	cout << vec[i].begin << " " << vec[i].end << endl; 
	//}
	//cout << endl; 

	//for(int k = 0; k < vec.size()-1; k++) // i - номер прохода
	//{            
	//	for(int i = 0; i < vec.size()-1; i++) // i - номер прохода
	//	{            
	//		les = vec[i];

	//		cout << vec[i].begin << " " << vec[i].end << " - "; 
	//		for(int j = i+1; j < vec.size(); j++) // внутренний цикл прохода
	//		{   
	//			if (les.end <= vec[j].begin)
	//			{
	//				les = vec[j];
	//				cout << vec[j].begin << " " << vec[j].end << " - "; 
	//			}
	//		}
	//		cout << endl; 
	//	}
	//}

//****************************************************************************************
// 	Алиса Стрелкова Шифр Цезаря
//****************************************************************************************

	//crypt
	//ofstream cryptFile;
	//cryptFile.open("crypt.txt");
	//if (!cryptFile.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 

	//ifstream file("foto2.jpg", std::ios::binary);//создать input-file object тоесть файл ИЗ которого читать  
	//
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	char ch;  
	//	while (file.get(ch))
	//	{
	//		cryptFile << ch + 500 + 3 << " ";
	//	}
	//	cryptFile << 1000;
	//	file.close();
	//	cryptFile.close();
	//}

	//decrypt
	//ofstream cryptFile2;
	//cryptFile2.open("decrypt.jpg", std::ios::binary);
	//if (!cryptFile2.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 
	//ifstream file2("crypt.txt"/*, std::ios::binary*/);
	//
	//if (!file2.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	int ch2;  
	//	while (file2.good())
	//	{
	//		file2 >> ch2;
	//		if (ch2 != 1000)
	//			cryptFile2 << (char)(ch2-500-3);
	//	}
	//	file2.close();
	//	cryptFile2.close();
	//}



//****************************************************************************************
// 	Шифрация подстановкой
//****************************************************************************************

	////crypt
	//string str = "ХУТЭЦЙГРФЫНАЪСИЩПБВДМЗЖЕШЬЧЯКЮОЛЁ";

	//ofstream cryptFile;
	//cryptFile.open("crypt.txt");
	//if (!cryptFile.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 

	//ifstream file("test.txt", std::ios::binary);//создать input-file object тоесть файл ИЗ которого читать  
	//
	//if (!file.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	char ch;  
	//	unsigned char ch2;  
	//	while (file.get(ch))
	//	{
	//		ch2 = (unsigned char)ch - 192;
	//		//cout << (int)ch2 << " ";
	//		if (ch2 == 96 || ch2 == 74 || ch2 == 77)
	//		{
	//			cryptFile << "*";
	//		}
	//		else
	//		{
	//			cryptFile << str[ch2];			
	//		}
	//		
	//		
	//	}
	//	file.close();
	//	cryptFile.close();
	//}

	////decrypt
	//string str2 = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	//ofstream cryptFile2;
	//cryptFile2.open("decrypt.txt", std::ios::binary);
	//if (!cryptFile2.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//} 
	//ifstream file2("crypt.txt"/*, std::ios::binary*/);
	//
	//if (!file2.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	char ch;  
	//	unsigned char  ch2;  
	//	while (file2.get(ch))
	//	{
	//		ch2 = (unsigned char)ch - 192;
	//		cout << (int)ch2 << " ";
	//		//ch2=ch;
	//		/*if (ch2 == 96 || ch2 == 74 || ch2 == 77 || ch2 == 106|| ch2 == 253|| ch2 == -2|| ch2 == -3|| ch2 == -171|| ch2 == -6|| ch2 == -1)
	//		{
	//			cryptFile2 << "*";
	//		}
	//		else */if (ch2 >= 0 && ch2 < str2.length())
	//		{
	//			cryptFile2 << str2[ch2];			
	//		}
	//		
	//		
	//	}
	//	file2.close();
	//	cryptFile2.close();
	//}


//****************************************************************************************
// 	Алиса Стрелкова Шифр Цезаря
//****************************************************************************************



//****************************************************************************************
// 	Меню без классов и структур
//****************************************************************************************

	//int x = 0, y = 0;
	//int ch = 0;

	//string fileName;

	//while(true)
	//{		
	//	system("cls");

	//	cout << "Зашифровать" << endl;
	//	cout << "Расшифровать" << endl;
	//	cout << "Выход" << endl;

	//	gotoxy(x, y);

	//	int tx = x;
	//	int ty = y;

	//	ch = _getch();
	//	if (ch == 224)
	//	{
	//		ch = _getch();
	//	}

	//	switch (ch)
	//	{
	//		case 77:// вправо
	//			x++;
	//		break;
	//		case 75:// влево
	//			x--;
	//			break;
	//		case 80:// вниз
	//			y++;
	//			break;
	//		case 72:// вверх
	//			y--;
	//			break;
	//		case 27:// esc

	//			break;
	//		case 13:// enter

	//				system("cls");
	//				if (y == 0 || y == 1)
	//				{
	//					cout << "Введите имя файла: ";	
	//					cin >> fileName;
	//				}
	//				else if (y == 2)
	//				{
	//					return 0;
	//				}


	//				//gotoxy(40,0);
	//				//gotoxy(0,0);
	//				//printVec(tasks2);
	//	

	//		break;
	//	}


	//	gotoxy(x,y);
	//}



//****************************************************************************************
// 	Процедурная генерация 2
//****************************************************************************************

	//srand(time(NULL));
	//int const n = 5;
	//int mas[n][n] = {0};
	//int x; int y;
	//for(int i = 0; i < 100000; i++){
	//	x = rand()%n; y = rand()%n;
	//	if (x != 0)
	//		if (mas[x-1][y] == 1)
	//			continue;
	//	if (x != n-1)
	//		if (mas[x+1][y] == 1)
	//			continue;
	//	if (x != 0 && y != 0)
	//		if (mas[x-1][y-1] == 1)
	//			continue;
	//	if (x != 0 && y != n-1)
	//		if (mas[x-1][y+1] == 1)
	//			continue;
	//	if (x != n-1 && y != n-1)
	//		if (mas[x+1][y+1] == 1)
	//			continue;
	//	if (x != n-1 && y != 0)
	//		if (mas[x+1][y-1] == 1)
	//			continue;
	//	if (y != 0)
	//		if (mas[x][y-1] == 1)
	//			continue;
	//	if (y != n-1)
	//		if (mas[x][y+1] == 1)
	//			continue;
	//	if (mas[x][y] == 1)
	//		continue;
	//	mas[x][y] = 1;
	//}		

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << mas[i][j] << " ";
	//	}
	//	cout << endl;
	//}



//****************************************************************************************
// Процедурная генерация в массиве с границами
//****************************************************************************************

	//const int n = 7;
	//int mas[n][n] = {0};
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
	//		{
	//			mas[j][i] = 2;
	//		}
	//	}
	//}
	//int x,y;
	//srand(time(0));
	//for(int i = 0; i < 100000; i++)
	//{
	//	x = rand(1,n-2);
	//	y = rand(1,n-2);

	//	if (mas[x-1][y] != 1 &&
	//		mas[x+1][y] != 1 &&
	//		mas[x-1][y-1] != 1 &&
	//		mas[x-1][y+1] != 1 &&
	//		mas[x+1][y-1] != 1 &&
	//		mas[x+1][y+1] != 1 &&
	//		mas[x][y-1] != 1 &&
	//		mas[x][y+1] != 1 &&
	//		mas[x][y] != 1)
	//	{
	//		mas[x][y] = 1;
	//	}
	//}		


	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << mas[i][j] << " ";
	//	}
	//	cout << endl;
	//}


//****************************************************************************************
// Палиндром
//****************************************************************************************

	//const int n = 5;
	//int mas[n] = {1,2,3,3,1};
	//bool f = 1;
	//for (int i = 0; i < n/2; i++)
	//{
	//	if (mas[i] != mas[n-i-1])
	//	{
	//		f = 0;		
	//		break;
	//	}
	//}
	//cout << f;


//****************************************************************************************
// 355.	Смена мест
//****************************************************************************************

	//vector <int> vec;
	//vec.push_back(1);
	//vec.push_back(2);
	//vec.push_back(3);
	//vec.push_back(4);
	//vec.push_back(5);
	//vec.push_back(6);
	//
	//for (int i = 0; i < vec.size()-1; i+=2)
	//{
	//	swap(vec[i], vec[i+1]);
	//}

	//for (int i = 0; i < vec.size(); i++)
	//{
	//	cout << vec[i] << " ";
	//}


//****************************************************************************************
// 353.	Циклический сдвиг влево
//****************************************************************************************

	//int t = 0;
	//vector <int> vec;
	//vec.push_back(1); vec.push_back(2); vec.push_back(3); vec.push_back(4);
	//t = vec[0];
	//for (int i = 0; i < vec.size()-1; i++)
	//{
	//	vec[i] = vec[i + 1];
	//}
	//vec.back() = t;

	//for (int i = 0; i < vec.size(); i++) 
	//{
	//	cout<<vec[i] << " ";
	//}

//****************************************************************************************
// 354.	Циклический сдвиг вправо
//****************************************************************************************

	//int t = 0;
	//vector <int> vec;
	//vec.push_back(1); vec.push_back(2); vec.push_back(3); vec.push_back(4);
	//t = vec.back();
	//for (int i = vec.size()-1; i > 0;i--)
	//{
	//	vec[i] = vec[i - 1];
	//}
	//vec[0] = t;
	//for (int i = 0; i < vec.size(); i++) 
	//{
	//	cout<<vec[i] << " ";
	//}

//****************************************************************************************
// Быстрая сортировка тест
//****************************************************************************************

	//vector <int> vec;

	//for (int i = 0; i < 5; i++) 
	//{
	//	initVecRand(vec);
	//	quickSort3(vec);
	//	if (!isSort(vec))
	//		printVec(vec);
	//	vec.clear();
	//}

//****************************************************************************************
// Быстрая сортировка тест
//****************************************************************************************

	//vector <int> vec;

	//for (int i = 0; i < 5; i++) 
	//{
	//	initVecRand(vec);
	//	quickSort3(vec);
	//	if (!isSort(vec))
	//		printVec(vec);
	//	vec.clear();
	//}

//****************************************************************************************
// Быстрая сортировка тест
//****************************************************************************************

	//vector <int> vec;

	//for (int i = 0; i < 5; i++) 
	//{
	//	initVecRand(vec);
	//	quickSort3(vec);
	//	if (!isSort(vec))
	//		printVec(vec);
	//	vec.clear();
	//}

//****************************************************************************************
// Угадай число
//****************************************************************************************

	//int x, y;
	//x = rand() % 50;
	//while(true)
	//{
	//	cin >> y;
	//	if (x == y)
	//	{
	//		cout << "good" << endl;
	//		break;
	//	}
	//	else if (y > x)
	//	{
	//		cout << "high" << endl;
	//	}
	//	else if (y < x)
	//	{
	//		cout << "low" << endl;
	//	}
	//}

//****************************************************************************************
// 361.	Из одного два
//****************************************************************************************

	//vector <int> vec;
	//vector <int> vec1;
	//vector <int> vec2;

	//vec.push_back(1);
	//vec.push_back(2);
	//vec.push_back(4);
	//vec.push_back(2);
	//vec.push_back(7);

	//for (int i = 0; i < vec.size(); i+=2)
	//{
	//	vec1.push_back(vec[i]);
	//}

	//for (int i = 1; i < vec.size(); i+=2)
	//{
	//	vec2.push_back(vec[i]);
	//}

	//print(vec);
	//print(vec1);
	//print(vec2);

//****************************************************************************************
// 359.	Наоборот
//****************************************************************************************

	//vector <int> vec;


	//vec.push_back(1);
	//vec.push_back(2);
	//vec.push_back(3);
	////vec.push_back(4);
	////vec.push_back(5);

	//for (int i = 0; i < vec.size(); i++)
	//{
	//	cout << vec[i] << ":" << vec[vec.size()-i-1] << " ";
	//}

//****************************************************************************************
// 25.	Скобки
//****************************************************************************************

 //   string s = "()()))";
 //   stack <char> stk;
	//stk.push(s[0]);
 //   for (int i = 1; i < s.length(); i++) 
	//{
 //       if (s[i] == '(')
 //       {
 //           stk.push(s[i]);
 //       }
	//	else if (!stk.empty() && stk.top() == '(' && s[i] == ')')
 //       {
 //           stk.pop();
 //       }
 //   }
	//cout << !str.empty();


//****************************************************************************************
// 25.	Скобки 2
//****************************************************************************************

 //   string s = "()(";
 //   stack <char> stk;
	//stk.push(s[0]);
 //   for (int i = 1; i < s.length(); i++) 
	//{
 //       if (s[i] == '(' || s[i] == '[')
 //       {
 //           stk.push(s[i]);
 //       }
 //       else if (stk.top() == '(' && s[i] == ')')
 //       {
 //           stk.pop();
 //       }
 //       else if (stk.top() == '[' && s[i] == ']')
 //       {
 //           stk.pop();
 //       }
 //   }
	//cout << !str.empty();

//****************************************************************************************
// Заливка
//****************************************************************************************


	//int map[10][10] = 
	//{
	//	{0,0,1,1,1,1,1,0,0,0},
	//	{0,1,0,0,0,0,0,1,0,0},
	//	{0,1,0,0,0,0,0,0,1,0},
	//	{0,1,0,0,0,0,0,0,1,0},
	//	{0,0,1,0,0,0,0,0,1,0},
	//	{0,1,0,0,0,0,0,0,1,0},
	//	{0,1,0,0,0,0,0,1,0,0},
	//	{0,0,1,0,0,0,1,0,0,0},
	//	{0,0,0,1,1,1,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0}
	//};


	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		if (map[i][j] == 0)
	//			cout << ' ';
	//		else
	//			cout << map[i][j];
	//	}
	//	cout << endl;
	//}


	//stack <SPoint> stk;
	//pushPoint(stk, 5, 5);
	//int x = 0;
	//int y = 0;

	//while(!stk.empty())
	//{
 //		x = stk.top().x;
	//	y = stk.top().y;
	//	stk.pop();

	//	map[x][y] = 1;

	//	validAndMarkMask(map, x+1, y,   stk);
	//	validAndMarkMask(map, x-1, y,   stk);
	//	validAndMarkMask(map, x,   y+1, stk);
	//	validAndMarkMask(map, x,   y-1, stk);
	//}

	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		cout << map[i][j];
	//	}
	//	cout << endl;
	//}



//****************************************************************************************
// Обратная польская запись
//****************************************************************************************

	//stack <int> stk;
 //   string str = "12+4*3/";

 //   for (i = 0; i < str.size(); i++)
 //   {

 //       if (isdigit(str[i]))
 //       {
	//		stk.push(str[i]-48);
 //       }
 //       else if (str[i] == '+' || str[i] == '-' || str[i] == '*'  || str[i] == '/')
 //       {
	//		int a, b;

	//		a = stk.top();
	//		stk.pop();
	//		b = stk.top();
	//		stk.pop();

	//		if (str[i] == '+')
	//			a = b + a;
	//		else if (str[i] == '-')
	//			a = b - a;
	//		else if (str[i] == '*')
	//			a = b * a;
	//		else if (str[i] == '/')
	//			a = b / a;

	//		stk.push(a);
 //       }
	//}

	//cout << stk.top();


//****************************************************************************************
// Из инфиксной в обратную польскую запись
//****************************************************************************************

	//stack <char> stk;
 //   string str = "2*(1+5)*2";
 //   string out_str ;

 //   for (int i = 0; i < str.size(); i++)
 //   {
 //       if (isdigit(str[i]))
 //       {
	//		out_str += str[i];
 //       }
	//	else if (str[i] == '(')
 //       {
	//		stk.push(str[i]);
	//	}
	//	else if (str[i] == ')')
 //       {
	//		while (stk.top() != '(')
	//		{
	//			out_str += stk.top();
	//			stk.pop();
	//		}
	//		stk.pop();
	//	}
 //       //else if (str[i] == '+' || str[i] == '-' || str[i] == '*'  || str[i] == '/')
	//	{
	//		while (!stk.empty() && (stk.top() == '+' || stk.top() == '-' || stk.top() == '*'  || stk.top() == '/'))
	//		{
	//			out_str += stk.top();
	//			stk.pop();
	//		}
	//		stk.push(str[i]);
	//	}
	//}

	//while (!stk.empty())
	//{
	//	out_str += stk.top();
	//	stk.pop();
	//}

	//cout << out_str << endl;
	//
	//cout << opz(out_str);

//****************************************************************************************
// 147.	Не более двух
//****************************************************************************************

	//int x, y;
 //   cin >> x >> y;
 //   if (abs(x-y)-1 <= 2)
 //   {
 //       cout << 1 << endl;
 //   }
 //   else
 //   {
 //       cout << 0 << endl;
 //   }

//****************************************************************************************
// блокировка закрытия консоли через крестик
//****************************************************************************************

	//HWND hWnd = GetForegroundWindow();
 //   cout<<"Try to close me..;)"<<endl;
 //   EnableWindow(hWnd, false);

	//BYTE pState;
 //   HWND hWnd = GetForegroundWindow();
 //   cout<<"Try to close me..;)"<<endl;
 //   EnableWindow(hWnd, false);
 //   GetKeyboardState(&pState);
 //   while( true )
 //   {
 //       Sleep(100);
 //       SetKeyboardState(&pState);
 //   }

//****************************************************************************************
// Шаблоны функций
//****************************************************************************************

	//int x = 0;
	//Point pt;
	//pt.x = 0;
	//printAdr(pt);
	//string str1 = "123";
	//string str2 = "234";
	//cout << _min(str1, str2);

//****************************************************************************************
// указатели на функции callback
//****************************************************************************************

	//int (*funcPtr)();
	//funcPtr = anyFunc;
 //   cout << anyFunc << " " << funcPtr << endl;
 //   cout << (*funcPtr)(); // вызов функции через указатель

//****************************************************************************************
// указатели на функции callback сортировка
//****************************************************************************************

	//vector <int> vec;
	//for (int i = 0; i < 5; i++){
	//	vec.push_back(rand()%10);
	//}
	//sort(vec, asc);
	//print(vec);

//****************************************************************************************
// указатели на функции callback калькулятор
//****************************************************************************************

 //   int a = getInteger();
 //   char op = getOperation();
 //   int b = getInteger();

	//arithmeticFcn fcn = getArithmeticFcn(op);
	//std::cout << a << ' ' << op << ' ' << b << " = " << fcn(a, b) << '\n';

//****************************************************************************************
// указатели на функции callback калькулятор массив
//****************************************************************************************

	//int a = 6;
	//int b = 3;

	//arithmeticFcn masFnc[] = {add, subtract, multiply, divide};

	//for(int i = 0; i < 4; i++)
	//{
	//	cout << a << ' ' /*<< op*/ << ' ' << b << " = " << masFnc[i](a, b) << '\n';
	//}

//****************************************************************************************
// указатели на функции callback тесты
//****************************************************************************************

	//vector <string> vec;
	//vec.push_back("abc");
	//vec.push_back("abc");
	//vec.push_back("abc");

	//testFnc masFnc[] = {test1,test2};

	//for(int i = 0; i < 2; i++)
	//{
	//	cout << masFnc[i](vec[0]) << '\n';
	//}


//****************************************************************************************
// указатели на функции callback for_each
//****************************************************************************************

	//vector <int> vec;
	//
	//vec.push_back(1);
	//vec.push_back(2);
	//vec.push_back(3);

	//for_each(vec,vecFunc2);

	//for_each(vec,vecFunc1);


	//testFnc masFnc[] = {test1,test2};

	//for(int i = 0; i < 2; i++)
	//{
	//	cout << masFnc[i](vec[0]) << '\n';
	//}


//****************************************************************************************
// моделирование очереди, двухядерная система
//****************************************************************************************

	//deque <Task> deq1;
	//deque <Task> deq2;

	//int id = 0;

	//for(int i = 0; i < 3; i++)
	//{
	//	pushTask(deq1, 50, 99);
	//}

	//for(int i = 0; i < 3; i++)
	//{
	//	pushTask(deq2, 10, 20);
	//}

	//int ch = 0;

	//while(true)
	//{

	//	while(!kbhit())// пока не нажата клавиша
	//	{
	//		system("cls");
	//		print(deq1,0, 0, "Ядро 1");
	//		print(deq2,10,0, "Ядро 2");
	//		Sleep(100);

	//		workDeque(deq1, deq2);
	//		workDeque(deq2, deq1);
	//	}
	//	ch = _getch();
	//	if (ch == 224)
	//		ch = _getch();

	//	switch (ch)
	//	{
	//		case 49: pushTask(deq1, 50, 99); break;// вправо
	//		case 50: pushTask(deq2, 50, 99); break;// вниз
	//		case 51: 
	//			if (!deq1.empty())
	//				deq1.pop_front(); 
	//			break;// влево
	//		case 52: ; 
	//			if (!deq2.empty())
	//				deq2.pop_front(); 
	//			break;// вверх

	//		case 13:// enter
	//		break;
	//	}
	//}

//****************************************************************************************
// 88.	Сортировка через указатели
//****************************************************************************************


	//const int n = 3;
 //   int mas[n] = { 4,2,3 }, * p;

	//sort(mas,3);

 //   for (int i = 0; i < n; i++)
 //   {
 //       cout << mas[i] << " ";
 //   }

//****************************************************************************************
// Студент - стипендия
//****************************************************************************************

	//map <string,int> mp;
	//
	//mp["ROMAN"]  = 100;
	//mp["ALEX"]   = 50;
	//mp["IVAN"]   = 200;
	//mp["ILIA"]   = 250;
	//mp["NIKITA"] = 50;

	////mp.key_comp();

	//int x = 0;

	//while(true)
	//{
	//	cout << "1. Добавить студета" << endl;
	//	cout << "2. Вывод списка" << endl;
	//	cout << "3. Удалить > 100" << endl;
	//	cout << "4. Поиск" << endl;
	//	cout << "5. Стипендия по ФИО" << endl;
	//	cout << "6. ФИО по стипендии" << endl;
	//	cout << "7. Удалить студента" << endl;
	//	cout << "8. Удалить диапазон" << endl;

	//	cin >> x;

	//	system("cls");

	//	if (x == 1)
	//	{
	//		//mp.insert ( pair< string ,int> ("asd",10) );
	//		//mp.insert(make_pair("asd",10));
	//		mp["Asd"] = 10;

	//	}
	//	else if (x == 2)
	//	{
	//		mp.value_comp();
	//		for (map <string,int>::iterator it = mp.begin(); it != mp.end(); it++)
	//		{
	//			cout << it->first << ": " << it->second << endl;
	//		}	
	//	}
	//	else if (x == 3)
	//	{
	//		//mp.key_comp();
	//		for (map <string,int>::iterator it = mp.begin(); it != mp.end(); )
	//		{
	//			if (it->second > 100) 
	//			{
	//				it = mp.erase(it);
	//				continue;
	//			}
	//			it++;
	//		}	
	//	}
	//	else if (x == 4)
	//	{
	//		if (mp.find("Asd") == mp.end()) 
	//		{
	//			cout << "no" << endl;
	//		}
	//		else
	//		{
	//			cout << "yes" << endl;
	//		}
	//	}
	//	else if (x == 5)
	//	{
	//		string str;
	//		cin >> str;

	//		str = toUpper(str);

	//		for (map <string,int>::iterator it = mp.begin(); it != mp.end(); it++)
	//		{
	//			cout << it->first << ": " << it->second << endl;
	//		}	

	//		cout << mp[str] << endl;

	//		system("pause");
	//	}
	//	else if (x == 6)
	//	{
	//		int x;
	//		cin >> x;

	//		for (map <string,int>::iterator it = mp.begin(); it != mp.end(); it++)
	//		{
	//			if (it->second == x)
	//				cout << it->first << endl;
	//				
	//		}	

	//		system("pause");
	//	}
	//	else if (x == 7)
	//	{
	//		string str;
	//		cin >> str;

	//		str = toUpper(str);

	//		map <string,int>::iterator it = mp.find(str);

	//		if (it == mp.end()) 
	//		{
	//			cout << "no" << endl;
	//		}
	//		else
	//		{
	//			mp.erase(it);
	//			cout << "yes" << endl;
	//		}
	//	}
	//	else if (x == 8)
	//	{

	//		map <string,int>::iterator itlow = mp.lower_bound ("IA");  // itlow points to b
	//		map <string,int>::iterator itup = mp.upper_bound ("IZ");   // itup points to e (not d!)

	//		cout << itlow->first << " " << itup->first << endl;
	//	
	//		mp.erase(itlow,itup);        // erases [itlow,itup)
	//
	//	}

	//	cin.clear();
	//	while(cin.get() !='\n');
	//}





	//std::map<char,int> mymap;
	//std::map<char,int>::iterator itlow,itup;

	//mymap['a']=20;
	//mymap['c']=40;
	//mymap['e']=60;
	//mymap['g']=80;
	//mymap['h']=100;

	//itlow=mymap.lower_bound ('b');  // itlow points to b
	//itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	//mymap.erase(itlow,itup);        // erases [itlow,itup)

	//// print content:
	//for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	//std::cout << it->first << " => " << it->second << '\n';

	system("pause");
}

// Как делать демонстрацию экрана, сделать подсказку
// Линии переделыват на ООП делать видео
// Будем ли с деревьями возиться, надо бы скорее всего там есть интересные моменты
// Прорабатывать очередь, возможно поискать новые задачи, это можно делать во время занятий
// Уровни программирования прописать, продвинутый курс разбить на уровни https://www.quora.com/What-are-the-growth-stages-of-a-programmer
// Нужна инструкция про то в каком формате высылать решения задач если через ВК.
// Если не наберем учеников нужно пересаживаться на питон
// IT Квантумы добавить в объявления.
// 74.	Двухядерный процеcсор добавить id для каждого процесса.
// Сделать видео в котором покзазывается как делать отсутпы
// Сделать видео о пошаговй отладке
// Доработать текст о пошагой отладке
// Оформить после след и пред
// Достаточно учеников много было потеряно из-за цены. Нужно что-то придумать дешевое но не напряжное для меня.
// Нужно каждый блок обосновывать для чего он нужен. Иначе ученик оказывается в вакууме.
// Куда мы движемся Ue4 QT или еще что-нибудь, приложение вконтакте



