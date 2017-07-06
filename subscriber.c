/* File name: subscriber.c */
#include "common.h"
#include "time.h"

void printTime(J t) {
  time_t timval= t / 1000000000;
  struct tm *timeInfo= localtime(&timval);

  printf("%dD%02d:%02d:%02d.%09lld ", timeInfo->tm_yday, timeInfo->tm_hour,
         timeInfo->tm_min, timeInfo->tm_sec, t % 1000000000);
}

I shapeOfTrade(K x, K tableName) {
  K columns;
  // check that we received 3 element list (`upd;`trade;table)
  if(x->t != 0 || x->n != 3)
    return 0;
  // check that second element is a table name
  if(kK(x)[1]->t != -KS || kK(x)[1]->s != tableName->s)
    return 0;
  // check if last element is a table
  if(kK(x)[2]->t != XT)
    return 0;
  // check that number of columns>=4
  columns= kK(kK(x)[2]->k)[0];
  if(columns->n < 4)
    return 0;
  // you can add more checks here to ensure that types are as expected
  // likely trade update
  return 1;
}

int main() {
  J i;
  I handle;
  I portnumber= 5010;
  S hostname= "localhost";
  S usernamePassword= "kdb:pass";
  K response, table, tableName, columnNames, columnValues;

  handle= khpu(hostname, portnumber, usernamePassword);
  if(!handleOk(handle))
    return EXIT_FAILURE;
  tableName= ks("trade");
  response= k(handle, ".u.sub", r1(tableName), ks(""), (K) 0);
  if(isRemoteErr(response)) {
    r0(tableName);
    kclose(handle);
    return EXIT_FAILURE;
  }
  r0(response);
  while(1) {
    response= k(handle, (S) 0);
    if(!response)
      break;

    if(shapeOfTrade(response, tableName)) {
      table= kK(response)[2]->k;
      columnNames= kK(table)[0];
      columnValues= kK(table)[1];
      printf(" %s %s %s %s\n", kS(columnNames)[0], kS(columnNames)[1],
             kS(columnNames)[2], kS(columnNames)[3]);
      printf(" -----------------------------\n");

      for(i= 0; i < kK(columnValues)[0]->n; i++) {
        printTime(kJ(kK(columnValues)[0])[i]);
        printf("%s ", kS(kK(columnValues)[1])[i]);
        printf("%lf ", kF(kK(columnValues)[2])[i]);
        printf("%lld \n", kJ(kK(columnValues)[3])[i]);
      }
    }
    r0(response);
  }
  r0(tableName);
  kclose(handle);
  return EXIT_SUCCESS;
}
