Date: June 29
Duration: 120 minutes

Goal:

Enhance RedisLite command parser and integrate it with the database to support persistent storage, multi-word values, and improved command handling.

Problem Encountered:

* Parser only printed parsed commands instead of executing database operations.
* Data was lost between commands because no persistent Redis instance existed.
* Compilation failed due to a const-correctness issue in the HashMap implementation.
* `SET` command stored only the first word of multi-word values.
* Commands were case-sensitive (`set` was treated as an unknown command).
* Build failed with a **Permission denied** error because `test_app.exe` was still running.

What I Tried:

* Modified the parser to accept a `Redis& db` reference and replaced print statements with `db.set()`, `db.get()`, and `db.del()` calls.
* Created a persistent `Redis db` object outside the REPL loop in `main.cpp` and passed it to the parser.
* Marked `HashMap::contains()` as `const` to satisfy const-correctness requirements.
* Replaced `ss >> value` with `getline(ss, value)` and trimmed the leading whitespace to capture the entire value.
* Converted command strings to uppercase before comparison to support case-insensitive commands.
* Terminated the running `test_app.exe` process before rebuilding the project.

Outcome:

* Successfully connected the parser to the Redis database, enabling command execution.
* Database state now persists across multiple REPL commands.
* Fixed the const-correctness compilation error.
* `SET` now correctly stores multi-word values (e.g., `SET name vivek singh`).
* Commands such as `set`, `Set`, and `SET` are all recognized correctly.
* Resolved the executable locking issue, allowing the project to rebuild successfully.
