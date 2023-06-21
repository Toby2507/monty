# Monty Language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (similar to Python). It relies on a unique stack with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty Byte Code Files

Files containing Monty byte codes usually have the .m extension. While most of the industry follows this standard, it is not required by the language specification. Here are some important points about Monty byte code files:

- Each line contains only one instruction.
- There can be any number of spaces before or after the opcode and its argument.
- Monty byte code files can contain blank lines (empty or made of spaces only), and any additional text after the opcode or its required argument is ignored.

The Monty program runs the bytecodes line by line and stops under the following conditions:

- It executed every line of the file successfully.
- It encounters an error in the file.
- An error occurs during execution.

## Opcodes

- **push**: The opcode push pushes an element to the stack.

  - Usage: push <int>
  - <int> represents an integer.
  - If <int> is not an integer or if there is no argument given to push, an error is raised and the program exitted.

- **pall**: The pall opcode prints all the values on the stack, starting from the top of the stack.

  - Usage: pall
  - If the stack is empty, pall does not print anything.

- **pint**: The pint opcode prints the value at the top of the stack, followed by a new line.

  - Usage: pint
  - If the stack is empty, pint prints an error message and the program exitted.

- **pop**: The pop opcode removes the top element of the stack.

  - Usage: pop
  - If the stack is empty, pop prints an error message and the program exitted.

- **swap**: The swap opcode swaps the top two elements of the stack.

  - Usage: swap
  - If the stack contains less than two elements, swap prints an error message and the program exitted.

- **add**: The add opcode adds the top two elements of the stack.

  - Usage: add
  - If the stack contains less than two elements, add prints an error message and the program exitted.
  - The result is stored in the second top element of the stack, and the top element is removed.

- **nop**: The nop opcode doesn’t do anything.

  - Usage: nop

- **sub**: The sub opcode subtracts the top element of the stack from the second top element of the stack.

  - Usage: sub
  - If the stack contains less than two elements, sub prints an error message and the program exitted.
  - The result is stored in the second top element of the stack, and the top element is removed.

- **div**: The div opcode divides the second top element of the stack by the top element of the stack.

  - Usage: div
  - If the stack contains less than two elements, div prints an error message and the program exitted.
  - The result is stored in the second top element of the stack, and the top element is removed.
  - If the top element of the stack is 0, div prints an error message and the program exitted.

- **mul**: The mul opcode multiplies the second top element of the stack with the top element of the stack.

  - Usage: mul
  - If the stack contains less than two elements, mul prints an error message and the program exitted.
  - The result is stored in the second top element of the stack, and the top element is removed.

- **mod**: The mod opcode computes the rest of the division of the second top element of the stack by the top element of the stack.

  - Usage: mod
  - If the stack contains less than two elements, mod prints an error message and the program exitted.
  - The result is stored in the second top element of the stack, and the top element is removed.
  - If the top element of the stack is 0, mod prints an error message and the program exitted.

- **pchar**: The pchar opcode prints the char at the top of the stack, followed by a new line.

  - Usage: pchar
  - The integer stored at the top of the stack is treated as the ascii value of the character to be printed.
  - If the stack is empty, pchar prints an error message and the program exitted.
  - If the value at the top of the stack is not in the ASCII table, pchar prints an error message and the program exitted.

- **pstr**: The pstr opcode prints the string starting at the top of the stack, followed by a new line.

  - Usage: pstr
  - The integer stored in each element of the stack is treated as the ascii value of the character to be printed.
  - The string stops when either:
  - the stack is over
  - the value of the element is 0
  - the value of the element is not in the ASCII table
  - If the stack is empty, pstr prints only a new line.

- **rotl**: The rotl opcode rotates the stack to the top.

  - Usage: rotl
  - The top element of the stack becomes the last one, and the second top element of the stack becomes the first one.

- **rotr**: The rotr opcode rotates the stack to the bottom.

  - Usage: rotr
  - The last element of the stack becomes the top element of the stack.

- **stack**: The stack opcode sets the format of the data to a stack (LIFO). This is the default behavior of the program.

  - Usage: stack

- **queue**: The queue opcode sets the format of the data to a queue (FIFO).

  - Usage: queue

- **Comments**: Every good language comes with the capability of commenting. In Monty, when the first non-space character of a line is #, treat this line as a comment (don't execute any action).

## Contributors

- Toby Salau
