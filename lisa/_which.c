#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int ac, char **av, char **env)
{
	int i = 0;

	while(*env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
