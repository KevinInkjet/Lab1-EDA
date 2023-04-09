
# Binary Sum Calculator

This program is a command-line tool written in C++ that receives two integer inputs x and y in the range of [-128,127]. The program outputs the following:

- Binary strings that represent x and y in 8-bit two's complement format.
- The binary two's complement format and decimal format of the sum of x and y. The addition operation is performed by manipulating the binary values directly using bitwise operators.
- In the case of overflow during the addition operation, the program reports an error. The validation of overflow is also performed using bitwise operators.


## Inatallation

To run this program, you must have a C++ compiler installed on your system.

1. Clone the  repository to your local machine using the command:

```bash
git clone https://github.com/<username>/<repository-name>.git
```

2. Compile the source code using the following command:

```bash
g++ -o BinarySumCalculator BinarySumCalculator.cpp
```

3. Run the program using the command:

```bash
./BinarySumCalculator
```

## Example

Suppose you enter the values x=25 and y=67. The program output will be as follows:

```
Enter the value of x in the range [-128,127]: 25
Enter the value of y in the range [-128,127]: 67

Binary two's complement format of x: 00011001
Binary two's complement format of y: 01000011
Result of the sum of the two's complement of x with the two's complement of y: 01011100
Result of the sum in decimal: 92
```
