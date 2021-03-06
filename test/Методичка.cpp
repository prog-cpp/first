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


struct StringAndCount
{
	string str;
	int count;
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


void printVec(vector <int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;	
}

void print(vector <string> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << i << ". " << vec[i] << endl;
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

bool find(vector < vector <int> > map, int x){
	for (int k = 0; k < map.size(); k++){
		for (int m = 0; m < map.size(); m++){
			if (x == map[k][m]){
				return 1;
			}
		}
	}
	return 0;
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
	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = 0; j < vec[i].size(); )
		{
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

void printVec(const vector <vector<int>> &vec)
{
	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j] < 10)
				cout << " ";
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}	
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

enum ECmd {mov, add, mul, call, ret, end};

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
 
// устанавливает цвет текста и подложки в консоли
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




int main()
{
	setlocale(LC_ALL, "rus");

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
	//file.open("test.txt");

	//while (file.good())
	//{
	//	file >> word;

	//	word = toUpper(word);

	//	int pos = find(words, word);
	//	if (pos >= 0)
	//	{
	//		words[pos].count++;
	//	}
	//	else
	//	{
	//		StringAndCount temp;
	//		temp.str = word;
	//		temp.count = 1;
	//		words.push_back(temp);
	//	}
	//}

	//file.close();

	//sort(words);

	//for (int i = 0; i < words.size(); i++)
	//{
	//	cout << words[i].str << " " << words[i].count << endl;
	//}
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

//double  x = 0;
//
//	for (int i = 0; i<=1000; i++)
//	{
//		//x = (double) rand() / RAND_MAX;
//		x = (double) (rand()%1000) / 1000;
//		cout << x << endl;
//	}

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
// пызырьковая сортировка на разных языках
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
//
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
// количество слов в предложении через флаг
//****************************************************************************************
	//string str1 = " k fg  ";

	//int k = 0;

	//bool wordBegin = 0;

	//for(int i = 0; i < str1.length(); i++)
	//{
	//	if (str1[i] != ' ')
	//	{
	//		if (!wordBegin)
	//			k++;
	//		wordBegin = 1;
	//	}
	//	/*else*/ if (wordBegin && str1[i] == ' ')
	//	{
	//		wordBegin = 0;
	//	}

	//}

	////k++;

	//cout << k;

//****************************************************************************************
// количество слов в предложении через два символа
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
// Самое длинное слово через флаги
//****************************************************************************************
	//string str1 = "    fff khh   fg  ";

	//int k = 0;
	//int max = 0;

	//for(int i = 0; i < str1.length(); i++)
	//{
	//	if (str1[i] != ' ')
	//	{
	//		k++;
	//	}
	//	else
	//	{
	//		k = 0;
	//	}

	//	if (k > max)
	//		max = k;
	//}

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

	//string str = "hkkkkkf";

	//char ch = str[0];
	//int k = 1;
	//bool f = 0;

	//for(int i = 1; i < str.length(); i++)
	//{
	//	if (ch == str[i])
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

	//string pass = "";
	//string symbols = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

	//for(int i = 0; i < 15; i++)
	//{
	//	int p = rand(0,symbols.length()-1);
	//	str = str + (char)symbols[p];
	//}

	//cout << str;

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
// проверка файла на пустоту
// ***************************************************************************

	//fstream file("test.txt");

 //   if (!file.is_open()) 
	//	cout << "Not open\n"; // если не открылся
 //   else if (file.peek() == EOF) 
	//	cout << "Fail empty\n"; // если первый символ конец файла
 //   else  
	//	cout << "Not empty\n"; // если первый символ конец файла

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
	//ifstream file ("c:\\test.txt");

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
//ifstream file ("test.txt");
//float f, s = 0, d = 0;
//if (file.is_open())
//{
//	int n = 0;
//	while ( file.good() )
//	{
//		file >> n;
//		int s = 0;
//		
//		for (int i = 0; i < n && file.good(); i++)
//		{
//			file >> x;
//			s += x;
//		}
//		
//		if (file.good())
//		{
//			cout << s << " ";
//		}
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
// напоминалка органайзер
//****************************************************************************************

	//ifstream file ("r:\\date.txt");

	//SYSTEMTIME st;
	//GetSystemTime(&st);

	//string curr_date = to_string(st.wDay) + ".0" + to_string(st.wMonth) + "." + to_string(st.wYear);

	//string date = "";
	//	string text = "";

	//if (file.is_open())
	//{
	//	while ( file.good() )
	//	{
	//		file >> date;
	//		file >> text;
	//		
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
// Заменить маленькие буквы в файле на большие
//****************************************************************************************

	//char text [256];

	//fstream file("t:\\test.txt",ios::in|ios::out);

	//if (!file) 
	//{	
	//	cerr << "Error in opening file !!!" << endl;
	//}
	//else   
	//{
	//	char ch;
	//	while (file.get(ch)) 
	//	{
	//		text[i] = ch;
	//		i++;  
	//	}

	//	text[i] = '\0'; 
	//	i = 0;

	//	file.clear();      
	//	file.seekp(ios::beg);

	//	for(int i = 0;i < strlen(text); i++)
	//	{
	//		file << (char)toupper(text[i]);
	//	}

	//	file.close();
	//}

//****************************************************************************************
// Запись в лог файл, логфайл, лог-файл, log-
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
	//	file << __DATE__ << " " << __TIME__<< " " << "helow!" << endl;

	//	int ch = 0;

	//	while(ch != 27)
	//	{
	//		ch = _getch();
	//		file << __DATE__ << " " << __TIME__<< " " << "key: " << (char)ch << endl;

	//	}

	//	file.close();
	//}

//****************************************************************************************
// Сравнение строк strcmp. си строки
//****************************************************************************************

	//char c1[] = "asd", c2[] = "asd";
	//if ( strcmp( c1, c2 ) == 0 ) // правильное сравнение
	//	cout << "ravni";

//****************************************************************************************
// struct как класс. Структуры. Структура. Герой
//****************************************************************************************
 
	//SHero hero;

	//hero.hp = 100;
	//hero.level = 1;
	//hero.hp = 100;
	//hero.name = "Alex";

	//show(hero);
	//show(hero);

	//hero.artef[0] = 1;

	//SHero heros[5];

	//heros[0].artef[0] = 1;

	//KIND_HERO kind;

	//kind = WARR;
	//cout << kind;

	//SHero hero(7,8);
	//cout << hero.x;


	//SHero hero1, hero2;

	//hero1.hp = 100;
	//hero1.level = 1;
	//hero1.hp = 100;
	//hero1.name = "Alex";
	//hero1.x = 1;
	//hero1.y = 1;


	//hero2.hp = 100;
	//hero2.level = 1;
	//hero2.hp = 100;
	//hero2.name = "Alex";
	//hero2.x = 1;
	//hero2.y = 1;

//****************************************************************************************
// Студент. Студенты без структур
//****************************************************************************************


	//const int N = 10;

	//string name[N];
	//int stip[N];
	//int vozrast[N];
	//int rost[N];
	//string data_post[N];
	//int ocenki[N][5];
	//

	//Student students[10];

	//name[0] = "Misha";
	//stip[0] = 0;
	//vozrast[0] = 18;
	//rost[0] = 163;
	//data_post[0] = "08.2018";
	//ocenki[0][0] = 4;
	//ocenki[0][1] = 5;
	//ocenki[0][2] = 3;
	//ocenki[0][3] = 4;
	//ocenki[0][4] = 5;

	//name[0] = "Kolia";
	//stip[0] = 800;
	//vozrast[0] = 19;
	//rost[0] = 170;
	//data_post[0] = "09.2017";
	//ocenki[0][0] = 4;
	//ocenki[0][1] = 5;
	//ocenki[0][2] = 3;
	//ocenki[0][3] = 4;
	//ocenki[0][4] = 5;

	//name[0] = "Petia";
	//stip[0] = 0;
	//vozrast[0] = 18;
	//rost[0] = 168;
	//data_post[0] = "07.2015";
	//ocenki[0][0] = 4;
	//ocenki[0][1] = 5;
	//ocenki[0][2] = 3;
	//ocenki[0][3] = 4;
	//ocenki[0][4] = 5;

	//name[0] = "Alex";
	//stip[0] = 0;
	//vozrast[0] = 19;
	//rost[0] = 180;
	//data_post[0] = "08.2014";
	//ocenki[0][0] = 4;
	//ocenki[0][1] = 5;
	//ocenki[0][2] = 3;
	//ocenki[0][3] = 4;
	//ocenki[0][4] = 5;

	//name[0] = "Maxim";
	//stip[0] = 800;
	//vozrast[0] = 20;
	//rost[0] = 175;
	//data_post[0] = "06.2017";
	//ocenki[0][0] = 4;
	//ocenki[0][1] = 5;
	//ocenki[0][2] = 3;
	//ocenki[0][3] = 4;
	//ocenki[0][4] = 5;

	//name[0] = "Olia";
	//stip[0] = 0;
	//vozrast[0] = 16;
	//rost[0] = 161;
	//data_post[0] = "09.2016";
	//ocenki[0][0] = 4;
	//ocenki[0][1] = 5;
	//ocenki[0][2] = 3;
	//ocenki[0][3] = 4;
	//ocenki[0][4] = 5;

	//name[0] = "Vera";
	//stip[0]= 0;
	//vozrast[0] = 18;
	//rost[0] = 173;
	//data_post[0] = "05.2015";
	//ocenki[0][0] = 4;
	//ocenki[0][1] = 5;
	//ocenki[0][2] = 3;
	//ocenki[0][3] = 4;
	//ocenki[0][4] = 5;

	//name[0] = "Igor";
	//stip[0] = 700;
	//vozrast[0] = 18;
	//rost[0] = 177;
	//data_post[0] = "07.2018";
	//ocenki[0][0] = 4;
	//ocenki[0][1] = 5;
	//ocenki[0][2] = 3;
	//ocenki[0][3] = 4;
	//ocenki[0][4] = 5;

	//name[0] = "Ruslan";
	//stip[0] = 0;
	//vozrast[0]= 19;
	//rost[0] = 187;
	//data_post[0] = "02.2017";
	//ocenki[0][0] = 4;
	//ocenki[0][1] = 5;
	//ocenki[0][2] = 3;
	//ocenki[0][3] = 4;
	//ocenki[0][4] = 5;

	//name[0] = "Masha";
	//stip[0] = 0;
	//vozrast[0] = 20;
	//rost[0] = 172;
	//data_post[0] = "10.2016";
	//ocenki[0][0] = 4;
	//ocenki[0][1] = 5;
	//ocenki[0][2] = 3;
	//ocenki[0][3] = 4;
	//ocenki[0][4] = 5;

//****************************************************************************************
// struct как класс. Структуры. Структура. Студент. Студенты
//****************************************************************************************
 
//Student student;
//
//student.name = "Alex";
//student.vozrast = 14;
//student.ocenki[0] = 4;
//
//Student students[10];
//
//students[0].name = "Misha";
//students[0].stip = 0;
//students[0].vozrast = 18;
//students[0].rost = 163;
//students[0].data_post = "08.2018";
//students[0].ocenki[0] = 4;
//students[0].ocenki[1] = 5;
//students[0].ocenki[2] = 3;
//students[0].ocenki[3] = 4;
//students[0].ocenki[4] = 5;
//
//students[1].name = "Kolia";
//students[1].stip = 800;
//students[1].vozrast = 19;
//students[1].rost = 170;
//students[1].data_post = "09.2017";
//students[1].ocenki[0] = 4;
//students[1].ocenki[1] = 4;
//students[1].ocenki[2] = 4;
//students[1].ocenki[3] = 4;
//students[1].ocenki[4] = 5;
//
//students[2].name = "Petia";
//students[2].stip = 0;
//students[2].vozrast = 18;
//students[2].rost = 168;
//students[2].data_post = "07.2015";
//students[2].ocenki[0] = 3;
//students[2].ocenki[1] = 5;
//students[2].ocenki[2] = 4;
//students[2].ocenki[3] = 4;
//students[2].ocenki[4] = 5;
//
//students[3].name = "Alex";
//students[3].stip = 0;
//students[3].vozrast = 19;
//students[3].rost = 180;
//students[3].data_post = "08.2014";
//students[3].ocenki[0] = 5;
//students[3].ocenki[1] = 3;
//students[3].ocenki[2] = 3;
//students[3].ocenki[3] = 4;
//students[3].ocenki[4] = 3;
//
//students[4].name = "Maxim";
//students[4].stip = 800;
//students[4].vozrast = 20;
//students[4].rost = 175;
//students[4].data_post = "06.2017";
//students[4].ocenki[0] = 4;
//students[4].ocenki[1] = 5;
//students[4].ocenki[2] = 5;
//students[4].ocenki[3] = 4;
//students[4].ocenki[4] = 4;
//
//students[5].name = "Olia";
//students[5].stip = 0;
//students[5].vozrast = 16;
//students[5].rost = 161;
//students[5].data_post = "09.2016";
//students[5].ocenki[0] = 3;
//students[5].ocenki[1] = 3;
//students[5].ocenki[2] = 4;
//students[5].ocenki[3] = 4;
//students[5].ocenki[4] = 5;
//
//students[6].name = "Vera";
//students[6].stip = 0;
//students[6].vozrast = 18;
//students[6].rost = 173;
//students[6].data_post = "05.2015";
//students[6].ocenki[0] = 4;
//students[6].ocenki[1] = 5;
//students[6].ocenki[2] = 5;
//students[6].ocenki[3] = 3;
//students[6].ocenki[4] = 3;
//
//students[7].name = "Igor";
//students[7].stip = 700;
//students[7].vozrast = 18;
//students[7].rost = 177;
//students[7].data_post = "07.2018";
//students[7].ocenki[0] = 4;
//students[7].ocenki[1] = 5;
//students[7].ocenki[2] = 4;
//students[7].ocenki[3] = 4;
//students[7].ocenki[4] = 4;
//
//students[8].name = "Ruslan";
//students[8].stip = 0;
//students[8].vozrast = 19;
//students[8].rost = 187;
//students[8].data_post = "02.2017";
//students[8].ocenki[0] = 5;
//students[8].ocenki[1] = 3;
//students[8].ocenki[2] = 5;
//students[8].ocenki[3] = 4;
//students[8].ocenki[4] = 5;
//
//students[9].name = "Masha";
//students[9].stip = 0;
//students[9].vozrast = 20;
//students[9].rost = 172;
//students[9].data_post = "10.2016";
//students[9].ocenki[0] = 5;
//students[9].ocenki[1] = 5;
//students[9].ocenki[2] = 4;
//students[9].ocenki[3] = 4;
//students[9].ocenki[4] = 3;

//****************************************************************************************
// сортировка студентов по росту
//****************************************************************************************

	//Student tmp;

	//for(int i = 0; i < 10-1; i++) // внутренний цикл прохода
	//{
	//	bool f = 0;
	//	for(int j = 0; j < 10-1; j++) // внутренний цикл прохода
	//	{
	//		if (students[j].rost > students[j+1].rost)
	//		{
	//			tmp = students[j];
	//			students[j] = students[j+1];
	//			students[j+1] = tmp;
	//			f = 1;
	//		}
	//	}
	//}

	//cout << endl;
	//cout << " " << left << setw(7) << "Name" 
	//					<< setw(9) << "Date" 
	//					<< setw(4) << "Age"
	//					<< setw(6) << "Rost"
	//					<< setw(5) << "Stip"
	//					<< setw(5) << "Ball";
	//cout << endl << " " << "----------------------------------------" << endl;

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << " " << left << setw(7) << students[i].name 
	//						<< setw(9) << students[i].data_post 
	//						<< setw(4) << students[i].vozrast
	//						<< setw(6) << students[i].rost
	//						<< setw(5) << students[i].stip;

	//	for (int j = 0; j < 5; j++)
	//	{
	//		cout << left << setw(2) << students[i].ocenki[j]; 

	//	}	
	//	cout << endl;
	//}	

//****************************************************************************************
// запись информации о студентах в файл
//****************************************************************************************

//ofstream file ("f:\\test.txt");
//
//if (!file.is_open())
//{
//	cout<<"Unable to open fout.\n";
//	system("pause");
//	return 0;
//}
//else 
//{
//	file << " " << left << setw(7) << "Name" 
//						<< setw(9) << "Date" 
//						<< setw(4) << "Age"
//						<< setw(6) << "Rost"
//						<< setw(5) << "Stip"
//						<< setw(5) << "Ball";
//	file << endl << " " << "----------------------------------------" << endl;
//	for (int i = 0; i < 10; i++)
//	{
//		file << " " << left << setw(7) << students[i].name 
//							<< setw(9) << students[i].data_post 
//							<< setw(4) << students[i].vozrast
//							<< setw(6) << students[i].rost
//							<< setw(5) << students[i].stip;
//
//		for (int j = 0; j < 5; j++)
//		{
//			file << left << setw(2) << students[i].ocenki[j]; 
//
//		}	
//
//		file << endl;
//	}	
//
//	file.close();
//}



//
//// вывод на экран данных из полей структуры
//cout << stud.name << endl;
//cout << stud.data_rozd << endl;

	//show(hero);
	//show(hero);

	//hero.artef[0] = 1;

	//SHero heros[5];

	//heros[0].artef[0] = 1;

	//KIND_HERO kind;

	//kind = WARR;
	//cout << kind;

	//SHero hero(7,8);
	//cout << hero.x;


	//SHero hero1, hero2;

	//hero1.hp = 100;
	//hero1.level = 1;
	//hero1.hp = 100;
	//hero1.name = "Alex";
	//hero1.x = 1;
	//hero1.y = 1;


	//hero2.hp = 100;
	//hero2.level = 1;
	//hero2.hp = 100;
	//hero2.name = "Alex";
	//hero2.x = 1;
	//hero2.y = 1;







//****************************************************************************************
// шаблон класс, template 
//****************************************************************************************

//CList <string> list;
//list.show("dgjkdljg");

//****************************************************************************************
// определение размера массива через sizeof
//****************************************************************************************
    //int a[] = { 1, 2, 3 };
    //cout << sizeof a << endl;
    //cout << sizeof *a << endl;
    //cout << sizeof a / sizeof *a << endl;
//****************************************************************************************
// герой движеться по команде вверх вниз влево вправо
//****************************************************************************************
	//int x=49, y=12, c = 1;
	//int x1=51, y1=12;
	//int x2=40, y2=12;
	//int x3=49, y3=8;
	//int x4=49, y4=16;
	//int hx=48, hy=17;
	//int dx=38, dy=17;
	//int bx=20, by=10;
	//int hp = 50;
	//int ti = 0;

	//while (c != 0)
	//{
	//	while (!kbhit())
	//	{
	//		gotoxy(0,0);
	//		cout << ti;
	//		ti = (ti + 1) % 5;
	//		Sleep(100);
	//	}

	//	c = getch();

	//	int lx = x, ly = y;

	//	gotoxy(x,y);
	//	cout << " ";

	//	if (c == 75)
	//	{
	//		x--;
	//	}
	//	if (c == 77)
	//	{
	//		x++;
	//	}
	//	if (c == 80)
	//	{
	//		y++;
	//	}
	//	if (c == 72)
	//	{
	//		y--;
	//	}

	//	if((x == x1) && (y == y1)
 //        ||(x == x2) && (y == y2)
	//     ||(x == x3) && (y == y3)
	//     ||(x == x4) && (y == y4))
	//	{
	//		x = lx, y = ly;
	//	}

	//	if((x == hx) && (y == hy))
	//	{
	//		hp = hp + 5;
	//		hx = 78;
	//		hy = 24;
	//	}

	//	if((x == dx) && (y == dy))
	//	{
	//		hp = hp - 5;
	//		dx = 78;
	//		dy = 24;
	//	}

	//	int lbx = bx, lby = by;

	//	if((x == bx) && (y == by))
	//	{
	//		if (x > lx)
	//		{
	//			bx++; 
	//		} 
	//		else if (x < lx)
	//		{
	//			bx--; 
	//		}
	//		else if (y > ly)
	//		{
	//			by++; 
	//		} 
	//		else if (y < ly)
	//		{
	//			by--; 
	//		}
	//	}

	//	if((bx == x1) && (by == y1)
 //        ||(bx == x2) && (by == y2)
	//     ||(bx == x3) && (by == y3)
	//     ||(bx == x4) && (by == y4))
	//	{
	//		x = lx, y = ly;
	//		bx = lbx, by = lby;
	//	}

	//	gotoxy(x,y);
	//	cout << "*";

	//	gotoxy(x1,y1);
	//	cout << "|";

	//	gotoxy(x2,y2);
	//	cout << "|";

	//	gotoxy(x3,y3);
	//	cout << "-";

	//	gotoxy(x4,y4);
	//	cout << "-";

	//	gotoxy(hx,hy);
	//	cout << (char)3;

	//	gotoxy(dx,dy);
	//	cout << (char)6;

	//	gotoxy(bx,by);
	//	cout << (char)5;

	//	gotoxy(0,24);
	//	cout << "hp=" << hp;

	//	gotoxy(78,24);
	//	cout << ' ';
	//	
	//}

//****************************************************************************************
// однорукий бандит
//****************************************************************************************

	//int x;
	//int d1;
	//int d2;
	//int d3;
	//int cmd = 2;
	//int s = 100;
	//

	//while (cmd != 0)
	//{

	//	cout << "Введите ставку = " << endl;
	//	cin >> cmd;
	//	Sleep(100);

	//	//if (cmd == 1)
	//	{

	//		x = 100 + rand()%1000;


	//		d1 = x % 10;
	//		cout << d1 << endl;
	//		Sleep(100);

	//		d2 = x / 100;
	//		cout << d1 << endl;
	//		Sleep(100);

	//		d3 = (x / 10) % 10;
	//		cout << d1 << endl;
	//		Sleep(100);

	//		if (d1 == 7 && d2 == 7 && d3 == 7)
	//		{
	//			s = s + 100;
	//			cout << "+100" << endl;
	//		}
	//		else if (d1 == 7 && d2 == 7 && d3 != 7)
	//		{
	//			s = s + 25;
	//			cout << "+25" << endl;
	//		} 
	//		else if (d1 == 7 && d2 != 7 && d3 == 7)
	//		{
	//			s = s + 25;
	//			cout << "+25" << endl;
	//		} 
	//		else if (d1 != 7 && d2 == 7 && d3 == 7)
	//		{
	//			s = s + 25;
	//			cout << "+25" << endl;
	//		} 
	//		else if (d1 == 7 && d2 != 7 && d3 != 7)
	//		{
	//			s = s + 5;
	//			cout << "+5" << endl;
	//		} 
	//		else if (d1 != 7 && d2 == 7 && d3 != 7)
	//		{
	//			s = s + 5;
	//			cout << "+5" << endl;
	//		} 
	//		else if (d1 != 7 && d2 != 7 && d3 == 7)
	//		{
	//			s = s + 5;
	//			cout << "+5" << endl;
	//		} 
	//		else 
	//		{
	//			s--;
	//			cout << "-1" << endl;
	//		}
	//		cout << s << endl;
	//	}
	//	
	//}

//****************************************************************************************
// клавиатурный тренажер
//****************************************************************************************

	//setlocale(LC_ALL, "rus");

	//string str = "privet";

	//char ch1 = 0;
	//int ch2 = 0;

	//int x = 0;

	//cout << str;

	//gotoxy(x,0);

	//while(ch2 != 27)
	//{
	//	ch1 = str[x];

	//	ch2 = getch();

	//	if ((char)ch1 == (char)ch2)
	//	{
	//		x++;
	//		gotoxy(x,0);
	//	}

	//	if (x == str.length())
	//	{
	//		break;	
	//	}

	//}

	//cout << "jgdhgkjdhg" << endl;

//****************************************************************************************
// герой движеться по траектории
//****************************************************************************************
	//int x=49, y=12;
	//
	//for (int i=0; i<10; i++)
	//{
	//	gotoxy(x,y);
	//	cout << " ";

	//	x++;

	//	gotoxy(x,y);
	//	cout << '*';

	//	Sleep(500);

	//}


//****************************************************************************************
// герой движеться по траектории
//****************************************************************************************
	//int x=49, y=12;
	//
	//for (int i=0; i<10; i++)
	//{
	//	gotoxy(x,y);
	//	cout << " ";

	//	x++;

	//	gotoxy(x,y);
	//	cout << '*';

	//	Sleep(500);

	//}

//****************************************************************************************
// печать из конслоли, открытие или запуск исполняемого файла из консоли
//****************************************************************************************

	//ShellExecuteA(NULL, "print", "r:\\test1.txt", NULL, NULL, SW_HIDE);
	//ShellExecuteA(NULL, "open", "r:\\test1.txt", NULL, NULL, SW_SHOWNORMAL);
	//ShellExecuteA(NULL, "open", "r:\\", NULL, NULL, SW_SHOWNORMAL);
	//ShellExecute(handle,'explore',путь_для_папки,nil,nil,SW_SHOWNORMAL);
	//ShellExecuteA(NULL, NULL, "http://vk.com/prog21", NULL, NULL, SW_RESTORE); //запуск нашей странички
	//ShellExecuteA(NULL, nil, PChar (Application.ExeName), nil, nil, SW_RESTORE); //запуск второй копии этой программы
	//ShellExecuteA(NULL, nil, 'iexplore', 'http://programming.dax.ru', nil, SW_RESTORE); //запуск в отдельном окне
	//ShellExecuteA(NULL, nil, 'mailto:semen@krovatka.net?subject=delphi', nil, nil, SW_RESTORE); //написать мне письмо
	//ShellExecuteA(NULL, nil, 'c:\1.doc', nil, nil, SW_RESTORE); //открыть документ

//****************************************************************************************
// поиск файлов, вывод на экран, в файл списка файлов и папок заданного каталога
//****************************************************************************************

 //   TCHAR Buffer[256];
 //   WIN32_FIND_DATA FindFileData;
 //   HANDLE hFile1, hFile2;
 //   TCHAR stdPath1[256] = TEXT("C:\\TEMP\\Extension_File.txt");
 //   TCHAR stdPath2[256] = TEXT("C:\\TEMP\\*.*");
 //
 //
 //   hFile1 = CreateFile(stdPath1, GENERIC_WRITE, 0, NULL,
 //       CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
 //
 //   if (hFile1 == INVALID_HANDLE_VALUE) {
 //       printf("ERROR %x \n", GetLastError());
 //
 //       return 2;
 //   }
 //
 //   hFile2 = FindFirstFile(stdPath2, &FindFileData);

	//while (FindNextFile(hFile2, &FindFileData) != 0)
 //   {
 //       wcout << FindFileData.cFileName << endl;
 //       DWORD dwBytesWrite;
 //       if (!WriteFile(hFile1, &FindFileData.cFileName, sizeof(TCHAR)* lstrlen(FindFileData.cFileName), &dwBytesWrite, (LPOVERLAPPED)NULL))
 //       {
 //           cerr << "Write file failed.." << endl
 //               << "The last error code: " << GetLastError() << endl;
 //           cout << "Press any key to finish.";
 //           cin.get();
 //           return 0;
 //       }
 //   }

	//CloseHandle(hFile1);
	//FindClose(hFile2);
//****************************************************************************************
// вызов рекурсивной функции
//****************************************************************************************
	//cout << digit_sum("1hd11h1");
//****************************************************************************************
// замер времени выполнения программы, время работы программы
//****************************************************************************************
	//unsigned int start_time =  clock(); // начальное время
	//
	//while (1)
	//{
	//	start_time =  clock();
	//	cout << start_time << " ";
	//	Sleep(200);
	//}

//****************************************************************************************
// кто быстрее вектор или список вектор vs список vs вектор 	Вектор или список
//****************************************************************************************

	//int n = 10000;
 //   
	//vector <int> vec;
	//vec.push_back(3);

 //   vector <int>::iterator it = vec.begin(); 

	//unsigned int start_time =  clock(); // начальное время

	//for (int i = 0; i < n; i++)
	//{
	//	vec.insert(it, i);
	//	it = vec.begin();
	//}

	//cout << clock() - start_time << endl;

 //   list <int> lst;
	//lst.push_back(3);

 //   list <int>::iterator it2 = lst.begin(); 

	//start_time =  clock(); // начальное время

	//for (int i = 0; i < n; i++)
	//{
	//	lst.insert(it2, i);
	//	it2 = lst.begin();
	//}

	//cout << clock() - start_time << endl;


//****************************************************************************************
// кто быстрее ссылка по значению или константная ссылка
//****************************************************************************************

	//int n = 100000000;
 //   
	//vector <int> vec;

	//for (int i = 0; i < n; i++)
	//{
	//	vec.push_back(rand()%3);
	//}

	//unsigned int start_time =  clock(); // начальное время
	//cout << sumVector(vec) << endl;
	//cout << clock() - start_time << endl;

	//start_time =  clock(); // начальное время
	//cout << sumVector2(vec) << endl;
	//cout << clock() - start_time << endl;


//****************************************************************************************
// кто быстрее вектор или множество set vs vector
//****************************************************************************************

	//int n = 10000;
 //   
	//string str = "_qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

	//set <char> st;

	

	//for (int i = 0; i < str.length(); i++)
	//{
	//	st.insert(str[i]);
	//}

	//int len = str.length();

	//char x = 0;

	//int d = 0;

	//unsigned int start_time = clock(); // начальное время

	//for (int i = 0; i < n; i++)
	//{
	//	x = rand()%200;

	//	for (int j = 0; j < str.length(); j++)
	//	{
	//		if (x == str[j])
	//		{
	//			d++;
	//			break;
	//		}
	//	}
	//}

	//cout << "d = " << d << " time = " << clock() - start_time << endl;

	//d = 0;

	//start_time =  clock(); // начальное время
	//set <char> :: iterator found;

	//for (int i = 0; i < n; i++)
	//{
	//	x = rand()%200;

	//	found = st.find(x);

	//	if (found != st.end())
	//	{
	//		d++;
	//	}
	//}

	//cout << "d = " << d << " time = " << clock() - start_time << endl;


//****************************************************************************************
// кто быстрее x*x или sqr
//****************************************************************************************

	//int n = 10000000;
 //   
	//long long int s = 0;

	//unsigned int start_time =  0; // начальное время

	//			s = 0;
	//			start_time =  clock(); // начальное время

	//			for (long long int i = 0; i < n; i++)
	//			{
	//				s = s + i*i;
	//			}

	//			cout << s << endl;
	//			cout << clock() - start_time << endl;


	//s = 0;
	//start_time =  clock();

	//for (long long int i = 0; i < n; i++)
	//{
	//	s = s + sqr(i);
	//}

	//cout << s << endl;
	//cout << clock() - start_time << endl;

//****************************************************************************************
// функции работы со временем
//****************************************************************************************

	//time_t seconds = time(NULL);
 //   tm * nowTime = localtime(&seconds);

	//cout << "Текущее время: " << asctime(nowTime) << endl;
	//cout << "Текущее время: " << tm->tm_hour << endl;

//****************************************************************************************
// попадение точки в заданную область треугольник
// процедурная генерация
// уравнение прямой через две точки
//****************************************************************************************

	//float x,y;

	//while (1)
	//{
	//	x = rand()%120;
	//	y = rand()%30;
	//	if ((x - 119)/(0-119) >= (y - 0)/(29-0))
	//	{
	//		gotoxy(x,y);
	//		cout << "*";
	//	}
	//}

//****************************************************************************************
// попадение точки в заданную область треугольник
// процедурная генерация
// окружность круг 
//****************************************************************************************

	//float x,y;


	//while (1)
	//{
	//	x = rand()%120;
	//	y = rand()%30;
	//	if ((x-60)*(x-60) + (y-15)*(y-15) < 200)
	//	{
	//		gotoxy(x,y);
	//		cout << "*";
	//	}
	//}

//****************************************************************************************
// случайные числа в случайной позиции
//****************************************************************************************

	//float x,y;

	//for (int i = 0; i < 200; i++)
	//{
	//	x = rand()%80;
	//	y = rand()%25;
	//	gotoxy(x,y);
	//	cout << rand(0,9);
	//}

//****************************************************************************************
// попадение точки в заданную область окружности окружность
//****************************************************************************************

	//float x,y;
	//for (int i = 0; i < 1000; i++)
	//{
	//	x = rand()%13-6;
	//	y = rand()%13-6;

	//	if (x*x + y*y <= 37)
	//	{
	//		gotoxy(x+40,y+13);
	//		cout << "*";
	//	}
	//}

//****************************************************************************************
// В одном ряду, в одном столбце
//****************************************************************************************

	//int x0 = 5, y0 = 5;

	//for (int i = 0; i < 10000; i++)
	//{
	//	x = rand()%120;
	//	y = rand()%30;

	//	if (x == x0 || y == y0)
	//	{
	//		gotoxy(x, y);
	//		cout << "*";
	//	}
	//}

//****************************************************************************************
// На одной диагонали
//****************************************************************************************

	//int x0 = 5, y0 = 5;

	//for (int i = 0; i < 10000; i++)
	//{
	//	x = rand()%120;
	//	y = rand()%30;

	//	if (abs(x0-x) == abs(y0 - y))
	//	{
	//		gotoxy(x, y);
	//		cout << "*";
	//	}
	//}

//****************************************************************************************
// В одном ряду, в одном столбце, на одной диагонали
//****************************************************************************************

	//int x0 = 5, y0 = 5;

	//for (int i = 0; i < 10000; i++)
	//{
	//	x = rand()%120;
	//	y = rand()%30;

	//	if (abs(x0-x) == abs(y0 - y) || x == x0 || y == y0)
	//	{
	//		gotoxy(x, y);
	//		cout << "*";
	//	}
	//}

//****************************************************************************************
// занятия с Никитой
//****************************************************************************************
	//int N;

	//cin >> N;

 //   int **E = new int *[N];
 //
 //   for (int i = 0; i < N; i++)
 //       E[i] = new int [N];
 //
 //   for (int i = 0; i < N; i++)
 //       for (int j = 0; j < N; j++)
 //       {
 //           E[i][j] = rand() % 10;
 //
 //           //if (i == j)
 //           //    E[i][j] = 1.0;
 //       }

 //   for (int i = 0; i < N; i++)
	//{
 //       for (int j = 0; j < N; j++)
 //       {
 //           cout << E[i][j] << " ";
 //
 //       }
 //           cout << endl;


//}

	//int * a;
	//int n;

	//a = form(n);

	//print(a,n);





//
//int a[15]={9,2,3,4,-2,-1,4,5,5,98,9,5,6,7,2},i,j,min=99999999,k;
//for (i=0;i<15;i++)
//cin>>a[i];
//for (j=0;j<15;j++)
//cout << j <<"="<<a[j]<<endl;
// for (j=0;j<15;j++)
// {  
//	if (min>abs(a[j]))
//	{
//    min=a[j] ;k=j;
//	}
// }
//
//cout<<"min="<<min<<endl;
//a[k]=0;
//for (j=0;j<15;j++)
//cout << j <<"="<<a[j]<<endl;
//
//int a[15]={9,2,3,4,-2,-1,4,5,5,98,9,5,6,7,2},ki,kj,i,j;
//cout<<"Введите ki"<<"Введите kj"<<endl;
//cin>>ki>>kj;
//j=ki;
//for(j=ki;j<=kj;j++)
//{
//	a[j]=a[j]*-1;
//}
//for (i=0;i<15;i++)
//cout<<a[i]<<endl;
//
//srand(time(NULL));
//
////int a[15],i,n;
//int a[15]={-9,2,3,4,2,1,4,5,5,98,9,5,6,7,2},n;
////n=15;
////for(i=0;i<15;i++)
////a[i]=rand()%19-9;
////a[14]=0;a[13]=-1;a[0]=
////for(i=0;i<15;i++)
////cout<<a[i]<<endl;
//for (n=14;n>=0;n--)
//{ 
//	if (a[n]*a[n-1]<0)
//	{
//		cout<<n<<"    "<<n-1<<endl;
//		break;
//	}
//	
//}

//const int n = 4;
//
////int a[n][n] = {{9,2,3},
////			   {4,2,1},
////               {4,5,5}};
//
//int a[n][n] = {{9,2,3,1},
//			   {4,2,1,5},
//               {4,5,5,8},
//               {6,2,7,0}};
//
//int i,j,k;
////for(i=0;i<n;i++){
//	for(j=0;j<n;j++)
//		cout<<a[i][j];
//	cout<<endl;
//}
//j=0;
//for(i=0;i<n;i++)
//	{
//		k=a[i][j];
//	    a[i][j]=a[i][n-1-j];
//		a[i][n-1-j]=k;
//		j++;
//		
//		}
//	
//
//for(i=0;i<n;i++){
//	for(j=0;j<n;j++)
//		cout<<a[i][j];
//	cout<<endl;
//}


//int * a;
//int * b;
//
//int w = 5;
//
//a = new int [w];
//
//delete [] a;

//****************************************************************************************
// крестики нолики
//****************************************************************************************

	//int N = 3;

	//int **E = new int * [N];

	//for (int i = 0; i < N; i++)
	//	E[i] = new int [N];

	//for (int i = 0; i < N; i++)
	//	for (int j = 0; j < N; j++)
	//	{
	//		E[i][j] = ;
	//	}	

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << E[i][j] << " ";
	//	}	
	//	cout << endl;
	//}

	//for (int i = 0; i < N; i++)
	//	delete [] E[i];

	//delete [] E;

//****************************************************************************************
// Три кости игра с компьютером
//****************************************************************************************
 
	//system("color F0");
	//srand(time(NULL));

	//int r;
	//int x1;
	//int x2;
	//int d1;
	//int d2;
	//int d3;
	//int cmd = 2;
	//int s1 = 0;
	//int s2 = 0;

	//cout << "Бросайте кубик. 1 - бросить, 0 - выйти " << endl;
	//cin >> cmd;
	//if (cmd != 0 )
	//{
	//	x1 = rnd(1,6);
	//	x2 = rnd(1,6);
	//}
	//else
	//	return 0;

	//cout << "Подождите ...";
	//Sleep(1000);
	//cout << "Выпало " << x1 << " - это будет ваше число" << endl;
	//cout << "Подождите ...";
	//Sleep(1000);
	//cout << "Это у кмопа " << x2 << " - это число компа" << endl;


	//while (cmd != 0)
	//{
	//	cout << "Бросайте три кубика (1 - бросить) -> ";
	//	cin >> cmd;

	//	if (cmd == 1)
	//	{
	//		cout << "Подождите ...";
	//		Sleep(1000);

	//		d1 = rnd(1,6);
	//		d2 = rnd(1,6);
	//		d3 = rnd(1,6);

	//		cout << "Выпало = " << endl;
	//		cout << d1 << " " << d2 << " " << d3 << endl;


	//		set_color(15,2);
	//		if (d1 == x1 && d2 == x1 && d3 == x1)
	//		{
	//			s1 = s1 + 1;
	//			cout << "+5" << endl;
	//		}
	//		else if (d1 == x1 && d2 == x1 && d3 != x1)
	//		{
	//			s1 = s1 + 2;
	//			cout << "+2" << endl;
	//		} 
	//		else if (d1 == x1 && d2 != x1 && d3 == x1)
	//		{
	//			s1 = s1 + 2;
	//			cout << "+2" << endl;
	//		} 
	//		else if (d1 != x1 && d2 == x1 && d3 == x1)
	//		{
	//			s1 = s1 + 2;
	//			cout << "+2" << endl;
	//		} 
	//		else if (d1 == x1 && d2 != x1 && d3 != x1)
	//		{
	//			s1 = s1 + 1;
	//			cout << "+1" << endl;
	//		} 
	//		else if (d1 != x1 && d2 == x1 && d3 != x1)
	//		{
	//			s1 = s1 + 1;
	//			cout << "+1" << endl;
	//		} 
	//		else if (d1 != x1 && d2 != x1 && d3 == x1)
	//		{
	//			s1 = s1 + 1;
	//			cout << "+1" << endl;
	//		} 
	//		set_color(15,0);

	//		cout << s1 << endl;
	//	}

	//	if (cmd == 1)
	//	{
	//		cout << "Теперь бросет комп. Подождите ...";
	//		Sleep(1000);

	//		d1 = rnd(1,6);
	//		d2 = rnd(1,6);
	//		d3 = rnd(1,6);

	//		cout << "Выпало = " << endl;
	//		cout << d1 << " " << d2 << " " << d3 << endl;

	//		if (d1 == x2 && d2 == x2 && d3 == x2)
	//		{
	//			s2 = s2 + 1;
	//			cout << "+5" << endl;
	//		}
	//		else if (d1 == x2 && d2 == x2 && d3 != x2)
	//		{
	//			s2 = s2 + 2;
	//			cout << "+2" << endl;
	//		} 
	//		else if (d1 == x2 && d2 != x2 && d3 == x2)
	//		{
	//			s2 = s2 + 2;
	//			cout << "+2" << endl;
	//		} 
	//		else if (d1 != x2 && d2 == x2 && d3 == x2)
	//		{
	//			s2 = s2 + 2;
	//			cout << "+2" << endl;
	//		} 
	//		else if (d1 == x2 && d2 != x2 && d3 != x2)
	//		{
	//			s2 = s2 + 1;
	//			cout << "+1" << endl;
	//		} 
	//		else if (d1 != x2 && d2 == x2 && d3 != x2)
	//		{
	//			s2 = s2 + 1;
	//			cout << "+1" << endl;
	//		} 
	//		else if (d1 != x2 && d2 != x2 && d3 == x2)
	//		{
	//			s2 = s2 + 1;
	//			cout << "+1" << endl;
	//		} 
	//		cout << s2 << endl;
	//	}
	//}

//****************************************************************************************
// Игра лабиринт
//****************************************************************************************

//****************************************************************************************
// Игра морской бой
//****************************************************************************************

	//int N = 5;
	////int X = 7;
	//int x=0,y=0;

	//int **E = new int * [N+2];

	//for (int i = 0; i < N+2; i++)
	//	E[i] = new int [N+2];

	//for (int i = 0; i < N+2; i++)
	//{
	//	for (int j = 0; j < N+2; j++)
	//	{
	//		if (i == 0 || i == N+1 || j == 0 || j == N+1)
	//			E[i][j] = 2;
	//		else
	//			E[i][j] = 0;
	//		cout << E[i][j];
	//	}	
	//	cout << endl;
	//}

	//srand(time(NULL));



	////for (int i = 0; i<3; i++)
	////{
	////	int x = rnd(0,N);
	////	int y = rnd(0,N);

	////	E[x][y] = 1;
	////}

	//E[rnd(1,N)][rnd(1,N)] = 1;
	////случайная расстановка 3-х палубного корабля горизонтально
	//int i = 1;
	//bool mozno = 1;
	//do	
	//{
	//	int x = rnd(1,N);
	//	int y = rnd(1,N);

	//	mozno = 1;

	//	if (E[x][y] != 1)
	//	{

	//		int x2 = x;
	//		int y2 = y;

	//		// пока x не вышло за пределы экрана или не попадаем на занятую
	//		// и не соприкасается с другими кораблями
	//		// проверяем можем ли разместить три палубы
	//		for (int i = 0; i<3; i++)
	//		{
	//			if (x2 > N 
	//				|| E[x2]   [y2]   == 1
	//				|| E[x2]   [y2+1] == 1
	//				|| E[x2]   [y2-1] == 1
	//				|| E[x2+1] [y2]   == 1
	//				|| E[x2+1] [y2-1] == 1
	//				|| E[x2+1] [y2+1] == 1
	//				|| E[x2-1] [y2]   == 1
	//				|| E[x2-1] [y2+1] == 1
	//				|| E[x2-1] [y2-1] == 1
	//				)
	//			{
	//				mozno = 0;
	//				//break;
	//			}
	//			x2++;
	//		}

	//		// если оказалось что можно размещаем
	//		if (mozno == 1)
	//		{
	//			for (int i = 0; i<3; i++)
	//			{
	//				E[x][y] = 1;
	//				x++;
	//			}
	//		}
	//	}
	//}while (mozno != 1);


	//for (int i = 0; i < N+2; i++)
	//{
	//	for (int j = 0; j < N+2; j++)
	//	{
	//		if (E[j][i] == 0)
	//			cout << ' ';
	//		else
	//			cout << E[j][i];
	//	}	
	//	cout << endl;
	//}

	//getch();


	//while (x != 7)
	//{
	//	cout << "Введите координаты противника -> ";
	//	cin >> x >> y;

	//	cout << "Выстрел произведен. Подождите ...";
	//	//Sleep(3000);


	//	if (E[x][y] == 1)
	//	{
	//		cout << "Попадание" << endl;
	//	} 
	//	else 
	//	{
	//		cout << "В молоко" << endl;
	//	}

	//	if (x == 7)
	//	{
	//		break;
	//	}
	//}
	//for (int i = 0; i < N; i++)
	//	delete [] E[i];

	//delete [] E;


// ***************************************************************************
// работа с указателями, адреса
// ***************************************************************************
	


	//int x = 5;
	//cout << &x;


	//int *p;

	//p = &x;

	//p = 2;

	//cout << *p;



	//int *a;
	//a = new int;

	//*a = 5;

	//cout << *a;

	//delete a;

	////	= new int; // Объявление указателя для переменной типа int
	//int *b = new int(5); // Инициализация указателя
	//int *c = new int(5); // Инициализация указателя



//
//	int x = 5;
//
//	*a = 10;
//
//	a = &x;
//
//cout << *a;
//	*b = *a + *b;
//
//	cout << "b is " << *b << endl;
//	cout << "адрес а = " << &a << endl;
//	cout << "адрес b = " << &b << endl;
//	cout << "адрес c = " << &c << endl;
//
//	delete c;
//	delete b;
//	delete a;

//****************************************************************************************
// Указатели 1 Работа с указателями
//****************************************************************************************


    //int array[500000]; // выделяем 1 миллион целочисленных значений

	//int *x; 
	//int *y; 

	//x = new int;
	//y = new int;

	//*x = 5;

	//y = x;

	////cout << x << " " << *x;
	//cout << x;
	//cout << endl;
	//cout << *y;

	//delete x;

//int x = 5;
//int *p;
//p = &x;
//x = 10;
//cout << *p;
//(*p)++;
//cout << *p;


//****************************************************************************************
// Указатели 2 Работа с указателями
//****************************************************************************************
	//int a; //Разные переменные
	//int *ptr; //ptr есть указатель на int

	////Вариант а. Изменение значения переменной для указателя
	//ptr = &a; //Указатель ptr = адрес переменной a
	//a = 100; //присвоили любое значение в переменную на адрес которой указатель указывает
	//cout << "a = " << *ptr << endl; //т.к. указатель опирается на адрес переменной a, любое изменение a влияет на то, что отображает разыменованный указатель. *ptr=a=100

	//a=999; //поменяли значение переменной
	//cout << "a = " << *ptr << endl; //указатель опирается на адрес переменной a. *ptr=a=999

	///*  Только что была продемонстрирована одна из сторон указателей. Тут менялось значение переменной */
	//
	////Вариант б. Изменение разыменованного указателя влияет на переменную по адресу указателя
	//a = 100; //чтоб было понятнее. изменим a на новое значение
	//int c = 55;   //вторая переменная
	//ptr = &a; //Указатель = адрес переменной a => *ptr=a=100;
	//*ptr = 999; //По адресу переменной а записалось новое значение. a=*ptr=999;
	//ptr = &c; //Указатель теперь указывает на адрес с. Влияние указателя на а прекращено
	//*ptr = 88; //с изменилось было 55 - стало 88
	//cout << "a = " << a << endl; //a=100 a=999
	//cout << "c = " << c << endl; //c=55  c=88

//****************************************************************************************
// Указатели 3 Работа с указателями
//****************************************************************************************

	//int mas[5] = {4,7,3,5,3};

	//cout << mas;
	//cout << *mas;
	//cout << *(mas + 1);
	//cout << *mas + 1;
	//mas++; ошибка

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << *(mas+i) << endl;
	//}

	//int *p;
	//p = mas;
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << *p << " ";
	//	p++;
	//}

//int **p;
//
//p = new int*;
//
//*p = new int;
//
//**p = 5;
//
//cout << **p;
//
//delete *p;
//
//delete p;

//int mas[2][3] = {
//					{1,7,3},
//					{5,3,6}
//				};
//
//cout << mas << endl;
//
//int *p;
//
//p = *mas;
//
//cout << *((*mas)+1) << endl;
//cout << *(p + 1) << endl;
//cout << *(mas+1) << endl;
//cout << **(mas + 1) << endl;

//for (int i = 0; i < 2; i++)
//{
//	cout << *(mas+i) << endl;
//
//	//p = *(mas+i);
//
//	//for (int j = 0; j < 3; j++)
//	//{
//	//	cout << *(*(mas+i)+j) << endl;
//	//	x = *(*(mas+i)+j);
//	//}
//}

//****************************************************************************************
// Массивы и указатели
//****************************************************************************************

	//int mas[5] = {4,7,3,5,3};
	//inc(mas, 5);
	//showMas(mas, 5);

//****************************************************************************************
// Строки и указатели
//****************************************************************************************

	//cout << strlen1("привет");
	
	//char s1[] = "asas";
	//char s2[] = "adas";
	//
	//copystr1(s2, s1);
	//cout << s2;

	//char s1[20] = "asas";
	//char s2[] = "adas";
	//
	//strcat1(s1,s2);

	//cout << s1;

//
//	cout << strcmp1(s2, s1);

// указатель на указатель
//int x = 5;
//int *xx = &x;
//int **xxx = &xx;
//cout << xxx << " " << *xxx << " " << **xxx;

//указатель на строку
//char * str = "sdfdfdf";
//char * s = str;
////cout << str;
//while (*str != 0)
//{
//	cout << *str;
//	str++;
//}
//str = s;
//
//while (*str != 0)
//{
//	cout << *str;
//	str++;
//}

//указатель на массив строк
//char *str[3] = {"sdsd", "we32we","ckf87"};
//char **p;
//p = str;

//
//for (int i = 0; i < 3; i++)
//{
//	cout << *str << endl;
//}
//
//for (int i = 0; i < 3; i++)
//{
//	cout << *(str+i) << endl;
//}
//cout << **str;

//int i = 0;
//int j = 0;
//while (i < 3)
//{
//	while(*(*(str+i)+j) != 0)
//	{
//		cout << *(*(str+i)+j);
//		j++;
//	}
//	cout << endl;
//	j = 0;
//	i++;
//}

	//int x = 5;
	//int * iii = &x;
	//show_ptr(iii);
	//cout << endl << iii;


//****************************************************************************************
// Char cтроки и динамическая память
//****************************************************************************************

//****************************************************************************************
// Создание динамической char строки
//****************************************************************************************

	//char * str;
	//assign(str, 5, 'd');
	//cout << str;
	//delete [] str;

//****************************************************************************************
// 	Копирование динамической строки
//****************************************************************************************

	//char * str1;
	//char str2[] = "abc";
	//strcopy(str1, str2);
	//
	//cout << str1;
	//
	//delete [] str1;

//****************************************************************************************
// 	Объединение динамических строк
//****************************************************************************************

	//char * str1;
	//assign(str1,5,'a');

	//char * str2;
	//assign(str2,3,'b');

	//strcat(str1, str2);
	//
	//cout << str1;
	//
	//delete [] str1;

//****************************************************************************************
// Добавить символ к char строке
//****************************************************************************************

	//char * str1;

	//assign(str1,3,'b');

	//str1 = addsymbol(str1,'c');
	//
	//cout << str1;
	//
	//delete [] str1;


	

//****************************************************************************************
// Односвязный однонаправленный список
//****************************************************************************************
	//add_node(5);
	//add_node(4);
	//add_node(3);
	//add_node(5);
	//
	//print_list();

//****************************************************************************************
// Односвязный однонаправленный список 2
//****************************************************************************************

	//SNode *node;

	//node = NULL;

	//if (node == NULL)
	//{
	//	node = new SNode();
	//	node->next = NULL;
	//	node->val = 1;
	//}
	//else 
	//{
	//	SNode * temp = new SNode();
	//	temp->next = node;
	//	temp->val = val;
	//	node = temp;
	//}

//****************************************************************************************
// Двусвязный двунаправленный список
//****************************************************************************************
	//add_node2(1);
	//add_node2(2);
	//add_node2(3);
	//add_node2(4);
	//
	//print_list2();

//****************************************************************************************
// Игра квадраты
//****************************************************************************************

	//int x = 1;
	//int y;

	//srand(time(NULL));
	//x = rand() % 50 + 50;
	//cout << "Текущее число x = " << x << endl;

	//while (x != 0)
	//{
	//	cout << "Ходит первый игрок  " << endl;
	//	cout << "Введите квадрат любого числа ";
	//	cin >> y;

	//	cout << "Идет анализ. Подождите ..." << endl;
	//	Sleep(2000);


	//	if (x - y > 0)
	//	{
	//		x = x - y;
	//		cout << "Текущее число x = " << x << endl;
	//	} 
	//	else if (x - y == 0)
	//	{
	//		cout << "Выиграл первый игрок" << x << endl;
	//	} 
	//}
//****************************************************************************************
// Сдвиг массива
//****************************************************************************************
	//const int n = 5;
	//int a[n] = {1,2,3,4,5};
	//int t = a[n-1];
 //   for (int i = n-2; i >=0; i--)
	//{
	//	a[i+1] = a[i];
	//}
	//a[0] = t;
 //   for (int i = 0; i < n; i++)
	//{
	//	cout << a[i];
	//}
//****************************************************************************************
// Поменять местами половины массива
//****************************************************************************************
	//const int n = 6;
	//int a[n] = {1,2,3,4,5,6};
	//int t = 0;

 //   for (int i = 0; i < n/2 ; i++)
	//{
	//	t = a[i];
	//	a[i] = a[n-i-1];
	//	a[n-i-1] = t;
	//}

 //   for (int i = 0; i < n; i++)
	//{
	//	cout << a[i];
	//}


	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << E[i][j] << " ";
	//	}	
	//	cout << endl;
	//}
	
//****************************************************************************************
// звук, звуки, проиграть звуки
// Компоновщик\Ввод\Дополнительные зависимости = Winmm.lib (полный путь указывать не надо)
//****************************************************************************************
	//PlaySound(TEXT("C:\\WINDOWS\\Media\\ding.wav"), NULL, SND_ASYNC | SND_LOOP);
	// многократное поигрывание звука	
	//PlaySound(TEXT("C:\\WINDOWS\\Media\\Windows XP - запуск.wav"), NULL, SND_ASYNC | SND_LOOP);
	// однократное поигрывание звука	
	//PlaySound(TEXT("C:\\WINDOWS\\Media\\Windows XP - запуск.wav"), NULL, SND_ASYNC | SND_FILENAME);

	//for (int i = 0; i < 1000; i++)
	//{
	//	cout << i << " ";
	//	Sleep(50);
	//}


//****************************************************************************************
// число в строку 
// перевод числа в строку
//****************************************************************************************
	//float x = 3.15;
	//string y = to_string(x);
	//cout << y;
//****************************************************************************************
// конь визуализация
//****************************************************************************************
// int a; 
// int b ;
// int c ;
// int d ;
//
// a = 3;
// b = 3;
//
//
//for (int i = 0; i < 1000; i++)
//{
//	c = rnd(1,8);
//	d = rnd(1,8);
//
//	gotoxy(a-1,b-1);
//    cout << "K" << endl ;
//
//	if ( abs(a - c) > abs(b - d)&& b != d && (abs(a - c) == 2 || abs(d - b) == 2 && abs(a - c) == 1 || abs(d - b) == 1) || abs(a - c) < abs(b - d)&& a != c && (abs(a - c) == 2||abs(b - d) == 2 && abs(a - c) == 1 || abs(d - b) == 1) )
//	 {
//		gotoxy(c-1,d-1);
//		 cout << "*" << endl ;
//	 }
//	 else 
//	 {
//		gotoxy(c-1,d-1);
//		 cout << "-" << endl ;
//	 }
//}
//****************************************************************************************
// виртуальный метод, виртуальная функция, пример работы
//****************************************************************************************
	//AAA aaa;
	//BBB bbb;
	//CCC ccc;

	//AAA *p;

	//p = & aaa;
	//p->show();

	//p = & bbb;
	//p->show();

	//p = & ccc;
	//p->show();
//****************************************************************************************
// разные классы в массиве, разные классы в одном массиве
//****************************************************************************************
	//AAA * aaa[2][10];
	//BBB bbb[10];
	//CCC ccc[10];

	//for (int i = 0; i < 10; i++)
	//{
	//	aaa[0][i] = & bbb[i];
	//	aaa[1][i] = & ccc[i];
	//}

	//for (int i = 0; i < 10; i++)
	//{
	//	aaa[0][i]->show();
	//	aaa[1][i]->show();
	//}
//****************************************************************************************
// передача строки в функцию по ссылке
//****************************************************************************************
	//string str = "privet";
	//swap(str, 0, 1);
	//cout << str;
//****************************************************************************************
// Массив записей
//****************************************************************************************

	//SSS sss[5];
	//sss[0].age = 5;

//****************************************************************************************
// Работа со строками Удаление подстроки из string
//****************************************************************************************
	//string str ("This is an example sentence.");
	//cout << str << '\n';
	//str.erase (10,8);
	//cout << str << '\n';
	//str.find("vet");// вёрнет 3


	//s.erase(i+1,s.length() - 1);
	//cout << s;
	//string str = "Privet! Kak dela?";
	//str.erase (3);//строка примет вид "Pri! Kak dela?"
	//cout << str;
	//str.erase (0,3); //строка примет вид "vet! Kak dela?"
	//str.erase (3,3);//строка примет вид "Pri! Kak dela?"
	//В результате строка str примет вид "This is a phrase."
	//str.erase (str.begin() + 5, str.end() - 7);
	//В результате строка str примет вид "This phrase."

	//string str1 = "Privet! Kak dela?";
	//string str2;
	//str2 = str1.substr(0,3);
	//cout << str2;


//	string str = "privet kak dela";
	//string str = "privet kak dela";
	//cout << str.find('i');
	//cout << str.find("pri");

//****************************************************************************************
// Имя файла
//****************************************************************************************

	//string str = "с:\\data\\sub\\note.txt";
	//string str2;
	//int i = 0;
	//for (i = str.size() - 1; i >= 0; i--) 
	//{
	//	if (str[i] == '\\')
	//	{
	//		break;
	//	}
	//}
	//str2 = str.substr(i+1,str.size()-i-1);
	//cout << str2;

//****************************************************************************************
// Путь к файлу
//****************************************************************************************

	//string str = "с:\\data\\sub\\note.txt";
	//string str2;
	//int i = 0;
	//for (i = str.size() - 1; i >= 0; i--) 
	//{
	//	if (str[i] == '\\')
	//	{
	//		break;
	//	}
	//}
	//str2 = str.substr(0,i+1);
	//cout << str2;

//****************************************************************************************
// Работа с вектором, vector, stl
//****************************************************************************************

//	vector <int> vec; // создаём пустой вектор типа int
//	////vector <int> vec(3); // создаём вектор из трех элеменов заполненных 0
//	////vector <int> vec(3,7); // создаём вектор из трех элеменов заполненных 7
//
//	//vec.assign(3,0); // удаляет вектор и копирует указанные элементы в пустой вектор.
//
//vec.push_back(1); //добавление элемента в конец вектора
//vec.push_back(3); //добавление элемента в конец вектора
//vec.push_back(2); //добавление элемента в конец вектора
//
//
//cout << vec.at(1);

//
//cout << vec.size() << endl; // метод size() возвращает размер вектора 
//
//	//for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
//	//{
//	//	cout << vec[i] << " "; // доступ к элементу по индексу
//	//}
//
//	//vector <int> vec2(vec); // копирование вектора
//
//	//if (vec == vec2) // сравнение векторов
//	//{
// //       cout << "Вектора равны" << endl;
// //   }
//
//	//vec.empty(); // проверка вектора на пустоту
//
//	//cout << vec[0];
//
//
//	//vector <int>::iterator it;
//	//
//	//ivec.push_back(1);
//	//ivec.push_back(3);
//	//ivec.push_back(4);
//	//ivec.push_back(2);
//
//vec.pop_back();
//
//	//cout << ivec.max_size() << endl;
//
//for (int i = 0; i < ivec.size(); i++)
//{
//	cout << ivec[i];
//}
	//
	//ivec.assign(5,7);
	//for (int i = 0; i < ivec.size(); i++)
	//{
	//	cout << ivec[i];
	//}

	//for (it = ivec.begin(); it != ivec.end(); ++it)
	//	cout << *it << ' ';

	//vector <int> ivec (3,100);
	//vector <int>::iterator it;

	//it = ivec.begin();
	////it = ivec.end();
	//it = ivec.insert ( it , 200 );

	////it = ivec.begin() + 1;
	//it = ivec.erase( ivec.begin() + 1 );

	//for (int i = 0; i < ivec.size(); i++)
	//{
	//	cout << ivec[i];
	//}

	//myvector.insert (it,2,300);

	//// "it" no longer valid, get a new one:
	//it = myvector.begin();

	//std::vector<int> anothervector (2,400);
	//myvector.insert (it+2,anothervector.begin(),anothervector.end());

	//int myarray [] = { 501,502,503 };
	//myvector.insert (myvector.begin(), myarray, myarray+3);

	//std::cout << "myvector contains:";
	//for (it=myvector.begin(); it<myvector.end(); it++)
	//std::cout << ' ' << *it;
	//std::cout << '\n';

//****************************************************************************************
// Удаление нулевых элементов из вектора, псевдо паралелльность
//****************************************************************************************

	//srand(time(NULL));

	//vector <int> vec; // создаём пустой вектор типа int

	//for (int i = 0; i < 20; i++) // перебор элементов вектора через цикл for
	//{
	//	vec.push_back(rand()%2);
	//	cout << vec[i] << " ";
	//}

	//cout << endl;

	//int t = 0;

	//if (vec[vec.size()-1] == 0)
	//(
	//		
	//)

	////0 1 2 3 4 0


	//while (vec[vec.size()-1] == 0)
	//	vec.pop_back();

	//for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	cout << vec[i] << " ";
	//}
	//cout << endl;

	//for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	if (vec[i] == 0)
	//	{
	//		int t = vec[i];
	//		vec[i] = vec[vec.size()-1];
	//		vec[vec.size()-1] = t;
	//		while (vec[vec.size()-1] == 0)
	//			vec.pop_back();
	//	}
	//}

	//for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	cout << vec[i] << " ";
	//}


//****************************************************************************************
// Работа с двумерным вектором, двумерный вектор
//****************************************************************************************
	// вариант заполнения 1
	//vector <vector<int>> imatrix(3,5); 
	//for (vector <vector<int>> ::iterator it1 = imatrix.begin(); it1 != imatrix.end(); it1++)
	//{
	//	for (vector <int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
	//	{
	//		*it2 = 7;
	//	}
	//}

	//vector <vector<int>> vec; 
	//for(int i = 0; i < 3; i++)
	//{
	//	vector<int> temp;

	//	for(int j = 0; j < 5; j++)
	//	{
	//		temp.push_back(rand() % 10);
	//	}

	//	vec.push_back(temp);
	//}

//for(int i = 0; i < vec.size(); i++)
//{
//
//	for(int j = 0; j < vec[i].size(); j++)
//	{
//		cout << vec[i][j];
//	}
//	cout << endl;
//}


	//for (vector <vector<int>> ::iterator it1 = imatrix.begin(); it1 != imatrix.end(); it1++)
	//{
	//	for (vector <int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
	//	{
	//		cout << *it2 << " ";
	//	}
	//	cout << endl;
	//}



//****************************************************************************************
// Вектор векторов
//****************************************************************************************

	//srand(time(0));
	//vector <vector<int>> vec; 

	//initVecRand(vec);
	//printVec(vec);

//****************************************************************************************
// Неповторяющиеся случайные числа в двумерном векторе
//****************************************************************************************

	//srand(time(0));
	//vector <vector<int>> vec; 
	//int n = 5;
	//initVec(vec, n, 0);
	//fillUniqueRand(vec,1, n*n);
	//printVec(vec);

//****************************************************************************************
// Количество различных элементов в двумерном векторе
//****************************************************************************************

	//srand(time(0));
	//vector <vector<int>> vec; 
	//int n = 5;
	//initVec(vec, n, 0);
	//fillVecRand(vec, 1, 20);
	//printVec(vec);
	//cout << countUnique(vec);

//****************************************************************************************
// Работа со списком, list, stl
//****************************************************************************************
	//list <int> iilist;
	//ilist.push_back(1);

	//char str[10] = "sfsdf";
	//cout << str << " " << strlen(str);

 
//****************************************************************************************
// Конструктор копирования
//****************************************************************************************

	//// проблемный участок если нет конструктора копирования
	//SomeClass obj1; // создаем объект класса
	//*obj1.x = 5;
	//funcShow(obj1); // передаем объект в функцию
	//cout << *obj1.x;


 //   cout << "1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 //   SomeClass obj1; // создаем объект класса
 //
	//*obj1.x = 5;

 //   //cout << "2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 //   funcShow(obj1); // передаем объект в функцию
 //
	//cout << *obj1.x;

 //   cout << "3 - 4 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 //   funcReturnObject(); // эта функция возвращает объект
 //
 //   //cout << "5 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 //   SomeClass obj2 = obj1;  // инициализация объекта при создании
//****************************************************************************************
// Виртуальный деструктор
//****************************************************************************************
    //Base * p = new Derived;
    //delete p;

//****************************************************************************************
// Математические функции. sqrt, pow, abs, sin, cos, tan, log, log10
//****************************************************************************************
	//cout << sqrt(25.0);
	//cout << pow(25,0.5);
	//cout << log10(10.0);

//****************************************************************************************
// принцип разделение логики и интерфейса
//****************************************************************************************

	//string menu[3] = {"111","222","333"};

	//for(int i = 0; i < 3; i++)
	//{
	//	cout << menu[i] << " ";
	//}

	//int x=0,y=0;
	//int j = 0;
	//gotoxy(0,0);

	//while(true)
	//{
	//	char ch = getch();


	//	if (ch == '1')
	//	{
	//		j--;
	//	}
	//	if (ch == '2')
	//	{
	//		j++;
	//	}


	//	if (j == 0)
	//	{
	//		gotoxy(0,10);
	//		cout << "Действие 1";
	//	}

	//	if (j == 1)
	//	{
	//		gotoxy(0,10);
	//		cout << "Действие 2";
	//	}

	//	if (j == 2)
	//	{
	//		gotoxy(0,10);
	//		cout << "Действие 3";
	//	}

	//	x = j*5;

	//	gotoxy(x,0);

	//}

//****************************************************************************************
// каталог папка где находиться exe файл, экзешник
//****************************************************************************************

	//string s = get_full_path();

//****************************************************************************************
// удаление последненго символа строки
//****************************************************************************************

	//while (!s.empty())
	//{
	//	cout << s << endl;
	//	s.erase(s.length()-1,1);
	//}

//****************************************************************************************
//  добавление символа в конец чаровской строки
//****************************************************************************************

	//char s1[10] = "123";
	//addd(s1);
	//addd(s1);
	//cout << s1 << " " << strlen(s1) << endl;

//****************************************************************************************
//  строковые операции с чаровской строкой, char строкой
//****************************************************************************************

	//char s1[10] = "1234546";

	////strchr(s1, '3');

	//char * ch = strchr(s1, '3');

	//if (ch != NULL)
	//	cout << s1[ch-s1];

	//char s2[10] = "1234";
	////strcpy(s2,s1); // Копирование строк

	////сравнивает строку s1 со строкой s2 и возвращает результат типа int: 
	////0 –если строки эквивалентны, 
	////>0 – если s1<s2,  
	////<0  — если s1>s2 С учётом регистра
	//if (strcmp(s1,s2) == 0) // Сравнение строк
	//	cout << "строки равны";
	//else
	//	cout << "строки не равны";


	//cout << isalnum((int)'1');//возвращает значение true, если с является буквой или цифрой, и false в других случаях
	//cout << isalpha('1');//возвращает значение true, если с является буквой,  и false в других случаях
	//cout << isdigit('6');//возвращает значение true, если с является цифрой, и false в других случаях
	//cout << islower('D');//возвращает значение true, если с является буквой нижнего регистра, и false в других случаях
	
	//char s1[10] = "123";
	//int x = atoi(s1);//преобразует строку s1 в тип int
	//char s1[10] = "3.14";
	//float x = atof(s1);//преобразует строку s1 в тип int
	//cout << x+1;

//****************************************************************************************
// atoi пример использования
//****************************************************************************************

//string s = "123";
//cout << atoi(s.c_str());

//****************************************************************************************
// Парсер целых чисел
//****************************************************************************************

	//string str1 = "12,400,1";
	//string str2 = "";
	//bool f = true;
	//int s = 0;
	//for (int i = 0; i < str1.length(); i++)
	//{
	//	if (str1[i] != ',')
	//	{
	//		str2 += str1[i];
	//	} 
	//	else if (str1[i] == ',')
	//	{
	//		s = s + atoi(str2.c_str());
	//		str2 = "";
	//	}
	//}
	//s = s + atoi(str2.c_str());
	//cout << s;

//****************************************************************************************
// Длинная арифметика
//****************************************************************************************

	//string str1 = "1";
	//string str2 = "9";
	//string str3 = "";

	//if (str1.length() < str2.length())
	//{
	//	str1.swap(str2);
	//}

	//int n = str2.length();

	//for(int i = 0; i < str1.length() - n; i++)
	//{
	//	str2 = '0' + str2;
	//}

	//bool perenos = 0;

	//for (int i = str1.length()-1; i >= 0; i--)
	//{
	//	int x = (str1[i]-48) + (str2[i]-48);

	//	if (perenos)
	//	{
	//		x++;
	//		perenos = 0;
	//	}		
	//	
	//	if (x >= 10)
	//	{
	//		perenos = 1;
	//	}

	//	str3 = (char)(x % 10 + 48) + str3;
	//}
	//if (perenos)
	//{
	//	str3 = '1' + str3;
	//}

	//cout << str3;


//****************************************************************************************
// массив строк
//****************************************************************************************

//string mas[3] = {"privet", "kak", "dela"};
//cout << mas[0];
//cout << mas[2];
//
//cout << mas[0].length();


//****************************************************************************************
// Список папок и файлов с диска С. Работает при настройке проекта: Использовать многобайтовую кодировку
//****************************************************************************************

	//WIN32_FIND_DATA FindFileData;
	//HANDLE hf;
	//hf = FindFirstFile("c:\\*",&FindFileData);
	//if(hf != INVALID_HANDLE_VALUE){
	//	do{
	//		printf("%s\n",FindFileData.cFileName);
	//	}
	//	while(FindNextFile(hf,&FindFileData) != 0);
	//	FindClose(hf);
	//}

//****************************************************************************************
// строковые операции со string строкой
//****************************************************************************************

	//string s = "pri  vet";
	//cout << s;


	//cout << s.erase();
	//cout << s.empty();
	//cout << s.erase(3);
	//cout << s.assign(5,'s');
	//cout << s.assign("sa");
	//const char * ss = s.c_str();
	//cout << ss;
	//cout << s.find("fv");
	//cout << string::npos;

	//cout << s.replace(s.find("  "),2,"");

//****************************************************************************************
// методичка
//****************************************************************************************

//setlocale(LC_ALL, "rus");
//
//// вывод данных
//cout << "Hello World!";
//cout << endl;
//cout << "Hello," << endl << "World!" << endl;
//cout << "Hello," << " World!" << endl;
//
//// арифметические операции
//cout << 1 << endl;
//cout << 1+3-2*5 << endl;
//cout << 10/2 << endl;
//cout << 10/3 << endl;
//cout << 10%2 << endl;
//cout << 10%3 << endl;
//cout << 10+3*2-4*(7-3) << endl;
//
//// способы объявления переменных
//int x;
//int y;
//int x,y;
//int x = 0;
//int x,y = 5;
//float x;
//float x = 3.14;
//x = 3;
//y = x;
// 
//cin >> x;
//

//int x;
//
//if (x > 5)
//{
//	cout << "Введите данные в x:" << endl;
//}
//else
//{
//	cout << "Введите данные в x:" << endl;
//}


//int x = 1;
//
//if (x > 5)
//{
//	cout << 1 << endl;
//}
//else if (x == 5)
//{
//	cout << 2 << endl;
//}
//else if (x < 5)
//{
//	cout << 3 << endl;
//}




//****************************************************************************************
// сеттеры геттеры set get  
//****************************************************************************************

    //CAny any(10);
    //cout << any.get_x() << endl;
    //any.set_x(-20);
    //cout << any.get_x() << endl;

//****************************************************************************************
// MyString
//****************************************************************************************

	//MyString s1;
	//MyString s2;

	//s1.assign("123");
	//s2.assign("45");

	////s2[0] = 50;
	////cout << s2;
	////cout << s1 << "     " << s1.length() << endl;

	////s1 = s1 + s2;
	////cout << s1 << "     " << s1.length() << endl;

	//cout << any_func();

	//any_func(s1);
	//
	//s1 = s2;

	//s1 = "asaasasasas";

	//cout << s1 << endl;
	//cout << s2 << endl;

//****************************************************************************************
// 
//****************************************************************************************

	//string s = "Pri  vet";

	//s[0] = toupper(s[0]);
	//s[0] = tolower(s[0]);

	//cout << s;

//****************************************************************************************
// Параметры командной строки, командная строка
// общие / набор знаков / или "не задано" или "использовать многобайт кодировку"
//****************************************************************************************

	//// Выводим список аргументов в цикле
	//   for (int i = 1; i < argc; i++) 
	//{
	//       cout << "Argument " << i << " : " << argv[i] << endl;

	//	if (strcmp(argv[i],"help") == 0)
	//	{
	//		cout << "help" << endl;
	//		cout << "help" << endl;
	//		cout << "help" << endl;
	//	}
	//   }

//****************************************************************************************
// дружественные функции, дружественные классы, friend
//****************************************************************************************

	//A test; //создали экземпляр класса А - example
	////собственно тестирование дружественной функции классу B
	//test.FriendToB();
	////проверим, все ли функции-члены класса A являются дружественными
	////классу С (на примере, функции SomeFunction)
	//test.SomeFunction();
//****************************************************************************************
// условная компиляция
//****************************************************************************************

//#if DEBUG == 1
//    cout << "DEBUG";
//#else
//    // код для Release
//    cout << "RELEASE";
//#endif

//****************************************************************************************
// разность дат
//****************************************************************************************

	//cout << diff_date("08.12.2016","01.12.2016");

//****************************************************************************************
// ханойская башня через вектор
//****************************************************************************************

//без графики только бек энд почему так акценты на другом
//архитекрута показать как выбранные данные вдлияют на работу программы
//сначала попробоавать на стеке сделать
//получисля набор условий
//с опытом вы будете понимать что этот код можно преобразовать
//к тому же что если башен станет больше и условий станет больше


	//vector <int> tower1;
	//vector <int> tower2;
	//vector <int> tower3;

	//int t1, t2, t3;
	//int disk1;
	//int disk2;

	//const int N = 2;

	//tower1.push_back(100);
	//tower2.push_back(100);
	//tower3.push_back(100);

	//for (int i = N; i >= 1; i--) 
	//{
	//	tower1.push_back(i);
	//}

	//while(true)
	//{
	//	cout << "Состояние башен: " << endl;

	//	show_tower(tower1);
	//	show_tower(tower2);
	//	show_tower(tower3);

	//	cout << "Откуда: ";
	//	cin >> t1;

	//	cout << "Куда: ";
	//	cin >> t2;

	//	if (t1 == 1 && t2 == 2)
	//	{
	//		disk1 = tower1[tower1.size()-1];
	//		disk2 = tower2[tower2.size()-1];

	//		if (!moveDisk(tower1,tower2,disk1,disk2))
	//		{
	//			cout << "error" << endl;
	//		}
	//	}

	//	if (t1 == 1 && t2 == 3)
	//	{
	//		disk1 = tower1[tower1.size()-1];
	//		disk2 = tower3[tower3.size()-1];

	//		if (!moveDisk(tower1,tower3,disk1,disk2))
	//		{
	//			cout << "error" << endl;
	//		}
	//	}

	//	if (t1 == 2 && t2 == 1)
	//	{
	//		disk1 = tower2[tower2.size()-1];
	//		disk2 = tower1[tower1.size()-1];

	//		if (!moveDisk(tower2,tower1,disk1,disk2))
	//		{
	//			cout << "error" << endl;
	//		}
	//	}

	//	if (t1 == 2 && t2 == 3)
	//	{
	//		disk1 = tower2[tower2.size()-1];
	//		disk2 = tower3[tower3.size()-1];

	//		if (!moveDisk(tower2,tower3,disk1,disk2))
	//		{
	//			cout << "error" << endl;
	//		}
	//	}
	//	if (t1 == 3 && t2 == 1)
	//	{
	//		disk1 = tower3[tower3.size()-1];
	//		disk2 = tower1[tower1.size()-1];

	//		if (!moveDisk(tower3,tower1,disk1,disk2))
	//		{
	//			cout << "error" << endl;
	//		}
	//	}
	//	if (t1 == 3 && t2 == 2)
	//	{
	//		disk1 = tower3[tower3.size()-1];
	//		disk2 = tower2[tower2.size()-1];

	//		if (!moveDisk(tower3,tower2,disk1,disk2))
	//		{
	//			cout << "error" << endl;
	//		}
	//	}

	//	if (tower2.size() == N+1 || tower3.size() == N+1)
	//	{
	//		cout << "Состояние башен: " << endl;
	//		show_tower(tower1);
	//		show_tower(tower2);
	//		show_tower(tower3);

	//		cout << "win!!!" << endl;
	//		break;
	//	}
	//}

//****************************************************************************************
// ханойская башня через двумерный вектор
//****************************************************************************************

	//vector <int> tower1;
	//vector <int> tower2;
	//vector <int> tower3;
	//
	//vector <vector <int>> towers;

	//int t1, t2, t3;
	//int disk1;
	//int disk2;

	//const int N = 2;

	//tower1.push_back(100);
	//tower2.push_back(100);
	//tower3.push_back(100);

	//for (int i = N; i >= 1; i--) 
	//{
	//	tower1.push_back(i);
	//}

	//towers.push_back(tower1);
	//towers.push_back(tower2);
	//towers.push_back(tower3);

	//while(true)
	//{
	//	cout << "Состояние башен: " << endl;

	//	show_tower(towers[0]);
	//	show_tower(towers[1]);
	//	show_tower(towers[2]);

	//	cout << "Откуда: ";
	//	cin >> t1;

	//	cout << "Куда: ";
	//	cin >> t2;

	//	disk1 = towers[t1][towers[t1].size()-1];
	//	disk2 = towers[t2][towers[t2].size()-1];

	//	if (!moveDisk(towers[t1],towers[t2],disk1,disk2))
	//	{
	//		cout << "error" << endl;
	//	}

	//	if (towers[1].size() == N+1 || towers[2].size() == N+1)
	//	{
	//		cout << "Состояние башен: " << endl;

	//		show_tower(towers[0]);
	//		show_tower(towers[1]);
	//		show_tower(towers[2]);

	//		cout << "win!!!" << endl;
	//		break;
	//	}
	//}



//****************************************************************************************
// ханойская башня через вектор и указатели
//****************************************************************************************

	//vector <int> tower1;
	//vector <int> tower2;
	//vector <int> tower3;

	//vector <int> * sour;
	//vector <int> * dest;

	//int t1, t2, t3;
	//int disk;

	//const int N = 2;

	//for (int i = N; i >= 1; i--) 
	//{
	//	tower1.push_back(i);
	//}

	//while(true)
	//{
	//	cout << "Состояние башен: " << endl;
	//	show_tower(&tower1);
	//	show_tower(&tower2);
	//	show_tower(&tower3);

	//	cout << "Откуда: ";
	//	cin >> t1;

	//	cout << "Куда: ";
	//	cin >> t2;

	//	if (t1 == 1)
	//		sour = &tower1;
	//	else if (t1 == 2)
	//		sour = &tower2;
	//	else if (t1 == 3)
	//		sour = &tower3;
	//	
	//	if (t2 == 1)
	//		dest = &tower1;
	//	else if (t2 == 2)
	//		dest = &tower2;
	//	else if (t2 == 3)
	//		dest = &tower3;

	//	if (!(*sour).empty())
	//	{
	//		disk = (*sour)[(*sour).size()-1];
	//		cout << disk << endl;
	//	}

	//	if ((*dest).empty())
	//	{
	//		if (!(*sour).empty())
	//		{
	//			(*dest).push_back(disk);
	//			(*sour).pop_back();
	//		}
	//	} 
	//	else if (disk < (*dest)[(*dest).size()-1])
	//	{
	//		(*dest).push_back(disk);
	//		(*sour).pop_back();
	//	}
	//	else
	//	{
	//		cout << "error" << endl;
	//	}

	//	if (tower2.size() == N || tower3.size() == N)
	//	{
	//		cout << "Состояние башен: " << endl;
	//		show_tower(&tower1);
	//		show_tower(&tower2);
	//		show_tower(&tower3);

	//		cout << "win!!!" << endl;
	//		break;
	//	}
	//}
//****************************************************************************************
// ханойская башня через двумерный вектор
//****************************************************************************************

	//vector <vector <int>> towers;
	//vector <int> tower1;

	//int sour;
	//int dest;

	//int disk;

	//const int N = 3;

	//for (int i = N; i >= 1; i--) 
	//{
	//	tower1.push_back(i);
	//}

	//towers.push_back(tower1);
	//tower1.clear();
	//towers.push_back(tower1);
	//towers.push_back(tower1);

	//while(true)
	//{
	//	cout << "Состояние башен: " << endl;
	//	show_tower(towers[0]);
	//	show_tower(towers[1]);
	//	show_tower(towers[2]);

	//	cout << "Откуда: ";
	//	cin >> sour;

	//	cout << "Куда: ";
	//	cin >> dest;

	//	if (!towers[sour].empty())
	//	{
	//		disk = towers[sour][towers[sour].size()-1];
	//		cout << disk << endl;
	//	}

	//	if (towers[dest].empty())
	//	{
	//		if (!towers[sour].empty())
	//		{
	//			towers[dest].push_back(disk);
	//			towers[sour].pop_back();
	//		}
	//	} 
	//	else if (disk < towers[dest][towers[dest].size()-1])
	//	{
	//		towers[dest].push_back(disk);
	//		towers[sour].pop_back();
	//	}
	//	else
	//	{
	//		cout << "error" << endl;
	//	}

	//	if (towers[1].size() == N || towers[2].size() == N)
	//	{
	//		cout << "Состояние башен: " << endl;
	//		show_tower(towers[0]);
	//		show_tower(towers[1]);
	//		show_tower(towers[2]);

	//		cout << "win!!!" << endl;
	//		break;
	//	}
	//}


//****************************************************************************************
// 	Шифрование через стек
//****************************************************************************************

	//string s = "12 123 34567";
	//string s2 = "";
	//stack <char> stk;

	//bool right = true;
	//for (int i = 0; i < s.length(); i++)  
	//{
	//	if (s[i] != ' ')
	//	{
	//		stk.push(s[i]);
	//	}
	//	else 
	//	{
	//		while (!stk.empty())
	//		{

	//			s2 = s2 + stk.top();
	//			stk.pop();
	//		}

	//		s2 += ' ';

	//	}
	//}

	//while (!stk.empty())
	//{

	//	s2 = s2 + stk.top();
	//	stk.pop();
	//}

	//cout << s2;


//****************************************************************************************
// проверка правильности расположения скобок
//****************************************************************************************

	//string s = "([)";
	//vector <char> v;

	//bool right = true;
	//for (int i = 0; i < s.length(); i++)  
	//{
	//	if (s[i] == '(' || s[i] == '[')
	//	{
	//		v.push_back(s[i]);
	//	}
	//	else if (s[i] == ')')
	//	{
	//		if (!v.empty())
	//		{
	//			if (v[v.size()-1] == '(')			
	//			{
	//				v.pop_back();
	//			}
	//			else
	//			{
	//				right = false;
	//				break;
	//			}
	//		}
	//		else
	//		{
	//			right = false;
	//			break;
	//		}
	//	}
	//	else if (s[i] == ']')
	//	{
	//		if (!v.empty())
	//		{
	//			if (v[v.size()-1] == '[')			
	//			{
	//				v.pop_back();
	//			}
	//			else
	//			{
	//				right = false;
	//				break;
	//			}
	//		}
	//		else
	//		{
	//			right = false;
	//			break;
	//		}
	//	}
	//}

	//if (v.empty() && right)
	//	cout << 1;
	//else
	//	cout << 0;


//****************************************************************************************
// передача массива в качестве параметра в функцию
//****************************************************************************************

	//int mas[5] = {0};

	//mas[0] = 2;
	//mas[1] = 4;
	//mas[2] = 7;
	//mas[3] = 1;

	//show2(mas);

	//size_t d;

	//int * p;

	//p = &mas[0];
	////cout << &p << " " << p << endl;

	////cout << mas + 1 << endl;
	////cout << mas + 2 << endl;
	//cout << *(mas + 0) << endl;

	/*const_cast*/ 

//****************************************************************************************
// Работа со структурами, персонаж, описание персонажа
//****************************************************************************************

	//SPlayer p1;
	//SPlayer p2;

	//p1.artef[0] = MECH;
	//p1.kind = MAG;

	//p1.name = "hdhfhf";
	////cout << pl.kind;
	//p1.x = 10;
	//p1.y = 20;
	//p1.show();


	//p2.artef[0] = MECH;
	//p2.kind = MAG;

	//p2.name = "hdhfhf";
	////cout << pl.kind;
	//p2.x = 11;
	//p2.y = 20;
	//p2.show();

	//atack(p1,p2);

//****************************************************************************************
// Размер переменных sizeof
//****************************************************************************************

//cout
//<< "char           " << sizeof(char)           << " " << SCHAR_MIN << " " << SCHAR_MAX << endl
//<< "char           " << sizeof(unsigned char)  << " " << 0         << " " << UCHAR_MAX << endl
//<< "short          " << sizeof(short)          << " " << SHRT_MIN  << " " << SHRT_MAX  << endl
//<< "unsigned short " << sizeof(unsigned short) << " " << 0         << " " << USHRT_MAX << endl
//<< "int            " << sizeof(int)            << " " << INT_MIN   << " " << INT_MAX   << endl
//<< "unsigned int   " << sizeof(unsigned int)   << " " << 0         << " " << UINT_MAX  << endl
//<< "long           " << sizeof(long)           << " " << LONG_MIN  << " " << LONG_MAX  << endl
//<< "long long      " << sizeof(long long)      << " " << LLONG_MIN << " " << LLONG_MAX << endl
//<< "float          " << sizeof(float)          << " " << LLONG_MIN << " " << LLONG_MAX << endl
//<< sizeof(float)  << endl
//<< sizeof(double)  << endl
//<< sizeof(long long)  << endl
//<< endl;	

	//int x;
	//cout << sizeof(long long int);




//FLT_DIG

	//short x = 32768;
	//cout << x;

	//int m[10];
	//cout << sizeof(m);

//****************************************************************************************
// Тернарный оператор ? Тернарная условная операция
//****************************************************************************************

	//cout << (10 < 5) ? 1 : 0;

//****************************************************************************************
// Очередь с удалением последнего элемента
//****************************************************************************************
	
	//vector <int> vec; // создаём пустой вектор типа int

	//for (int i = 0; i < 15; i++) // перебор элементов вектора через цикл for
	//{
	//	//vec.push_back(rnd(1,200)); //добавление элемента в конец вектора
	//	vec.push_back(i+10); //добавление элемента в конец вектора
	//}

	//while (!vec.empty())
	//{
	//	system("cls");

	//	for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
	//	{

	//		// добавление случайным образом нового задания
	//		if (rnd(1,100) < 4) // перебор элементов вектора через цикл for
	//		{
	//			//vec.push_back(rnd(1,50)); //добавление элемента в конец вектора
	//		}

	//		//gotoxy(0,i);
	//		//cout << "   " << endl;
	//		//gotoxy(0,i);
	//		cout << vec[i] << endl;

	//		// пока задание активно делаем действие
	//		if (vec[i] > 0)
	//		{
	//			vec[i]--;
	//			Sleep(100);
	//		}

	//		else
	//		{
	//			// оптимизация удаления отработавщих заданий
	//			// если в векторе не менее двух элементов обмениваем местами текущий с последним
	//			if (vec.size()>=2)
	//			{
	//				int t = 0;
	//				t = vec[i];
	//				vec[i] = vec[vec.size() - 1];
	//				vec[vec.size() - 1] = t;
	//			}
	//		}

	//		//if (vec.empty())
	//		//	break;

	//		// удаление нулевых значений
	//		while (vec[vec.size() - 1] == 0)
	//		{
	//			vec.pop_back();
	//			if (vec.empty())
	//				break;
	//		}

	//		if (vec.empty())
	//			break; 

	//	}
	//}

//****************************************************************************************
// Очередь с удалением последнего элемента
//****************************************************************************************

	//CTasks <int> tasks;// = new CTasks();

	//tasks.push(7);
	//tasks.push(7);
	//tasks.push(17);
	//tasks.push(27);
	//tasks.push(57);

	//while (!tasks.empty())
	//{
	//	system("cls");
	//	tasks.work();
	//	tasks.show();
	//	Sleep(100);
	//}

	//system("cls");
	//tasks.show();

//****************************************************************************************
// Очередь на основе массива.
// В очередь добавляется случайное число. Работа декремент. Когда выполнилось элемент удаляется из очередь.
// Случайно добавляется новый элемент.
//****************************************************************************************

	//int mas[500] = {0};
	//int tail;
	//int head;

	//head = 0;
	//tail = 0;

	//while(true)
	//{
	//	// work
	//	if (head != tail)
	//	{
	//		mas[0]--;
	//	}

	//	//fin_first()
	//	if (mas[0] == 0)
	//	{
	//		for(int i = 0; i < tail-1; i++)
	//		{
	//			mas[i] = mas[i+1];
	//		}
	//		mas[tail] = 0;
	//		tail--;
	//	}

	//	if (rand(1,4) == 1)
	//	{
	//		mas[tail] = rand(1,10);
	//		tail++;
	//	}

	//	system("cls");

	//	for(int i = 0; i < tail; i++)
	//	{
	//		cout << mas[i] << " ";
	//	}
	//	
	//	Sleep(100);

	//}

//****************************************************************************************
// 	Словарь цвет номер
//****************************************************************************************

	//map <string,int> mp;
	//
	//mp["Red"]    = 1;
	//mp["Yellow"] = 2;
	//mp["Green"]  = 3;

	//cout << mp["Red"] << endl;

	//for (map <string,int>::iterator it = mp.begin(); it != mp.end(); it++)
	//{
	//	cout << it->first << ": " << it->second << endl;
	//}	

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

//****************************************************************************************
// Ассоциативный массив map словарь
//****************************************************************************************


	//map <char,int> my_map;

	//my_map['s']++; 
	//my_map['d']++; 
	//my_map['d']++; 
	//my_map['a']++; 
	//my_map['a']++; 
	//my_map['f']++; 
	//my_map['a']++; 

	//cout << "Char count:" << endl;







	//map <char,int> my_map;

	//my_map.insert ( pair<char,int>('a',10) );
	//my_map.insert ( pair<char,int>('d',20) );
	//my_map.insert ( pair<char,int>('f',10) );	

	//for (map <char,int>::iterator it = my_map.begin(); it != my_map.end(); it++)
	//{
	//	cout << it->first << ": " << it->second << endl;
	//}	



//****************************************************************************************
// Умный указатель
//****************************************************************************************

	//int *x = new int;
	//auto_ptr <int> px1(x);
	//auto_ptr <int> px2;
	//*x = 5;

	//cout << px1.get() << " " << px2.get() << endl;
	//
	////vector <auto_ptr <int>> vec;
	////vec.push_back(px1);

	//px2 = px1;

	//cout << px1.get() << " " << px2.get() << endl;

	//cout << *x << endl;

	//int *x = new int;
	//*x = 5;
	//smart_pointer <int> px(x);
	//std::tr1::shared_ptr <int> ppx;
	//px.m_obj = 7;

//****************************************************************************************
// поле ввода
//****************************************************************************************

	//int ch;

	//string pass = "";

	//int x = 0;

	//while(true)
	//{
	//	ch = getch();

	//	if (ch == 13)
	//	{
	//		break;	
	//	}
	//	else if (ch == 8)
	//	{
	//		if (!pass.empty())
	//			pass.erase(pass.length()-1);
	//		cout << (char)8 << ' ' << (char)8;
	//	}
	//	else
	//	{
	//		pass = pass + (char)ch;
	//		cout << (char)ch;
	//	}
	//}

	//cout << endl << pass;


//****************************************************************************************
// пароль поле ввода
//****************************************************************************************

	//stack <int> stk;

	//int ch;

	//string pass = "";

	//while(true)
	//{
	//	ch = getch();

	//	if (ch == 13)
	//		break;	

	//	else if (ch == 8)
	//	{
	//		if (!pass.empty())
	//		{
	//			stk.push(pass[pass.length()-1]);
	//			pass.erase(pass.length()-1);
	//		}
	//		cout << (char)8 << ' ' << (char)8;
	//	}
	//	else if (ch == 27)
	//	{
	//		if (!stk.empty())
	//		{
	//			if (stk.top() == 1)
	//			{
	//				if (!pass.empty())
	//					pass.erase(pass.length()-1);
	//				cout << (char)8 << ' ' << (char)8;
	//				stk.pop();
	//			}
	//			else if (stk.top() != 1)
	//			{
	//				if (!pass.empty())
	//				{
	//					pass = pass + (char)stk.top();
	//					cout << (char)stk.top();
	//					stk.pop();
	//				}
	//			}
	//		}
	//	
	//	}
	//	else
	//	{
	//		pass = pass + (char)ch;
	//		cout << (char)ch;
	//		stk.push(1);
	//	}
	//}

	//cout << endl << pass;

//****************************************************************************************
// приведение типов
//****************************************************************************************

    //int int_value15 = 15, int_value2 = 2; // объявляем две переменные типа int
    //float float_value15 = 15, float_value2 = 2; // объявляем две переменные типа float

    //cout << fixed << setprecision(2) // определяем, при выводе чисел с плавающей точкой, два знака после запятой
    //     << "15   / 2   = " << int_value15   / int_value2   << endl  //неявное преобразование типов данных
    //     << "15   / 2   = " << int_value15   / float_value2 << endl  //неявное преобразование типов данных
    //     << "15   / 2   = " << float_value15 / int_value2   << endl  //неявное преобразование типов данных
    //     << "15   / 2   = " << float_value15 / float_value2 << endl; //неявное преобразование типов данных
    //cout << "15.0 / 2   = " << 15.0 / 2 << endl  // явное преобразование типа данных, число 15.0 - число с плавающей точкой
    //     << "15   / 2.0 = " << 15 / 2.0 << endl; // явное преобразование типа данных, число 2.0  - число с плавающей точкой
    //cout << "float(int_value15) / int_value2 = " << float(int_value15) / int_value2 << endl // явное преобразование типа данных
    //     << "15 / double(2) = " << 15 / double(2) << endl;                                    // используя приводимый тип как функцию
    //cout << "static_cast<float>(15) / 2 = " << static_cast<float>(15) / 2 << endl // унарная операция приведения типа
    //     << "static_cast<char>(15) = " << static_cast<char>(15) << endl  // можно печатать различные символы из таблицы ASCII,
    //     << "static_cast<char>(20) = " << static_cast<char>(20) << endl; // в скобочках прописываем код символа, который находим в таблице ASCII

	//cout << fact(150000);


    //float x = 2.4567;
    //cout << fixed << setprecision(2) << x;


//****************************************************************************************
// cin очистка буфера
//****************************************************************************************

	//int x;


	//while(true)
	//{
	//	cin >> x;
	//	if (cin.good())
	//	{
	//		cout << "1";
	//	} 
	//	else
	//	{
	//		cout << "0";
	//		cin.clear();
	//		cin.sync();
	//		while (cin.get() != '\n');
	//	}

	//}

//****************************************************************************************
// два кубика
//****************************************************************************************

	//int mas[13] = {0};

	//int d1, d2;

	//for (int i = 0; i < 100000; i++)
	//{
	//	d1 = rand()%6 + 1;
	//	d2 = rand()%6 + 1;

	//	mas[d1+d2]++;
	//}

	//for (int i = 1; i < 13; i++)
	//{
	//	cout << i << " = " << (float)mas[i]/100000 << endl;
	//}

//****************************************************************************************
// два кубика один за другим
//****************************************************************************************

	//int mas[13] = {0};

	//int d1, d2;
	//float f = 0;

	//int n;

	//cin >> n;

	//for (int i = 0; i < n; i++)
	//{
	//	d1 = rand()%6 + 1;

	//	if (d1 >= 4)
	//	{

	//		d2 = rand()%6 + 1;
	//		if (d2 >= 4)
	//		{
	//			f++;
	//		}

	//	}

	//}

	//cout << f * 100 / n << endl;


//****************************************************************************************
// заполнение массива случайными неповтор не повтор числами
//****************************************************************************************

	//srand(time(NULL));

	//const int N = 5;

	//int mas[N] = {0};

	//int x = 0;
	//int k = 0;

	//bool canFill = true;

	//while (k < N)
	//{
	//	x = rand(1,N);

	//	bool find = false;

	//	for (int i = 0; i < N; i++)
	//	{
	//		if (x == mas[i])
	//		{
	//			find = true;		
	//			break;
	//		}
	//	}

	//	if (!find)
	//	{
	//		mas[k] = x;
	//		k++;
	//	}

	//}

	//for (int i = 0; i < N; i++)
	//{
	//	cout << mas[i] << " ";
	//}

//****************************************************************************************
// работа с потоками
//****************************************************************************************

	//InitializeCriticalSection( &cs );

	//int param = 1;  
 //   int * pparam = &param;  
 //    _beginthread( Thread1, 0, (void *) pparam );

	//int param2 = 2;  
 //   int * pparam2 = &param2;  
 //   _beginthread( Thread1, 0, (void *) pparam2);
	 


	 //_beginthread( Thread2, 0, NULL );
  
  //   while(1)
	 //{
  ////      printf("%d %d %d %d %d\n", 
  ////             a[ 0 ], a[ 1 ], a[ 2 ],
  ////             a[ 3 ], a[ 4 ] );
		////EnterCriticalSection( &cs );
		////cout << xxx;
		////LeaveCriticalSection( &cs );
	 //}

//****************************************************************************************
// работа с потоками
//****************************************************************************************


	//InitializeCriticalSection( &cs );

	//int param = 1;  
 //   int * pparam = &param;  
 //    _beginthread( Thread3, 0, (void *) pparam );

	// cin >> str;

//****************************************************************************************
// бинарные файлы
//****************************************************************************************

	//ifstream file1("d:\\test\\test1.txt");//создать input-file object тоесть файл ИЗ которого читать  
	//ofstream file2("d:\\test\\test2.txt");//создать input-file object тоесть файл ИЗ которого читать  
	////ifstream file1("d:\\test\\test1.jpg");//создать input-file object тоесть файл ИЗ которого читать  
	////ofstream file2("d:\\test\\test2.jpg");//создать input-file object тоесть файл ИЗ которого читать  
	//
	//if (!file1.is_open() || !file2.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	char ch;  
	//	while (file1.get(ch))
	//	{
	//		cout << (int)ch << " ";
	//		file2.put(ch);
	//	}
	//	file1.close();
	//	file2.close();
	//}

	//cout << endl;

	////ifstream file1("d:\\test\\test1.txt",ios::binary);//создать input-file object тоесть файл ИЗ которого читать  
	////ofstream file2("d:\\test\\test2.txt",ios::binary);//создать input-file object тоесть файл ИЗ которого читать  

	//file1.open("d:\\test\\test2.txt",ios::binary);
	//file1.seekg(0);

	//if (!file1.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}
	//else
	//{
	//	char ch;  
	//	while (file1.get(ch))
	//	{
	//		cout << (int)ch << " ";
	//		file2.put(ch);
	//	}
	//	file1.close();
	//	file2.close();
	//}

//****************************************************************************************
// псевдо паралелльность вектор
//****************************************************************************************

	//vector <SPoint> vec;
	//int ch = 0;
	//int a = 0;

	//while(ch != 27)
	//{
	//	while(!kbhit())
	//	{
	//		for(int l=0; l < vec.size(); l++)
	//		{
	//			if(vec[l].val > 0)
	//			{
	//				vec[l].val--;
	//			}

	//			cout << vec[l].val;
	//			cout << endl;
	//		}

	//		Sleep(200);
	//		system("cls");

	//	}

	//	ch = _getch();

	//	if (ch == 'a')
	//	{
	//		SPoint t;
	//		t.val = rand()%20;

	//		vec.push_back(t);
	//	}
	//	else if (ch == 'd')
	//	{
	//		for(int l=0; l < vec.size(); l++)
	//		{
	//			
	//			if (!vec.empty())
	//			{
	//				if(vec[vec.size()-1].val <=0)
	//				{
	//					vec.pop_back();
	//				}
	//			}

	//			if (!vec.empty())
	//			{
	//				if(vec[l].val <= 0)
	//				{
	//					vec[l].val = vec[vec.size()-1].val;
	//					vec.pop_back();
	//				}
	//			}

	//		}
	//	
	//	}
	//	
	//	

	//}


//****************************************************************************************
// игра 24 для детишек
//****************************************************************************************

	//int mas[50] = {0};

	//int d1, d2;

	//for (int i = 0; i < 10000; i++)
	//{
	//	int s = 0;

	//	for (int i = 0; i < 2; i++)
	//	{
	//		d1 = rand()%6 + 1;

	//		if (rand()%2 == 0)
	//		{
	//			s = s + d1;
	//			//cout << " + ";
	//		}
	//		else
	//		{
	//			s = s - d1;
	//			//cout << " - ";
	//		}

	//		cout << d1 << " ";
	//		if (s >= 0)
	//		mas[s]++;

	//	}

	//	cout << s << endl;

	//}

	//for (int i = 0; i < 50; i++)
	//{
	//	cout << i << " = " << mas[i] << endl;
	//}
	
//****************************************************************************************
// сортировка выбором
//****************************************************************************************

//Шаги алгоритма:
//
//находим номер минимального значения в текущем списке
//производим обмен этого значения со значением первой неотсортированной позиции (обмен не нужен, если минимальный элемент уже находится на данной позиции)
//теперь сортируем хвост списка, исключив из рассмотрения уже отсортированные элементы
//Для реализации устойчивости алгоритма необходимо в пункте 2 минимальный элемент непосредственно вставлять в первую неотсортированную позицию, не меняя порядок остальных элементов.

	//const int n = 5;

	//int Arr[n] = {3,2,0,5,3};

	//srand(time(NULL));

	//for (int k = 0; k < n; k++) // перебор элементов массива за исключ последнего
	//{

	//	Arr[k] = rand()%5;
	//	cout << Arr[k] << " ";
	//}

	//cout << endl;


	//for (int i = 0; i < n - 1; i++) // перебор элементов массива за исключ последнего
	//{
	//	int imin = i;

	//	// поиск индекса мин элемента относительно i-го
	//	// если таковой не найден то imin остается равен i
	//	for (int j = i + 1; j < n; j++)
	//	{
	//		if (Arr[j] < Arr[imin])
	//		{
	//			imin = j;
	//		}
	//	}

	//	cout << imin << " " << endl << endl;

	//	// меняем местами мин элемент относительно i-го с i-м элементом
	//	int temp = Arr[imin];
	//	Arr[imin] = Arr[i];
	//	Arr[i] = temp;

	//	for (int k = 0; k < n; k++) // перебор элементов массива за исключ последнего
	//	{
	//		cout << Arr[k] << " ";
	//	}

	//	cout << endl;

	//}

//****************************************************************************************
// сортировка вставкой
//****************************************************************************************

	//const int n = 5;

	//int Arr[n] = {7,5,4,3,1};

	//srand(time(NULL));

	//for (int k = 0; k < n; k++) // перебор элементов массива за исключ последнего
	//{

	//	Arr[k] = rand()%5;
	//	cout << Arr[k] << " ";
	//}

	//cout << endl;

	//for (int i = 1; i < n; i++)
	//{
	//	int j = i;
	//	int temp = Arr[j];

	//	//cout << "Arr[j - 1] = " << Arr[j - 1] << " temp = " << temp;
	//	//cout << endl;

	//	while ((j - 1) >= 0 && Arr[j - 1] > temp)
	//	{
	//		Arr[j] = Arr[j - 1];

	//						for (int k = 0; k < n; k++) // перебор элементов массива за исключ последнего
	//						{
	//							cout << Arr[k] << " ";
	//						}
	//						
	//						//cout << "Arr[j - 1] = " << Arr[j - 1] << " temp = " << temp;
	//						//
	//						cout << " while " << endl;


	//		j--;
	//	}
	//	Arr[j] = temp;

	//						for (int k = 0; k < n; k++) // перебор элементов массива за исключ последнего
	//						{
	//							cout << Arr[k] << " ";
	//						}
	//						cout << endl;


	//}


//****************************************************************************************
// быки и коровы
//****************************************************************************************

	//const int N = 2;

	//srand(time(NULL));

	//vector <int> randComb; 
	//vector <int> userComb;

	//int bulls = 0, cows = 0;

	//int x = 0;
	//int k = 0;

	//bool canFill = true;

	//while (k < N)
	//{
	//	x = rand(0,9);

	//	bool find = false;

	//	for (int i = 0; i < N; i++)
	//	{
	//		if (x == randComb[i])
	//		{
	//			find = true;		
	//			break;
	//		}
	//	}

	//	if (!find)
	//	{
	//		randComb[k] = x;
	//		k++;
	//	}
	//}

	//while(true)
	//{
	//	for (int i = 0; i < N; i++)
	//	{
	//		cin >> userComb[i];
	//	}

	//	// подсчёт быков
	//	for (int i = 0; i < N; i++)
	//	{
	//		if (randComb[i] == userComb[i])
	//			bulls++;
	//	}

	//	// подсчёт коров
	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < N; j++)
	//		{
	//			if (randComb[j] == userComb[i] && j != i)
	//				cows++;
	//		}
	//	}

