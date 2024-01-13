#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXVARIABLELENGTH 100
#define MAXTYPELENGTH 16
#define MAXNUMBERPARAMETERS 246
#define MAXSTRINGLENGTH 2048
#define MAXNUMBERVARIABLE 1024
#define MAXNUMBERFUNCTIONS 1024
#define ERRNOFUNCTION -1
#define ERRINVALIDNUMBEROFPARAMETERS -2
#define ERRVARIABLENOTFOUND -4
#define ERRWRONGTYPE 0

union typeVar {
int intval;
float floatval;
char* strval;
char charval;
};

struct var {
	char name[MAXVARIABLELENGTH];
	char type[MAXTYPELENGTH];
};

struct varTableCell {
	struct var currentVar;
	int initialized;
	void *address;
};

struct funcTableCell {
	char name[MAXVARIABLELENGTH];
	char typeReturn[MAXTYPELENGTH];
	int numberParam;
	char typeParam[MAXNUMBERPARAMETERS][MAXTYPELENGTH];
	int reserved;
};

int posVarTable(char *varNames, struct varTableCell *table, int varNum) {
	int pos = -1;
	struct var v;
	for (int i = 0; i < varNum; i++) {
		v = table[i].currentVar;
		if (strcmp(varNames, v.name) == 0) {
			pos = i;
		}
	}

	return pos;
};

void addFuncTable(char *funcName, char *typeReturn, char *params, int pos, 
	struct funcTableCell *table, int reserved) {
	struct funcTableCell c;
	strcpy(c.name, funcName);
	strcpy(c.typeReturn, typeReturn);
	c.numberParam = 0;
	char *paramsCopy = (char *)malloc(sizeof(char) * MAXNUMBERPARAMETERS);
	strcpy(paramsCopy, params);
	char *p = strtok(paramsCopy, " ");
	while (p) {
		strcpy(c.typeParam[c.numberParam++], p);
		p = strtok(NULL, " ");
	}
	c.reserved = reserved;
	table[pos] = c;
}

