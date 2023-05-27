#include<iostream>

using namespace std;

int main(){
    
    int s;
    cin >> s;

    int d = (s / 60 / 60 / 24);
    s -= (d * 24 * 60 * 60);

    int h = (s / 60 / 60);
    s -= (h * 60 * 60);

    int m = (s / 60);
    s -= (m * 60);

    cout << d << ":" << h << ":" << m << ":" << s << endl;
    return 0;

}