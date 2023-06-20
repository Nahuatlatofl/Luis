#include <stdio.h>
#include <conio.h>

#define SIZE 100
#define MAXPACIENTS 10

struct Pacient
{
	char name[SIZE];
	int years; 
	int sex;
	float height;
	float weight;
	char disease[SIZE];
	int room;
	char tBlood[2];
	int status;
	float timeM[2];
	char medication[2][SIZE];
};


struct Pacient pacient[MAXPACIENTS];
int room[MAXPACIENTS];

void stop(){
	int tec=0,exitFlag=0;
	do
	{
		printf("presiona enter para continuar\n");
		tec=getch();
		if (tec==13)
		exitFlag=1;	
	}while(exitFlag!=1);
}

void setMedication(int numPacient){
	int i;
	for (i = 0; i < 2; ++i)
	{
		puts("INGRESE EL MEDICAMENTO\n");
		scanf("%s", pacient[numPacient].medication[i]);
		stop();
		puts("INGRESE LA HORA\n");
		scanf("%f", &pacient[numPacient].timeM[i]);
		stop();
	}
}

void getMedication(int numPacient){
	int i;
	for (i = 0; i < 2; ++i)
	{
		printf("MEDICAMENTO: %s    ",pacient[numPacient].medication[i]);
		printf("HORA: %f\n", pacient[numPacient].timeM[i]);
	}
}

int rooms(){
    int rm = 0, i;
    printf("CUARTOS DISPONIBLES\n");

    for(i = 0; i<MAXPACIENTS; ++i){
        if (room[i] == 0){
            printf(":%d",i);
        }
    }

    puts("\nESCOJA UN CUARTO");

    while(1){
        scanf("%d",&rm);
        if(room[rm] == 0){
            room[rm] = -1;
            return rm;
        }
        else{
            printf("ese cuarto esta ocupado ingrese otro\n");
        }
    }
}

void setDataPacient(int numPacient) {
    printf("Ingrese su nombre\n");
    scanf("%s", pacient[numPacient].name);

    printf("Ingrese su edad\n");
    scanf("%d", &pacient[numPacient].years);

    printf("Ingrese su sexo\n");
    printf("[1] HOMBRE\n");
    printf("[2] MUJER\n");
    scanf("%d", &pacient[numPacient].sex);
 
    while (pacient[numPacient].sex < 1 || pacient[numPacient].sex > 2) {
        printf("LA OPCION QUE ESCOGIO NO ES VALIDA\nFAVOR DE INGRESAR OTRO VALOR\n");
        scanf("%d", &pacient[numPacient].sex);
    }

    printf("Ingrese su altura\n");
    scanf("%f", &pacient[numPacient].height);

    printf("Ingrese su peso\n");
    scanf("%f", &pacient[numPacient].weight);

    printf("Ingrese su padecimiento\n");
    scanf("%s", pacient[numPacient].disease);

    printf("Ingrese su cuarto\n");
    pacient[numPacient].room = rooms();

    printf("Ingrese su tipo de sangre\n");
    scanf("%s", pacient[numPacient].tBlood);

    setMedication(numPacient);

    pacient[numPacient].status = 1;
    stop();
}
 
void getDataPacient(int numPacient) {
    if (pacient[numPacient].status = 1){
         printf("NOMBRE: %s\n", pacient[numPacient].name);
         printf("AHNOS: %d\n", pacient[numPacient].years);
         
         if (pacient[numPacient].sex == 1) {
            printf("SEXO: H\n");
         } else {
            printf("SEXO: M\n");
         }
        printf("ALTURA: %3.2f\n", pacient[numPacient].height);
        printf("PESO: %3.2f\n",pacient[numPacient].weight);
        printf("PADECIMIENTO: %s\n", pacient[numPacient].disease);
        printf("CUARTO: %d\n", pacient[numPacient].room);
        printf("TIPO DE SAGRE:%s\n", pacient[numPacient].tBlood);
        printf("ESTADO: ENFERMO\n");

        getMedication(numPacient);
    }  
}
int main(){
	int i,op;

	c:
	puts("[1] INGRESAR DATOS");
	puts("[2] MOSTRAR DATOS");
	scanf("%d", &op);
	switch(op){
	case 1:
		a:
		for (i = 0; i < MAXPACIENTS; ++i){
			setDataPacient(i);
		}
		puts("Quiere mostrar los datos[1] o reingresar datos[2]");
		scanf("%d", &op);
		if(op == 1){
			goto a;
		}else{
			goto b;
		}

		break;
	case 2:

		b:
		for (i = 0; i < MAXPACIENTS; ++i){
			getDataPacient(i);
		}
		break;
	default:
		puts("Esa opcion no existe");
		stop();
		goto c;
	}
		
	return 0;
}