	//	cout << "Быки = " << bulls << endl;
	//	cout << "Коровы = " << cows << endl;

	//	if (bulls == N)
	//	{
	//		cout << "Угадал" << endl;
	//		for (int i = 0; i < N; i++)
	//		{
	//			cout << randComb[i] << " ";
	//		}
	//		break;
	//	}

	//	bulls = 0;
	//	cows = 0;
	//}

//****************************************************************************************
// список файлов в папке, атрибуты файлов
// crt_find.c 
// This program uses the 32-bit _find functions to print 
// a list of all files (and their attributes) with a .C extension 
// in the current directory. 
//****************************************************************************************
//#include <stdio.h> 
//#include <stdlib.h> 
//#include <io.h> 
//#include <time.h> 

	//struct _finddata_t c_file; 
	//intptr_t hFile; 
	//// Find first file in current directory 
	//if( (hFile = _findfirst( "c:\\*.txt", &c_file )) == -1L ) 
	//	cout << "No *.c files in current directory!\n"; 
	//else 
	//{ 
	//	//cout << "Listing of files\n\n"; 
	//	//cout << "RDO HID SYS ARC  FILE         DATE %25c SIZE\n", ' ' ); 
	//	//cout << "--- --- --- ---  ----         ---- %25c ----\n", ' ' ); 
	//	do { 
	//		char buffer[30]; 
	//		cout << c_file.name << endl;
	//		//printf( ( c_file.attrib & _A_RDONLY ) ? " Y  " : " N  " ); 
	//		//printf( ( c_file.attrib & _A_HIDDEN ) ? " Y  " : " N  " ); 
	//		//printf( ( c_file.attrib & _A_SYSTEM ) ? " Y  " : " N  " ); 
	//		//printf( ( c_file.attrib & _A_ARCH )   ? " Y  " : " N  " ); 
	//		//ctime_s( buffer, _countof(buffer), &c_file.time_write ); 
	//		//printf( " %-12s %.24s  %9ld\n", c_file.name, buffer, c_file.size ); */
	//	} while( _findnext( hFile, &c_file ) == 0 ); 
	//	_findclose( hFile ); 
	//}
//****************************************************************************************
// удаление лишних пробелов
//****************************************************************************************
	//string s;
	//	cout << "Введите строку:\n";
	//	//getline(cin, s);
	//	s = "sd    sdfsd";
	//	for (int i = 0; i < s.size(); i++) {
	//		if (s[i] == ' ' && s[i+1] == ' ') {
	//			for (int j = i; j < s.size(); j++) {
	//				const int a = j;
	//				if (s[j] != 0) {
	//					int b = j;
	//					s.erase(a, b - a + 1);
	//					i = a + 1;
	//                    
	// 
	//				}
	//			}
	//		}
	//	}

//****************************************************************************************
// сортировка выбором
//****************************************************************************************

