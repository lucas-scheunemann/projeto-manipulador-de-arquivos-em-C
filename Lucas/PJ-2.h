#include <stdio.h>
#include <stdlib.h>
//função de teste
int retorno1 (){
	printf("hello world!\n");
	return 0;
}

//fazer cópia de um arquivo
int criarCopia(){
	//ch pegara caractere por caractere
   char ch, source_file[20], target_file[20];
   FILE *source, *target;
 
   printf("Digite o nome do arquivo de origem:\n");
   gets(source_file);
 
   source = fopen(source_file, "r");
 
   if (source == NULL)
   {
      printf("erro de abertura do arquivo\n");
      return 1;
   }
 
   printf("Digite o nome do novo arquivo para copia:\n");
   gets(target_file);
 
   target = fopen(target_file, "w");
 
   if (target == NULL)
   {
      fclose(source);
      printf("erro de abertura do novo arquivo\n");
      return 1;
   }
 
   while ((ch = fgetc(source)) != EOF){
      fputc(ch, target);
   }
 
   printf("Arquivo copiado com sucesso.\n");
 
   fclose(source);
   fclose(target);
 
   return 0;
}
//cria um novo arquivo com texto 3
int criarArquivo(char nomeDoArquivo[30], char texto[100]){
	FILE *arquivoNovo;
	arquivoNovo = fopen (nomeDoArquivo, "w");
	fprintf(arquivoNovo, texto);
	fclose(arquivoNovo);
	return 0;
}
//deleta um arquivo 4
int deletarArquivo(char nomeDoArquivo[30]){
	int teste;
	teste = remove(nomeDoArquivo);
	if (teste==0){
		printf("excluido com sucesso.\n");
		return 0;
	}
	else {
		printf("erro na exclusao.\n");
		return 1;
	}
}
