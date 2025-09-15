# Random Number Generator (`Random.cpp`)

## Overview

This module provides a simple random number generator class for C++. It is designed to generate random numbers within a specified limit, suitable for game development or any application requiring bounded randomization.

## Features

- Generates a random integer between 1 and a user-defined maximum limit.
- Supports error handling for invalid limits.
- Utilizes modern C++ `<random>` facilities for better randomness.

## Usage

1. **Initialization:**
   - Create an instance of the `Random` class, passing the upper limit as a constructor argument.
   - The limit must be between 1 and 99 (inclusive). Otherwise, an error is thrown and the program terminates.

2. **Generating a Random Number:**
   - Call the `Get_Random_Number()` method to receive a random integer between 1 and the specified limit.

## Example

```cpp
#include "Random.h"

int main() {
    Random rng(50); // Limit is 50
    unsigned short num = rng.Get_Random_Number();
    std::cout << "Random number: " << num << std::endl;
    return 0;
}
```

## Main Functions

- `Random::Random(const size_t limite)`
  - Constructor that sets the upper limit for random number generation.

- `unsigned short Random::Get_Random_Number() const`
  - Generates and returns a random number in the range `[1, limit]`.

- `void Random::Error(const char* str) noexcept` and `void Random::Error(const std::string str) noexcept`
  - Internal error reporting and termination.

## Implementation Notes

- Uses `std::random_device`, `std::mt19937`, and `std::uniform_real_distribution` for number generation.
- Limit checking ensures the upper bound does not exceed 99.
- Outputs errors to `std::cout` and terminates on invalid usage.

## File Location

- Source: [`Random.cpp`](./Random.cpp)
- Header: [`Random.h`](./Random.h)

---

*This module is a basic and efficient solution for generating random numbers within a given range, with built-in error handling for safe usage.*
