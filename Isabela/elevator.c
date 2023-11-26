#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int NumeroaPlanta(char planta){

    int num;
    
    switch (planta){

    case 'B':
     num = -1;
      break;

    case 'G':
     num = 0;
      break;

    case '1':
     num = 1;
      break;

    case '2':
      num = 2;
      break;

    case '3':
      num = 3;
      break;

    case '4':
      num = 4;
      break;

    case '5':
      num = 5;
      break;

    case 'A':
      num = 6;
      break;
    }
 return num;
}

char plantaOrigen, plantaDesti, ascensorAssignat;
int ubicacioAssignat, ubicacioAlpha = 'G', ubicacioBeta = 'G', ubicacioGamma = 'G';
int distanciaAlpha = 0, distanciaBeta = 0, distanciaGamma = 0;
int viatgesAlpha = 0, viatgesBeta = 0, viatgesGamma = 0;
int recorregutAlpha = 0, recorregutBeta = 0, recorregutGamma = 0;
int pujadesassignat = 0, baixadesassignat = 0, pujadesAlpha = 0, pujadesBeta = 0, pujadesGamma = 0, baixadesAlpha = 0, baixadesBeta = 0, baixadesGamma = 0;
int pisosAlpha, pisosBeta, pisosGamma;
char incitaciopreus;

void benvinguda() {
    printf("Welcome to our building!\n");
}

void mostramenu() {
    printf("A. Use Elevator | B. Statistics | C. Inspection | Q. Quit\n");
}

void UseElevator() {
    plantaOrigen = 0;
    plantaDesti = 0;
    
    while (plantaOrigen < '1' || plantaOrigen > '5' && plantaOrigen != 'A' && plantaOrigen != 'B' && plantaOrigen != 'G' ){
    printf("From? ");
    scanf("%c", &plantaOrigen);
    scanf("%c", &plantaOrigen);
    }
    while (plantaDesti < '1' || plantaDesti > '5' && plantaDesti != 'A' && plantaDesti != 'B' && plantaDesti != 'G'){
    printf("To? ");
    scanf("%c", &plantaDesti);
    scanf("%c", &plantaDesti);
    }
    if (plantaOrigen == plantaDesti) {
        printf("(ERROR) Are you joking?\n");
        return;
    }
    

    
    distanciaAlpha = abs(NumeroaPlanta(plantaOrigen) - NumeroaPlanta(ubicacioAlpha));
    distanciaBeta = abs(NumeroaPlanta(plantaOrigen) - NumeroaPlanta(ubicacioBeta));
    distanciaGamma = abs(NumeroaPlanta(plantaOrigen) - NumeroaPlanta(ubicacioGamma));
    recorregutAlpha = abs(NumeroaPlanta(plantaDesti) - NumeroaPlanta(plantaOrigen));
    recorregutBeta = abs(NumeroaPlanta(plantaDesti) - NumeroaPlanta(plantaOrigen));
    recorregutGamma = abs(NumeroaPlanta(plantaDesti) - NumeroaPlanta(plantaOrigen));

    // Ascensor assignat
    
    if (distanciaBeta < distanciaGamma && distanciaBeta < distanciaGamma
        ||distanciaBeta == distanciaGamma && distanciaBeta < distanciaAlpha && viatgesBeta < viatgesGamma
        || distanciaBeta == distanciaAlpha && distanciaBeta < distanciaGamma && viatgesBeta < viatgesAlpha
        || distanciaBeta == distanciaAlpha && distanciaBeta == distanciaGamma && viatgesBeta < viatgesAlpha 
        && viatgesBeta < viatgesGamma){
            
        viatgesBeta++;
        ubicacioAssignat = ubicacioBeta;
        printf("Elevator Beta assigned\n");
        
    } else if (distanciaGamma < distanciaAlpha && distanciaBeta < distanciaGamma
    || distanciaGamma == distanciaAlpha && viatgesGamma < viatgesAlpha
    || distanciaGamma == distanciaBeta && viatgesGamma < viatgesBeta) {
        
        viatgesBeta++;
        ubicacioAssignat = ubicacioBeta;
        printf("Elevator Gamma assigned\n");
        
    } else {
        viatgesAlpha++;
        ubicacioAssignat = ubicacioAlpha;
        printf("Elevator Alpha assigned\n");
        
    }



   
        // Recorregut del ascensor per anar a buscar l'usuari
        
        int i;
        if (NumeroaPlanta(ubicacioAssignat) < NumeroaPlanta(plantaOrigen)) {
            for (i = NumeroaPlanta(ubicacioAssignat); i <= NumeroaPlanta(plantaOrigen); i++) {
                if(i == -1){
                    printf("B..");
                }
                else if(i == 0){
                        printf("G..");
                    }
                else if (i == 6){
                           printf("A.."); 
                        }
                else{
                    printf("%d..", i);  
                }
            }
        }
        else {
            for (i = NumeroaPlanta(ubicacioAssignat); i >= NumeroaPlanta(plantaOrigen); i--) {
                if(i == -1){
                  printf("B..");
                }else if(i == 0){
                        printf("G..");   
                }else if (i == 6){
                        printf("A.."); 
                }
                else{
                    printf("%d..", i);  
                }
            }
        }
            
        
        if (NumeroaPlanta(ubicacioAssignat) > NumeroaPlanta(plantaOrigen)) {
            printf(" Going up! "); 
            pujadesassignat++;
            
        } else if (NumeroaPlanta(ubicacioAssignat) < NumeroaPlanta(plantaOrigen)) {
            printf(" Going down! "); 
            baixadesassignat++;
        }

        // Recorregut del ascensor per anar a la planta desti

        int ii;
        if (NumeroaPlanta(plantaOrigen) < NumeroaPlanta(plantaDesti)) {
            for (ii = NumeroaPlanta(plantaOrigen); ii <= NumeroaPlanta(plantaDesti); ii++) {
                if(ii == -1){
                    printf("B..");
                } else if(ii == 0){
                    printf("G..");
                }else if (ii == 6){
                    printf("A..");
                }
                else{
                    printf("%d..", ii);
                }
            }
        
            printf("\n\n");
        } else {
            for (ii = NumeroaPlanta(plantaOrigen); ii >= NumeroaPlanta(plantaDesti); ii--) {
               if(ii == -1){
                  printf("B..");
                }else if(ii == 0){
                        printf("G..");   
                }else if (ii == 6){
                        printf("A.."); 
                }
                else{
                    printf("%d..", ii);;  
                }
            }
        
            
            printf("\n\n");
        }
}

