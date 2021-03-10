.. SPDX-License-Identifier: GPL-2.0

=====================
Netdev XDP features
=====================

 * XDP FEATURES FLAGS

Following netdev xdp features flags can be retrieved over route netlink
interface (compact form) - the same way as netdev feature flags.
These features flags are read only and cannot be change at runtime.

*  XDP_ACT_ABORTED

This feature informs if netdev supports xdp aborted action.

*  XDP_ACT_DROP

This feature informs if netdev supports xdp drop action.

*  XDP_ACT_PASS

This feature informs if netdev supports xdp pass action.

*  XDP_ACT_TX

This feature informs if netdev supports xdp tx action.

*  XDP_ACT_REDIRECT

This feature informs if netdev supports xdp redirect action.
It assumes the all beforehand mentioned flags are enabled.

*  XDP_ACT_XSK_ZEROCOPY

This feature informs if netdev driver supports xdp zero copy.

*  XDP_ACT_HW_OFFLOAD

This feature informs if netdev driver supports xdp hw oflloading.

*  XDP_ACT_NDO_XMIT

This feature informs if netdev implements ndo_xdp_xmit callback.

*  XDP_ACT_RX_SG

This feature informs if netdev implements non-linear xdp buff support in
the driver napi callback.

*  XDP_ACT_NDO_XMIT_SG

This feature informs if netdev implements non-linear xdp buff support in
ndo_xdp_xmit callback. XDP_FRAG_TARGET requires XDP_REDIRECT_TARGET is properly
supported.
