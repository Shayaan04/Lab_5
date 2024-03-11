#include <stdio.h>  // Include standard input-output library

// This function prints out the different combinations for the score
void points(int input_value)
{
    // Constants representing different point values for touchdowns, field goals, etc.
    const int TD_conversion = 8;
    const int TD_field = 7;
    const int TD = 6;
    const int FG = 3;
    const int S = 2;
    
    // Nested loops to iterate through possible combinations of scores
    for (int i = 0; i < (input_value / TD_conversion); i++)
    {
        for (int j = 0; j < (input_value / TD_field); j++)
        {
            for (int k = 0; k < (input_value / TD); k++)
            {
                for (int l = 0; l < (input_value / FG); l++)
                {
                    for (int m = 0; m < (input_value / S); m++)
                    {
                        // Check if the combination adds up to the input value
                        if (((8 * i) + (7 * j) + (6 * k) + (3 * l) + (2 * m)) == input_value)
                        {
                            // Print the combination
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", i, j, k, l, m);
                        }
                    }
                }
            }
        }
    }
}

// This function mainly interacts with the user as it asks for an input, gives an output, and runs the while loop until the user inputs a 0 or 1
int main()
{
    int input_value; // Variable to store the user's input
    
    // Loop runs indefinitely until user inputs 0 or 1
    while (1)
    {
        // Prompt the user for input
        printf("Enter 0 or 1 to STOP");
        printf("\nEnter the NFL Score: ");
        
        // Read the user's input
        scanf("%d", &input_value);
        
        // Check if the user wants to stop the program
        if (input_value == 0 || input_value == 1)
        {
            printf("Stopped!\n"); // Inform the user that the program has stopped
            break; // Exit the loop
        }
        else if (input_value < 0) // Check if the input is negative
        {
            printf("Invalid input, try again\n"); // Inform the user of invalid input
        }
        else // If input is valid, call the points function to calculate combinations
        {
            points(input_value); // Call the points function to calculate combinations for the input value
        }
    }
    return 0;
}