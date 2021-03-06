#ifndef __FORMAT_H__
#define __FORMAT_H__

#define FMT_START		0
#define DEFAULT_FMT_MSG_SIZE	1024
struct oryx_fmt_buff_t {

	/** data hold by this variable. */
	char *fmt_data;

	/** data offset from start of fmt_data. */
	size_t fmt_doffs;

	/** buffer length of whole fmt_data. */
	size_t fmt_buff_size;
};

#define FMT_BUFF_INITIALIZATION	{NULL, 0, 0}
#define FMT_DATA(fmt)	((struct oryx_fmt_buff_t *)(&fmt))->fmt_data
#define FMT_DATA_LENGTH(fmt) ((struct oryx_fmt_buff_t *)(&fmt))->fmt_doffs

#endif

