#include <iostream>
#include <map>
#include <string>

using namespace std;


/**
*** problem distribution:
***
***     给定两个字符串,s1和s2, 将s1表达成一个二分树,然后交换任意一个非叶子节点变成另外一个字符，判断s2能否由s1转变而成。
***
**/


bool DP_found(string  s1, string  s2, map<string, bool>& dp_map){
    int length = s1.size();
    bool flag = false;
    
   if (length == 0){
       return true;
   }else if (length == 1){
       return s1 == s2;
   }else{
       if (s1 == s2)
           return true;
       
       if (dp_map.find(s1 + s2) != dp_map.end()){
           return dp_map[s1 + s2];
       }
       for (int i = 1; i < length && !flag; i++){
           flag = flag || (DP_found(s1.substr(0, i), s2.substr(0, i), dp_map) && DP_found(s1.substr(i, length - i), s2.substr(i, length - i), dp_map));
           
           flag = flag || (DP_found(s1.substr(0, i), s2.substr(length - i, i), dp_map) && DP_found(s1.substr(i, length - i), s2.substr(0, length - i), dp_map));
       }
       
       //cout << "s1:" << s1 << ", s2:" << s2 << ", flag:" << flag << endl;
       dp_map[s1 + s2] = flag;
       return flag;
       
   }
}

int main(int args, char ** argv){
    map<string, bool> dp_map;
    bool flag = DP_found("great", "rgeat", dp_map);
    cout << flag <<endl;
    return 0;
}