void Statistics() {

     if (ubicacioAlpha == ubicacioAssignat){
            pujadesAlpha = pujadesassignat;
            baixadesAlpha = baixadesassignat;
            pisosAlpha = pisosAlpha + distanciaAlpha + recorregutAlpha;
    
        } else if (ubicacioBeta == ubicacioAssignat){
            pujadesBeta = pujadesassignat;
            baixadesBeta= baixadesassignat;
            pisosBeta = pisosBeta + distanciaBeta + recorregutBeta;

        }else if (ubicacioGamma == ubicacioAssignat){
            pujadesGamma = pujadesassignat;
            baixadesGamma = baixadesassignat;
            pisosGamma =  pisosGamma + distanciaGamma + recorregutGamma;
        }


    printf("ALPHA: %d rides (%d-%d) and %d floors traveled\n", viatgesAlpha, pujadesAlpha, baixadesAlpha, pisosAlpha);
    printf("BETA: %d rides (%d-%d) and %d floors traveled\n", viatgesBeta, pujadesBeta, baixadesBeta, pisosBeta);
    printf("GAMMA: %d rides (%d-%d) and %d floors traveles\n", viatgesGamma, pujadesGamma, baixadesGamma, pisosGamma);
    printf("\n\n");
}

void Inspection() {
    #define FLOORS_FOR_INSPECTION 12
    #define INSPECTION_PRICE 150

    int preuAlpha, preuBeta, preuGamma, preutotal;

    preuAlpha = 0;
    preuBeta = 0;
    preuGamma = 0;
    

    if (pisosAlpha > 12) {
        printf("Elevator Alpha: inspection required\n");

    } else if (pisosBeta > 12) {
        printf("Elevator Beta: inspection required\n");

    } else if (pisosGamma > 12) {
        printf("Elevator Gamma: inspection required\n");

    } else if ((pisosGamma <= 12) && (pisosBeta <= 12) && (pisosAlpha <= 12)) {
        printf("No required inspection\n");

    }
    
    if ((pisosAlpha > 12) || (pisosBeta > 12) || (pisosGamma > 12)){
        do {
            printf("Perform inspection? \n");
            scanf("%c", &incitaciopreus);
        } while ((incitaciopreus == 'y') && (incitaciopreus == 'Y')); 
          if (pisosAlpha >= 12){
              printf("Elevator Alpha inspected! (%d euros)\n", preuAlpha);
            }else if (pisosBeta >= 12){
              printf("Elevator Beta inspected! (%d euros)\n", preuBeta);
            } else if (pisosGamma >= 12){
              printf("Elevator Gamma inspected! (%d euros)\n", preuGamma);
            }
    }
   

    preutotal = (preuAlpha + preuBeta + preuGamma);
    preuAlpha = ((pisosAlpha / 12) * 150);
    preuBeta = ((pisosBeta / 12) * 150);
    preuGamma = ((pisosGamma / 12) * 150);
    
    printf("Accumulated expense: %d euros\n\n", preutotal);


}

void Quit() {
    printf("See you later! ");
}


  int main() {
      char option;
      benvinguda();
      do {
          mostramenu();
          printf("Enter option: ");
          scanf(" %c", &option);
          switch (option) {
              
              case 'a':
              case 'A':
              UseElevator();
              break;
              
              case 'b':
              case 'B':
              Statistics();
              break;
              
              case 'c':
              case 'C':
              Inspection();
              break;
              
              case 'd':
              case 'D':
              Quit();
              break;
              
              default:
              printf("Invalid option. Please try again.\n");
            }
        }while (option !='D' || option !='d');
        
        return 0;
    }