 //7 5 3 1 8
//^
 //1 5 3 7 8
 //1 3 5 7 8

	//8 @1 3 5 7@
	//1 8 @3 5 7@
	//1 3 8 @5 7@
	//1 2 5 8 @7@

	//0 8 3 1 2
	//^
	//0 8 3 1 2
	//  ^
	//0 1 3 8 2
	//  ^
	//0 1 2 8 3
	//    ^
	//0 1 2 8 3
	//      ^
	//0 1 2 3 8
	//        ^

	//const int N = 5;
	//int mas[N] = {0,8,3,1,2};
	//int tmp;

	//for(int i = 0; i < N; i++)
	//{
	//	cout << mas[i] << " ";
	//}
	//cout << endl;

	//for(int i = 0; i < N-1; i++) 
 //   {
 //       int min_idx = i;

 //       for (int j = i + 1; j < N; j++)
 //       {
 //           if (mas[j] < mas[min_idx])
 //           {
 //               min_idx = j;
 //           }
 //       }

 //       if (min_idx != i)
 //       {
	//		tmp = mas[i];
	//		mas[i] = mas[min_idx];
	//		mas[min_idx] = tmp;
 //       }

 // 		for(int i = 0; i < N; i++) // внутренний цикл прохода
	//	{
	//		cout << mas[i] << " ";
	//	}
	//	cout << endl;
 // }

// обясняем алгоритм на примере
// поиск индекса минимума массиве
// если найден мин отличный от самого элемента сменка и тем на который указывает указатель
// после первого прохода мин гарантированно будет на первом месте
// почему проходв четыре обратить внимание
	//переходим к коду
	//внешний цикл переставляет указатель на элемент перем i, 
	//внутрениий ищет минимум
// почему это услович if (min_idx != i)
// объяснить почему j+1 for (int j = i + 1; j < N; j++) оптимизация небольшая если повторяется милионы раз 
// то всё имеет значение

//****************************************************************************************
// Зёрна на шахматной доске.
//****************************************************************************************

