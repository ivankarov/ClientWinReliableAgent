#include "winservice.h"
#include <stdio.h>
#include <windows.h>
#include <WinUser.h>
int main(){
    SC_HANDLE srv = NULL;
    int code = InitSvc(&srv);
    printf("sv init code: %d \n",code);
    if(code!=1){
        ReportSvc(SERVICE_STOP_PENDING,NO_ERROR,5000);
        ReportSvc(SERVICE_STOPPED,NO_ERROR,5000);
        DelSvc(srv);
        return 0;
    }
    printf("print smth to start service \n");
    int n = 10; 
    while(n==10){
        scanf("%d",&n);
    }
    ReportSvc(SERVICE_START_PENDING,NO_ERROR,5000);
    ReportSvc(SERVICE_RUNNING,NO_ERROR,5000);
    printf("service running \n");
    int code2 = StartServiceA(srv,0,NULL); 
    if(!code2){
        printf("starting failed: %lu\n",GetLastError());
    }
    printf("print smth to delete service \n");
    int n2 = 10; 
    while(n2==10){
        scanf("%d",&n2);
    }   
    ReportSvc(SERVICE_STOP_PENDING,NO_ERROR,5000);
    ReportSvc(SERVICE_STOPPED,NO_ERROR,5000);
    DelSvc(srv);
    return code;
}