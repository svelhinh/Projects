/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 18:01:22 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 15:18:29 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include "libft.h"

# if defined(__powerpc__) || defined(__ppc__) || defined(__PPC__)
#  define CPU CPU_TYPE_POWERPC
# elif defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__)
#  define CPU CPU_TYPE_POWERPC64
# elif defined(__sparc)
#  define CPU CPU_TYPE_SPARC
# elif defined(__i386) || defined(_M_IX86)
#  define CPU CPU_TYPE_X86
# elif defined(__x86_64__) || defined(_M_X64)
#  define CPU CPU_TYPE_X86_64
# endif

typedef struct load_command			t_load_com;
typedef struct symtab_command		t_symtab_com;
typedef struct stat					t_stat;

typedef struct segment_command_64	t_seg_com_64;
typedef struct section_64			t_sec_64;
typedef struct nlist_64				t_nlist_64;
typedef struct mach_header_64		t_mach_header_64;

typedef struct segment_command		t_seg_com;
typedef struct section				t_sec;
typedef struct nlist				t_nlist;
typedef struct mach_header			t_mach_header;

typedef struct fat_arch				t_fat_arch;
typedef struct fat_header			t_fat_header;

typedef struct						s_sym
{
	char			*name;
	char			*addr;
	char			type;
	uint8_t			type_flag;
	uint8_t			sect_nb;
	struct s_sym	*next;
}									t_sym;

int									reverse_int(int value);
void								print_arch(int cpu_type, int nfat_arch,
	char *filename);
int									arch_match(int nfat_arch,
	t_fat_arch *f_arch);
char								available_section(char *section_name);
int									value_len(uint32_t value, uint32_t base);
char								*ft_value_to_hex(uint32_t value);
int									value_len_64(uint64_t value, uint64_t base);
char								*ft_value_to_hex_64(uint64_t value);

#endif
