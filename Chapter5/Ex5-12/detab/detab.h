#define TABSTOP 8
#define START_COL 1

int setTab(int *s_col, int *incr, int argc, char *argv[]);
int nextTab(int s_col, int incr, int idx);

void detab(int s_col, int incr);
