
#ifndef FT_ENUM_MACRO_H
# define FT_ENUM_MACRO_H

# define ENUM_FACTORY(prefix, typename, list)\
	typedef enum e_##typename { \
		list(ENUM_FACTORY_ENUM, prefix) \
		prefix##_COUNT \
	} t_##typename; \
	const char *prefix##_str[prefix##_COUNT] = { \
		list(ENUM_FACTORY_STR, prefix) \
	};

# define ENUM_FACTORY_ENUM(prefix, name) prefix##_##name,
# define ENUM_FACTORY_STR(prefix, name) #name,

# define FT_COLOR_LIST(X, prefix) \
	X(prefix, RED) \
	X(prefix, GREEN) \
	X(prefix, BLUE) \
	X(prefix, YELLOW) \
	X(prefix, ORANGE) \
	X(prefix, PURPLE) \
	X(prefix, CYAN) \
	X(prefix, MAGENTA) \
	X(prefix, BLACK) \
	X(prefix, WHITE) \
	X(prefix, GREY)

ENUM_FACTORY(FT, color, \
	FT_COLOR_LIST \
)

#endif
