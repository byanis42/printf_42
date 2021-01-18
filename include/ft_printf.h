#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "-0.*"
# define CONV_FORMAT "cspdiuxX%"
# define HEXA "0123456789abcdef"
# define LEFT 1
# define RIGHT 0

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h> // Temp a supprimer

typedef	struct	s_struct
{
	int		width;
	int		convert;
	int		justif;
	int		precision;
	char	fill;

}				t_struct;

int				ft_printf(const char *str, ...);

int				ft_print_str(const char *str, int i);
int				print_till_next_arg(char *str);
int				ft_get_index(const char *str);
t_struct		*ft_parse(const char *str, va_list args);
int				ft_define_type(char c);

int			ft_str_pf(va_list args, t_struct *settings);
int			ft_char_pf(va_list args, t_struct *settings);
int			ft_decimal_pf(va_list args, t_struct *settings);
int			ft_integer_pf(va_list args, t_struct *settings);
int			ft_address_pf(va_list args, t_struct *settings);
int			ft_unsigned_pf(va_list args, t_struct *settings);
int			ft_hexadecimal_pf(va_list args, t_struct *settings);
int			ft_hexadecimal_upper_pf(va_list args, t_struct *settings);
int			ft_percent_pf(va_list args, t_struct *settings);

char		*ft_width_right(t_struct *settings, char *str);
char		*ft_width_left(t_struct *settings, char *str);
char		*ft_width_nb(t_struct *settings, char *str);
char		*ft_precision(char *str, t_struct *settings);
char		*ft_precision_nb(char *str, t_struct *settings);


int		ft_ret(int ret, int nb_arg, ...);


#endif