# Created by: SimaMoto,RyoTa <liangtai.s4@gmail.com>
# $FreeBSD$

PORTNAME=	libbs2b
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/bs2b/bs2b/${PORTVERSION}

MAINTAINER=	liangtai.s4@gmail.com
COMMENT=	Bauer Stereophonic-to-Binaural DSP

LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile \
		ogg:${PORTSDIR}/audio/libogg \
		FLAC:${PORTSDIR}/audio/flac \
		vorbis:${PORTSDIR}/audio/libvorbis

USES=		pkgconfig
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	CFLAGS=`pkg-config --cflags sndfile` \
	LDFLAGS=`pkg-config --libs-only-L sndfile`

pre-configure:
	${REINPLACE_CMD} -e 's@^\(pkgconfigdir = \).*@\1$${prefix}/libdata/pkgconfig@' \
	${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
