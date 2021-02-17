#ifndef MY_ENV_H
#define MY_ENV_H

void print_env_at_my_env(void);
void export_tmp_env_vars(char **args);
void unset_tmp_env_vars(char **args);
void exec_tasks_in_args(char **args);

#endif