/* router.c generated by valac 0.24.0, the Vala compiler
 * generated from router.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>


#define YRCD_TYPE_YRCD_ROUTER (yrcd_yrcd_router_get_type ())
#define YRCD_YRCD_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_ROUTER, yrcdyrcd_router))
#define YRCD_YRCD_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_ROUTER, yrcdyrcd_routerClass))
#define YRCD_IS_YRCD_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_ROUTER))
#define YRCD_IS_YRCD_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_ROUTER))
#define YRCD_YRCD_ROUTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_ROUTER, yrcdyrcd_routerClass))

typedef struct _yrcdyrcd_router yrcdyrcd_router;
typedef struct _yrcdyrcd_routerClass yrcdyrcd_routerClass;
typedef struct _yrcdyrcd_routerPrivate yrcdyrcd_routerPrivate;

#define YRCD_TYPE_YRCD_SERVER (yrcd_yrcd_server_get_type ())
#define YRCD_YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_server))
#define YRCD_YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverClass))
#define YRCD_IS_YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_SERVER))
#define YRCD_IS_YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_SERVER))
#define YRCD_YRCD_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverClass))

typedef struct _yrcdyrcd_server yrcdyrcd_server;
typedef struct _yrcdyrcd_serverClass yrcdyrcd_serverClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define YRCD_TYPE_YRCD_USER (yrcd_yrcd_user_get_type ())
#define YRCD_YRCD_USER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_USER, yrcdyrcd_user))
#define YRCD_YRCD_USER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_USER, yrcdyrcd_userClass))
#define YRCD_IS_YRCD_USER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_USER))
#define YRCD_IS_YRCD_USER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_USER))
#define YRCD_YRCD_USER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_USER, yrcdyrcd_userClass))

typedef struct _yrcdyrcd_user yrcdyrcd_user;
typedef struct _yrcdyrcd_userClass yrcdyrcd_userClass;
#define _g_free0(var) (var = (g_free (var), NULL))

#define YRCD_TYPE_YRCD_CHANNEL (yrcd_yrcd_channel_get_type ())
#define YRCD_YRCD_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channel))
#define YRCD_YRCD_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channelClass))
#define YRCD_IS_YRCD_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_CHANNEL))
#define YRCD_IS_YRCD_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_CHANNEL))
#define YRCD_YRCD_CHANNEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channelClass))

typedef struct _yrcdyrcd_channel yrcdyrcd_channel;
typedef struct _yrcdyrcd_channelClass yrcdyrcd_channelClass;
typedef struct _yrcdyrcd_serverPrivate yrcdyrcd_serverPrivate;

#define YRCD_TYPE_YRCD_NUMERIC_WRAPPER (yrcd_yrcd_numeric_wrapper_get_type ())
#define YRCD_YRCD_NUMERIC_WRAPPER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_NUMERIC_WRAPPER, yrcdyrcd_numeric_wrapper))
#define YRCD_YRCD_NUMERIC_WRAPPER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_NUMERIC_WRAPPER, yrcdyrcd_numeric_wrapperClass))
#define YRCD_IS_YRCD_NUMERIC_WRAPPER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_NUMERIC_WRAPPER))
#define YRCD_IS_YRCD_NUMERIC_WRAPPER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_NUMERIC_WRAPPER))
#define YRCD_YRCD_NUMERIC_WRAPPER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_NUMERIC_WRAPPER, yrcdyrcd_numeric_wrapperClass))

typedef struct _yrcdyrcd_numeric_wrapper yrcdyrcd_numeric_wrapper;
typedef struct _yrcdyrcd_numeric_wrapperClass yrcdyrcd_numeric_wrapperClass;
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))

struct _yrcdyrcd_router {
	GObject parent_instance;
	yrcdyrcd_routerPrivate * priv;
	yrcdyrcd_server* server;
};

struct _yrcdyrcd_routerClass {
	GObjectClass parent_class;
};

struct _yrcdyrcd_server {
	GObject parent_instance;
	yrcdyrcd_serverPrivate * priv;
	GeeHashMap* channellist;
	gint64 epoch;
	gint max_users;
	yrcdyrcd_numeric_wrapper* numeric_wrapper;
};

struct _yrcdyrcd_serverClass {
	GObjectClass parent_class;
};


static gpointer yrcd_yrcd_router_parent_class = NULL;

GType yrcd_yrcd_router_get_type (void) G_GNUC_CONST;
GType yrcd_yrcd_server_get_type (void) G_GNUC_CONST;
enum  {
	YRCD_YRCD_ROUTER_DUMMY_PROPERTY
};
yrcdyrcd_router* yrcd_yrcd_router_new (yrcdyrcd_server* k);
yrcdyrcd_router* yrcd_yrcd_router_construct (GType object_type, yrcdyrcd_server* k);
GType yrcd_yrcd_user_get_type (void) G_GNUC_CONST;
void yrcd_yrcd_router_route (yrcdyrcd_router* self, yrcdyrcd_user* user, const gchar* msg);
yrcdyrcd_server* yrcd_yrcd_user_get_server (yrcdyrcd_user* self);
void yrcd_yrcd_server_log (yrcdyrcd_server* self, const gchar* msg);
gint yrcd_yrcd_user_get_id (yrcdyrcd_user* self);
void yrcd_yrcd_user_quit (yrcdyrcd_user* self, const gchar* msg);
gchar* yrcd_yrcd_router_strip_end (yrcdyrcd_router* self, const gchar* msg);
gchar** yrcd_yrcd_router_tokenize (yrcdyrcd_router* self, const gchar* msg, int* result_length1);
void yrcd_yrcd_user_update_timestamp (yrcdyrcd_user* self);
void yrcd_yrcd_user_change_nick (yrcdyrcd_user* self, gchar** args, int args_length1);
void yrcd_yrcd_user_user_reg (yrcdyrcd_user* self, gchar** args, int args_length1);
void yrcd_yrcd_router_privmsg_handler (yrcdyrcd_router* self, yrcdyrcd_user* user, gchar** args, int args_length1);
void yrcd_yrcd_router_join_handler (yrcdyrcd_router* self, yrcdyrcd_user* user, gchar** args, int args_length1);
void yrcd_yrcd_router_unknown_command_handler (yrcdyrcd_router* self, yrcdyrcd_user* user, gchar** args, int args_length1);
void yrcd_yrcd_user_fire_numeric (yrcdyrcd_user* self, gint numeric, ...);
#define YRCD_ERR_UNKNOWNCOMMAND 421
GType yrcd_yrcd_channel_get_type (void) G_GNUC_CONST;
yrcdyrcd_channel* yrcd_yrcd_server_get_channel_by_name (yrcdyrcd_server* self, const gchar* nametocheck);
gint yrcd_yrcd_server_new_cid (yrcdyrcd_server* self);
yrcdyrcd_channel* yrcd_yrcd_channel_new (gint id);
yrcdyrcd_channel* yrcd_yrcd_channel_construct (GType object_type, gint id);
void yrcd_yrcd_channel_set_name (yrcdyrcd_channel* self, const gchar* value);
GType yrcd_yrcd_numeric_wrapper_get_type (void) G_GNUC_CONST;
void yrcd_yrcd_user_join (yrcdyrcd_user* self, yrcdyrcd_channel* chan);
yrcdyrcd_user* yrcd_yrcd_server_get_user_by_nick (yrcdyrcd_server* self, const gchar* nicktocheck);
static void yrcd_yrcd_router_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);

extern const gchar* YRCD_YRCD_CONSTANTS_chan_prefixes[2];

static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


yrcdyrcd_router* yrcd_yrcd_router_construct (GType object_type, yrcdyrcd_server* k) {
	yrcdyrcd_router * self = NULL;
	yrcdyrcd_server* _tmp0_ = NULL;
	yrcdyrcd_server* _tmp1_ = NULL;
	g_return_val_if_fail (k != NULL, NULL);
	self = (yrcdyrcd_router*) g_object_new (object_type, NULL);
	_tmp0_ = k;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->server);
	self->server = _tmp1_;
	return self;
}


yrcdyrcd_router* yrcd_yrcd_router_new (yrcdyrcd_server* k) {
	return yrcd_yrcd_router_construct (YRCD_TYPE_YRCD_ROUTER, k);
}


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
	gchar** _tmp15_ = NULL;
	gint _tmp15__length1 = 0;
	const gchar* _tmp16_ = NULL;
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
	_tmp15_ = args;
	_tmp15__length1 = args_length1;
	_tmp16_ = _tmp15_[0];
	if (_tmp16_ != NULL) {
		yrcdyrcd_user* _tmp17_ = NULL;
		yrcdyrcd_server* _tmp18_ = NULL;
		yrcdyrcd_server* _tmp19_ = NULL;
		yrcdyrcd_user* _tmp20_ = NULL;
		gint _tmp21_ = 0;
		gint _tmp22_ = 0;
		const gchar* _tmp23_ = NULL;
		gchar* _tmp24_ = NULL;
		gchar* _tmp25_ = NULL;
		yrcdyrcd_user* _tmp26_ = NULL;
		gchar** _tmp27_ = NULL;
		gint _tmp27__length1 = 0;
		const gchar* _tmp28_ = NULL;
		gchar* _tmp29_ = NULL;
		gchar* _tmp30_ = NULL;
		GQuark _tmp32_ = 0U;
		static GQuark _tmp31_label0 = 0;
		static GQuark _tmp31_label1 = 0;
		static GQuark _tmp31_label2 = 0;
		static GQuark _tmp31_label3 = 0;
		static GQuark _tmp31_label4 = 0;
		_tmp17_ = user;
		_tmp18_ = yrcd_yrcd_user_get_server (_tmp17_);
		_tmp19_ = _tmp18_;
		_tmp20_ = user;
		_tmp21_ = yrcd_yrcd_user_get_id (_tmp20_);
		_tmp22_ = _tmp21_;
		_tmp23_ = stripped;
		_tmp24_ = g_strdup_printf ("USER %d: received line %s", _tmp22_, _tmp23_);
		_tmp25_ = _tmp24_;
		yrcd_yrcd_server_log (_tmp19_, _tmp25_);
		_g_free0 (_tmp25_);
		_tmp26_ = user;
		yrcd_yrcd_user_update_timestamp (_tmp26_);
		_tmp27_ = args;
		_tmp27__length1 = args_length1;
		_tmp28_ = _tmp27_[0];
		_tmp29_ = g_utf8_strdown (_tmp28_, (gssize) (-1));
		_tmp30_ = _tmp29_;
		_tmp32_ = (NULL == _tmp30_) ? 0 : g_quark_from_string (_tmp30_);
		g_free (_tmp30_);
		if (_tmp32_ == ((0 != _tmp31_label0) ? _tmp31_label0 : (_tmp31_label0 = g_quark_from_static_string ("quit")))) {
			switch (0) {
				default:
				{
					yrcdyrcd_user* _tmp33_ = NULL;
					yrcdyrcd_server* _tmp34_ = NULL;
					yrcdyrcd_server* _tmp35_ = NULL;
					yrcdyrcd_user* _tmp36_ = NULL;
					_tmp33_ = user;
					_tmp34_ = yrcd_yrcd_user_get_server (_tmp33_);
					_tmp35_ = _tmp34_;
					yrcd_yrcd_server_log (_tmp35_, "Received QUIT");
					_tmp36_ = user;
					yrcd_yrcd_user_quit (_tmp36_, NULL);
					break;
				}
			}
		} else if (_tmp32_ == ((0 != _tmp31_label1) ? _tmp31_label1 : (_tmp31_label1 = g_quark_from_static_string ("nick")))) {
			switch (0) {
				default:
				{
					yrcdyrcd_user* _tmp37_ = NULL;
					gchar** _tmp38_ = NULL;
					gint _tmp38__length1 = 0;
					_tmp37_ = user;
					_tmp38_ = args;
					_tmp38__length1 = args_length1;
					yrcd_yrcd_user_change_nick (_tmp37_, _tmp38_, _tmp38__length1);
					break;
				}
			}
		} else if (_tmp32_ == ((0 != _tmp31_label2) ? _tmp31_label2 : (_tmp31_label2 = g_quark_from_static_string ("user")))) {
			switch (0) {
				default:
				{
					yrcdyrcd_user* _tmp39_ = NULL;
					gchar** _tmp40_ = NULL;
					gint _tmp40__length1 = 0;
					_tmp39_ = user;
					_tmp40_ = args;
					_tmp40__length1 = args_length1;
					yrcd_yrcd_user_user_reg (_tmp39_, _tmp40_, _tmp40__length1);
					break;
				}
			}
		} else if (_tmp32_ == ((0 != _tmp31_label3) ? _tmp31_label3 : (_tmp31_label3 = g_quark_from_static_string ("privmsg")))) {
			switch (0) {
				default:
				{
					yrcdyrcd_user* _tmp41_ = NULL;
					gchar** _tmp42_ = NULL;
					gint _tmp42__length1 = 0;
					_tmp41_ = user;
					_tmp42_ = args;
					_tmp42__length1 = args_length1;
					yrcd_yrcd_router_privmsg_handler (self, _tmp41_, _tmp42_, _tmp42__length1);
					break;
				}
			}
		} else if (_tmp32_ == ((0 != _tmp31_label4) ? _tmp31_label4 : (_tmp31_label4 = g_quark_from_static_string ("join")))) {
			switch (0) {
				default:
				{
					yrcdyrcd_user* _tmp43_ = NULL;
					gchar** _tmp44_ = NULL;
					gint _tmp44__length1 = 0;
					_tmp43_ = user;
					_tmp44_ = args;
					_tmp44__length1 = args_length1;
					yrcd_yrcd_router_join_handler (self, _tmp43_, _tmp44_, _tmp44__length1);
					break;
				}
			}
		} else {
			switch (0) {
				default:
				{
					yrcdyrcd_user* _tmp45_ = NULL;
					gchar** _tmp46_ = NULL;
					gint _tmp46__length1 = 0;
					_tmp45_ = user;
					_tmp46_ = args;
					_tmp46__length1 = args_length1;
					yrcd_yrcd_router_unknown_command_handler (self, _tmp45_, _tmp46_, _tmp46__length1);
					break;
				}
			}
		}
	}
	args = (_vala_array_free (args, args_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (stripped);
}


void yrcd_yrcd_router_unknown_command_handler (yrcdyrcd_router* self, yrcdyrcd_user* user, gchar** args, int args_length1) {
	yrcdyrcd_user* _tmp0_ = NULL;
	gchar** _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	const gchar* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	_tmp0_ = user;
	_tmp1_ = args;
	_tmp1__length1 = args_length1;
	_tmp2_ = _tmp1_[0];
	yrcd_yrcd_user_fire_numeric (_tmp0_, YRCD_ERR_UNKNOWNCOMMAND, _tmp2_, NULL);
}


void yrcd_yrcd_router_join_handler (yrcdyrcd_router* self, yrcdyrcd_user* user, gchar** args, int args_length1) {
	yrcdyrcd_server* _tmp0_ = NULL;
	gchar** _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	const gchar* _tmp2_ = NULL;
	yrcdyrcd_channel* _tmp3_ = NULL;
	yrcdyrcd_channel* _tmp4_ = NULL;
	gboolean _tmp5_ = FALSE;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	_tmp0_ = self->server;
	_tmp1_ = args;
	_tmp1__length1 = args_length1;
	_tmp2_ = _tmp1_[1];
	_tmp3_ = yrcd_yrcd_server_get_channel_by_name (_tmp0_, _tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = _tmp4_ == NULL;
	_g_object_unref0 (_tmp4_);
	if (_tmp5_) {
		gint cid = 0;
		yrcdyrcd_server* _tmp6_ = NULL;
		gint _tmp7_ = 0;
		yrcdyrcd_channel* newchan = NULL;
		gint _tmp8_ = 0;
		yrcdyrcd_channel* _tmp9_ = NULL;
		yrcdyrcd_channel* _tmp10_ = NULL;
		gchar** _tmp11_ = NULL;
		gint _tmp11__length1 = 0;
		const gchar* _tmp12_ = NULL;
		yrcdyrcd_server* _tmp13_ = NULL;
		GeeHashMap* _tmp14_ = NULL;
		gint _tmp15_ = 0;
		yrcdyrcd_channel* _tmp16_ = NULL;
		yrcdyrcd_user* _tmp17_ = NULL;
		yrcdyrcd_channel* _tmp18_ = NULL;
		_tmp6_ = self->server;
		_tmp7_ = yrcd_yrcd_server_new_cid (_tmp6_);
		cid = _tmp7_;
		_tmp8_ = cid;
		_tmp9_ = yrcd_yrcd_channel_new (_tmp8_);
		newchan = _tmp9_;
		_tmp10_ = newchan;
		_tmp11_ = args;
		_tmp11__length1 = args_length1;
		_tmp12_ = _tmp11_[1];
		yrcd_yrcd_channel_set_name (_tmp10_, _tmp12_);
		_tmp13_ = self->server;
		_tmp14_ = _tmp13_->channellist;
		_tmp15_ = cid;
		_tmp16_ = newchan;
		gee_abstract_map_set ((GeeAbstractMap*) _tmp14_, (gpointer) ((gintptr) _tmp15_), _tmp16_);
		_tmp17_ = user;
		_tmp18_ = newchan;
		yrcd_yrcd_user_join (_tmp17_, _tmp18_);
		_g_object_unref0 (newchan);
	}
}


static gboolean string_contains (const gchar* self, const gchar* needle) {
	gboolean result = FALSE;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	_tmp0_ = needle;
	_tmp1_ = strstr ((gchar*) self, (gchar*) _tmp0_);
	result = _tmp1_ != NULL;
	return result;
}


void yrcd_yrcd_router_privmsg_handler (yrcdyrcd_router* self, yrcdyrcd_user* user, gchar** args, int args_length1) {
	gchar** _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	_tmp0_ = args;
	_tmp0__length1 = args_length1;
	if (_tmp0__length1 < 2) {
	} else {
		gchar** _tmp1_ = NULL;
		gint _tmp1__length1 = 0;
		_tmp1_ = args;
		_tmp1__length1 = args_length1;
		if (_tmp1__length1 < 3) {
		} else {
			yrcdyrcd_server* _tmp7_ = NULL;
			{
				const gchar** k_collection = NULL;
				gint k_collection_length1 = 0;
				gint _k_collection_size_ = 0;
				gint k_it = 0;
				k_collection = YRCD_YRCD_CONSTANTS_chan_prefixes;
				k_collection_length1 = G_N_ELEMENTS (YRCD_YRCD_CONSTANTS_chan_prefixes);
				for (k_it = 0; k_it < G_N_ELEMENTS (YRCD_YRCD_CONSTANTS_chan_prefixes); k_it = k_it + 1) {
					gchar* _tmp2_ = NULL;
					gchar* k = NULL;
					_tmp2_ = g_strdup (k_collection[k_it]);
					k = _tmp2_;
					{
						gchar** _tmp3_ = NULL;
						gint _tmp3__length1 = 0;
						const gchar* _tmp4_ = NULL;
						const gchar* _tmp5_ = NULL;
						gboolean _tmp6_ = FALSE;
						_tmp3_ = args;
						_tmp3__length1 = args_length1;
						_tmp4_ = _tmp3_[1];
						_tmp5_ = k;
						_tmp6_ = string_contains (_tmp4_, _tmp5_);
						if (_tmp6_) {
							_g_free0 (k);
							return;
						}
						_g_free0 (k);
					}
				}
			}
			_tmp7_ = self->server;
			if (yrcd_yrcd_server_get_user_by_nick == NULL) {
			}
			return;
		}
	}
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


static void yrcd_yrcd_router_class_init (yrcdyrcd_routerClass * klass) {
	yrcd_yrcd_router_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = yrcd_yrcd_router_finalize;
}


static void yrcd_yrcd_router_instance_init (yrcdyrcd_router * self) {
}


static void yrcd_yrcd_router_finalize (GObject* obj) {
	yrcdyrcd_router * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, YRCD_TYPE_YRCD_ROUTER, yrcdyrcd_router);
	_g_object_unref0 (self->server);
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



