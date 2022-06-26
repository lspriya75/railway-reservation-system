void topScreen() {
  printf("\nWelcome to %s Railways\n", RAILWAYS_NAME); nl();
}

void mainOptions() {
  char *options[3] = {"Book Trains", "Admin Login", "Exit"};
  printArray(options, 3); nl();
}

void mainOptionsHandle(int option) {
  if (option > 0 && option < 4) { 
    switch (option) {
      case 1:
        userView();
        break;
      case 2:
        adminView();
        break;
      case 3:
        exitView();
        break;
    }
  } else {
    printf("Invalid option!\n");
    bye();
  }
}



void mainOptionsView() {
  mainOptions();
  int option;
  printf("Select an option => ");
  scanf("%d", &option); nl();
  mainOptionsHandle(option);
}