	//unsigned long long int x = 1;

	//unsigned long long int s = 0;

	//for(int i = 0; i < 64; i++) // внутренний цикл прохода
	//{
	//	s = s + x;
	//	cout << s << endl;
	//	x = x*2;
	//}

//****************************************************************************************
// Труба и лягушка
//****************************************************************************************


	//double x = 1;
	//double s = 0;

	////float x = 1;
	////float s = 0;

	//for(int i = 0; i < 3; i++) // внутренний цикл прохода
	//{
	//	x = x/2;
	//	s = s + x;
	//	//cout << left /*<< setw(16)*/ << fixed << setprecision(18) << s << endl;
	//	cout << setprecision(18) << s << endl;
	//	//cout << s << endl;
	//}

//****************************************************************************************
// Число пи 
//****************************************************************************************

	//float x = 1;
	//float sign = 1;
	//float s = 4;

	//int n = 3;

	//for(int i = 0; i < n-1; i++) // внутренний цикл прохода
	//{
	//	x = x + 2;
	//	sign = -sign;
	//	s = s + sign * 4 / x;
	//}

	//cout << s << endl;

//****************************************************************************************
// Шахматы пешки
//****************************************************************************************


//int a , b, c, d;
//
//cin >> a >> b >> c >> d;
//
//if (b == d)
//{
//	cout << "Пешки на одном ряду";
//}

//****************************************************************************************
// 
//****************************************************************************************


//****************************************************************************************
// светофор
//****************************************************************************************

//int x;
//cin >> x;
//switch(x)
//{
//	case 0:
//		cout << "красный";
//	break;
//	case 1:
//		cout << "желтый";
//	break;
//	case 2:
//		cout << "зеленый";
//	break;
//	default:
//		cout << "Ошибка ввода";
//}	


//****************************************************************************************
// обработчик нажатия клавиш
//****************************************************************************************

//char ch = 0;
//ch = _getch();
//cout << ch;
//
//
//switch(ch)
//{
//	case 'd':
//		cout << "красный";
//	break;
//	case 'a':
//		cout << "желтый";
//	break;
//	case 'f':
//		cout << "зеленый";
//	break;
//}	

//****************************************************************************************
// псевдо параллельность
//****************************************************************************************


//	int d1 = 0, d2 = 0;
//	int x1 = 0, y1 = 0;
//	int x2 = 0, y2 = 5;
//
//	int f = 0;
//
//	while(true)
//	{
//		gotoxy(x1,y1);
//		cout << d1;
//		
//		gotoxy(x2,y2);
//		cout << d2;
//
//		x1++;
//		x2++;
//
//
//		//d1++;
//
//		//if (f == 0)
//		//{
//		//	d2++;
//		//}
//
//		f = !f;
//
//
//		Sleep(100);
//		
//	}
//
//int c1 = 0, c2 = 0;
//
//for (int i = 0; i < 100; i++)
//{
//	c1++;
//	c2++;
//}

//****************************************************************************************
// stack стек Работа со стеком
//****************************************************************************************
	
	//func1();

	//stack <int> stk;

	//stk.push(5);
	//stk.push(3);
	//stk.push(4);

	//while (!stk.empty())
	//{
	//	cout << stk.top();
	//	stk.pop();
	//
	//}

	//string s = "01010";

	//stk.push(s[0]);

	//for (int i = 1; i < s.length(); i++)
	//{
	//	if (stk.top() != s[i])
	//	{
	//		stk.push(s[i]);
	//	}
	//	else
	//	{
	//		cout << "error";
	//		break;
	//	}
	//}


	//while (!stk.empty())
	//{
	//	cout << stk.top();
	//	stk.pop();
	//
	//}

//
//cout << "   *   ";
//cout << "  ***  ";
//cout << " ***** ";
//cout << "   *   ";
//cout << "   *   ";
//cout << "   *   ";
//
//const float PI = 3.14;
//
//short x;

	//cout << sum(1,2);

	//int x = 0;

	//while(true)
	//{
	//	cout << x + 1;
	//	x = (x + 1) % 4;
	//	Sleep(100);
	//}



	//int x = 0;
	//cin >> x;
	//if (x == 5)
	//{
	//	cout << " Число равно  5" << endl;
	//}
	//else 
	//{
	//	cout << "Число не равно 5" << endl;
	//}

//****************************************************************************************
// callback
//****************************************************************************************

    //int arr[5] = {0,-1,2,3,5};
 
    //cout<<"Max elem: "<<my_function(arr,5,max_)<<endl;
    //cout<<"Min elem: "<<my_function(arr,5,min_)<<endl;
 
//****************************************************************************************
// очередь
//****************************************************************************************

	//deque <int> deq;
	//
	//deq.push_back(2);
	//deq.push_front(3);
	//deq.push_back(1);


	//cout << deq[3];


  //  try
  //  {
		//cout << deq.at(3);
  //  }
  //  catch (out_of_range e)
  //  {
  //      cout << "Incorrect index" << endl;
  //  }

	//for (deque <int> :: iterator  it = deq.begin(); it != deq.end(); it++)
	//{
	//	cout << *it << " ";
	//}

	//deq.pop_front();

	////cout << deq.back();
	//
	//for(int i = 0; i < deq.size(); i++) 
	//{
	//	cout << deq[i];
	//}




	//cout << deq.front();
	//cout << deq.back();
	//cout << deq.empty(); 

//****************************************************************************************
// Буфер клавиатуры
//****************************************************************************************

	//queue <char> que;

	//char ch = 0;

	//while(true) // главный цикл 
	//{
	//	while (!kbhit()) // цикл будет работать пока не нажата любая клавиша
	//	{
	//		if (!que.empty())
	//		{
	//			ch = que.front();
	//			que.pop();
	//			cout << ch;
	//		}
	//		
	//		Sleep(1000);
	//	}
	//	
	//	ch = _getch();

	//	if (que.size() < 10)
	//	{
	//		que.push(ch);
	//	}

	//	system("cls");

	//	cout << "size = " << que.size() << endl;

	//}

//****************************************************************************************
// Пока не чётный
//****************************************************************************************

	//deque <int> deq;


	//for(int i = 0; i < 10; i++) 
	//{
	//	deq.push_back(rand(1,10));
	//}


	//for(int i = 0; i < deq.size(); i++) 
	//{
	//	cout << deq[i] << " ";
	//}
	//cout << endl;

	//while (!deq.empty() && deq.front() % 2 == 0)
	//{
	//	deq.pop_front();
	//}

	//while (!deq.empty() && deq.back() % 2 == 0)
	//{
	//	deq.pop_back();
	//}

	//for(int i = 0; i < deq.size(); i++) 
	//{
	//	cout << deq[i] << " ";
	//}

	//cout << endl;


//****************************************************************************************
// заливка
//****************************************************************************************

//алгоритм заливки
//есть контур фигуры очерченой нулями
//нужно заполнить внутренность нулями


//	const int N = 6;
//
//int mas[N][N] = 
//{
//{0,1,1,0,0,0},
//{1,0,0,1,1,0},
//{0,1,0,0,0,1},
//{0,1,0,0,0,1},
//{0,1,0,0,1,0},
//{0,0,1,1,0,0}
//};
//
//	for(int i=0; i < N; i++)
//	{
//		for (int j=0; j < N; j++)
//		{
//			if (mas [i][j] == 0)
//				cout <<	" ";
//			else
//				cout <<	mas [i][j];
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//
//	
//	int x = 0;
//	int y = 0;
//
//	queue <SPoint> stk;
//
//
//	SPoint p;
//	p.x = 3;
//	p.y = 3;
//
//	stk.push(p);
//
//	while(!stk.empty())
//	{
//		x = stk.front().x;
//		y = stk.front().y;
//
//		mas[x][y] = 1;
//
//		stk.pop();
//
//
//		if (mas[x+1][y] == 0)
//		{
//			mas[x+1][y] = 1;
//			p.x = x + 1;
//			p.y = y;
//			stk.push(p);
//		}
//
//		if (mas[x-1][y] == 0)
//		{
//			mas[x-1][y] = 1;
//			p.x = x - 1;
//			p.y = y;
//			stk.push(p);
//		}
//
//		if (mas[x][y+1] == 0)
//		{
//			mas[x][y+1] = 1;
//
//			p.x = x;
//			p.y = y + 1;
//			stk.push(p);
//
//		}
//
//		if (mas[x][y-1] == 0)
//		{
//			mas[x][y-1] = 1;
//			p.x = x;
//			p.y = y - 1;
//			stk.push(p);
//
//		}
//	}
//
//
//	for(int i=0; i < N; i++)
//	{
//		for (int j=0; j < N; j++)
//		{
//			if (mas [i][j] == 0)
//				cout <<	" ";
//			else
//				cout <<	mas [i][j];
//		}
//		cout<<endl;
//	}
//	cout<<endl;

//****************************************************************************************
// Заполните двумерный массив следующим образом
//****************************************************************************************

