# IT2244-Operating-Systems

# README File for Shell Commands

## Commands & Examples

### 1. `vi file28.csv`
   - **Description**: Opens or creates a CSV file named `file28.csv` for editing using the `vi` text editor.
   - **Usage**:
     - `vi file28.csv`
   - **Purpose**: Used to view or edit the contents of `file28.csv`.

### 2. `wc -l file28.csv`
   - **Description**: Counts the number of lines in `file28.csv`.
   - **Usage**:
     - `wc -l file28.csv`
   - **Purpose**: Displays the number of lines in the file.

### 3. `awk -F, '{print NF;exit}' file28.csv`
   - **Description**: Prints the number of columns in `file28.csv` (based on a comma delimiter).
   - **Usage**:
     - `awk -F, '{print NF;exit}' file28.csv`
   - **Purpose**: Finds the number of columns in the CSV file.

### 4. `awk -F, '{print $3}' file28.csv`
   - **Description**: Prints the values of the third column (Age) in `file28.csv`.
   - **Usage**:
     - `awk -F, '{print $3}' file28.csv`
   - **Purpose**: Extracts the third column from the CSV file.

### 5. `cut -d, -f3 file28.csv`
   - **Description**: Another way to print the third column using `cut` command.
   - **Usage**:
     - `cut -d, -f3 file28.csv`
   - **Purpose**: Extracts the third column (Age) from the CSV file.

### 6. `head -n7 file28.csv | tail -n1`
   - **Description**: Prints the seventh row of `file28.csv`.
   - **Usage**:
     - `head -n7 file28.csv | tail -n1`
   - **Purpose**: Displays the 7th row from the file.

### 7. `tail -n7 file28.csv`
   - **Description**: Displays the last seven rows from `file28.csv`.
   - **Usage**:
     - `tail -n7 file28.csv`
   - **Purpose**: Prints the last 7 rows of the file.

### 8. `awk -d, '{print}' file28.csv`
   - **Description**: Prints all the contents of `file28.csv`.
   - **Usage**:
     - `awk -d, '{print}' file28.csv`
   - **Purpose**: Displays all rows and columns of the file.

### 9. `awk -F, '{print $2,$3}' file28.csv`
   - **Description**: Prints the second (Name) and third (Age) columns of `file28.csv`.
   - **Usage**:
     - `awk -F, '{print $2,$3}' file28.csv`
   - **Purpose**: Extracts and prints the Name and Age columns.

### 10. `awk -F, '{print $2,$3}' file28.csv >> xyz1.csv`
   - **Description**: Extracts the second and third columns (Name, Age) and appends them to a file `xyz1.csv`.
   - **Usage**:
     - `awk -F, '{print $2,$3}' file28.csv >> xyz1.csv`
   - **Purpose**: Saves the selected columns (Name, Age) to `xyz1.csv`.

### 11. `awk -F, '{print $4}' file28.csv | sort -r`
   - **Description**: Prints the Salary column in reverse (descending) order.
   - **Usage**:
     - `awk -F, '{print $4}' file28.csv | sort -r`
   - **Purpose**: Sorts and displays the Salary column in descending order.

### 12. `sort -t',' -k4,4n file28.csv`
   - **Description**: Sorts the rows of `file28.csv` by the Salary column in ascending order.
   - **Usage**:
     - `sort -t',' -k4,4n file28.csv`
   - **Purpose**: Sorts and displays the rows by Salary in ascending order.

### 13. `sort -t',' -k4,4 -r file28.csv`
   - **Description**: Sorts the rows of `file28.csv` by the Salary column in descending order.
   - **Usage**:
     - `sort -t',' -k4,4 -r file28.csv`
   - **Purpose**: Sorts and displays the rows by Salary in descending order.

