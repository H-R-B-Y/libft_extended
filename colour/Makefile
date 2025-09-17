NAME			:= libftcolour.a

SRC				:= \
				./colour/colour_add.c \
				./colour/colour_average.c \
				./colour/colour_blend.c \
				./colour/colour_brightness.c \
				./colour/colour_clamp.c \
				./colour/colour_contrast.c \
				./colour/colour_create.c \
				./colour/colour_distance.c \
				./colour/colour_equal.c \
				./colour/colour_gamma_correction.c \
				./colour/colour_invert.c \
				./colour/colour_lerp.c \
				./colour/colour_multiply.c \
				./colour/colour_scale.c \
				./colour/colour_subtract.c \
				./colour/colour_to_colourf.c \
				./colour/colour_to_greyscale.c \
				\
				./colourf/colourf_add.c \
				./colourf/colourf_average.c \
				./colourf/colourf_blend.c \
				./colourf/colourf_brightness.c \
				./colourf/colourf_clamp.c \
				./colourf/colourf_contrast.c \
				./colourf/colourf_create.c \
				./colourf/colourf_distance.c \
				./colourf/colourf_equal.c \
				./colourf/colourf_gamma_correction.c \
				./colourf/colourf_invert.c \
				./colourf/colourf_lerp.c \
				./colourf/colourf_multiply.c \
				./colourf/colourf_scale.c \
				./colourf/colourf_subtract.c \
				./colourf/colourf_to_colour.c \
				./colourf/colourf_to_greyscale.c \
				\



OBJDIR			:= obj
OBJ				:= $(patsubst ./%,$(OBJDIR)/%,$(SRC:.c=.o))

# module dependencies
DEPS			:= mem math 

CC				:= gcc
AR				:= ar rcs
CFLAGS			:= -Wall -Wextra -Werror
INCLUDE			:= -I$(INCDIR)

all: $(LIBDIR)/$(NAME)

$(LIBDIR)/$(NAME): $(OBJ) | $(LIBDIR)
	for dep in $(DEPS); do \
		 $(MAKE) -C ../$$dep LIBDIR=$(LIBDIR) INCDIR=$(INCDIR); \
	done
	$(AR) $@ $(OBJ)

$(OBJDIR):
	mkdir -p $(OBJDIR)

# Pattern rule to build .o files from .c files in subdirectories
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBDIR):
	mkdir -p $(LIBDIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(LIBDIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re