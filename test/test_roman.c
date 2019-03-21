/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * d0p1 wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */
#include <stdlib.h>
#include <republican_calendar.h>
#include <string.h>
#include <assert.h>

#include "../src/roman.c"

static void test_to_roman_nulla(void)
{
	char	*res;

	/* init */
	/* run */
	res = to_roman(0);

	/* check */
	assert(strcmp(res, "nulla") == 0);

	free(res);
}

static void test_to_roman_limits(void)
{
	assert(to_roman(-666) == NULL);
	assert(to_roman(999999) == NULL);
}

static void test_to_roman_1000(void)
{
	char *res;

	res = to_roman(1000);

	assert(strcmp(res, "M") == 0);

	free(res);
}

static void test_to_roman_basic_combo_ones(void)
{
	char *r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *r9;

	r1 = to_roman(1);
	r2 = to_roman(2);
	r3 = to_roman(3);
	r4 = to_roman(4);
	r5 = to_roman(5);
	r6 = to_roman(6);
	r7 = to_roman(7); 
	r8 = to_roman(8);
	r9 = to_roman(9);

	assert(strcmp(r1, "I") == 0);
	assert(strcmp(r2, "II") == 0);
	assert(strcmp(r3, "III") == 0);
	assert(strcmp(r4, "IV") == 0);
	assert(strcmp(r5, "V") == 0);
	assert(strcmp(r6, "VI") == 0);
	assert(strcmp(r7, "VII") == 0);
	assert(strcmp(r8, "VIII") == 0);
	assert(strcmp(r9, "IX") == 0);

	free(r1);
	free(r2);
	free(r3);
	free(r4);
	free(r5);
	free(r6);
	free(r7);
	free(r8);
	free(r9);
}

static void test_to_roman_basic_combo_tens(void)
{
	char *r10, *r20, *r30, *r40, *r50, *r60, *r70, *r80, *r90;

	r10 = to_roman(10);
	r20 = to_roman(20);
	r30 = to_roman(30);
	r40 = to_roman(40);
	r50 = to_roman(50);
	r60 = to_roman(60);
	r70 = to_roman(70); 
	r80 = to_roman(80);
	r90 = to_roman(90);

	assert(strcmp(r10, "X") == 0);
	assert(strcmp(r20, "XX") == 0);
	assert(strcmp(r30, "XXX") == 0);
	assert(strcmp(r40, "XL") == 0);
	assert(strcmp(r50, "L") == 0);
	assert(strcmp(r60, "LX") == 0);
	assert(strcmp(r70, "LXX") == 0);
	assert(strcmp(r80, "LXXX") == 0);
	assert(strcmp(r90, "XC") == 0);

	free(r10);
	free(r20);
	free(r30);
	free(r40);
	free(r50);
	free(r60);
	free(r70);
	free(r80);
	free(r90);
}

static void test_to_roman_basic_combo_huns(void)
{
	char *r100, *r200, *r300, *r400, *r500, *r600, *r700, *r800, *r900;

	r100 = to_roman(100);
	r200 = to_roman(200);
	r300 = to_roman(300);
	r400 = to_roman(400);
	r500 = to_roman(500);
	r600 = to_roman(600);
	r700 = to_roman(700); 
	r800 = to_roman(800);
	r900 = to_roman(900);

	assert(strcmp(r100, "C") == 0);
	assert(strcmp(r200, "CC") == 0);
	assert(strcmp(r300, "CCC") == 0);
	assert(strcmp(r400, "CD") == 0);
	assert(strcmp(r500, "D") == 0);
	assert(strcmp(r600, "DC") == 0);
	assert(strcmp(r700, "DCC") == 0);
	assert(strcmp(r800, "DCCC") == 0);
	assert(strcmp(r900, "CM") == 0);

	free(r100);
	free(r200);
	free(r300);
	free(r400);
	free(r500);
	free(r600);
	free(r700);
	free(r800);
	free(r900);
}

static void test_to_roman_1917(void)
{
	char *res;

	res = to_roman(1917);

	assert(strcmp(res, "MCMXVII") == 0);

	free(res);
}

int	main(void)
{
	test_to_roman_nulla();
	test_to_roman_limits();
	test_to_roman_1000();
	test_to_roman_basic_combo_ones();
	test_to_roman_basic_combo_tens();
	test_to_roman_basic_combo_huns();
	test_to_roman_1917();
	return (0);
}
