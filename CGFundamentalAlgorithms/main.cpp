#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "imgutils.h"
#include "line.h"
#include "linetest.h"

using namespace std;


int main() {
	LineTest test;
	cout << test.Run() << endl;
}