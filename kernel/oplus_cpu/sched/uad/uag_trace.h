/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2022 Oplus. All rights reserved.
 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM uad

#if !defined(_TRACE_UAG_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_UAG_H

#include <linux/string.h>
#include <linux/types.h>
#include <linux/tracepoint.h>

/* Optional target-load tracing. Disabled for the minimal UAG build. */
#ifdef CONFIG_OPLUS_UAG_USE_TL
TRACE_EVENT(uag_next_util_tl,
	TP_PROTO(unsigned int cpu, unsigned long util, unsigned long max,
		unsigned int target_util),
	TP_ARGS(cpu, util, max, target_util),
	TP_STRUCT__entry(
		__field(unsigned int, cpu)
		__field(unsigned long, util)
		__field(unsigned long, max)
		__field(unsigned int, target_util)),
	TP_fast_assign(
		__entry->cpu = cpu;
		__entry->util = util;
		__entry->max = max;
		__entry->target_util = target_util;),
	TP_printk("cpu=%u util=%lu max=%lu target_util=%u",
		__entry->cpu,
		__entry->util,
		__entry->max,
		__entry->target_util)
);

TRACE_EVENT(uag_next_freq_info,
	    TP_PROTO(int cluster_id, unsigned long util, int opp,
		     unsigned int next_freq),
	    TP_ARGS(cluster_id, util, opp, next_freq),
	    TP_STRUCT__entry(
		    __field(int, cluster_id)
		    __field(unsigned long, util)
		    __field(int, opp)
		    __field(unsigned int, next_freq)),
	    TP_fast_assign(
		    __entry->cluster_id = cluster_id;
		    __entry->util = util;
		    __entry->opp = opp;
		    __entry->next_freq = next_freq;),
	    TP_printk("cluster_id=%d util=%lu opp=%d next_freq=%u",
		      __entry->cluster_id,
		      __entry->util,
		      __entry->opp,
		      __entry->next_freq)
);

TRACE_EVENT(choose_util,
	    TP_PROTO(unsigned int cpu, unsigned int util, unsigned int prevutil, unsigned int utilmax,
		     unsigned int utilmin, unsigned int tl),
	    TP_ARGS(cpu, util, prevutil, utilmax, utilmin, tl),
	    TP_STRUCT__entry(
			__field(unsigned int, cpu)
			__field(unsigned int, util)
			__field(unsigned int, prevutil)
			__field(unsigned int, utilmax)
			__field(unsigned int, utilmin)
			__field(unsigned int, tl)),
	    TP_fast_assign(
			__entry->cpu = cpu;
			__entry->util = util;
			__entry->prevutil = prevutil;
			__entry->utilmax = utilmax;
			__entry->utilmin = utilmin;
			__entry->tl = tl;),
	    TP_printk("cpu=%u util=%u prevutil=%u utilmax=%u utilmin=%u tl=%u",
			__entry->cpu,
			__entry->util,
			__entry->prevutil,
			__entry->utilmax,
			__entry->utilmin,
			__entry->tl)
);

TRACE_EVENT(uag_next_freq_tl,
	    TP_PROTO(unsigned int cpu, unsigned long raw_util, unsigned long raw_freq,
		     unsigned long util, unsigned long next_freq),
	    TP_ARGS(cpu, raw_util, raw_freq, util, next_freq),
	    TP_STRUCT__entry(
		    __field(unsigned int, cpu)
		    __field(unsigned long, raw_util)
		    __field(unsigned long, raw_freq)
		    __field(unsigned long, util)
		    __field(unsigned long, next_freq)),
	    TP_fast_assign(
		    __entry->cpu = cpu;
		    __entry->raw_util = raw_util;
		    __entry->raw_freq = raw_freq;
		    __entry->util = util;
		    __entry->next_freq = next_freq;),
	    TP_printk("cpu=%u raw_util=%lu raw_freq=%lu util=%lu next_freq=%lu",
		      __entry->cpu,
		      __entry->raw_util,
		      __entry->raw_freq,
		      __entry->util,
		      __entry->next_freq)
);
#endif

#endif /* _TRACE_UAG_H */

#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH .
#undef TRACE_INCLUDE_FILE
#define TRACE_INCLUDE_FILE uag_trace

/* This part must be outside protection. */
#include <trace/define_trace.h>
