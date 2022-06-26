#define RAILWAYS_NAME "KLNCE"
#define MAX 100
#define MAX_LEN 10

struct Train {
  int id;
  char *name;
  char *from;
  char *to;
  int totalSeats;
  int avalSeats;
  float price;
};
