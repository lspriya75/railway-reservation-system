void printArray(char *arr[], int n) {
  for (int i=0; i<n; i++) {
    printf("%d) %s\n", i+1, arr[i]);
  }
}

void nl() {
  printf("\n");
}

void bye() {
  nl(); printf("Bye!"); nl();
}

void thanks() {
  printf("Thanks for using %s Railways", RAILWAYS_NAME); nl();
}

void exitView() {
  thanks();
  bye();
  exit(1);
}

int randticketno() {
  srand( time( NULL ) );
  int no = rand() % 9000 + 1000;
  return no;
}

void timeout() {
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Time: %s", asctime (timeinfo) );
}