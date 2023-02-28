/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All rights reserved.
 * Author: Huawei OS Kernel Lab
 * Create: Fri May 24 11:31:40 2019
 */
#ifndef ENTITY_H
#define ENTITY_H

#include <stdbool.h>
#include <stdint.h>

struct type_sink;
typedef struct type_sink *type_sink_ptr;

typedef struct entity entity_t;
typedef struct entity_opset entity_opset_t;
typedef struct type_desc type_desc_t;

struct type_desc {
	const char *name;
	const char *parent;

	int entity_size;
	int (*entity_init)(entity_t *ent);
	int (*entity_finalize)(entity_t *ent);

	bool abstract;

	int opset_size;
	int (*opset_init)(entity_opset_t *opset, void *data);

	void *opset_data;
};

typedef void (entity_free)(void *ent);

struct entity {
	entity_opset_t *opset;

	entity_free *free;
	uint32_t ref;
	entity_t *parent;
};

struct entity_opset {
	type_sink_ptr type_sink_ptr;
};

#define TYPE_ENTITY "entity"
#define ENTITY(ent) ((entity_t *)(ent))
#define ENTITY_OPSET(opset) ((entity_opset_t *)(opset))
#define ENTITY_GET_OPSET(opset, ent, name) \
	ENTITY_OPSET_CHECK(opset, entity_get_opset(ENTITY(ent)), name)

#define ENTITY_OPSET_CHECK(ent_opset_type, opset, name) \
	((ent_opset_type *) entity_opset_dynamic_cast(ENTITY_OPSET(opset), \
	(name)))
#define ENTITY_CHECK(type, ent, name) \
	((type *) entity_dynamic_cast(ENTITY(ent), (name)))

#define VEM_MAX_REFCNT 0x7fffffffu

#ifdef __HOST_LLT__
#define TS_HT_SIZE 20
#else
#define TS_HT_SIZE 4
#endif

entity_t *entity_new(const char *type_name);
int entity_initialize(entity_t *ent, int size, const char *type_name);

entity_opset_t *entity_get_opset(entity_t *ent);
const char *entity_get_type_name(const entity_t *ent);
int entity_get_size(const char *type_name);

type_sink_ptr type_register(const type_desc_t *t_desc);

entity_opset_t *entity_opset_dynamic_cast(entity_opset_t *opset,
					  const char *type_name);
entity_t *entity_dynamic_cast(entity_t *ent, const char *type_name);

entity_opset_t *entity_opset_get_parent(entity_opset_t *opset);
const char *entity_opset_get_name(const entity_opset_t *opset);
bool entity_opset_is_abstract(const entity_opset_t *opset);
entity_opset_t *entity_opset_get_by_name(const char *type_name);

int entity_ref(entity_t *ent);
int entity_unref(entity_t *ent);
int entity_unref_only(entity_t *ent);
#endif
