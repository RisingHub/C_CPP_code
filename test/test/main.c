//
//  main.c
//  test
//
//  Created by 昇 R on 2025/6/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char name[20];
    int n;
    scanf("%[^*]“, name);
          //scanf("%d", &n);
    printf("%s %d", name, n);
    return 0;
}
