#include <stdio.h>
int main(){
    int count=-1, N=-1;
    int number=-1, guess=-1;
    count = 0;
    scanf("%d%d", &number, &N);
    while(count<N){
        scanf("%d", &guess);
        count++;
        if(guess<0){
            break;
        }
        if(guess==number){
            if(count==1){
                printf("Bingo!\n");
                break;
            }
            else if(count<=3){
                printf("Lucky You!\n");
                break;
            }
            else{
                printf("Good Guess!\n");
                break;
            }
        }
        else if(guess<number){
            printf("Too small\n");
        }
        else{
            printf("Too big\n");
        }
    }
    if(guess<0 || count==N&&guess!=number){
        printf("Game Over\n");
    }

    return 0;
}

//��Ȩ����������ΪCSDN�������������¡���ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https://blog.csdn.net/qq_36913610/article/details/81117435
