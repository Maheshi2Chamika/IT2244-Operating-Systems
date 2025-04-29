# IT2244-Operating-Systems


## Commands & Examples

---

### 1. Fibonacci Numbers
   - **Description**: Generates and displays the first 10 Fibonacci numbers.
   - **Usage**:
     ```bash
     a=0
     b=1
     echo -n "$a $b "
     for (( i=2; i<10; i++))
     do
         fib=$((a+b))
         echo -n "$fib "
         a=$b
         b=$fib
     done
     ```
   - **Purpose**: Calculates a sequence where each number is the sum of the two preceding ones.

---

### 2. Factorial
   - **Description**: Calculates the factorial of a given number (e.g., 5!).
   - **Usage**:
     ```bash
     fact=1
     num=5
     for (( i=1; i<=num; i++))
     do
         fact=$((fact*i))
     done
     echo "Factorial $num = $fact"
     ```
   - **Purpose**: Finds the product of all positive integers up to the specified number.

---

### 3. Multiples of 3 between 1 and 50
   - **Description**: Displays all multiples of 3 from 1 to 50 using both while and for loops.
   - **Usage**:
     ```bash
     # using while loop
     let i=3
     while [ $i -le 50 ];
     do
         echo $i
         i=$(($i+3))
     done

     # using for loop
     for (( i=3; i<=50; i+=3))
     do
         echo $i
     done
     ```
   - **Purpose**: Prints a list of numbers divisible by 3 within a specific range using two different loop constructs.
