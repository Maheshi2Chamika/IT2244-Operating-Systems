![02](https://github.com/user-attachments/assets/701f5ad4-cc5d-44ed-b8b6-e51b876a927d)
![01](https://github.com/user-attachments/assets/1f24f2bd-bf85-4d01-9e3e-d5d3ad3ea764)
![03](https://github.com/user-attachments/assets/90599396-ddec-41ec-94ad-b7efba93ede1)

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
