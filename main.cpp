#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


int main (int argc, char *argv[]){

	const char* short_options = "V:L:hv";

	const struct option long_options[] = {
		{"Value",	required_argument,	NULL,'V'},
		{"List",	required_argument,	NULL,'L'},
		{"help",	no_argument,		NULL,'h'},
		{"version",	no_argument,		NULL,'v'},
		{NULL,		0,					NULL, 0}
	};

	int parse, option_index = -1;

	bool counter[4] = {false, false, false, false};

	while ((parse=getopt_long(argc, argv, 
							short_options, 
							long_options, 
							&option_index))!=-1){
		switch(parse){
			case 'V': {
				if (!counter[0]){
					
					printf("Value = %s\n",optarg);
					counter[0] = true;
				}
				break;
			}
			case 'L': {
				if (!counter[1]){
					
					printf("List = %s\n",optarg);
					counter[1] = true;
				}
				break;
			}
			case 'h': {
				if (!counter[2]){
					
					printf("Help.\n");
					counter[2] = true;
				}
				break;
			}
			case 'v': {
				if (!counter[3]){
					
					printf("Program version is 1.0.\n");
					counter[3] = true;
				}
				break;
			}
			case '?': default: {
				printf("Unknown option.\n");
				break;
			}
		}
		option_index = -1;
	}
	return 0;
}