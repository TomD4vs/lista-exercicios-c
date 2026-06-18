#include <iostream>
using namespace std;

void trocar(int* a, int* b) {
    *a = *a ^ *b;  
    *b = *a ^ *b;  
    *a = *a ^ *b;  
}

int main() {
    int x = 10;
    int y = 20;
    
    cout << "Valores antes da troca:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    
    trocar(&x, &y);
    
    cout << "\nValores depois da troca:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    
    return 0;
}
