#include <stdio.h>
#include <ctype.h>

float celsius_to_fahrenheit(float celsius) {
    float final = (celsius * (9.0 / 5.0)) + 32;
    return final;
}

float farenheit_to_celsius(float fahrenheit) {
    float final = ((fahrenheit - 32) * (5.0 / 9.0));
    return final;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float farenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(farenheit_to_celsius(fahrenheit));
}

float kelvin_to_farenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void catagorize_value(float celsius) {
    if(celsius < 0) {
        printf("Freezing, wear a coat\n");
    }
    else if(celsius < 10) {
        printf("Cold, wear a sweater\n");
    }
    else if (celsius < 25) {
        printf("Comfortable, sit in the sun\n");
    }
    else if (celsius < 35) {
        printf("Hot, remember sunscreen\n");
    }
    else {
        printf("Extreme Heat, stay indoors\n");
    }
}

float convert_temperature(float temp, char inputScale, char outputScale) {
    const char input = toupper(inputScale);
    const char output = toupper(outputScale);

    if (input == 'C') {
        if (output == 'C') {
            return temp;
        }
        if (output == 'F') {
            return celsius_to_fahrenheit(temp);
        }
        if (output == 'K') {
            return celsius_to_kelvin(temp);
        }
    }
    if (input == 'F') {
        if (output == 'F') {
            return temp;
        }
        if (output == 'C') {
            return farenheit_to_celsius(temp);
        }
        if (output == 'K') {
            return farenheit_to_kelvin(temp);
        }
    }
    if (output == 'K') {
        return temp;
    }
    if (output == 'C') {
        return kelvin_to_celsius(temp);
    }
    if (output == 'F') {
        return kelvin_to_farenheit(temp);
    }

    return 0;
}

int main() {

    float temperature;
    char inputScale;
    char outputScale;
    char trash;
    printf("Enter a temperature: \n");
    scanf("%f", &temperature);
    scanf("%c", &trash);
    printf("Entered temperature scale (K, C, F): ");
    scanf("%c", &inputScale);
    scanf("%c", &trash);
    printf("\nDesired temperature scale (K, C, F): ");
    scanf("%c", &outputScale);
    printf("%f",temperature);
    printf("\nIt is %f", convert_temperature(temperature, inputScale, outputScale));
    printf(" degrees %c\n", outputScale);
    catagorize_value(convert_temperature(temperature, inputScale, 'C'));



    return 0;
}