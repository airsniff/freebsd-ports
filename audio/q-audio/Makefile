# Created by: ag@muwiinfa.geschichte.uni-mainz.de Albert Graef
# $FreeBSD$

PORTNAME=	audio
PORTVERSION=	2.7
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF/q-lang/q-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	q-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Q-Audio -- digital audio interface for the Q language

LIB_DEPENDS=	q.8:${PORTSDIR}/lang/q \
    		jack.0:${PORTSDIR}/audio/jack \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		fftw3:${PORTSDIR}/math/fftw3
BUILD_DEPENDS=	${LOCALBASE}/lib/portaudio2/libportaudio.so.2:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		pkgconfig

.if defined(.PARSEDIR)
USE_GMAKE=	yes
.endif

DATADIR=	${PREFIX}/share/q

CFLAGS+=	-I${LOCALBASE}/include/portaudio2 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/portaudio2 -L${LOCALBASE}/lib
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