	//const int N = 6;
	//int mas[N][N] = {0};
	//int k = 0;
	//for(int i=0; i < N; i++)
	//{
	//	k = i+1;
	//	for (int j=0; j < N; j++)
	//	{
	//		if (k >= 7)
	//		{
	//			k = 1;
	//		}
	//		mas [i][j] = k;
	//		k++;
	//	}
	//}

	//for(int i=0; i < N; i++)
	//{
	//	for (int j=0; j < N; j++)
	//	{
	//		if (mas [i][j] == 0)
	//			cout <<	"-";
	//		else
	//			cout <<	mas [i][j];
	//	}
	//	cout<<endl;
	//}

//****************************************************************************************
// крестики нолики на большом поле 413.	Пять подряд
//****************************************************************************************

	//const int N = 10;

	//int mas[N][N] = {
	//				{0,0,0,0,2,0,0,0,0,0},
	//				{0,0,0,2,0,0,2,0,0,0},
	//				{0,2,2,2,2,2,0,2,2,2},
	//				{0,2,0,0,2,0,0,0,0,2},
	//				{2,0,0,0,0,2,0,0,0,2},
	//				{0,0,2,0,0,2,0,0,2,2},
	//				{0,0,0,0,0,2,0,2,0,2},
	//				{0,0,0,0,0,0,2,0,0,0},
	//				{0,0,0,0,0,2,0,0,0,0},
	//				{0,0,0,0,0,2,2,2,2,0}
	//				};

	//for(int i=0; i < N; i++)
	//{
	//	for (int j=0; j < N; j++)
	//	{
	//		if (mas [i][j] == 0)
	//			cout <<	"-";
	//		else
	//			cout <<	mas [i][j];
	//	}
	//	cout<<endl;
	//}
	//cout<<endl;

	//for(int i=0; i < N; i++)
	//{
	//	int kr = 0;
	//	for (int j=0; j < N; j++)
	//	{
	//		if (mas[i][j] == 2)
	//		{
	//			kr++;
	//		}
	//		else
	//		{
	//			kr = 0;
	//		}
	//		if (kr == 5)
	//		{
	//			cout << "Крестики" << endl;
	//		}
	//	}
	//}

	//
	//for(int i = 0; i < N; i++)
	//{
	//	int kr = 0;

	//	for (int j = 0; j < N; j++)
	//	{
	//		if (mas[j][i] == 2)
	//		{
	//			kr++;
	//		}
	//		else
	//		{
	//			kr = 0;
	//		}
	//		if (kr == 5)
	//		{
	//			cout << "Крестики" << endl;
	//		}
	//	}
	//}
	//cout<<endl;

	//// верхняя половина 
	////        * * * * * *
	////      * * * * * * 
	////    * * * * * *
	////  * * * * * *
	////* * * * * *
	////* * * * * 
	////* * * * 
	////* * * 
	////* * 
	////*  

	//// начинаем с 4 так как начиная с этой диагонали может поместиться 5
	//for(int i = 4; i < N; i++)
	//{
	//	int kr = 0;
	//	for (int j=0; j < i+1; j++)
	//	{
	//		cout << i-j << " " << j << "   ";

	//		if (mas[i-j][j] == 2)
	//		{
	//			kr++;
	//		}
	//		else
	//		{
	//			kr = 0;
	//		}
	//		if (kr == 5)
	//		{
	//			cout << "Крестики" << endl;
	//		}
	//	}
	//	cout << endl;
	//}

	//cout << endl;
	//// нижняя половина 
	////                  *
	////                * *
	////              * * *
	////            * * * *
	////          * * * * *
	////        * * * * * 
	////      * * * * * 
	////    * * * * * 
	////  * * * * * 
	//for(int i=1; i < N-4; i++)
	//{
	//	int kr = 0;

	//	for (int j=0; j < N-i; j++)
	//	{
	//		cout << N-1-j << " " << j+i << "   ";

	//		if (mas[N-1-j][j+i] == 2)
	//		{
	//			kr++;
	//		}
	//		else
	//		{
	//			kr = 0;
	//		}
	//		if (kr == 5)
	//		{
	//			cout << "Крестики";
	//		}
	//	}
	//	cout << endl;
	//}

//****************************************************************************************
// волновой алгоритм
//****************************************************************************************

	//const int N = 12;

	//int mas[N][N] = {
	//				{1,1,1,1,1,1,1,1,1,1,1,1},
	//				{1,0,0,1,0,0,0,0,0,0,0,1},
	//				{1,0,0,1,0,0,0,1,0,0,0,1},
	//				{1,0,0,1,1,1,1,1,0,1,1,1},
	//				{1,0,0,1,0,1,0,0,0,0,0,1},
	//				{1,0,0,0,0,0,0,0,0,0,0,1},
	//				{1,0,0,1,1,1,1,0,0,1,0,1},
	//				{1,0,0,0,0,0,0,0,1,1,0,1},
	//				{1,0,0,0,1,1,1,0,0,0,0,1},
	//				{1,0,0,0,1,0,0,0,0,0,0,1},
	//				{1,0,0,0,1,0,1,0,0,0,0,1},
	//				{1,1,1,1,1,1,1,1,1,1,1,1} 
	//				};

	//int vol[N][N] = {
	//				{1,1,1,1,1,1,1,1,1,1,1,1},
	//				{1,0,0,0,0,0,0,0,0,0,0,1},
	//				{1,0,0,0,0,0,0,0,0,0,0,1},
	//				{1,0,0,0,0,0,0,0,0,0,0,1},
	//				{1,0,0,0,0,0,0,0,0,0,0,1},
	//				{1,0,0,0,0,0,0,0,0,0,0,1},
	//				{1,0,0,0,0,0,0,0,0,0,0,1},
	//				{1,0,0,0,0,0,0,0,0,0,0,1},
	//				{1,0,0,0,0,0,0,0,0,0,0,1},
	//				{1,0,0,0,0,0,0,0,0,0,0,1},
	//				{1,0,0,0,0,0,0,0,0,0,0,1},
	//				{1,1,1,1,1,1,1,1,1,1,1,1} 
	//				};


	//for(int i=0; i < N; i++)
	//{
	//	for (int j=0; j < N; j++)
	//	{
	//		if (mas [j][i] == 0)
	//			cout <<	" ";
	//		else
	//			cout <<	mas [j][i];
	//	}
	//	cout<<endl;
	//}
	//cout<<endl;

	//int x1 = 10, y1 = 9;
	//int x2 = 9, y2 = 10;

	//gotoxy(x1,y1);
	//cout << 'X';

	//vector <SVolna> deq;

	//SVolna v;

	//v.x = x1;
	//v.y = y1;
	//v.k = 1;

	//deq.push_back(v);

	//vol[x1][y1] = 1;

	//int i = 0;

	//int k = 1;
	//int x = x1;
	//int y = y1;

	//bool find = false;

	//do
	//{
	//	x = deq[i].x;
	//	y = deq[i].y;
	//	k = deq[i].k;

	//	if (mas[x+1][y] == 0 && vol[x+1][y] == 0)
	//	{
	//		vol[x+1][y] = k + 1;

	//		if (x+1 == x2 && y == y2)
	//		{
	//			find = true;
	//			break;		
	//		}

	//		v.x = x + 1;
	//		v.y = y;
	//		v.k = k + 1;

	//		deq.push_back(v);
	//	}

	//	if (mas[x-1][y] == 0 && vol[x-1][y] == 0)
	//	{
	//		vol[x-1][y] = k + 1;

	//		if (x-1 == x2 && y == y2)
	//		{
	//			find = true;
	//			break;		
	//		}

	//		v.x = x - 1;
	//		v.y = y;
	//		v.k = k + 1;

	//		deq.push_back(v);
	//	}

	//	if (mas[x][y+1] == 0 && vol[x][y+1] == 0)
	//	{
	//		vol[x][y+1] = k + 1;

	//		if (x == x2 && y+1 == y2)
	//		{
	//			find = true;
	//			break;		
	//		}

	//		v.x = x;
	//		v.y = y + 1;
	//		v.k = k + 1;

	//		deq.push_back(v);
	//	}

	//	if (mas[x][y-1] == 0 && vol[x][y-1] == 0)
	//	{
	//		vol[x][y-1] = k + 1;

	//		if (x == x2 && y-1 == y2)
	//		{
	//			find = true;
	//			break;		
	//		}

	//		v.x = x;
	//		v.y = y - 1;
	//		v.k = k + 1;

	//		deq.push_back(v);
	//	}

	//	i++;

	//	//gotoxy(0,0);

	//	//for(int i=0; i < N; i++)
	//	//{
	//	//	for (int j=0; j < N; j++)
	//	//	{
	//	//		if (mas[j][i] == 0)
	//	//		{
	//	//			if (vol[j][i] == 0)
	//	//				cout <<	" ";
	//	//			else
	//	//				cout <<	vol[j][i]%10;
	//	//		}
	//	//		else
	//	//		{
	//	//			cout <<	mas[j][i];
	//	//		}
	//	//	}
	//	//	cout<<endl;
	//	//}

	//	//gotoxy(x2,y2);
	//	//_getch();

	//} while (i != deq.size()-1);

	//gotoxy(0,15);
	//if (find)
	//{
	//	cout << "find";
	//}
	//else
	//{
	//	cout << "not find";
	//}

//****************************************************************************************
// сортировка вставками
//****************************************************************************************

	//const int N = 5;

	//int mas[N] = {9,8,3,4,7};


	//for(int i = 0; i < N; i++)
	//{
	//	cout << mas[i] << " " ;
	//}
	//cout << endl;


	//for (int i = 1; i < N; i++) 
	//{
	//	int key = mas[i];
	//	int j = i-1;

	//	while (j >= 0 && mas[j] > key)
	//	{
	//		mas[j + 1] = mas[j];
	//		mas[j] = key;
	//		j--;
	//	}
	//}


	//for(int k = 0; k < N; k++)
	//{
	//	cout << mas[k] << " ";
	//}
	//cout << endl;



//****************************************************************************************
// Близкий по величине
//****************************************************************************************

	//const int N = 5;
	//int mas[N] = {1,3,4,3,6}; 


	//int x = 7;
	//int delta = 0;
	//int delta_min = 9999;
	//int idx = 0;

	//for(int i=0; i<N; i++)
	//{
	//	cout << mas[i] << " ";
	//}

	//for(int i=0; i<N; i++)
	//{
	//	delta = abs(mas[i] - x);

	//	if (delta_min > delta)
	//	{
	//		delta_min = delta;
	//		idx = i;
	//	}
	//}

	//cout << endl << mas[idx];

//****************************************************************************************
// Треугольник пустотелый
//****************************************************************************************

	//int n;

 //   cout << "Введите высоту треугольника: ";
 //   cin >> n;
 //
 //   for (int i = 1; i <= n; i++)
 //   {
 //       for (int j = 1; j <= n * 2; j++)
 //       {
 //           if (j == ((n + 1) - (i - 1)) || j == ((n + 1) + (i - 1)))
 //               cout << '*';
 //           else
 //               if (i == n && j > 1)
 //                   cout << '*';
 //               else
 //                   cout << ' ';
 //       }
 //
 //       cout << endl;
 //   }

//****************************************************************************************
// Алгоритм Брезенхема линия
//****************************************************************************************

	//float angle = 360/60; //Узнаем угол для одной секунды
 //   float step = 360/angle-1; //Количество повторений для цикла
	//
	//O.x=0;
	//O.y=0;
	//A.x=5;
	//A.y=5;
	////O.x=0;
	////O.y=0;
	////A.x=4;
	////A.y=0;

	////line3(1,1,50,20);

	////BresenhamLine(0,0,4,2);

	////getch();

	////BresenhamLine(40,10,40,20);
	////line2(1,1,5,2);

	////scale(0,0,0,5,0,2);
	////getch();

	////for (int i=0;i<step*20;i++)
	////{

	////	rotate(O.x,O.y,A.x,A.y,angle,1);
	////	Sleep(10);
	////	system("cls");
	////}

	//line(O.x,O.y,A.x,A.y);
	//getch();
	//scale(O.x,O.y,A.x,A.y,1,2);

//****************************************************************************************
// Список CList
//****************************************************************************************

	//CList <float> list;
	//CList <float> list2;

	//list.add(3.3);
	//list.add(4.3);
	//list.add(2.3);

	//list2 = list;

	//list.show();
	//list2.show();

	//list = list + list2;
	//list.show();

//****************************************************************************************
// Вывод массива на экран
//****************************************************************************************

	//int mas[3][5] = 
	//{
	//  {4, 7, 8, 3, 2}, 
	//  {9, 6, 1, 4, 3}, 
	//  {5, 5, 3, 2, 1}
	//};

	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		cout << mas[i][j] << " ";
	//	}
	//	cout << endl;
	//}

//****************************************************************************************
// Вывод массива на экран 2
//****************************************************************************************
	//int mas[3][5] = 
	//{
	//  {4, 7, 8, 3, 2}, 
	//  {9, 6, 1, 4, 3}, 
	//  {5, 5, 3, 2, 1}
	//};

	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		cout << mas[j][i] << " ";
	//	}
	//	cout << endl;
	//}
//****************************************************************************************
// Сумма строки, сумма столбца
//****************************************************************************************

	//int mas[3][5] = 
	//{
	//  {4, 7, 8, 3, 2}, 
	//  {9, 6, 1, 4, 3}, 
	//  {5, 5, 3, 2, 1}
	//};
	//int s = 0;
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		if (mas[i][j] < 10) 
	//			cout << " ";
	//		cout << mas[i][j] << " ";
	//		s += mas[i][j];
	//	}
	//	cout << " | "<< s << " " << endl;
	//	s = 0;
	//}
	//cout << "---------------" << endl;
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		s += mas[j][i];
	//	}

	//	if (s < 10) 
	//		cout << " ";

	//	cout << s << " ";
	//	s = 0;
	//}


//****************************************************************************************
// Стек перегрузка операций
//****************************************************************************************

	//CStack <float> stk;
	//CStack <float> stk2;

	//stk.add(3.3);
	//stk.add(4.3);
	//stk.add(2.3);

	//stk2.copyFrom(stk);

	////stk2 = stk;

	//stk.show();
	//stk2.show();

	//stk = stk + stk2;
	//stk.show();

//****************************************************************************************
// Заливка через winapi
//****************************************************************************************

	//POINT op;
	//
	//HWND hWnd=GetConsoleWindow();//Функция GetConsoleWindow извлекает дескриптор окна, используемый консолью, связанной с вызывающим процессом.
	//HDC hDC=GetDC(hWnd);//Функция GetDC извлекает дескриптор дисплейного контекста устройства (DC) для рабочей области заданного окна или для всего экрана.

	//SelectObject(hDC,GetStockObject(WHITE_PEN));

	//SelectObject(hDC,GetStockObject(WHITE_PEN));
	//SelectObject(hDC,GetStockObject(BLACK_BRUSH));

	//Rectangle(hDC, 120, 20, 520, 280);

	//int x = 150; 
	//int y = 100;

	//DWORD color;

	//stack <POINT> stk;

	//POINT p;

	//p.x = 150;
	//p.y = 100;

	//stk.push(p);

	//while(!stk.empty())
	//{
	//	x = stk.top().x;
	//	y = stk.top().y;

	//	stk.pop();

	//	SetPixel(hDC, x, y, RGB(255, 255, 0));

	//	color = GetPixel(hDC, x+1, y);
	//	if (color == 0)
	//	{
	//		SetPixel(hDC, x+1, y, RGB(255, 255, 0));
	//		p.x = x + 1;
	//		p.y = y;
	//		stk.push(p);
	//	}

	//	color = GetPixel(hDC, x-1, y);
	//	if (color == 0)
	//	{
	//		SetPixel(hDC, x-1, y, RGB(255, 255, 0));
	//		p.x = x - 1;
	//		p.y = y;
	//		stk.push(p);
	//	}

	//	color = GetPixel(hDC, x, y+1);
	//	if (color == 0)
	//	{
	//		SetPixel(hDC, x, y+1, RGB(255, 255, 0));
	//		p.x = x;
	//		p.y = y + 1;
	//		stk.push(p);
	//	}

	//	color = GetPixel(hDC, x, y-1);
	//	if (color == 0)
	//	{
	//		SetPixel(hDC, x, y-1, RGB(255, 255, 0));
	//		p.x = x;
	//		p.y = y - 1;
	//		stk.push(p);
	//	}
	//}
	//ReleaseDC(hWnd,hDC);

//****************************************************************************************
// Заполнение массива по спирали
//****************************************************************************************

	//int const N = 9 + 2;

	//int mas[N][N] = {0};

	//for (int i=0; i<N; i++) 
	//{
	//	for(int j=0; j<N; j++) 
	//	{
	//		if (i == 0 || i == N-1 || j == 0 || j == N-1)
	//			mas[i][j]=1;
	//	} 
	//}


	//int dir = 0;

	//int i = 1,j = 0, g = 1;

	//while(g <= ((N-2)*(N-2)))
	//{
	//	
	//	int ti = i;
	//	int tj = j;

	//	if (dir == 0)
	//		j++;
	//	else if (dir == 1)
	//		i++;
	//	else if (dir == 2)
	//		j--;
	//	else if (dir == 3)
	//		i--;

	//	if (mas[i][j] != 0)
	//	{
	//		// откат
	//		i = ti;
	//		j = tj;

	//		// смена направления
	//		dir = (dir + 1)%4;
	//	}
	//	else
	//	{
	//		mas[i][j] = g;
	//		g++;
	//	
	//	}
	//}


	//for (int i=1; i<N-1; i++) 
	//{
	//	for(int j=1; j<N-1; j++) 
	//	{
	//		if (mas[i][j] < 10)
	//		{
	//			cout << "  ";
	//			cout << mas[i][j];
	//		}
	//		else
	//			cout << " " << mas[i][j];
	//	} 
	//	cout << endl;
	//}
	//cout << endl;

//****************************************************************************************
// ассемблер доступ к элементу двумерного массива
//****************************************************************************************

	//const int N = 3;

	//int mas[N][N] = 
	//{ 
	//	{1,3,4},
	//	{2,200,1},
	//	{2,3,13}
	//};
 //   int i = 2, j = 2, x = 0;
 //   //cout << mas[i][j] << endl;

	//__asm
 //   {
	//	mov eax, N;
	//	mul i;
	//	add eax, j;
	//	lea ebx, mas;
	//	mov ecx, dword ptr[ ebx + eax * 4 ];
	//	mov x, ecx;
 //   }

 //   cout << x << endl;
//****************************************************************************************
// ассемблер увеличить на 2 элементы двумерного массива
//****************************************************************************************

	//const int N = 3;

	//int mas[N][N] = 
	//{ 
	//	{1,3,4},
	//	{2,200,1},
	//	{2,3,13}
	//};
 //   int i = 0, j = 0, x = 0;

	//__asm
 //   {
	//	xor edi, edi
	//	m2:
	//		xor esi, esi
	//		m1:
	//			mov eax, N;
	//			mul i;
	//			add eax, esi;
	//			lea ebx, mas;
	//			add dword ptr[ ebx + eax * 4 ], 2;
	//			inc esi;
	//			cmp esi, N;
	//		jnge m1
	//		inc i;
	//		inc edi;
	//		cmp edi, N;
	//	jnge m2
 //   }

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << mas[i][j] << " ";
	//	}
	//	cout << endl;
	//}


//****************************************************************************************
// ассемблер сложение вычитание
//****************************************************************************************

	//int a = 10;
	//__asm {
	//	ADD a, 10; // прибавляем к а 10
	//	SUB a, 2;  // вычитаем из a 2	
	//};

//****************************************************************************************
// ассемблер факториал
//****************************************************************************************

	//int a;
	//int f = 1;

	//a = 5;

	//__asm
	//{
	//xor esi, esi
	//mov esi, 1
	//mov eax, f

	//LOOP1:
	//	mul esi
	//	inc esi

	//	cmp esi,a
	//jng LOOP1

	//mov a,eax
	//}
	//cout << a << endl;

//****************************************************************************************
// ассемблер инкремент inc
//****************************************************************************************

  //short a=0;
  //__asm
  //{
  //mov ax, a
  //inc ax
  //inc ax
  //inc ax
  //mov a, ax
  //}

//****************************************************************************************
// ассемблер доступ к двумерногму массиву
//****************************************************************************************


				//__asm
			 //   {
				//	xor edi, edi
				//	m2:
				//		xor esi, esi
				//		m1:

				//			mov eax, N;
				//			mul i;
				//			add eax, esi;
				//			lea ebx, mas;
				//			mov ecx, dword ptr[ ebx + eax * 4 ];//mas[i][k]

				//			mov eax, N;
				//			mul k;
				//			add eax, edi;
				//			lea ebx, mas;
				//			mov eax, dword ptr[ ebx + eax * 4 ];//mas[k][i]

				//			cmp eax, ecx
				//			jne 

				//			inc k;
				//			inc esi;

				//			cmp esi, N;
				//		jnge m1
				//		inc i;
				//		inc edi;
				//		mov k,0;
				//		cmp edi, N;
				//	jnge m2
			 //   }

//****************************************************************************************
// Елизавета чтение файла асм 1
//****************************************************************************************

	//ifstream file ("r:\\matrix.txt");

	//int N = 0;

	//int mas[3][3];

	//int x;

	//if (file.is_open())
	//{
	//	file >> N;

	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < N; j++)
	//		{
	//			file >> x;
	//			mas[i][j] = x;
	//			cout << mas[i][j] << " ";

	//		
	//		}
	//		cout << endl;
	//	}

	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < N; j++)
	//		{
	//			int equal = 1;

	//			//for (int k = 0; k < N; k++)
	//			//{
	//			//	if (mas[i][k] != mas[k][j])
	//			//	{
	//			//		equal = 0;
	//			//		break;
	//			//	}
	//			//}

	//			//int k = 0;

	//			__asm
	//		    {

	//				xor esi, esi
	//				m1:

	//					mov eax, N;// eax - 32 битный регистр
	//					mul i; // умножение на i того что находиться в eax
	//					add eax, esi;
	//					lea ebx, mas;//получение смещения массива
	//					mov ecx, dword ptr[ ebx + eax * 4 ];//mas[i][k] - 

	//					mov eax, N;
	//					mul esi;
	//					add eax, j;
	//					lea ebx, mas;
	//					mov eax, dword ptr[ ebx + eax * 4 ];//mas[k][i]

	//					cmp eax, ecx
	//					jne resetFlag;// Перейти, если не равно  

	//					inc esi;

	//					cmp esi, N;
	//				jnge m1
	//				jmp exit0;
	//				resetFlag:
	//					mov equal,0;
	//				exit0:
	//		    }

	//			if (equal == 1)
	//			{
	//				cout << i << " " << j;

	//				ofstream file;
	//				file.open("r:\\test1.txt", ios::app);
	//				if (!file.is_open())
	//				{
	//					cout<<"Файл не открыт. Программа завершена.\n";
	//					system("pause");
	//					return 0;
	//				} 
	//				else
	//				{
	//					for (int i = 0; i < N; i++)
	//					{
	//						for (int j = 0; j < N; j++)
	//						{
	//							file << mas[i][j] << " ";
	//						}
	//						file << endl;
	//					}
	//					file << i << " " << j;
	//					file.close();
	//				}

	//			}


	//		}
	//		cout << endl;
	//	}

	//	file.close();
	//}
	//else cout << "Unable to open file";

//****************************************************************************************
// Елизавета чтение + динамический массив не доделал
//****************************************************************************************

	//ifstream file ("r:\\matrix.txt");

	//int mas[3][3];

	//int N;
	//int x;

	//if (file.is_open())
	//{
	//	file >> N;

	//	//int **mas = new int *[N];
	// //
	//	//for (int i = 0; i < N; i++)
	//	//	mas[i] = new int [N];
	// 

	// 


	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < N; j++)
	//		{
	//			file >> x;
	//			mas[i][j] = x;

	//			x = mas[i][j];

	//			cout << mas[i][j] << " ";

	//		
	//		}
	//		cout << endl;
	//	}

	//	for (int i = 0; i < N; i++)
	//	{
	//		for (int j = 0; j < N; j++)
	//		{
	//			int equal = 1;

	//			//for (int k = 0; k < N; k++)
	//			//{

	//			//	//i = mas[i][k];
	//			//	//i = mas[k][j];

	//			//	if (mas[i][k] != mas[k][j])
	//			//	{
	//			//		equal = 0;
	//			//		break;
	//			//	}
	//			//}

	//			int k = 0;

	//			__asm
	//		    {

	//				xor esi, esi
	//				m1:

	//					mov eax, N;
	//					mul i;
	//					add eax, esi;
	//					lea ebx, mas;
	//					mov ecx, dword ptr[ ebx + eax * 4 ];//mas[i][k]

	//					//mov         eax,dword ptr [i] 
	//					//mov         ecx,dword ptr [mas] 
	//					//mov         edx,dword ptr [ecx+eax*4] 
	//					//mov         eax,dword ptr [k] 
	//					//mov         eax,dword ptr [edx+eax*4] 

	//					//mov         eax,dword ptr [k] 
	//					//mov         ecx,dword ptr [mas] 
	//					//mov         edx,dword ptr [ecx+eax*4] 
	//					//mov         eax,dword ptr [j] 
	//					//mov         ecx,dword ptr [edx+eax*4] 
	//


	//					mov eax, N;
	//					mul esi;
	//					add eax, j;
	//					lea ebx, mas;
	//					mov eax, dword ptr[ ebx + eax * 4 ];//mas[k][i]

	//					cmp eax, ecx
	//					jne resetFlag;

	//					inc esi;

	//					cmp esi, N;
	//				jnge m1
	//				jmp exit0;
	//			resetFlag:
	//				mov equal,0;
	//			exit0:
	//				//inc i;
	//				//inc edi;
	//				//mov k,0;
	//				//cmp edi, N;

	//		    }
	//			//__asm
	//		 //   {
	//			//	xor edi, edi
	//			//	m2:
	//			//		xor esi, esi
	//			//		m1:

	//			//			mov eax, N;
	//			//			mul i;
	//			//			add eax, esi;
	//			//			lea ebx, mas;
	//			//			mov ecx, dword ptr[ ebx + eax * 4 ];//mas[i][k]

	//			//			mov eax, N;
	//			//			mul k;
	//			//			add eax, edi;
	//			//			lea ebx, mas;
	//			//			mov eax, dword ptr[ ebx + eax * 4 ];//mas[k][i]

	//			//			cmp eax, ecx
	//			//			jne 

	//			//			inc k;
	//			//			inc esi;

	//			//			cmp esi, N;
	//			//		jnge m1
	//			//		inc i;
	//			//		inc edi;
	//			//		mov k,0;
	//			//		cmp edi, N;
	//			//	jnge m2
	//		 //   }

	//			if (equal == 1)
	//			{
	//				cout << i << " " << j;
	//			}
	//		}
	//		cout << endl;
	//	}

	//	//for (int i = 0; i < N; i++)
	//	//	delete [] mas[i];
	// //
	//	//delete [] mas;


	//	file.close();
	//}
	//else cout << "Unable to open file";


//****************************************************************************************
// Округление
//****************************************************************************************

	//srand(time(0));
	//float x = 0;
	//x = rand() % 21 / 3.0;
	//cout << "" << x << endl;
	//cout << floor(x) << endl;
	//cout << ceil(x) << endl;

	//cout << "1. Создать" << endl;
	//cout << "2. Открыть" << endl;
	//cout << "3. Выход" << endl;

//****************************************************************************************
// Архиватор
//****************************************************************************************

	//string s = "aabbbbbbccc";
	//string s2 = "";

	//int d = 0;

	//for (int i = 0; i < s.length(); i++)
	//{
	//	char ch = s[i];

	//	while(ch == s[i] && i < s.length())
	//	{
	//		d++;
	//		i++;
	//	}

	//	s2 = s2 + ch + (char)(d+48);
	//	
	//	d = 1;
	//}

	//cout << s2;

//****************************************************************************************
// Пятнашки
//****************************************************************************************

	//const int COL = 3;
	//const int ROW = 3;

	//int mas[ROW][COL] = {0};

	//for (int i = 0; i < ROW; i++)
	//{
	//	for (int j = 0; j < COL; j++)
	//	{
	//		mas[i][j] = -1;			
	//	}
	//}

	//int x = 0;

	//for (int i = 0; i < ROW; i++)
	//{
	//	for (int j = 0; j < COL; j++)
	//	{
	//		x = rand() % (ROW * COL);			

	//		bool find = 0;

	//		for (int k = 0; k < ROW; k++)
	//		{
	//			for (int m = 0; m < COL; m++)
	//			{
	//				if (x == mas[k][m])
	//				{
	//					find = 1;
	//				}

	//			}
	//		}

	//		if (find == 0)
	//		{
	//			mas[i][j] = x;			
	//		}
	//		else
	//		{
	//			j--;
	//		}

	//	}
	//}

	//for (int i = 0; i < ROW; i++)
	//{
	//	for (int j = 0; j < COL; j++)
	//	{
	//		if (mas[i][j] == 0)
	//			cout << " ";
	//		else
	//			cout << mas[i][j];
	//	}
	//	cout << endl;
	//}

	//while (true)
 //   {
	//	int i = 0; 
	//	int j = 0; 

	//	if (getClickCoord(j,i))
	//	{
	//		if (mas[i][j+1] == 0)
	//		{
	//			int tmp = mas[i][j];
	//			mas[i][j] = mas[i][j+1];
	//			mas[i][j+1] = tmp;
	//		}

	//		else if (mas[i][j-1] == 0)
	//		{
	//			int tmp = mas[i][j];
	//			mas[i][j] = mas[i][j-1];
	//			mas[i][j-1] = tmp;
	//		}

	//		else if (mas[i+1][j] == 0)
	//		{
	//			int tmp = mas[i][j];
	//			mas[i][j] = mas[i+1][j];
	//			mas[i+1][j] = tmp;
	//		}

	//		else if (mas[i-1][j] == 0)
	//		{
	//			int tmp = mas[i][j];
	//			mas[i][j] = mas[i-1][j];
	//			mas[i-1][j] = tmp;
	//		}

	//		gotoxy(0,0);

	//		for (int i = 0; i < ROW; i++)
	//		{
	//			for (int j = 0; j < COL; j++)
	//			{
	//				if (mas[i][j] == 0)
	//					cout << " ";
	//				else
	//					cout << mas[i][j];
	//			}
	//			cout << endl;
	//		}
	//	}
	//}

