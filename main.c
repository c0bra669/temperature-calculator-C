#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef enum {
    Kelvin='K',Celsius = 'C',Fahrenheit = 'F'
}t_tempunit;
float K_to_C(int K){
    return (K - 273.15);
}
float K_to_F(int K){
    return (K * 1.8 - 459.67);
}
float F_to_K(int F){
    return (((F + 459.67) * 5)/9 );
}
float C_to_K(int C)
{
    return (C + 273.15);
}
bool is_temp_unit(char c){
    switch (c)
    {
    case Kelvin:
    case Celsius:
    case Fahrenheit:
        return true;
        break;
    
    default:
        return false;
        break;
    }

}
bool is_valid(char C){
    if(is_temp_unit(C)){
        return true;
    }
    switch (C) {
        case '-':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
        default:
            return false;
    }

}
int main(int argc,char** argv){
if(argc != 2){
    printf("pas 1 arg");
    return 1;
}
char *temp = malloc((strlen(argv[1]) + 1)*sizeof(char));
temp[0] = '\0';
char unit;
for(int i=1 ; i<argc ; i++){
    for(int j=0; j<=strlen(argv[i]);j++){
        if(!is_valid(argv[i][j])){
            printf("invalid unit %c\n" ,argv[i][j]);
            break;
        }
         if (is_temp_unit(argv[i][j]))
         {
            unit=argv[i][j];
            break;
         }
        char tmp[2] = { argv[i][j], '\0' };
        strncat(temp, tmp,1);
       }
       
}
int deg = atoi(temp);
switch (unit)
{
case Kelvin:
    printf("Celsius: %f\n",K_to_C(deg));
    printf("Farenheit: %f",K_to_F(deg));
    break;

case Celsius:
    printf("Kelvin: %f\n",C_to_K(deg));
    printf("Farenheit %f",K_to_F(C_to_K(deg)));
    break;
case Fahrenheit:
    printf("Kelvin: %f\n",F_to_K(deg));
    printf("Celsius: %f",K_to_C(F_to_K(deg)));
    break;
default:
    break;
}
free(temp);
temp == NULL;
   
return 0;
}