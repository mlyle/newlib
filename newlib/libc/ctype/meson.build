srcs_ctype = [
    'categories.c',
    'ctype_.c',
    'isalnum.c',
    'isalnum_l.c',
    'isalpha.c',
    'isalpha_l.c',
    'isascii.c',
    'isascii_l.c',
    'isblank.c',
    'isblank_l.c',
    'iscntrl.c',
    'iscntrl_l.c',
    'isdigit.c',
    'isdigit_l.c',
    'islower.c',
    'islower_l.c',
    'isprint.c',
    'isprint_l.c',
    'ispunct.c',
    'ispunct_l.c',
    'isspace.c',
    'isspace_l.c',
    'isupper.c',
    'isupper_l.c',
    'iswalnum.c',
    'iswalnum_l.c',
    'iswalpha.c',
    'iswalpha_l.c',
    'iswblank.c',
    'iswblank_l.c',
    'iswcntrl.c',
    'iswcntrl_l.c',
    'iswctype.c',
    'iswctype_l.c',
    'iswdigit.c',
    'iswdigit_l.c',
    'iswgraph.c',
    'iswgraph_l.c',
    'iswlower.c',
    'iswlower_l.c',
    'iswprint.c',
    'iswprint_l.c',
    'iswpunct.c',
    'iswpunct_l.c',
    'iswspace.c',
    'iswspace_l.c',
    'iswupper.c',
    'iswupper_l.c',
    'iswxdigit.c',
    'iswxdigit_l.c',
    'isxdigit.c',
    'isxdigit_l.c',
    'jp2uc.c',
    'toascii.c',
    'toascii_l.c',
    'tolower.c',
    'tolower_l.c',
    'toupper.c',
    'toupper_l.c',
    'towctrans.c',
    'towctrans_l.c',
    'towlower.c',
    'towlower_l.c',
    'towupper.c',
    'towupper_l.c',
    'wctrans.c',
    'wctrans_l.c',
    'wctype.c',
    'wctype_l.c',
]
hdrs_ctype = [
    'categories.h',
    'ctype_cp.h',
    'ctype_.h',
    'ctype_iso.h',
    'jp2uc.h',
    'local.h',
]
foreach target : targets
	value = get_variable('target_' + target)
	set_variable('lib_ctype' + target,
		static_library('ctype' + target,
			srcs_ctype,
			pic: false,
			include_directories: inc,
			c_args: value[1]))
endforeach
