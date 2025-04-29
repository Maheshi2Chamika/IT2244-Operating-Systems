
## Commands & Examples

---

### 1. Multiplication Table of 2
- **Description**: Prints the multiplication table of 2 from 1 to 10 using a for loop.
- **Usage**:
  ```bash
  for ((i=1;i<=10;i++))
  do
      echo "$i * 2 = $((i * 2))"
  done
  ```
- **Purpose**: Demonstrates how to perform multiplication operations and use a `for` loop in Bash scripting.

---

### 2. Diamond Star Pattern
- **Description**: Prints a symmetrical diamond-shaped pattern based on user input.
- **Usage**:
  ```bash
  echo "Enter the number of stars: "
  read stars
  # Top half
  for ((i=1; i<=stars; i++))
  do
     for ((j=i; j<stars; j++))
     do
       echo -n " "
     done
     for ((k=1; k<=((2*i-1)); k++))
     do
       echo -n "*"
     done
     echo ""
  done
  # Bottom half
  for ((i=stars-1; i>=1; i--))
  do
      for ((j=stars; j>i; j--))
      do
          echo -n " "
      done
      for ((k=1; k<=((2*i-1)); k++))
      do
          echo -n "*"
      done
      echo
  done
  ```
- **Purpose**: Uses nested loops and alignment techniques to generate a centered diamond star pattern.

---

### 3. Hollow Square Pattern
- **Description**: Prints a 6x6 hollow square pattern using asterisks.
- **Usage**:
  ```bash
  rows=6
  cols=6
  for ((i=1; i<=rows; i++))
  do
      for ((j=1; j<=cols; j++))
      do
          if [ $i -eq 1 ] || [ $i -eq $rows ] || [ $j -eq 1 ] || [ $j -eq $cols ]; then
              echo -n "*"
          else
              echo -n " "
          fi
      done
      echo ""
  done
  ```
- **Purpose**: Shows how to use conditions inside loops to create bordered patterns.

---

### 4. Fibonacci Series and Sum
- **Description**: Displays the first 10 Fibonacci numbers and their sum.
- **Usage**:
  ```bash
  a=0
  b=1
  sum=0
  count=10

  echo -n "Fibonacci Series: "

  for ((i=0; i<count; i++))
  do
      echo -n "$a "
      sum=$((sum + a))
      fn=$((a + b))
      a=$b
      b=$fn
  done
  echo ""
  echo "Sum of the first 10 fibonacci numbers is: $sum"
  ```
- **Purpose**: Uses variables and iteration to compute the Fibonacci series and its cumulative sum.

---

### 5. Sum of Prime Numbers (1–100)
- **Description**: Calculates the sum of all prime numbers between 1 and 100.
- **Usage**:
  ```bash
  sum=0

  is_prime() {
      num=$1
      if [ $num -le 1 ]; then
          return 1
      fi
      for ((i=2; i*i<=num; i++)); do
          if (( num % i == 0 )); then
              return 1
          fi
      done
      return 0
  }

  for ((n=1; n<=100; n++))
  do
      if is_prime $n; then
          sum=$((sum + n))
      fi
  done

  echo "Sum of prime numbers between 1 and 100 is: $sum"
  ```
- **Purpose**: Demonstrates function creation and prime number logic using loops and conditionals.

---
