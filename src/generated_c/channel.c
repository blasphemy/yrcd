/* channel.c generated by valac 0.24.0, the Vala compiler
 * generated from channel.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>


#define YRCD_TYPE_YRCD_CHANNEL (yrcd_yrcd_channel_get_type ())
#define YRCD_YRCD_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channel))
#define YRCD_YRCD_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channelClass))
#define YRCD_IS_YRCD_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_CHANNEL))
#define YRCD_IS_YRCD_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_CHANNEL))
#define YRCD_YRCD_CHANNEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channelClass))

typedef struct _yrcdyrcd_channel yrcdyrcd_channel;
typedef struct _yrcdyrcd_channelClass yrcdyrcd_channelClass;
typedef struct _yrcdyrcd_channelPrivate yrcdyrcd_channelPrivate;

#define YRCD_TYPE_YRCD_SERVER (yrcd_yrcd_server_get_type ())
#define YRCD_YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_server))
#define YRCD_YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverClass))
#define YRCD_IS_YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_SERVER))
#define YRCD_IS_YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_SERVER))
#define YRCD_YRCD_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverClass))

typedef struct _yrcdyrcd_server yrcdyrcd_server;
typedef struct _yrcdyrcd_serverClass yrcdyrcd_serverClass;

#define YRCD_TYPE_YRCD_USER (yrcd_yrcd_user_get_type ())
#define YRCD_YRCD_USER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_USER, yrcdyrcd_user))
#define YRCD_YRCD_USER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_USER, yrcdyrcd_userClass))
#define YRCD_IS_YRCD_USER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_USER))
#define YRCD_IS_YRCD_USER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_USER))
#define YRCD_YRCD_USER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_USER, yrcdyrcd_userClass))

typedef struct _yrcdyrcd_user yrcdyrcd_user;
typedef struct _yrcdyrcd_userClass yrcdyrcd_userClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))
typedef struct _yrcdyrcd_serverPrivate yrcdyrcd_serverPrivate;

#define YRCD_TYPE_YRCD_NUMERIC_WRAPPER (yrcd_yrcd_numeric_wrapper_get_type ())
#define YRCD_YRCD_NUMERIC_WRAPPER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_NUMERIC_WRAPPER, yrcdyrcd_numeric_wrapper))
#define YRCD_YRCD_NUMERIC_WRAPPER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_NUMERIC_WRAPPER, yrcdyrcd_numeric_wrapperClass))
#define YRCD_IS_YRCD_NUMERIC_WRAPPER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_NUMERIC_WRAPPER))
#define YRCD_IS_YRCD_NUMERIC_WRAPPER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_NUMERIC_WRAPPER))
#define YRCD_YRCD_NUMERIC_WRAPPER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_NUMERIC_WRAPPER, yrcdyrcd_numeric_wrapperClass))

typedef struct _yrcdyrcd_numeric_wrapper yrcdyrcd_numeric_wrapper;
typedef struct _yrcdyrcd_numeric_wrapperClass yrcdyrcd_numeric_wrapperClass;

#define YRCD_TYPE_YRCD_CONFIG (yrcd_yrcd_config_get_type ())
#define YRCD_YRCD_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_CONFIG, yrcdyrcd_config))
#define YRCD_YRCD_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_CONFIG, yrcdyrcd_configClass))
#define YRCD_IS_YRCD_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_CONFIG))
#define YRCD_IS_YRCD_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_CONFIG))
#define YRCD_YRCD_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_CONFIG, yrcdyrcd_configClass))

typedef struct _yrcdyrcd_config yrcdyrcd_config;
typedef struct _yrcdyrcd_configClass yrcdyrcd_configClass;
#define _g_date_time_unref0(var) ((var == NULL) ? NULL : (var = (g_date_time_unref (var), NULL)))
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))
typedef struct _yrcdyrcd_userPrivate yrcdyrcd_userPrivate;

struct _yrcdyrcd_channel {
	GObject parent_instance;
	yrcdyrcd_channelPrivate * priv;
	gchar** modes;
	gint modes_length1;
	gint _modes_size_;
	gchar* topic;
	gint64 epoch;
	gint64 topictime;
	gchar* topic_host;
	yrcdyrcd_server* server;
	GList* users;
	guint timer;
};

struct _yrcdyrcd_channelClass {
	GObjectClass parent_class;
};

struct _yrcdyrcd_channelPrivate {
	gchar* _name;
};

struct _yrcdyrcd_server {
	GObject parent_instance;
	yrcdyrcd_serverPrivate * priv;
	GeeHashMap* userlist;
	GeeHashMap* channellist;
	gint64 epoch;
	gint max_users;
	yrcdyrcd_numeric_wrapper* numeric_wrapper;
	yrcdyrcd_config* config;
};

struct _yrcdyrcd_serverClass {
	GObjectClass parent_class;
};

struct _yrcdyrcd_user {
	GObject parent_instance;
	yrcdyrcd_userPrivate * priv;
	gchar* ip;
	gchar* host;
	GeeHashMap* user_chanels;
};

struct _yrcdyrcd_userClass {
	GObjectClass parent_class;
};


static gpointer yrcd_yrcd_channel_parent_class = NULL;

GType yrcd_yrcd_channel_get_type (void) G_GNUC_CONST;
GType yrcd_yrcd_server_get_type (void) G_GNUC_CONST;
GType yrcd_yrcd_user_get_type (void) G_GNUC_CONST;
#define YRCD_YRCD_CHANNEL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channelPrivate))
enum  {
	YRCD_YRCD_CHANNEL_DUMMY_PROPERTY,
	YRCD_YRCD_CHANNEL_NAME
};
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);
yrcdyrcd_channel* yrcd_yrcd_channel_new (yrcdyrcd_server* _server, const gchar* _name);
yrcdyrcd_channel* yrcd_yrcd_channel_construct (GType object_type, yrcdyrcd_server* _server, const gchar* _name);
void yrcd_yrcd_channel_set_topic (yrcdyrcd_channel* self, const gchar* newtopic, const gchar* hostmask);
GType yrcd_yrcd_numeric_wrapper_get_type (void) G_GNUC_CONST;
GType yrcd_yrcd_config_get_type (void) G_GNUC_CONST;
const gchar* yrcd_yrcd_config_get_sname (yrcdyrcd_config* self);
void yrcd_yrcd_channel_set_name (yrcdyrcd_channel* self, const gchar* value);
void yrcd_yrcd_server_log (yrcdyrcd_server* self, const gchar* msg);
const gchar* yrcd_yrcd_channel_get_name (yrcdyrcd_channel* self);
void yrcd_yrcd_channel_check_users (yrcdyrcd_channel* self);
static gboolean __lambda4_ (yrcdyrcd_channel* self);
void yrcd_yrcd_server_remove_channel (yrcdyrcd_server* self, const gchar* name);
static gboolean ___lambda4__gsource_func (gpointer self);
gboolean yrcd_yrcd_channel_add_user (yrcdyrcd_channel* self, yrcdyrcd_user* user);
const gchar* yrcd_yrcd_user_get_nick (yrcdyrcd_user* self);
gchar* yrcd_yrcd_user_get_hostmask (yrcdyrcd_user* self);
void yrcd_yrcd_user_send_line (yrcdyrcd_user* self, const gchar* msg);
void yrcd_yrcd_user_fire_numeric (yrcdyrcd_user* self, gint numeric, ...);
#define YRCD_RPL_TOPIC 332
#define YRCD_RPL_TOPICWHOTIME 333
void yrcd_yrcd_channel_fire_names (yrcdyrcd_channel* self, yrcdyrcd_user* user);
void yrcd_yrcd_channel_quit (yrcdyrcd_channel* self, yrcdyrcd_user* user, const gchar* msg);
void yrcd_yrcd_channel_part (yrcdyrcd_channel* self, yrcdyrcd_user* user, const gchar* msg);
#define YRCD_RPL_NAMEPLY 353
#define YRCD_RPL_ENDOFNAMES 366
void yrcd_yrcd_channel_privmsg (yrcdyrcd_channel* self, yrcdyrcd_user* user, const gchar* msg);
void yrcd_yrcd_channel_who_response (yrcdyrcd_channel* self, yrcdyrcd_user* user);
#define YRCD_RPL_WHOREPLY 352
const gchar* yrcd_yrcd_user_get_ident (yrcdyrcd_user* self);
const gchar* yrcd_yrcd_user_get_realname (yrcdyrcd_user* self);
#define YRCD_RPL_ENDOFWHO 315
static void yrcd_yrcd_channel_finalize (GObject* obj);
static void _vala_yrcd_yrcd_channel_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_yrcd_yrcd_channel_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


yrcdyrcd_channel* yrcd_yrcd_channel_construct (GType object_type, yrcdyrcd_server* _server, const gchar* _name) {
	yrcdyrcd_channel * self = NULL;
	yrcdyrcd_server* _tmp0_ = NULL;
	yrcdyrcd_server* _tmp1_ = NULL;
	yrcdyrcd_server* _tmp2_ = NULL;
	yrcdyrcd_config* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	const gchar* _tmp5_ = NULL;
	GDateTime* _tmp6_ = NULL;
	GDateTime* _tmp7_ = NULL;
	gint64 _tmp8_ = 0LL;
	const gchar* _tmp9_ = NULL;
	yrcdyrcd_server* _tmp10_ = NULL;
	const gchar* _tmp11_ = NULL;
	const gchar* _tmp12_ = NULL;
	gchar* _tmp13_ = NULL;
	gchar* _tmp14_ = NULL;
	g_return_val_if_fail (_server != NULL, NULL);
	g_return_val_if_fail (_name != NULL, NULL);
	self = (yrcdyrcd_channel*) g_object_new (object_type, NULL);
	_tmp0_ = _server;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->server);
	self->server = _tmp1_;
	_tmp2_ = self->server;
	_tmp3_ = _tmp2_->config;
	_tmp4_ = yrcd_yrcd_config_get_sname (_tmp3_);
	_tmp5_ = _tmp4_;
	yrcd_yrcd_channel_set_topic (self, "", _tmp5_);
	_tmp6_ = g_date_time_new_now_utc ();
	_tmp7_ = _tmp6_;
	_tmp8_ = g_date_time_to_unix (_tmp7_);
	self->epoch = _tmp8_;
	_g_date_time_unref0 (_tmp7_);
	_tmp9_ = _name;
	yrcd_yrcd_channel_set_name (self, _tmp9_);
	_tmp10_ = self->server;
	_tmp11_ = self->priv->_name;
	_tmp12_ = string_to_string (_tmp11_);
	_tmp13_ = g_strconcat ("New channel created ", _tmp12_, NULL);
	_tmp14_ = _tmp13_;
	yrcd_yrcd_server_log (_tmp10_, _tmp14_);
	_g_free0 (_tmp14_);
	__g_list_free__g_object_unref0_0 (self->users);
	self->users = NULL;
	yrcd_yrcd_channel_check_users (self);
	return self;
}


yrcdyrcd_channel* yrcd_yrcd_channel_new (yrcdyrcd_server* _server, const gchar* _name) {
	return yrcd_yrcd_channel_construct (YRCD_TYPE_YRCD_CHANNEL, _server, _name);
}


static gboolean __lambda4_ (yrcdyrcd_channel* self) {
	gboolean result = FALSE;
	GList* _tmp0_ = NULL;
	guint _tmp1_ = 0U;
	_tmp0_ = self->users;
	_tmp1_ = g_list_length (_tmp0_);
	if (_tmp1_ < ((guint) 1)) {
		yrcdyrcd_server* _tmp2_ = NULL;
		const gchar* _tmp3_ = NULL;
		guint _tmp4_ = 0U;
		yrcdyrcd_server* _tmp5_ = NULL;
		const gchar* _tmp6_ = NULL;
		const gchar* _tmp7_ = NULL;
		gchar* _tmp8_ = NULL;
		gchar* _tmp9_ = NULL;
		_tmp2_ = self->server;
		_tmp3_ = self->priv->_name;
		yrcd_yrcd_server_remove_channel (_tmp2_, _tmp3_);
		_tmp4_ = self->timer;
		g_source_remove (_tmp4_);
		_tmp5_ = self->server;
		_tmp6_ = self->priv->_name;
		_tmp7_ = string_to_string (_tmp6_);
		_tmp8_ = g_strconcat ("channel ", _tmp7_, " has no users, destroying", NULL);
		_tmp9_ = _tmp8_;
		yrcd_yrcd_server_log (_tmp5_, _tmp9_);
		_g_free0 (_tmp9_);
		result = FALSE;
		return result;
	} else {
		result = TRUE;
		return result;
	}
}


static gboolean ___lambda4__gsource_func (gpointer self) {
	gboolean result;
	result = __lambda4_ ((yrcdyrcd_channel*) self);
	return result;
}


void yrcd_yrcd_channel_check_users (yrcdyrcd_channel* self) {
	guint _tmp0_ = 0U;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) 30, ___lambda4__gsource_func, g_object_ref (self), g_object_unref);
	self->timer = _tmp0_;
}


gboolean yrcd_yrcd_channel_add_user (yrcdyrcd_channel* self, yrcdyrcd_user* user) {
	gboolean result = FALSE;
	GList* _tmp0_ = NULL;
	yrcdyrcd_user* _tmp1_ = NULL;
	GList* _tmp2_ = NULL;
	yrcdyrcd_user* _tmp14_ = NULL;
	yrcdyrcd_user* _tmp15_ = NULL;
	GList* _tmp16_ = NULL;
	yrcdyrcd_user* _tmp26_ = NULL;
	const gchar* _tmp27_ = NULL;
	const gchar* _tmp28_ = NULL;
	yrcdyrcd_user* _tmp29_ = NULL;
	const gchar* _tmp30_ = NULL;
	const gchar* _tmp31_ = NULL;
	gint64 _tmp32_ = 0LL;
	yrcdyrcd_user* _tmp33_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (user != NULL, FALSE);
	_tmp0_ = self->users;
	_tmp1_ = user;
	_tmp2_ = g_list_find (_tmp0_, _tmp1_);
	if (_tmp2_ != NULL) {
		gchar* nick = NULL;
		yrcdyrcd_user* _tmp3_ = NULL;
		const gchar* _tmp4_ = NULL;
		const gchar* _tmp5_ = NULL;
		gchar* _tmp6_ = NULL;
		yrcdyrcd_server* _tmp7_ = NULL;
		const gchar* _tmp8_ = NULL;
		const gchar* _tmp9_ = NULL;
		const gchar* _tmp10_ = NULL;
		const gchar* _tmp11_ = NULL;
		gchar* _tmp12_ = NULL;
		gchar* _tmp13_ = NULL;
		_tmp3_ = user;
		_tmp4_ = yrcd_yrcd_user_get_nick (_tmp3_);
		_tmp5_ = _tmp4_;
		_tmp6_ = g_strdup (_tmp5_);
		nick = _tmp6_;
		_tmp7_ = self->server;
		_tmp8_ = nick;
		_tmp9_ = string_to_string (_tmp8_);
		_tmp10_ = self->priv->_name;
		_tmp11_ = string_to_string (_tmp10_);
		_tmp12_ = g_strconcat ("user ", _tmp9_, " attempted to join ", _tmp11_, " while already joined... doing nothing", NULL);
		_tmp13_ = _tmp12_;
		yrcd_yrcd_server_log (_tmp7_, _tmp13_);
		_g_free0 (_tmp13_);
		result = FALSE;
		_g_free0 (nick);
		return result;
	}
	_tmp14_ = user;
	_tmp15_ = _g_object_ref0 (_tmp14_);
	self->users = g_list_append (self->users, _tmp15_);
	_tmp16_ = self->users;
	{
		GList* k_collection = NULL;
		GList* k_it = NULL;
		k_collection = _tmp16_;
		for (k_it = k_collection; k_it != NULL; k_it = k_it->next) {
			yrcdyrcd_user* _tmp17_ = NULL;
			yrcdyrcd_user* k = NULL;
			_tmp17_ = _g_object_ref0 ((yrcdyrcd_user*) k_it->data);
			k = _tmp17_;
			{
				gchar* msg = NULL;
				yrcdyrcd_user* _tmp18_ = NULL;
				gchar* _tmp19_ = NULL;
				gchar* _tmp20_ = NULL;
				const gchar* _tmp21_ = NULL;
				gchar* _tmp22_ = NULL;
				gchar* _tmp23_ = NULL;
				yrcdyrcd_user* _tmp24_ = NULL;
				const gchar* _tmp25_ = NULL;
				_tmp18_ = user;
				_tmp19_ = yrcd_yrcd_user_get_hostmask (_tmp18_);
				_tmp20_ = _tmp19_;
				_tmp21_ = self->priv->_name;
				_tmp22_ = g_strdup_printf (":%s JOIN %s", _tmp20_, _tmp21_);
				_tmp23_ = _tmp22_;
				_g_free0 (_tmp20_);
				msg = _tmp23_;
				_tmp24_ = k;
				_tmp25_ = msg;
				yrcd_yrcd_user_send_line (_tmp24_, _tmp25_);
				_g_free0 (msg);
				_g_object_unref0 (k);
			}
		}
	}
	_tmp26_ = user;
	_tmp27_ = self->priv->_name;
	_tmp28_ = self->topic;
	yrcd_yrcd_user_fire_numeric (_tmp26_, YRCD_RPL_TOPIC, _tmp27_, _tmp28_, NULL);
	_tmp29_ = user;
	_tmp30_ = self->priv->_name;
	_tmp31_ = self->topic_host;
	_tmp32_ = self->topictime;
	yrcd_yrcd_user_fire_numeric (_tmp29_, YRCD_RPL_TOPICWHOTIME, _tmp30_, _tmp31_, _tmp32_, NULL);
	_tmp33_ = user;
	yrcd_yrcd_channel_fire_names (self, _tmp33_);
	result = TRUE;
	return result;
}


void yrcd_yrcd_channel_quit (yrcdyrcd_channel* self, yrcdyrcd_user* user, const gchar* msg) {
	GList* _tmp0_ = NULL;
	yrcdyrcd_user* _tmp9_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	g_return_if_fail (msg != NULL);
	_tmp0_ = self->users;
	{
		GList* k_collection = NULL;
		GList* k_it = NULL;
		k_collection = _tmp0_;
		for (k_it = k_collection; k_it != NULL; k_it = k_it->next) {
			yrcdyrcd_user* _tmp1_ = NULL;
			yrcdyrcd_user* k = NULL;
			_tmp1_ = _g_object_ref0 ((yrcdyrcd_user*) k_it->data);
			k = _tmp1_;
			{
				yrcdyrcd_user* _tmp2_ = NULL;
				yrcdyrcd_user* _tmp3_ = NULL;
				gchar* _tmp4_ = NULL;
				gchar* _tmp5_ = NULL;
				const gchar* _tmp6_ = NULL;
				gchar* _tmp7_ = NULL;
				gchar* _tmp8_ = NULL;
				_tmp2_ = k;
				_tmp3_ = user;
				_tmp4_ = yrcd_yrcd_user_get_hostmask (_tmp3_);
				_tmp5_ = _tmp4_;
				_tmp6_ = msg;
				_tmp7_ = g_strdup_printf (":%s QUIT :%s", _tmp5_, _tmp6_);
				_tmp8_ = _tmp7_;
				yrcd_yrcd_user_send_line (_tmp2_, _tmp8_);
				_g_free0 (_tmp8_);
				_g_free0 (_tmp5_);
				_g_object_unref0 (k);
			}
		}
	}
	_tmp9_ = user;
	self->users = g_list_remove (self->users, _tmp9_);
}


void yrcd_yrcd_channel_part (yrcdyrcd_channel* self, yrcdyrcd_user* user, const gchar* msg) {
	GList* _tmp0_ = NULL;
	yrcdyrcd_user* _tmp10_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	g_return_if_fail (msg != NULL);
	_tmp0_ = self->users;
	{
		GList* k_collection = NULL;
		GList* k_it = NULL;
		k_collection = _tmp0_;
		for (k_it = k_collection; k_it != NULL; k_it = k_it->next) {
			yrcdyrcd_user* _tmp1_ = NULL;
			yrcdyrcd_user* k = NULL;
			_tmp1_ = _g_object_ref0 ((yrcdyrcd_user*) k_it->data);
			k = _tmp1_;
			{
				yrcdyrcd_user* _tmp2_ = NULL;
				yrcdyrcd_user* _tmp3_ = NULL;
				gchar* _tmp4_ = NULL;
				gchar* _tmp5_ = NULL;
				const gchar* _tmp6_ = NULL;
				const gchar* _tmp7_ = NULL;
				gchar* _tmp8_ = NULL;
				gchar* _tmp9_ = NULL;
				_tmp2_ = k;
				_tmp3_ = user;
				_tmp4_ = yrcd_yrcd_user_get_hostmask (_tmp3_);
				_tmp5_ = _tmp4_;
				_tmp6_ = self->priv->_name;
				_tmp7_ = msg;
				_tmp8_ = g_strdup_printf (":%s PART %s :%s", _tmp5_, _tmp6_, _tmp7_);
				_tmp9_ = _tmp8_;
				yrcd_yrcd_user_send_line (_tmp2_, _tmp9_);
				_g_free0 (_tmp9_);
				_g_free0 (_tmp5_);
				_g_object_unref0 (k);
			}
		}
	}
	_tmp10_ = user;
	self->users = g_list_remove (self->users, _tmp10_);
}


void yrcd_yrcd_channel_set_topic (yrcdyrcd_channel* self, const gchar* newtopic, const gchar* hostmask) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (newtopic != NULL);
	g_return_if_fail (hostmask != NULL);
	_tmp0_ = newtopic;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->topic);
	self->topic = _tmp1_;
	_tmp2_ = hostmask;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 (self->topic_host);
	self->topic_host = _tmp3_;
}


static gchar* string_strip (const gchar* self) {
	gchar* result = NULL;
	gchar* _result_ = NULL;
	gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup (self);
	_result_ = _tmp0_;
	_tmp1_ = _result_;
	g_strstrip (_tmp1_);
	result = _result_;
	return result;
}


void yrcd_yrcd_channel_fire_names (yrcdyrcd_channel* self, yrcdyrcd_user* user) {
	GString* builder = NULL;
	GString* _tmp0_ = NULL;
	GList* _tmp1_ = NULL;
	gchar* resp = NULL;
	GString* _tmp8_ = NULL;
	const gchar* _tmp9_ = NULL;
	gchar* _tmp10_ = NULL;
	yrcdyrcd_user* _tmp11_ = NULL;
	const gchar* _tmp12_ = NULL;
	yrcdyrcd_user* _tmp13_ = NULL;
	const gchar* _tmp14_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	_tmp0_ = g_string_new ("");
	builder = _tmp0_;
	_tmp1_ = self->users;
	{
		GList* k_collection = NULL;
		GList* k_it = NULL;
		k_collection = _tmp1_;
		for (k_it = k_collection; k_it != NULL; k_it = k_it->next) {
			yrcdyrcd_user* _tmp2_ = NULL;
			yrcdyrcd_user* k = NULL;
			_tmp2_ = _g_object_ref0 ((yrcdyrcd_user*) k_it->data);
			k = _tmp2_;
			{
				GString* _tmp3_ = NULL;
				yrcdyrcd_user* _tmp4_ = NULL;
				const gchar* _tmp5_ = NULL;
				const gchar* _tmp6_ = NULL;
				GString* _tmp7_ = NULL;
				_tmp3_ = builder;
				_tmp4_ = k;
				_tmp5_ = yrcd_yrcd_user_get_nick (_tmp4_);
				_tmp6_ = _tmp5_;
				g_string_append (_tmp3_, _tmp6_);
				_tmp7_ = builder;
				g_string_append (_tmp7_, " ");
				_g_object_unref0 (k);
			}
		}
	}
	_tmp8_ = builder;
	_tmp9_ = _tmp8_->str;
	_tmp10_ = string_strip (_tmp9_);
	resp = _tmp10_;
	_tmp11_ = user;
	_tmp12_ = self->priv->_name;
	yrcd_yrcd_user_fire_numeric (_tmp11_, YRCD_RPL_NAMEPLY, _tmp12_, resp, NULL);
	_tmp13_ = user;
	_tmp14_ = self->priv->_name;
	yrcd_yrcd_user_fire_numeric (_tmp13_, YRCD_RPL_ENDOFNAMES, _tmp14_, NULL);
	_g_free0 (resp);
	_g_string_free0 (builder);
}


void yrcd_yrcd_channel_privmsg (yrcdyrcd_channel* self, yrcdyrcd_user* user, const gchar* msg) {
	gchar* to_send = NULL;
	yrcdyrcd_user* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	yrcdyrcd_server* _tmp7_ = NULL;
	const gchar* _tmp8_ = NULL;
	const gchar* _tmp9_ = NULL;
	const gchar* _tmp10_ = NULL;
	const gchar* _tmp11_ = NULL;
	gchar* _tmp12_ = NULL;
	gchar* _tmp13_ = NULL;
	GList* _tmp14_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	g_return_if_fail (msg != NULL);
	_tmp0_ = user;
	_tmp1_ = yrcd_yrcd_user_get_hostmask (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = self->priv->_name;
	_tmp4_ = msg;
	_tmp5_ = g_strdup_printf (":%s PRIVMSG %s :%s", _tmp2_, _tmp3_, _tmp4_);
	_tmp6_ = _tmp5_;
	_g_free0 (_tmp2_);
	to_send = _tmp6_;
	_tmp7_ = self->server;
	_tmp8_ = self->priv->_name;
	_tmp9_ = string_to_string (_tmp8_);
	_tmp10_ = msg;
	_tmp11_ = string_to_string (_tmp10_);
	_tmp12_ = g_strconcat ("channel ", _tmp9_, " sending message ", _tmp11_, NULL);
	_tmp13_ = _tmp12_;
	yrcd_yrcd_server_log (_tmp7_, _tmp13_);
	_g_free0 (_tmp13_);
	_tmp14_ = self->users;
	{
		GList* k_collection = NULL;
		GList* k_it = NULL;
		k_collection = _tmp14_;
		for (k_it = k_collection; k_it != NULL; k_it = k_it->next) {
			yrcdyrcd_user* _tmp15_ = NULL;
			yrcdyrcd_user* k = NULL;
			_tmp15_ = _g_object_ref0 ((yrcdyrcd_user*) k_it->data);
			k = _tmp15_;
			{
				yrcdyrcd_user* _tmp16_ = NULL;
				yrcdyrcd_user* _tmp17_ = NULL;
				_tmp16_ = k;
				_tmp17_ = user;
				if (_tmp16_ != _tmp17_) {
					yrcdyrcd_user* _tmp18_ = NULL;
					const gchar* _tmp19_ = NULL;
					_tmp18_ = k;
					_tmp19_ = to_send;
					yrcd_yrcd_user_send_line (_tmp18_, _tmp19_);
				}
				_g_object_unref0 (k);
			}
		}
	}
	_g_free0 (to_send);
}


void yrcd_yrcd_channel_who_response (yrcdyrcd_channel* self, yrcdyrcd_user* user) {
	GList* _tmp0_ = NULL;
	yrcdyrcd_user* _tmp19_ = NULL;
	const gchar* _tmp20_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	_tmp0_ = self->users;
	{
		GList* k_collection = NULL;
		GList* k_it = NULL;
		k_collection = _tmp0_;
		for (k_it = k_collection; k_it != NULL; k_it = k_it->next) {
			yrcdyrcd_user* _tmp1_ = NULL;
			yrcdyrcd_user* k = NULL;
			_tmp1_ = _g_object_ref0 ((yrcdyrcd_user*) k_it->data);
			k = _tmp1_;
			{
				yrcdyrcd_user* _tmp2_ = NULL;
				const gchar* _tmp3_ = NULL;
				yrcdyrcd_user* _tmp4_ = NULL;
				const gchar* _tmp5_ = NULL;
				const gchar* _tmp6_ = NULL;
				yrcdyrcd_user* _tmp7_ = NULL;
				const gchar* _tmp8_ = NULL;
				yrcdyrcd_server* _tmp9_ = NULL;
				yrcdyrcd_config* _tmp10_ = NULL;
				const gchar* _tmp11_ = NULL;
				const gchar* _tmp12_ = NULL;
				yrcdyrcd_user* _tmp13_ = NULL;
				const gchar* _tmp14_ = NULL;
				const gchar* _tmp15_ = NULL;
				yrcdyrcd_user* _tmp16_ = NULL;
				const gchar* _tmp17_ = NULL;
				const gchar* _tmp18_ = NULL;
				_tmp2_ = user;
				_tmp3_ = self->priv->_name;
				_tmp4_ = k;
				_tmp5_ = yrcd_yrcd_user_get_ident (_tmp4_);
				_tmp6_ = _tmp5_;
				_tmp7_ = k;
				_tmp8_ = _tmp7_->host;
				_tmp9_ = self->server;
				_tmp10_ = _tmp9_->config;
				_tmp11_ = yrcd_yrcd_config_get_sname (_tmp10_);
				_tmp12_ = _tmp11_;
				_tmp13_ = k;
				_tmp14_ = yrcd_yrcd_user_get_nick (_tmp13_);
				_tmp15_ = _tmp14_;
				_tmp16_ = k;
				_tmp17_ = yrcd_yrcd_user_get_realname (_tmp16_);
				_tmp18_ = _tmp17_;
				yrcd_yrcd_user_fire_numeric (_tmp2_, YRCD_RPL_WHOREPLY, _tmp3_, _tmp6_, _tmp8_, _tmp12_, _tmp15_, "H", ":0", _tmp18_, NULL);
				_g_object_unref0 (k);
			}
		}
	}
	_tmp19_ = user;
	_tmp20_ = self->priv->_name;
	yrcd_yrcd_user_fire_numeric (_tmp19_, YRCD_RPL_ENDOFWHO, _tmp20_, NULL);
}


const gchar* yrcd_yrcd_channel_get_name (yrcdyrcd_channel* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}


void yrcd_yrcd_channel_set_name (yrcdyrcd_channel* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_name);
	self->priv->_name = _tmp1_;
	g_object_notify ((GObject *) self, "name");
}


static void yrcd_yrcd_channel_class_init (yrcdyrcd_channelClass * klass) {
	yrcd_yrcd_channel_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (yrcdyrcd_channelPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_yrcd_yrcd_channel_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_yrcd_yrcd_channel_set_property;
	G_OBJECT_CLASS (klass)->finalize = yrcd_yrcd_channel_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_YRCD_CHANNEL_NAME, g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void yrcd_yrcd_channel_instance_init (yrcdyrcd_channel * self) {
	self->priv = YRCD_YRCD_CHANNEL_GET_PRIVATE (self);
}


static void yrcd_yrcd_channel_finalize (GObject* obj) {
	yrcdyrcd_channel * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channel);
	_g_free0 (self->priv->_name);
	self->modes = (_vala_array_free (self->modes, self->modes_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (self->topic);
	_g_free0 (self->topic_host);
	_g_object_unref0 (self->server);
	__g_list_free__g_object_unref0_0 (self->users);
	G_OBJECT_CLASS (yrcd_yrcd_channel_parent_class)->finalize (obj);
}


GType yrcd_yrcd_channel_get_type (void) {
	static volatile gsize yrcd_yrcd_channel_type_id__volatile = 0;
	if (g_once_init_enter (&yrcd_yrcd_channel_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (yrcdyrcd_channelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) yrcd_yrcd_channel_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (yrcdyrcd_channel), 0, (GInstanceInitFunc) yrcd_yrcd_channel_instance_init, NULL };
		GType yrcd_yrcd_channel_type_id;
		yrcd_yrcd_channel_type_id = g_type_register_static (G_TYPE_OBJECT, "yrcdyrcd_channel", &g_define_type_info, 0);
		g_once_init_leave (&yrcd_yrcd_channel_type_id__volatile, yrcd_yrcd_channel_type_id);
	}
	return yrcd_yrcd_channel_type_id__volatile;
}


static void _vala_yrcd_yrcd_channel_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	yrcdyrcd_channel * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channel);
	switch (property_id) {
		case YRCD_YRCD_CHANNEL_NAME:
		g_value_set_string (value, yrcd_yrcd_channel_get_name (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_yrcd_yrcd_channel_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	yrcdyrcd_channel * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channel);
	switch (property_id) {
		case YRCD_YRCD_CHANNEL_NAME:
		yrcd_yrcd_channel_set_name (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
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



