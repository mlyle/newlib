/* wf_pow.c -- float version of w_pow.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 */

/* 
 * wrapper powf(x,y) return x**y
 */

#include "fdlibm.h"
#if __OBSOLETE_MATH
#include <errno.h>

#if !defined(_IEEE_LIBM) || !defined(HAVE_ALIAS_ATTRIBUTE)
#ifdef __STDC__
	float powf(float x, float y)	/* wrapper powf */
#else
	float powf(x,y)			/* wrapper powf */
	float x,y;
#endif
{
	float z;
	struct exception exc;
	z=__ieee754_powf(x,y);
	if(_LIB_VERSION == _IEEE_|| isnan(y)) return z;
	if(isnan(x)) {
	    if(y==(float)0.0) { 
		/* powf(NaN,0.0) */
		/* error only if _LIB_VERSION == _SVID_ & _XOPEN_ */
		exc.type = DOMAIN;
		exc.name = "powf";
		exc.err = 0;
		exc.arg1 = (double)x;
		exc.arg2 = (double)y;
		exc.retval = 1.0;
		if (_LIB_VERSION == _IEEE_ ||
		    _LIB_VERSION == _POSIX_) exc.retval = 1.0;
		else if (!matherr(&exc)) {
			errno = EDOM;
		}
	        if (exc.err != 0)
	           errno = exc.err;
                return (float)exc.retval; 
	    } else 
		return z;
	}
	if(x==(float)0.0){ 
	    if(y==(float)0.0) {
		/* powf(0.0,0.0) */
		/* error only if _LIB_VERSION == _SVID_ */
		exc.type = DOMAIN;
		exc.name = "powf";
		exc.err = 0;
		exc.arg1 = (double)x;
		exc.arg2 = (double)y;
		exc.retval = 0.0;
		if (_LIB_VERSION != _SVID_) exc.retval = 1.0;
		else if (!matherr(&exc)) {
			errno = EDOM;
		}
	        if (exc.err != 0)
	           errno = exc.err;
                return (float)exc.retval; 
	    }
	    if(finitef(y)&&y<(float)0.0) {
		/* 0**neg */
		exc.type = DOMAIN;
		exc.name = "powf";
		exc.err = 0;
		exc.arg1 = (double)x;
		exc.arg2 = (double)y;
		if (_LIB_VERSION == _SVID_) 
		  exc.retval = 0.0;
		else
		  exc.retval = -HUGE_VAL;
		if (_LIB_VERSION == _POSIX_)
		  errno = EDOM;
		else if (!matherr(&exc)) {
		  errno = EDOM;
		}
	        if (exc.err != 0)
	           errno = exc.err;
                return (float)exc.retval; 
            }
	    return z;
	}
	if(!finitef(z)) {
	    if(finitef(x)&&finitef(y)) {
	        if(isnan(z)) {
		    /* neg**non-integral */
		    exc.type = DOMAIN;
		    exc.name = "powf";
		    exc.err = 0;
		    exc.arg1 = (double)x;
		    exc.arg2 = (double)y;
		    if (_LIB_VERSION == _SVID_) 
		        exc.retval = 0.0;
		    else 
		        /* Use a float divide, to avoid a soft-float double
			   divide call on single-float only targets.  */
		        exc.retval = (0.0f/0.0f);	/* X/Open allow NaN */
		    if (_LIB_VERSION == _POSIX_) 
		        errno = EDOM;
		    else if (!matherr(&exc)) {
		        errno = EDOM;
		    }
	            if (exc.err != 0)
	                errno = exc.err;
                    return (float)exc.retval; 
	        } else {
		    /* powf(x,y) overflow */
		    exc.type = OVERFLOW;
		    exc.name = "powf";
		    exc.err = 0;
		    exc.arg1 = (double)x;
		    exc.arg2 = (double)y;
		    if (_LIB_VERSION == _SVID_) {
		       exc.retval = HUGE;
		       y *= 0.5;
		       if(x<0.0f&&rintf(y)!=y) exc.retval = -HUGE;
		    } else {
		       exc.retval = HUGE_VAL;
                       y *= 0.5;
		       if(x<0.0f&&rintf(y)!=y) exc.retval = -HUGE_VAL;
		    }
		    if (_LIB_VERSION == _POSIX_)
		        errno = ERANGE;
		    else if (!matherr(&exc)) {
			errno = ERANGE;
		    }
	            if (exc.err != 0)
	                errno = exc.err;
                    return (float)exc.retval; 
                }
	    }
	} 
	if(z==(float)0.0&&finitef(x)&&finitef(y)) {
	    /* powf(x,y) underflow */
	    exc.type = UNDERFLOW;
	    exc.name = "powf";
	    exc.err = 0;
	    exc.arg1 = (double)x;
	    exc.arg2 = (double)y;
	    exc.retval =  0.0;
	    if (_LIB_VERSION == _POSIX_)
	        errno = ERANGE;
	    else if (!matherr(&exc)) {
	     	errno = ERANGE;
	    }
	    if (exc.err != 0)
	        errno = exc.err;
            return (float)exc.retval; 
        }
	return z;
}
#endif

#ifdef _DOUBLE_IS_32BITS

#ifdef __STDC__
	double pow(double x, double y)
#else
	double pow(x,y)
	double x,y;
#endif
{
	return (double) powf((float) x, (float) y);
}

#endif /* defined(_DOUBLE_IS_32BITS) */
#endif /* __OBSOLETE_MATH */
