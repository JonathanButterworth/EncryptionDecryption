#include <math.h>
#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] )  {//argc is number of arguments, argv is a pointer to the strings/characters in the arguments

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

    char counter, Hex[3], char1;//character never changed
    int Char, plc = 0;//plc never changed

     while (((counter=fgetc(input))!=EOF))

     {

    if (check == 1){//Encrypting
     
     if (counter == '\t')//check for tabs
     {
     Hex[0]='T';//set hex array values to 'T' (encryption rule)
     Hex[1]='T';
     }
     else if(counter == '\n')//check for an enter (new line)
     {
     Hex[0]='\n';//Set first array value to next line
     }

     else //if not a tab or new line
     {
          Char = counter - 16; //changing ASCII Value

          if (Char<32){     //Alter character further if value is below 32 initially
               Char = (Char-32)+144;
          }
          sprintf(Hex, "%02x", Char);//Pointer to string array, formatting, value inputted
                    //adjust lowercase hexadecimal letters into uppercase.
                    if (Hex[1]>=97 && Hex[1]<=102) {

                        Hex[1]-= 32;//Just changing the cases to uppercase
                    
                    }
          //convert outChar into a hexidecimal and put it in hexa
            fputc(Hex[0], output);
            //in case of '\n', hexa[1] or the second number is not printed.
            if (Hex[0]!='\n') {
                fputc(Hex[1], output);
                    
     }
          printf("%c%c", Hex[0], Hex[1]);

     }
    }


     else if (check ==2){//Decrypting
     
     if (plc==0) {
                char1=Char;
                plc=1;
                if (Char =='\n') {
                    //case for new line: set place back to 0 and rerun for next character
                    fputc('\n', output);
                    plc=0;
                    printf("\n");
                }
            }
else {
                if (char1=='T' && Char =='T') {
                    //case for tab
                    Char='\t';
                }
                else {
                    //hexadecimal conversions for A-F
                    if (char1>='A' && char1<='F') {
                        char1=char1-'A'+10;
                    }
                    else {
                        char1=char1-'0';
                    }
                    if (Char>='A' && Char<='F') {
                        Char=Char-'A'+10;
                    }
                    else {
                        Char=Char-'0';
                    }
                    //hexadecimal to character conversion
                    Char=char1*16+Char;
                    Char+=16;
                    if (Char>127) {
                        Char=(Char - 144) + 32;
                    }      
                }

    }

    }
}

    printf ("\nOutput file %s updated.", outfile);
    //print into file
    printf ("%c", Char);
    fputc(Char, output);
    plc = 0;
}



else {
        printf ("\nInvalid Terminal Input.");
        
return 0;
}


    printf ("\n\nOutput file %s updated.", outfile);
    return 0;

}
