//Author: Nicholas Amancio
//CS2600 | Quiz 3 | 10/23/22


/*Question 2 : Restaurant Bill 
Write a program that computes the tax and tip on a restaurant bill for a patron. The 
program should accept the tax and tip both as percentages as command line arguments. 
Values will be passed into the main() function as arguments. Display the meal cost, tax 
amount, tip amount, and total bill on the screen. The meal cost should be randomly 
chosen between the following four:
Salad: $9.95
Soup: $4.55
Sandwich: $13.25
Pizza: $22.35
*/

/*Outline
Declare our methods for tax and tip and we will take our total and run it through the two methods
First we're going to create a list of the 4 menu items and have a randomizer to choose different items
Afterwards, the program will ask the user to input the amount of tip
the tax is set for the food which is 7.25% in CA
After the total runs through both methods, then the main function will print out our new total.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//declaring our methods
float tax(float total);
float tip(float total, float tipAmount);

float tax(float total) {
    return total * 0.0775;
}
float tip(float totalAfterTax, float tipAmount) {
    return totalAfterTax + tipAmount;
}

int main() {
    //food prices
    float salad = 9.95;
    float soup = 4.55;
    float sandwich = 13.25;
    float pizza = 22.35;
    float total = 0.0;
    float tipAmount;
    float taxAmount;
    float totalAfterTax;
    float totalAfterTip;

    //list of food available
    /*char food1[10] = "salad\n";
    char food2[10] = "soup\n";
    char food3[10] = "sandwich\n";
    char food4[10] = "pizza\n";*/
    float food[4] = {salad, soup, sandwich, pizza};


    //create a new list of food being ordered, most people shouldn't order more than 3 items
    float foodOrdered[3];

    //randomizer seed
    //srand(time(0));

    //run through a for loop in order to let the program choose 3 random foods and insert them into a new array
    for (int i = 0; i < 3; i++) {
        foodOrdered[i] = food[rand() % sizeof * food];
        total += foodOrdered[i];
    }

    //print out a list of items ordered
    /*printf("Items ordered: \n");
    for (int i = 0; i < 3; i++) {
        if (foodOrdered[i] = salad)
            printf("%s", food1);
        else if(foodOrdered[i] = soup)
            printf("%s", food2);
        else if(foodOrdered[i] = sandwich)
            printf("%s", food3); 
        else if(foodOrdered[i] = pizza)
            printf("%s", food4);
    }*/

    //throw the total into our tax method
    taxAmount = tax(total);
    totalAfterTax = total + tax(total);

    //ask the user to input the tip
    printf("Enter the amount of tip you would like to give: \n");
    scanf("%f", &tipAmount);

    //then throw the total into our tip method
    totalAfterTip = tip(totalAfterTax, tipAmount);
    
    //print out the bill
    printf("Bill:\nMeal Cost: $%.2f\n", total);
    printf("tax: $%.2f\n", taxAmount);
    printf("tip: $%.2f\n", tipAmount);
    printf("-------------------------------\n");
    printf("Your total amount is $%.2f\n", totalAfterTip);

    //end program
    return 0;
}
