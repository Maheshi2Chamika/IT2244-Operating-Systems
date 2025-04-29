Commands & Examples

1. touch
   Description: Creates a new empty file.
   Usage:
     - touch abc.tsv
   Purpose: Creates the file `abc.tsv` in the current directory.

2. vi
   Description: Opens a file in the 'vi' text editor to create or edit content.
   Usage:
     - vi abc.tsv
   Purpose: Opens the file `abc.tsv` for editing or creation.

3. more
   Description: Displays the contents of a file one page at a time.
   Usage:
     - more abc.tsv
   Purpose: Shows the contents of `abc.tsv` with pagination for easier reading.

4. cut
   Description: Extracts specific columns from a file using a delimiter.
   Usage:
     - cut -d$'\t' -f1 abc.tsv
     - cut -d ' ' -f1 abc.tsv
   Purpose:
     - Extracts the 1st column from `abc.tsv` using tabs as the delimiter.
     - Extracts the 1st column from `abc.tsv` using spaces as the delimiter.

5. head
   Description: Displays the first N lines of a file.
   Usage:
     - head -n2 abc.tsv
   Purpose: Displays the first 2 lines of `abc.tsv`.

6. tail
   Description: Displays the last N lines of a file.
   Usage:
     - tail -n2 abc.tsv
   Purpose: Displays the last 2 lines of `abc.tsv`.

7. awk
   Description: A pattern scanning and text processing language used to manipulate files.
   Usage:
     - awk '{print}' abc.tsv
     - awk '{print $3}' abc.tsv
   Purpose:
     - Prints all the content of `abc.tsv`.
     - Prints the 3rd column of `abc.tsv`.

8. wc
   Description: Counts lines, words, and characters in a file.
   Usage:
     - wc -l abc.tsv
   Purpose: Counts the number of lines in the file `abc.tsv`.

9. grep
   Description: Searches for patterns in a file and displays the matching lines.
   Usage:
     - head -n10 abc.tsv | grep 'dd'
     - head -n7 abc.tsv | grep '56'
   Purpose:
     - Searches for the string "dd" within the first 10 lines of `abc.tsv`.
     - Searches for the string "56" within the first 7 lines of `abc.tsv`.
