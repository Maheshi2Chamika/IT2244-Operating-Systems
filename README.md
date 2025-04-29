# IT2244-Operating-Systems![01](https://github.com/user-attachments/assets/3ab7a97e-9395-4554-b233-9ee18f417e09)
![02](https://github.com/user-attachments/assets/bab61eea-4dfe-42b9-9674-46026c64f289)

Commands & Examples

1. vi
Description: Opens a file in the 'vi' text editor to create or edit content.
Usage:
    - vi test.csv
Purpose: Opens the file `test.csv` for editing or creation.

2. more
Description: Displays the contents of a file one page at a time.
Usage:
    - more test.csv
Purpose: Shows the contents of `test.csv` with pagination for easier reading.

3. less
Description: Allows scrolling up and down in the file.
Usage:
    - less test.csv
Purpose: Provides a more flexible way to view `test.csv` content, allowing both upward and downward scrolling.

4. cut
Description: Extracts specific columns from a CSV file using a delimiter.
Usage:
    - cut -d, -f1,3 test.csv
    - cut -d, -f2 test.csv
Purpose: 
    - Extracts the 1st and 3rd columns from `test.csv`.
    - Extracts only the 2nd column from `test.csv`.

5. head
Description: Displays the first N lines of a file.
Usage:
    - head -3 test.csv
Purpose: Displays the first 3 lines of `test.csv`.

6. tail
Description: Displays the last N lines of a file.
Usage:
    - tail -3 test.csv
Purpose: Displays the last 3 lines of `test.csv`.

7. wc
Description: Counts lines, words, and characters in a file.
Usage:
    - wc -l test4.csv
Purpose: Counts the number of lines in the file `test4.csv`.

8. awk
Description: A pattern scanning and text processing language used to manipulate files.
Usage:
    - awk -F, '{print$1}' test.csv
Purpose: Extracts and prints the first column of `test.csv` based on the comma delimiter.

9. chmod
Description: Changes the file permissions of a file or directory.
Usage:
    - chmod 444 test4.csv
    - chmod 744 test4.csv
Purpose:
    - Sets read-only permissions for everyone on `test4.csv`.
    - Grants full permissions to the owner and read-only permissions to others on `test4.csv`.
