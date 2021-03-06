# Created by: Eijiro Shibusawa <ej-sib@ice.uec.ac.jp>
# $FreeBSD$

PORTNAME=	openblas
PORTVERSION=	0.2.6
CATEGORIES=	math
MASTER_SITES=	https://github.com/${GH_USER}/${GH_PORTNAME}/tarball/${GH_VERSION}/ \
		NL:lapack,lapack_tmg
MASTER_SITE_SUBDIR=	lapack/:lapack lapack/timing/:lapack_tmg
DISTFILES=	${GH_USER}-${GH_PORTNAME}-${GH_VERSION}-0-g${GH_REVISION}${EXTRACT_SUFX} \
		lapack-${LAPACKVER}.tgz:lapack \
		large.tgz:lapack_tmg timing.tgz:lapack_tmg

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	Optimized BLAS library based on GotoBLAS2

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

DIST_SUBDIR=	openblas
FETCH_ARGS=	-pRr
GH_USER=	xianyi
GH_PORTNAME=	OpenBLAS
GH_REVISION=	54e7b37
GH_VERSION=	v${PORTVERSION}
LAPACKVER=	3.4.2
LAPACK_SRCFILE=	lapack-${LAPACKVER}.tgz
LARGE_FILE=	large.tgz
TIMING_FILE=	timing.tgz

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_FORTRAN=	yes
USE_PERL5_BUILD=	yes
OPENBLAS_SUFX=	r${PORTVERSION}
OPENBLAS_LIBS=	libopenblas libopenblasp
OPENBLAS_SVER=	0
OPENBLAS_FILES=	${OPENBLAS_LIBS:S|$|.so|} ${OPENBLAS_LIBS:S|$|.so.${OPENBLAS_SVER}|} ${OPENBLAS_LIBS:S|$|.a|}
PLIST_FILES=	${OPENBLAS_FILES:S|^|lib/|}

MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${GH_USER}-${GH_PORTNAME}-87b4d0c

OPTIONS_DEFINE=		DYNAMIC_ARCH INTERFACE64 OPENMP AVX

DYNAMIC_ARCH_DESC=	Support multiple CPU types on i386 and amd64
INTERFACE64_DESC=	Use 8 byte integers on 64-bit architectures
OPENMP_DESC=		Use OpenMP for threading
AVX_DESC=		Support Advanced Vector Extensions (AVX)

.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT=	DYNAMIC_ARCH
.endif

.include <bsd.port.options.mk>

.if defined(TARGET_CPU_ARCH)
BUILDFLAGS+=	TARGET=${TARGET_CPU_ARCH}
.endif

MAXTHREADS?=	8

.if ${ARCH:M*64} == ""
BUILDFLAGS+=	BINARY32=1
.else
BUILDFLAGS+=	BINARY64=1
.endif

.if ! ( ${PORT_OPTIONS:MDYNAMIC_ARCH} && ( ${ARCH} == "amd64" || ${ARCH} == "i386" ) )
MANUAL_PACKAGE_BUILD=	Optimizes for the build machine.
.endif

.if ${PORT_OPTIONS:MDYNAMIC_ARCH}
BUILDFLAGS+=	DYNAMIC_ARCH=1
.endif

.if ${PORT_OPTIONS:MINTERFACE64}
BUILDFLAGS+=	INTERFACE64=1
.endif

.if ${PORT_OPTIONS:MOPENMP}
BUILDFLAGS+=	USE_OPENMP=1
.endif

.if ${PORT_OPTIONS:MQUAD_PRECISION}
BROKEN =	QUAD_PRECISION is broken; please disable this option
BUILDFLAGS+=	QUAD_PRECISION=1
.endif

.if ! ${PORT_OPTIONS:MAVX}
BUILDFLAGS+=	NO_AVX=1
.endif

post-extract:
	cd ${DISTDIR}/${DIST_SUBDIR} ; \
	${CP} ${LAPACK_SRCFILE} ${LARGE_FILE} ${TIMING_FILE} ${WRKSRC}
	${MKDIR} ${WRKDIR}/lib

