/* server.c generated by valac 0.24.0, the Vala compiler
 * generated from server.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <stdio.h>


#define YRCD_TYPE_YRCD_SERVER (yrcd_yrcd_server_get_type ())
#define YRCD_YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_server))
#define YRCD_YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverClass))
#define YRCD_IS_YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_SERVER))
#define YRCD_IS_YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_SERVER))
#define YRCD_YRCD_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverClass))

typedef struct _yrcdyrcd_server yrcdyrcd_server;
typedef struct _yrcdyrcd_serverClass yrcdyrcd_serverClass;
typedef struct _yrcdyrcd_serverPrivate yrcdyrcd_serverPrivate;

#define YRCD_TYPE_YRCD_USER (yrcd_yrcd_user_get_type ())
#define YRCD_YRCD_USER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_USER, yrcdyrcd_user))
#define YRCD_YRCD_USER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_USER, yrcdyrcd_userClass))
#define YRCD_IS_YRCD_USER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_USER))
#define YRCD_IS_YRCD_USER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_USER))
#define YRCD_YRCD_USER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_USER, yrcdyrcd_userClass))

typedef struct _yrcdyrcd_user yrcdyrcd_user;
typedef struct _yrcdyrcd_userClass yrcdyrcd_userClass;

#define YRCD_TYPE_YRCD_CHANNEL (yrcd_yrcd_channel_get_type ())
#define YRCD_YRCD_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channel))
#define YRCD_YRCD_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channelClass))
#define YRCD_IS_YRCD_CHANNEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_CHANNEL))
#define YRCD_IS_YRCD_CHANNEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_CHANNEL))
#define YRCD_YRCD_CHANNEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_CHANNEL, yrcdyrcd_channelClass))

typedef struct _yrcdyrcd_channel yrcdyrcd_channel;
typedef struct _yrcdyrcd_channelClass yrcdyrcd_channelClass;

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

#define YRCD_TYPE_YRCD_ROUTER (yrcd_yrcd_router_get_type ())
#define YRCD_YRCD_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_ROUTER, yrcdyrcd_router))
#define YRCD_YRCD_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_ROUTER, yrcdyrcd_routerClass))
#define YRCD_IS_YRCD_ROUTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_ROUTER))
#define YRCD_IS_YRCD_ROUTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_ROUTER))
#define YRCD_YRCD_ROUTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_ROUTER, yrcdyrcd_routerClass))

typedef struct _yrcdyrcd_router yrcdyrcd_router;
typedef struct _yrcdyrcd_routerClass yrcdyrcd_routerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_date_time_unref0(var) ((var == NULL) ? NULL : (var = (g_date_time_unref (var), NULL)))
typedef struct _yrcdyrcd_configPrivate yrcdyrcd_configPrivate;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))

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

struct _yrcdyrcd_serverPrivate {
	GSocketService* ss;
	yrcdyrcd_router* router;
	gint user_counter;
	gint cid_counter;
};

struct _yrcdyrcd_config {
	GObject parent_instance;
	yrcdyrcd_configPrivate * priv;
	GList* listen_ports;
	gchar** listen_ips;
	gint listen_ips_length1;
	GList* motd;
	gint ping_invertal;
	gboolean config_error;
	gchar* salt;
};

struct _yrcdyrcd_configClass {
	GObjectClass parent_class;
};


static gpointer yrcd_yrcd_server_parent_class = NULL;

GType yrcd_yrcd_server_get_type (void) G_GNUC_CONST;
GType yrcd_yrcd_user_get_type (void) G_GNUC_CONST;
GType yrcd_yrcd_channel_get_type (void) G_GNUC_CONST;
GType yrcd_yrcd_numeric_wrapper_get_type (void) G_GNUC_CONST;
GType yrcd_yrcd_config_get_type (void) G_GNUC_CONST;
GType yrcd_yrcd_router_get_type (void) G_GNUC_CONST;
#define YRCD_YRCD_SERVER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverPrivate))
enum  {
	YRCD_YRCD_SERVER_DUMMY_PROPERTY
};
yrcdyrcd_numeric_wrapper* yrcd_yrcd_numeric_wrapper_new (void);
yrcdyrcd_numeric_wrapper* yrcd_yrcd_numeric_wrapper_construct (GType object_type);
gint yrcd_yrcd_server_new_cid (yrcdyrcd_server* self);
gint yrcd_yrcd_server_new_userid (yrcdyrcd_server* self);
void yrcd_yrcd_server_log (yrcdyrcd_server* self, const gchar* msg);
yrcdyrcd_server* yrcd_yrcd_server_new (yrcdyrcd_config* _config);
yrcdyrcd_server* yrcd_yrcd_server_construct (GType object_type, yrcdyrcd_config* _config);
#define YRCD_YRCD_CONSTANTS_software "yrcd"
#define YRCD_YRCD_CONSTANTS_version "0.2"
void yrcd_yrcd_server_add_listeners (yrcdyrcd_server* self);
yrcdyrcd_router* yrcd_yrcd_router_new (yrcdyrcd_server* k);
yrcdyrcd_router* yrcd_yrcd_router_construct (GType object_type, yrcdyrcd_server* k);
gboolean yrcd_yrcd_server_accept_connection (yrcdyrcd_server* self, GSocketConnection* conn);
static gboolean _yrcd_yrcd_server_accept_connection_g_socket_service_incoming (GSocketService* _sender, GSocketConnection* connection, GObject* source_object, gpointer self);
void yrcd_yrcd_server_remove_user (yrcdyrcd_server* self, gint id);
void yrcd_yrcd_router_process_user (yrcdyrcd_router* self, GSocketConnection* conn, GAsyncReadyCallback _callback_, gpointer _user_data_);
void yrcd_yrcd_router_process_user_finish (yrcdyrcd_router* self, GAsyncResult* _res_);
gchar* yrcd_yrcd_server_ut_to_utc (yrcdyrcd_server* self, gint64 ut);
yrcdyrcd_user* yrcd_yrcd_server_get_user_by_nick (yrcdyrcd_server* self, const gchar* nicktocheck);
gboolean yrcd_yrcd_user_get_nick_set (yrcdyrcd_user* self);
const gchar* yrcd_yrcd_user_get_nick (yrcdyrcd_user* self);
yrcdyrcd_channel* yrcd_yrcd_server_get_channel_by_name (yrcdyrcd_server* self, const gchar* nametocheck);
yrcdyrcd_channel* yrcd_yrcd_channel_new (yrcdyrcd_server* _server, const gchar* _name);
yrcdyrcd_channel* yrcd_yrcd_channel_construct (GType object_type, yrcdyrcd_server* _server, const gchar* _name);
const gchar* yrcd_yrcd_channel_get_name (yrcdyrcd_channel* self);
gchar* yrcd_yrcd_server_secure_hash (yrcdyrcd_server* self, const gchar* in);
static void yrcd_yrcd_server_finalize (GObject* obj);


gint yrcd_yrcd_server_new_cid (yrcdyrcd_server* self) {
	gint result = 0;
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->cid_counter;
	self->priv->cid_counter = _tmp0_ + 1;
	_tmp1_ = self->priv->cid_counter;
	result = _tmp1_;
	return result;
}


gint yrcd_yrcd_server_new_userid (yrcdyrcd_server* self) {
	gint result = 0;
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->user_counter;
	self->priv->user_counter = _tmp0_ + 1;
	_tmp1_ = self->priv->user_counter;
	result = _tmp1_;
	return result;
}


void yrcd_yrcd_server_log (yrcdyrcd_server* self, const gchar* msg) {
	FILE* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (msg != NULL);
	_tmp0_ = stdout;
	_tmp1_ = msg;
	fprintf (_tmp0_, "LOG: %s\n", _tmp1_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean _yrcd_yrcd_server_accept_connection_g_socket_service_incoming (GSocketService* _sender, GSocketConnection* connection, GObject* source_object, gpointer self) {
	gboolean result;
	result = yrcd_yrcd_server_accept_connection ((yrcdyrcd_server*) self, connection);
	return result;
}


yrcdyrcd_server* yrcd_yrcd_server_construct (GType object_type, yrcdyrcd_config* _config) {
	yrcdyrcd_server * self = NULL;
	yrcdyrcd_config* _tmp0_ = NULL;
	yrcdyrcd_config* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	GDateTime* _tmp4_ = NULL;
	GDateTime* _tmp5_ = NULL;
	gint64 _tmp6_ = 0LL;
	yrcdyrcd_router* _tmp7_ = NULL;
	GeeHashMap* _tmp8_ = NULL;
	GSocketService* _tmp9_ = NULL;
	GSocketService* _tmp10_ = NULL;
	g_return_val_if_fail (_config != NULL, NULL);
	self = (yrcdyrcd_server*) g_object_new (object_type, NULL);
	_tmp0_ = _config;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->config);
	self->config = _tmp1_;
	_tmp2_ = g_strdup_printf ("Initializing server: %s %s", YRCD_YRCD_CONSTANTS_software, YRCD_YRCD_CONSTANTS_version);
	_tmp3_ = _tmp2_;
	yrcd_yrcd_server_log (self, _tmp3_);
	_g_free0 (_tmp3_);
	_tmp4_ = g_date_time_new_now_utc ();
	_tmp5_ = _tmp4_;
	_tmp6_ = g_date_time_to_unix (_tmp5_);
	self->epoch = _tmp6_;
	_g_date_time_unref0 (_tmp5_);
	yrcd_yrcd_server_add_listeners (self);
	_tmp7_ = yrcd_yrcd_router_new (self);
	_g_object_unref0 (self->priv->router);
	self->priv->router = _tmp7_;
	_tmp8_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, YRCD_TYPE_YRCD_CHANNEL, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL);
	_g_object_unref0 (self->channellist);
	self->channellist = _tmp8_;
	_tmp9_ = self->priv->ss;
	g_signal_connect_object (_tmp9_, "incoming", (GCallback) _yrcd_yrcd_server_accept_connection_g_socket_service_incoming, self, 0);
	_tmp10_ = self->priv->ss;
	g_socket_service_start (_tmp10_);
	return self;
}


yrcdyrcd_server* yrcd_yrcd_server_new (yrcdyrcd_config* _config) {
	return yrcd_yrcd_server_construct (YRCD_TYPE_YRCD_SERVER, _config);
}


void yrcd_yrcd_server_remove_user (yrcdyrcd_server* self, gint id) {
	GeeHashMap* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->userlist;
	_tmp1_ = id;
	gee_abstract_map_unset ((GeeAbstractMap*) _tmp0_, (gpointer) ((gintptr) _tmp1_), NULL);
}


void yrcd_yrcd_server_add_listeners (yrcdyrcd_server* self) {
	yrcdyrcd_config* _tmp0_ = NULL;
	gchar** _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->config;
	_tmp1_ = _tmp0_->listen_ips;
	_tmp1__length1 = _tmp0_->listen_ips_length1;
	{
		gchar** k_collection = NULL;
		gint k_collection_length1 = 0;
		gint _k_collection_size_ = 0;
		gint k_it = 0;
		k_collection = _tmp1_;
		k_collection_length1 = _tmp1__length1;
		for (k_it = 0; k_it < _tmp1__length1; k_it = k_it + 1) {
			gchar* _tmp2_ = NULL;
			gchar* k = NULL;
			_tmp2_ = g_strdup (k_collection[k_it]);
			k = _tmp2_;
			{
				yrcdyrcd_config* _tmp3_ = NULL;
				GList* _tmp4_ = NULL;
				_tmp3_ = self->config;
				_tmp4_ = _tmp3_->listen_ports;
				{
					GList* j_collection = NULL;
					GList* j_it = NULL;
					j_collection = _tmp4_;
					for (j_it = j_collection; j_it != NULL; j_it = j_it->next) {
						guint16 j = 0U;
						j = (guint16) ((guintptr) j_it->data);
						{
							const gchar* _tmp5_ = NULL;
							guint16 _tmp6_ = 0U;
							gchar* _tmp7_ = NULL;
							gchar* _tmp8_ = NULL;
							GSocketAddress* serversock = NULL;
							GInetAddress* inetaddr = NULL;
							const gchar* _tmp9_ = NULL;
							GInetAddress* _tmp10_ = NULL;
							GSocketAddress* sockaddr = NULL;
							GInetAddress* _tmp11_ = NULL;
							guint16 _tmp12_ = 0U;
							GInetSocketAddress* _tmp13_ = NULL;
							_tmp5_ = k;
							_tmp6_ = j;
							_tmp7_ = g_strdup_printf ("Adding listener on IP: %s port %d", _tmp5_, (gint) _tmp6_);
							_tmp8_ = _tmp7_;
							yrcd_yrcd_server_log (self, _tmp8_);
							_g_free0 (_tmp8_);
							serversock = NULL;
							_tmp9_ = k;
							_tmp10_ = g_inet_address_new_from_string (_tmp9_);
							inetaddr = _tmp10_;
							_tmp11_ = inetaddr;
							_tmp12_ = j;
							_tmp13_ = (GInetSocketAddress*) g_inet_socket_address_new (_tmp11_, _tmp12_);
							sockaddr = (GSocketAddress*) _tmp13_;
							{
								GSocketService* _tmp14_ = NULL;
								GSocketAddress* _tmp15_ = NULL;
								GSocketService* _tmp16_ = NULL;
								GSocketAddress* _tmp17_ = NULL;
								_tmp14_ = self->priv->ss;
								_tmp15_ = sockaddr;
								_tmp16_ = self->priv->ss;
								g_socket_listener_add_address ((GSocketListener*) _tmp14_, _tmp15_, G_SOCKET_TYPE_STREAM, G_SOCKET_PROTOCOL_DEFAULT, (GObject*) _tmp16_, &_tmp17_, &_inner_error_);
								_g_object_unref0 (serversock);
								serversock = _tmp17_;
								if (_inner_error_ != NULL) {
									goto __catch2_g_error;
								}
							}
							goto __finally2;
							__catch2_g_error:
							{
								GError* e = NULL;
								GError* _tmp18_ = NULL;
								const gchar* _tmp19_ = NULL;
								gchar* _tmp20_ = NULL;
								gchar* _tmp21_ = NULL;
								e = _inner_error_;
								_inner_error_ = NULL;
								_tmp18_ = e;
								_tmp19_ = _tmp18_->message;
								_tmp20_ = g_strdup_printf ("Error opening socket: %s", _tmp19_);
								_tmp21_ = _tmp20_;
								yrcd_yrcd_server_log (self, _tmp21_);
								_g_free0 (_tmp21_);
								_g_error_free0 (e);
							}
							__finally2:
							if (_inner_error_ != NULL) {
								_g_object_unref0 (sockaddr);
								_g_object_unref0 (inetaddr);
								_g_object_unref0 (serversock);
								_g_free0 (k);
								g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
								g_clear_error (&_inner_error_);
								return;
							}
							_g_object_unref0 (sockaddr);
							_g_object_unref0 (inetaddr);
							_g_object_unref0 (serversock);
						}
					}
				}
				_g_free0 (k);
			}
		}
	}
}


gboolean yrcd_yrcd_server_accept_connection (yrcdyrcd_server* self, GSocketConnection* conn) {
	gboolean result = FALSE;
	yrcdyrcd_router* _tmp0_ = NULL;
	GSocketConnection* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (conn != NULL, FALSE);
	_tmp0_ = self->priv->router;
	_tmp1_ = conn;
	yrcd_yrcd_router_process_user (_tmp0_, _tmp1_, NULL, NULL);
	result = TRUE;
	return result;
}


static gchar* g_date_time_to_string (GDateTime* self) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_date_time_format (self, "%FT%H:%M:%S%z");
	result = _tmp0_;
	return result;
}


gchar* yrcd_yrcd_server_ut_to_utc (yrcdyrcd_server* self, gint64 ut) {
	gchar* result = NULL;
	GDateTime* time = NULL;
	gint64 _tmp0_ = 0LL;
	GDateTime* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = ut;
	_tmp1_ = g_date_time_new_from_unix_utc (_tmp0_);
	time = _tmp1_;
	_tmp2_ = g_date_time_to_string (time);
	result = _tmp2_;
	_g_date_time_unref0 (time);
	return result;
}


yrcdyrcd_user* yrcd_yrcd_server_get_user_by_nick (yrcdyrcd_server* self, const gchar* nicktocheck) {
	yrcdyrcd_user* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (nicktocheck != NULL, NULL);
	{
		GeeHashMap* _k_list = NULL;
		GeeHashMap* _tmp0_ = NULL;
		GeeHashMap* _tmp1_ = NULL;
		gint _k_size = 0;
		GeeHashMap* _tmp2_ = NULL;
		gint _tmp3_ = 0;
		gint _tmp4_ = 0;
		gint _k_index = 0;
		_tmp0_ = self->userlist;
		_tmp1_ = _g_object_ref0 (_tmp0_);
		_k_list = _tmp1_;
		_tmp2_ = _k_list;
		_tmp3_ = gee_abstract_map_get_size ((GeeMap*) _tmp2_);
		_tmp4_ = _tmp3_;
		_k_size = _tmp4_;
		_k_index = -1;
		while (TRUE) {
			gint _tmp5_ = 0;
			gint _tmp6_ = 0;
			gint _tmp7_ = 0;
			yrcdyrcd_user* k = NULL;
			GeeHashMap* _tmp8_ = NULL;
			gint _tmp9_ = 0;
			gpointer _tmp10_ = NULL;
			yrcdyrcd_user* _tmp11_ = NULL;
			gboolean _tmp12_ = FALSE;
			gboolean _tmp13_ = FALSE;
			_tmp5_ = _k_index;
			_k_index = _tmp5_ + 1;
			_tmp6_ = _k_index;
			_tmp7_ = _k_size;
			if (!(_tmp6_ < _tmp7_)) {
				break;
			}
			_tmp8_ = _k_list;
			_tmp9_ = _k_index;
			_tmp10_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp8_, (gpointer) ((gintptr) _tmp9_));
			k = (yrcdyrcd_user*) _tmp10_;
			_tmp11_ = k;
			_tmp12_ = yrcd_yrcd_user_get_nick_set (_tmp11_);
			_tmp13_ = _tmp12_;
			if (_tmp13_) {
				yrcdyrcd_user* _tmp14_ = NULL;
				const gchar* _tmp15_ = NULL;
				const gchar* _tmp16_ = NULL;
				gchar* _tmp17_ = NULL;
				gchar* _tmp18_ = NULL;
				const gchar* _tmp19_ = NULL;
				gchar* _tmp20_ = NULL;
				gchar* _tmp21_ = NULL;
				gboolean _tmp22_ = FALSE;
				_tmp14_ = k;
				_tmp15_ = yrcd_yrcd_user_get_nick (_tmp14_);
				_tmp16_ = _tmp15_;
				_tmp17_ = g_utf8_strdown (_tmp16_, (gssize) (-1));
				_tmp18_ = _tmp17_;
				_tmp19_ = nicktocheck;
				_tmp20_ = g_utf8_strdown (_tmp19_, (gssize) (-1));
				_tmp21_ = _tmp20_;
				_tmp22_ = g_strcmp0 (_tmp18_, _tmp21_) == 0;
				_g_free0 (_tmp21_);
				_g_free0 (_tmp18_);
				if (_tmp22_) {
					result = k;
					_g_object_unref0 (_k_list);
					return result;
				}
			}
			_g_object_unref0 (k);
		}
		_g_object_unref0 (_k_list);
	}
	result = NULL;
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


yrcdyrcd_channel* yrcd_yrcd_server_get_channel_by_name (yrcdyrcd_server* self, const gchar* nametocheck) {
	yrcdyrcd_channel* result = NULL;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	GeeHashMap* _tmp4_ = NULL;
	const gchar* _tmp5_ = NULL;
	gpointer _tmp6_ = NULL;
	yrcdyrcd_channel* _tmp7_ = NULL;
	gboolean _tmp8_ = FALSE;
	const gchar* _tmp16_ = NULL;
	const gchar* _tmp17_ = NULL;
	gchar* _tmp18_ = NULL;
	gchar* _tmp19_ = NULL;
	yrcdyrcd_channel* chan = NULL;
	const gchar* _tmp20_ = NULL;
	yrcdyrcd_channel* _tmp21_ = NULL;
	GeeHashMap* _tmp22_ = NULL;
	yrcdyrcd_channel* _tmp23_ = NULL;
	const gchar* _tmp24_ = NULL;
	const gchar* _tmp25_ = NULL;
	gchar* _tmp26_ = NULL;
	gchar* _tmp27_ = NULL;
	yrcdyrcd_channel* _tmp28_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (nametocheck != NULL, NULL);
	_tmp0_ = nametocheck;
	_tmp1_ = string_to_string (_tmp0_);
	_tmp2_ = g_strconcat ("Looking for channel ", _tmp1_, NULL);
	_tmp3_ = _tmp2_;
	yrcd_yrcd_server_log (self, _tmp3_);
	_g_free0 (_tmp3_);
	_tmp4_ = self->channellist;
	_tmp5_ = nametocheck;
	_tmp6_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp4_, _tmp5_);
	_tmp7_ = (yrcdyrcd_channel*) _tmp6_;
	_tmp8_ = _tmp7_ != NULL;
	_g_object_unref0 (_tmp7_);
	if (_tmp8_) {
		const gchar* _tmp9_ = NULL;
		const gchar* _tmp10_ = NULL;
		gchar* _tmp11_ = NULL;
		gchar* _tmp12_ = NULL;
		GeeHashMap* _tmp13_ = NULL;
		const gchar* _tmp14_ = NULL;
		gpointer _tmp15_ = NULL;
		_tmp9_ = nametocheck;
		_tmp10_ = string_to_string (_tmp9_);
		_tmp11_ = g_strconcat ("channel ", _tmp10_, "  found", NULL);
		_tmp12_ = _tmp11_;
		yrcd_yrcd_server_log (self, _tmp12_);
		_g_free0 (_tmp12_);
		_tmp13_ = self->channellist;
		_tmp14_ = nametocheck;
		_tmp15_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp13_, _tmp14_);
		result = (yrcdyrcd_channel*) _tmp15_;
		return result;
	}
	_tmp16_ = nametocheck;
	_tmp17_ = string_to_string (_tmp16_);
	_tmp18_ = g_strconcat ("Channel ", _tmp17_, " not found, creating it", NULL);
	_tmp19_ = _tmp18_;
	yrcd_yrcd_server_log (self, _tmp19_);
	_g_free0 (_tmp19_);
	_tmp20_ = nametocheck;
	_tmp21_ = yrcd_yrcd_channel_new (self, _tmp20_);
	chan = _tmp21_;
	_tmp22_ = self->channellist;
	_tmp23_ = chan;
	_tmp24_ = yrcd_yrcd_channel_get_name (_tmp23_);
	_tmp25_ = _tmp24_;
	_tmp26_ = g_utf8_strdown (_tmp25_, (gssize) (-1));
	_tmp27_ = _tmp26_;
	_tmp28_ = chan;
	gee_abstract_map_set ((GeeAbstractMap*) _tmp22_, _tmp27_, _tmp28_);
	_g_free0 (_tmp27_);
	result = chan;
	return result;
}


gchar* yrcd_yrcd_server_secure_hash (yrcdyrcd_server* self, const gchar* in) {
	gchar* result = NULL;
	GString* builder = NULL;
	GString* _tmp0_ = NULL;
	GString* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	GString* _tmp17_ = NULL;
	const gchar* _tmp18_ = NULL;
	gint _tmp19_ = 0;
	gint _tmp20_ = 0;
	GString* _tmp21_ = NULL;
	const gchar* _tmp22_ = NULL;
	gchar* _tmp23_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (in != NULL, NULL);
	_tmp0_ = g_string_new ("");
	builder = _tmp0_;
	_tmp1_ = builder;
	_tmp2_ = in;
	_tmp3_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, _tmp2_, (gsize) (-1));
	_tmp4_ = _tmp3_;
	g_string_append (_tmp1_, _tmp4_);
	_g_free0 (_tmp4_);
	while (TRUE) {
		GString* _tmp5_ = NULL;
		const gchar* _tmp6_ = NULL;
		gint _tmp7_ = 0;
		gint _tmp8_ = 0;
		const gchar* _tmp9_ = NULL;
		gint _tmp10_ = 0;
		gint _tmp11_ = 0;
		GString* _tmp12_ = NULL;
		GString* _tmp13_ = NULL;
		const gchar* _tmp14_ = NULL;
		gchar* _tmp15_ = NULL;
		gchar* _tmp16_ = NULL;
		_tmp5_ = builder;
		_tmp6_ = _tmp5_->str;
		_tmp7_ = strlen (_tmp6_);
		_tmp8_ = _tmp7_;
		_tmp9_ = in;
		_tmp10_ = strlen (_tmp9_);
		_tmp11_ = _tmp10_;
		if (!(_tmp8_ < _tmp11_)) {
			break;
		}
		_tmp12_ = builder;
		_tmp13_ = builder;
		_tmp14_ = _tmp13_->str;
		_tmp15_ = g_compute_checksum_for_string (G_CHECKSUM_MD5, _tmp14_, (gsize) (-1));
		_tmp16_ = _tmp15_;
		g_string_append (_tmp12_, _tmp16_);
		_g_free0 (_tmp16_);
	}
	_tmp17_ = builder;
	_tmp18_ = in;
	_tmp19_ = strlen (_tmp18_);
	_tmp20_ = _tmp19_;
	g_string_truncate (_tmp17_, (gsize) _tmp20_);
	_tmp21_ = builder;
	_tmp22_ = _tmp21_->str;
	_tmp23_ = g_strdup (_tmp22_);
	result = _tmp23_;
	_g_string_free0 (builder);
	return result;
}


static void yrcd_yrcd_server_class_init (yrcdyrcd_serverClass * klass) {
	yrcd_yrcd_server_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (yrcdyrcd_serverPrivate));
	G_OBJECT_CLASS (klass)->finalize = yrcd_yrcd_server_finalize;
}


static void yrcd_yrcd_server_instance_init (yrcdyrcd_server * self) {
	GSocketService* _tmp0_ = NULL;
	GeeHashMap* _tmp1_ = NULL;
	yrcdyrcd_numeric_wrapper* _tmp2_ = NULL;
	self->priv = YRCD_YRCD_SERVER_GET_PRIVATE (self);
	_tmp0_ = g_socket_service_new ();
	self->priv->ss = _tmp0_;
	_tmp1_ = gee_hash_map_new (G_TYPE_INT, NULL, NULL, YRCD_TYPE_YRCD_USER, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL);
	self->userlist = _tmp1_;
	self->priv->user_counter = 0;
	self->priv->cid_counter = 0;
	self->max_users = 0;
	_tmp2_ = yrcd_yrcd_numeric_wrapper_new ();
	self->numeric_wrapper = _tmp2_;
}


static void yrcd_yrcd_server_finalize (GObject* obj) {
	yrcdyrcd_server * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, YRCD_TYPE_YRCD_SERVER, yrcdyrcd_server);
	_g_object_unref0 (self->priv->ss);
	_g_object_unref0 (self->priv->router);
	_g_object_unref0 (self->userlist);
	_g_object_unref0 (self->channellist);
	_g_object_unref0 (self->numeric_wrapper);
	_g_object_unref0 (self->config);
	G_OBJECT_CLASS (yrcd_yrcd_server_parent_class)->finalize (obj);
}


GType yrcd_yrcd_server_get_type (void) {
	static volatile gsize yrcd_yrcd_server_type_id__volatile = 0;
	if (g_once_init_enter (&yrcd_yrcd_server_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (yrcdyrcd_serverClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) yrcd_yrcd_server_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (yrcdyrcd_server), 0, (GInstanceInitFunc) yrcd_yrcd_server_instance_init, NULL };
		GType yrcd_yrcd_server_type_id;
		yrcd_yrcd_server_type_id = g_type_register_static (G_TYPE_OBJECT, "yrcdyrcd_server", &g_define_type_info, 0);
		g_once_init_leave (&yrcd_yrcd_server_type_id__volatile, yrcd_yrcd_server_type_id);
	}
	return yrcd_yrcd_server_type_id__volatile;
}



