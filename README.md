# IT2244-Operating-Systems

#Q1
Commands & Examples

1. @echo off
   - Description: Disables command echoing in the Command Prompt.
   - Usage:
     - @echo off
   - Purpose: Keeps the output clean by hiding command lines from displaying during execution.

2. cd
   - Description: Changes the current directory.
   - Usage:
     - cd %USERPROFILE%\Desktop
     - cd CSC2244
     - cd practical
   - Purpose: Navigates to specified folders to perform operations like file creation.

3. mkdir
   - Description: Creates one or more new directories.
   - Usage:
     - mkdir CSC2244 Marks Exam
     - mkdir practical theory "exam papers"
   - Purpose: Creates necessary folders for organizing exam-related files.

4. echo. > filename
   - Description: Creates empty files with the specified name and extension.
   - Usage:
     - echo. > practical.txt
     - echo. > exam.docx
   - Purpose: Simulates or initializes blank files in relevant directories.

5. move
   - Description: Moves files from one directory to another.
   - Usage:
     - move "Icae Marks.xlsx" Marks
   - Purpose: Organizes files by placing them into appropriate folders.

6. xcopy
   - Description: Copies files and directories, including subdirectories.
   - Usage:
     - xcopy Marks Exam /E /I
   - Purpose: Duplicates the "Marks Exam" folder structure with all contents.

7. attrib +h
   - Description: Sets the "hidden" attribute on a file or folder.
   - Usage:
     - attrib +h Exam
   - Purpose: Hides the "Exam" folder from normal view in File Explorer.
  

#Q2
#AWK Commands for GPA Analysis

Commands & Examples

1. Filter rows where GPA > 3.5
   - Description: Selects and displays rows from the CSV file where the GPA (assumed to be in the 4th column) is greater than 3.5.
   - Usage:
     - awk -F, 'NR==1 || $4 > 3.5' data.csv
   - Purpose: Displays the header and all student records with a GPA above 3.5, helping to identify high-performing students.

2. Calculate average GPA
   - Description: Computes the average GPA from the values in the 4th column of the CSV file, excluding the header row.
   - Usage:
     - awk -F, 'NR>1 {sum+=$4; count++} END {if (count > 0) print "Average GPA:", sum/count}' data.csv
   - Purpose: Provides a summary statistic for all GPAs in the dataset, useful for academic performance analysis.
  

#Q3
#Bash Script to Compare String Lengths

Commands & Examples

1. read
   - **Description**: Reads input from the user.
   - **Usage**:
     - read -p "Enter String_1: " str1
     - read -p "Enter String_2: " str2
   - **Purpose**: Captures two strings from the user for comparison.

2. String Length: ${#var}
   - **Description**: Returns the length of a given string variable.
   - **Usage**:
     - len1=${#str1}
     - len2=${#str2}
   - **Purpose**: Calculates the length of each user-entered string.

3. if / elif / else
   - **Description**: Conditional statements used to compare values.
   - **Usage**:
     - if [ $len1 -gt $len2 ]; then ...
     - elif [ $len1 -lt $len2 ]; then ...
     - else ...
   - **Purpose**: Compares the lengths of the strings and prints which one is longer or if they are equal.

4. echo
   - **Description**: Outputs text to the terminal.
   - **Usage**:
     - echo "$str1 is larger than $str2"
   - **Purpose**: Displays the result of the string comparison to the user.



