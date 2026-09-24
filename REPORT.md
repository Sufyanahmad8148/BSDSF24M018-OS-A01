# Operating Systems Programming Assignment - Report

## Feature 2: Multi-file Project, Make and Git

### Question 1

**Explain the linking rule in this part's Makefile: `$(TARGET): $(OBJECTS)`. How does it differ from a Makefile rule that links against a library?**

**Answer:**

The rule:

```make
$(TARGET): $(OBJECTS)
```

means that the final program (`$(TARGET)`) depends on all the object files (`$(OBJECTS)`).

The object files are then linked together to create the final executable.

For example:

```text
main.o + myutils.o + fileutils.o → client
```

When linking against a library, the Makefile also tells the compiler to use a library. For example:

```bash
gcc main.o -Llib -lmyutils -o client
```

Here, `-Llib` tells the compiler where the library is located, and `-lmyutils` tells it to link with `libmyutils`.

So, the main difference is that `$(OBJECTS)` directly lists the object files being linked, while a library rule uses a library file containing compiled functions.

---

### Question 2

**What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?**

**Answer:**

A Git tag is a name given to a specific commit in a Git repository.

Tags are useful for marking important versions of a project. For example:

```text
v0.2.1-static
v0.3.1-dynamic
v0.4.1-final
```

A simple tag is a lightweight tag. It is basically just a name pointing to a commit.

An annotated tag contains more information, such as the tag message, tagger information, and date.

For example, the annotated tag command is:

```bash
git tag -a v0.4.1-final -m "Version 0.4.1 - Final Build"
```

Annotated tags are useful for marking important releases because they contain additional information.

---

### Question 3

**What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?**

**Answer:**

A GitHub Release is used to publish a specific version of a project.

It is connected to a Git tag, so users can easily find the source code for that version.

Attaching binaries such as the client executable is useful because users can download and run the already-built program without compiling the source code themselves.

For example, a release can contain:

```text
client_static
client_dynamic
libmyutils.a
libmyutils.so
```

This makes the release easier to use and share.

---

# Feature 3: Static Library

### Question 4

**Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?**

**Answer:**

In Part 2, the Makefile mainly compiled the source files into object files and then linked those object files to create the executable.

In Part 3, the Makefile also includes rules for creating a static library.

For example, the object files can be combined into:

```text
libmyutils.a
```

The important addition is a library target and a rule that uses `ar` to create the library.

The static library is then linked with the client program.

So, Part 2 mainly builds the executable, while Part 3 builds both the static library and the executable that uses it.

---

### Question 5

**What is the purpose of the `ar` command? Why is `ranlib` often used immediately after it?**

**Answer:**

The `ar` command is used to create and modify archive files.

For a static library, it combines object files into one archive:

```text
libmyutils.a
```

For example:

```bash
ar rcs lib/libmyutils.a mystrlen.o mystrcpy.o
```

The `.a` file is a static library.

`ranlib` is often used after `ar` to create or update the index of symbols inside the library.

This index helps the linker find the required functions quickly.

On many systems, the `s` option in:

```bash
ar rcs
```

already creates this index, so a separate `ranlib` command may not be necessary.

---

### Question 6

**When you run `nm` on your `client_static` executable, are the symbols for functions like `mystrlen` present? What does this tell you about how static linking works?**

**Answer:**

Yes, functions such as `mystrlen` can appear in the symbols of the `client_static` executable.

This happens because the required code from the static library is copied into the executable during the linking process.

This shows that static linking puts the required library code directly into the final executable.

Because of this, the program does not need the original static library file when it runs.

---

# Feature 4: Dynamic Library

### Question 7

**What is Position-Independent Code (`-fPIC`) and why is it a fundamental requirement for creating shared libraries?**

**Answer:**

Position-Independent Code means code that can run correctly no matter where it is placed in memory.

The `-fPIC` option tells GCC to create position-independent code.

For example:

```bash
gcc -fPIC -c myutils.c
```

Shared libraries can be loaded at different memory addresses by different programs.

Therefore, the code in a shared library needs to work correctly regardless of its memory location.

That is why `-fPIC` is important when creating shared libraries.

---

### Question 8

**Explain the difference in file size between your static and dynamic clients. Why does this difference exist?**

**Answer:**

The static client is usually larger than the dynamic client.

With static linking, the required library code is copied into the executable.

With dynamic linking, the executable does not contain the complete library code. Instead, it refers to the shared library:

```text
libmyutils.so
```

The shared library is loaded when the program runs.

Therefore, the dynamic client is usually smaller, while the static client contains more code inside the executable.

---

### Question 9

**What is the `LD_LIBRARY_PATH` environment variable? Why was it necessary to set it for your program to run, and what does this tell you about the responsibilities of the operating system's dynamic loader?**

**Answer:**

`LD_LIBRARY_PATH` is an environment variable that tells the dynamic loader where to look for shared libraries.

In our project, the shared library was inside the project's `lib` directory:

```text
./lib/libmyutils.so
```

The system did not automatically search this directory, so we used:

```bash
export LD_LIBRARY_PATH=./lib
```

After setting it, the program could find the shared library and run successfully.

This shows that the dynamic loader is responsible for finding and loading the required shared libraries when a dynamically linked program starts.

If the library cannot be found in the normal library locations or specified search paths, the program cannot start correctly.
