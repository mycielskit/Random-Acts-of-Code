#include <bits/stdc++.h>
#include "element.cpp"
#include "container.cpp"
#include "klelele.cpp"
#include "stos.cpp"

using namespace std;

int main(){
    Klelele<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}