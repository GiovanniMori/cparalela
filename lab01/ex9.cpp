// 9. Crie uma função capaz de substituir todos os números negativos de uma matriz por seu módulo.
// 
//  Duvidas:
#include <iostream>
using namespace std;

int convertArray(int a[], int sizeofArray)

{
    bool v = false;
    for (int i = 0; i < sizeofArray; i++)
    {

        if (a[i] < 0)
        {
            a[i] = abs(a[i]);
            v = true;
        }

        cout << i << "  " << a[i] << endl;
    }
    return v;
}
int main()

{
    int b[5] = {1, -2, 3, 5, 2};
    cout << convertArray(b, 5) << endl;

    return 0;
}