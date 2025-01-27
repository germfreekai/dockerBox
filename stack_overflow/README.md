# stack overflow box

This Docker Image contains a couple of vulnerable C executables to stack overflow attacks.

## stack overflow
A stack overflow is a type of runtime error that occurs when a program attempts to use more memory than is available on the call stack. In C, the call stack is a region of memory that stores information about the active subroutines (functions) of a program, including the return address, function arguments, and local variables. When a function is called, a block of memory is allocated on the stack to store these details. If a function calls another function, which in turn calls another function, and so on, each function's block of memory is allocated on top of the previous one, forming a stack. If this process continues recursively without terminating, the stack can overflow, leading to a stack overflow error.

The risks of stack overflow in C programming include:
- **Program crashes**: A stack overflow can cause the program to crash or terminate abnormally.
- **Data corruption**: In some cases, a stack overflow can lead to data corruption or unexpected behavior.
- **Security vulnerabilities**: In rare cases, a stack overflow can be exploited by attackers to execute malicious code or gain unauthorized access to sensitive data.

## canaries
A canary is a technique used to detect stack overflows in a program. It is a small, sacrificial value placed on the stack that is checked periodically to ensure it has not been corrupted. The term "canary" comes from the idea of a canary in a coal mine, which serves as an early warning system for detecting toxic gases.

### How Do Canaries Mitigate Stack Overflow?
A canary works by placing a specific value on the stack, usually at the beginning of a function or at the entry point of a program. This value is then checked periodically, usually at the end of the function or at the exit point of the program. If the value has been corrupted or altered, it indicates that a stack overflow has occurred.

Here's how canaries mitigate stack overflow:
- Early Detection: Canaries allow for early detection of stack overflows, enabling the program to take corrective action before the overflow causes significant damage.
- Prevention of Data Corruption: By detecting stack overflows early, canaries help prevent data corruption and unexpected behavior.
- Improved Security: Canaries can help prevent stack-based buffer overflow attacks, which can be used to exploit vulnerabilities in a program.

### fstack protector
The fstack-protector flags are available in GCC (GNU Compiler Collection) and Clang compilers. The exact behavior of these flags may vary depending on the compiler version and architecture.

- -fstack-protector: Enables stack smashing protection on all functions. This flag inserts a canary value on the stack and checks it periodically to detect stack overflows.
- -fstack-protector-all: Enables stack smashing protection on all functions, including those with a small number of local variables. This flag is more aggressive than -fstack-protector and can increase the overhead of the program.
- -fstack-protector-strong: Enables strong stack smashing protection on all functions. This flag is similar to -fstack-protector-all, but uses a more sophisticated algorithm to detect stack overflows.
- -fno-stack-protector: Disables stack smashing protection on all functions. This flag is useful for optimizing performance-critical code or for working around issues with the stack protector.

### checksec
[checksec](https://github.com/slimm609/checksec) is a tool that allows us to verrify a variery of things, including if a file was compiled using canaries.
```bash
$ checksec --file=integrity_vuln
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      Symbols         FORTIFY Fortified       Fortifiable     FILE
Full RELRO      No canary found   NX enabled    PIE enabled     No RPATH   No RUNPATH   47 Symbols      No      0               2               integrity_vuln
$ checksec --file=integrity_vuln_protected
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      Symbols         FORTIFY Fortified       Fortifiable     FILE
Full RELRO      Canary found      NX enabled    PIE enabled     No RPATH   No RUNPATH   48 Symbols      No      0               2               integrity_vuln_protected
```

## Case
An attacker made himself feel like home at a vulnerable system. He spoofed jon's credentials and now is looking around the system trying to find a really valuable flag.

He found some interesting executables at jon's home dir. The attacker was able to determine which executables were more likely to be vulnerable to a stack overflow attack and was able to retrieve the flag.

Can you mimic what the attacker did?

