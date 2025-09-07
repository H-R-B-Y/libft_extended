/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defined.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:16:56 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/07 14:52:09 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINED_H
# define DEFINED_H

#include <stdint.h>

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

#ifndef MYFLOAT
# define MYFLOAT float
#endif

typedef uint8_t				t_u8;
typedef uint16_t			t_u16;
typedef uint32_t			t_u32;
typedef uint64_t			t_u64;

typedef int8_t				t_s8;
typedef int16_t				t_s16;
typedef int32_t				t_s32;
typedef int64_t				t_s64;

typedef volatile t_u8		t_vu8;
typedef volatile t_u16		t_vu16;
typedef volatile t_u32		t_vu32;
typedef volatile t_u64		t_vu64;

typedef volatile t_s8		t_vs8;
typedef volatile t_s16		t_vs16;
typedef volatile t_s32		t_vs32;
typedef volatile t_s64		t_vs64;

typedef enum e_returncode	t_returncode;
enum e_returncode
{
	RETURN_OK,
	RETURN_ERROR,
	RETURN_FATAL,
	RETURN_CODE_COUNT
};


#endif