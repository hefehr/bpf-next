/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Network device xdp features.
 */
#ifndef _LINUX_XDP_FEATURES_H
#define _LINUX_XDP_FEATURES_H

#include <linux/types.h>
#include <linux/bitops.h>
#include <asm/byteorder.h>
#include <uapi/linux/xdp_features.h>

typedef u32 xdp_features_t;

#define __XDP_ACT_BIT(bit)	((xdp_features_t)1 << (bit))
#define __XDP_ACT(name)		__XDP_ACT_BIT(XDP_ACT_##name##_BIT)

#define XDP_ACT_ABORTED		__XDP_ACT(ABORTED)
#define XDP_ACT_DROP		__XDP_ACT(DROP)
#define XDP_ACT_PASS		__XDP_ACT(PASS)
#define XDP_ACT_TX		__XDP_ACT(TX)
#define XDP_ACT_REDIRECT	__XDP_ACT(REDIRECT)
#define XDP_ACT_NDO_XMIT	__XDP_ACT(NDO_XMIT)
#define XDP_ACT_XSK_ZEROCOPY	__XDP_ACT(XSK_ZEROCOPY)
#define XDP_ACT_HW_OFFLOAD	__XDP_ACT(HW_OFFLOAD)
#define XDP_ACT_RX_SG		__XDP_ACT(RX_SG)
#define XDP_ACT_NDO_XMIT_SG	__XDP_ACT(NDO_XMIT_SG)

#define XDP_ACT_BASIC		(XDP_ACT_ABORTED | XDP_ACT_DROP |	\
				 XDP_ACT_PASS | XDP_ACT_TX)

#define XDP_ACT_FULL		(XDP_ACT_BASIC | XDP_ACT_REDIRECT)

#define XDP_ACT_FULL_ZC		(XDP_ACT_FULL | XDP_ACT_XSK_ZEROCOPY)

#define XDP_ACT_ABORTED_STR		"xdp-aborted"
#define XDP_ACT_DROP_STR		"xdp-drop"
#define XDP_ACT_PASS_STR		"xdp-pass"
#define XDP_ACT_TX_STR			"xdp-tx"
#define XDP_ACT_REDIRECT_STR		"xdp-redirect"
#define XDP_ACT_NDO_XMIT_STR		"xdp-ndo-xmit"
#define XDP_ACT_XSK_ZEROCOPY_STR	"xsk-zerocopy"
#define XDP_ACT_HW_OFFLOAD_STR		"xdp-hw-offload"
#define XDP_ACT_RX_SG_STR		"xdp-rx-sg"
#define XDP_ACT_NDO_XMIT_SG_STR		"xdp-ndo-xmit-sg"

#define DECLARE_XDP_FEATURES_TABLE(name, length)			\
	const char name[][length] = {					\
		[XDP_ACT_ABORTED_BIT] = XDP_ACT_ABORTED_STR,		\
		[XDP_ACT_DROP_BIT] = XDP_ACT_DROP_STR,			\
		[XDP_ACT_PASS_BIT] = XDP_ACT_PASS_STR,			\
		[XDP_ACT_TX_BIT] = XDP_ACT_TX_STR,			\
		[XDP_ACT_REDIRECT_BIT] = XDP_ACT_REDIRECT_STR,		\
		[XDP_ACT_NDO_XMIT_BIT] = XDP_ACT_NDO_XMIT_STR,		\
		[XDP_ACT_XSK_ZEROCOPY_BIT] = XDP_ACT_XSK_ZEROCOPY_STR,	\
		[XDP_ACT_HW_OFFLOAD_BIT] = XDP_ACT_HW_OFFLOAD_STR,	\
		[XDP_ACT_RX_SG_BIT] = XDP_ACT_RX_SG_STR,		\
		[XDP_ACT_NDO_XMIT_SG_BIT] = XDP_ACT_NDO_XMIT_SG_STR,	\
	}

#endif /* _LINUX_XDP_FEATURES_H */
