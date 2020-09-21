# Monty :guardsman:

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
 push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$

```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$

```

# Usage

All the files are compiled in the following form:

```
 gcc -Wall -Werror -Wextra -pedantic *.c -o monty.

```

To Run the program:

```
 ./monty bytecode_file
```

OPCODES (Operation Codes):

| Opcode | Description |
|---------------- | -----------|
|push   | Pushes an element to the stack.|
|pall   | Prints all the values on the stack, starting from the to of the stack.|
|pint   | Prints the value at the top of the stack; followed by a new line.|
|pop    | Removes the top element of the stack.|
|swap   | Swaps the top to elements of the stack.|
|add    | Adds the top two elements of the stack. The result is then stored in the second node, and the first node is removed.|
|nop    | Does not do anything.|
|sub    | Subtracts the top two elements of the stack from the second top element. The result is then stored in the second top element of the stack, and the top element is removed.|
|div    | Divides the second top element of the stack by the top element. The result is stored in the second top element of the stack, and the top element is removed.|
|mul	| Multiplies the second top element of the stack with the top element. The result is stored in the second top element of the stack, and the top element is removed.|
|mod    | Computes the rest of the division of the second top element of the stack by the top element. The result is stored in the second top element of the stack, and the top element is removed|
|#      | When the first non-space of a line is a # the line will be trated as a comment (don't do anything).|
|pchar  | Prints as char at the top of the stack, followed by a new line.|
|pstr   | Prints the string starting at the top of the stack, followed by a new line. The string stops when either: i) the stack is over, ii) the value of the element is 0 or iii) the value of the element is not in the ascii table.|
|rotl   | Rotates the stack to the top. The top element of the stack becomes the last one, and the second top element of the stack becomes the first one.|
|rotr   | Rotates the stack to the bottom. The last element of the stack becomes the top element of the stack.|
|stack  | Sets the format of the data to a stack (LIFO). This is the default behavior of the program.|
|queue  | Sets the format of the data into a queue (FIFO).|

## Author
* **Gabriel Cifuentes** - [gcifuentess](https://github.com/gcifuentess/)

