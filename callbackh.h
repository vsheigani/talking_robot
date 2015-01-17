#include "stdio.h"
#include "sqlite3.h"
#include "stdlib.h"
#include <stdbool.h>
#include "string.h"

extern int cc;
extern char MyField[100];
extern char MyValue[100];


static int callback(void *NotUsed, int argc, char **argv, char **azColName)

{
   int i;
     for(i=0; i<argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

   printf("\n");
   return 0;
}

static int callback_print(void *NotUsed, int argc, char **argv, char **azColName)

{         
   int i;

   for(i=0; i<argc; i++)
    {
            printf("Smith:%s\n\n", argv[i] ? argv[i] : "NULL");
    }

        return 0;
}

static int callback_find(void *NotUsed, int argc, char **argv, char **azColName)

{         
   int i;

   for(i=0; i<argc; i++)
    {
            if(strcmp(azColName[i],MyField)==0 && strcmp(argv[i],MyValue)==0){
              cc++;
            }
    }

        return cc;
}

