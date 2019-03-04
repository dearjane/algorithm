#include <iostream>
#include <string>


using namespace std;


int main(int args, char ** argv){

    string s = "15";
    int length = s.size();

    if (length > 0 && s[0] == '0')
        return 0;

    int * f = new int[length + 1];    
    f[0] = 1;    
    f[1] = 1;    
    

    /***
     ***   f[i] 为斐波那契数列
     ***。   f[i] = condition1 * f[i - 1] + f[i - 2] * condition2;
     ***/

    for (int i = 2; i <= length; i++){
        f[i] = f[i - 1] * (int)(s[i - 1] != '0') + f[i - 2] * (int)(s[i - 2] == '1' || (s[i - 1] < '7' && s[i - 2] == '2'));

    }

    cout <<  f[length] << endl;
    return 0;
}
