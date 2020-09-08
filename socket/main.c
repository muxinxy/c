#include <stdio.h>
#include <WinSock2.h>
#include <time.h>
#pragma comment(lib,"ws2_32.lib")

void usage()//使用方法说明

{
    printf("Usage: <socket> [IP] [StartPort]-[EndPort]\n");
    printf("Example: socket 192.168.1.1 80-100\n");
    ExitProcess(1);
}

DWORD WINAPI ThreadProc(LPVOID pPara);

int main(int argc, char *argv[])
{

    WSADATA wsad;//Windows Sockets 数据
    SOCKADDR_IN target;
    char *IP,*p;
    USHORT PortEnd,PortStart,i;
    clock_t TimeStart,TimeEnd;
    HANDLE    hThread;
    DWORD    dwThreadId;

    //参数处理
    if(argc!=3) usage();
    IP = argv[1];  //第一个参数是IP
    PortStart = atoi(argv[2]);  //第二个参数是端口范围，分别得到首尾端口
    for(p = argv[2];*(p++)!='-';);  //指向结束端口的起始位置
    PortEnd = atoi(p);
    printf("Scanner will work on %s %d-%d now..\n",IP,PortStart,PortEnd);
    TimeStart = clock();//“开启这个程序进程”到“程序中调用clock()函数”时之间的CPU时钟计时单元（clock tick）数，以1毫秒为一个计时单元

    //加载，创建套接字，填写目标主机地址，按端口扫描
    WSAStartup(MAKEWORD(2,2),&wsad);
    target.sin_family = AF_INET;//设置地址族
    target.sin_addr.s_addr = inet_addr(IP);//设置地址
    for(i=PortStart;i<=PortEnd;++i){
    target.sin_port = htons(i);//主机字节转换为网络字节

    //创建进程接收数据
    hThread = CreateThread(NULL,0,ThreadProc,(LPVOID)&target,0,&dwThreadId);
    Sleep(10);  //主进程先等待一段时间，使得子进程能够有时间来读取端口信息，不致跳过、错开某些端口
    if (hThread == NULL){
        printf("CreateThread() failed: %d\n", (int)GetLastError());
        break;
    }
    CloseHandle(hThread); //不再需要这个句柄，关掉它，但并非是关掉对应线程
    }
    Sleep(50);  //等待上一段时间，等待所有子进程结束任务
    TimeEnd = clock();
    printf("Time cost:%.3fs\n",(float)(TimeEnd-TimeStart)/CLOCKS_PER_SEC);
    WSACleanup();
    return 0;
}

DWORD WINAPI ThreadProc(LPVOID pParam)//进行端口扫描
{
    SOCKADDR_IN target = *(SOCKADDR_IN*) pParam;
    SOCKET sConn;
    printf("%s %d\n",inet_ntoa(target.sin_addr),ntohs(target.sin_port));
    sConn = socket(AF_INET,SOCK_STREAM,IPPROTO_IP);
    if(connect(sConn,(const SOCKADDR*) &target,sizeof(target)) == SOCKET_ERROR) return 0;
    printf("Port %d is open\n",ntohs(target.sin_port));//端口开放
    closesocket(sConn);
    return 0;
}
