void topScreen() {
  printf("\nWelcome to %s Railways\n", RAILWAYS_NAME); nl();
}

void mainOptions() {
  char *options[3] = {"Login", "Admin Login", "Exit"};
  printArray(options, 3); nl();
}

void mainOptionsView() {
  mainOptions();
  int option;
  printf("Select an option => ");
  scanf("%d", &option); nl();
  mainOptionsHandle(option);
}
