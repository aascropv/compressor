#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <stdarg.h>
#include <ctype.h>

void Bin_to_Base64(char *ln_bin, char *b64) {
	int j = 0;
	int num = 0;
	char six_bin[7];
	strcpy(six_bin, "222222");      //因為有padding要判斷，先把6 bits的字串長度設為"222222"
	for (int i = 0; ln_bin[i] != '\0'; i++)
	{
		if(j < 6) {                      //每六個字串接在一起放到six_bin，直到遇到空字元
			six_bin[j] = ln_bin[i];
			/*printf("ln_bin[i]: %c\n", ln_bin[i]);
			printf("%d\n", j);
			printf("six: %s\n", six_bin);*/
			j++;
			num++;
		}
		if(j == 6) {                    //當六個字元都擺好，判斷它是Base64的多少
			if(strcmp(six_bin, "000000") == 0 && num == 0)
				strcpy(b64, "A");
			else if(strcmp(six_bin, "000000") == 0 && num != 0)
				strcat(b64, "A");
			else if(strcmp(six_bin, "000001") == 0 && num == 0)
				strcpy(b64, "B");
			else if(strcmp(six_bin, "000001") == 0 && num != 0)
				strcat(b64, "B");
			else if(strcmp(six_bin, "000010") == 0 && num == 0)
				strcpy(b64, "C");
			else if(strcmp(six_bin, "000010") == 0 && num != 0)
				strcat(b64, "C");
			else if(strcmp(six_bin, "000011") == 0 && num == 0)
				strcpy(b64, "D");
			else if(strcmp(six_bin, "000011") == 0 && num != 0)
				strcat(b64, "D");
			else if(strcmp(six_bin, "000100") == 0 && num == 0)
				strcpy(b64, "E");
			else if(strcmp(six_bin, "000100") == 0 && num != 0)
				strcat(b64, "E");
			else if(strcmp(six_bin, "000101") == 0 && num == 0)
				strcpy(b64, "F");
			else if(strcmp(six_bin, "000101") == 0 && num != 0)
				strcat(b64, "F");
			else if(strcmp(six_bin, "000110") == 0 && num == 0)
				strcpy(b64, "G");
			else if(strcmp(six_bin, "000110") == 0 && num != 0)
				strcat(b64, "G");
			else if(strcmp(six_bin, "000111") == 0 && num == 0)
				strcpy(b64, "H");
			else if(strcmp(six_bin, "000111") == 0 && num != 0)
				strcat(b64, "H");
			else if(strcmp(six_bin, "001000") == 0 && num == 0)
				strcpy(b64, "I");
			else if(strcmp(six_bin, "001000") == 0 && num != 0)
				strcat(b64, "I");
			else if(strcmp(six_bin, "001001") == 0 && num == 0)
				strcpy(b64, "J");
			else if(strcmp(six_bin, "001001") == 0 && num != 0)
				strcat(b64, "J");
			else if(strcmp(six_bin, "001010") == 0 && num == 0)
				strcpy(b64, "K");
			else if(strcmp(six_bin, "001010") == 0 && num != 0)
				strcat(b64, "K");
			else if(strcmp(six_bin, "001011") == 0 && num == 0)
				strcpy(b64, "L");
			else if(strcmp(six_bin, "001011") == 0 && num != 0)
				strcat(b64, "L");
			else if(strcmp(six_bin, "001100") == 0 && num == 0)
				strcpy(b64, "M");
			else if(strcmp(six_bin, "001100") == 0 && num != 0)
				strcat(b64, "M");
			else if(strcmp(six_bin, "001101") == 0 && num == 0)
				strcpy(b64, "N");
			else if(strcmp(six_bin, "001101") == 0 && num != 0)
				strcat(b64, "N");
			else if(strcmp(six_bin, "001110") == 0 && num == 0)
				strcpy(b64, "O");
			else if(strcmp(six_bin, "001110") == 0 && num != 0)
				strcat(b64, "O");
			else if(strcmp(six_bin, "001111") == 0 && num == 0)
				strcpy(b64, "P");
			else if(strcmp(six_bin, "001111") == 0 && num != 0)
				strcat(b64, "P");
			else if(strcmp(six_bin, "010000") == 0 && num == 0)
				strcpy(b64, "Q");
			else if(strcmp(six_bin, "010000") == 0 && num != 0)
				strcat(b64, "Q");
			else if(strcmp(six_bin, "010001") == 0 && num == 0)
				strcpy(b64, "R");
			else if(strcmp(six_bin, "010001") == 0 && num != 0)
				strcat(b64, "R");
			else if(strcmp(six_bin, "010010") == 0 && num == 0)
				strcpy(b64, "S");
			else if(strcmp(six_bin, "010010") == 0 && num != 0)
				strcat(b64, "S");
			else if(strcmp(six_bin, "010011") == 0 && num == 0)
				strcpy(b64, "T");
			else if(strcmp(six_bin, "010011") == 0 && num != 0)
				strcat(b64, "T");
			else if(strcmp(six_bin, "010100") == 0 && num == 0)
				strcpy(b64, "U");
			else if(strcmp(six_bin, "010100") == 0 && num != 0)
				strcat(b64, "U");
			else if(strcmp(six_bin, "010101") == 0 && num == 0)
				strcpy(b64, "V");
			else if(strcmp(six_bin, "010101") == 0 && num != 0)
				strcat(b64, "V");
			else if(strcmp(six_bin, "010110") == 0 && num == 0)
				strcpy(b64, "W");
			else if(strcmp(six_bin, "010110") == 0 && num != 0)
				strcat(b64, "W");
			else if(strcmp(six_bin, "010111") == 0 && num == 0)
				strcpy(b64, "X");
			else if(strcmp(six_bin, "010111") == 0 && num != 0)
				strcat(b64, "X");
			else if(strcmp(six_bin, "011000") == 0 && num == 0)
				strcpy(b64, "Y");
			else if(strcmp(six_bin, "011000") == 0 && num != 0)
				strcat(b64, "Y");
			else if(strcmp(six_bin, "011001") == 0 && num == 0)
				strcpy(b64, "Z");
			else if(strcmp(six_bin, "011001") == 0 && num != 0)
				strcat(b64, "Z");
			else if(strcmp(six_bin, "011010") == 0 && num == 0)
				strcpy(b64, "a");
			else if(strcmp(six_bin, "011010") == 0 && num != 0)
				strcat(b64, "a");
			else if(strcmp(six_bin, "011011") == 0 && num == 0)
				strcpy(b64, "b");
			else if(strcmp(six_bin, "011011") == 0 && num != 0)
				strcat(b64, "b");
			else if(strcmp(six_bin, "011100") == 0 && num == 0)
				strcpy(b64, "c");
			else if(strcmp(six_bin, "011100") == 0 && num != 0)
				strcat(b64, "c");
			else if(strcmp(six_bin, "011101") == 0 && num == 0)
				strcpy(b64, "d");
			else if(strcmp(six_bin, "011101") == 0 && num != 0)
				strcat(b64, "d");
			else if(strcmp(six_bin, "011110") == 0 && num == 0)
				strcpy(b64, "e");
			else if(strcmp(six_bin, "011110") == 0 && num != 0)
				strcat(b64, "e");
			else if(strcmp(six_bin, "011111") == 0 && num == 0)
				strcpy(b64, "f");
			else if(strcmp(six_bin, "011111") == 0 && num != 0)
				strcat(b64, "f");
			else if(strcmp(six_bin, "100000") == 0 && num == 0)
				strcpy(b64, "g");
			else if(strcmp(six_bin, "100000") == 0 && num != 0)
				strcat(b64, "g");
			else if(strcmp(six_bin, "100001") == 0 && num == 0)
				strcpy(b64, "h");
			else if(strcmp(six_bin, "100001") == 0 && num != 0)
				strcat(b64, "h");
			else if(strcmp(six_bin, "100010") == 0 && num == 0)
				strcpy(b64, "i");
			else if(strcmp(six_bin, "100010") == 0 && num != 0)
				strcat(b64, "i");
			else if(strcmp(six_bin, "100011") == 0 && num == 0)
				strcpy(b64, "j");
			else if(strcmp(six_bin, "100011") == 0 && num != 0)
				strcat(b64, "j");
			else if(strcmp(six_bin, "100100") == 0 && num == 0)
				strcpy(b64, "k");
			else if(strcmp(six_bin, "100100") == 0 && num != 0)
				strcat(b64, "k");
			else if(strcmp(six_bin, "100101") == 0 && num == 0)
				strcpy(b64, "l");
			else if(strcmp(six_bin, "100101") == 0 && num != 0)
				strcat(b64, "l");
			else if(strcmp(six_bin, "100110") == 0 && num == 0)
				strcpy(b64, "m");
			else if(strcmp(six_bin, "100110") == 0 && num != 0)
				strcat(b64, "m");
			else if(strcmp(six_bin, "100111") == 0 && num == 0)
				strcpy(b64, "n");
			else if(strcmp(six_bin, "100111") == 0 && num != 0)
				strcat(b64, "n");
			else if(strcmp(six_bin, "101000") == 0 && num == 0)
				strcpy(b64, "o");
			else if(strcmp(six_bin, "101000") == 0 && num != 0)
				strcat(b64, "o");
			else if(strcmp(six_bin, "101001") == 0 && num == 0)
				strcpy(b64, "p");
			else if(strcmp(six_bin, "101001") == 0 && num != 0)
				strcat(b64, "p");
			else if(strcmp(six_bin, "101010") == 0 && num == 0)
				strcpy(b64, "q");
			else if(strcmp(six_bin, "101010") == 0 && num != 0)
				strcat(b64, "q");
			else if(strcmp(six_bin, "101011") == 0 && num == 0)
				strcpy(b64, "r");
			else if(strcmp(six_bin, "101011") == 0 && num != 0)
				strcat(b64, "r");
			else if(strcmp(six_bin, "101100") == 0 && num == 0)
				strcpy(b64, "s");
			else if(strcmp(six_bin, "101100") == 0 && num != 0)
				strcat(b64, "s");
			else if(strcmp(six_bin, "101101") == 0 && num == 0)
				strcpy(b64, "t");
			else if(strcmp(six_bin, "101101") == 0 && num != 0)
				strcat(b64, "t");
			else if(strcmp(six_bin, "101110") == 0 && num == 0)
				strcpy(b64, "u");
			else if(strcmp(six_bin, "101110") == 0 && num != 0)
				strcat(b64, "u");
			else if(strcmp(six_bin, "101111") == 0 && num == 0)
				strcpy(b64, "v");
			else if(strcmp(six_bin, "101111") == 0 && num != 0)
				strcat(b64, "v");
			else if(strcmp(six_bin, "110000") == 0 && num == 0)
				strcpy(b64, "w");
			else if(strcmp(six_bin, "110000") == 0 && num != 0)
				strcat(b64, "w");
			else if(strcmp(six_bin, "110001") == 0 && num == 0)
				strcpy(b64, "x");
			else if(strcmp(six_bin, "110001") == 0 && num != 0)
				strcat(b64, "x");
			else if(strcmp(six_bin, "110010") == 0 && num == 0)
				strcpy(b64, "y");
			else if(strcmp(six_bin, "110010") == 0 && num != 0)
				strcat(b64, "y");
			else if(strcmp(six_bin, "110011") == 0 && num == 0)
				strcpy(b64, "z");
			else if(strcmp(six_bin, "110011") == 0 && num != 0)
				strcat(b64, "z");
			else if(strcmp(six_bin, "110100") == 0 && num == 0)
				strcpy(b64, "0");
			else if(strcmp(six_bin, "110100") == 0 && num != 0)
				strcat(b64, "0");
			else if(strcmp(six_bin, "110101") == 0 && num == 0)
				strcpy(b64, "1");
			else if(strcmp(six_bin, "110101") == 0 && num != 0)
				strcat(b64, "1");
			else if(strcmp(six_bin, "110110") == 0 && num == 0)
				strcpy(b64, "2");
			else if(strcmp(six_bin, "110110") == 0 && num != 0)
				strcat(b64, "2");
			else if(strcmp(six_bin, "110111") == 0 && num == 0)
				strcpy(b64, "3");
			else if(strcmp(six_bin, "110111") == 0 && num != 0)
				strcat(b64, "3");
			else if(strcmp(six_bin, "111000") == 0 && num == 0)
				strcpy(b64, "4");
			else if(strcmp(six_bin, "111000") == 0 && num != 0)
				strcat(b64, "4");
			else if(strcmp(six_bin, "111001") == 0 && num == 0)
				strcpy(b64, "5");
			else if(strcmp(six_bin, "111001") == 0 && num != 0)
				strcat(b64, "5");
			else if(strcmp(six_bin, "111010") == 0 && num == 0)
				strcpy(b64, "6");
			else if(strcmp(six_bin, "111010") == 0 && num != 0)
				strcat(b64, "6");
			else if(strcmp(six_bin, "111011") == 0 && num == 0)
				strcpy(b64, "7");
			else if(strcmp(six_bin, "111011") == 0 && num != 0)
				strcat(b64, "7");
			else if(strcmp(six_bin, "111100") == 0 && num == 0)
				strcpy(b64, "8");
			else if(strcmp(six_bin, "111100") == 0 && num != 0)
				strcat(b64, "8");
			else if(strcmp(six_bin, "111101") == 0 && num == 0)
				strcpy(b64, "9");
			else if(strcmp(six_bin, "111101") == 0 && num != 0)
				strcat(b64, "9");
			else if(strcmp(six_bin, "111110") == 0 && num == 0)
				strcpy(b64, "+");
			else if(strcmp(six_bin, "111110") == 0 && num != 0)
				strcat(b64, "+");
			else if(strcmp(six_bin, "111111") == 0 && num == 0)
				strcpy(b64, "/");
			else if(strcmp(six_bin, "111111") == 0 && num != 0)
				strcat(b64, "/");
			
			strcpy(six_bin, "222222");
			//printf("tmp_result: %s\n", b64);
			j = 0;
		}
	}
	if(strcmp(six_bin, "000022") == 0)             //例外情況，需要補"="
			strcat(b64, "A=");
		else if(strcmp(six_bin, "000122") == 0)
			strcat(b64, "E=");
		else if(strcmp(six_bin, "001022") == 0)
			strcat(b64, "I=");
		else if(strcmp(six_bin, "001122") == 0)
			strcat(b64, "M=");
		else if(strcmp(six_bin, "010022") == 0)
			strcat(b64, "Q=");
		else if(strcmp(six_bin, "010122") == 0)
			strcat(b64, "U=");
		else if(strcmp(six_bin, "011022") == 0)
			strcat(b64, "Y=");
		else if(strcmp(six_bin, "011122") == 0)
			strcat(b64, "c=");
		else if(strcmp(six_bin, "100022") == 0)
			strcat(b64, "g=");
		else if(strcmp(six_bin, "100122") == 0)
			strcat(b64, "k=");
		else if(strcmp(six_bin, "101022") == 0)
			strcat(b64, "o=");
		else if(strcmp(six_bin, "101122") == 0)
			strcat(b64, "s=");
		else if(strcmp(six_bin, "110022") == 0)
			strcat(b64, "w=");
		else if(strcmp(six_bin, "110122") == 0)
			strcat(b64, "0=");
		else if(strcmp(six_bin, "111022") == 0)
			strcat(b64, "4=");
		else if(strcmp(six_bin, "111122") == 0)
			strcat(b64, "8=");
		else if(strcmp(six_bin, "002222") == 0)
			strcat(b64, "A==");
		else if(strcmp(six_bin, "012222") == 0)
			strcat(b64, "Q==");
		else if(strcmp(six_bin, "102222") == 0)
			strcat(b64, "g==");
		else if(strcmp(six_bin, "112222") == 0)
			strcat(b64, "w==");
}

