
int		main(int argc, char **argv, char **envp)
{
	setup_signal();
	while (1)
	{
		read_line();
		parse_line();
		create_empty_file(); // open とclose
		exec_cmd();

		free_line();
		free_list();
	}
}
