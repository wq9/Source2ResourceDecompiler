#include "s2rd.h"


int main(int argc, char** argv) {
	if(argc < 2) {
		fprintf(stderr, "Error: Insufficient arguments. Use `s2rd help` for more info.\n");
		return 1;
	}
	if(strncmp(argv[1],"help",5)==0) {
		fprintf(stderr, "Source 2 Resource Decompiler\nUsage: s2rd <action>\nActions:\n\thelp\t\t\t\tDisplay this message.\n\tdecompile <filein> <fileout>\tDecompile a file.\n");
		return 0;
	} else if(strncmp(argv[1],"decompile",10)==0) {
		if(argc < 4) {
			fprintf(stderr, "Error: insufficient arguments. Use `s2rd help` for more info.\n");
			return 1;
		}
		filedata* data = loadfile(argv[2]);
		if(data == NULL) {
			fprintf(stderr, "Error: Unable to load '%s' properly.\n",argv[1]);
		}
		return 0;
	} else {
		fprintf(stderr, "Error: Unknown action '%s'.\n",argv[1]);
		return 1;
	}
}
