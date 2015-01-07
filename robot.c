//This is a talking robot
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlite3.h"



sqlite3 *db;
   int  rc;


static int callback_find(void *NotUsed, int argc, char **argv, char **azColName)

{
   int i;

   for(i=0; i<argc; i++)
    {
            printf("Smith:%s\n\n", argv[i] ? argv[i] : "NULL");
    }

   //printf("\n");
   return 0;
}

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

  void create_db(char db_name[])
  {
   // sqlite3 *db;
  // int  rc;

   rc = sqlite3_open(db_name, &db);
   if( rc )
      {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
      }
   else
      {
         fprintf(stdout, "Database %s opened successfully\n",db_name);
      }
   }


   void select_data(char q[])
   {
   
   char *zErrMsg = 0;
   char sql_string[700] = "SELECT answer FROM negos WHERE question=";


      strcat(sql_string,"\"");
      strcat(sql_string,q);
      strcat(sql_string,"\"");

     // printf("%s\n", sql_string);



//   sprintf(sql_string,"SELECT answer FROM negos WHERE question= "%s"",q);

   char *sql= sql_string;


   /* Execute SQL statement */

   rc = sqlite3_exec(db, sql, callback_find, 0, &zErrMsg);
   if( rc != SQLITE_OK )
   {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   else
   {
   //   fprintf(stdout, "Table Selected succefully\n");
   }
 }
   

int main(int argc, const char *argv[])
{
   
char db_name[100]="nego.db";
char q[512];

create_db(db_name);
system("clear");
while(strcmp(q,"bye") != 0) {
    printf("You:");
    scanf("%s",q);
    select_data(q);
}
printf("Smith:bye\n");
getchar();
getchar();
system("clear");

    return 0;
}

