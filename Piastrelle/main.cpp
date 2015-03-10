/*
 * Piastrelle.cc
 *
 *  Created on: 10/mar/2015
 *      Author: enric_000
 */

#include "Utils.h"
#include "Read.h"
#include "Write.h"
#include "Listify.h"


int main (void)
{
	int N = Read::read_file("files/input.txt");
	assert( N >= 1 && N <= 25 );

	string s = Listify::listify(N);

	Write::write_file("files/output.txt", s);

	return 0;

}


