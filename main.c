//testing stuff out
#include <stdio.h>
#include <math.h>

enum measurement_type_options {QUIT, LENGTH, WEIGHT};
typedef enum measurement_type_options Measurement_type_options;

enum conversion_menu{BACK_TO_MAIN_MENU, US_TO_METRIC, METRIC_TO_US};
typedef enum conversion_menu Conversion_menu;

void conversion_type(Measurement_type_options* choice);
void select_conversion_type(Conversion_menu* choice, Measurement_type_options type);

void convert_lengths(void);
void length_to_metric(void);
void input_length_to_metric(int* pFeet, double* pInches);
void calculate_length_to_metric(int feet, double inches, int* pMeters, double* pCentimeters);
void output_length_to_metric(int feet, double inches, int meters, double centimeters);
void length_to_us(void);
void input_length_to_us(int* pMeters, double* pCentimeters);
void calculate_length_to_us(int meters, double centimeters, int* pFeet, double* pInches);
void output_length_to_us(int meters, double centimeters, int feet, double inches);

void convert_weights(void);
void weight_to_metric(void);
void input_weight_to_metric(int* pPounds, double* pOunces);
void calculate_weight_to_metric(int pounds, double ounces, int* pKilograms, double* pGrams);
void output_weight_to_metric(int pounds, double ounces, int kilograms, double grams);
void weight_to_us(void);
void input_weight_to_us(int* kilograms, double* grams);
void calculate_weight_to_us(int kilograms, double grams, int* pounds, double* ounces);
void output_weight_to_us(int kilograms, double grams, int pounds, double ounces);

void clear_keyboard_buffer(void);

//conversion factors for weight
const int INCHES_TO_FEET = 12;
const double FEET_TO_METERS = 0.3048;
const int METERS_TO_CENTIMETERS = 100;

//conversion factors for weight
const int OUNCES_TO_POUNDS = 16;
const double POUNDS_TO_KILOGRAMS = 2.2046;
const int KILOGRAM_TO_GRAMS = 1000;

int main(int argc, char* argv[]) {
	Measurement_type_options user_input;
	conversion_type(&user_input);
	while (user_input != QUIT) {
		switch (user_input) {
		case LENGTH:
			convert_lengths();
			break;
		case WEIGHT:
			convert_weights();
			break;
		}
		printf("\n");
		conversion_type(&user_input);
	}
	printf("QUITING...");
	return 0;
}

void conversion_type(Measurement_type_options* choice) {
	do {
		printf("PLEASE SELECT WHAT YOU WOULD LIKE TO CONVERT.\n");
		printf("0.) QUIT\n");         
		printf("1.) CONVERT LENGTH\n");
		printf("2.) CONVERT WEIGHT\n");
		scanf("%d", choice);
		clear_keyboard_buffer();
		if (*choice != QUIT && *choice != LENGTH && *choice != WEIGHT) {
			printf("SORRY, I DON'T UNDERSTAND\n");
		}
	} while (*choice != QUIT && *choice != LENGTH && *choice != WEIGHT);
}

void select_conversion_type(Conversion_menu* choice, Measurement_type_options type) {
	switch (type) {
	case LENGTH:
		printf("\n");
		printf("YOU'RE CONVERTING LENGTH\n");
		break;
	case WEIGHT:
		printf("\n");
		printf("YOU'RE CONVERTING WEIGHT\n");
		break;
	}
	do {
		printf("0.) RETURN TO MAIN MENU\n");
		printf("1.) CONVERT US TO METRIC\n");
		printf("2.) CONVERT METRIC TO US\n");
		scanf("%d", choice);
		clear_keyboard_buffer();
		if (*choice != BACK_TO_MAIN_MENU && *choice != US_TO_METRIC && *choice != METRIC_TO_US) {
			printf("SORRY, I DON'T UNDERSTAND\n");
		}
	} while (*choice != BACK_TO_MAIN_MENU && *choice != US_TO_METRIC && *choice != METRIC_TO_US);
}

