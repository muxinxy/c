#include <stdio.h>
#include <WinSock2.h>
#include <time.h>
#pragma comment(lib,"ws2_32.lib")

void usage()//ʹ�÷���˵��

{
    printf("Usage: <socket> [IP] [StartPort]-[EndPort]\n");
    printf("Example: socket 192.168.1.1 80-100\n");
    ExitProcess(1);
}

DWORD WINAPI ThreadProc(LPVOID pPara);

int main(int argc, char *argv[])
{

    WSADATA wsad;//Windows Sockets ����
    SOCKADDR_IN target;
    char *IP,*p;
    USHORT PortEnd,PortStart,i;
    clock_t TimeStart,TimeEnd;
    HANDLE    hThread;
    DWORD    dwThreadId;

    //��������
    if(argc!=3) usage();
    IP = argv[1];  //��һ��������IP
    PortStart = atoi(argv[2]);  //�ڶ��������Ƕ˿ڷ�Χ���ֱ�õ���β�˿�
    for(p = argv[2];*(p++)!='-';);  //ָ������˿ڵ���ʼλ��
    PortEnd = atoi(p);
    printf("Scanner will work on %s %d-%d now..\n",IP,PortStart,PortEnd);
    TimeStart = clock();//���������������̡����������е���clock()������ʱ֮���CPUʱ�Ӽ�ʱ��Ԫ��clock tick��������1����Ϊһ����ʱ��Ԫ

    //���أ������׽��֣���дĿ��������ַ�����˿�ɨ��
    WSAStartup(MAKEWORD(2,2),&wsad);
    target.sin_family = AF_INET;//���õ�ַ��
    target.sin_addr.s_addr = inet_addr(IP);//���õ�ַ
    for(i=PortStart;i<=PortEnd;++i){
    target.sin_port = htons(i);//�����ֽ�ת��Ϊ�����ֽ�

    //�������̽�������
    hThread = CreateThread(NULL,0,ThreadProc,(LPVOID)&target,0,&dwThreadId);
    Sleep(10);  //�������ȵȴ�һ��ʱ�䣬ʹ���ӽ����ܹ���ʱ������ȡ�˿���Ϣ��������������ĳЩ�˿�
    if (hThread == NULL){
        printf("CreateThread() failed: %d\n", (int)GetLastError());
        break;
    }
    CloseHandle(hThread); //������Ҫ���������ص������������ǹص���Ӧ�߳�
    }
    Sleep(50);  //�ȴ���һ��ʱ�䣬�ȴ������ӽ��̽�������
    TimeEnd = clock();
    printf("Time cost:%.3fs\n",(float)(TimeEnd-TimeStart)/CLOCKS_PER_SEC);
    WSACleanup();
    return 0;
}

DWORD WINAPI ThreadProc(LPVOID pParam)//���ж˿�ɨ��
{
    SOCKADDR_IN target = *(SOCKADDR_IN*) pParam;
    SOCKET sConn;
    printf("%s %d\n",inet_ntoa(target.sin_addr),ntohs(target.sin_port));
    sConn = socket(AF_INET,SOCK_STREAM,IPPROTO_IP);
    if(connect(sConn,(const SOCKADDR*) &target,sizeof(target)) == SOCKET_ERROR) return 0;
    printf("Port %d is open\n",ntohs(target.sin_port));//�˿ڿ���
    closesocket(sConn);
    return 0;
}
