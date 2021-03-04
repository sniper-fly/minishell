# minishell

This is a subject at 42Tokyo.  
We implemented a shell program like bash from scratch.  

## Member
rnakai  
yyabumot

## Feature
These features below are available.

 - one liner shell commands
 - execute commands with both absolute path and relative path (refering PATH environment variable)
 - stdin, stdout, stderr redirection (can use <, >, >> 2>)
 - pipelines (can use | )
 - single quote and double quote (except for not closed cases)
 - semicolon delimiter (execute commands sequentially)
 - expansion of environment variables in the command line sentences
 - display exit status with using special parameters ($?)
 - interrupt signal and quit signal (Ctrl-C, Ctrl-\\)
 - builtins
	- echo with option -n
	- cd with only a relative or absolute path, without any options
	- pwd without any options
	- export without any options
	- unset without any options
	- env without any options and any arguments
	- exit without any options

## Instllation
**Recommended environment**  
GNU Make 4.1  
gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0  

just entering "make" command on the root of this repo.

## Link
https://github.com/sniper-fly/minishell
