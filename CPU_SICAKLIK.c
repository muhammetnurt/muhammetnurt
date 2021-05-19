/*
Bu çalışma için aşağıdaki sitelerden yararlanılmıştır.
	https://man7.org/linux/man-pages/man3/usleep.3.html
	http://www.digitalruh.com/wordpress/2018/07/09/raspberry-pi-ile-thread-kullanarak-tcp-server-uygulamasi/
	https://www.bilgigunlugum.net/prog/cprog/c_stdkut


*/
#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

char CPUtempfile[] = {"/sys/class/thermal/thermal_zone0/temp"};
//RPi için CPU sıcaklık bilgisinin tutulduğu adres.

int main (int argc, char *argv[])
{
	FILE *ftemp;
	float Sicaklik_Deger;
	char* Sicaklik_Okunan, Sicaklik_index;
	char filebuffer[100];
	
	do{
	if((ftemp=fopen(CPUtempfile,"r")) == NULL)
	{
	printf("Dosya açma hatası!\n(%s) Bulunamadı ...\n",CPUtempfile);
	exit(EXIT_FAILURE);
	}	
	fread(filebuffer, sizeof(filebuffer), 1, ftemp);//dosyayı okur ve değerleri filebuffer değişkenine atılır.
	fclose(ftemp);
	Sicaklik_Deger=atoi(filebuffer);
	Sicaklik_Deger=Sicaklik_Deger/1000;//dosyada okunan değerin anlaşılır bir hale gelmesi gerekmektedir.
	
	printf("%5.2f\n",Sicaklik_Deger);
	usleep(500*1000);
	}while(1);
	return 0;
	
}

