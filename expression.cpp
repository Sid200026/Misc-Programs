#include<stdio.h>
#include<math.h>
int main() {
    int x,y;
    scanf("%d%d",&y,&x);
    int negative = 5 * pow(x,3) - 4 * pow(x,2) + 3 * x + 2;
    int ans = y - negative;
    printf("%d",ans);
}