void convert_lengths(void) {
	Conversion_menu length_conversion;
	select_conversion_type(&length_conversion, LENGTH);
	while (length_conversion != BACK_TO_MAIN_MENU) {
		switch (length_conversion) {
		case US_TO_METRIC:
			length_to_metric();
			break;
		case METRIC_TO_US:
			length_to_us();
			break;
		}
		select_conversion_type(&length_conversion, LENGTH);
	}
}

void length_to_metric(void) {
	int feet;
	double inches;
	int meters;
	double centimeters;

	input_length_to_metric(&feet, &inches);
	calculate_length_to_metric(feet, inches, &meters, &centimeters);
	output_length_to_metric(feet, inches, meters, centimeters);
}

void input_length_to_metric(int* pFeet, double* pInches) {
	do {
		printf("PLEASE ENTER FEET THAT YOU WOULID LIKE TO CONVERT: ");
		scanf("%d", pFeet);
		clear_keyboard_buffer();
		if (*pFeet < 0) {
			printf("that response is invalid.\n");
		}
	} while (*pFeet < 0);
	do {
		printf("PLEASE ENTER THE INCHES YOU WOULD LIKE TO CONVERT: ");
		scanf("%lf", pInches);
		clear_keyboard_buffer();
		if (*pInches < 0) {
			printf("that response is invalid.\n");
		}
	} while (*pInches < 0);
}

void calculate_length_to_metric(int feet, double inches, int* pMeters, double* pCentimeters) {
	double total_feet;
	double total_meters;

	total_feet = feet + (inches / INCHES_TO_FEET);
	total_meters = total_feet * FEET_TO_METERS;

	*pMeters = floor(total_meters);
	*pCentimeters = (total_meters - *pMeters) * METERS_TO_CENTIMETERS;
}

void output_length_to_metric(int feet, double inches, int meters, double centimeters) {
	printf("%d feet and %.2f inches converts to\n", feet, inches);
	printf("%d meters and %.2f centimeters\n", meters, centimeters);
}

void length_to_us(void) {
	int feet;
	double inches;
	int meters;
	double centimeters;

	input_length_to_us(&meters, &centimeters);
	calculate_length_to_us(meters, centimeters, &feet, &inches);
	output_length_to_us(meters, centimeters, feet, inches);
}

void input_length_to_us(int* pMeters, double* pCentimeters) {
	do {
		printf("PLEASE ENTER METERS THAT YOU WOULID LIKE TO CONVERT: ");
		scanf("%d", pMeters);
		clear_keyboard_buffer();
		if (*pMeters < 0) {
			printf("that response is invalid.\n");
		}
	} while (*pMeters < 0);
	do {
		printf("PLEASE ENTER THE INCHES YOU WOULD LIKE TO CONVERT: ");
		scanf("%lf", pCentimeters);
		clear_keyboard_buffer();
		if (*pCentimeters < 0) {
			printf("that response is invalid.\n");
		}
	} while (*pCentimeters < 0);
}

void calculate_length_to_us(int meters, double centimeters, int* pFeet, double* pInches) {
	double total_meters;
	double total_feet;

	total_meters = meters + (centimeters / METERS_TO_CENTIMETERS);
	total_feet = total_meters / FEET_TO_METERS;

	*pFeet = floor(total_feet);
	*pInches = (total_feet - *pFeet) * INCHES_TO_FEET;
}

void output_length_to_us(int meters, double centimeters, int feet, double inches) {
	printf("%d meters and %.2f centimeters converts to\n", meters, centimeters);
	printf("%d feet and %.2f inches\n", feet, inches);
}

