#include <iostream>
#include <climits>

unsigned int add_checksum(unsigned int n);
void add_checksum( unsigned int array[], std::size_t capacity);
bool verify_checksum(unsigned int n);
unsigned int remove_checksum(unsigned int n);
void remove_checksum(unsigned int array[], std::size_t capacity);

#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING
int main() {

    unsigned int value_to_protect{21352411};
    unsigned int protected_value = add_checksum(value_to_protect);

    std::cout << "The value " << value_to_protect
              << " with the checksum added is " << protected_value
              << "." << std::endl;

    if (verify_checksum(protected_value)) {
        std::cout << "The checksum is valid." << std::endl;
    }
    else {
        std::cout << "The checksum is invalid." << std::endl;
    }

    std::size_t qty_values{3};
    unsigned int value_series[3]{20201122, 20209913, 20224012};

    add_checksum(value_series, qty_values);

    std::cout << "Series with checksums added: ";
    for (std::size_t series_index{0}; series_index < qty_values; series_index++) {
        std::cout << value_series[series_index] << " ";
    }
    std::cout << std::endl;

    return 0;
}
#endif

unsigned int add_checksum(unsigned int n) {
    //Temp variable used to store original input for later use
    unsigned int number = n;

    if (n < 99999999) {
        //Count number of digits in the number
        int count_digits = 0;
        while (n != 0) {
            n /= 10;
            count_digits++;
        }

        if (count_digits != 0) {
            //Declare array
            unsigned int array[count_digits];

            //Reset n to original number
            n = number;

            //Starting at capacity of array, input digits as elements
            for (int i = (count_digits - 1); i >= 0; i--) {
                array[i] = n % 10;
                n /= 10;
            }

            for (int k = (count_digits - 1); k >= 0; k -= 2) {
                //Multiply every other element by 2
                array[k] = array[k] * 2;

                //If the result of multiplying by 2 is greater than 9 -->
                if (array[k] > 9) {
                    //sum the individual digits of result
                    unsigned int sum_digit = 0;
                    while (array[k] != 0) {
                        sum_digit += array[k] % 10;
                        array[k] /= 10;
                    }
                    //Set the result as the new element in array
                    array[k] = sum_digit;
                }
            }

            //Iterate through array and sum all the elements
            unsigned int sum_array = 0;
            for (int i = 0; i < count_digits; ++i) {
                sum_array += array[i];
            }

            //Compute checksum digit
            unsigned int d = (sum_array * 9) % 10;

            //Compute new value with checksum added
            unsigned int new_value = (number * 10) + d;

            //Return new value
            return new_value;
        }
    }

    //Signal error
    else {
        return UINT_MAX;
    }
}

void add_checksum(unsigned int array[], std::size_t capacity) {
    //Loop through each element in array
    for (unsigned int i = 0; i < capacity; i++) {
        //If element value is greater than 9 digits
        if (array[i] > 999999999) {
            //Set element to max unsigned integer
            array[i] = UINT_MAX;
        }
        else {
            //Set element to value with checksum
            array[i] = add_checksum(array[i]);
        }
    }
}

bool verify_checksum(unsigned int n) {
    //Remove last digit of input to use in checksum function
    unsigned int num_check = n / 10;

    //If n is less than 9 digit number and has correct checksum value
    if ((n < 999999999) && (n == add_checksum(num_check))) {
//        std::cout << "true" << std::endl;
        return true;
    }
    else {
//        std::cout << "false" << std::endl;
        return false;
    }
}

unsigned int remove_checksum(unsigned int n) {
    //If checksum digit is not valid or n is greater than 9 digits
    if ((!verify_checksum(n)) || (n > 999999999)) {
        return UINT_MAX;
    }
    else {
        return n/10;
    }
}

void remove_checksum(unsigned int array[], std::size_t capacity) {
    //Loop through each element in array
    for (unsigned int i = 0; i < capacity; i++) {
        //If checksum digit is not valid or value is greater than 9 digit
        if ((!verify_checksum(array[i])) || (array[i] > 999999999)) {
            //Set element to max unsigned integer
            array[i] = UINT_MAX;
        }
        else {
            //Set element without checksum digit
            array[i] = (array[i] / 10);
        }
    }
}