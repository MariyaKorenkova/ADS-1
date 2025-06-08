// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
	for (uint64_t i = 2; i < value / 2; i++) {
		if (value % i == 0) {
			return false;
		}
	}
	return true;
}

uint64_t nPrime(uint64_t n) {
	uint64_t i = 0, j = 2;
	while (true) {
		if (checkPrime(j)) {
			if (i == n) return j;
		}
		j++;
	}
}

uint64_t nextPrime(uint64_t value) {
	uint64_t i = value;
	while (true) {
		if (checkPrime(i)) return i;
		i++;
	}
}

uint64_t sumPrime(uint64_t hbound) {
	uint64_t sum = 0;
	for (uint64_t i = 2; i < hbound; i++) {
		if (checkPrime(i)) {
			sum += i;
		}
	}
	return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
	uint64_t cnt = 0, prev = 2;
	for (uint64_t i = lbound; i < hbound; i++) {
		if (checkPrime(i)) {
			if (prev + 2 == i) cnt++;
			prev = i;
		}
	}
	return cnt;
}