void convert_weights(void) {
	Conversion_menu weight_conversion;
	printf("you're converting weights\n");
	select_conversion_type(&weight_conversion, WEIGHT);
	while (weight_conversion != BACK_TO_MAIN_MENU) {
		switch (weight_conversion) {
		case US_TO_METRIC:
			weight_to_metric();
			break;
		case METRIC_TO_US:
			weight_to_us();
			break;
		}
		select_conversion_type(&weight_conversion, WEIGHT);
		printf("you're converting weights\n");

	}
}

void weight_to_metric(void) {
	int pounds;
	double ounces;
	int kilograms;
	double grams;

	input_weight_to_metric(&pounds, &ounces);
	calculate_weight_to_metric(pounds, ounces, &kilograms, &grams);
	output_weight_to_metric(pounds, ounces, kilograms, grams);
}

void input_weight_to_metric(int* pPounds, double* pOunces) {
	do {
		printf("PLEASE ENTER POUNDS THAT YOU WOULID LIKE TO CONVERT: ");
		scanf("%d", pPounds);
		clear_keyboard_buffer();
		if (*pPounds < 0) {
			printf("that response is invalid.\n");
		}
	} while (*pPounds < 0);
	do {
		printf("PLEASE ENTER THE OUNCES YOU WOULD LIKE TO CONVERT: ");
		scanf("%lf", pOunces);
		clear_keyboard_buffer();
		if (*pOunces < 0) {
			printf("that response is invalid.\n");
		}
	} while (*pOunces < 0);
}

void calculate_weight_to_metric(int pounds, double ounces, int* pKilograms, double* pGrams) {
	double total_pounds;
	double total_kilograms;

	total_pounds = pounds + (ounces / OUNCES_TO_POUNDS);
	total_kilograms = total_pounds / POUNDS_TO_KILOGRAMS;

	*pKilograms = floor(total_kilograms);
	*pGrams = (total_kilograms - *pKilograms) * KILOGRAM_TO_GRAMS;
}

void output_weight_to_metric(int pounds, double ounces, int kilograms, double grams) {
	printf("%d pounds and %.2f ounces converts to\n", pounds, ounces);
	printf("%d kilograms and %.2f grams\n", kilograms, grams);
}

void weight_to_us(void) {
	int pounds;
	double ounces;
	int kilograms;
	double grams;

	input_weight_to_us(&kilograms, &grams);
	calculate_weight_to_us(kilograms, grams, &pounds, &ounces);
	output_weight_to_us(kilograms, grams, pounds, ounces);
}

void input_weight_to_us(int* pKilograms, double* pGrams) {
	do {
		printf("PLEASE ENTER KILOGRAMS THAT YOU WOULID LIKE TO CONVERT: ");
		scanf("%d", pKilograms);
		clear_keyboard_buffer();
		if (*pKilograms < 0) {
			printf("that response is invalid.\n");
		}
	} while (*pKilograms < 0);
	do {
		printf("PLEASE ENTER THE GRAMS YOU WOULD LIKE TO CONVERT: ");
		scanf("%lf", pGrams);
		clear_keyboard_buffer();
		if (*pGrams < 0) {
			printf("that response is invalid.\n");
		}
	} while (*pGrams < 0);
}

void calculate_weight_to_us(int kilograms, double grams, int* pPounds, double* pOunces) {
	double total_pounds;
	double total_kilograms;

	total_kilograms = kilograms + (grams / KILOGRAM_TO_GRAMS);
	total_pounds = total_kilograms * POUNDS_TO_KILOGRAMS;

	*pPounds = floor(total_pounds);
	*pOunces = (total_pounds - *pPounds) * OUNCES_TO_POUNDS;
}

void output_weight_to_us(int kilograms, double grams, int pounds, double ounces) {
	printf("%d kilograms and %.2f grams converts to\n", kilograms, grams);
	printf("%d pounds and %.2f ounces\n", pounds, ounces);
}

void clear_keyboard_buffer(void) {
	char c;
	scanf("%c", &c);
	while (c != '\n') {
		scanf("%c", &c);
	}
	return;
}