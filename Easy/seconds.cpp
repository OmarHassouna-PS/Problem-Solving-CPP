#include<iostream>

using namespace std;

int main(){
    
    float d, h, m, s;
    cin >> d >> h >> m >> s;

    float ss = (d * 24 * 60 * 60 ) + (h * 60 * 60) + (m * 60) + s;

    cout << ss << endl;
    return 0;

}