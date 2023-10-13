#include <stdio.h>
#define MAX_ALU 100
#define MAX_CUR 50

int main(){
	//Datos de alumno
	int arrCodAlumno[MAX_ALU], nAlumnos = 0;
	double arrEscAlumno[MAX_ALU];
	int cod;
	double costo;
	
	//Leer y guardar alumnos
	/*C�digo*/
	for(nAlumnos=0; nAlumnos<MAX_ALU; nAlumnos++){
		scanf("%d", &cod);
		if(cod == 0) break;
		scanf("%lf", &costo);
		arrCodAlumno[nAlumnos] = cod;
		arrEscAlumno[nAlumnos] = costo;
	}
	
	//Datos de curso
	int arrCodCurso[MAX_CUR], nCursos = 0;
	double arrCredCurso[MAX_CUR];
	//Leer y guardar cursos
	/*C�digo*/
	for(nCursos = 0; nCursos<MAX_CUR; nCursos++){
		scanf("%d", &cod);
		if(cod == 0) break;
		scanf("%lf", &costo);
		arrCodCurso[nCursos] = cod;
		arrCredCurso[nCursos] = costo;
	}

	//Totales a acumular
	double arrTotalCreditos[MAX_ALU], arrTotalApagar[MAX_ALU];
	
	//Inicializaci�n en arreglos de totales
	/*Codigo*/
	for(int i=0; i<MAX_ALU; i++){
		arrTotalCreditos[i] = 0;
		arrTotalApagar[i] = 0;
	}
	
	//Leer matr�culas y actualizar arreglos
	/*C�digo*/
	int alumno = 1;
	int curso = 1;

	while(alumno){
		scanf("%d", &alumno);
		if(alumno == 0) break;
		scanf("%d", &curso);
		int i = 0, j = 0;
		for(i=0; i<nAlumnos; i++)
			if(alumno == arrCodAlumno[i]) break;
		
		for(j = 0; j<nCursos; j++)
			if(curso == arrCodCurso[j]) break;

		arrTotalCreditos[i] += arrCredCurso[j];
		arrTotalApagar[i] += arrCredCurso[j]*arrEscAlumno[i];
	}
	
	//Imprimir reporte
	/*C�digo*/
	printf("Alumno Costo/Credito Total Creditos Total a Pagar\n");
	for(int i=0; i<nAlumnos; i++){
		printf("%d   s/.%5.2f   %5.2f   s/.%5.2f\n", arrCodAlumno[i], arrEscAlumno[i], arrTotalCreditos[i], arrTotalApagar[i]);
	}

}