#include "lib/IP2Location.h"
#include <string.h>
#include <arpa/inet.h>

int main (int argc, char** argv) {

	FILE *file;
	char ipCheck[20]; /* Maximum output   */

	IP2Location *IP2LocationObj = IP2Location_open("/usr/share/ip2location/ip2location.bin");
	IP2LocationRecord *record = NULL;

	/* Check availability of the ip2location database */

	if (IP2LocationObj == NULL) {
		printf("ip2location database not found at : /usr/share/ip2location/ip2location.bin");
		exit(1);
	}
	
	/* Check correct IP format */

	char isValidipCheck(char *ipCheck) {

		struct sockaddr_in sa;
		int result = inet_pton(AF_INET, ipCheck, &(sa.sin_addr));
		return result;
	}

	/* Check for empty argument */

	if (argv[1] == NULL) {
		printf("use -h or --help for the usage of ip2l\n");
		exit(1);
	} 

	/* Display api version */
	if (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--help")) {
		printf("IP2Location API version: %s (%lu)\n", IP2Location_api_version_string(), IP2Location_api_version_num());
		exit(1);
	}

	/* Help argument */

	if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
		printf("ip2l version 0.1\n");
		printf("\n");
		printf("Simple parser for ip2location lite database, currently only display the country code. \n");
		printf("IP2L use the free IP2Location lite database and API, available at https://ip2location.com/.\n");
		printf("\n\n");
		printf("Usage : ./ip2l /home/linux/ipfile.txt \n");
		printf("To get a proper output, the file should contain 1 ip by line.\n");
		printf("\n\n");
		printf("IP2L options :\n");
		printf("  -h or --help  Print this message.\n");
		printf("  -v or --version  Print the IP2Location API version.\n");
		exit(1);
	}

	else {

	file = fopen(argv[1], "r");

		if (file == NULL) {
			printf("%s not found\n", argv[1]);
			exit(1);
		}

	}
	
	while (fgets(ipCheck, sizeof(ipCheck), file)) {
	
		ipCheck[strcspn(ipCheck, "\n")] = 0;

		/* Strip newline from the curent line */

		if (isValidipCheck(ipCheck) != 1) {

			printf("%s invalid ip format\n", ipCheck);
			
			/* Stop output of the string after 15 chars */

			if (!strchr(ipCheck, '\n')) 
				continue;	
		}

		else {
			
			record = IP2Location_get_all(IP2LocationObj, ipCheck);

			/* Print country code following by the IP */

			if (record != NULL)	{
				printf("[%s] %s\n", record->country_short, ipCheck);
			} 

			/* Free array record for the next iteration */

			IP2Location_free_record(record);
		} 
	}

	fclose(file);
	exit(1);
}
