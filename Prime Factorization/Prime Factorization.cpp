#include <iostream>
#include <limits>
#include <set>
#include <unordered_map>

int main()
{
    // Current value for the given number
    unsigned long long n = 0;
    // The current factor being checked
    unsigned long long currentFactor = 2;

    // A set that holds all the unique factors
    std::set<unsigned long long> factor_table;
    // A map between each individual factor and the number of times it is applied.
    std::unordered_map<unsigned long long, unsigned short> count_table;

    std::cout << "Please enter a number. [0, " << std::numeric_limits<unsigned long long>::max() << "] : ";
    std::cin >> n;

    // Print heading text
    std::cout << "The Prime Factorization of " << n << " is: 1";

    // While we are unfinished and we have not exceeded the number-space
    while (n != 0 && currentFactor < (n / 2))
    {
        // If it divides evenly
	    if (n % currentFactor == 0)
	    {
            // If a new factor has been reached
            if (factor_table.emplace(currentFactor).second)
                // Add a new counter
                count_table.emplace(currentFactor, 1);
            else// if its the same value
                // Increment the counter
                count_table.at(currentFactor)++;

            // Remove the factor from n
            n /= currentFactor;
            
	    }

        // Increment the current factor being checked
        ++currentFactor;
    }

    // For all used factors
    for (auto factor : factor_table)
    {
        // If this factor is used more than once
        if (count_table.at(factor) > 1)
            // Print it with its exponent
            std::cout << " * (" << factor << "^" << count_table.at(factor) << ')';
        else
            // Print the standalone factor
            std::cout << " * " << factor;
    }

    // If we exceeded the number-space
    if (n != 0)
        // Default by printing n
        std::cout << " * " << n;
}
