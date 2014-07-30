/* channel.c generated by valac 0.24.0, the Vala compiler
 * generated from channel.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>


#define YRCD_TYPE_CHANNEL (yrcd_channel_get_type ())
#define YRCD_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_CHANNEL, yrcdChannel))
#define YRCD_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_CHANNEL, yrcdChannelClass))
#define YRCD_IS_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_CHANNEL))
#define YRCD_IS_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_CHANNEL))
#define YRCD_CHANNEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_CHANNEL, yrcdChannelClass))

typedef struct _yrcdChannel yrcdChannel;
typedef struct _yrcdChannelClass yrcdChannelClass;
typedef struct _yrcdChannelPrivate yrcdChannelPrivate;

#define YRCD_TYPE_SERVER (yrcd_server_get_type ())
#define YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_SERVER, yrcdServer))
#define YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_SERVER, yrcdServerClass))
#define YRCD_IS_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_SERVER))
#define YRCD_IS_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_SERVER))
#define YRCD_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_SERVER, yrcdServerClass))

typedef struct _yrcdServer yrcdServer;
typedef struct _yrcdServerClass yrcdServerClass;

#define YRCD_TYPE_USER (yrcd_user_get_type ())
#define YRCD_USER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_USER, yrcdUser))
#define YRCD_USER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_USER, yrcdUserClass))
#define YRCD_IS_USER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_USER))
#define YRCD_IS_USER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_USER))
#define YRCD_USER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_USER, yrcdUserClass))

typedef struct _yrcdUser yrcdUser;
typedef struct _yrcdUserClass yrcdUserClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))
typedef struct _yrcdServerPrivate yrcdServerPrivate;

#define YRCD_TYPE_NUMERIC_WRAPPER (yrcd_numeric_wrapper_get_type ())
#define YRCD_NUMERIC_WRAPPER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_NUMERIC_WRAPPER, yrcdNumericWrapper))
#define YRCD_NUMERIC_WRAPPER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_NUMERIC_WRAPPER, yrcdNumericWrapperClass))
#define YRCD_IS_NUMERIC_WRAPPER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_NUMERIC_WRAPPER))
#define YRCD_IS_NUMERIC_WRAPPER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_NUMERIC_WRAPPER))
#define YRCD_NUMERIC_WRAPPER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_NUMERIC_WRAPPER, yrcdNumericWrapperClass))

typedef struct _yrcdNumericWrapper yrcdNumericWrapper;
typedef struct _yrcdNumericWrapperClass yrcdNumericWrapperClass;

#define YRCD_TYPE_CONFIG (yrcd_config_get_type ())
#define YRCD_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_CONFIG, yrcdConfig))
#define YRCD_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_CONFIG, yrcdConfigClass))
#define YRCD_IS_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_CONFIG))
#define YRCD_IS_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_CONFIG))
#define YRCD_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_CONFIG, yrcdConfigClass))

typedef struct _yrcdConfig yrcdConfig;
typedef struct _yrcdConfigClass yrcdConfigClass;
#define _g_date_time_unref0(var) ((var == NULL) ? NULL : (var = (g_date_time_unref (var), NULL)))
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))
typedef struct _yrcdUserPrivate yrcdUserPrivate;

struct _yrcdChannel {
	GObject parent_instance;
	yrcdChannelPrivate * priv;
	gchar** modes;
	gint modes_length1;
	gint _modes_size_;
	gchar* topic;
	gint64 epoch;
	gint64 topictime;
	gchar* topic_host;
	yrcdServer* server;
	GList* users;
	guint timer;
};

struct _yrcdChannelClass {
	GObjectClass parent_class;
};

struct _yrcdChannelPrivate {
	gchar* _name;
};

struct _yrcdServer {
	GObject parent_instance;
	yrcdServerPrivate * priv;
	GeeHashMap* userlist;
	GeeHashMap* channellist;
	gint64 epoch;
	gint max_users;
	yrcdNumericWrapper* numeric_wrapper;
	yrcdConfig* config;
};

struct _yrcdServerClass {
	GObjectClass parent_class;
};

struct _yrcdUser {
	GObject parent_instance;
	yrcdUserPrivate * priv;
	gchar* ip;
	gchar* host;
	GeeHashMap* user_chanels;
	GList* asources;
};

struct _yrcdUserClass {
	GObjectClass parent_class;
};


static gpointer yrcd_channel_parent_class = NULL;

GType yrcd_channel_get_type (void) G_GNUC_CONST;
GType yrcd_server_get_type (void) G_GNUC_CONST;
GType yrcd_user_get_type (void) G_GNUC_CONST;
#define YRCD_CHANNEL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), YRCD_TYPE_CHANNEL, yrcdChannelPrivate))
enum  {
	YRCD_CHANNEL_DUMMY_PROPERTY,
	YRCD_CHANNEL_NAME
};
yrcdChannel* yrcd_channel_new (yrcdServer* _server, const gchar* _name);
yrcdChannel* yrcd_channel_construct (GType object_type, yrcdServer* _server, const gchar* _name);
void yrcd_channel_set_topic (yrcdChannel* self, const gchar* newtopic, const gchar* hostmask);
GType yrcd_numeric_wrapper_get_type (void) G_GNUC_CONST;
GType yrcd_config_get_type (void) G_GNUC_CONST;
const gchar* yrcd_config_get_sname (yrcdConfig* self);
void yrcd_channel_set_name (yrcdChannel* self, const gchar* value);
void yrcd_server_log (yrcdServer* self, const gchar* msg);
const gchar* yrcd_channel_get_name (yrcdChannel* self);
void yrcd_channel_check_users (yrcdChannel* self);
static gboolean __lambda5_ (yrcdChannel* self);
void yrcd_server_remove_channel (yrcdServer* self, const gchar* name);
static gboolean ___lambda5__gsource_func (gpointer self);
gboolean yrcd_channel_add_user (yrcdChannel* self, yrcdUser* user);
const gchar* yrcd_user_get_nick (yrcdUser* self);
gchar* yrcd_user_get_hostmask (yrcdUser* self);
void yrcd_user_send_line (yrcdUser* self, const gchar* msg, gint p);
void yrcd_user_fire_numeric (yrcdUser* self, gint numeric, ...);
#define YRCD_RPL_TOPIC 332
#define YRCD_RPL_TOPICWHOTIME 333
void yrcd_channel_fire_names (yrcdChannel* self, yrcdUser* user);
void yrcd_channel_remove_user (yrcdChannel* self, yrcdUser* user);
GList* yrcd_channel_get_users (yrcdChannel* self);
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);
void yrcd_channel_part (yrcdChannel* self, yrcdUser* user, const gchar* msg);
#define YRCD_RPL_NAMEPLY 353
#define YRCD_RPL_ENDOFNAMES 366
void yrcd_channel_privmsg (yrcdChannel* self, yrcdUser* user, const gchar* msg);
void yrcd_server_send_to_many (yrcdServer* self, GList* users, const gchar* msg, gint p);
void yrcd_channel_who_response (yrcdChannel* self, yrcdUser* user);
#define YRCD_RPL_WHOREPLY 352
const gchar* yrcd_user_get_ident (yrcdUser* self);
const gchar* yrcd_user_get_realname (yrcdUser* self);
#define YRCD_RPL_ENDOFWHO 315
static void yrcd_channel_finalize (GObject* obj);
static void _vala_yrcd_channel_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_yrcd_channel_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


yrcdChannel* yrcd_channel_construct (GType object_type, yrcdServer* _server, const gchar* _name) {
	yrcdChannel * self = NULL;
	yrcdServer* _tmp0_ = NULL;
	yrcdServer* _tmp1_ = NULL;
	yrcdServer* _tmp2_ = NULL;
	yrcdConfig* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	const gchar* _tmp5_ = NULL;
	GDateTime* _tmp6_ = NULL;
	GDateTime* _tmp7_ = NULL;
	gint64 _tmp8_ = 0LL;
	const gchar* _tmp9_ = NULL;
	yrcdServer* _tmp10_ = NULL;
	const gchar* _tmp11_ = NULL;
	const gchar* _tmp12_ = NULL;
	gchar* _tmp13_ = NULL;
	gchar* _tmp14_ = NULL;
	g_return_val_if_fail (_server != NULL, NULL);
	g_return_val_if_fail (_name != NULL, NULL);
	self = (yrcdChannel*) g_object_new (object_type, NULL);
	_tmp0_ = _server;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->server);
	self->server = _tmp1_;
	_tmp2_ = self->server;
	_tmp3_ = _tmp2_->config;
	_tmp4_ = yrcd_config_get_sname (_tmp3_);
	_tmp5_ = _tmp4_;
	yrcd_channel_set_topic (self, "", _tmp5_);
	_tmp6_ = g_date_time_new_now_utc ();
	_tmp7_ = _tmp6_;
	_tmp8_ = g_date_time_to_unix (_tmp7_);
	self->epoch = _tmp8_;
	_g_date_time_unref0 (_tmp7_);
	_tmp9_ = _name;
	yrcd_channel_set_name (self, _tmp9_);
	_tmp10_ = self->server;
	_tmp11_ = self->priv->_name;
	_tmp12_ = string_to_string (_tmp11_);
	_tmp13_ = g_strconcat ("New channel created ", _tmp12_, NULL);
	_tmp14_ = _tmp13_;
	yrcd_server_log (_tmp10_, _tmp14_);
	_g_free0 (_tmp14_);
	_g_list_free0 (self->users);
	self->users = NULL;
	yrcd_channel_check_users (self);
	return self;
}


yrcdChannel* yrcd_channel_new (yrcdServer* _server, const gchar* _name) {
	return yrcd_channel_construct (YRCD_TYPE_CHANNEL, _server, _name);
}


static gboolean __lambda5_ (yrcdChannel* self) {
	gboolean result = FALSE;
	GList* _tmp0_ = NULL;
	guint _tmp1_ = 0U;
	_tmp0_ = self->users;
	_tmp1_ = g_list_length (_tmp0_);
	if (_tmp1_ < ((guint) 1)) {
		yrcdServer* _tmp2_ = NULL;
		const gchar* _tmp3_ = NULL;
		guint _tmp4_ = 0U;
		yrcdServer* _tmp5_ = NULL;
		const gchar* _tmp6_ = NULL;
		const gchar* _tmp7_ = NULL;
		gchar* _tmp8_ = NULL;
		gchar* _tmp9_ = NULL;
		_tmp2_ = self->server;
		_tmp3_ = self->priv->_name;
		yrcd_server_remove_channel (_tmp2_, _tmp3_);
		_tmp4_ = self->timer;
		g_source_remove (_tmp4_);
		_tmp5_ = self->server;
		_tmp6_ = self->priv->_name;
		_tmp7_ = string_to_string (_tmp6_);
		_tmp8_ = g_strconcat ("channel ", _tmp7_, " has no users, destroying", NULL);
		_tmp9_ = _tmp8_;
		yrcd_server_log (_tmp5_, _tmp9_);
		_g_free0 (_tmp9_);
		result = FALSE;
		return result;
	} else {
		result = TRUE;
		return result;
	}
}


static gboolean ___lambda5__gsource_func (gpointer self) {
	gboolean result;
	result = __lambda5_ ((yrcdChannel*) self);
	return result;
}


void yrcd_channel_check_users (yrcdChannel* self) {
	guint _tmp0_ = 0U;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) 30, ___lambda5__gsource_func, g_object_ref (self), g_object_unref);
	self->timer = _tmp0_;
}


gboolean yrcd_channel_add_user (yrcdChannel* self, yrcdUser* user) {
	gboolean result = FALSE;
	GList* _tmp0_ = NULL;
	yrcdUser* _tmp1_ = NULL;
	GList* _tmp2_ = NULL;
	yrcdUser* _tmp14_ = NULL;
	GList* _tmp15_ = NULL;
	yrcdUser* _tmp25_ = NULL;
	const gchar* _tmp26_ = NULL;
	const gchar* _tmp27_ = NULL;
	yrcdUser* _tmp28_ = NULL;
	const gchar* _tmp29_ = NULL;
	const gchar* _tmp30_ = NULL;
	gint64 _tmp31_ = 0LL;
	yrcdUser* _tmp32_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (user != NULL, FALSE);
	_tmp0_ = self->users;
	_tmp1_ = user;
	_tmp2_ = g_list_find (_tmp0_, _tmp1_);
	if (_tmp2_ != NULL) {
		gchar* nick = NULL;
		yrcdUser* _tmp3_ = NULL;
		const gchar* _tmp4_ = NULL;
		const gchar* _tmp5_ = NULL;
		gchar* _tmp6_ = NULL;
		yrcdServer* _tmp7_ = NULL;
		const gchar* _tmp8_ = NULL;
		const gchar* _tmp9_ = NULL;
		const gchar* _tmp10_ = NULL;
		const gchar* _tmp11_ = NULL;
		gchar* _tmp12_ = NULL;
		gchar* _tmp13_ = NULL;
		_tmp3_ = user;
		_tmp4_ = yrcd_user_get_nick (_tmp3_);
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
		yrcd_server_log (_tmp7_, _tmp13_);
		_g_free0 (_tmp13_);
		result = FALSE;
		_g_free0 (nick);
		return result;
	}
	_tmp14_ = user;
	self->users = g_list_append (self->users, _tmp14_);
	_tmp15_ = self->users;
	{
		GList* k_collection = NULL;
		GList* k_it = NULL;
		k_collection = _tmp15_;
		for (k_it = k_collection; k_it != NULL; k_it = k_it->next) {
			yrcdUser* _tmp16_ = NULL;
			yrcdUser* k = NULL;
			_tmp16_ = _g_object_ref0 ((yrcdUser*) k_it->data);
			k = _tmp16_;
			{
				gchar* msg = NULL;
				yrcdUser* _tmp17_ = NULL;
				gchar* _tmp18_ = NULL;
				gchar* _tmp19_ = NULL;
				const gchar* _tmp20_ = NULL;
				gchar* _tmp21_ = NULL;
				gchar* _tmp22_ = NULL;
				yrcdUser* _tmp23_ = NULL;
				const gchar* _tmp24_ = NULL;
				_tmp17_ = user;
				_tmp18_ = yrcd_user_get_hostmask (_tmp17_);
				_tmp19_ = _tmp18_;
				_tmp20_ = self->priv->_name;
				_tmp21_ = g_strdup_printf (":%s JOIN %s", _tmp19_, _tmp20_);
				_tmp22_ = _tmp21_;
				_g_free0 (_tmp19_);
				msg = _tmp22_;
				_tmp23_ = k;
				_tmp24_ = msg;
				yrcd_user_send_line (_tmp23_, _tmp24_, G_PRIORITY_LOW);
				_g_free0 (msg);
				_g_object_unref0 (k);
			}
		}
	}
	_tmp25_ = user;
	_tmp26_ = self->priv->_name;
	_tmp27_ = self->topic;
	yrcd_user_fire_numeric (_tmp25_, YRCD_RPL_TOPIC, _tmp26_, _tmp27_, NULL);
	_tmp28_ = user;
	_tmp29_ = self->priv->_name;
	_tmp30_ = self->topic_host;
	_tmp31_ = self->topictime;
	yrcd_user_fire_numeric (_tmp28_, YRCD_RPL_TOPICWHOTIME, _tmp29_, _tmp30_, _tmp31_, NULL);
	_tmp32_ = user;
	yrcd_channel_fire_names (self, _tmp32_);
	result = TRUE;
	return result;
}


void yrcd_channel_remove_user (yrcdChannel* self, yrcdUser* user) {
	yrcdUser* _tmp0_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	_tmp0_ = user;
	self->users = g_list_remove (self->users, _tmp0_);
}


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


GList* yrcd_channel_get_users (yrcdChannel* self) {
	GList* result = NULL;
	GList* response = NULL;
	GList* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	response = NULL;
	_tmp0_ = self->users;
	{
		GList* k_collection = NULL;
		GList* k_it = NULL;
		k_collection = _tmp0_;
		for (k_it = k_collection; k_it != NULL; k_it = k_it->next) {
			yrcdUser* _tmp1_ = NULL;
			yrcdUser* k = NULL;
			_tmp1_ = _g_object_ref0 ((yrcdUser*) k_it->data);
			k = _tmp1_;
			{
				yrcdUser* _tmp2_ = NULL;
				yrcdUser* _tmp3_ = NULL;
				_tmp2_ = k;
				_tmp3_ = _g_object_ref0 (_tmp2_);
				response = g_list_append (response, _tmp3_);
				_g_object_unref0 (k);
			}
		}
	}
	result = response;
	return result;
}


void yrcd_channel_part (yrcdChannel* self, yrcdUser* user, const gchar* msg) {
	GList* _tmp0_ = NULL;
	yrcdUser* _tmp10_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	g_return_if_fail (msg != NULL);
	_tmp0_ = self->users;
	{
		GList* k_collection = NULL;
		GList* k_it = NULL;
		k_collection = _tmp0_;
		for (k_it = k_collection; k_it != NULL; k_it = k_it->next) {
			yrcdUser* _tmp1_ = NULL;
			yrcdUser* k = NULL;
			_tmp1_ = _g_object_ref0 ((yrcdUser*) k_it->data);
			k = _tmp1_;
			{
				yrcdUser* _tmp2_ = NULL;
				yrcdUser* _tmp3_ = NULL;
				gchar* _tmp4_ = NULL;
				gchar* _tmp5_ = NULL;
				const gchar* _tmp6_ = NULL;
				const gchar* _tmp7_ = NULL;
				gchar* _tmp8_ = NULL;
				gchar* _tmp9_ = NULL;
				_tmp2_ = k;
				_tmp3_ = user;
				_tmp4_ = yrcd_user_get_hostmask (_tmp3_);
				_tmp5_ = _tmp4_;
				_tmp6_ = self->priv->_name;
				_tmp7_ = msg;
				_tmp8_ = g_strdup_printf (":%s PART %s :%s", _tmp5_, _tmp6_, _tmp7_);
				_tmp9_ = _tmp8_;
				yrcd_user_send_line (_tmp2_, _tmp9_, G_PRIORITY_LOW);
				_g_free0 (_tmp9_);
				_g_free0 (_tmp5_);
				_g_object_unref0 (k);
			}
		}
	}
	_tmp10_ = user;
	self->users = g_list_remove (self->users, _tmp10_);
}


void yrcd_channel_set_topic (yrcdChannel* self, const gchar* newtopic, const gchar* hostmask) {
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


void yrcd_channel_fire_names (yrcdChannel* self, yrcdUser* user) {
	GString* builder = NULL;
	GString* _tmp0_ = NULL;
	GList* _tmp1_ = NULL;
	gchar* resp = NULL;
	GString* _tmp8_ = NULL;
	const gchar* _tmp9_ = NULL;
	gchar* _tmp10_ = NULL;
	yrcdUser* _tmp11_ = NULL;
	const gchar* _tmp12_ = NULL;
	yrcdUser* _tmp13_ = NULL;
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
			yrcdUser* _tmp2_ = NULL;
			yrcdUser* k = NULL;
			_tmp2_ = _g_object_ref0 ((yrcdUser*) k_it->data);
			k = _tmp2_;
			{
				GString* _tmp3_ = NULL;
				yrcdUser* _tmp4_ = NULL;
				const gchar* _tmp5_ = NULL;
				const gchar* _tmp6_ = NULL;
				GString* _tmp7_ = NULL;
				_tmp3_ = builder;
				_tmp4_ = k;
				_tmp5_ = yrcd_user_get_nick (_tmp4_);
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
	yrcd_user_fire_numeric (_tmp11_, YRCD_RPL_NAMEPLY, _tmp12_, resp, NULL);
	_tmp13_ = user;
	_tmp14_ = self->priv->_name;
	yrcd_user_fire_numeric (_tmp13_, YRCD_RPL_ENDOFNAMES, _tmp14_, NULL);
	_g_free0 (resp);
	_g_string_free0 (builder);
}


void yrcd_channel_privmsg (yrcdChannel* self, yrcdUser* user, const gchar* msg) {
	gchar* to_send = NULL;
	yrcdUser* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	yrcdServer* _tmp7_ = NULL;
	const gchar* _tmp8_ = NULL;
	const gchar* _tmp9_ = NULL;
	const gchar* _tmp10_ = NULL;
	const gchar* _tmp11_ = NULL;
	gchar* _tmp12_ = NULL;
	gchar* _tmp13_ = NULL;
	GList* rec = NULL;
	GList* _tmp14_ = NULL;
	yrcdUser* _tmp15_ = NULL;
	yrcdServer* _tmp16_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	g_return_if_fail (msg != NULL);
	_tmp0_ = user;
	_tmp1_ = yrcd_user_get_hostmask (_tmp0_);
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
	yrcd_server_log (_tmp7_, _tmp13_);
	_g_free0 (_tmp13_);
	_tmp14_ = yrcd_channel_get_users (self);
	rec = _tmp14_;
	_tmp15_ = user;
	rec = g_list_remove (rec, _tmp15_);
	_tmp16_ = self->server;
	yrcd_server_send_to_many (_tmp16_, rec, to_send, G_PRIORITY_HIGH);
	__g_list_free__g_object_unref0_0 (rec);
	_g_free0 (to_send);
}


void yrcd_channel_who_response (yrcdChannel* self, yrcdUser* user) {
	GList* _tmp0_ = NULL;
	yrcdUser* _tmp19_ = NULL;
	const gchar* _tmp20_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (user != NULL);
	_tmp0_ = self->users;
	{
		GList* k_collection = NULL;
		GList* k_it = NULL;
		k_collection = _tmp0_;
		for (k_it = k_collection; k_it != NULL; k_it = k_it->next) {
			yrcdUser* _tmp1_ = NULL;
			yrcdUser* k = NULL;
			_tmp1_ = _g_object_ref0 ((yrcdUser*) k_it->data);
			k = _tmp1_;
			{
				yrcdUser* _tmp2_ = NULL;
				const gchar* _tmp3_ = NULL;
				yrcdUser* _tmp4_ = NULL;
				const gchar* _tmp5_ = NULL;
				const gchar* _tmp6_ = NULL;
				yrcdUser* _tmp7_ = NULL;
				const gchar* _tmp8_ = NULL;
				yrcdServer* _tmp9_ = NULL;
				yrcdConfig* _tmp10_ = NULL;
				const gchar* _tmp11_ = NULL;
				const gchar* _tmp12_ = NULL;
				yrcdUser* _tmp13_ = NULL;
				const gchar* _tmp14_ = NULL;
				const gchar* _tmp15_ = NULL;
				yrcdUser* _tmp16_ = NULL;
				const gchar* _tmp17_ = NULL;
				const gchar* _tmp18_ = NULL;
				_tmp2_ = user;
				_tmp3_ = self->priv->_name;
				_tmp4_ = k;
				_tmp5_ = yrcd_user_get_ident (_tmp4_);
				_tmp6_ = _tmp5_;
				_tmp7_ = k;
				_tmp8_ = _tmp7_->host;
				_tmp9_ = self->server;
				_tmp10_ = _tmp9_->config;
				_tmp11_ = yrcd_config_get_sname (_tmp10_);
				_tmp12_ = _tmp11_;
				_tmp13_ = k;
				_tmp14_ = yrcd_user_get_nick (_tmp13_);
				_tmp15_ = _tmp14_;
				_tmp16_ = k;
				_tmp17_ = yrcd_user_get_realname (_tmp16_);
				_tmp18_ = _tmp17_;
				yrcd_user_fire_numeric (_tmp2_, YRCD_RPL_WHOREPLY, _tmp3_, _tmp6_, _tmp8_, _tmp12_, _tmp15_, "H", ":0", _tmp18_, NULL);
				_g_object_unref0 (k);
			}
		}
	}
	_tmp19_ = user;
	_tmp20_ = self->priv->_name;
	yrcd_user_fire_numeric (_tmp19_, YRCD_RPL_ENDOFWHO, _tmp20_, NULL);
}


const gchar* yrcd_channel_get_name (yrcdChannel* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}


void yrcd_channel_set_name (yrcdChannel* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_name);
	self->priv->_name = _tmp1_;
	g_object_notify ((GObject *) self, "name");
}


static void yrcd_channel_class_init (yrcdChannelClass * klass) {
	yrcd_channel_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (yrcdChannelPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_yrcd_channel_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_yrcd_channel_set_property;
	G_OBJECT_CLASS (klass)->finalize = yrcd_channel_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_CHANNEL_NAME, g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void yrcd_channel_instance_init (yrcdChannel * self) {
	self->priv = YRCD_CHANNEL_GET_PRIVATE (self);
}


static void yrcd_channel_finalize (GObject* obj) {
	yrcdChannel * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, YRCD_TYPE_CHANNEL, yrcdChannel);
	_g_free0 (self->priv->_name);
	self->modes = (_vala_array_free (self->modes, self->modes_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (self->topic);
	_g_free0 (self->topic_host);
	_g_object_unref0 (self->server);
	_g_list_free0 (self->users);
	G_OBJECT_CLASS (yrcd_channel_parent_class)->finalize (obj);
}


GType yrcd_channel_get_type (void) {
	static volatile gsize yrcd_channel_type_id__volatile = 0;
	if (g_once_init_enter (&yrcd_channel_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (yrcdChannelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) yrcd_channel_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (yrcdChannel), 0, (GInstanceInitFunc) yrcd_channel_instance_init, NULL };
		GType yrcd_channel_type_id;
		yrcd_channel_type_id = g_type_register_static (G_TYPE_OBJECT, "yrcdChannel", &g_define_type_info, 0);
		g_once_init_leave (&yrcd_channel_type_id__volatile, yrcd_channel_type_id);
	}
	return yrcd_channel_type_id__volatile;
}


static void _vala_yrcd_channel_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	yrcdChannel * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, YRCD_TYPE_CHANNEL, yrcdChannel);
	switch (property_id) {
		case YRCD_CHANNEL_NAME:
		g_value_set_string (value, yrcd_channel_get_name (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_yrcd_channel_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	yrcdChannel * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, YRCD_TYPE_CHANNEL, yrcdChannel);
	switch (property_id) {
		case YRCD_CHANNEL_NAME:
		yrcd_channel_set_name (self, g_value_get_string (value));
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



