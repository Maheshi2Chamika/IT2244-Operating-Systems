# IT2244-Operating-Systems


## Commands & Examples

---

### 1. `cal` and `date`
   - **Description**: Displays the current calendar and the current date and time.
   - **Usage**:
     - `cal`
     - `date`
   - **Purpose**: Shows the current month’s calendar and displays the current date and time in the system's timezone.

---

### 2. Get the student name and marks for 3 subjects and calculate "Total" and "Average"
   - **Description**: Prompts the user to input their name and marks for 3 subjects, then calculates the total and average.
   - **Usage**:
     ```bash
     echo "Enter the name:"
     read name
     echo "Enter the mark for subject1"
     read x
     echo "Enter the mark for subject2"
     read y
     echo "Enter the mark for subject3"
     read z
     sum=$(($x+$y+$z))
     avg=$(($sum/3))
     echo "Enter the name:" $name
     echo "Summation " $sum
     echo "Average   " $avg
     ```
   - **Purpose**: Computes the total and average marks of a student in 3 subjects.

---

### 3. Create a calculator with arithmetic operators
   - **Description**: Prompts the user to input two numbers and performs basic arithmetic operations: addition, subtraction, multiplication, and division.
   - **Usage**:
     ```bash
     echo "Enter the first number"
     read a
     echo "Enter the second number"
     read b
     sum=$(($a+$b))
     sub=$(($a-$b))
     div=$(($a/$b))
     mul=$(($a*$b))
     echo "Summation      " $sum
     echo "Substraction   " $sub
     echo "Division       " $div
     echo "Multiplication " $mul
     ```
   - **Purpose**: Performs arithmetic operations on two user-provided numbers.

---

### 4. Get the day of the week based on the user input number
   - **Description**: Takes a number (1-7) and outputs the corresponding day of the week.
   - **Usage**:
     ```bash
     echo "Enter a number (1-7) for the day"
     read dayNumber
     case $dayNumber in
       1) echo "Monday";;
       2) echo "Tuesday";;
       3) echo "Wednesday";;
       4) echo "Thursday";;
       5) echo "Friday";;
       6) echo "Saturday";;
       7) echo "Sunday";;
       *) echo "Invalid input. Please enter a number between 1 and 7.";;
     esac
     ```
   - **Purpose**: Displays the name of the day corresponding to the number entered by the user.

---

### 5. Verify if the username is correct
   - **Description**: Prompts the user for their username and checks it against a predefined correct username.
   - **Usage**:
     ```bash
     correctUsername="Mino"
     echo "Enter user name:"
     read enteredUsername
     if [ "$enteredUsername" == "$correctUsername" ]; then
         echo "User name is correct"
     else
         echo "User name is incorrect"
     fi
     ```
   - **Purpose**: Verifies whether the entered username matches the expected username.

---

### 6. Compare two numbers and print which one is greater or if they are equal
   - **Description**: Compares two input numbers and outputs which number is greater or if they are equal.
   - **Usage**:
     ```bash
     echo "Enter numbers"
     read num1 num2
     if [ "$num1" -gt "$num2" ]; then
         echo "$num1 is greater than $num2"
     elif [ "$num1" -lt "$num2" ]; then
         echo "$num1 is less than $num2"
     else
         echo "$num1 is equal to $num2"
     fi
     ```
   - **Purpose**: Compares two numbers and outputs the comparison result.

---

### 7. Create a simple calculator using the `expr` command
   - **Description**: Performs basic arithmetic operations using the `expr` command.
   - **Usage**:
     ```bash
     a=15
     b=4
     echo "Add: $(expr $a + $b)"
     echo "Sub: $(expr $a - $b)"
     echo "Mul: $(expr $a \* $b)"
     echo "Div: $(expr $a / $b)"
     echo "Mod: $(expr $a % $b)"
     ```
   - **Purpose**: Performs addition, subtraction, multiplication, division, and modulus operations using `expr`.
