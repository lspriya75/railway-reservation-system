void adminOptions() {
  char *options[3] = {"Add trains", "Get trains", "Exit"};
  printArray(options, 3); nl();
}

int getCount() {
  FILE *fptr;
  fptr = fopen("trains.txt", "r");
  int count = 0;
  char c;
  for (c=getc(fptr); c!=EOF; c = getc(fptr)) {
    if (c == '\n') {
      count++;
    }
  }
  fclose(fptr);
  return count;
}

void addTrain(struct Train data) {
  FILE *fptr;
  fptr = fopen("trains.txt", "a");
  fprintf(fptr, "%d %s %s %s %d %d %f\n", data.id, data.name, data.from, data.to, data.totalSeats, data.avalSeats, data.price);
  fclose(fptr);
}

void addTrainView() {
  int id, totalSeats, avalSeats;
  float price;
  char name[MAX], from[MAX], to[MAX];
  id = getCount()+1;
  printf("Enter the name of the train: ");
  scanf("%s", name);
  printf("Enter the from location: ");
  scanf("%s", from);
  printf("Enter the to location: ");
  scanf("%s", to);
  printf("Enter total seat count: ");
  scanf("%d", &totalSeats);
  printf("Enter available seats: ");
  scanf("%d", &avalSeats);
  printf("Enter the price of the ticket: ");
  scanf("%f", &price);
  
  struct Train traindata = {id, name, from, to, totalSeats, avalSeats, price};
  addTrain(traindata);
  printf("Train added successfully!"); nl();
}

void viewTrains(int id, char name[], char from[], char to[], int totalSeats, int avalSeats, float price) {
  printf("%s Train Data\n\n", name);
  printf("Train id: %d", id); nl();
  printf("Train name: %s", name); nl();
  printf("Train from city: %s", from); nl();
  printf("Train to city: %s", to); nl();
  printf("Train total seat count: %d", totalSeats); nl();
  printf("Train available seats: %d", avalSeats); nl();
  printf("Train ticket price: %.2f", price); nl();
  printf("Train Dealer: %s", RAILWAYS_NAME); nl();
}

void viewTrainsView() {
  FILE *fptr;
  fptr = fopen("trains.txt", "r");
  int id, totalSeats, avalSeats;
  float price;
  char name[MAX], from[MAX], to[MAX];
  fscanf(fptr, "%d %s %s %s %d %d %f", &id, name, from, to, &totalSeats, &avalSeats, &price);
  while (!feof(fptr)) {
    viewTrains(id, name, from, to, totalSeats, avalSeats, price); nl(); nl();
    fscanf(fptr, "%d %s %s %s %d %d %f", &id, name, from, to, &totalSeats, &avalSeats, &price);
  }
  fclose(fptr);
}


void adminView() {
  adminOptions();
  int option;
  printf("Select an option: ");
  scanf("%d", &option); nl();
  if (option > 0 && option < 4) {
    switch (option) {
      case 1:
        addTrainView();
        break;
      case 2:
        viewTrainsView();
        break;
      case 3:
        exitView();
        break;
    }
  }
}