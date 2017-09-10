# vi: ft=make 

MAKEFLAGS += --no-builtin-rules 
.SUFFIXES:

STD:=-std=c++1z
DKRI:=gcc #docker image
COMPILER=docker run -v ${PWD}:/usr/src/$(CURDIR) -w /usr/src/$(CURDIR) $(DKRI) g++ # lazy or second $ like $${PWD} ??

.PHONY: all clean
all:

makefiles_ := $(wildcard *.makef)

$(warning makefiles found: $(makefiles_))
$(warning bs.inc pwd: $(CURDIR))

files_to_clean_ := 
$(foreach mf_,$(makefiles_),\
	$(eval include $(mf_))\
	$(foreach exe_,$($(CURDIR).EXES),\
		$(eval obj_ := )\
		$(foreach src_,$($(exe_).SRC),\
		  $(eval base_name_ := $(basename $(src_)))\
			$(eval target_obj_ := $(exe_)_$(base_name_).o)\
	    $(eval $(target_obj_): $(src_) ; $(COMPILER) -c -o $$@ $$<)\
			$(eval all: $(target_obj_))\
			$(eval obj_ += $(target_obj_))\
		)\
	  $(eval $(exe_): $(obj_) ; $(COMPILER) -o $$@ $$^)\
		$(eval all: $(exe_))\
		$(eval files_to_clean_ += $(obj_) $(exe_))\
	)\
)

clean:
	rm -f $(files_to_clean_)