//****************************************************************************************
// Функция вывода точки
//****************************************************************************************

	//SPoint p;

	//p.x = 0;
	//p.y = 5;

	//while (true)
	//{
	//	showPoint(p);
	//	Sleep(100);
	//	hidePoint(p);
	//	Sleep(100);
	//}

//****************************************************************************************
// Точка движется
//****************************************************************************************

	//SPoint p;

	//p.x = 0;
	//p.y = 5;

	//p.dir = 0;

	//while (true)
	//{
	//	for (int i = 0; i < 10; i++)
	//	{
	//		move(p);
	//		showPoint(p);
	//		Sleep(100);
	//		hidePoint(p);
	//	}
	//	p.dir = (p.dir + 1) % 4;
	//}

//****************************************************************************************
// Броуновское движение
//****************************************************************************************

	//SPoint p;

	//p.x = 60;
	//p.y = 15;

	//while (true)
	//{
	//	p.dir = rand()%4;
	//	move(p);
	//	showPoint(p);
	//	Sleep(100);
	//	hidePoint(p);
	//}

//****************************************************************************************
// Броуновское движение 2
//****************************************************************************************
	//const int n = 10;
	//SPoint p[n];
	//for (int i = 0; i < n; i++)
	//{
	//	p[i].x = 60;
	//	p[i].y = 15;
	//}
	//while (true)
	//{
	//	for (int i = 0; i < n; i++)
	//	{
	//		p[i].dir = rand()%4;
	//		move(p[i]);
	//		showPoint(p[i]);
	//	}
	//	Sleep(100);
	//	for (int i = 0; i < n; i++)
	//	{
	//		hidePoint(p[i]);
	//	}
	//}

//****************************************************************************************
// Расстояние между точками
//****************************************************************************************
	//const int n = 2;
	//SPoint p[n];

	//p[0].x = 5;
	//p[0].y = 5;

	//p[1].x = 11;
	//p[1].y = 11;

	//while (true)
	//{
	//	for (int i = 0; i < n; i++)
	//	{
	//		p[i].dir = rand()%4;
	//		move(p[i]);
	//		showPoint(p[i]);
	//	}
	//	if (distanceBetweenPoints(p[0], p[1]) < 7)
	//	{
	//		cout << distanceBetweenPoints(p[0], p[1]);
	//		break;
	//	}
	//	Sleep(100);
	//	for (int i = 0; i < n; i++)
	//	{
	//		hidePoint(p[i]);
	//	}
	//}

//****************************************************************************************
// Два бойца
//****************************************************************************************

	//SPlayer p1, p2;

	//p1.atack = 3;
	//p1.shild = 1;
	//p1.chanceHit = 50;
	//p1.hp = 100;

	//p2.atack = 2;
	//p2.shild = 1;
	//p2.chanceHit = 50;
	//p2.hp = 100;

	//int n = 1000;

	//while (true)
	//{

	//	cout << "Игрок 1 бьёт Игрока 2" << endl;
	//	Sleep(n);
	//	bool res = kick(p1,p2);
	//	if (res)
	//	{
	//		cout << "Игрок 1 попал " << endl;
	//		cout << "Жизнь игрока 2. hp = " << p2.hp << endl;
	//	}
	//	else
	//	{
	//		cout << "Игрок 1 промах " << endl;
	//	}

	//	getch();

	//	cout << "Игрок 2 бьёт Игрока 1" << endl;
	//	Sleep(n);
	//	res = kick(p2,p1);
	//	if (res)
	//	{
	//		cout << "Игрок 2 попал " << endl;
	//		cout << "Жизнь игрока 1. hp =  " << p1.hp << endl;
	//	}
	//	else
	//	{
	//		cout << "Игрок 2 промах " << endl;
	//	}

	//	getch();
	//}

//****************************************************************************************
// Замер времени
//****************************************************************************************

	//const int N = 100;

	//SYSTEMTIME st1;
	//SYSTEMTIME st2;

	//GetSystemTime(&st1);

	//for (int i = 0; i < N; i++)
	//{
	//	x = i*i;
	//}

	//GetSystemTime(&st2);

	//cout << st2.wMilliseconds - 

//****************************************************************************************
// Симулятор ассемблера применение стека 	Ассемблер
//****************************************************************************************

	//vector <SCommand> vec(11);
	//stack <int> stk;

	//int ax = 0;

	//vec[0].cmd = mov;  vec[0].val = 2;	
	//vec[1].cmd = add;  vec[1].val = 5;	
	//vec[2].cmd = mul;  vec[2].val = 3;
	//vec[3].cmd = call; vec[3].val = 5;
	//vec[4].cmd = end;  vec[4].val = 0;
	//vec[5].cmd = add;  vec[5].val = 10;
	//vec[6].cmd = add;  vec[6].val = 10;
	//vec[7].cmd = call; vec[7].val = 9;
	//vec[8].cmd = ret;  vec[8].val = 0;
	//vec[9].cmd = add;  vec[9].val = 1;
	//vec[10].cmd = ret;  vec[10].val = 0;

	//for (int i = 0; i < vec.size(); i++)
	//{
	//	switch(vec[i].cmd)
	//	{
	//		case mov:
	//			ax = vec[i].val;
	//		break;
	//		case add:
	//			ax = ax + vec[i].val;
	//		break;
	//		case mul:
	//			ax = ax * vec[i].val;
	//		break;
	//		case call:
	//			stk.push(i+1);
	//			i = vec[i].val-1;
	//		break;
	//		case ret:
	//			i = stk.top()-1;
	//			stk.pop();
	//		break;
	//		case end:
	//			i = vec.size();
	//		break;
	//	}
	//}

	//cout << ax << endl;

//****************************************************************************************
// map словарь ассоциативный массив
//****************************************************************************************

 //   map <int, int> mp;
 //   
 //   
	//int n = 5; 
	//
 //
 //   for (int i = 0; i < n; i++) 
	//{
 //       mp[rand(1, 100)] = i;  // добавляем новые элементы
 //   }
 //
	//mp[10] = 10;

	//for (map <int, int> :: iterator it = mp.begin(); it != mp.end(); it++) 
	//{  
 //       cout << " Ключ " << it->first << ", значение " << it->second << endl;
 //   }

	//cout << endl << mp.count(11);


	//int x = 7;

	//cout << x - (x / 3) * 3 ;

//****************************************************************************************
// граическая консоль
//****************************************************************************************

	//взято здесь http://www.cyberforum.ru/cpp-beginners/thread843217.html
	//print();
	//print();
	//print();


//****************************************************************************************
// Криптарифм
//****************************************************************************************
	
	//int s = 0;
	//int e = 0;
	//int n = 0;
	//int d = 0;

	//int m = 0;
	//int o = 0;
	//int r = 0;

	//int y = 0;

	//for(s = 0; s < 10; s++)
	//{
	//	for(e = 0; e < 10; e++)
	//	{
	//		for(n = 0; n < 10; n++)
	//		{
	//			for(d = 0; d < 10; d++)
	//			{
	//				for(m = 0; m < 10; m++)
	//				{
	//					for(o = 0; o < 10; o++)
	//					{
	//						for(r = 0; r < 10; r++)
	//						{
	//							for(y = 0; y < 10; y++)
	//							{
	//								if (s*1000 + e*100 + n*10 + d + m*1000 + o*100 + r*10 + e == m*10000 + o*1000 + n*100 + e*10 + y)
	//								{
	//									cout << s << e << n << d << "+" << m << o << r << e << " = " << m << o << n << e << y << endl;
	//									//cout << "!!!";
	//								}
	//							}
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	//int x = 0;
	//byVal(x);
	//cout << x;
//****************************************************************************************
// Все слова без рекурсии. Генерация всех слов. 
//****************************************************************************************
	
 //   // Initialize the slots to hold the current iteration value for each depth
	//int depth = 3;
 //   vector <int> slots;
 //   for (int i = 0; i < depth; i++)
 //   {
	//	slots.push_back(0);
 //   }

	//int max = 9;

 //   int index = 0;

	//bool exit = false;

 //   while (true)
 //   {
	//	for (int i = 0; i < slots.size(); i++)
	//	{
	//		cout << slots[i] << " ";
	//	}
	//	cout << endl;

	//	//увеличиваем число единиц
 //       slots[0]++;


	//	if (slots[0] == 8 && slots[1] == 8 && slots[2] == 7)
	//	{
	//		cout << "";
	//	}

 //       // пока число единиц максивально
 //       while (slots[index] == max)
 //       {
 //           // Overflow, we're done
 //           if (index == depth - 1)
 //           {
	//			exit = true;
 //               break;
 //           }

	//		// число единиц обнуляем
 //           slots[index] = 0;
	//		//переходим на десятки, сотни и тд.
	//		index++;
	//		// увеличиваем их на 1
 //           slots[index]++;

 //       }

 //       index = 0;

 //       if (exit)
 //       {
 //           break;
 //       }

 //   }

//****************************************************************************************
// Шифрация
//****************************************************************************************

	//ifstream file1("r:\\test1.txt");//создать input-file object тоесть файл ИЗ которого читать  
	//
	//if (!file1.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}

	//ofstream file2 ("r:\\test2.txt");
	//if (!file2.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}

	//string mas = "ХУТЭЦЙГРФЫНАЪСИЩПБВДМЗЖЕШЬЧЯКЮОЛЁ";
	////char mas[33];
	////mas[0] = 'Х';mas[1] = 'У';mas[2] = 'Т';mas[3] = 'Э';
	////mas[4] = 'Ц';mas[5] = 'Й';mas[6] = 'Г';mas[7] = 'Р';
	////mas[8] = 'Ф';mas[9] = 'Ы';mas[10] = 'Н';mas[11] = 'А';
	////mas[12] = 'Ъ';mas[13] = 'С';mas[14] = 'И';mas[15] = 'Щ';
	////mas[16] = 'П';mas[17] = 'Б';mas[18] = 'В';mas[19] = 'Д';
	////mas[20] = 'М';mas[21] = 'З';mas[22] = 'Ж';mas[23] = 'Е';
	////mas[24] = 'Ш';mas[25] = 'Ь';mas[26] = 'Ч';mas[27] = 'Я';
	////mas[28] = 'К';mas[29] = 'Ю';mas[30] = 'О';mas[31] = 'Л';
	////mas[32] = 'Ё';

	//char ch; 

	//int d = 0;
	//int p = 0;

	//while (file1.get(ch))
	//{
	//	cout << ch << " " << (int)ch << endl;
	//	if (ch == ' ')
	//		file2 << '*';
	//	else if ((int)ch == 10)
	//		file2 << '#';
	//	else
	//		file2 << mas[(int)ch+64];
	//	d++;

	//	if (d == 5)
	//	{
	//		p++;
	//		if (p == 5)
	//		{
	//			file2 << endl;
	//			p = 0;
	//		}
	//		else
	//			file2 << ' ';
	//		d = 0;
	//	}
	//}

	//file1.close();
	//file2.close();

//****************************************************************************************
// Дешифрация
//****************************************************************************************

	//ifstream file1("r:\\test2.txt");//создать input-file object тоесть файл ИЗ которого читать  
	//
	//if (!file1.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}

	//ofstream file2 ("r:\\test3.txt");
	//if (!file2.is_open())
	//{
	//	cout << "Unable to open file.\n";
	//	system("pause");
	//	return 0;
	//}

	//string mas = "ХУТЭЦЙГРФЫНАЪСИЩПБВДМЗЖЕШЬЧЯКЮОЛЁ";
	////mas[0] = 'Х';mas[1] = 'У';mas[2] = 'Т';mas[3] = 'Э';
	////mas[4] = 'Ц';mas[5] = 'Й';mas[6] = 'Г';mas[7] = 'Р';
	////mas[8] = 'Ф';mas[9] = 'Ы';mas[10] = 'Н';mas[11] = 'А';
	////mas[12] = 'Ъ';mas[13] = 'С';mas[14] = 'И';mas[15] = 'Щ';
	////mas[16] = 'П';mas[17] = 'Б';mas[18] = 'В';mas[19] = 'Д';
	////mas[20] = 'М';mas[21] = 'З';mas[22] = 'Ж';mas[23] = 'Е';
	////mas[24] = 'Ш';mas[25] = 'Ь';mas[26] = 'Ч';mas[27] = 'Я';
	////mas[28] = 'К';mas[29] = 'Ю';mas[30] = 'О';mas[31] = 'Л';
	////mas[32] = 'Ё';

	//char ch; 

	//int d = 0;
	//int p = 0;

	//while (file1.get(ch))
	//{
	//	if (ch == '*')
	//		file2 << ' ';
	//	else if (ch == 10)
	//		file2 << endl;
	//	else if (ch == ' ')
	//	{}//file2 << endl;
	//	else
	//	{
	//		for(int i = 0; i<33; i++)
	//		{
	//			if (mas[i] == ch)
	//			{
	//				file2 << (char)(i+128);
	//				break;
	//			}
	//		}

	//	}
	//}

	//file1.close();

//****************************************************************************************
// Таблица степеней двойки
//****************************************************************************************
	//file2.close();


	//int x = 0;

	//for (int i = 1; i <= 20; i++)
	//{
	//	x = pow(2.0, (double(i)));
	//	cout << i << " " << x << endl;
	//}


	//int x, y, z;
	//int c = 0;
	//cin >> x >> y >> z;

	//if (x == 2)
	//{
	//	c = c + 1;
	//}
	//if (y == 2)
	//{
	//	c = c + 1;
	//}
	//if (z == 2)
	//{
	//	c = c + 1;
	//}

	//cout << c;

//****************************************************************************************
// Квадраты чисел не превышающие n
//****************************************************************************************
	//int n = 8;
	//int x = 1;

	//while (x * x <= n)
	//{
	//	cout << x * x << "" << endl;
	//	x++;
	//}	

//****************************************************************************************
// Номер квадрата числа
//****************************************************************************************

	//int n = 8;
	//int x = 0;
	//bool f = 0;

	//while (x * x <= n)
	//{
	//	if (x * x == n)
	//	{
	//		f = 1;	
	//	}
	//	x++;
	//}	

	//if (f == 1)
	//{
	//	cout << x-1 << endl;
	//}
	//else
	//{
	//	cout << 0 << endl;
	//}

//****************************************************************************************
// Квадрат числа
//****************************************************************************************

	//int n = 4;
	//int x = 0;
	//bool f = 0;

	//while (x * x < n)
	//{
	//	x++;
	//}	

	//if (x * x == n)
	//{
	//	f = 1;	
	//}

	//cout << f;

//****************************************************************************************
// исключения
//****************************************************************************************

// И для пункта меню C/C++ ->Code Generation->Enable C++ Exceptions устанавливаем значение 
// Yes With SEH Exceptions (/EHa).

	//try
	//{ 
	//	int a=1;
	//	int b=0;
	//	//if(b==0)
	//	//{
	//	//	throw string("Деление на ноль");
	//	//}
	//	cout<<(a/b);
	//}
	//catch (...)
	//{
	//	cout << "sdfsdfdf" << endl;
	//}

	//Price & operator[](int n) 
	//{
	//	//if (n >= tsize)
	//	//	throw 123;

	//	if (n >= tsize)
	//		throw out_of_range("Vector::operator[]");
 //
	//	return mas[n];
	//}

	//try
	//{
	//	cout << p[5].getCost();
	//}
	//catch(int ex)
	//{
	//	cout << "Код ошибки: " << ex << " Выход за пределы массива" << endl;
	//
	//}
	//catch (out_of_range) 
	//{  
	//	cout<<"out_of_range\n";
 //   }
	//catch(...)
	//{
	//	cout<<"неопознанная ошибка\n";
	//}

	//CommonPrice(int n)
	//{
	//	tsize = 0;
	//	if (n < 0)
	//		throw length_error("length_error");

	//	mas = new Price[n];

	//	cout << "\nКонструктор \n";
	//}

	//try
	//{
	//	CommonPrice pp(-2);
	//}
	//catch(length_error)
	//{
	//	cout << "\length_error \n";
	//}

//****************************************************************************************
// сложение длинных чисел, длинная арифметика
//****************************************************************************************



//****************************************************************************************
// Целая часть. Определите целую часть вещественного числа
//****************************************************************************************
	
	//float x;

	//cin >> x;

	//int i = 0;

	//while (i < x)
	//{
	//	i++;
	//}

	//if (i > x)
	//	i--;

	//cout << i << " ";

//****************************************************************************************
// Квадратный корень. Определите целую квадратного корня для числа x
//****************************************************************************************
	
	//float x;

	//cin >> x;

	//int i = 0;

	//while (i*i < x)
	//{
	//	i++;
	//}

	//if (i*i > x)
	//	i--;

	//cout << i << " ";

//****************************************************************************************
// Быстрая сортировка
//****************************************************************************************

	//const int N = 4;
	////int mas[N] = {4, 9, 7, 6, 2, 3, 8};
	//int mas[N] = {4, 8, 3, 1};

	//qSortI(mas, 4);


	//for(int i = 0; i < N; i++) // внутренний цикл прохода
	//{
	//	cout << mas[i] << " ";
	//}

	//quickSortR(mas, N);
	//quickSort(mas, 0,N-1);
	//quicksort(mas, 0,N-1);











//****************************************************************************************
// Быстрая сортировка Ютуб Youtube
//****************************************************************************************

	//const int N = 4;
	////int mas[N] = {4, 9, 7, 6, 2, 3, 8};
	//int mas[N] = {4, 8, 3, 1};

	//for(int i = 0; i < N; i++) // внутренний цикл прохода
	//{
	//	cout << mas[i] << " ";
	//}
	//cout << endl;	




	//quickSort(mas, N);





	//cout << endl;	
	//for(int i = 0; i < N; i++) // внутренний цикл прохода
	//{
	//	cout << mas[i] << " ";
	//}











	//cout << endl;	
	//for(int i = 0; i < N; i++) // внутренний цикл прохода
	//{
	//	cout << mas2[i] << " ";
	//}
	//cout << endl;	

	//quickSort2(mas2, N);

	//cout << endl;	
	//for(int i = 0; i < N; i++) // внутренний цикл прохода
	//{
	//	cout << mas2[i] << " ";
	//}

	//for (int i = 0; i < 10000; i++)
	//{
	//	vector <int> mas;

	//	int len = rand(2, 100);

	//	for (int j = 0; j < len; j++)
	//	{
	//		mas.push_back(rand(0, 100));
	//	}

	//	//printVec(mas);
	//	quickSort3(mas);
	//	//printVec(mas);

	//	//_getch();

	//	if (!isSort(mas))
	//	{
	//		printVec(mas);
	//	}

	//}


//****************************************************************************************
// формирование имени файла питер
//****************************************************************************************

//template <typename T>
//string toString(T val)
//{
//    std::ostringstream oss;
//    oss << val;
//    return oss.str();
//}
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	int month = 2; 
//	string monthStr = toString(month);
//	string fileName = "j:\\1\\lp-" + monthStr + "-231-piv1.txt"; 
//	std::ofstream out_file(fileName.c_str(), std::ios::out);
//	return 0;
//}

//****************************************************************************************
// числовой ряд
//****************************************************************************************

	//int s = 0;
	//int z = 1;
	//int n = 0;

	//cin >> n;

	//for (int i = 1; i <= n; i++)
	//{
	//	s = s + z*i;
	//	z = -z;
	//}

	//cout << s;

//****************************************************************************************
// орлянка
//****************************************************************************************

	//int x = 0;
	//int y = 1;
	//int n1 = 0;
	//int n2 = 0;

	//bool turn = 1;


	//do
	//{
	//	if (turn == 1)
	//	{
	//		cin >> x;
	//		y = rand()%2;

	//		cout << "монетка " << y << endl;

	//		if (x == y)
	//		{
	//			n1++;
	//			cout << "угадал" << endl;
	//		}
	//		else
	//		{
	//			cout << "не угадал" << endl;
	//		}
	//	}
	//	else
	//	{
	//		x = rand()%2;
	//		cout << "комп " << x << endl;
	//		y = rand()%2;
	//		cout << "монетка " << y << endl;

	//		if (x == y)
	//		{
	//			n2++;
	//			cout << "угадал" << endl;
	//		}
	//		else
	//		{
	//			cout << "не угадал" << endl;
	//		}

	//	}
	//	
	//	turn = !turn;

	//} while(n1 < 3 && n2 < 3);

	//cout << n1 << endl;
	//cout << n2 << endl;


	//turn = !turn;
	//cout << turn;

//****************************************************************************************
// баше
//****************************************************************************************

	//int x = 0;
	//int y = 1;
	//int n = 15;

	//bool turn = 1;

	//cout << "Осталось " << n << endl;
	//
	//do
	//{
	//	if (turn == 1)
	//	{
	//		cin >> x;
	//	}
	//	else
	//	{
	//		int d = n % 4;
	//		if (d == 0)
	//			x = 1;
	//		else
	//			x = d;
	//	}

	//	if (x > 3)
	//	{
	//		cout << "не больше 3" << endl;
	//		continue;
	//	}

	//	n = n - x;
	//	
	//	cout << "Осталось " << n << endl;

	//	turn = !turn;

	//} while(n > 0);

	//turn = !turn;
	//cout << turn;

//****************************************************************************************
// Чётные числа
//****************************************************************************************

//int x = 2;
//int n;
//cin >> n;
//while(x <= n)
//{
//	cout << x << " "; 	
//	x += 2;
//}

//****************************************************************************************
// Количество различных
//****************************************************************************************
	
	//const int N = 3;

	//int mas[N][N] = {
	//	{1,1,2},
	//	{1,1,2},
	//	{1,1,2}
	//};

	//int mas2[100] = {0};
	//mas2len = 0;

	//int x;

	//for (int i=0; i<10; i++) 
	//{
	//	for(int j=0; j<10; j++) 
	//	{
	//		bool find = false;
	//		for(int k=0; k<mas2len; k++) 
	//		{
	//			if (mas[i][j] == mas2[k])
	//			{
	//				find = true;
	//				break;
	//			}
	//			if (find)
	//			{
	//				mas2[mas2len] = 0;
	//				mas2len++;
	//			}
	//		} 
	//	} 
	//}

//****************************************************************************************
// Выше главной диагонали
//****************************************************************************************
	//const int N = 4;
	//int mas[N][N] = {
	//	{1,2,3,4},
	//	{1,2,3,4},
	//	{1,2,3,4},
	//	{1,2,3,4}
	//};
	//for (int i=0; i<N; i++) 
	//{
	//	for(int j=i+1; j<N; j++) 
	//	{
	//		cout << mas[i][j] << " ";
	//	} 
	//	cout << endl;
	//}
//****************************************************************************************
// Симметрия
//****************************************************************************************
	//const int N = 4;

	//int mas[N][N] = {
	//	{1,1,2,2},
	//	{1,1,2,3},
	//	{2,2,1,2},
	//	{2,3,0,1}
	//};


	//bool sim = true;

	//for (int i=0; i<N; i++) 
	//{
	//	for(int j=i+1; j<N; j++) 
	//	{
	//		cout << mas[i][j] << " ";
	//		if (mas[i][j] != mas[j][i])
	//		{
	//			sim = false;
	//			break;
	//		}
	//	} 
	//	cout << endl;
	//}

	//cout << sim;

//****************************************************************************************
// Чётные индексы
//****************************************************************************************
	
	//const int n = 4;

	//int mas[n] = {1,1,2,4};

	//for (int i=1; i<n; i += 2) 
	//{
	//	cout << mas[i];
	//}


//****************************************************************************************
// 222333
//****************************************************************************************
	
	//const int n = 5;
	//int mas[n] = {0};
	//int m = n/2;
	//if (n % 2 == 1)
	//{
	//	m++;
	//}
	//for (int i=0; i < m; i++) 
	//{
	//	mas[i] = 2;
	//}
	//for (int i=m; i<n; i++) 
	//{
	//	mas[i] = 3;
	//}
	//for (int i=0; i<n; i++) 
	//{
	//	cout << mas[i];
	//}

//****************************************************************************************
// Пары
//****************************************************************************************
	
	//const int n = 15;

	//int mas[n] = {0};

	//for (int i=0; i<n; i++) 
	//{
	//	if (i % 4 < 2)
	//		mas[i] = 1;
	//}


	//for (int i=0; i<n; i++) 
	//{
	//	cout << mas[i];
	//}

//****************************************************************************************
// Два наименьших 1
//****************************************************************************************
	
	//const int n = 4;

	//int mas[n] = {1,1,2,4};

	//int min = mas[0];
	//int ii = 0;

	//for (int i=0; i<n; i++) 
	//{
	//	if (mas[i] < min)
	//	{
	//		ii = i;
	//		min = mas[i];
	//	}
	//}

	//mas[ii] = 999;

	//cout << min;

	//min = mas[0];
	//ii = 0;

	//for (int i=0; i<n; i++) 
	//{
	//	if (mas[i] < min)
	//	{
	//		ii = i;
	//		min = mas[i];
	//	}
	//}

	//cout << min;
//****************************************************************************************
// Два наименьших 2
//****************************************************************************************
	
	//const int n = 4;

	//int mas[n] = {4,5,7,1};

	//int min1 = mas[0];

	//for (int i=0; i<n; i++) 
	//{
	//	if (mas[i] < min1)
	//	{
	//		min1 = mas[i];
	//	}
	//}

	//// ищем макс чтобы было правильное начальное значение 
	////а иначе программа работает некорректно
	//int min2 = mas[0];
	//for (int i=0; i<n; i++) 
	//{
	//	if (mas[i] > min2)
	//	{
	//		min2 = mas[i];
	//	}
	//}

	//cout << endl << min1 << " ";


	//for (int i=0; i<n; i++) 
	//{
	//	if (mas[i] < min2 && mas[i] != min1)
	//	{
	//		min2 = mas[i];
	//	}
	//}

	//cout << min2;

//****************************************************************************************
// Два наименьших 2
//****************************************************************************************
	
	//const int n = 5;

	//int mas[n] = {2,5,7,4,1};

	//int min1 = INT_MAX;
	//int min2 = INT_MAX;

	//for (int i=0; i<n; i++) 
	//{
	//	if (mas[i] < min1)
	//	{
	//		min1 = mas[i];
	//	}

	//}

	//cout << endl << min1 << " ";

	//for (int i=0; i<n; i++) 
	//{
	//	if (mas[i] < min2 && mas[i] != min1)
	//	{
	//		min2 = mas[i];
	//	}
	//}

	//cout << min2;


//****************************************************************************************
// Близкий по величине
//****************************************************************************************
	
	//const int n = 4;

	//int mas[n] = {1,1,2,4};

	//int x = 0;
	//int min = abs(x - mas[0]);

	//for (int i=0; i<n; i++) 
	//{
	//	if (abs(x - mas[0]) < min)
	//	{
	//		min = mas[i];
	//	}
	//}

	//cout << min;

//****************************************************************************************
// Отсортирован или нет
//****************************************************************************************

	//const int n = 5;

	//int mas[n] = {1,2,3,4,0};

	//int f = 1;
	//for (int i = 0; i < n-1; i++)
	//{
	//	if (mas[i] > mas[i+1])
	//	{
	//		f = 0;
	//		break;
	//	}
	//}

	//cout << f;

//****************************************************************************************
// Пять единиц
//****************************************************************************************

	//const int n = 7;
	//int mas[n] = {0};
	//for (int c = 0; c < 5;)
	//{
	//	int i = rand()%n;

	//	if (mas[i] == 0)
	//	{
	//		mas[i] = 1;
	//		c++;
	//	}
	//}

	//for (int i=0; i<n; i++) 
	//{
	//	cout << mas[i];
	//}

//****************************************************************************************
// Одинокие единицы
//****************************************************************************************

	//const int n = 5;
	//int mas[n] = {0};
	//for (int c = 0; c < 1000; c++)
	//{
	//	int i = rand()%n;
	//	if (i == 0 && mas[i+1] == 0)
	//	{
	//		mas[i] = 1;
	//	}
	//	else if (i == n-1 && mas[i-1] == 0)
	//	{
	//		mas[i] = 1;
	//	}
	//	else if (mas[i-1] == 0 && mas[i+1] == 0)
	//	{
	//		mas[i] = 1;
	//	}
	//}

	//for (int i=0; i<n; i++) 
	//{
	//	cout << mas[i];
	//}

//****************************************************************************************
// Одинокие единицы и границы
//****************************************************************************************

	//srand(time(0));

	//const int n = 7;
	//int mas[n] = {0};

	//for (int c = 0; c < 1000; c++)
	//{
	//	int i = rand(1,n-1);

	//	if (mas[i] == 0   && 
	//	    mas[i+1] != 1 && 
	//	    mas[i-1] != 1)
	//	{
	//		mas[i] = 1;
	//	}
	//}

	//for (int i=1; i<n-1; i++) 
	//{
	//	cout << mas[i];
	//}

