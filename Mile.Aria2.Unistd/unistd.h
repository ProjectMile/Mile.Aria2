#include <stdint.h>

typedef uint16_t mode_t;

#define STDIN_FILENO _fileno(stdin)

#ifndef S_ISREG
#define S_ISREG(x) (_S_IFREG & x)
#endif

#ifndef S_ISDIR
#define S_ISDIR(x) (_S_IFDIR & x)
#endif
