void nl() {
  printf("\n");
}

void printArray(char *arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d) %s\n", i+1, arr[i]);
  }
}

void mainOptionsHandle(int option) {
  if (option > 0 && option < 4) {
    printf("Valid option %d\n", option);
  } else {
    printf("Invalid option %d\n", option);
  }
}
