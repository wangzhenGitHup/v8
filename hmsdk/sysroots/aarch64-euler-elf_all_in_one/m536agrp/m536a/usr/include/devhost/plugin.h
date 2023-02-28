/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: Main header file for plugin coding
 * Author: Huawei OS Kernel Lab
 * Create: Mon Jun 1 11:10:51 2020
 */
#ifndef ULIBS_LIBDEVHOST_PLUGIN_H
#define ULIBS_LIBDEVHOST_PLUGIN_H

#include <devhost/plugin/base.h>
#include <devhost/plugin/event_ep.h>
#include <devhost/plugin/sysif_ep.h>
#include <devhost/plugin/advice_ep.h>

int libdh_dso_plugin_init(struct libdh_plugin *dso_plugin);

#define PUBLIC_SYMBOL	__attribute__((visibility ("default")))

/* plugin definition helper */
#define DEFINE_SYSIF_EXTENSION(ext_name, handler)		\
	static __used struct sysif_extension_info _sf_##ext_name = {	\
		.ext_fn = (sysif_ep_fn_t)(handler),		\
		.precond = NULL,				\
		.ext_inst = NULL,				\
	}
#define DEFINE_EVENT_EXTENSION(ext_name, _before, _after)	\
	static __used struct event_extension_info _ev_##ext_name = {	\
		.before = (void (*)())(_before),		\
		.after = (void (*)())(_after),			\
		.before_inst = NULL,				\
		.after_inst = NULL,				\
	}
#define DEFINE_ADVICE_EXTENSION(ext_name, _before, _around, _after)	\
	static __used struct advice_extension_info _ad_##ext_name = {	\
		.selfish = 0,						\
		.before = (void (*)())(_before),			\
		.around = (int (*)(struct advice_ctx *, ...))(_around),	\
		.after = (void (*)(int around_ret, ...))(_after),	\
		.ext_inst = NULL,					\
	}
#define DEFINE_ADVICE_SELFISH_EXTENSION(ext_name, _before, _around, _after)	\
	static __used struct advice_extension_info _ad_##ext_name = {		\
		.selfish = 1,						\
		.before = (void (*)())(_before),			\
		.around = (int (*)(struct advice_ctx *, ...))(_around),	\
		.after = (void (*)(int around_ret, ...))(_after),	\
		.ext_inst = NULL,					\
	}

/* for sysif */
#define __DEFINE_SYSIF_EP_HANDLER(sysif_name, ext_name, argn, ...)			\
	static int __##sysif_name(__SC_MAP(argn, __SC_DECL, ##__VA_ARGS__));		\
	__DEFINE_SYSIF_EP_HANDLER_CHECKER(sysif_name, ext_name, argn, ##__VA_ARGS__);	\
	DEFINE_SYSIF_EXTENSION(ext_name, __##sysif_name);				\
	static int __##sysif_name(__SC_MAP(argn, __SC_DECL, ##__VA_ARGS__))

#define DEFINE_SYSIF_EXT_HANDLER(sysif_name, ext_name, ...)				\
	__DEFINE_SYSIF_EP_HANDLER(sysif_name, ext_name, __HDLR_ARG_NR(__VA_ARGS__), ##__VA_ARGS__)


#define IMPORT_SYSIF_EXTENSION(ep_name, ext_name)	\
	{ #ep_name, DH_EP_TYPE_SYSIF, __DH_PLUGIN_NAME__, RAW_MUTEX_INITIALIZER, &_sf_##ext_name }
#define IMPORT_EVENT_EXTENSION(ep_name, ext_name)	\
	{ #ep_name, DH_EP_TYPE_EVENT, __DH_PLUGIN_NAME__, RAW_MUTEX_INITIALIZER, &_ev_##ext_name }
#define IMPORT_ADVICE_EXTENSION(ep_name, ext_name)	\
	{ #ep_name, DH_EP_TYPE_ADVICE, __DH_PLUGIN_NAME__, RAW_MUTEX_INITIALIZER, &_ad_##ext_name }

#define __EP_EXTENSION_EOF { NULL, DH_EP_TYPE_INVALID, NULL, RAW_MUTEX_INITIALIZER, NULL }
#define __DEFINE_EP_EXTENSIONS(plugin_name, ...)		\
	static struct libdh_extension			\
		__##plugin_name##_ep_target[] = {	\
		__VA_ARGS__				\
	}

struct libdh_builtin_plugin {
	struct libdh_plugin base;
	int (*constructor)(const struct libdh_builtin_plugin *plugin);
};
int __libdh_builtin_plugin_init(struct libdh_plugin *plugin);

#define DEFINE_BUILTIN_PLUGIN(plugin_name, constructor_fn, ...)			\
__DEFINE_EP_EXTENSIONS(plugin_name, ##__VA_ARGS__, __EP_EXTENSION_EOF);		\
__DEFINE_PLUGIN(plugin_name, struct libdh_builtin_plugin, base,			\
		__##plugin_name##_ep_target, __libdh_builtin_plugin_init, NULL,	\
		DH_PLUGIN_TYPE_BUILTIN,						\
		__SUBCLASS_MEMBER_SET(constructor, constructor_fn))

struct libdh_dso_plugin {
	struct libdh_plugin base;
	int (*constructor)(const struct libdh_dso_plugin *plugin);
};
int __libdh_dso_plugin_init(struct libdh_plugin *plugin);

#define DEFINE_DSO_PLUGIN(plugin_name, constructor_fn, ...)			\
__DEFINE_EP_EXTENSIONS(plugin_name, ##__VA_ARGS__, __EP_EXTENSION_EOF);		\
__DEFINE_PLUGIN(plugin_name, struct libdh_dso_plugin, base,			\
		__##plugin_name##_ep_target, __libdh_dso_plugin_init, NULL,	\
		DH_PLUGIN_TYPE_DYNAMIC,						\
		__SUBCLASS_MEMBER_SET(constructor, constructor_fn))

#endif /* ULIBS_LIBDEVHOST_PLUGIN_H */