int checkFunc(char *funcName, char *params, struct funcTableCell *funcTable, 
	struct varTableCell *varTable, int numberFunc, int varNum) {
	int pos = -1;
	for (int i = 0; i < numberFunc; i++) {
		if (strcmp(funcTable[i].name, funcName) == 0) {
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		printf("No se encontro la funcion %s\n", funcName);
		return ERRNOFUNCTION;
	}
	int nrP = 0;
	int ok = 1;
	struct var v;
	int posVar = -1;
	char *paramsCopy = (char *)malloc(sizeof(char) * MAXNUMBERPARAMETERS);
	strcpy(paramsCopy, params);
	char *p = strtok(paramsCopy, " ");

	while (p) {

		if (nrP > funcTable[pos].numberParam) {
			return ERRINVALIDNUMBEROFPARAMETERS;
		}
		posVar = posVarTable(p, varTable, varNum);
		if (posVar != -1) {
			v = varTable[posVar].currentVar;
			if (strcmp(v.type, funcTable[pos].typeParam[nrP]) != 0) {
				ok = 0;
			}
		} else {
			ok = ERRVARIABLENOTFOUND;
		}
		p = strtok(NULL, " ");
		nrP++;
	}

	if (nrP < funcTable[pos].numberParam) {
		return ERRINVALIDNUMBEROFPARAMETERS - 1;
	}

	return ok;
}

int checkInitializedVar(char *varName, struct varTableCell *table, int varNum) {
	int pos = posVarTable(varName, table, varNum);
	if (pos == -1) {
		return -1;
	}

	return table[pos].initialized;
}

int addVarTable(char *varType, char *varNames, int pos, struct varTableCell *table) {
	struct var v;
	if (posVarTable(varNames, table, pos) != -1) {
		return 0;
	}
	struct varTableCell c;
	strcpy(v.name, varNames);
	strcpy(v.type, varType);
	void *varAddress;
	void *address;
	if (strcmp(varType, "int") == 0) {
		address = malloc(sizeof(int));
	}
	if (strcmp(varType, "char") == 0) {
		address = malloc(sizeof(char));
	}
	if (strcmp(varType, "float") == 0) {
		address = malloc(sizeof(float));
	}
	if (strcmp(varType, "string") == 0) {
		address = malloc(MAXSTRINGLENGTH * sizeof(char));
	}
	c.currentVar = v;
	c.address = address;
	c.initialized = 0;

	table[pos] = c;
	fflush(stdout);

	return 1;
};

void print(char *varName, struct varTableCell *table, int varNum) {
	int pos = posVarTable(varName, table, varNum);

	if (pos == -1) {
		return;
	}
	if (table[pos].initialized == 0) {
		printf("<la variable no esta inicializada!\n");
		return;
	}
	struct var v = table[pos].currentVar;

	if (strcmp(v.type, "int") == 0) {
		int valueInt = *((int *)table[pos].address);
		printf("%s = %d\n", varName, valueInt);

		return ;
	}
	if (strcmp(v.type, "char") == 0) {
		char valueChar = *((char *)table[pos].address);
		printf("%s = \'%c\'\n",varName , valueChar);

		return ;
	}
	if (strcmp(v.type, "float") == 0) {
		float valueFloat = *((float *)table[pos].address);
		printf("%s = %f\n", varName, valueFloat);

		return ;	
	}
	if (strcmp(v.type, "string") == 0) {
		printf("%s = \"%s\"\n", varName, (char *)table[pos].address);

		return ;
	}

};

int setValue(char *varNames, char *value, struct varTableCell *table, int varNum) {

	int pos = posVarTable(varNames, table, varNum);

	if (pos == -1) {
		return 0;
	}
	struct var v = table[pos].currentVar;
	if ((value[0] >= 'a' && value[0] <='z') || (value[0] >= 'A' && value[0] <= 'Z')) {
		int posVar2 = -1;
		posVar2 = posVarTable(value, table, varNum);
		struct var v2 = table[posVar2].currentVar;
		if (strcmp(v.type, v2.type) == 0) {
			int dim;
			if (strcmp(v.type, "int") == 0) {
				dim = sizeof(int);
			}
			if (strcmp(v.type, "char") == 0) {
				dim = sizeof(char);
			}
			if (strcmp(v.type, "float") == 0) {
				dim = sizeof(float);
			}
			if (strcmp(v.type, "string") == 0) {
				strcpy(table[pos].address, table[posVar2].address);
			} else {
				int i;
				memcpy(&i, table[posVar2].address, dim);
				memcpy(table[pos].address, table[posVar2].address, dim);
				table[pos].initialized = 1;
			}

			return 1;
		} else {

			return 0;
		}
	}
	if (strcmp(v.type, "int") == 0 && value[0] >= '0' && value[0] <= '9') {
		int valueInt = atoi(value);
		memcpy(table[pos].address, &valueInt, sizeof(int));

		table[pos].initialized = 1;
		return 1;
	}
	if (strcmp(v.type, "char") == 0 && value[0] == '\'') {
		char valueChar = value[1];
		memcpy(table[pos].address, &valueChar, sizeof(char));

		table[pos].initialized = 1;
		return 1;
	}
	if (strcmp(v.type, "float") == 0  && value[0] >= '0' && value[0] <= '9') {
		float valueFloat = atof(value);
		memcpy(table[pos].address, &valueFloat, sizeof(float));

		table[pos].initialized = 1;
		return 1;	
	}
	if (strcmp(v.type, "string") == 0 && value[0] == '\"') {
		char *p = (char *)malloc(MAXSTRINGLENGTH * sizeof(char));
		for (int i = 0; i < strlen(value) - 2; i++) {
			p[i] = value[i+1];
		}
		strcpy(table[pos].address, p);

		table[pos].initialized = 1;
		return 1;
	}

	return 0;
};

int maximum(int a, int b) {
	if (a < b) {
		return b;
	}

	return a;
};

int minimum(int a, int b) {
	if (a < b) {
		return a;
	}

	return b;
};


int execReservedFunc(int pos, char *params, struct varTableCell *varTable, int varNum,
	struct funcTableCell *funcTable, int numberFunc) {
	printf(" ");
	if (strcmp(funcTable[pos].name, "maximum") == 0) {
		int a, b;
		char *p = strtok(params, " ");
		int pos = posVarTable(p, varTable, varNum);
		a = *((int *)varTable[pos].address);
		p = strtok(NULL, " ");
		pos = posVarTable(p, varTable, varNum);
		b = *((int *)varTable[pos].address);

		return maximum(a, b);
	}
	if (strcmp(funcTable[pos].name, "minimum") == 0) {
		int a, b;
		char *p = strtok(params, " ");
		int pos = posVarTable(p, varTable, varNum);
		a = *((int *)varTable[pos].address);
		p = strtok(NULL, " ");
		pos = posVarTable(p, varTable, varNum);
		b = *((int *)varTable[pos].address);

		return minimum(a, b);
	}
};

