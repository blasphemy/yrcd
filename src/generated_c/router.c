/* router.c generated by valac 0.24.0, the Vala compiler
 * generated from router.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>


#define YRCD_TYPE_YRCD_ROUTER (yrcd_yrcd_router_get_type ())
#define YRCD_YRCD_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_ROUTER, yrcdyrcd_router))
#define YRCD_YRCD_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_ROUTER, yrcdyrcd_routerClass))
#define YRCD_IS_YRCD_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_ROUTER))
#define YRCD_IS_YRCD_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_ROUTER))
#define YRCD_YRCD_ROUTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_ROUTER, yrcdyrcd_routerClass))

typedef struct _yrcdyrcd_router yrcdyrcd_router;
typedef struct _yrcdyrcd_routerClass yrcdyrcd_routerClass;
typedef struct _yrcdyrcd_routerPrivate yrcdyrcd_routerPrivate;

#define YRCD_TYPE_DELEGATE_WRAPPER (yrcd_delegate_wrapper_get_type ())
#define YRCD_DELEGATE_WRAPPER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_DELEGATE_WRAPPER, yrcdDelegateWrapper))
#define YRCD_DELEGATE_WRAPPER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_DELEGATE_WRAPPER, yrcdDelegateWrapperClass))
#define YRCD_IS_DELEGATE_WRAPPER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_DELEGATE_WRAPPER))
#define YRCD_IS_DELEGATE_WRAPPER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_DELEGATE_WRAPPER))
#define YRCD_DELEGATE_WRAPPER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_DELEGATE_WRAPPER, yrcdDelegateWrapperClass))

typedef struct _yrcdDelegateWrapper yrcdDelegateWrapper;
typedef struct _yrcdDelegateWrapperClass yrcdDelegateWrapperClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define YRCD_TYPE_YRCD_USER (yrcd_yrcd_user_get_type ())
#define YRCD_YRCD_USER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_USER, yrcdyrcd_user))
#define YRCD_YRCD_USER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_USER, yrcdyrcd_userClass))
#define YRCD_IS_YRCD_USER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_USER))
#define YRCD_IS_YRCD_USER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_USER))
#define YRCD_YRCD_USER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_USER, yrcdyrcd_userClass))

typedef struct _yrcdyrcd_user yrcdyrcd_user;
typedef struct _yrcdyrcd_userClass yrcdyrcd_userClass;

#define YRCD_TYPE_YRCD_SERVER (yrcd_yrcd_server_get_type ())
#define YRCD_YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_server))
#define YRCD_YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverClass))
#define YRCD_IS_YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_SERVER))
#define YRCD_IS_YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_SERVER))
#define YRCD_YRCD_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverClass))

typedef struct _yrcdyrcd_server yrcdyrcd_server;
typedef struct _yrcdyrcd_serverClass yrcdyrcd_serverClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))

struct _yrcdyrcd_router {
	GObject parent_instance;
	yrcdyrcd_routerPrivate * priv;
};

struct _yrcdyrcd_routerClass {
	GObjectClass parent_class;
};

struct _yrcdyrcd_routerPrivate {
	GeeHashMap* command_list;
};


static gpointer yrcd_yrcd_router_parent_class = NULL;

GType yrcd_yrcd_router_get_type (void) G_GNUC_CONST;
#define YRCD_YRCD_ROUTER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), YRCD_TYPE_YRCD_ROUTER, yrcdyrcd_routerPrivate))
enum  {
	YRCD_YRCD_ROUTER_DUMMY_PROPERTY
};
gpointer yrcd_delegate_wrapper_ref (gpointer instance);
void yrcd_delegate_wrapper_unref (gpointer instance);
GParamSpec* yrcd_param_spec_delegate_wrapper (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void yrcd_value_set_delegate_wrapper (GValue* value, gpointer v_object);
void yrcd_value_take_delegate_wrapper (GValue* value, gpointer v_object);
gpointer yrcd_value_get_delegate_wrapper (const GValue* value);
GType yrcd_delegate_wrapper_get_type (void) G_GNUC_CONST;
GType yrcd_yrcd_user_get_type (void) G_GNUC_CONST;
void yrcd_yrcd_router_route (yrcdyrcd_router* self, yrcdyrcd_user* user, const gchar* msg);
GType yrcd_yrcd_server_get_type (void) G_GNUC_CONST;
yrcdyrcd_server* yrcd_yrcd_user_get_server (yrcdyrcd_user* self);
void yrcd_yrcd_server_log (yrcdyrcd_server* self, const gchar* msg);
gint yrcd_yrcd_user_get_id (yrcdyrcd_user* self);
void yrcd_yrcd_user_quit (yrcdyrcd_user* self, const gchar* msg);
gchar* yrcd_yrcd_router_strip_end (yrcdyrcd_router* self, const gchar* msg);
gchar** yrcd_yrcd_router_tokenize (yrcdyrcd_router* self, const gchar* msg, int* result_length1);
yrcdyrcd_router* yrcd_yrcd_router_new (void);
yrcdyrcd_router* yrcd_yrcd_router_construct (GType object_type);
static void yrcd_yrcd_router_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


void yrcd_yrcd_router_route (yrcdyrcd_router* self, yrcdyrcd_user* user, const gchar* msg) {
	const gchar* _tmp0_ = NULL;
	gchar* stripped = NULL;
	const gchar* _tmp10_ = NULL;
	gchar* _tmp11_ = NULL;
	gchar** args = NULL;
	const gchar* _tmp12_ = NULL;
	gint _tmp13_ = 0;
	gchar** _tmp14_ = NULL;
	gint args_length1 = 0;
	gint _args_size_ = 0;
	yrcdyrcd_user* _tmp15_ = NULL;
	yrcdyrcd_server* _tmp16_ = NULL;
	yrcdyrcd_server* _tmp17_ = NULL;
	yrcdyrcd_user* _tmp18_ = NULL;
	gint _tmp19_ = 0;
	gint _tmp20_ = 0;
	const gchar* _tmp21_ = NULL;
	gchar* _tmp22_ = NULL;
	gchar* _tmp23_ = NULL;
	gchar** _tmp24_ = NULL;
	gint _tmp24__length1 = 0;
	const gchar* _tmp25_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	_tmp0_ = msg;
	if (_tmp0_ == NULL) {
		yrcdyrcd_user* _tmp1_ = NULL;
		yrcdyrcd_server* _tmp2_ = NULL;
		yrcdyrcd_server* _tmp3_ = NULL;
		yrcdyrcd_user* _tmp4_ = NULL;
		gint _tmp5_ = 0;
		gint _tmp6_ = 0;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_ = NULL;
		yrcdyrcd_user* _tmp9_ = NULL;
		_tmp1_ = user;
		_tmp2_ = yrcd_yrcd_user_get_server (_tmp1_);
		_tmp3_ = _tmp2_;
		_tmp4_ = user;
		_tmp5_ = yrcd_yrcd_user_get_id (_tmp4_);
		_tmp6_ = _tmp5_;
		_tmp7_ = g_strdup_printf ("Received null message, disconnecting user %d", _tmp6_);
		_tmp8_ = _tmp7_;
		yrcd_yrcd_server_log (_tmp3_, _tmp8_);
		_g_free0 (_tmp8_);
		_tmp9_ = user;
		yrcd_yrcd_user_quit (_tmp9_, NULL);
		return;
	}
	_tmp10_ = msg;
	_tmp11_ = yrcd_yrcd_router_strip_end (self, _tmp10_);
	stripped = _tmp11_;
	_tmp12_ = stripped;
	_tmp14_ = yrcd_yrcd_router_tokenize (self, _tmp12_, &_tmp13_);
	args = _tmp14_;
	args_length1 = _tmp13_;
	_args_size_ = args_length1;
	_tmp15_ = user;
	_tmp16_ = yrcd_yrcd_user_get_server (_tmp15_);
	_tmp17_ = _tmp16_;
	_tmp18_ = user;
	_tmp19_ = yrcd_yrcd_user_get_id (_tmp18_);
	_tmp20_ = _tmp19_;
	_tmp21_ = stripped;
	_tmp22_ = g_strdup_printf ("USER %d: received line %s", _tmp20_, _tmp21_);
	_tmp23_ = _tmp22_;
	yrcd_yrcd_server_log (_tmp17_, _tmp23_);
	_g_free0 (_tmp23_);
	_tmp24_ = args;
	_tmp24__length1 = args_length1;
	_tmp25_ = _tmp24_[0];
	if (g_strcmp0 (_tmp25_, "QUIT") == 0) {
		yrcdyrcd_user* _tmp26_ = NULL;
		yrcdyrcd_server* _tmp27_ = NULL;
		yrcdyrcd_server* _tmp28_ = NULL;
		yrcdyrcd_user* _tmp29_ = NULL;
		_tmp26_ = user;
		_tmp27_ = yrcd_yrcd_user_get_server (_tmp26_);
		_tmp28_ = _tmp27_;
		yrcd_yrcd_server_log (_tmp28_, "Received QUIT");
		_tmp29_ = user;
		yrcd_yrcd_user_quit (_tmp29_, NULL);
	}
	args = (_vala_array_free (args, args_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (stripped);
}


gchar* yrcd_yrcd_router_strip_end (yrcdyrcd_router* self, const gchar* msg) {
	gchar* result = NULL;
	GString* builder = NULL;
	GString* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gssize _tmp2_ = 0L;
	const gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (msg != NULL, NULL);
	_tmp0_ = g_string_new ("");
	builder = _tmp0_;
	_tmp1_ = msg;
	g_string_append (builder, _tmp1_);
	_tmp2_ = builder->len;
	g_string_truncate (builder, (gsize) (_tmp2_ - 1));
	_tmp3_ = builder->str;
	_tmp4_ = g_strdup (_tmp3_);
	result = _tmp4_;
	_g_string_free0 (builder);
	return result;
}


gchar** yrcd_yrcd_router_tokenize (yrcdyrcd_router* self, const gchar* msg, int* result_length1) {
	gchar** result = NULL;
	const gchar* _tmp0_ = NULL;
	gchar** _tmp1_ = NULL;
	gchar** _tmp2_ = NULL;
	gchar** _tmp3_ = NULL;
	gint _tmp3__length1 = 0;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (msg != NULL, NULL);
	_tmp0_ = msg;
	_tmp2_ = _tmp1_ = g_strsplit (_tmp0_, " ", 0);
	_tmp3_ = _tmp2_;
	_tmp3__length1 = _vala_array_length (_tmp1_);
	if (result_length1) {
		*result_length1 = _tmp3__length1;
	}
	result = _tmp3_;
	return result;
}


yrcdyrcd_router* yrcd_yrcd_router_construct (GType object_type) {
	yrcdyrcd_router * self = NULL;
	self = (yrcdyrcd_router*) g_object_new (object_type, NULL);
	return self;
}


yrcdyrcd_router* yrcd_yrcd_router_new (void) {
	return yrcd_yrcd_router_construct (YRCD_TYPE_YRCD_ROUTER);
}


static void yrcd_yrcd_router_class_init (yrcdyrcd_routerClass * klass) {
	yrcd_yrcd_router_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (yrcdyrcd_routerPrivate));
	G_OBJECT_CLASS (klass)->finalize = yrcd_yrcd_router_finalize;
}


static void yrcd_yrcd_router_instance_init (yrcdyrcd_router * self) {
	GeeHashMap* _tmp0_ = NULL;
	self->priv = YRCD_YRCD_ROUTER_GET_PRIVATE (self);
	_tmp0_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, YRCD_TYPE_DELEGATE_WRAPPER, (GBoxedCopyFunc) yrcd_delegate_wrapper_ref, yrcd_delegate_wrapper_unref, NULL, NULL, NULL);
	self->priv->command_list = _tmp0_;
}


static void yrcd_yrcd_router_finalize (GObject* obj) {
	yrcdyrcd_router * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, YRCD_TYPE_YRCD_ROUTER, yrcdyrcd_router);
	_g_object_unref0 (self->priv->command_list);
	G_OBJECT_CLASS (yrcd_yrcd_router_parent_class)->finalize (obj);
}


GType yrcd_yrcd_router_get_type (void) {
	static volatile gsize yrcd_yrcd_router_type_id__volatile = 0;
	if (g_once_init_enter (&yrcd_yrcd_router_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (yrcdyrcd_routerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) yrcd_yrcd_router_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (yrcdyrcd_router), 0, (GInstanceInitFunc) yrcd_yrcd_router_instance_init, NULL };
		GType yrcd_yrcd_router_type_id;
		yrcd_yrcd_router_type_id = g_type_register_static (G_TYPE_OBJECT, "yrcdyrcd_router", &g_define_type_info, 0);
		g_once_init_leave (&yrcd_yrcd_router_type_id__volatile, yrcd_yrcd_router_type_id);
	}
	return yrcd_yrcd_router_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



