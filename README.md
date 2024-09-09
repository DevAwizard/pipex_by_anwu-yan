# pipex_by_anwu-yan






## Tester - Mandatory Part

### Valid arguments - Command Combinations for Two Commands:

#### 1. **Word Count**
- **Command**: `valgrind ./pipex infile "cat" "wc -w" outfile`
- **Explanation**: `cat` reads the contents of `infile`, and `wc -w` counts the words, writing the result to `outfile`.

#### 2. **Line Count**
- **Command**: `valgrind ./pipex infile "cat" "wc -l" outfile`
- **Explanation**: `cat` reads the contents of `infile`, and `wc -l` counts the number of lines.

#### 3. **Character Count**
- **Command**: `valgrind ./pipex infile "cat" "wc -c" outfile`
- **Explanation**: `cat` reads the contents of `infile`, and `wc -c` counts the number of characters (including whitespace and newlines).

#### 4. **Sort File Contents**
- **Command**: `valgrind ./pipex infile "cat" "sort" outfile`
- **Explanation**: `cat` outputs the content of `infile`, and `sort` sorts the lines alphabetically.

#### 5. **Reverse File Content**
- **Command**: `valgrind ./pipex infile "cat" "rev" outfile`
- **Explanation**: `cat` reads `infile`, and `rev` reverses each line of text before writing to `outfile`.

#### 6. **Search for a Pattern**
- **Command**: `valgrind ./pipex infile "cat" "grep 'pattern'" outfile`
- **Explanation**: `cat` reads the contents of `infile`, and `grep 'pattern'` filters lines containing the pattern "pattern".

#### 7. **Remove Empty Lines**
- **Command**: `valgrind ./pipex infile "cat" "grep -v '^$'" outfile`
- **Explanation**: `cat` reads the file, and `grep -v '^$'` removes empty lines from the output.

#### 8. **Count the Number of Lines Matching a Pattern**
- **Command**: `valgrind ./pipex infile "grep 'pattern'" "wc -l" outfile`
- **Explanation**: `grep 'pattern'` searches for lines containing the word "pattern", and `wc -l` counts how many lines matched the pattern.

#### 9. **Find and Count Specific Words**
- **Command**: `valgrind ./pipex infile "grep 'txt'" "wc -w" outfile`
- **Explanation**: `grep 'txt'` searches for lines containing the word "txt", and `wc -w` counts how many words match.

#### 10. **Count Non-Empty Lines**
- **Command**: `valgrind ./pipex infile "grep -v '^$'" "wc -l" outfile`
- **Explanation**: `grep -v '^$'` filters out empty lines, and `wc -l` counts the number of non-empty lines.

#### 11. **Transform Text to Uppercase**
- **Command**: `valgrind ./pipex infile "cat" "tr 'a-z' 'A-Z'" outfile`
- **Explanation**: `cat` reads the contents of `infile`, and `tr 'a-z' 'A-Z'` converts all lowercase letters to uppercase.

#### 12. **Transform Text to Lowercase**
- **Command**: `valgrind ./pipex infile "cat" "tr 'A-Z' 'a-z'" outfile`
- **Explanation**: `cat` reads `infile`, and `tr 'A-Z' 'a-z'` converts uppercase letters to lowercase.

#### 13. **Display the First 5 Lines of the File**
- **Command**: `valgrind ./pipex infile "head -n 5" "cat" outfile`
- **Explanation**: `head -n 5` reads the first 5 lines from `infile`, and `cat` writes it to `outfile`.

#### 14. **Display the Last 5 Lines of the File**
- **Command**: `valgrind ./pipex infile "tail -n 5" "cat" outfile`
- **Explanation**: `tail -n 5` reads the last 5 lines from `infile`, and `cat` outputs them.

#### 15. **Find Files in a Directory and Count Matching Files**
- **Command**: `valgrind ./pipex infile "ls -l" "grep 'txt'" outfile`
- **Explanation**: `ls -l` lists files in the directory, and `grep 'txt'` filters files that contain "txt" in their names.

#### 16. **Unique Lines from a File**
- **Command**: `valgrind ./pipex infile "cat" "uniq" outfile`
- **Explanation**: `cat` reads the content of `infile`, and `uniq` filters out duplicate consecutive lines.

#### 17. **Sort and Remove Duplicates**
- **Command**: `valgrind ./pipex infile "sort" "uniq" outfile`
- **Explanation**: `sort` sorts the lines alphabetically, and `uniq` removes duplicate lines.

#### 18. **Replace a Word in the File**
- **Command**: `valgrind ./pipex infile "sed 's/old/new/g'" "cat" outfile`
- **Explanation**: `sed 's/old/new/g'` replaces all occurrences of "old" with "new" in the file.

#### 19. **Count the Occurrences of a Pattern**
- **Command**: `./pipex infile "grep -o 'word'" "wc -l" outfile`
- **Explanation**: `grep -o 'word'` prints each occurrence of the word "word", and `wc -l` counts how many times it appeared.

#### 20. **Display File Content with Line Numbers**
- **Command**: `valgrind ./pipex infile "cat -n" "cat" outfile`
- **Explanation**: `cat -n` displays each line with its line number, and `cat` writes it to `outfile`.

---
