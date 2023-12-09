#include <stdio.h>
#include <stdlib.h>

#define Vec(T) struct Vec__##T { T *at; size_t _len; }

#define vec_push(a,v) ((a)->at = realloc((a)->at, ++(a)->_len * sizeof *(a)->at), (a)->at[(a)->_len - 1] = (v))
#define vec_len(a) ((a)._len)

void fill(Vec(int) *vec) {
	for (int i = 0; i < 10; i += 2)
		vec_push(vec, i);
}

int main() {
	Vec(int) x = { 0 };
	fill(&x);
	for (size_t i = 0; i < vec_len(x); ++i)
		printf("%d\n", x.at[i]); // this beautiful at...
}
