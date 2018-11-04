// DEVELOPED by wilt00x

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 150


void decrypt_cesar_algorithm()
{
	char decryptFunctionBuffer[BUFF_SIZE+1];
	char decryptFunctionRes;
    	int k, decryptFunctionKey;

	puts("\n-Texte à déchiffrer : ");
        fgets(decryptFunctionBuffer,100,stdin);
        puts("-Décalage (en chiffre) : ");
        scanf("%d", &decryptFunctionKey);

	   for(k = 0; decryptFunctionBuffer[k] != '\0'; ++k){
        decryptFunctionRes = decryptFunctionBuffer[k];

        if(decryptFunctionRes >= 'a' && decryptFunctionRes <= 'z'){
            decryptFunctionRes = decryptFunctionRes - decryptFunctionKey;

            if(decryptFunctionRes < 'a'){
                decryptFunctionRes = decryptFunctionRes + 'z' - 'a' + 1;
            }

            decryptFunctionBuffer[k] = decryptFunctionRes;
        }
        else if(decryptFunctionRes >= 'A' && decryptFunctionRes <= 'Z'){
            decryptFunctionRes = decryptFunctionRes - decryptFunctionKey;

            if(decryptFunctionRes < 'A'){
                decryptFunctionRes = decryptFunctionRes + 'Z' - 'A' + 1;
            }

            decryptFunctionBuffer[k] = decryptFunctionRes;
        }
    }

    printf("-Message déchiffrer : %s", decryptFunctionBuffer);
}

void encrypt_cesar_algorithm()
{
    char encryptFunctionBuffer[BUFF_SIZE+1];
    char encryptFunctionRes;
    int i, encryptFunctionKey;

    puts("-Texte à chiffrer : ");
    fgets(encryptFunctionBuffer,100,stdin);
    puts("-Décalage (en chiffre) : ");
    scanf("%d", &encryptFunctionKey);

    for(i = 0; encryptFunctionBuffer[i] != '\0'; ++i){
        encryptFunctionRes = encryptFunctionBuffer[i];

        if(encryptFunctionRes >= 'a' && encryptFunctionRes <= 'z'){
            encryptFunctionRes = encryptFunctionRes + encryptFunctionKey;

            if(encryptFunctionRes > 'z'){
                encryptFunctionRes = encryptFunctionRes - 'z' + 'a' - 1;
            }

            encryptFunctionBuffer[i] = encryptFunctionRes;
        }
        else if(encryptFunctionRes >= 'A' && encryptFunctionRes <= 'Z'){
            encryptFunctionRes = encryptFunctionRes + encryptFunctionKey;

            if(encryptFunctionRes > 'Z'){
                encryptFunctionRes = encryptFunctionRes - 'Z' + 'A' - 1;
            }

            encryptFunctionBuffer[i] = encryptFunctionRes;
        }
    }

    		printf("-Texte déchiffrer : %s", encryptFunctionBuffer);
}

int main()
{
	char *buf = (char*)malloc(sizeof(char)*1);

	puts("\n -[1] Chiffrer \n\n -[2] Dechiffrer \n");
	fgets(buf, sizeof(buf), stdin);

	switch(*buf)
	{
		case'1':
		encrypt_cesar_algorithm();
		break;
		case'2':
		decrypt_cesar_algorithm();
		break;
               default:
               puts("1 ou 2\n");
               exit(1);
	}

	return 0;
}
