#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //1. get the lower limit
    //2. get the upper limit with the lower limit 
    //3. get the step 
    //4. for loop from low to upper with step print out 
    //
    //

    int lower, upper, step;
    int lower_low = 0;
    int step_low = 0;
    int step_high = 10;
    int upper_limit = 5000;
    printf("Enter a lower limit: limit >= %d :", lower_low);
    scanf("%d", &lower);

    printf("Enter a upper limit : %d > limit <= %d :", lower, upper_limit);
    scanf("%d", &upper);

    printf("Enter a step, %d < step <= %d : ", step_low, step_high);
    scanf("%d", &step);
    
    cout << right << setw(5) << "Celcius" << "Farenheit" << endl;
    cout << right << setw(5) << "--------" << "----------" << endl;

    double cel = 0;
    double freh = 0;
    for(int i = lower; i<= upper; i+= step) {
        cel = i;
        freh = (9.0 * cel) / 5.0 + 32.0;
        printf("%9.6f\t %9.6f\n", cel, freh);
    }

}
