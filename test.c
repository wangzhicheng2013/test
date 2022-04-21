#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Template
{
    int title;
    int font;
    int lineDistance;
    void (*operate)(struct _Template *pTemplate);
} Template;
void operate(struct _Template *pTemplate)
{
    if (pTemplate)
    {
        printf("title:%d, font:%d, lineDistance:%d\n", pTemplate->title, pTemplate->font, pTemplate->lineDistance);
    }
}
/*typedef struct _TemplateFactory
{
    Template **pTemplates;
    int num;
    int size;
    Template *GetTemplate(struct _TemplateFactory *pTemplateFactory, int title, int font, int lineDistance);
    void (*free)(struct _TemplateFactory *pTemplateFactory);
} TemplateFactory;
Template *GetTemplate(struct _TemplateFactory *pTemplateFactory, int title, int font, int lineDistance)
{
    int index = 0;
    Template *pTemplate = NULL;
    Template **pTemplates = NULL;
    if (NULL == pTemplateFactory)
    {
        return NULL;
    }
    for (;index < pTemplateFactory->num;index++)
    {
        if (title != pTemplateFactory->pTemplates[index]->title) 
        {
            continue;
        }
        if (font != pTemplateFactory->pTemplates[index]->font) 
        {
            continue;
        }
        if (lineDistance != pTemplateFactory->pTemplates[index]->lineDistance) 
        {
            continue;
        }
        return pTemplateFactory->pTemplates[index];
    }
    pTemplate = (Template *)malloc(sizeof(Template));
    if (NULL == pTemplate)
    {
        return NULL;
    }
    pTemplate->title = title;
    pTemplate->font = font;
    pTemplate->lineDistance = lineDistance;
    if (pTemplateFactory->num < pTemplateFactory->size)
    {
        pTemplateFactory->pTemplates[index] = pTemplate;
        ++(pTemplateFactory->num);
        return pTemplate;
    }
    pTemplates = (Template **)malloc(sizeof(Template *) * (2 * pTemplateFactory->size));
    if (NULL == pTemplates)
    {
        return NULL;
    }
    memmove(pTemplates, pTemplateFactory->pTemplates, pTemplateFactory->size);
    free(pTemplateFactory->pTemplates);
    pTemplateFactory->pTemplates = pTemplates;
    pTemplateFactory->pTemplates[pTemplateFactory->size] = pTemplate;
    pTemplateFactory->size *= 2;
    ++(pTemplateFactory->num);
    return pTemplate;
}
void free(struct _TemplateFactory *pTemplateFactory)
{
    int index = 0;
    Template *pTemplate = NULL;
    for (;index < pTemplateFactory->size;index++)
    {
        pTemplate = pTemplateFactory->pTemplates[index];
        if (pTemplate)
        {
            free(pTemplate);
        }
    }
    if (pTemplateFactory->pTemplates)
    {
        free(pTemplateFactory->pTemplates);
    }
}*/
int main() 
{
   /* TemplateFactory templateFactory = { 0 };
    templateFactory.GetTemplate = GetTemplate;
    templateFactory.free = free;
    Template *pTemplate = templateFactory.GetTemplate(&templateFactory, 1, 2, 3);
    if (pTemplate != NULL)
    {
        pTemplate->operate(pTemplate);
    }
    templateFactory.free();
*/
    return 0;
}
