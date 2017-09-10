# vi: ft=make
MAKEFLAGS += --no-builtin-rules 
.SUFFIXES:

makefiles_ := $(wildcard *.makef)

$(foreach mf_,$(makefiles_),\
	$(eval include $(mf_))\
	$(foreach exe_,$($(CURDIR).EXES),\
	  $(eval $(exe_).INC := $(INCLUDES))\
	)\
)
