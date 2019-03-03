#include <iostream>
#include <string.h>

using namespace std;

void compute_next(char pattern[], int next[], int n){
    next[0] = 0;
    int pos = 1;
    int pattern_pos = 0;    

    while (pos < n){
        if (pattern[pattern_pos] == pattern[pos]){
            // 假设当前位置和前缀的对应位置相同,则next为上一个位置next+1;
            pattern_pos++;
            next[pos] = pattern_pos;
	    pos++;
 	}else{
            if (pattern_pos > 0){
                // 当pattern_pos 大于0时,尝试用pattern中的子对称的序列匹配。
	        pattern_pos = next[pattern_pos - 1];
            }else{
                // 假设前缀匹配位置已经在第一位，则取下一位的pattern
                pos++;
            }
	}

    }


}


void search_by_kpm(char searched[], char pattern[]){
    int i = strlen(searched);
    int j = strlen(pattern);

    int * next = (int *)malloc(sizeof(int) * j);
    memset(next, 0, j);

    compute_next(pattern, next, j);

    int i_begin = 0;
    int j_begin = 0;

    while (i_begin < i){

        cout << i_begin << "," << j_begin << endl;
        if (searched[i_begin] == pattern[j_begin]){
	    // 判断当前的pattern是否匹配字符的对应位置
            i_begin ++;
            j_begin ++;
        }else{
            if (j_begin != 0){
	        j_begin = next[j_begin];
            }else{
	        i_begin ++;
            }
        }

        if (j_begin == j){
	    // 当j已经完整匹配上后,调整j_begin
            cout << "match:" << i_begin << endl;
            j_begin = next[j_begin - 1];
            j_begin ++;
        }


    }  

}


int main(int args, char ** argv){
    char pattern[] = "ababcababc";
    char searched[] = "absdababcababcabceababcababc";
    search_by_kpm(searched, pattern);

    /*
    for (int i = 0; i < length; i++){
        cout << i << ":" << next[i] << endl;
    }
    */
    return 0;
}
