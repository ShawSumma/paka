ret = {};
ret.types = {};
ret.types.signgam = ffi.type.int;
ret.types.scalbl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.fmal = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real, ffi.type.real]);
ret.types.fminl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.fmaxl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.fdiml = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.llroundl = ffi.type.function(ffi.type.long, [ffi.type.real]);
ret.types.lroundl = ffi.type.function(ffi.type.long, [ffi.type.real]);
ret.types.llrintl = ffi.type.function(ffi.type.long, [ffi.type.real]);
ret.types.lrintl = ffi.type.function(ffi.type.long, [ffi.type.real]);
ret.types.remquol = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real, ffi.type.pointer(ffi.type.int)]);
ret.types.truncl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.roundl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.nearbyintl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.scalblnl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.long]);
ret.types.ilogbl = ffi.type.function(ffi.type.int, [ffi.type.real]);
ret.types.scalbnl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.int]);
ret.types.remainderl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.nexttowardl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.nextafterl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.rintl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.lgammal_r = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.pointer(ffi.type.int)]);
ret.types.gammal = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.tgammal = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.lgammal = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.erfcl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.erfl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.ynl = ffi.type.function(ffi.type.real, [ffi.type.int, ffi.type.real]);
ret.types.y1l = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.y0l = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.jnl = ffi.type.function(ffi.type.real, [ffi.type.int, ffi.type.real]);
ret.types.j1l = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.j0l = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.isnanl = ffi.type.function(ffi.type.int, [ffi.type.real]);
ret.types.nanl = ffi.type.function(ffi.type.real, [ffi.type.pointer(ffi.type.byte)]);
ret.types.copysignl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.significandl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.dreml = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.finitel = ffi.type.function(ffi.type.int, [ffi.type.real]);
ret.types.isinfl = ffi.type.function(ffi.type.int, [ffi.type.real]);
ret.types.fmodl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.floorl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.fabsl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.ceill = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.cbrtl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.hypotl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.sqrtl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.powl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.log2l = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.exp2l = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.logbl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.log1pl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.expm1l = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.modfl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.pointer(ffi.type.real)]);
ret.types.log10l = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.logl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.ldexpl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.int]);
ret.types.frexpl = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.pointer(ffi.type.int)]);
ret.types.expl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.atanhl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.asinhl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.acoshl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.tanhl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.sinhl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.coshl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.tanl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.sinl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.cosl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.atan2l = ffi.type.function(ffi.type.real, [ffi.type.real, ffi.type.real]);
ret.types.atanl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.asinl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.acosl = ffi.type.function(ffi.type.real, [ffi.type.real]);
ret.types.scalbf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float]);
ret.types.fmaf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float, ffi.type.float]);
ret.types.fminf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float]);
ret.types.fmaxf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float]);
ret.types.fdimf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float]);
ret.types.llroundf = ffi.type.function(ffi.type.long, [ffi.type.float]);
ret.types.lroundf = ffi.type.function(ffi.type.long, [ffi.type.float]);
ret.types.llrintf = ffi.type.function(ffi.type.long, [ffi.type.float]);
ret.types.lrintf = ffi.type.function(ffi.type.long, [ffi.type.float]);
ret.types.remquof = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float, ffi.type.pointer(ffi.type.int)]);
ret.types.truncf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.roundf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.nearbyintf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.scalblnf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.long]);
ret.types.ilogbf = ffi.type.function(ffi.type.int, [ffi.type.float]);
ret.types.scalbnf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.int]);
ret.types.remainderf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float]);
ret.types.nexttowardf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.real]);
ret.types.nextafterf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float]);
ret.types.rintf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.lgammaf_r = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.pointer(ffi.type.int)]);
ret.types.gammaf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.tgammaf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.lgammaf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.erfcf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.erff = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.ynf = ffi.type.function(ffi.type.float, [ffi.type.int, ffi.type.float]);
ret.types.y1f = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.y0f = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.jnf = ffi.type.function(ffi.type.float, [ffi.type.int, ffi.type.float]);
ret.types.j1f = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.j0f = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.isnanf = ffi.type.function(ffi.type.int, [ffi.type.float]);
ret.types.nanf = ffi.type.function(ffi.type.float, [ffi.type.pointer(ffi.type.byte)]);
ret.types.copysignf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float]);
ret.types.significandf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.dremf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float]);
ret.types.finitef = ffi.type.function(ffi.type.int, [ffi.type.float]);
ret.types.isinff = ffi.type.function(ffi.type.int, [ffi.type.float]);
ret.types.fmodf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float]);
ret.types.floorf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.fabsf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.ceilf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.cbrtf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.hypotf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float]);
ret.types.sqrtf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.powf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float]);
ret.types.log2f = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.exp2f = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.logbf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.log1pf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.expm1f = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.modff = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.pointer(ffi.type.float)]);
ret.types.log10f = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.logf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.ldexpf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.int]);
ret.types.frexpf = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.pointer(ffi.type.int)]);
ret.types.expf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.atanhf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.asinhf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.acoshf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.tanhf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.sinhf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.coshf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.tanf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.sinf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.cosf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.atan2f = ffi.type.function(ffi.type.float, [ffi.type.float, ffi.type.float]);
ret.types.atanf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.asinf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.acosf = ffi.type.function(ffi.type.float, [ffi.type.float]);
ret.types.scalb = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double]);
ret.types.fma = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double, ffi.type.double]);
ret.types.fmin = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double]);
ret.types.fmax = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double]);
ret.types.fdim = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double]);
ret.types.llround = ffi.type.function(ffi.type.long, [ffi.type.double]);
ret.types.lround = ffi.type.function(ffi.type.long, [ffi.type.double]);
ret.types.llrint = ffi.type.function(ffi.type.long, [ffi.type.double]);
ret.types.lrint = ffi.type.function(ffi.type.long, [ffi.type.double]);
ret.types.remquo = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double, ffi.type.pointer(ffi.type.int)]);
ret.types.trunc = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.round = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.nearbyint = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.scalbln = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.long]);
ret.types.ilogb = ffi.type.function(ffi.type.int, [ffi.type.double]);
ret.types.scalbn = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.int]);
ret.types.remainder = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double]);
ret.types.nexttoward = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.real]);
ret.types.nextafter = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double]);
ret.types.rint = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.lgamma_r = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.pointer(ffi.type.int)]);
ret.types.gamma = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.tgamma = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.lgamma = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.erfc = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.erf = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.yn = ffi.type.function(ffi.type.double, [ffi.type.int, ffi.type.double]);
ret.types.y1 = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.y0 = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.jn = ffi.type.function(ffi.type.double, [ffi.type.int, ffi.type.double]);
ret.types.j1 = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.j0 = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.isnan = ffi.type.function(ffi.type.int, [ffi.type.double]);
ret.types.nan = ffi.type.function(ffi.type.double, [ffi.type.pointer(ffi.type.byte)]);
ret.types.copysign = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double]);
ret.types.significand = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.drem = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double]);
ret.types.finite = ffi.type.function(ffi.type.int, [ffi.type.double]);
ret.types.isinf = ffi.type.function(ffi.type.int, [ffi.type.double]);
ret.types.fmod = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double]);
ret.types.floor = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.fabs = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.ceil = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.cbrt = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.hypot = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double]);
ret.types.sqrt = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.pow = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double]);
ret.types.log2 = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.exp2 = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.logb = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.log1p = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.expm1 = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.modf = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.pointer(ffi.type.double)]);
ret.types.log10 = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.log = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.ldexp = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.int]);
ret.types.frexp = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.pointer(ffi.type.int)]);
ret.types.exp = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.atanh = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.asinh = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.acosh = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.tanh = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.sinh = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.cosh = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.tan = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.sin = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.cos = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.atan2 = ffi.type.function(ffi.type.double, [ffi.type.double, ffi.type.double]);
ret.types.atan = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.asin = ffi.type.function(ffi.type.double, [ffi.type.double]);
ret.types.acos = ffi.type.function(ffi.type.double, [ffi.type.double]);
return ret;