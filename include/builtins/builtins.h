#ifndef BUILTINS_H
#define BUILTINS_H

void my_echo(char **args);
void my_export(char **args);
void my_cd(char **args);
void my_unset(char **args);
void my_env(char **args); 
void my_pwd(char **args);
void my_exit(char **args);
void exec_builtins(char **args);


#endif