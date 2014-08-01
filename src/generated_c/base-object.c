/* base-object.c generated by valac 0.25.1, the Vala compiler
 * generated from base-object.vala, do not modify */

/* Copyright 2013-2014 Yorba Foundation
 *
 * This software is licensed under the GNU Lesser General Public License
 * (version 2.1 or later).  See the COPYING file in this distribution.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdio.h>


#define YRCD_TYPE_BASE_OBJECT (yrcd_base_object_get_type ())
#define YRCD_BASE_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_BASE_OBJECT, yrcdBaseObject))
#define YRCD_BASE_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_BASE_OBJECT, yrcdBaseObjectClass))
#define YRCD_IS_BASE_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_BASE_OBJECT))
#define YRCD_IS_BASE_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_BASE_OBJECT))
#define YRCD_BASE_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_BASE_OBJECT, yrcdBaseObjectClass))

typedef struct _yrcdBaseObject yrcdBaseObject;
typedef struct _yrcdBaseObjectClass yrcdBaseObjectClass;
typedef struct _yrcdBaseObjectPrivate yrcdBaseObjectPrivate;

struct _yrcdBaseObject {
	GObject parent_instance;
	yrcdBaseObjectPrivate * priv;
};

struct _yrcdBaseObjectClass {
	GObjectClass parent_class;
};


static gpointer yrcd_base_object_parent_class = NULL;

GType yrcd_base_object_get_type (void) G_GNUC_CONST;
enum  {
	YRCD_BASE_OBJECT_DUMMY_PROPERTY
};
yrcdBaseObject* yrcd_base_object_construct (GType object_type);
void yrcd_base_object_dump_refs (FILE* outs);


yrcdBaseObject* yrcd_base_object_construct (GType object_type) {
	yrcdBaseObject * self = NULL;
	self = (yrcdBaseObject*) g_object_new (object_type, NULL);
	return self;
}


void yrcd_base_object_dump_refs (FILE* outs) {
	FILE* _tmp0_ = NULL;
	g_return_if_fail (outs != NULL);
	_tmp0_ = outs;
	fprintf (_tmp0_, "Reference tracking disabled.\n");
}


static void yrcd_base_object_class_init (yrcdBaseObjectClass * klass) {
	yrcd_base_object_parent_class = g_type_class_peek_parent (klass);
}


static void yrcd_base_object_instance_init (yrcdBaseObject * self) {
}


GType yrcd_base_object_get_type (void) {
	static volatile gsize yrcd_base_object_type_id__volatile = 0;
	if (g_once_init_enter (&yrcd_base_object_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (yrcdBaseObjectClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) yrcd_base_object_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (yrcdBaseObject), 0, (GInstanceInitFunc) yrcd_base_object_instance_init, NULL };
		GType yrcd_base_object_type_id;
		yrcd_base_object_type_id = g_type_register_static (G_TYPE_OBJECT, "yrcdBaseObject", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&yrcd_base_object_type_id__volatile, yrcd_base_object_type_id);
	}
	return yrcd_base_object_type_id__volatile;
}



