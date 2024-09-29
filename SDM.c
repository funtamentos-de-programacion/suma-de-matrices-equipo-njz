/*
programa de suma de matrices
@authors: Martinez Garcia Nour, Vargas Aguilar Joana Amilet, Villegas Gurrola Zara Paulina
@date: 28/09/2024
*/
#include <stdio.h>
#define TAM 100
int main(){
  int a[TAM][TAM], b[TAM][TAM], c[TAM][TAM];
  int m, n, p, q;
  int i, j;
  do{
    printf("Ingresa las dimensiones de la primer matriz\n");
    scanf("%d %d", &m, &n);
    printf("Ingresa las dimensiones de la segunda matriz\n");
    scanf("%d %d", &p, &q);
  }while(m!=p || n!=q || m <=0 || n<=0 || p <= 0 ||  q <=0);

  for(i =0; i <m; i++){
    for(j=0; j <n ; j++){
      scanf("%d", &a[i][j]);
      scanf("%d", &b[i][j]);
      suma[i][j] =  a[i][j] + b[i][j];
    }
  }
   printf("la suma de las matrices es:\n");
  for(i =0; i <m; i++){
    for(j=0; j <n ; j++){
      printf("%d", suma[i][j]);
    }
   printf("\n");
  }
  //TODO(1): Colocar el código para leer la segunda matriz
  //TODO(2): Colocar el código para sumar las matrices
  //TODO(3): Colocar el código para mostrar la matriz C
  return 0;
}
test_main.c
+57
Original file line number	Diff line number	Diff line change
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>
START_TEST(test_suma_matrices) {
    FILE *fp;
    char output[256];
    char expected_output[] = "Resultado de la suma:\n6\t8\t\n10\t12\t\n";
    // Ejecutar el programa principal
    fp = popen("./main_program", "w");
    if (fp == NULL) {
        perror("Error al abrir el programa");
        return;
    }
    fprintf(fp, "2 2\n2 2\n1 2\n3 4\n5 6\n7 8\n");
    pclose(fp);
    // Leer la salida
    fp = popen("./main_program", "r");
    fread(output, sizeof(char), 255, fp);
    pclose(fp);
    // Comparar la salida con la salida esperada
    ck_assert_str_eq(output, expected_output);
}
END_TEST
Suite* suma_suite(void) {
    Suite* suite;
    TCase* tcase;
    suite = suite_create("Suma");
    tcase = tcase_create("Pruebas");
    tcase_add_test(tcase, test_suma_matrices);
    suite_add_tcase(suite, tcase);
    return suite;
}
int main(void) {
    int number_failed;
    Suite* suite;
    SRunner* runner;
    suite = suma_suite();
    runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (number_failed == 0) ? 0 : 1;
} 