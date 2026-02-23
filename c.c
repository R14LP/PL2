#include <stdio.h>
#include <string.h>

int main(){
    char str[5][100], temp[100];

    printf("ver:");

    for(int i =0; i<5; i++){
        scanf("%s", str[i]);
    }

    for(int i =0; i< 4;i++){
        for(int j = i+1; j<5;j++){
            if(strcmp(str[i], str[j]) > 0){
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nIn lexicographical order:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%s\n", str[i]);
    }

    return 0;
}


//#include <stdio.h>
//#include <ctype.h>
//
//int main(){
//    char str[100];
//    int sesli =0,sessiz =0, bosluk=0, sayi=0;
//
//    printf("ver:");
//    fgets(str, sizeof(str), stdin);
//
//    for(int i=0; str[i] != '\0'; i++){
//        char ch= tolower(str[i]);
//
//        if(ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i'){
//            sesli++;
//        }else if(ch > 'a' && ch <= 'z'){
//            sessiz++;
//        }else if(ch >= '0' && ch <='9'){
//            sayi++;
//        }else if(ch == ' '){
//            bosluk++;
//        }
//    }
//    printf("\nsesli: %d, sessiz: %d, sayi: %d, bosluk: %d", sesli, sessiz, sayi, bosluk);
//
//    return 0;
//}


//#include <stdio.h>
//#include <ctype.h>
//
//int main(){
//    char str[100];
//    int j=0;
//
//    printf("ver:");
//    scanf("%s",str);
//
//    for(int i=0; str[i] != '\0';i++)
//    {
//        if(isalpha(str[i])){
//            str[j] = str[i];
//            j++;
//        }
//    }
//
//    str[j] = '\0';
//    printf("\nson hali:%s", str);
//    
//
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main(){
//    char str1[100], str2[100];
//
//    printf("ver:");
//    scanf("%s",str1);
//    printf("\nver:");
//    scanf("%s",str2);
//
//    strcat(str1, str2);
//
//    printf("\n%s",str1);
//    return 0;
//}