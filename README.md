# 🐍 Python Awk Utility (`python-awk`)

A small, versatile Python utility that mimics the pattern-matching and field-processing functionality of the classic Unix `awk` command. Easily extract and replace fields from input strings, standard input, or files\!

## ✨ Key Features

  * **Flexible Input Handling:** Accepts input data as a **direct string**, from **standard input (`-stdin`)**, or from a **specified file** (e.g., `-filename.txt`).
  * **Awk-style Field Referencing:** Uses simple dot notation (e.g., **`.1`, `.2`**) to reference fields/columns in the input data.
  * **Custom Output:** Define a custom output string where field references are dynamically replaced with the actual input data.
  * **Pythonic & Simple:** A concise, self-contained Python script with clear function separation.

-----

## 🚀 Quick Usage

USE . instead of $

e.g.
python awk.py "e r t" "last: .3  first: .1 middle: .2"
python awk.py -file "last: .3  first: .1 middle: .2 bad: .2 bad: .-1"
echo "t g b" | python awk.py -stdin "last: .3  first: .1 middle: .2 bad: .2 bad: .-1"

The general syntax is:

```bash
python awk.py <INPUT_SOURCE> "<OUTPUT_FORMAT_STRING>"
```

### 1\. Direct String Input (Most Common)

Pass the input data as the first argument (must be space-separated).

```bash
# Input: "Apple Banana Cherry"
# Output Format: "I like .2 and .3"
# Expected Output: "I like Banana and Cherry"
python awk.py "Apple Banana Cherry" "I like .2 and .3"
```

### 2\. Standard Input (`-stdin`)

Pipe data directly into the script.

```bash
echo "red green blue" | python awk.py -stdin "The colors are .3, .2, and .1."
# Expected Output: "The colors are blue, green, and red."
```

### 3\. File Input

Read data from a specified file (must start with `-` followed by the filename).

**`data.txt` content:**

```
user_id created_at status
```

```bash
python awk.py -data.txt "User .1 was created on .2"
# Expected Output: "User user_id was created on created_at"
```

-----

## 🛠️ How it Works

The script follows a simple three-step process:

1.  **Parse Arguments:** Determine the input source and the desired output format string.
2.  **Extract Fields:** Read the input and split it into a list of fields (tokens).
3.  **Replace & Print:** Iterate through the output format string, identify field references (`.1`, `.2`, etc.), substitute them with the corresponding field from the input, and print the result.

-----

### 💡 Contribute

Feel free to fork, suggest improvements, or submit pull requests\!
