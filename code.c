#include <stdio.h>
float calculate_bmi(float weight, float height) {
    return weight / (height * height);
}
void save_bmi_to_file(const char name[], float weight, float height, float bmi) {
    FILE *file = fopen("bmi_data.txt", "a");  //
    if (file != NULL) {
        fprintf(file, "%s %.2f %.2f %.2f\n", name, weight, height, bmi);
        fclose(file);
    } else {
        printf("Error opening file to save BMI data.\n");
    }
}
void input_and_process() {
    char name[50];
    float weight, height, bmi;

    printf("Enter name: ");
    scanf("%49s", name);

    printf("Enter weight (kg): ");
    if (scanf("%f", &weight) != 1 || weight <= 0) {
        printf("Invalid weight input.\n");
        return;
    }

    printf("Enter height (m): ");
    if (scanf("%f", &height) != 1 || height <= 0) {
        printf("Invalid height input.\n");
        return;
    }

    bmi = calculate_bmi(weight, height);
    printf("BMI of %s is %.2f\n", name, bmi);

    save_bmi_to_file(name, weight, height, bmi);
}
int main() {
    input_and_process();
    return 0;
}
