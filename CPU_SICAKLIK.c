#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
//int usleep(useconds_t usec);
char CPUtempfile[] = {"/sys/class/thermal/thermal_zone0/temp"};


int main (int argc, char *argv[])
{
	FILE *ftemp;
	float Sicaklik_Deger;
	char* Sicaklik_Okunan, Sicaklik_index;
	FILE *fp;
	char filebuffer[100];
	
	do{
	if((fp=fopen(CPUtempfile,"r")) == NULL)
	{
	printf("Dosya açma hatası!\n(%s) Bulunamadı ...\n",CPUtempfile);
	exit(EXIT_FAILURE);
	}	
	fread(filebuffer, sizeof(filebuffer), 1, fp);
	fclose(fp);
	Sicaklik_Deger=atoi(filebuffer);
	Sicaklik_Deger=Sicaklik_Deger/1000;
	
	printf("%5.2f\n",Sicaklik_Deger);
	usleep(500*1000);
	}while(1);
	return 0;
	
}

