/*
Use of swap as temp var name avoids the case
where x or y is named the same as the temp var

do

while(0)

allows use of idiom if (cond) swap(t,x, y); else

*/
#define swap(t, x, y)\
do { \
    t swap = x; \
    x = y; \
    y = swap; \
} while(0)
