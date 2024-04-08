# Self-Compiled-Language (SCL)

SCL is a simple educational language for understanding more about compilers and interpreters. The objective in a first time is to create a simple interpreter for this language, then a compiler to finally rewrite the whole interpreter and compiler in SCL itself.

## Language Specification

SCL is a simple language with a C-like syntax. It is a statically typed language with a simple type system. It will be a stack-based language with a simple stack machine.

### Types

- `byte`: 8-bit unsigned integer
- `char`: 8-bit character
- `int`: 32-bit signed integer
- `float`: 32-bit floating point number
- `bool`: boolean value
- `string`: string of characters
- `void`: no value
- `function`: function
- `array`: array of values

| Type      | Size (bytes) | Range                           |
|-----------|--------------|---------------------------------|
| `byte`    | 1            | 0 to 255                        |
| `char`    | 1            | 0 to 255                        |
| `int`     | 4            | -2,147,483,648 to 2,147,483,647 |
| `float`   | 4            | 1.2E-38 to 3.4E+38              |
| `bool`    | 1            | `true` or `false`               |
| `string`  | n            | n characters                    |
| `void`    | 0            | no value                        |
| `function`| 0            | no value                        |
| `array`   | n            | n values                        |

### Keywords

- `if`
- `else`
- `while`
- `for`
- `return`
- `break`
- `continue`
- `fun`
- `var`
- `const`
- `true`
- `false`
- `null`
- `and`
- `or`

### Variables

There are two types of variables in SCL: `var` and `const`. `var` is a mutable variable, while `const` is an immutable variable.

```scl
var x: int = 10;
const y: int = 20;
```

### Functions

Functions are defined using the `fun` keyword. Functions can have multiple parameters and a return type.

```scl
fun add(a: int, b: int): int {
    return a + b;
}
```

### Control Structures

SCL has the following control structures:

- `if`
- `else`
- `while`
- `for`

```scl
if (x > 10) {
    print("x is greater than 10");
} else {
    print("x is less than or equal to 10");
}

while (x < 10) {
    print(x);
    x = x + 1;
}

for (var i: int = 0; i < 10; i = i + 1) {
    print(i);
}
```

### Operators

SCL has the following operators:

- `+`, `-`, `*`, `/`, `%`
- `==`, `!=`, `<`, `>`, `<=`, `>=`
- `&&`, `||`, `!`
- `=`
- `+=`, `-=`, `*=`, `/=`, `%=`
- `++`, `--`
- `[]`
- `()`
- `.`
- `:`
- `?`
- `@`
- `#`
- `~`
- `^`
- `&`
- `|`
- `<<`, `>>`

### Comments

Comments in SCL are similar to C-style comments.

```scl
// This is a single line comment

/*
This is a
multi-line
comment
*/
```