//****************************************************************************************
// Единицы и двойки не доделал
//****************************************************************************************

	//srand(time(0));

	//const int n = 5;

	//int mas[n] = {0};

	//int c = 0;

	//while (c < 1000)
	//{
	//	int i = rand()%n;
	//	
	//	if (i == 0 && mas[i+1] == 0)
	//	{
	//		mas[i] = 1;
	//	}
	//	else if (i == n-1 && mas[i-1] == 0)
	//	{
	//		mas[i] = 1;
	//	}
	//	else if (mas[i-1] == 0 && mas[i+1] == 0)
	//	{
	//		mas[i] = 1;
	//	}
	//	
	//	c++;
	//}

	//c = 0;
	//while (c < 1000)
	//{
	//	int i = rand()%n;
	//	
	//	if (i == 0 && mas[i+1] == 1)
	//	{
	//		mas[i] = 2;
	//	}
	//	else if (i == n-1 && mas[i-1] == 1)
	//	{
	//		mas[i] = 2;
	//	}
	//	else if (mas[i-1] == 1 && mas[i+1] == 0)
	//	{
	//		mas[i] = 2;
	//	}
	//	
	//	c++;
	//}

	//for (int i=0; i<n; i++) 
	//{
	//	cout << mas[i];
	//}


//****************************************************************************************
// Пары.
//****************************************************************************************

	//srand(time(0));
	//while (true)
	//{
	//	const int n = 10;
	//	int mas[n] = {0};
	//	//mas[0] = 2;
	//	//mas[n-1] = 2;
	//	//mas[n-2] = 2;

	//	int c = 0;
	//	for (int j = 0; j < 1000; j++)
	//	{
	//		int i = rand(1,n-4);

	//		if (mas[i] == 0   && 
	//			mas[i+1] == 0 && 
	//			mas[i-1] == 0 && 
	//			mas[i+2] == 0)
	//		{
	//			mas[i] = 1;
	//			mas[i+1] = 1;
	//		}
	//	}

	//	for (int i=1; i<n-2; i++) 
	//	{
	//		cout << mas[i];
	//	}
	//	cout << endl;
	//	getch();
	//}

//****************************************************************************************
// дубликаты
//****************************************************************************************

	//srand(time(NULL));

	//const int N = 5;
	//int mas[N] = {4,2,3,1,4};

	//int find = false;

	//for (int i = 0; i < N; i++)
	//{
	//	int t = 0;
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (mas[i] == mas[j])
	//		{
	//			t++;		
	//		}
	//	}
	//	if (t >= 2)
	//	{
	//		find = true;
	//		break;
	//	}

	//}

	//cout << find;

//****************************************************************************************
// только два
//****************************************************************************************

	//srand(time(NULL));

	//const int N = 5;
	//int mas[N] = {1,7,4,4,5};

	//int t = 0;

	//bool find = false;

	//for (int i = 0; i < N; i++)
	//{
	//	int k = 0;
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (mas[i] == mas[j])
	//		{
	//			k++;
	//		}
	//	}
	//	if (k == 2)
	//	{
	//		t = mas[i];
	//		break;
	//	}
	//}

	//cout << t;

//****************************************************************************************
// все одинаковые
//****************************************************************************************

	//const int N = 5;
	//int mas[N] = {1,1,1,1,0};
	//int t = mas[0];
	//bool f = true;
	//for (int i = 0; i < N; i++)
	//{
	//	if (t != mas[i])
	//	{
	//		f = false;
	//		break;
	//	}
	//}
	//cout << f;

//****************************************************************************************
// Количество различных
//****************************************************************************************

	//const int N = 5;
	//int mas[N] = {4,4,5,5,6};
	//int t = mas[0];
	//int d = 1;
	//for (int i = 1; i < N; i++)
	//{
	//	if (t != mas[i])
	//	{
	//		d++;		
	//		t = mas[i];
	//	}
	//}
	//cout << d;

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
// Слово-палиндром
//****************************************************************************************

	//char str[] = "abfba";
	//bool f = 1;
	//int n = strlen(str);
	//for (int i = 0; i < n/2; i++)
	//{
	//	if (str[i] != str[n-i-1])
	//	{
	//		f = 0;		
	//		break;
	//	}
	//}
	//cout << f;

//****************************************************************************************
// Максимум
//****************************************************************************************

	//const int n = 5;
	//int mas[n] = {5,2,3,3,7};
	//x = mas[0];
	//for (int i = 1; i < n; i++)
	//{
	//	if (x < mas[i])
	//	{
	//		x = mas[i];
	//	}
	//}
	//cout << x;

//****************************************************************************************
// Циклический сдвиг влево
//****************************************************************************************

	//const int n = 5;
	//int mas[n] = {1,2,3,4,5};
	//int x = mas[0];
	//for (int i = 0; i < n-1; i++)
	//{
	//		mas[i] = mas[i+1];
	//}
	//mas[n-1] = x;

	//for (int i = 0; i < n; i++)
	//{
	//	cout << mas[i];
	//}

//****************************************************************************************
// Циклический сдвиг вправо
//****************************************************************************************

	//const int n = 5;
	//int mas[n] = {1,2,3,4,5};
	//int x = mas[n-1];
	//for (int i = n-1; i > 0; i--)
	//{
	//		mas[i] = mas[i-1];
	//}
	//mas[0] = x;

	//for (int i = 0; i < n; i++)
	//{
	//	cout << mas[i];
	//}

//****************************************************************************************
// Смена мест
//****************************************************************************************

	//const int n = 5;
	//int mas[n] = {1,2,3,4,5};
	////const int n = 6;
	////int mas[n] = {1,2,3,4,5,6};
	//for (int i = 0; i < n-1; i+=2)
	//{
	//		swap(mas[i], mas[i+1]);
	//}

	//for (int i = 0; i < n; i++)
	//{
	//	cout << mas[i];
	//}

//****************************************************************************************
// Наоборот
//****************************************************************************************

	//const int n = 5;
	//int mas[n] = {1,2,3,4,5};
	//const int n = 6;
	//int mas[n] = {1,2,3,4,5,6};
	//for (int i = 0; i < n/2; i++)
	//{
	//		swap(mas[i], mas[n-i-1]);
	//}

	//for (int i = 0; i < n; i++)
	//{
	//	cout << mas[i];
	//}


//****************************************************************************************
// Один большой, два маленьких
//****************************************************************************************

	//const int n = 6;
	//int mas[n] = {0,1,2,3,4,5};
	//int mas1[n/2];
	//int mas2[n/2];
	//
	//int j = 0;
	//for (int i = 0; i < n; i+=2)
	//{
	//	mas1[j] = mas[i];
	//	j++;
	//}

	//j = 0;
	//for (int i = 1; i < n; i+=2)
	//{
	//	mas2[j] = mas[i];
	//	j++;
	//}

	//for (int i = 0; i < n/2; i++)
	//{
	//	cout << mas1[i];
	//}

	//cout << endl;

	//for (int i = 0; i < n/2; i++)
	//{
	//	cout << mas2[i];
	//}



//****************************************************************************************
// Все, кроме одного
//****************************************************************************************

	//const int n = 5;

	//int mas[n] = {1,2,3,4,5};
	//int mas2[n-1] = {0};
	//int k;

	//int j = 0;

	//cin >> k;

	//for (int i = 0; i < n; i++)
	//{
	//	if (k != i)
	//	{
	//		mas2[j] = mas[i];
	//		j++;
	//	}
	//}

	//for (int i = 0; i < n-1; i++)
	//{
	//	cout << mas2[i];
	//}


//****************************************************************************************
// Вставка элемента
//****************************************************************************************

	//const int n = 5;

	//int mas[n] = {1,2,3,4,0};
	//int k;
	//int x = 7;

	//int j = 0;

	//cin >> k;

	//if (k == n-1)
	//{
	//	mas[k] = x;
	//}
	//else
	//{
	//	for (int i = n-1; i > k; i--)
	//	{
	//		mas[i] = mas[i-1];
	//	}
	//	mas[k] = x;
	//}

	//for (int i = 0; i < n; i++)
	//{
	//	cout << mas[i];
	//}

//****************************************************************************************
// Только чётные
//****************************************************************************************

	//const int n = 5;

	//int mas[5] = {0};
	//int n;
	//int x = 0;
	//int j = 0;
	//cin >> n;

	//for (int i = 0; i < n; i++)
	//{
	//	x = rand(1,9);
	//	cout << x << " ";
	//	if (x % 2 == 0)
	//	{
	//		if (j >= 5)
	//		{
	//			break;
	//		}
	//		mas[j] = x;
	//		j++;
	//	}
	//}

	//cout << endl;

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << mas[i] << " ";
	//}

//****************************************************************************************
// Один большой, два маленьких
//****************************************************************************************

	//const int n = 6;

	//int mas[n] = {1,2,3,4,5,6};
	//int mas2[n/2] = {0};
	//int mas3[n/2] = {0};
	//int k;

	//int j = 0;

	//for (int i = 0; i < n/2; i++)
	//{
	//	mas2[i] = mas[i];
	//}

	//for (int i = n/2; i < n; i++)
	//{
	//	mas3[i-n/2] = mas[i];
	//}

	//for (int i = 0; i < n/2; i++)
	//{
	//	cout << mas2[i];
	//}

	//for (int i = 0; i < n/2; i++)
	//{
	//	cout << mas3[i];
	//}

//****************************************************************************************
// getch 224
//****************************************************************************************

	//int ch = 0;

	//ch = getch();

	//if (ch == 224)
	//{
	//	ch = getch();
	//	if (ch == 82)
	//	{
	//		cout << "ins";
	//	}
	//}

//****************************************************************************************
// динамический массив на основе статического
//****************************************************************************************

	//const int n = 5;

	//int mas[n] = {0,0,0,0,0};
	//int k;
	//int x = 7;

	//int size = 0;
	//int op = 0;

	//while (true)
	//{
	//	cout << "Введите вид операции " << endl;
	//	cout << "1. Добавить в конец " << endl;
	//	cout << "2. Вставка " << endl;
	//	cout << "3. Вывести на экран " << endl;
	//	cout << "4. Выход " << endl;

	//	cin >> op;

	//	if (op == 1)
	//	{
	//		if (size >= n)
	//		{
	//			cout << "full" << endl;
	//			continue;
	//		}

	//		cin >> x;

	//		mas[size] = x;
	//		size++;

	//	}
	//	else if (op == 2)
	//	{
	//		cin >> k;
	//		cin >> x;

	//		if (k == n-1)
	//		{
	//			mas[k] = x;
	//		}
	//		else
	//		{
	//			for (int i = n-1; i > k; i--)
	//			{
	//				mas[i] = mas[i-1];
	//			}
	//			mas[k] = x;
	//		}
	//	}

	//	for (int i = 0; i < n; i++)
	//	{
	//		cout << mas[i] << " ";
	//	}
	//	cout << endl;
	//}

//****************************************************************************************
// Уменьшить на 15 процентов
//****************************************************************************************

	//float f = 7;
	//reduce(f);
	//cout << f;

//****************************************************************************************
// Таблица умножения на 3
//****************************************************************************************

	//int n = 20;
	//int x = 3;

	//for (int i = 1; i <= n; i++)
	//{
	//	if (i < 10)
	//	{
	//		cout << " ";
	//	}

	//	cout << i << " * " << x << " = " ;

	//	if (i*2 < 10)
	//	{
	//		cout << " ";
	//	}
	//	cout << i*2 << endl;
	//}

//****************************************************************************************
// N элементов по m
//****************************************************************************************

	//int n = 20;
	//int m = 4;
	//int j = 1;

	//for (int i = 1; i <= n; i++)
	//{
	//	cout << i << " ";
	//	if (i < 10)
	//	{
	//		cout << " ";
	//	}

	//	if (j >= m)
	//	{
	//		j = 0;
	//		cout << endl;
	//	}
	//	j++;
	//}

//****************************************************************************************
// установка размера консольного окна шрифта
//****************************************************************************************



	//HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
 //   CONSOLE_FONT_INFOEX fontInfo;
 //   // эта строка нужна
 //   fontInfo.cbSize = sizeof( fontInfo );
 //   GetCurrentConsoleFontEx( hConsole, TRUE, &fontInfo );
 //   wcscpy( fontInfo.FaceName, L"Lucida Console" );
 //   fontInfo.dwFontSize.Y = 20;
 //   SetCurrentConsoleFontEx( hConsole, TRUE, &fontInfo );


//typedef BOOL (WINAPI *SETCONSOLEFONT)(HANDLE, DWORD);     // прототип недокументированый функции
// SETCONSOLEFONT SetConsoleFont;
//
//  HMODULE hmod = GetModuleHandleA("KERNEL32.DLL");     // функция здесь
//  SetConsoleFont =(SETCONSOLEFONT) GetProcAddress(hmod, "SetConsoleFont");   // берем ее адрес
//  if (!SetConsoleFont) {cout<<"error\n" ; exit(1);}   //   если ошибка
//  SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), 8);  // устанавливаем 8-й шрифт..
//  //эксперементально установил что в обычной XP  это Lucida  Console = 6 или 8.
//  // разница только в размерах. 6 - помельче.
//  SetConsoleCP(1251);            // устанавливаем кодировку ввода
//  SetConsoleOutputCP(1251) ;  // устанавливаем кодировку вывода

//****************************************************************************************
// установка размера консольного окна шрифта рабочий вариант 
//****************************************************************************************

	//system("color F0");

 //   HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
 //   CONSOLE_FONT_INFOEX fontInfo;
 //   fontInfo.cbSize = sizeof( fontInfo );
 //   GetCurrentConsoleFontEx( hConsole, TRUE, &fontInfo );
 //   wcscpy( fontInfo.FaceName, L"Lucida Console" );
 //   fontInfo.dwFontSize.Y = 30;
 //   SetCurrentConsoleFontEx( hConsole, TRUE, &fontInfo );

	//HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
 //   COORD crd = {80, 25};
 //   SMALL_RECT src = {0, 0, crd.X-1, crd.Y-1};
 //   SetConsoleWindowInfo (out_handle, true, &src);
 //   SetConsoleScreenBufferSize (out_handle, crd);   

	//cout << "sdfsdfsdfsdfsdfsdf";

//****************************************************************************************
// побитовые операции
//****************************************************************************************
	//unsigned int x = 4;
	//x = x << 2; // x должен быть 8
	//cout << x;

 //ofstream file;

 //file.open("d:\\test\\test.txt");
 //file << "Hello!" << endl;
 //file << 12345 << endl;
 //file.close();

//****************************************************************************************
// Сравнение строк
//****************************************************************************************
	
	//string str1 = "asd";
	//string str2 = "as";

	//if (str1 > str2)
	//	cout << 1;

//****************************************************************************************
// Рекурсия
//****************************************************************************************

//	cout << fact(5);

	//cout << deg(2, 10000);
	//cout << sumDigits(123);
	//cout << numDigits(22);
	//cout << sumRow123(4);
	//cout << Fibo(6);

	
	//const int N = 5;
	//int mas[N] = {22, 3, 14, 16, 77};

	////cout << maxInMas(mas,N);
	//cout << idxMaxInMas(mas,N);

//****************************************************************************************
// Одинаковый столбец и строка
//****************************************************************************************

	//const int N = 3;

	//int mas[3][3] = 
	//{
	//	{1,1,9},
	//	{1,1,2},
	//	{9,9,8}
	//};

	//bool f = false;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		bool egual = true;
	//		for (int k = 0; k < N; k++)
	//		{
	//			if (mas[i][k] != mas[k][j])
	//			{
	//				egual = false;
	//				break;
	//			}
	//		}

	//		if (egual)
	//		{
	//			cout << i << " " << j << endl;
	//		}
	//	}
	//}


//****************************************************************************************
// Множество случайных чисел
//****************************************************************************************
 //   set <int> st;
	//for (int i = 0; i < 5; i++) // перебор элементов вектора через цикл for
	//{
	//	st.insert(rand(1,5));
	//}
	//cout << st.count(6);

	//for(set <int>::iterator it = st.begin(); it != st.end(); it++)
	//{
	//	cout << *it << " ";
	//}

	//cout << endl;


	//for(set <int>::iterator it = st.begin(); it != st.end(); )
	//{
	//	if (*it > 2) 
	//	{
	//		it = st.erase(it);
	//		continue;
	//	};

	//	it++;
	//}

	////if (*(st.end()) > 2 )
	////{
	////	st.erase(st.end());
	////}


	//for(set <int>::iterator it = st.begin(); it != st.end(); it++)
	//{
	//	cout << *it << " ";
	//}

	//cout << endl;

//****************************************************************************************
// Раздача игральных карт
//****************************************************************************************

	//srand(time(0));

 //   set <int> st;
 //   vector <set <int>> vec;

	//for (int i = 0; i < 36; i++) // перебор элементов вектора через цикл for
	//{
	//	st.insert(i);
	//}

	//int n = 6;
	//int m = 8;

	//bool kolodaEmpty = 0;


	//for(int i = 0; i < n; i++)
	//{
	//	set <int> tempSet;

	//	vec.push_back(tempSet);

	//	for(int j = 0; j < m; j++)
	//	{
	//		int x = rand() % st.size();

	//		set<int>::iterator it = st.begin();
	//		advance(it, x);

	//		vec[i].insert(*it);

	//		if (!st.empty())
	//			st.erase(it);

	//		if (st.empty())
	//		{
	//			kolodaEmpty = 1;
	//			break;
	//		}
	//	}
	//	if (kolodaEmpty)
	//		break;
	//}

	//for(int i = 0; i < vec.size(); i++)
	//{
	//	for(set <int>::iterator it = vec[i].begin(); it != vec[i].end(); it++)
	//	{
	//		cout << setw(3) << *it;
	//	}
	//	cout << endl;
	//}



//****************************************************************************************
// Уникальные числа в векторе с помощью set
//****************************************************************************************
	
	//vector <string> vec;

	//vec.push_back("aa");
	//vec.push_back("aa");
	//vec.push_back("bb");
	//vec.push_back("aa");

 //   set <string> st;

	//for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	st.insert(vec[i]);
	//}

	//for(set <string>::iterator it = st.begin(); it != st.end(); it++)
	//{
	//	cout << *it << " ";
	//}

//****************************************************************************************
// Подмножество всех остальных множеств через set_intersection
//****************************************************************************************
	
	//vector <string> vec;

	//vec.push_back("abcef");
	//vec.push_back("ef");
	//vec.push_back("cefdg");
	//vec.push_back("fe");

 //   vector <set <char>> vec_set;

	//for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	set <char> temp;
	//	for (int j = 0; j < vec[i].size(); j++) // перебор элементов вектора через цикл for
	//	{
	//		temp.insert(vec[i][j]);
	//	}
	//	vec_set.push_back(temp);
	//}

	//for (int i = 0; i < vec_set.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	printSet(vec_set[i]);
	//}
	//cout << endl;

	//for (int i = 0; i < vec_set.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	bool f = true;
	//	for (int j = 0; j < vec_set.size(); j++) // перебор элементов вектора через цикл for
	//	{
	//		if (i == j) continue;

	//		set<char> intersect;
	//		set_intersection(vec_set[i].begin(),
	//						 vec_set[i].end(),
	//						 vec_set[j].begin(),
	//						 vec_set[j].end(),
	//						 inserter(intersect,intersect.begin()));		

	//		if (intersect.size() != vec_set[i].size())
	//		{
	//			f = false;
	//			break;
	//		}

	//	}
	//	if (f) printSet(vec_set[i]);
	//}

//****************************************************************************************
// Подмножество всех остальных множеств
//****************************************************************************************
	
	//vector <string> vec;

	//vec.push_back("ef");
	//vec.push_back("abcef");
	//vec.push_back("cefdg");
	//vec.push_back("fe");

 //   vector <set <char>> vec_set;

	//for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	set <char> temp;
	//	for (int j = 0; j < vec[i].size(); j++) // перебор элементов вектора через цикл for
	//	{
	//		temp.insert(vec[i][j]);
	//	}
	//	vec_set.push_back(temp);
	//}

	//for (int i = 0; i < vec_set.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	print(vec_set[i]);
	//}
	//cout << endl;

	//int i = 0;

	//for(vector <set <char>>::iterator it1 = vec_set.begin(); it1 != vec_set.end(); it1++)
	//{
	//	bool find = 1;

	//	// все элементы сета (*it1) ищу во всех сетах вектора *it2 
	//	for(vector <set <char>>::iterator it2 = vec_set.begin(); it2 != vec_set.end(); it2++)
	//	{
	//		if (it1 == it2)
	//			continue;

	//		//каждый элемент сета *it3 ищу в сете *it2
	//		for(set <char>::iterator it3 = (*it1).begin(); it3 != (*it1).end(); it3++)
	//		{
	//			if ((*it2).find(*it3) == (*it2).end())
	//			{
	//				find = 0;
	//				break;
	//			}
	//		}

	//		if (!find)
	//			break;
	//	}

	//
	//	if (find)
	//	{
	//		cout << i << " ";
	//		print(*it1);
	//	}

	//	i++;
	//}

//****************************************************************************************
// Угаданные и не угаданные числа
//****************************************************************************************

	//set <int> st;
 //   set <int> st1;
 //   set <int> st2;
 //   set <int> st3;

	//srand(time(0));
	//
	//for (int i = 0; i < 5; i++) // перебор элементов вектора через цикл for
	//{
	//	int x = rand(0,9);
	//	if (st.count(x) == 1)
	//	{
	//		i--;
	//	}
	//	else
	//	{
	//		st.insert(x);
	//	}
	//}

	//int x = 0;
	//for (int i = 0; i < 5; i++) // перебор элементов вектора через цикл for
	//{
	//	cin >> x;
	//	if (st.count(x) == 1)
	//	{
	//		st1.insert(x);
	//	}
	//	else
	//	{
	//		st2.insert(x);
	//	}
	//}

	//cout << "Угаданные: ";
	//print(st1);
	//cout << "Ошибочные: ";
	//print(st2);
	//cout << "Неугаданные: ";
	//print(subSet(st,st1));

//****************************************************************************************
// Проверка корректности строки-идентификатора
//****************************************************************************************

	//string strFirstChar = "abc_";
	//string strSecondChar = "abc_123";
	//string strIn = "a@123";

	//set <char> st1;
	//set <char> st2;

	//for (int i = 0; i < strFirstChar.length(); i++) // перебор элементов вектора через цикл for
	//{
	//	st1.insert(strFirstChar[i]);
	//}

	//for (int i = 0; i < strSecondChar.length(); i++) // перебор элементов вектора через цикл for
	//{
	//	st2.insert(strSecondChar[i]);
	//}

	//bool f = 1;

	//if (st1.count(strIn[0]) == 1)
	//{
	//	for (int i = 1; i < strIn.length(); i++) // перебор элементов вектора через цикл for
	//	{
	//		if (st2.count(strIn[i]) == 0)
	//		{
	//			f = 0;
	//			break;
	//		}
	//	}
	//}
	//else
	//{
	//	f = 0;
	//}
	//cout << f;


//****************************************************************************************
// Правильное окончание
//****************************************************************************************

	//while (true)
	//{
	//	int x;
	//	cin >> x;

	//	switch(x%10)
	//	{
	//		case 1:
	//			cout << " год" << endl;
	//		break;

	//		case 2: case 3: case 4:
	//			cout << " года" << endl;
	//		break;

	//		case 5: case 6: case 7: case 8: case 9: case 0:
	//			cout << " лет" << endl;
	//		break;
	//	}		
	//}

//****************************************************************************************
// Подмножество всех остальных множеств через самопис
//****************************************************************************************
	
	//vector <string> vec;

	//vec.push_back("abcef");
	//vec.push_back("ef");
	//vec.push_back("cefdg");
	//vec.push_back("fe");

 //   vector <set <char>> vec_set;

	//for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	set <char> temp;
	//	for (int j = 0; j < vec[i].size(); j++) // перебор элементов вектора через цикл for
	//	{
	//		temp.insert(vec[i][j]);
	//	}
	//	vec_set.push_back(temp);
	//}

	//for (int i = 0; i < vec_set.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	printSet(vec_set[i]);
	//}
	//cout << endl;

	//for (int i = 0; i < vec_set.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	bool f = true;
	//	for (int j = 0; j < vec_set.size(); j++) // перебор элементов вектора через цикл for
	//	{
	//		if (i == j) continue;

	//		if (!isIntersect(vec_set[i],vec_set[j]))
	//		{
	//			f = false;
	//			break;
	//		}

	//	}
	//	if (f) printSet(vec_set[i]);
	//}

//****************************************************************************************
// Не уникальные символы в строке
//****************************************************************************************

 //   string str = "abcabcdef";

 //   multiset <char> st;
 //   set <char> st2;


	//for (int i = 0; i < str.size(); i++)
	//{
	//	st.insert(str[i]);
	//}

	//for(multiset <char>::iterator it = st.begin(); it != st.end(); it++)
	//{
	//	cout << *it << " ";
	//}

	//cout << endl;

	//for(multiset <char>::iterator it = st.begin(); it != st.end(); it++)
	//{
	//	if (st.count(*it) > 1)
	//	{
	//		st2.insert(*it);
	//	}
	//}

	//print(st2);

//****************************************************************************************
// И тут и там вектор vector
//****************************************************************************************

 //   vector <int> vec1;
 //   vector <int> vec2;
	//
	//vec1.push_back(1);
	//vec1.push_back(2);
	//vec1.push_back(7);

	//vec2.push_back(1);
	//vec2.push_back(2);
	//vec2.push_back(3);
	//vec2.push_back(2);
	//vec2.push_back(5);

 //   set <int> st;

	//for (int i = 0; i < vec1.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	st.insert(vec1[i]);
	//}

	//int d = 0;

	//for (int i = 0; i < vec2.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	set <int> :: iterator found = st.find(vec2[i]);

	//	if (found != st.end())
	//	{
	//		st.insert(vec2[i]);
	//		d++;
	//	}
	//}

	//for(set <int>::iterator it = st.begin(); it != st.end(); it++)
	//{
	//	cout << *it << " ";
	//}

	//cout << endl << d;

//****************************************************************************************
// И тут и там множество оформить в функцию 
// Операции над множествами
//****************************************************************************************

 //   set <int> set1;
 //   set <int> set2;
	//
	//set1.insert(1);
	//set1.insert(2);
	//set1.insert(3);
	//set1.insert(4);

	//set2.insert(3);
	//set2.insert(4);
	//set2.insert(5);

 //   set <int> st;

	//st = addSet(set1, set2);
	//print(st);

	//st = subSet(set1, set2);
	//print(st);


	//st = mulSet(addSet(set1, set2), subSet(set1, set2));
	//print(st);


//****************************************************************************************
// Есть тут, но нет там вектор
//****************************************************************************************

 //   vector <int> vec1;
 //   vector <int> vec2;
	//
	//vec1.push_back(1);
	//vec1.push_back(2);
	//vec1.push_back(7);

	//vec2.push_back(6);
	//vec2.push_back(2);
	//vec2.push_back(3);
	//vec2.push_back(2);
	//vec2.push_back(5);

 //   set <int> st;

	//for (int i = 0; i < vec2.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	st.insert(vec2[i]);
	//}

	//for (int i = 0; i < vec1.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	set <int> :: iterator found = st.find(vec1[i]);

	//	if (found == st.end())
	//	{
	//		cout << vec1[i] << " ";
	//	}
	//}

//****************************************************************************************
// Есть тут, но нет там множество
//****************************************************************************************

 //   vector <int> vec1;
 //   vector <int> vec2;
	//
	//vec1.push_back(1);
	//vec1.push_back(2);
	//vec1.push_back(7);

	//vec2.push_back(6);
	//vec2.push_back(2);
	//vec2.push_back(3);
	//vec2.push_back(2);
	//vec2.push_back(5);

 //   set <int> st;

	//for (int i = 0; i < vec2.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	st.insert(vec2[i]);
	//}

	//for (int i = 0; i < vec1.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	set <int> :: iterator found = st.find(vec1[i]);

	//	if (found == st.end())
	//	{
	//		cout << vec1[i] << " ";
	//	}
	//}


//****************************************************************************************
// Уникальные слова в файле
//****************************************************************************************

	//ifstream file ("vim.txt");

	//unsigned int start_time =  clock(); // начальное время

	//if (file.is_open())
	//{
	//	string word;
	//	
	//	set <string> st;

	//	while ( file.good() )
	//	{
	//		file >> word;
	//		st.insert(word);
	//	}

	//	file.close();
	//	cout << st.size() << endl;

	//}
	//else cout << "Unable to open file";

	//cout << clock() - start_time << endl;





	//start_time =  clock(); // начальное время

	//ifstream file2 ("f:\\vim.txt");

	//if (file2.is_open())
	//{
	//	string word;
	//	
	//	vector <string> vec;

	//	while ( file2.good() )
	//	{
	//		file2 >> word;

	//		if (!find(vec, word))
	//		{
	//			vec.push_back(word);
	//		}

	//	}

	//	file2.close();
	//	cout << vec.size() << endl;

	//}
	//else cout << "Unable to open file";

	//cout << clock() - start_time << endl;

//****************************************************************************************
// Не повторяющиеся случайные числа на основе множества
//****************************************************************************************

 //   vector <int> vec;
 //   
	//set <int> st;

 // 	int n = 5;
	//int x = 0;
	//while (st.size() < n) // перебор элементов вектора через цикл for
	//{
	//	x = rand(1,n);
	//	
	//	set <int> :: iterator found = st.find(x);

	//	if (found == st.end())
	//	{
	//		st.insert(x);
	//		vec.push_back(x);
	//	}
	//}

	//for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	cout << vec[i] << " ";
	//}	


//****************************************************************************************
// Анаграммы
//****************************************************************************************

	//vector <string> vec;

	//vec.push_back("maaster streaam");
	//vec.push_back("eat teaa");

	//for (int i = 0; i < vec.size(); i++)
	//{
	//
	//	int p = vec[i].find(' ');

	//	string word1 = vec[i].substr(0,p);
	//	string word2 = vec[i].substr(p+1,vec[i].length()-p);

	//	cout << word1 << " " << word2 << endl;
	//	
	//	cout << isAnagramm(word1, word2) << endl;
	//}

