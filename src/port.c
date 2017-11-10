#include "erl_port.h"

int main(void)
{
  erl_init(NULL, 0);
  byte buf[BUFSIZ];
  FILE *f = fopen("/tmp/port", "a");

  while(read_cmd(buf) > 0)
  {
    int index = 0;
    ETERM* term;
    int res = ei_decode_term(buf, &index, term);

    fprintf(f, "%i\n", res);
    fflush(f);
  }
  return 1;
}
