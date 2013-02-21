test:
	gcc -Wall control_test.c control.c -o control_test && ./control_test

.PHONY:	test
