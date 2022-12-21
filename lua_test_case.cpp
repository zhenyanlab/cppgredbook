#include "gtest/gtest.h"
#include "Test.h"
int tool_malloc(void** p,int size){
    char *  ptr =(char * ) malloc(size);
    memset(ptr,65,size);
    memset(ptr+(size-1),0,1);
    printf("ptr: %s,%p,%p\n",ptr,ptr,&ptr);
    *p = ptr;
    return 0;
}
int tool_delete(void * p){
    printf("tool_delete: %p\n",p);
    free(p);
    p = NULL;
    return 0;
}
TEST(lua_test_case, main)
{
    printf("void * lens:|%lu|\n",sizeof(void * ));
    printf("int * lens:|%lu|\n",sizeof(int * ));
    printf("int lens:|%lu|\n",sizeof(int));

    void *  pin=malloc(sizeof(int));
    memset(pin,0,sizeof(int));
    char * pcin=(char *)pin;
    for(int i=0;i<sizeof(int)-1;i++){
        printf("%d",i);
        memset(pcin,65,1); 
        printf("%c\n",*pcin);
        pcin=pcin+1;
    }
    printf("%s\n",(char *)pin);
    memset(pin,66,3); 
    printf("strlen:|%lu|\n",strlen((char *)pin));
    printf("%s\n",(char *)pin);
    void ** pp;
    tool_malloc(pp,10);
    printf("pp: %s,%p,%p,%p\n",(char *)*pp,*pp,pp,0);

    char * ppp=(char*)*pp;
    printf("**p: %s",ppp);
    tool_delete(*pp);
    printf("ppp: %s,%p,%p,%p\n",(char *)*pp,*pp,pp,0);

}

TEST(lua_test_case ,luaImport){
    printf("%s","test");
    
}