# ft_printf 🖨️

[![42 School](https://img.shields.io/badge/42-School-blue)](https://42firenze.it/)
[![GitHub license](https://img.shields.io/github/license/Nazar963/42_ft_printf)](https://github.com/Nazar963/42_ft_printf/blob/master/LICENSE)
[![Build Status](https://img.shields.io/github/actions/workflow/status/Nazar963/42_ft_printf/build.yml?branch=master)](https://github.com/Nazar963/42_ft_printf/.github/workflows/build.yml)
[![Bonus](https://img.shields.io/badge/Bonus-Complete-brightgreen)](https://github.com/Nazar963/42_ft_printf)

A custom implementation of printf with extended functionality, featuring comprehensive formatting options and bonus features.

## Table of Contents 📖
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Makefile Targets](#makefile-targets)
- [Testing](#testing)
- [Acknowledgments](#acknowledgments)
- [License](#license)

## Description 
This 42 School project recreates the standard `printf` function with enhanced capabilities. The implementation:
- Handles various conversion specifiers
- Supports flags, Left justification and zero padding
- Includes bonus features for extended functionality
- Passes rigorous testing with multiple edge cases

**Bonus Features Implemented**:
- All mandatory features plus full support for `' '` (space), `'+'`, `'#'` flags
- Left justification and zero padding handling

## Features 

### Core Conversion Specifiers 🔧
| Specifier | Description                |
|-----------|----------------------------|
| `%c`      | Characters                 |
| `%s`      | Strings                    |
| `%p`      | Pointer addresses          |
| `%d`, `%i`| Signed integers            |
| `%u`      | Unsigned integers          |
| `%x`, `%X`| Hexadecimal numbers        |
| `%%`      | Percent sign               |

### Supported Flags 🚩
- `-` : Left justification
- `0` : Zero padding
- `#` : Alternative form
- ` ` : Space prefix
- `+` : Always show sign

## Installation

### Requirements
- GCC (GNU Compiler Collection)
- GNU Make

### Compilation
1. Clone the repository:
   ```bash
   git clone https://github.com/Nazar963/42_ft_printf.git
   cd 42_ft_printf
   ```
2. Build the library:
   ```bash
   make
   ```
3. The static library `42_ft_printf/libftprintf.a` will be created

## Usage 

Include the header in your source files:
```c
#include "42_ft_printf/libft/libft.h"
#include "42_ft_printf/include/ft_printf.h"
```

Compile your project with:
```bash
gcc -Wall -Wextra -Werror your_file.c -L42_ft_printf -lftprintf -I includes -o output
```

### Example
```c
#include "42_ft_printf/libft/libft.h"
#include "42_ft_printf/include/ft_printf.h"

int main(void)
{
    int count = ft_printf("%-20d\n", 12345);
    ft_printf("Printed %d characters\n", count);
    return 0;
}
```

## Makefile Targets
- `make` : Compile library with bonuses
- `make clean` : Remove object files
- `make fclean` : Remove objects and library
- `make re` : Rebuild library
- `make bonus` : Verify bonus implementation

## Testing
Validated with:
- [Tripouille/printfTester](https://github.com/Tripouille/printfTester)
- [paulo-santana/ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester)

## Acknowledgments
- 42 School curriculum for project concept
- printf(3) man page documentation
- Peer code reviews and debugging sessions
- Open source community testers

## License
Distributed under the MIT License - see [LICENSE](LICENSE) for details.

---

🚀 Show your support by starring this repository!  
[![GitHub stars](https://img.shields.io/github/stars/Nazar963/42_ft_printf?style=social)](https://github.com/Nazar963/42_ft_printf/stargazers)

[![42 School](https://img.shields.io/badge/42-profile-blue)](https://profile-v3.intra.42.fr/users/naal-jen)
[![GitHub Profile](https://img.shields.io/badge/GitHub-Nazar963-lightgrey)](https://github.com/Nazar963)
