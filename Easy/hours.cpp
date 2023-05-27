#include <iostream>
using namespace std;

int main() {

    int Hours = 0;
    cin >> Hours;

    int Years = ( Hours / 24 / 30.41 / 12 );
    Hours -= ( Years * 12 * 30.41 * 24 );

    int Month = ( Hours / 24 / 30.41 );
    Hours -= ( Month * 30.41 * 24 );

    int Days = (Hours / 24);
    Hours -= ( Days * 24 );

    cout << Hours << " Hours\n" << Days << " Days\n" <<  Month << " Month\n" << Years << " Years\n";
    return 0;


}