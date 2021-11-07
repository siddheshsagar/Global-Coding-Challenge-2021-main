
using namespace std;
#include <string>
#include <iostream>

int solution(int n)
{
    if(n%3==0)
        return (n/3)*2;
    else
        return ((n/3)*2)+1;
}

/*  Do not edit below code */
int main() {
	int n;
	cin >> n;	
    int answer=solution(n);
	cout << answer << endl;	
}
