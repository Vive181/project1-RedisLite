### Date: June 26, 2026

### Section 1 — Specific Bug

**Runtime Output:**

redis> SET name
SET -> name =


The parser accepted the `SET` command even though the value argument was missing. Instead of reporting an error, it treated the value as an empty string.

---

### Section 2 — Failed Attempt

My first approach was to split the input using `stringstream` and immediately process the command without validating the number of arguments.

```cpp
ss >> command;
ss >> key;
ss >> value;
```

This failed because commands with missing arguments, such as `SET name`, were still accepted. The parser did not check whether extraction of the key and value was successful before processing the command.

To fix this, I tested the parser with multiple valid and invalid inputs and added checks to ensure that each command received the required number of arguments before continuing.

---

### Section 3 — Memory Diagram

memory diagram showing how `stringstream` extracts tokens:

```
Input:
"SET name Uvek"

                stringstream
                     |
                     v
+-----------------------------+
| SET | name | Vivek |
+-----------------------------+
   |      |       |
   v      v       v
command   key    value

command = "SET"
key     = "name"
value   = "Uvek"
```

---

### Section 4 — Code Reference

**Commit Hash:** `<your_git_commit_hash>`

**Filename:** `parser.cpp`

**Relevant Lines:** 8–32 (Command parsing logic)

---

### Section 5 — Learning Reflection

Today I learned that parsing is more than splitting a string into words. A parser must also validate whether the input follows the expected command format. I realized that `stringstream` silently fails when tokens are missing, so relying only on extraction is not enough. Every command should verify that the required arguments exist before execution. This understanding will make it easier to connect the parser with the key-value storage in the next stage of the Redis clone.
