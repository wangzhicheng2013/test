#include <stdio.h>
#include <stdlib.h>
typedef struct _surf_internet 
{
    void (*request)();
} surf_internet;
void ftp_request()
{
    printf("request from ftp\n");
}
void smtp_request()
{
    printf("request from smtp\n");
}
void web_request()
{
    printf("request from web\n");
}
typedef struct _Proxy
{
    surf_internet *client;
} Proxy;
void process(Proxy *proxy) 
{
    if ((NULL == proxy) || (NULL == proxy->client))
    {
        return;
    }
    proxy->client->request();
}
int main() 
{
    Proxy *proxy = (Proxy *)malloc(sizeof(Proxy));
    if (NULL == proxy)
    {
        return -1;
    }
    proxy->client = (surf_internet *)malloc(sizeof(surf_internet));
    if (NULL == proxy->client)
    {
        free(proxy);
        return -1;    
    }
    proxy->client->request = web_request;
    process(proxy);
    free(proxy->client);
    free(proxy);

    return 0;
}