int main(int argc, char *argv[])
{
	extern char *optarg;
	FILE *input_file, *output_file;
	int num = 0;
	int line = 0;
	int c = 0, err = 0;
	char ch, ln_bin[10000], sh_bin[5], b64[10000], recover_bin[10000], *inFile, *outFile;
	bool nextLine = false;
	
	while((c = getopt(argc, argv, "i:o:")) != -1) {   //利用getopt寫入參數
		switch (c) {
			case 'i':
				inFile = optarg;
				break;
			case 'o':
				outFile = optarg;
				break;
			case '?':
				err = 1;
				break;
		}
	}
	//printf("%s\n", inFile);
	//printf("%s\n", outFile);
	input_file = fopen(inFile, "r");  //讀入input 和output file
	output_file = fopen(outFile, "w");

	//int len = 0;
	//char tmp = 0;
	
	while((ch = getc(input_file)) != EOF) {  //把Input File每個字讀進來
		if (!isprint(ch) && ch != '\n')   //因為有其他控制字元的問題，所以用這行條件來判斷
			continue;
		
		num++;
		nextLine = false;
		//printf("test\n");

		switch(ch) {         //判斷讀進來的字是甚麼，把它轉成二進位
			case '0':
				strcpy(sh_bin, "0000");
				break;
			case '1':
				strcpy(sh_bin, "0001");
				break;
			case '2':
				strcpy(sh_bin, "0010");
				break;
			case '3':
				strcpy(sh_bin, "0011");
				break;
			case '4':
				strcpy(sh_bin, "0100");
				break;
			case '5':
				strcpy(sh_bin, "0101");
				break;
			case '6':
				strcpy(sh_bin, "0110");
				break;
			case '7':
				strcpy(sh_bin, "0111");
				break;
			case '8':
				strcpy(sh_bin, "1000");
				break;
			case '9':
				strcpy(sh_bin, "1001");
				break;
			case 'A':
			case 'a':
				strcpy(sh_bin, "1010");
				break;
			case 'B':
			case 'b':
				strcpy(sh_bin, "1011");
				break;
			case 'C':
			case 'c':
				strcpy(sh_bin, "1100");
				break;
			case 'D':
			case 'd':
				strcpy(sh_bin, "1101");
				break;
			case 'E':
			case 'e':
				strcpy(sh_bin, "1110");
				break;
			case 'F':
			case 'f':
				strcpy(sh_bin, "1111");
				break;
			case '\n':                            //如果遇到換行，則先把這一行的字串印出來
				//printf("%s\n", ln_bin);
				Bin_to_Base64(ln_bin, b64);      //呼叫function把一行二進位字串轉換成Base64的字串
#if 0
				if(line != 0)
					fprintf(output_file, "\n");
#endif
				fprintf(output_file, "%s\n", b64);    //把Base64字串印到output file
				//printf("translate: %s\n", b64);
				line++;
				memset(b64, 0, 10000);           
				memset(ln_bin, 0, 10000);
				nextLine = true;
				num = 0;
				break;
		}
		//printf("test2\n");
		
		if(num == 1 && nextLine == false) {         //判斷是否為每行第一個字元，並用strcpy和strcat把short_binary貼(接)到long_binary
			strcpy(ln_bin, recover_bin);
			strcpy(ln_bin, sh_bin);
		}
		else if(num != 1 && nextLine == false)
			strcat(ln_bin, sh_bin);
/*		tmp |= (ch & 15);
		len += 4;
		tmp <<= len;*/
	}
	
	fclose(output_file);
	fclose(input_file);
	return 0;
}
