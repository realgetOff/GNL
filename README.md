<p align="center">
  <img src="https://github.com/realgetOff/main/blob/main/Header/gnl.png">
</p>

<p align="center">
	<img src="https://img.shields.io/badge/status-finished-chocolate"/>
	<img src="https://img.shields.io/badge/evaluated-14%20%2F%2012%20%2F%202024-chocolate"/>
	<img src="https://img.shields.io/badge/score-105%2F100-chocolate"/>
	<img src="https://img.shields.io/badge/language-C_100%25-chocolate"/>
	<img src="https://img.shields.io/badge/last_commit-december-chocolate"/>
	<a href='https://profile.intra.42.fr/users/mforest-' target="_blank"><img alt='42' src='https://img.shields.io/badge/Intra-100000?style=flat-round&logo=42&logoColor=white&labelColor=000000&color=000000'/></a>
</p>

<p align="center">
	<a href="#about">About</a> •
	<a href="#how-to-use">How to use</a> •
	<a href="#mandatory">Mandatory</a> •
	<a href="#bonus">Bonus</a> •
	<a href="#norminette">Norminette</a> •
	<a href="#contributing">Contributing</a>
</p>

## ABOUT
This project taught me how to read from a file descriptor and use static variables. This function retrieves a single line from a specified file descriptor. When called in a loop, get_next_line returns all the contents of the file, one line at a time until the end of the file is reached. Additionally, this function can be compiled with any buffer size specified.

- [Subject](https://github.com/realgetOff/GNL/blob/main/fr_subject.pdf) `PDF`
- [References](https://github.com/realgetOff/GNL) `GitHub`

## HOW TO USE
#### 1º - Clone the repository
```git
git clone https://github.com/realgetOff/GNL.git
```

#### 2º - Enter the project folder
```bash
cd get_next_line/get_next_line
```

#### 3º - Compile the mandatory or bonus files
> The program should always be compiled with the flags below.
```bash
[Flags] -Wall -Wextra -Werror
[Mandatory] cc [Flags] main.c get_next_line.c get_next_line_utils.c
```

#### 4º - BUFFER_SIZE can be specified at compilation to override the default BUFFER_SIZE
> get_next_line should be able to compile with and without the -D BUFFER_SIZE=[SIZE] flag.
```bash
[Flags] -Wall -Wextra -Werror -D BUFFER_SIZE=[SIZE] 
[Mandatory] cc [Flags] main.c get_next_line.c get_next_line_utils.c
```

#### 5º - Execution with one or multiple file descriptors/standard input
```bash
./a.out [text.txt]
./a.out [text1.txt] [text2.txt]
```

## MANDATORY
- [x] Read from one file descriptor, one line at a time.
- [x] Needs to return the line that was read. If empty or error, return `NULL`.
- [x] Should work as expected reading from a file or standard input.
- [x] Returned line should include the terminating `\n` character, except if it's the end of the file and the line does not end with `\n`.
- [x] The `get_next_line.h` header file should include at least the `get_next_line()` function.
- [x] All adicional functions should be included in `get_next_line_utils.c` file, libft is not allowed.
- [x] To define the buffer size for `read()`, add the option to the compiled file `-D BUFFER_SIZE=[SIZE]`.

## BONUS
- [x] Use only one static variable.
- [ ] Manage multiple file descriptors at the same time.
- [ ] Bonus files should include a suffix `_bonus.[c/h]`.

## NORMINETTE
> At 42 School, it is expected that almost every project is written following the Norm, which is the coding standard of the school.

```
- No for, do...while, switch, case, goto, ternary operators, or variable-length arrays allowed;
- Each function must be a maximum of 25 lines, not counting the function's curly brackets;
- Each line must be at most 80 columns wide, with comments included;
- A function can take 4 named parameters maximum;
- No assigns and declarations in the same line (unless static);
- You can't declare more than 5 variables per function;
- ...
```

* [42 Norms](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf) - Information about 42 code norms. `PDF`
* [Norminette](https://github.com/42School/norminette) - Tool to respect the code norm, made by 42. `GitHub`
* [42 Header](https://github.com/42Paris/42header) - 42 header for Vim. `GitHub`

## CONTRIBUTING

If you find any issues or have suggestions for improvements, feel free to fork the repository and open an issue or submit a pull request.
All credits goes to @jotavare (for the README.md).
