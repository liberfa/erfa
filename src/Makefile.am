lib_LTLIBRARIES = liberfa.la
liberfa_la_SOURCES = a2af.c a2tf.c af2a.c anp.c anpm.c bi00.c bp00.c \
bp06.c bpn2xy.c c2i00a.c c2i00b.c c2i06a.c c2ibpn.c c2ixy.c c2ixys.c \
c2s.c c2t00a.c c2t00b.c c2t06a.c c2tcio.c c2teqx.c c2tpe.c c2txy.c \
cal2jd.c cp.c cpv.c cr.c d2dtf.c d2tf.c dat.c dtdb.c dtf2d.c ee00a.c \
ee00b.c ee00.c ee06a.c eect00.c eform.c eo06a.c eors.c epb2jd.c epb.c \
epj2jd.c epj.c epv00.c eqeq94.c era00.c fad03.c fae03.c faf03.c faju03.c \
fal03.c falp03.c fama03.c fame03.c fane03.c faom03.c fapa03.c fasa03.c \
faur03.c fave03.c fk52h.c fk5hip.c fk5hz.c fw2m.c fw2xy.c gc2gd.c gc2gde.c \
gd2gc.c gd2gce.c gmst00.c gmst06.c gmst82.c gst00a.c gst00b.c \
gst06a.c gst06.c gst94.c h2fk5.c hfk5z.c ir.c jd2cal.c jdcalf.c \
num00a.c num00b.c num06a.c numat.c nut00a.c nut00b.c nut06a.c nut80.c \
nutm80.c obl06.c obl80.c p06e.c p2pv.c p2s.c pap.c pas.c pb06.c \
pdp.c pfw06.c plan94.c pmat00.c pmat06.c pmat76.c pm.c pmp.c pn00a.c \
pn00b.c pn00.c pn06a.c pn06.c pn.c pnm00a.c pnm00b.c pnm06a.c pnm80.c \
pom00.c ppp.c ppsp.c pr00.c prec76.c pv2p.c pv2s.c pvdpv.c pvm.c \
pvmpv.c pvppv.c pvstar.c pvu.c pvup.c pvxpv.c pxp.c rm2v.c rv2m.c \
rx.c rxp.c rxpv.c rxr.c ry.c rz.c s00a.c s00b.c s00.c s06a.c s06.c \
s2c.c s2p.c s2pv.c s2xpv.c sepp.c seps.c sp00.c starpm.c starpv.c sxp.c \
sxpv.c taitt.c taiut1.c taiutc.c tcbtdb.c tcgtt.c tdbtcb.c tdbtt.c \
tf2a.c tf2d.c tr.c trxp.c trxpv.c tttai.c tttcg.c tttdb.c \
ttut1.c ut1tai.c ut1tt.c ut1utc.c utctai.c utcut1.c xy06.c xys00a.c \
xys00b.c xys06a.c zp.c zpv.c zr.c

include_HEADERS = erfa.h erfam.h

## Version info is in current : revision : age form
## A library supports interfaces from current downto current - age
## Revision is the version of the current interface
## If the source code has changed at all, rev += 1

#liberfa_la_LDFLAGS = -version-info 0:0:0

#for erfa, we compute this version info. For ERFA x.y.z we set version-info
#to (x+y):z:y, as this reproduces the appropriate SONAME matching the
#library version number for semantic versioning
PKG_MAJ = `echo $(PACKAGE_VERSION) | cut -d . -f 1`
PKG_MIN = `echo $(PACKAGE_VERSION) | cut -d . -f 2`
PKG_BUG = `echo $(PACKAGE_VERSION) | cut -d . -f 3`
VI_CURR =  $(shell echo $(PKG_MAJ)+$(PKG_MIN) | bc)
VI_REV = $(PKG_BUG)
VI_AGE = $(PKG_MIN)

liberfa_la_LDFLAGS = -version-info $(VI_CURR):$(VI_REV):$(VI_AGE)


## Check program
TESTS = t_erfa_c
check_PROGRAMS = t_erfa_c
t_erfa_c_SOURCES = t_erfa_c.c
AM_CPPFLAGS = -I$(top_srcdir)
LDADD = $(top_builddir)/src/liberfa.la
