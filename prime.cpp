    #include<stdio.h>
    #include<math.h>
    int main() {
        int num;
        scanf("%d",&num);
        bool flag = false;
        for(int i = 2; i<sqrt(num); i++) {
            if(num % i == 0) {
                flag = true;
                break;
            }
        }
        if(flag || num == 1) {
            printf("Not Prime");
        }
        else {
            printf("Prime");
        }
    }