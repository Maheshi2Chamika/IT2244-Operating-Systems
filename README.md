# IT2244-Operating-Systems

## Commands & Examples
### 1. LCM and GCD Calculator
- **Description**: Reads three numbers from the user and calculates:
  - LCM (Least Common Multiple) of the first two numbers (a and b)
  - GCD (Greatest Common Divisor) of the last two numbers (b and c)

- **Usage**:
  ```bash
  echo "Enter the first number(a): "
  read a
  echo "Enter the second number(b): "
  read b
  echo "Enter the third number(c): "
  read c

  gcd() {
      local x=$1
      local y=$2
      while [ $y -ne 0 ]; 
      do
          temp=$y
          y=$((x % y))
          x=$temp
      done
      echo $x
  }

  lcm() {
      local x=$1
      local y=$2
      echo $((x * y / $(gcd $x $y)))
  }

  # Calculate LCM of a and b
  lcm_ab=$(lcm $a $b)

  # Calculate GCD of b and c
  gcd_bc=$(gcd $b $c)

  # Display results
  echo "LCM of $a and $b: $lcm_ab"
  echo "GCD of $b and $c: $gcd_bc"
  ```

- **Purpose**: Demonstrates reading user input, function creation, and performing mathematical operations using logic in Bash to compute both LCM and GCD.
