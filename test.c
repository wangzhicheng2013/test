#include <stdio.h>
#include <stdlib.h>
typedef struct _BodyBuilder
{
    void (*play)();
} BodyBuilder;
typedef struct _BailPlaying
{
    void (*play)();
} BailPlaying;
typedef struct _PlayRequest
{
    int type;
    void *pPlaying;
} PlayRequest;
#define BODY_BUILDER_TYPE 0
#define BAIL_PLAYING_TYPE 1
void person_playing(PlayRequest *pPlayRequest)
{
    if ((NULL == pPlayRequest) || (NULL == pPlayRequest->pPlaying))
    {
        return;
    }
    switch (pPlayRequest->type)
    {
    case BODY_BUILDER_TYPE:
        ((BodyBuilder *)pPlayRequest->pPlaying)->play();
        break;
    case BAIL_PLAYING_TYPE:
        ((PlayRequest *)pPlayRequest->pPlaying)->play();
        break;
    }
}
void body_building() 
{
    printf("body building!\n");
}
int main() 
{
    BodyBuilder bodyBuilder;
    bodyBuilder.play = body_building;
    PlayRequest request;
    request.type = BODY_BUILDER_TYPE;
    request.pPlaying = &bodyBuilder;
    person_playing(&request);

    return 0;
}
