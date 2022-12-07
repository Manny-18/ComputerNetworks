#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n,r;
struct frame
{
    char ack;
    int data;
}frm[10];

int sender(void);
void recvack(void);
void resend_gb(void);
void goback(void);


int main(){
    printf("\nGoBack \n");
    goback();
}
void goback(){
    sender();
    recvack();
    resend_gb();
    printf("\n all frames sent sucessfully\n");

}

int sender(){
    int i;
    printf("\nEnter number of frames to be sent:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("\nEnter data for frames [%d] ",i);
        scanf("%d",&frm[i].data);
        frm[i].ack='y';

    }
    return 0;
}

void recvack(){
    int i;
    rand();
    r=rand()%n;
    frm[r].ack='n';
    for(i=1;i<=n;i++){
        if(frm[i].ack=='n')
        printf("\nThe frame number %d is not received\n",r);

    }
}
   
void resend_gb(){
    int i;
    printf("\nresending frame %d",r);
    for(i=r;i<=n;i++){
        sleep(2);
        frm[i].ack='y';
        printf("\nReceived data of frame %d id %d",i,frm[i].data);
    }
}