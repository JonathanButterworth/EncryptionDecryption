#include <math.h>
#include <stdio.h>
#include <string.h>
#define MAX 120

int main( int argc, char *argv[] )  {

char *infile;
char *outfile;

if (argc >=2 && argc <= 4){//checks number of arguments in manual compile

    if ((strcmp(argv[1],"-D")) || (strcmp(argv[1],"-E"))==0){
    char *infile=argv[2];//recognizes that the input file is the 3rd argument (see proper structure at end of code)
    char *outfile=argv[3];//recognizes that the output file is the 4th argument (see proper structure at end of code)
    }

    else {
    char *infile=argv[1];//recognizes that the input file is the 2nd argument (see proper structure at end of code)
    char *outfile=argv[2];//recognizes that the output file is the 3rd argument (see proper structure at end of code)
    }


   //Check for decryption, otherwise default to Encryption.
   int check=0;
   if (strcmp(argv[1],"-D")==0) 
   {
        check=2;//Decrypting
        printf("Decrypting:");
   }
   else//Encrypting
   {
        check=1;
        printf("Encrypting:");
   }

    FILE *input;
    FILE *output;
    //open files for read and write
    input=fopen(infile, "r");
    output=fopen(outfile, "w");

    switch(check){
    case 1://Encrypting
    

    case 2://Decrypting

    }

    printf ("\nOutput file %s updated.", outfile);
    return 0;
}
else{
        printf ("\nInvalid Terminal Arguments.\n\nTo Encrypt: ./cryptoMagic -E [inputfile].txt [outputfile].txt\nTo Decrypt: ./cryptoMagic -D [inputfile].txt [outputfile].txt\n");
        printf ("\nexample encryption: ./cryptoMagic -E d.txt e.txt\nexample decryption: ./cryptoMagic -D e.txt d.txt\n");
        printf ("\nif no output file is given, program will default to defaultoutputfile.txt\n");
        printf ("if file cannot be found, first make the terminal open the folder the file is in by typing: cd [foldername]\n\n");
        
return 0;
}
}