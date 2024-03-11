#include <stdio.h>     
#include <stdlib.h>    
#include <string.h>   

// Define a structure named Key_Val to represent a key-value pair
struct Key_Val {
    char key[100];    // A character array to store the key (month name)
    double value;     // A double to store the value (sales number)
};

// Declare an array of structures to store monthly sales data
struct Key_Val month_sales[12];  // It can hold sales data for 12 months

// This function creates a dictionary where the months are the key names, and the sales number is the value
// It reads data from a file containing the sales numbers
void dictionary() {
    // Open the file named "sample_input.txt" for reading
    FILE *sales = fopen("sample_input.txt", "r");

    char mySales[100];   // Buffer to store each line read from the file
    // Array containing month names
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int i = 0;   // Counter for indexing month_sales array
    // Read each line from the file until end of file or all 12 months are read
    while (fgets(mySales, sizeof(mySales), sales) && (i < 12)) {
        // Convert the read sales number from string to float
        float sale_num = atof(mySales);
        // Copy the month name into the key field of the corresponding struct
        strcpy(month_sales[i].key, months[i]);
        // Store the sales number into the value field of the corresponding struct
        month_sales[i].value = sale_num;
        i++;  // Move to the next month
    }
    fclose(sales);  // Close the file after reading
}

// This function prints the monthly sales report
void monthly_report() {
    // Print the header of the sales report
    printf("Monthly Sales Report for 2022: \n");
    printf("\n");
    printf("%-10s %s\n", "Month", "Sales");
    printf("\n");

    // Loop through each month and print its name and corresponding sales number
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2f\n", month_sales[i].key, month_sales[i].value);
    }
}


// This method prints the sales summary
void sales_summary()
{
    // Initialize variables to store maximum, minimum, average, and total sales
    float max_sales = month_sales[0].value, min_sales = max_sales, avg_sales = 0, total_sales = 0;
    char max_month[100], min_month[100]; // Arrays to store names of months with maximum and minimum sales

    // Print the header for the sales summary
    printf("Sales Summary \n");
    printf("\n");

    // Loop through each month to find minimum, maximum, and total sales
    for (int i = 0; i < 12; i++)
    {
        // Check if current month's sales is greater than current maximum sales
        if (month_sales[i].value > max_sales)
        {
            max_sales = month_sales[i].value; // Update maximum sales
            strcpy(max_month, month_sales[i].key); // Update month with maximum sales
        }

        // Check if current month's sales is less than or equal to current minimum sales
        if (month_sales[i].value <= min_sales)
        {
            min_sales = month_sales[i].value; // Update minimum sales
            strcpy(min_month, month_sales[i].key); // Update month with minimum sales
        }

        total_sales += month_sales[i].value; // Accumulate total sales
    }

    avg_sales = total_sales / 12; // Calculate average sales

    // Print minimum, maximum, and average sales
    printf("Minimum sales: $%.2f (%s)\n", min_sales, min_month);
    printf("Maximum sales: $%.2f (%s)\n", max_sales, max_month);
    printf("Average sales: $%.2f\n", avg_sales);
}

// This function calculates and prints the six month moving average report
void six_month_report()
{
    char max_month[100], min_month[100]; // Arrays to store names of months with maximum and minimum sales
    float avg_sales = 0; // Variable to store average sales

    // Print the header for the six-month moving average report
    printf("Six-Month Moving Average Report:\n");
    printf("\n");

    // Loop through each set of six months to calculate their average sales
    for (int i = 0; i <= 6; i++)
    {
        float total_sales = 0; // Variable to store total sales for current six months
        // Calculate total sales for current set of six months
        for (int j = i; j <= (5 + i); j++)
        {
            total_sales += month_sales[j].value;
        }
        avg_sales = total_sales / 6; // Calculate average sales for the current six months
        // Print the average sales for the current set of six months
        printf("%-10s - %-10s $%.2f\n", month_sales[i].key, month_sales[i + 5].key, avg_sales);
    }
}

// This method prints the sales report in order of highest sales to the lowest sales
void high_low_report()
{
    float temp_value; // Temporary variable to store sales value during swapping

    // Sort the month_sales array based on sales values in descending order using bubble sort
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (month_sales[i].value > month_sales[j].value) // Check if current sales is greater than sales to its right
            {
                // Swap sales values
                temp_value = month_sales[i].value;
                month_sales[i].value = month_sales[j].value;
                month_sales[j].value = temp_value;

                // Swap month names
                struct Key_Val temp_month; // Temporary structure variable to store month name during swapping
                strcpy(temp_month.key, month_sales[i].key);
                strcpy(month_sales[i].key, month_sales[j].key);
                strcpy(month_sales[j].key, temp_month.key);
            }
        }
    }

    // Print the header for the high to low sales report
    printf("Sales Report (Highest to Lowest):\n");
    printf("\n");
    printf("%-10s %-10s\n", "Month", "Sales");
    printf("\n");

    // Print the sorted sales report
    for (int i = 0; i < 12; ++i)
    {
        printf("%-10s: $%-10.2f\n", month_sales[i].key, month_sales[i].value);
    }
}

// This is the main method that calls the methods created above and calculates and prints the results
int main()
{
    dictionary();        // Populate the month_sales array from file
    monthly_report();    // Print the monthly sales report
    printf("\n");
    printf("\n");
    sales_summary();     // Print the sales summary
    printf("\n");
    printf("\n");
    six_month_report();  // Print the six-month moving average report
    printf("\n");
    printf("\n");
    high_low_report();   // Print the high to low sales report
    return 0;
}
