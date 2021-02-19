#ifndef EXIT_STATUS_C
#define EXIT_STATUS_C

#define SUCCEEDED 0
#define GENERAL_ERROROS 1
#define MISUSE_OF_SHELL_BUILTINS 2	// Missing keyword or command, or permission problem
#define COMMAND_CANNOT_EXECUTE 126	// Permission problem or command is not executable
#define COMMAND_NOT_FOUND 127	// Possible problem with $PATH or a typo
// #define INVALID_ARG_TO_EXIT 128	// exitに不正な値(浮動小数点など)を渡した
#define CTRL_C 130
#define CTRL_BKSLSH 131

#endif