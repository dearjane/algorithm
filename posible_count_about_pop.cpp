/*****************************************************
>File Name: stack.cpp
> Author: chenxiaoqiang
> mail: 916684703@qq.com
> Created Time: 三  3/ 6 15:49:09 2019
******************************************************/
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    int length = 5;
    int a[5][5] = {0};

    for(int i = 0; i < 5; i++){
      for(int j = 0; j <= i; j++){
          if (j == 0 || i == 0)
	      a[i][j] = 1;
	  else
	      a[i][j] = a[i - 1][j] + a[i][j - 1];
      }
    }

    cout << a[4][4] << endl;
    return 0;
}
