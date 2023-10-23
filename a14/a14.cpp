// a14.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"fa14.h"


int main()
{
    double U, R1, R2, C, tges, tsch;
    int NAnzT;
    double* tFld; 
    double* IFld;
    double Lm, I0, K;


    puts("Einschalten eines RC-Netzwerks");
    puts("++++++++++++++++++++++++++++++");
    printf("\nSpannung U in V:\t\t\t");
    scanf("%lf", &U);
    fflush(stdin);
    printf("\n Widerstand R1 in kOhm :\t\t");
    scanf("%lf", &R1);
    fflush(stdin);
    printf("\n Widerstand R2 in kOhm :\t\t");
    scanf("%lf", &R2);
    fflush(stdin);
    printf("\n Kapazitaet C in mikroF :\t\t");
    scanf("%lf", &C);
    fflush(stdin);
    printf("\n Gesamtzeit der Berechnung in s :\t");
    scanf("%lf", &tges);
    fflush(stdin);
    printf("\n Abstand der Rechnungen in s :\t\t");
    scanf("%lf", &tsch);
    fflush(stdin);

    NAnzT = (int)(1+ tges/tsch);
    Lm = dLm(R1 * 1e3, R2 * 1e3, C * 1e-6);
    I0 = Storm0(R1 * 1e3, R2 * 1e3, U);
    K = dK(R1 * 1e3, R2 * 1e3, U);
    tFld = (double*)malloc(NAnzT * sizeof(double));
    IFld = (double*)malloc(NAnzT * sizeof(double));
  
    printf("\n%d Zeiten t, fuer die Strom berechnet wird, in s:\n", NAnzT);
    puts("-------------------------------------------------------");
 

    for (int x = 0; x < NAnzT; x++) {
        tFld[x] = 0.000 + x * tsch;
        if (x % 6 != 0)printf("\t%.3lf", tFld[x]);
        else printf("\n\t%.3lf", tFld[x]);
    }
    puts("\n\nBerechneter Strom I in mA zu diesen Zeiten:");
    puts("-------------------------------------------------------");
    
    for (int i = 0; i < NAnzT; i++)
    {
       

        IFld[i] = (K * exp(Lm * tFld[i]) + I0)*1e3;
        if (i % 6 != 0)printf("\t%.3lf", IFld[i]);
        else printf("\n\t%.3lf", IFld[i]);
    }
    printf("\n");
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
