# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	unalz
PORTVERSION=	0.65
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.kipple.pe.kr/win/unalz/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extracts AlZip archives

LICENSE_FILE=	${WRKSRC}/readme.txt

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		iconv
USE_DOS2UNIX=	yes
MAKE_ARGS=	CPP="${CXX}" CC="${CC}" OBJ="${UNALZ_OBJS}" \
		LDFLAGS="${LDFLAGS}" CFLAGS="${CFLAGS}"
ALL_TARGET=	posix-utf8
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lz -lbz2

PLIST_FILES=	bin/${PORTNAME}

UNALZ_OBJS=	main.o UnAlz.o UnAlzUtils.o UnAlzBz2decompress.o \
		UnAlzBzip2.o UnAlzbzlib.o

post-patch:
	@${REINPLACE_CMD} -e \
		'/<sys\/timeb.h>/d' ${WRKSRC}/main.cpp

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin)

.include <bsd.port.mk>
