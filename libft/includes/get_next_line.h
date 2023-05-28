
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

extern  int BUFFER_SIZE;
void	*ft_free_strs_line(char **str, char **str2);
char	*get_next_line(int fd);
char	*read_file(int fd, char *buffer, int bytes_read);
char	*join_buff(char *buffer, char *reader);
char	*buffer_prep(char *buffer);
char	*parse_line(char *buffer);

#endif
