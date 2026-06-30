Date: June 29

Section 1 — Specific Bug
---

### Bug 1: Multi-word Values

When executing:

```text
redis> SET name vivek singh
redis> GET name
vivek
```

Only the first word of the value was stored because the parser extracted the value using the stream extraction operator (`>>`).

---

### Bug 2: Google Test Compilation

Compilation failed while building Google Test.

**Compiler Error**

```text
error: 'mutex' in namespace 'std' does not name a type
error: 'condition_variable' in namespace 'std' does not name a type
```

The project was using MinGW GCC 6.3.0, which is incompatible with the downloaded Google Test version.

---

### Bug 3: CMake Generator Conflict

After reconfiguring the project:

```text
CMake Error:
generator : MinGW Makefiles
Does not match the generator used previously:
NMake Makefiles
```

The existing build directory had been configured with a different generator.

---

Section 2 — Failed Attempt

Initially, I believed that modifying only the parser logic would make the Redis commands functional. Although the parser correctly extracted the command, key, and value, it only printed them to the console. Since no `Redis` object was shared between commands, no data was stored.

For Google Test, I first assumed the compilation errors were caused by incorrect CMake configuration or missing libraries. After checking the build output and compiler version, I determined that the actual issue was the outdated MinGW GCC 6.3.0 toolchain rather than the test code itself.

---

Section 3 — Memory Diagram

**The Hand drawn diagram submitted separately**

The diagram includes:

1. DynamicArray memory before and after resize.
2. Redis object connected to the parser and HashMap.
3. Deep copy of a user-defined object during DynamicArray resize.
4. Parser → Redis → HashMap interaction during `SET` and `GET` commands.

---

Section 4 — Code Reference

### Files Modified

* `src/parser.cpp`
* `include/parser.h`
* `main.cpp`
* `include/HashMap.h`
* `CMakeLists.txt`

**Relevant Sections**

* Parser integration with Redis
* Persistent Redis object creation
* Multi-word value parsing using `getline()`
* Case-insensitive command handling
* Google Test configuration

---

Section 5 — Learning Reflection

Today I gained a much clearer understanding of how parsing, data storage, and automated testing work together in a C++ project.

Before today, I viewed the parser as a component that only interpreted user input. After integrating it with the `Redis` class, I understood that a parser should convert text commands into operations on application state. I also realized why the `Redis` object must exist outside the REPL loop—creating it inside the loop would recreate the database on every iteration and lose previously stored data.

While improving the parser, I learned that the stream extraction operator (`>>`) stops reading at whitespace, which explains why only the first word of a value was stored. Replacing it with `getline()` allowed the parser to capture the remainder of the input as a single value.

I also explored Google Test for the first time. Instead of relying on manual testing, I learned how to write repeatable unit tests using fixtures (`TEST_F`) and assertions such as `EXPECT_EQ` and `EXPECT_THROW`. 

