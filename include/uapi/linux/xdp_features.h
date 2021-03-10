/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * Copyright (c) 2020 Intel
 */

#ifndef __UAPI_LINUX_XDP_FEATURES__
#define __UAPI_LINUX_XDP_FEATURES__

enum {
	XDP_ACT_ABORTED_BIT,
	XDP_ACT_DROP_BIT,
	XDP_ACT_PASS_BIT,
	XDP_ACT_TX_BIT,
	XDP_ACT_REDIRECT_BIT,
	XDP_ACT_NDO_XMIT_BIT,
	XDP_ACT_XSK_ZEROCOPY_BIT,
	XDP_ACT_HW_OFFLOAD_BIT,
	XDP_ACT_RX_SG_BIT,
	XDP_ACT_NDO_XMIT_SG_BIT,
	/*
	 * Add your fresh new property above and remember to update
	 * documentation.
	 */
	XDP_ACT_COUNT,
};

#define XDP_FEATURES_WORDS			((XDP_ACT_COUNT + 32 - 1) / 32)
#define XDP_FEATURES_WORD(blocks, index)	((blocks)[(index) / 32U])
#define XDP_FEATURES_FIELD_FLAG(index)		(1U << (index) % 32U)
#define XDP_FEATURES_BIT_IS_SET(blocks, index)        \
	(XDP_FEATURES_WORD(blocks, index) & XDP_FEATURES_FIELD_FLAG(index))

#endif  /* __UAPI_LINUX_XDP_FEATURES__ */
