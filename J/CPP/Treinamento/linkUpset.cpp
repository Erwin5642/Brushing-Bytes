#include <cstdio>
#include <cstring>
#include <cctype>
 
int main() {
    char input[100001];
    int it;
    

    scanf("%s", input);
    
    for(it = 0; input[it] != '\0' && it < 10001; it++){
        if(isupper(input[it])){
            input[it] += 32;
        }
    }
    
    if(strstr(input, "zelda")){
        printf("Link Bolado\n");
    }
    else{
        printf("Link Tranquilo\n");
    }
 
    return 0;
}