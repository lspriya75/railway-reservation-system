bool check_train_exists(char qfrom[], char qto[]) {
  FILE *fptr;
  fptr = fopen("trains.txt", "r");
  int id, totalSeats, avalSeats;
  float price;
  char name[MAX], from[MAX], to[MAX];
  fscanf(fptr, "%d %s %s %s %d %d %f", &id, name, from, to, &totalSeats, &avalSeats, &price);
  while (!feof(fptr)) {
    if (strcmp(qfrom, from) == 0)
    {
      if (strcmp(qto, to) == 0)
      {
        return true;
      }
    }
    fscanf(fptr, "%d %s %s %s %d %d %f", &id, name, from, to, &totalSeats, &avalSeats, &price);
  }
  fclose(fptr);
  return false;
}

bool check_train_exists_name(char qname[]) {
  FILE *fptr;
  fptr = fopen("trains.txt", "r");
  int id, totalSeats, avalSeats;
  float price;
  char name[MAX], from[MAX], to[MAX];
  fscanf(fptr, "%d %s %s %s %d %d %f", &id, name, from, to, &totalSeats, &avalSeats, &price);
  while (!feof(fptr)) {
    if (strcmp(qname, name) == 0)
    {
      return true;
    }
    fscanf(fptr, "%d %s %s %s %d %d %f", &id, name, from, to, &totalSeats, &avalSeats, &price);
  }
  fclose(fptr);
  return false;
}

void list_trains(char qfrom[], char qto[]) {
  FILE *fptr;
  fptr = fopen("trains.txt", "r");
  int id, totalSeats, avalSeats;
  float price;
  char name[MAX], from[MAX], to[MAX];
  fscanf(fptr, "%d %s %s %s %d %d %f", &id, name, from, to, &totalSeats, &avalSeats, &price);
  while (!feof(fptr)) {
    if (strcmp(qfrom, from) == 0)
    {
      if (strcmp(qto, to) == 0)
      {
        printf("Id: %d Name: %s\n", id, name);
      }
    }
    fscanf(fptr, "%d %s %s %s %d %d %f", &id, name, from, to, &totalSeats, &avalSeats, &price);
  }
  fclose(fptr);
}

void bookTrain(char buyer[], int age, char qname[]) {
  FILE *fptr;
  fptr = fopen("trains.txt", "r");
  int id, totalSeats, avalSeats;
  float price;
  char name[MAX], from[MAX], to[MAX];
  fscanf(fptr, "%d %s %s %s %d %d %f", &id, name, from, to, &totalSeats, &avalSeats, &price);
  while (!feof(fptr)) {
    if (strcmp(qname, name) == 0)
    {
      printf("TICKET RECEIPT"); nl(); nl();
      printf("****** TRAIN TICKET BOOKING DETAILS ******");nl();nl();
      printf("Train Name: %s\n", name);
      printf("From: %s\n", from);
      printf("To: %s\n", to);
      printf("TicketNumber: %s_%d\n", RAILWAYS_NAME, randticketno());
      nl(); nl();
      printf("****** BUYER DETAILS ******");nl();nl();
      printf("Name: %s\n", buyer);
      printf("Age: %d\n", age);
      printf("Booking ");
      timeout();
      nl(); nl();
      printf("*** Kindly save these details for further use! ***"); nl();nl();
      printf("*** %s Railways ***", RAILWAYS_NAME); nl();
    }
    fscanf(fptr, "%d %s %s %s %d %d %f", &id, name, from, to, &totalSeats, &avalSeats, &price);
  }
  fclose(fptr);
}

void userView() {
  char qfrom[MAX], qto[MAX];
  printf("Welcome to %s railway booking", RAILWAYS_NAME); nl();
  printf("Enter from city: ");
  scanf("%s", qfrom);
  printf("Enter to city: ");
  scanf("%s", qto);
  if (check_train_exists(qfrom, qto))
  {
    char qname[MAX];
    printf("\nAvailable Trains\n\n");
    list_trains(qfrom, qto);
    printf("\nEnter an option: ");
    scanf("%s", qname);
    if (!check_train_exists_name(qname))
    {
      printf("Train not exists!\n");
    } else {
      char buyer[MAX];
      int age;
      printf("Enter your name: ");
      scanf("%s", buyer);
      printf("Enter your age: ");
      scanf("%d", &age); nl();
      bookTrain(buyer, age, qname);
    }
  } else {
    printf("Not Exists\n");
  }
}
