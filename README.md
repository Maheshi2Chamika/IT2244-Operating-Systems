##  Commands & Examples

### 1. `awk`
**Description:** A pattern scanning and text processing language.  
**Usage:**
```bash
awk '{ sum += $1 }; END { print sum }' file
awk -F: '{ print $1 }' /etc/passwd
```
**Purpose:** Aggregates data or extracts specific fields from structured text.

---

### 2. `sed`
**Description:** A stream editor for filtering and transforming text.  
**Usage:**
```bash
sed -n '1,3p' file.txt
sed 's/old/new/g' file.txt
```
**Purpose:** Performs editing operations like substitution, deletion, and selective printing.

---

### 3. `find`
**Description:** Searches for files and directories in a directory hierarchy.  
**Usage:**
```bash
find .
find . -name "*.txt"
```
**Purpose:** Lists files in the current directory or recursively based on patterns.

---

### 4. `ls`
**Description:** Lists files and directories.  
**Usage:**
```bash
ls -ltr
ls -a
```
**Purpose:** Displays file details and hidden files with sorting options.