post-patch:
	${REINPLACE_CMD} -e "s+%%FIND%%+${FIND}+" \
	-e "s+%%XARGS%%+${XARGS}+" \
	-e "s+%%REINPLACE_CMD%%+${REINPLACE_CMD}+" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s+%%FC%%+${FC}+" -e "s+%%CC%%+${CC}+" \
		${WRKSRC}/Makefile.rule
	${REINPLACE_CMD} -e "s+%%LAPACKVER%%+${LAPACKVER}+g" \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s+%%LAPACKVER%%+${LAPACKVER}+g" \
		${WRKSRC}/exports/gensymbol
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" \
		${WRKSRC}/Makefile.rule \
		${WRKSRC}/Makefile.tail \
		${WRKSRC}/driver/level3/Makefile \
		${WRKSRC}/driver/others/Makefile \
		${WRKSRC}/exports/Makefile \
		${WRKSRC}/interface/Makefile \
		${WRKSRC}/kernel/Makefile \
		${WRKSRC}/kernel/Makefile.L3 \
		${WRKSRC}/lapack/laswp/Makefile \
		${WRKSRC}/reference/Makefile
	${REINPLACE_CMD} -e "s+(ARCH)+(ARCH_)+" \
	-e 's+%%LOCALBASE%%+${LOCALBASE}+' \
	-e 's+%%FIND%%+${FIND}+' \
	-e 's+%%XARGS%%+${XARGS}+' \
	-e 's+%%REINPLACE_CMD%%+${REINPLACE_CMD}+' \
	-e 's+%%_GCC_BUILD_DEPENDS%%+${_GCC_BUILD_DEPENDS}+' \
	-e 's+$$(CROSS_SUFFIX)+${LOCALBASE}/bin/+' \
	-e "s+%%LAPACKVER%%+${LAPACKVER}+g" \
		${WRKSRC}/Makefile.system
.if ${PORT_OPTIONS:MOPENMP}
	${REINPLACE_CMD} -e "s+OPENBLAS_NUM_THREADS+OMP_NUM_THREADS+g" \
		${WRKSRC}/test/Makefile \
		${WRKSRC}/ctest/Makefile
.endif

do-build:
	cd ${WRKSRC} ; ${SETENV} ${BUILDFLAGS} NUM_THREADS=1 USE_THREAD=0 \
	${GMAKE} ${MAKE_ARGS}
	${CP} ${WRKSRC}/libopenblas-${OPENBLAS_SUFX}.a ${WRKDIR}/lib/libopenblas.a
	${CP} ${WRKSRC}/libopenblas-${OPENBLAS_SUFX}.so ${WRKDIR}/lib/libopenblas.so.${OPENBLAS_SVER}
	cd ${WRKSRC} ; ${GMAKE} ${MAKE_ARGS} clean
	cd ${WRKSRC} ; ${SETENV} ${BUILDFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${GMAKE} ${MAKE_ARGS}
	${CP} ${WRKSRC}/libopenblasp-${OPENBLAS_SUFX}.a ${WRKDIR}/lib/libopenblasp.a
	${CP} ${WRKSRC}/libopenblasp-${OPENBLAS_SUFX}.so ${WRKDIR}/lib/libopenblasp.so.${OPENBLAS_SVER}
.if !${PORT_OPTIONS:MDEBUG}
	${LOCALBASE}/bin/strip -X ${WRKDIR}/lib/*.so.${OPENBLAS_SVER}
.endif

BENCHMARK_MAXTHREADS?=	${MAXTHREADS}
.if ${PORT_OPTIONS:MOPENMP}
BENCHMARK_THREADS_FLAG =	OMP_NUM_THREADS=${BENCHMARK_MAXTHREADS}
.else
BENCHMARK_THREADS_FLAG =	OPENBLAS_NUM_THREADS=${BENCHMARK_MAXTHREADS}
.endif

benchmark: build
	cd ${WRKSRC} ; ${SETENV} ${BUILDFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${GMAKE} ${MAKE_ARGS} hpl
	cd ${WRKSRC}/benchmark ; ${SETENV} ${BUILDFLAGS} NUM_THREADS=${MAXTHREADS} \
	USE_THREAD=1 ${BENCHMARK_THREADS_FLAG} ${GMAKE} ${MAKE_ARGS}

do-install:
	cd ${WRKDIR}/lib ; \
	${INSTALL_DATA} ${OPENBLAS_LIBS:S|$|.a|} ${OPENBLAS_LIBS:S|$|.so.${OPENBLAS_SVER}|} \
	${PREFIX}/lib/
	cd ${PREFIX}/lib ; \
	for i in ${OPENBLAS_LIBS:S|$|.so|}; do \
		${LN} -sf $$i.${OPENBLAS_SVER} $$i ; \
	done

.include <bsd.port.mk>
