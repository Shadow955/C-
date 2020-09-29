#define funds = 0;
#include<stdio.h>
#include<stdlib.h>
#include"base_struct.h"
#include "file.h"
#include"allfunc.h"
int main() {
	if (!openfile())
		return 0;
	read_and_link();
}