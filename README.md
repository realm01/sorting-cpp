Sorting in CPP
==============

I implemented these 3 sorting algorithms in c++:

  - bubblesort
  - heapsort
  - quicksort

Why?
----
Because: fun!

Usage
-----
```c++
#include "quicksort.h"

int size = 100;
int my_ints = new int[size];

/* do some stuff */

qsort(my_ints, size);
```

For the other sorting algorithms just include the appropriate header.

Methods:
```c++
bsort(T*, int);   # bubblesort
qsort(T*, int);   # quicksort
hsort(T*, int);   # heapsort
```

Performance
-----------
Here are some the results of some test runs I made:

The Computer I used:
  - Ubuntu 14.04
  - 1 Core (3.40 ghz)
  - 4 gb RAM

```sh
# I am sorting only integers here, also the time is in ms and it represents the
# cpu time used. (so not the real time consumed)
# 10 000 integers

# bubblesort
280.292
272.54
268.62

# quicksort
0.67
0.708
0.557

# heapsort
2.279
2.305
2.285

# this is quite boring ..... lets have some fun with a lot more numbers:
# 10 000 000 integers

# bubblesort
<takes ages ...>
# The average compute time is O(n^2), so yeah ...

# quicksort
602.829
587.033
619.979

# heapsort
3766.53
3987.11
3870.48
```
