/*******************************************************
      PIC16F877 ile Grafik LCD Uygulamas�
*******************************************************/

#include <16f877.h>     // Kullan�lacak denetleyicinin ba�l�k dosyas� tan�t�l�yor.

#fuses HS,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD // Denetleyici konfig�rasyon ayarlar�

#use delay (clock=20000000) // Gecikme fonksiyonu i�in kullan�lacak osilat�r frekans� belirtiliyor.

#include <HDM64GS12.c> // HDM64GS12.c dosyas� programa ekleniyor
#include <graphics.c>  // graphics.c dosyas� programa ekleniyor

char yazi1[]="YTU";        // Karakter dizisi tan�mlan�yor
char yazi2[]="UNIVERSITY";  // Karakter dizisi tan�mlan�yor
int i,x1,y1,x2,y2;

/********* ANA PROGRAM FONKS�YONU********/

void main ( )
{
   setup_psp(PSP_DISABLED);        // PSP birimi devre d���
   setup_timer_1(T1_DISABLED);     // T1 zamanlay�c�s� devre d���
   setup_timer_2(T2_DISABLED,0,1); // T2 zamanlay�c�s� devre d���
   setup_adc_ports(NO_ANALOGS);    // ANALOG giri� yok
   setup_adc(ADC_OFF);             // ADC birimi devre d���
   setup_CCP1(CCP_OFF);            // CCP1 birimi devre d���
   setup_CCP2(CCP_OFF);            // CCP2 birimi devre d���

   glcd_init(ON); // Grafik LCD haz�rlan�yor ve ekran siliniyor

   while(1)
   {
      glcd_init(ON); // Ekran siliniyor
      glcd_text57(39, 5, yazi1, 2, ON);  // GLCD'de yaz� yazd�r�l�yor
      glcd_text57(5, 30, yazi2, 2, ON);  // GLCD'de yaz� yazd�r�l�yor
      delay_ms(2000);

      glcd_init(ON); // Ekran siliniyor
      x1=5;
      y1=5;
      x2=100;
      y2=5;
      for(i=0;i<6;i++)
      {
         glcd_line(x1, y1, x2, y2, ON); // GLCD'de �izgi �izdiriliyor
         y2=y1+=10; // y2=y1=y2+10; anlam�nda
         x2-=10;    // x2=x2-10; anlam�nda
         delay_ms(1000);
      }

      glcd_init(ON); // Ekran siliniyor
      x1=y1=10;
      for (i=0;i<120;i++)
      {
         glcd_pixel(x1,y1,ON); // Ekranda istenen pikseller aktif yap�l�yor
         y1=x1++;   // y1=x1+1; anlam�nda
         delay_ms(50);
      }

      glcd_init(ON); // Ekran siliniyor
      y2=60;
      x1=5;
      for (i=0;i<8;i++)
      {
         glcd_bar(x1, 0, x1, y2, 10, ON); // GLCD'de �ubuk �izdiriliyor
         delay_ms(1000);
         x1+=15; // x1=x1+15; anlam�nda
         y2-=5;  // y2=y2-5; anlam�nda
      }

      glcd_init(ON); // Ekran siliniyor
      for(i=0;i<=30;i=i+5)
      {
         glcd_circle(60, 30, i, NO, ON); // GLCD'de Daire �izdiriliyor
         delay_ms(1000);
      }

      glcd_init(ON); // Ekran siliniyor
      x1=5;
      y1=5;
      x2=120;
      y2=63;
      for(i=0;i<6;i++)
      {
         glcd_rect(x1, y1, x2, y2, NO, ON); // GLCD'de dikd�trgen �izdiriliyor
         y1=x1+=5; // y1=x1+5; anlam�nda
         x2-=5;    // x2=x2-5; anlam�nda
         y2-=5;    // y2=y2-5; anlam�nda
         delay_ms(500);
      }


   }
}
