
#ifndef FT_ENUM_MACRO_H
# define FT_ENUM_MACRO_H

# define ENUM_FACTORY(prefix, typename, list)\
	typedef enum e_##typename { \
		list(prefix, ENUM_FACTORY_ENUM) \
		prefix##_COUNT \
	} t_##typename; \
	const char *prefix##_str[prefix##_COUNT] = { \
		list(prefix, ENUM_FACTORY_STR) \
	};

# define ENUM_FACTORY_ENUM(prefix, name) prefix##_##name,
# define ENUM_FACTORY_STR(prefix, name) #name,

#endif
