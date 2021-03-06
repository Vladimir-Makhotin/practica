#include <iostream>
#include <ctime>

using namespace std;

struct cell
{
    int i;
    int j;
};

int** createmass(int& n, int& m);
cell searchel(const int n, const int m, int*** mass);
int** solve(const int n, const int m, int*** mass, const cell el);
void output(const int n, const int m, int*** mass);
void delmass(const int n, int*** mass);

int main()
{
    setlocale(LC_ALL, "ru-RU");
    int n, m;
    int** mass = createmass(n, m);
    cell k = searchel(n, m, &mass);
    mass = solve(n, m, &mass, k);
    output(n, m, &mass);
    delmass(n, &mass);
}
int** createmass(int& n, int& m)
{
    int** mass;

    srand(time(NULL));
    cout << "������� ����������� �������" << endl;
    cin >> n >> m;
    mass = new int* [n];
    for (int i = 0; i < n; i++)
    {
        mass[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            mass[i][j] = rand() % 100;
            cout << mass[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    return mass;
}
cell searchel(const int n, const int m, int*** mass)
{
    int ik = 0, jk = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((*mass)[i][j] < (*mass)[ik][jk])
            {
                ik = i;
                jk = j;
            }
        }
    }
    cell el;
    el.i = ik;
    el.j = jk;
    return el;
}
int** solve(const int n, const int m, int*** mass, const cell el)
{
    for (int i = 0; i < n; i++)
    {
        int t = (*mass)[i][0];
        (*mass)[i][0] = (*mass)[i][el.j];
        (*mass)[i][el.j] = t;
    }
    for (int i = 0; i < m; i++)
    {
        int t = (*mass)[0][i];
        (*mass)[0][i] = (*mass)[el.i][i];
        (*mass)[el.i][i] = t;
    }

    return *mass;
}
void output(const int n, const int m, int*** mass)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << (*mass)[i][j] << "\t";
        cout << endl;
    }
}
void delmass(const int n, int*** mass)
{
    for (int i = 0; i < n; i++) delete[] (*mass)[i];
    delete[] *mass;
}