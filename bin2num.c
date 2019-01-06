/* Convert a binary string to a number */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define PASS 1
#define FAIL 0

#define YES 1
#define NO 0
#define MAX_LEN 32


/* Uncomment this macro to make testing exit out immediately after a failure */
#define HARDCHECK 


#ifdef HARDCHECK
#define CHECK(tmp, rc) if(tmp == FAIL) return -1;
#else
#define CHECK(tmp, rc) if(tmp == FAIL && rc == PASS) rc = FAIL;
#endif


/* go through digits and make sure string is a valid binary string */

int is_binary_string(const char *str, int ndigits)
{
    int n;
    int rc;

    rc = YES;
    for(n = 0; n < ndigits; n++) {
        if(str[n] != '0' && str[n] != '1') {
            rc = NO;
            break;
        }
    }
    return rc;
}

/* TODO: implement this algorithm */

unsigned long bin2num(const char *str, int ndigits)
{
    int n;
    unsigned long num;
	int pls;

    if(is_binary_string(str, ndigits) == NO) {
        return 0;
    }

    num = 0;
	pls = pow(2,ndigits-1);

    for(n = 0; n < ndigits; n++) {
        if(str[n] == '1') {
			num += pls; 
        } else if(str[n] == '0') {
            /* TODO: what do we do when we find a 0? */
        }
		pls /= 2; }

    return num;
}

static int test_bin2num(const char *str, int ndigits, unsigned long expected)
{
    unsigned long out;
    fprintf(stdout, "Testing '");
    fwrite(str, 1, ndigits, stdout);
    fprintf(stdout, "': ");
    out = bin2num(str, ndigits);

    if(out != expected) {
        fprintf(stdout, "FAIL\n");
        fprintf(stdout, "Expected %lu, but returned %lu\n", expected, out);
        return FAIL;
    }

    fprintf(stdout, "PASS\n");
    return PASS;
}

static int test_binary_string(const char *str, int ndigits, int expected)
{
    int rc;
    rc = is_binary_string(str, ndigits);
    fprintf(stdout, "Validating '");
    fwrite(str, 1, ndigits, stdout);
    fprintf(stdout, "': ");
    fflush(stdout);

    if(rc != expected) {
        fprintf(stdout, "FAIL\n");
        if(rc == NO) {
            fprintf(stdout, "This was actually a valid binary number\n");
        } else {
            fprintf(stdout, "This was actually an invalid binary number\n");
        }
        return FAIL;
    }

    fprintf(stdout, "PASS\n");
    fflush(stdout);
    return PASS;
}

int test_program(void)
{
    int rc;
    int tmp;

    rc = PASS;

    fprintf(stdout, "\n*** Testing number validator:\n\n");
    /* test binary number validator */
    tmp = test_binary_string("010101", 6, YES);
    CHECK(tmp, rc);
    tmp = test_binary_string("deeznutz", 8, NO);
    CHECK(tmp, rc);
    tmp = test_binary_string("0101a10", 7, NO);
    CHECK(tmp, rc);
    tmp = test_binary_string("010 001", 7, NO);
    CHECK(tmp, rc);
    tmp = test_binary_string("12", 2, NO);
    CHECK(tmp, rc);

    fprintf(stdout, "\n*** Testing bin2num algorithm:\n\n");
    /* count up to 7 */
    tmp = test_bin2num("0", 1, 0);
    CHECK(tmp, rc);
    tmp = test_bin2num("1", 1, 1);
    CHECK(tmp, rc);
    tmp = test_bin2num("10", 2, 2);
    CHECK(tmp, rc);
    tmp = test_bin2num("11", 2, 3);
    CHECK(tmp, rc);
    tmp = test_bin2num("100", 3, 4);
    CHECK(tmp, rc);
    tmp = test_bin2num("101", 3, 5);
    CHECK(tmp, rc);
    tmp = test_bin2num("110", 3, 6);
    CHECK(tmp, rc);
    tmp = test_bin2num("111", 3, 7);
    CHECK(tmp, rc);

    fprintf(stdout, "\n*** Testing zero-padding:\n\n");
    /* make sure leftpadded zeros are handled okay */
    tmp = test_bin2num("001", 3, 1);
    CHECK(tmp, rc);
    tmp = test_bin2num("000", 3, 0);
    CHECK(tmp, rc);
    tmp = test_bin2num("00010", 5, 2);
    CHECK(tmp, rc);


    if(rc == PASS) {
        return 0;
    } else {
        fprintf(stdout, "Oops! Looks like some tests failed.\n");
        return -1;
    }
} 

int main(int argc, char *argv[])
{
	char a_word[MAX_LEN];

	printf ("Welcome to the Cardinal Binary Converter. Please input a binary string: ");
	scanf ("%s", a_word);
	printf ("You entered: %s\n", a_word);
	return 0;
	/* return test_program(); */
}