//****************************************************************************************
// Англо-русский словарь Задача с map
//****************************************************************************************
	//struct Command
	//{
	//	string type;
	//	string word1;
	//	string word2;
	//};

	//vector <Command> cmd;
	//Command temp;

	//temp.type  = "ADD";   temp.word1 = "pen";   temp.word2 = "ручка";  cmd.push_back(temp);
	//temp.type  = "ADD";   temp.word1 = "post";  temp.word2 = "почта";  cmd.push_back(temp);
	//temp.type  = "ADD";   temp.word1 = "paper"; temp.word2 = "бумага"; cmd.push_back(temp);
	//temp.type  = "ADD";   temp.word1 = "table"; temp.word2 = "стол";   cmd.push_back(temp);
	//temp.type  = "ADD";   temp.word1 = "map";   temp.word2 = "карта";  cmd.push_back(temp);
	//temp.type  = "PRINT"; cmd.push_back(temp);
	//temp.type  = "FIND";  temp.word1 = "post";   cmd.push_back(temp);
	//temp.type  = "DEL";   temp.word1 = "post";   cmd.push_back(temp);
	//temp.type  = "PRINT"; cmd.push_back(temp);
	//temp.type  = "DEL2";  temp.word1 = "p"; cmd.push_back(temp);
	//temp.type  = "PRINT"; cmd.push_back(temp);

	//map <string,string> mp;


 //   for (int i = 0; i < cmd.size(); i++) 
	//{
	//	if (cmd[i].type == "ADD") 
	//	{
	//		mp[cmd[i].word1] = cmd[i].word2; 
	//	}
	//	else if (cmd[i].type == "FIND") 
	//	{
	//		map <string,string> :: iterator found = mp.find(cmd[i].word1);

	//		if (found != mp.end())
	//		{
	//			cout << 1 << endl;
	//		}
	//		else
	//		{
	//			cout << 0 << endl;
	//		}
	//	}		
	//	else if (cmd[i].type == "DEL") 
	//	{
	//		map <string,string> :: iterator found = mp.find(cmd[i].word1);

	//		if (found != mp.end())
	//		{
	//			mp.erase(found);
	//		}
	//	}
	//	else if (cmd[i].type == "DEL2") 
	//	{
	//		int f = 0;
	//		for (map <string, string>::iterator it = mp.begin(); it != mp.end(); )
	//		{
	//			f = it->first.find(cmd[i].word1);
	//			if (f == 0)
	//			{
	//				it = mp.erase(it);
	//			}
	//			else
	//			{
	//				it++;
	//			}
	//		}
	//	}
	//	else if (cmd[i].type == "PRINT")
	//	{
	//		cout << "---" << endl; 
	//		for (map <string, string>::iterator it = mp.begin(); it != mp.end(); it++)
	//		{
	//			cout << it->first << " " << it->second << endl; 
	//		}
	//	}
	//}

//****************************************************************************************
// Латино-английский словарь ( сочетание map и set)
//****************************************************************************************

	//vector <string> vec;
	//map <string, set<string>> dic;

	//vec.push_back("apple - malum, pomum, popula");
	//vec.push_back("fruit - baca, bacca, popum");
	//vec.push_back("punishment - malum, multa");

	//for (int i = 0; i < vec.size(); i++)
	//{
	//	string str = vec[i];

	//	string eng = getWord(str);

	//	while (true)
	//	{
	//		string key = getWord(str);
	//		if (key == "")
	//		{
	//			break;
	//		}

	//		map <string, set<string> >::iterator found = dic.find(key);

	//		if (found != dic.end())
	//		{
	//			found->second.insert(eng);
	//		}
	//		else
	//		{
	//			set <string> temp;
	//			temp.insert(eng);
	//			dic.insert(make_pair(key, temp));
	//		}
	//	}
	//}

 //   for( map<string,set<string> >::const_iterator it = dic.begin(); it != dic.end(); it++) 
	//{
	//	cout << it->first << ": ";

	//	for(set <string>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
	//	{
	//		cout << *it2 << " ";
	//	}

	//	cout << endl;
 //   }

//****************************************************************************************
// Синонимы. Сочетание map и set
//****************************************************************************************

	//struct Command
	//{
	//	string type;
	//	string word1;
	//	string word2;
	//};

	//vector <Command> cmd;
	//Command temp;

	//temp.type  = "ADD";   temp.word1 = "program"; temp.word2 = "code";    cmd.push_back(temp);
	//temp.type  = "COUNT"; temp.word1 = "cipher";                          cmd.push_back(temp);
	//temp.type  = "ADD";   temp.word1 = "code";    temp.word2 = "cipher";  cmd.push_back(temp);
	//temp.type  = "COUNT"; temp.word1 = "code";                            cmd.push_back(temp);
	//temp.type  = "COUNT"; temp.word1 = "program";                         cmd.push_back(temp);
	//temp.type  = "CHECK"; temp.word1 = "code";    temp.word2 = "program"; cmd.push_back(temp);
	//temp.type  = "CHECK"; temp.word1 = "program"; temp.word2 = "cipher";  cmd.push_back(temp);
	//temp.type  = "CHECK"; temp.word1 = "cpp";     temp.word2 = "java";    cmd.push_back(temp);

 //   map<string, std::set<string>> synonyms;
 //
 //   for (int i = 0; i < cmd.size(); i++) 
	//{
	//	if (cmd[i].type == "ADD") 
	//	{
 //           synonyms[cmd[i].word1].insert(cmd[i].word2);
 //           synonyms[cmd[i].word2].insert(cmd[i].word1);
 //       } 
	//	else if (cmd[i].type == "COUNT") 
	//	{

 //           int synonymsCount = 0;
 //
 //           map <string, set<string> >::iterator it = synonyms.find(cmd[i].word1);

	//		if (it != synonyms.end())
	//		{
 //               synonymsCount = it->second.size();
	//		}
 //
 //           cout << synonymsCount << endl;
 //
 //       } 
	//	else if (cmd[i].type == "CHECK") 
	//	{
 //           bool isSynonyms = false;
 //
 //           map <string, set<string> >::iterator it = synonyms.find(cmd[i].word1);
 //           if (it != synonyms.end())
	//		{
 //               if (it->second.find(cmd[i].word2) != it->second.end())
	//			{
 //                   isSynonyms = true;
	//			}
	//		}
 //
 //           cout << (isSynonyms ? "TRUE" : "FALSE") << endl;
 //       }
 //   }

//****************************************************************************************
// Список. Сортировка через вектор. Без использования sort
//****************************************************************************************

	//list <int> lst; // создём список с элементами типа int

	//lst.push_front(3);
	//lst.push_front(2);
	//lst.push_front(1);
	//lst.push_front(2);
	//lst.push_front(2);

	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	//vector <int> vec;
	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	vec.push_back(*it);
	//}

	//sort(vec);
	//
	//lst.clear();

	//for (vector <int>::iterator it = vec.begin(); it != vec.end(); it++)
	//{
	//	lst.push_back(*it);
	//}


	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

//****************************************************************************************
// Список. Удалить дубликаты.
//****************************************************************************************

	//list <int> lst; // создём список с элементами типа int

	//lst.push_front(3);
	//lst.push_front(2);
	//lst.push_front(1);
	//lst.push_front(2);
	//lst.push_front(2);


	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;


	//for (list <int>::iterator base = lst.begin(); base != lst.end(); )
	//{

	//	int findElem = *base;
	//	list<int>::iterator findIter;
	//	findIter = ++base;
	//	findIter = find(findIter, lst.end(), findElem);

	//	while (findIter != lst.end())
	//	{
	//		findIter = lst.erase(findIter);
	//		findIter = find(findIter, lst.end(), findElem);
	//		base = lst.begin();
	//	}

	//}


	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

//****************************************************************************************
// Список. Удалить дубликаты.
//****************************************************************************************

	//list <int> lst; // создём список с элементами типа int

	//// заносим элементы в начало списка
	//lst.push_front(3);
	//lst.push_front(2);
	//lst.push_front(1);
	//lst.push_front(2);
	//lst.push_front(2);

	//lst.sort();
	//lst.unique();

	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}

//****************************************************************************************
// 	Ноль после чётного
//****************************************************************************************

	//list <int> lst; // создём список с элементами типа int

	//lst.push_front(4);
	//lst.push_front(2);
	//lst.push_front(1);
	//lst.push_front(2);
	//lst.push_front(2);

	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	if (*it % 2 == 0)
	//	{
	//		it++;
	//		lst.insert(it,0);
	//		it--;
	//	}
	//}

	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}


	//list <int> lst; // создём список с элементами типа int

	//lst.push_front(4);
	//lst.push_front(2);
	//lst.push_front(1);
	//lst.push_front(2);
	//lst.push_front(2);

	//list <int> lst22; // создём список с элементами типа int
	//lst22.push_back(7);
	//lst22.push_back(8);


	//lst.sort();
	//lst22.sort();

	//copy(lst.begin(), lst.end(), ostream_iterator<int>(cout," "));

	//cout << endl

	//lst.merge(lst22);

	//copy(lst.begin(), lst.end(), ostream_iterator<int>(cout," "));

	//copy(lst.begin(), lst.end(), lst22.begin());
	//copy(lst22.begin(), lst22.end(), ostream_iterator<int>(cout," "));


//****************************************************************************************
// Список. Удалить дубликаты.
//****************************************************************************************

	//list <int> lst; // создём список с элементами типа int

	//// заносим элементы в начало списка
	//lst.push_front(3);
	//lst.push_front(2);
	//lst.push_front(1);
	//lst.push_front(2);
	//lst.push_front(2);

	//lst.sort();
	//lst.unique();

	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}

//****************************************************************************************
// Удалить N наименьших без sort
//****************************************************************************************

	//list <int> lst; 

	//lst.push_front(3);
	//lst.push_front(4);
	//lst.push_front(1);
	//lst.push_front(1);
	//lst.push_front(5);

	//int n = 2;

	//for (int i = 0; i < n; i++) 
	//{
	//	if (lst.empty())
	//		break;

	//	
	//	list <int>::iterator it = lst.begin();
	//	list <int>::iterator itMin = it;
	//	int x = *it;

	//	for( ; it != lst.end(); it++)
	//	{
	//		if (*it < x)
	//		{
	//			x = *it;
	//			itMin = it;

	//		}

	//	}

	//	if (!lst.empty())
	//		lst.erase(itMin);
	//}


	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}

//****************************************************************************************
// Удалить N наименьших через sort
//****************************************************************************************

	//list <int> lst; 

	//lst.push_front(3);
	//lst.push_front(4);
	//lst.push_front(1);
	//lst.push_front(2);
	//lst.push_front(5);

	//lst.sort();

	//for (int i = 0; i < 2; i++) 
	//{
	//	if (!lst.empty())
	//		lst.pop_front();
	//}


	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}

//****************************************************************************************
// Список. Более одного раза
//****************************************************************************************

	//list <int> lst; // создём список с элементами типа int
	//list <int> lst22; // создём список с элементами типа int

	//lst.push_front(2);
	//lst.push_front(2);
	//lst.push_front(3);
	//lst.push_front(3);
	//lst.push_front(4);

	//lst.sort();

	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	//list <int>::iterator it = lst.begin();
	//int x = *it;
	//int d = 1;

	//bool first = true;

	//for (; it != lst.end(); it++)
	//{
	//	if (x == *it && first)
	//	{
	//		first = 0;
	//	}
	//	else if (x == *it && !first)
	//	{
	//		lst22.push_back(x);
	//	}
	//	else if (x != *it)
	//	{
	//		x = *it;
	//		first = 1;
	//		it--;
	//	}
	//}

	//for(list <int>::iterator it = lst22.begin(); it != lst22.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

//****************************************************************************************
// Объединение списков без повторений элементов
//****************************************************************************************

	//list <int> list1; // создём список с элементами типа int
	//list <int> list2; // создём список с элементами типа int

	//list1.push_front(1);
	//list1.push_front(2);
	//list1.push_front(3);

	//list2.push_front(2);
	//list2.push_front(3);
	//list2.push_front(4);

	//for (list <int>::iterator it = list2.begin(); it != list2.end(); it++)
	//{

	//	if (find(list1.begin(), list1.end(), *it) == list1.end())
	//	{
	//		list1.push_back(*it);
	//	}
	//}

	//for(list <int>::iterator it = list1.begin(); it != list1.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;


//****************************************************************************************
// Строка. Заменить подряд идущие
//****************************************************************************************

	//string str = "aaabbbc"; // создём список с элементами типа int

	//char x = str[0];
	//string str2; // создём список с элементами типа int
	//str2 += x;
	//bool first = true;

	//for (int i = 0 ; i < str.length(); i++)
	//{
	//	if (x == str[i] && first)
	//	{
	//		//str2 += str[i];
	//		first = 0; 
	//	}
	//	else if (x == str[i] && !first)
	//	{
	//	}
	//	else if (x != str[i])
	//	{
	//		str2 += str[i];
	//		x = str[i];
	//		first = 1;
	//		//i--;
	//	}
	//}

	//cout << str2;


//****************************************************************************************
// Список. Заменить подряд идущие
//****************************************************************************************

	//list <int> lst; // создём список с элементами типа int

	//lst.push_back(2);
	//lst.push_back(2);
	//lst.push_back(2);
	//lst.push_back(3);
	//lst.push_back(3);
	//lst.push_back(2);
	//lst.push_back(3);
	//lst.push_back(3);
	//lst.push_back(4);

	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	//list <int>::iterator it = lst.begin();
	//
	//int x = *it;

	//bool first = true;

	//for (; it != lst.end();)
	//{
	//	if (x == *it && first)
	//	{
	//		first = 0; 
	//		it++;
	//	}
	//	else if (x == *it && !first)
	//	{
	//		it = lst.erase(it);
	//	}
	//	else if (x != *it)
	//	{
	//		x = *it;
	//		first = 1;
	//	}
	//}

	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

//****************************************************************************************
// 	Отрицательные и остальные
//****************************************************************************************

	//list <int> lst; // создём список с элементами типа int

	//lst.push_back(-1);
	//lst.push_back(-2);
	//lst.push_back(2);
	//lst.push_back(3);
	//lst.push_back(3);
	//lst.push_back(-2);


	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	//for (list <int>::iterator it = lst.begin(); it != lst.end();)
	//{
	//	if (*it < 0)
	//	{
	//		lst.push_front(*it);
	//		it = lst.erase(it);
	//	}
	//	else 
	//	{
	//		it++;
	//	}
	//}

	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

//****************************************************************************************
// Список. Объединить списки.
//****************************************************************************************

	//list <int> list1; // создём список с элементами типа int
	//list <int> list2; // создём список с элементами типа int
	//list <int> list3; // создём список с элементами типа int

	//list1.push_back(0);
	//list1.push_back(1);
	//list1.push_back(2);
	//list1.push_back(3);
	//list1.push_back(4);
	//list1.push_back(5);

	//list2.push_back(0);
	//list2.push_back(1);
	//list2.push_back(2);


	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	
	//bool chet = true;
	//for (list <int>::iterator it = list1.begin(); it != list1.end(); it++)
	//{
	//	if (chet)
	//	{
	//		list3.push_back(*it);
	//	}
	//	chet = !chet;
	//}
	//chet = true;
	//for (list <int>::iterator it = list2.begin(); it != list2.end(); it++)
	//{
	//	if (chet)
	//	{
	//		list3.push_back(*it);
	//	}
	//	chet = !chet;
	//}

	//for(list <int>::iterator it = list3.begin(); it != list3.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

//****************************************************************************************
// Список. Объединить списки.
//****************************************************************************************

	//list <int> list1; // создём список с элементами типа int
	//list <int> list2; // создём список с элементами типа int
	//list <int> list3; // создём список с элементами типа int

	//list1.push_back(0);
	//list1.push_back(1);
	//list1.push_back(1);
	//list1.push_back(1);
	//list1.push_back(3);
	//list1.push_back(3);

	//list2.push_back(0);
	//list2.push_back(1);
	//list2.push_back(1);


	//for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	
	//for (list <int>::iterator it = list1.begin(); it != list1.end(); it++)
	//{
	//	list3.push_back(*it);
	//}

	//for (list <int>::iterator it = list2.begin(); it != list2.end(); it++)
	//{
	//	list3.push_back(*it);
	//}

	//list3.sort();
	//list3.unique();

	//for(list <int>::iterator it = list3.begin(); it != list3.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;


//****************************************************************************************
// Список. Объединить списки 2.
//****************************************************************************************

	//list <int> list1; // создём список с элементами типа int
	//list <int> list2; // создём список с элементами типа int
	//list <int> list3; // создём список с элементами типа int

	//list1.push_back(0);
	//list1.push_back(1);
	//list1.push_back(1);
	//list1.push_back(1);
	//list1.push_back(3);
	//list1.push_back(3);

	//list2.push_back(0);
	//list2.push_back(1);
	//list2.push_back(1);


	////for(list <int>::iterator it = lst.begin(); it != lst.end(); it++)
	////{
	////	cout << *it << " ";
	////}
	////cout << endl;

	//
	//for (list <int>::iterator it = list1.begin(); it != list1.end(); it++)
	//{
	//	list3.push_back(*it);
	//}

	//for (list <int>::iterator it = list2.begin(); it != list2.end(); it++)
	//{
	//	list3.push_back(*it);
	//}

	//list3.sort();
	//list3.unique();

	//for(list <int>::iterator it = list3.begin(); it != list3.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;


//****************************************************************************************
// Массив в вектор
//****************************************************************************************

	//int mas[5] = {1,2,3,2,5};
	//vector <int> vec;
	//for (int i = 0; i < 5; i++) 
	//{
	//	vec.push_back(mas[i]);
	//}

	//for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	cout << vec[i] << endl;
	//}

//****************************************************************************************
// Удалить нечетные
//****************************************************************************************

	//vector <int> vec; // создаём пустой вектор типа int

	//for (int i = 0; i < 10; i++) // перебор элементов вектора через цикл for
	//{
	//	vec.push_back(rand(1,4)); //добавление элемента в конец вектора
	//}

	//printVec(vec);

	//for (int i = 0; i < vec.size(); i++) // перебор элементов вектора через цикл for
	//{
	//	if (vec[i] % 2 == 1)
	//	{
	//		vec[i] = vec.back();
	//		vec.pop_back();
	//		i--;
	//	}
	//}

	//printVec(vec);

//****************************************************************************************
// Тип данных bool
//****************************************************************************************

	//bool b;


	//cin >> b;


	//if (b == true)
	//{
	//	cout << "true";
	//}
	//else
	//{
	//	cout << "false";
	//}

//****************************************************************************************
// спираль
//****************************************************************************************

	//const int N = 12;

	//int mas[N][N] = {
	//				{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	//				{-1,0,0,0,0,0,0,0,0,0,0,-1},
	//				{-1,0,0,0,0,0,0,0,0,0,0,-1},
	//				{-1,0,0,0,0,0,0,0,0,0,0,-1},
	//				{-1,0,0,0,0,0,0,0,0,0,0,-1},
	//				{-1,0,0,0,0,0,0,0,0,0,0,-1},
	//				{-1,0,0,0,0,0,0,0,0,0,0,-1},
	//				{-1,0,0,0,0,0,0,0,0,0,0,-1},
	//				{-1,0,0,0,0,0,0,0,0,0,0,-1},
	//				{-1,0,0,0,0,0,0,0,0,0,0,-1},
	//				{-1,0,0,0,0,0,0,0,0,0,0,-1},
	//				{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} 
	//				};


	//int x = 0 ;
	//int y = 1;
	//int dir = 0;

	//bool find = false;

	//int tx = 0;
	//int ty = 0;

	//int k = 1;

	//while(true)
	//{
	//	while(true)
	//	{
	//		tx = x;
	//		ty = y;

	//		switch(dir)
	//		{
	//			case 0: 
	//				x++; 
	//			break;
	//			case 1: 
	//				y++; 
	//			break;
	//			case 2: 
	//				x--; 
	//			break;
	//			case 3: 
	//				y--; 
	//			break;
	//			
	//		}

	//		if (mas[x][y] == 0)
	//		{
	//			mas[x][y] = k;
	//			k++;
	//		}
	//		else if (mas[x][y] == -1 || mas[x][y] > 0)
	//		{
	//			x = tx;
	//			y = ty;
	//			break;
	//		}
	//	}

	//	if (k > 100)
	//		break;

	//	dir = (dir + 1) % 4;
	//}

	//for(int i=1; i < N-1; i++)
	//{
	//	for (int j=1; j < N-1; j++)
	//	{
	//		cout << right << setw(3) <<	mas[j][i];
	//	}
	//	cout<<endl;
	//}

//****************************************************************************************
// Процедурная генерация 2
//****************************************************************************************
	//const int n = 4;

	//int mas[n][n] = {0};

	//int x,y;

	//srand(time(0));

	//for(int i = 0; i < 100000; i++)
	//{
	//	x = rand()%n;
	//	y = rand()%n;

	//	bool f = 1;

	//	if (x != 0)
	//	{
	//		if (mas[x-1][y] == 1)
	//		{
	//			f = 0;
	//		}
	//	}

	//	if (x != n-1)
	//	{
	//		if (mas[x+1][y] == 1)
	//		{
	//			f = 0;
	//		}
	//	}

	//	if (x != 0 && y != 0)
	//	{
	//		if (mas[x-1][y-1] == 1)
	//		{
	//			f = 0;
	//		}
	//	}

	//	if (x != 0 && y != n-1)
	//	{
	//		if (mas[x-1][y+1] == 1)
	//		{
	//			f = 0;
	//		}
	//	}

	//	if (x != n-1 && y != n-1)
	//	{
	//		if (mas[x+1][y+1] == 1)
	//		{
	//			f = 0;
	//		}
	//	}

	//	if (x != n-1 && y != 0)
	//	{
	//		if (mas[x+1][y-1] == 1)
	//		{
	//			f = 0;
	//		}
	//	}

	//	if (y != 0)
	//	{
	//		if (mas[x][y-1] == 1)
	//		{
	//			f = 0;
	//		}
	//	}		
	//	
	//	if (y != n-1)
	//	{
	//		if (mas[x][y+1] == 1)
	//		{
	//			f = 0;
	//		}
	//	}

	//	if (mas[x][y] == 1)
	//	{
	//		f = 0;
	//	}

	//	if (f)
	//		mas[x][y] = 1;
	//}		

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << mas[i][j];
	//	}
	//	cout << endl;
	//}
//****************************************************************************************
// Процедурная генерация 2 с границами
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

	//	bool f = 1;

	//	if (mas[x-1][y] == 1 ||
	//		mas[x+1][y] == 1 ||
	//		mas[x-1][y-1] == 1 ||
	//		mas[x-1][y+1] == 1 ||
	//		mas[x+1][y-1] == 1 ||
	//		mas[x+1][y+1] == 1 ||
	//		mas[x][y-1] == 1 ||
	//		mas[x][y+1] == 1 ||
	//		mas[x][y] == 1)
	//	{
	//	}
	//	else
	//	{
	//		mas[x][y] = 1;
	//	}
	//}		

	//for (int i = 1; i < n-1; i++)
	//{
	//	for (int j = 1; j < n-1; j++)
	//	{
	//		cout << mas[i][j];
	//	}
	//	cout << endl;
	//}
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
// Минимальный делитель целого числа
//****************************************************************************************

	//int x = 3;
	//int i = 2;
	//while (x % i != 0)
	//{
	//	i++;
	//}
	//cout << i;

//****************************************************************************************
// Максимальный делитель целого числа
//****************************************************************************************

	//int x = 0;
	//cin >> x;
	//int i = x-1;
	//while (x % i != 0)
	//{
	//	i--;
	//}
	//cout << i;

//****************************************************************************************
// Наибольший общий делитель
//****************************************************************************************

	//int x = 0, y = 0;
	//cin >> x >> y;

	//if (x > y)
	//{
	//	swap(x,y);
	//}

	//int i = x;

	//while (x % i != 0 || y % i != 0)
	//{
	//	i--;
	//}
	//cout << i;

//****************************************************************************************
// Сократите дробь
//****************************************************************************************

	//int p = 0, q = 0;
	//int x = 0, y = 0;
	//cin >> p >> q;

	//x = p;
	//y = q;

	//if (x > y)
	//{
	//	swap(x,y);
	//}

	//int i = x;
	//while (x % i != 0 || y % i != 0)
	//{
	//	i--;
	//}
	//
	//cout << p/i << " " << q/i;

//****************************************************************************************
// Наименьшее общее кратное
//****************************************************************************************

	//int x = 0, y = 0, z = 0;
	//cin >> x >> y >> z;

	//int d = 0;

	//if (x >= y && x >= z)
	//	d = x;
	//else if (y >= x && y >= z)
	//	d = y;
	//else
	//	d = z;

	//while (d % x != 0 || d % y != 0 || d % z != 0)
	//{
	//	d++;
	//}

	//cout << d;

//****************************************************************************************
// Простое число
//****************************************************************************************

	int x = 0;
	cin >> x;
	int i = 2;
	while (x % i != 0)
	{
		i++;
	}
	if (x != i)
		cout << 0;
	else
		cout << 1;

//****************************************************************************************
// Простое число до миллиона
//****************************************************************************************
	//for (int i = 1000000; i > 0; i--)
	//{
	//	if (prost(i))
	//	{
	//		cout << i;
	//		break;
	//	}
	//}

//****************************************************************************************
// Числа-близнецы
//****************************************************************************************

	//for (int i = 1; i <= 198; i++)
	//{
	//	if (prost(i) && prost(i+2))
	//	{
	//		cout << i << " " << i+2 << endl;
	//	}
	//}


//****************************************************************************************
// Чётные числа 2 Четные числа 2
//****************************************************************************************

	//int a = 1;
	//int b = 9;

	//if (a % 2 == 1)
	//	a++;

	//while (a <= b)
	//{
	//	cout << a << " ";
	//	a = a + 2;
	//}

//****************************************************************************************
// Оглавление
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
// 	Очередь вещественных чисел
//****************************************************************************************
	//srand(time(0));
	//int b;
	//float a;
	//a=0;
	//b=0;
	//
	//queue <float> que1,que2;
	//stack <float> stk;

	//que1.push(7.8);
	//que1.push(4.8);
	//que1.push(3.9);
	//que1.push(2.4);

	//que2=que1;

	//while(!que2.empty())
	//{
	//	a=a+que2.front();
	//	b++;
	//	que2.pop();
	//}

	//while(que1.front() > a/b)
	//{
	//	que2.push(que1.front());
	//	que1.pop();
	//}

	//que2.push(a/b);

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
// 	Число Исенбаева
//****************************************************************************************
//Isenbaev Oparin Toropov
//Ayzenshteyn Oparin Samsonov
//Ayzenshteyn Chevdar Samsonov
//Fominykh Isenbaev Oparin
//Dublennykh Fominykh Ivankov
//Burmistrov Dublennykh Kurpilyanskiy
//Cormen Leiserson Rivest 


	//const int N = 7;
	// 
	//map<string, int> mp;
	//string s[N][3];
 // 
	//s[0][0] = "Isenbaev";    s[0][1] = "Oparin";     s[0][2] = "Toropov";
	//s[1][0] = "Ayzenshteyn"; s[1][1] = "Oparin";     s[1][2] = "Samsonov";
	//s[2][0] = "Ayzenshteyn"; s[2][1] = "Chevdar";    s[2][2] = "Samsonov";
	//s[3][0] = "Fominykh";    s[3][1] = "Isenbaev";   s[3][2] = "Oparin";
	//s[4][0] = "Dublennykh";  s[4][1] = "Fominykh";   s[4][2] = "Ivankov";
	//s[5][0] = "Burmistrov";  s[5][1] = "Dublennykh"; s[5][2] = "Kurpilyanskiy";
	//s[6][0] = "Cormen";      s[6][1] = "Leiserson";  s[6][2] = "Rivest";

	//mp.insert(pair<string,int>("Isenbaev", 0));

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
// 	Размен купюр (жадный алгоритм)
//****************************************************************************************

	//vector <int> vec;

	//vec.push_back(100);
	//vec.push_back(50);
	//vec.push_back(10);
	//vec.push_back(5);
	//vec.push_back(1);
	//
	//int x = 514;

	//for(int i = 0; i < vec.size(); i++) // i - номер прохода
	//{            
	//	cout << x / vec[i] << " " << vec[i] << endl;
	//	x = x % vec[i];
	//}

	//int x = 1, s = 0;
	//while (x != 0){
	//	cin >> x;
	//	s += x;
	//}
	//cout << "Сумма = " << s << endl;

	//int x = 2,y = 1,z = 0;
	//cout << (x > y && y > z);

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




	//system("cls");

	//ifstream file(fileName.c_str());
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
	//		//cout << (int)ch << " ";

	//		if ((int)ch == 10)
	//		{
	//			vec.push_back(s);
	//			s.clear();
	//		}
	//		else
	//		{
	//			if (s == "int" && ch == 32)
	//			{
	//				s += ch;
	//			}
	//			else if (ch != 32 && (int)ch != 9)
	//				s += ch;
	//		}

	//	}
	//	print(vec);

	//	validSemicolon(vec);
	//	//validRavno(vec);


	//	file.close();
	//}

//****************************************************************************************
// 	поиск максимума
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
	//	
	//	cout << x << endl;

	//	int l = 0;
	//	int r = n-1;
	//	int m = 0;

	//	int find = 0;

	//	//cout << l << " " << m <<  " " << r << " " << vec[m] << endl;

	//	while (l <= r)
	//	{
	//		d++;

	//		m = (l + r) / 2;

	//		if (vec[m] == x) 
	//		{
	//			find = 1; //проверяем ключ со серединным элементом
	//			break;
	//		}

	//		if (vec[m] > x) 
	//			r = m - 1; // проверяем, какую часть нужно отбросить
	//		else 
	//			l = m + 1;

	//	}

	//	if (find)
	//	{
	//		cout << "Найден " << endl;
	//	}
	//	else
	//	{
	//		cout << "Не найден " << endl;
	//	}

	//	cout << n << " " << d << " " << " " << log((float)n) / log(2.0) << endl;

	//	getch();
	//}

	system("pause");
}

 
