configure_file(output: 'config.h', configuration: confdata)
add_project_arguments('-DHAVE_CONFIG_H', language: 'c')

liberfa = library(
    'erfa',
    'a2af.c', 'a2tf.c', 'ab.c', 'ae2hd.c', 'af2a.c', 'anp.c', 'anpm.c', 'apcg13.c',
    'apcg.c', 'apci13.c', 'apci.c', 'apco13.c', 'apco.c', 'apcs13.c', 'apcs.c', 'aper13.c',
    'aper.c', 'apio13.c', 'apio.c', 'atcc13.c', 'atccq.c',
    'atci13.c', 'atciq.c', 'atciqn.c', 'atciqz.c', 'atco13.c',
    'atic13.c', 'aticq.c', 'aticqn.c', 'atio13.c', 'atioq.c', 'atoc13.c', 'atoi13.c', 'atoiq.c',
    'bi00.c', 'bp00.c', 'bp06.c', 'bpn2xy.c', 'c2i00a.c', 'c2i00b.c', 'c2i06a.c', 'c2ibpn.c',
    'c2ixy.c', 'c2ixys.c', 'c2s.c', 'c2t00a.c', 'c2t00b.c', 'c2t06a.c', 'c2tcio.c', 'c2teqx.c',
    'c2tpe.c', 'c2txy.c', 'cal2jd.c', 'cp.c', 'cpv.c', 'cr.c', 'd2dtf.c', 'd2tf.c', 'dat.c', 'dtdb.c',
    'dtf2d.c', 'eceq06.c', 'ee00a.c', 'ee00.c', 'eect00.c', 'eo06a.c', 'epb2jd.c', 'epj2jd.c', 'epv00.c',
    'eqeq94.c', 'ecm06.c', 'ee00b.c', 'ee06a.c', 'eform.c', 'eors.c', 'epb.c', 'epj.c', 'eqec06.c',
    'era00.c', 'fad03.c', 'fae03.c', 'faf03.c', 'faju03.c', 'fal03.c', 'falp03.c', 'fama03.c',
    'fame03.c', 'fane03.c', 'faom03.c', 'fapa03.c', 'fasa03.c', 'faur03.c', 'fave03.c',
    'fk425.c', 'fk45z.c', 'fk524.c', 'fk54z.c',
    'fk52h.c', 'fk5hip.c', 'fk5hz.c', 'fw2m.c', 'fw2xy.c', 'g2icrs.c', 'gc2gd.c', 'gc2gde.c', 'gd2gc.c',
    'gd2gce.c', 'gmst00.c', 'gmst06.c', 'gmst82.c', 'gst00a.c', 'gst00b.c', 'gst06a.c',
    'gst06.c', 'gst94.c', 'hd2ae.c', 'hd2pa.c', 'h2fk5.c', 'hfk5z.c', 'icrs2g.c', 'ir.c',
    'jd2cal.c', 'jdcalf.c', 'ld.c',
    'ldn.c', 'ldsun.c', 'lteceq.c', 'ltecm.c', 'lteqec.c', 'ltpb.c', 'ltp.c', 'ltpecl.c', 'ltpequ.c',
    'moon98.c',
    'num00a.c', 'num00b.c', 'num06a.c', 'numat.c', 'nut00a.c', 'nut00b.c',
    'nut06a.c', 'nut80.c', 'nutm80.c', 'obl06.c', 'obl80.c', 'p06e.c', 'p2pv.c', 'p2s.c', 'pap.c',
    'pas.c', 'pb06.c', 'pdp.c', 'pfw06.c', 'plan94.c', 'pmat00.c', 'pmat06.c', 'pmat76.c',
    'pm.c', 'pmp.c', 'pmpx.c', 'pmsafe.c', 'pn00a.c', 'pn00b.c', 'pn00.c', 'pn06a.c',
    'pn06.c', 'pn.c', 'pnm00a.c', 'pnm00b.c', 'pnm06a.c', 'pnm80.c', 'pom00.c', 'ppp.c',
    'ppsp.c', 'pr00.c', 'prec76.c', 'pv2p.c', 'pv2s.c', 'pvdpv.c', 'pvm.c', 'pvmpv.c', 'pvppv.c',
    'pvstar.c', 'pvtob.c', 'pvu.c', 'pvup.c', 'pvxpv.c', 'pxp.c', 'refco.c', 'rm2v.c', 'rv2m.c',
    'rx.c', 'rxp.c', 'rxpv.c', 'rxr.c', 'ry.c', 'rz.c', 's00a.c', 's00b.c', 's00.c',
    's06a.c', 's06.c', 's2c.c', 's2p.c', 's2pv.c', 's2xpv.c', 'sepp.c', 'seps.c', 'sp00.c',
    'starpm.c', 'starpv.c', 'sxp.c', 'sxpv.c', 'taitt.c', 'taiut1.c', 'taiutc.c', 'tcbtdb.c',
    'tcgtt.c', 'tdbtcb.c', 'tdbtt.c', 'tf2a.c', 'tf2d.c', 'tpors.c', 'tporv.c', 'tpsts.c',
    'tpstv.c', 'tpxes.c', 'tpxev.c', 'tr.c', 'trxp.c', 'trxpv.c', 'tttai.c',
    'tttcg.c', 'tttdb.c', 'ttut1.c', 'ut1tai.c', 'ut1tt.c', 'ut1utc.c', 'utctai.c', 'utcut1.c',
    'xy06.c', 'xys00a.c', 'xys00b.c', 'xys06a.c', 'zp.c', 'zpv.c', 'zr.c',
    'erfaversion.c', 'erfadatextra.c',
    dependencies: libm,
    version: soversion,
    install: true,
)

erfa_dep = declare_dependency(link_with: liberfa, include_directories: '.')
install_headers('erfa.h', 'erfam.h', 'erfaextra.h', 'erfadatextra.h')

foreach t: ['t_erfa_c', 't_erfa_c_extra']
    exe = executable(t, t+'.c', link_with: liberfa)
    test(t, exe)
endforeach
