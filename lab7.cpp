#include <iostream>
#include <conio.h>
#include <fstream>
#define N 5
using namespace std;
typedef unsigned short int usi;
void input_matr(int (*matr)[N]);
void output_matr(int *matr);
void output_matr(int (*matr)[N]);
void solve(int (*matr)[N], int *vect, usi &y);
usi rek_y(usi j);
void foutput(int *vect, usi &y);
void finput(int (*matr)[N]);

int main() 
{
	setlocale(LC_ALL, "Rus");
	usi mode, Y(0);
	int A[N][N], X[N];		
	cout << "��������� ������ �������(1) ��� � ������� �����(2)?" << endl;
	cout << "�����: ";
	cin >> mode;
	switch (mode) 
	{
	    case 1: 
	    input_matr(A);
		break;
	    case 2: 
		finput(A);
		break;
	    default: 
		cout << "Error!!!";
		getch();
		return 1;
	}
	output_matr(A);
	solve(A, X, Y);
	output_matr(X);
	cout << Y;
	foutput(X, Y);
	getch();
	return 0;
}
void input_matr(int (*matr)[N]) 
{
	cout << "Input massive:" << endl;
	for (usi i = 0; i < N; i++)
		for (usi j = 0; j < N; j++)
			cin >> matr[i][j];
}
void output_matr(int *matr) 
{
	cout << "Output massive:" << endl;
	for (usi i = 0; i < N; i++) 
	{
		cout << matr[i] << '\t';
	}
	cout << endl;
}
void output_matr(int (*matr)[N]) 
{
	cout << "Output massive:" << endl;
	for (usi i = 0; i < N; i++) 
	{
		for (usi j = 0; j < N; j++)
			cout << matr[i][j] << '\t';
		cout << endl;
	}
}
void solve(int (*matr)[N], int *vect, usi &y) 
{
	usi i,j; bool check=false; int mas[4];
	for(j=0;j<N;j++)
	{
	    vect[j]=0;
	}
	for(i=0;i<N;i++)
	{
	    for(j=0;j<N;j++)
	    {
	        if(matr[i][j]>0) vect[j]=vect[j]+matr[i][j];
	    }
	}
	for(j=0;j<N;j++)
	{
	    mas[j]=rek_y(j);
	    if(vect[j]==mas[j]) check=true; else check=false;
	}
	if (check==true) y=1; else y=0;
}
usi rek_y(usi j) 
{
    if(j<0) return 0;
    if(j==0||j==1) return 1;
    return rek_y(j-1)+rek_y(j-2);
}
void finput(int(*matr)[N]) 
{
	ifstream in("in.txt", ios::in);
	if (!in) return;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			in >> matr[i][j];
	in.close();
}
void foutput(int *vect, usi &y) 
{
	ofstream out("out.txt", ios::out);
	out << "Massive \'X\'" << endl;
	for (usi i = 0; i < N; i++)
		out << vect[i] << ' ';
	out << endl;
	out << "Y = " << y;
	out.close();
}