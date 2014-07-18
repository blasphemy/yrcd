/* user.c generated by valac 0.24.0, the Vala compiler
 * generated from user.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>


#define YRCD_TYPE_YRCD_USER (yrcd_yrcd_user_get_type ())
#define YRCD_YRCD_USER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_USER, yrcdyrcd_user))
#define YRCD_YRCD_USER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_USER, yrcdyrcd_userClass))
#define YRCD_IS_YRCD_USER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_USER))
#define YRCD_IS_YRCD_USER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_USER))
#define YRCD_YRCD_USER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_USER, yrcdyrcd_userClass))

typedef struct _yrcdyrcd_user yrcdyrcd_user;
typedef struct _yrcdyrcd_userClass yrcdyrcd_userClass;
typedef struct _yrcdyrcd_userPrivate yrcdyrcd_userPrivate;

#define YRCD_TYPE_YRCD_SERVER (yrcd_yrcd_server_get_type ())
#define YRCD_YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_server))
#define YRCD_YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverClass))
#define YRCD_IS_YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_SERVER))
#define YRCD_IS_YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_SERVER))
#define YRCD_YRCD_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverClass))

typedef struct _yrcdyrcd_server yrcdyrcd_server;
typedef struct _yrcdyrcd_serverClass yrcdyrcd_serverClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_date_time_unref0(var) ((var == NULL) ? NULL : (var = (g_date_time_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))

struct _yrcdyrcd_user {
	GObject parent_instance;
	yrcdyrcd_userPrivate * priv;
	gint64 epoch;
};

struct _yrcdyrcd_userClass {
	GObjectClass parent_class;
};

struct _yrcdyrcd_userPrivate {
	GSocketConnection* _sock;
	GDataInputStream* _dis;
	GDataOutputStream* _dos;
	yrcdyrcd_server* _server;
	gint _id;
	gint64 time_last_rcv;
	gchar* _nick;
	gchar* _ident;
	gchar* _realname;
	gboolean _nick_set;
	gboolean _user_set;
	gboolean _reg_complete;
};


static gpointer yrcd_yrcd_user_parent_class = NULL;

GType yrcd_yrcd_user_get_type (void) G_GNUC_CONST;
GType yrcd_yrcd_server_get_type (void) G_GNUC_CONST;
#define YRCD_YRCD_USER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), YRCD_TYPE_YRCD_USER, yrcdyrcd_userPrivate))
enum  {
	YRCD_YRCD_USER_DUMMY_PROPERTY,
	YRCD_YRCD_USER_SOCK,
	YRCD_YRCD_USER_DIS,
	YRCD_YRCD_USER_DOS,
	YRCD_YRCD_USER_SERVER,
	YRCD_YRCD_USER_ID,
	YRCD_YRCD_USER_NICK,
	YRCD_YRCD_USER_IDENT,
	YRCD_YRCD_USER_REALNAME,
	YRCD_YRCD_USER_NICK_SET,
	YRCD_YRCD_USER_USER_SET,
	YRCD_YRCD_USER_REG_COMPLETE
};
yrcdyrcd_user* yrcd_yrcd_user_new (GSocketConnection* conn, yrcdyrcd_server* _server);
yrcdyrcd_user* yrcd_yrcd_user_construct (GType object_type, GSocketConnection* conn, yrcdyrcd_server* _server);
void yrcd_yrcd_user_set_sock (yrcdyrcd_user* self, GSocketConnection* value);
void yrcd_yrcd_user_set_server (yrcdyrcd_user* self, yrcdyrcd_server* value);
yrcdyrcd_server* yrcd_yrcd_user_get_server (yrcdyrcd_user* self);
void yrcd_yrcd_server_log (yrcdyrcd_server* self, const gchar* msg);
GSocketConnection* yrcd_yrcd_user_get_sock (yrcdyrcd_user* self);
void yrcd_yrcd_user_set_dis (yrcdyrcd_user* self, GDataInputStream* value);
void yrcd_yrcd_user_set_dos (yrcdyrcd_user* self, GDataOutputStream* value);
gint yrcd_yrcd_server_new_userid (yrcdyrcd_server* self);
void yrcd_yrcd_user_set_id (yrcdyrcd_user* self, gint value);
gint yrcd_yrcd_user_get_id (yrcdyrcd_user* self);
void yrcd_yrcd_user_quit (yrcdyrcd_user* self, const gchar* msg);
void yrcd_yrcd_server_remove_user (yrcdyrcd_server* self, gint id);
void yrcd_yrcd_user_change_nick (yrcdyrcd_user* self, gchar** args, int args_length1);
const gchar* yrcd_yrcd_user_get_nick (yrcdyrcd_user* self);
void yrcd_yrcd_user_set_nick (yrcdyrcd_user* self, const gchar* value);
gboolean yrcd_yrcd_user_get_nick_set (yrcdyrcd_user* self);
void yrcd_yrcd_user_set_nick_set (yrcdyrcd_user* self, gboolean value);
gboolean yrcd_yrcd_user_get_reg_complete (yrcdyrcd_user* self);
gboolean yrcd_yrcd_user_get_user_set (yrcdyrcd_user* self);
void yrcd_yrcd_user_reg_finished (yrcdyrcd_user* self);
void yrcd_yrcd_user_user_reg (yrcdyrcd_user* self, gchar** args, int args_length1);
void yrcd_yrcd_user_set_ident (yrcdyrcd_user* self, const gchar* value);
void yrcd_yrcd_user_set_realname (yrcdyrcd_user* self, const gchar* value);
void yrcd_yrcd_user_set_reg_complete (yrcdyrcd_user* self, gboolean value);
const gchar* yrcd_yrcd_user_get_ident (yrcdyrcd_user* self);
const gchar* yrcd_yrcd_user_get_realname (yrcdyrcd_user* self);
void yrcd_yrcd_user_update_timestamp (yrcdyrcd_user* self);
GDataInputStream* yrcd_yrcd_user_get_dis (yrcdyrcd_user* self);
GDataOutputStream* yrcd_yrcd_user_get_dos (yrcdyrcd_user* self);
void yrcd_yrcd_user_set_user_set (yrcdyrcd_user* self, gboolean value);
static void yrcd_yrcd_user_finalize (GObject* obj);
static void _vala_yrcd_yrcd_user_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_yrcd_yrcd_user_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


yrcdyrcd_user* yrcd_yrcd_user_construct (GType object_type, GSocketConnection* conn, yrcdyrcd_server* _server) {
	yrcdyrcd_user * self = NULL;
	GSocketConnection* _tmp0_ = NULL;
	yrcdyrcd_server* _tmp1_ = NULL;
	yrcdyrcd_server* _tmp2_ = NULL;
	GSocketConnection* _tmp3_ = NULL;
	GInputStream* _tmp4_ = NULL;
	GInputStream* _tmp5_ = NULL;
	GDataInputStream* _tmp6_ = NULL;
	GDataInputStream* _tmp7_ = NULL;
	GSocketConnection* _tmp8_ = NULL;
	GOutputStream* _tmp9_ = NULL;
	GOutputStream* _tmp10_ = NULL;
	GDataOutputStream* _tmp11_ = NULL;
	GDataOutputStream* _tmp12_ = NULL;
	yrcdyrcd_server* _tmp13_ = NULL;
	gint _tmp14_ = 0;
	GDateTime* _tmp15_ = NULL;
	GDateTime* _tmp16_ = NULL;
	gint64 _tmp17_ = 0LL;
	yrcdyrcd_server* _tmp18_ = NULL;
	gint _tmp19_ = 0;
	gchar* _tmp20_ = NULL;
	gchar* _tmp21_ = NULL;
	g_return_val_if_fail (conn != NULL, NULL);
	g_return_val_if_fail (_server != NULL, NULL);
	self = (yrcdyrcd_user*) g_object_new (object_type, NULL);
	_tmp0_ = conn;
	yrcd_yrcd_user_set_sock (self, _tmp0_);
	_tmp1_ = _server;
	yrcd_yrcd_user_set_server (self, _tmp1_);
	_tmp2_ = self->priv->_server;
	yrcd_yrcd_server_log (_tmp2_, "User constructor called, opening data streams");
	_tmp3_ = self->priv->_sock;
	_tmp4_ = g_io_stream_get_input_stream ((GIOStream*) _tmp3_);
	_tmp5_ = _tmp4_;
	_tmp6_ = g_data_input_stream_new (_tmp5_);
	_tmp7_ = _tmp6_;
	yrcd_yrcd_user_set_dis (self, _tmp7_);
	_g_object_unref0 (_tmp7_);
	_tmp8_ = self->priv->_sock;
	_tmp9_ = g_io_stream_get_output_stream ((GIOStream*) _tmp8_);
	_tmp10_ = _tmp9_;
	_tmp11_ = g_data_output_stream_new (_tmp10_);
	_tmp12_ = _tmp11_;
	yrcd_yrcd_user_set_dos (self, _tmp12_);
	_g_object_unref0 (_tmp12_);
	_tmp13_ = self->priv->_server;
	_tmp14_ = yrcd_yrcd_server_new_userid (_tmp13_);
	yrcd_yrcd_user_set_id (self, _tmp14_);
	_tmp15_ = g_date_time_new_now_utc ();
	_tmp16_ = _tmp15_;
	_tmp17_ = g_date_time_to_unix (_tmp16_);
	self->epoch = _tmp17_;
	_g_date_time_unref0 (_tmp16_);
	_tmp18_ = self->priv->_server;
	_tmp19_ = self->priv->_id;
	_tmp20_ = g_strdup_printf ("User registered with ID %d", _tmp19_);
	_tmp21_ = _tmp20_;
	yrcd_yrcd_server_log (_tmp18_, _tmp21_);
	_g_free0 (_tmp21_);
	return self;
}


yrcdyrcd_user* yrcd_yrcd_user_new (GSocketConnection* conn, yrcdyrcd_server* _server) {
	return yrcd_yrcd_user_construct (YRCD_TYPE_YRCD_USER, conn, _server);
}


void yrcd_yrcd_user_quit (yrcdyrcd_user* self, const gchar* msg) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	{
		GSocketConnection* _tmp0_ = NULL;
		GSocket* _tmp1_ = NULL;
		yrcdyrcd_server* _tmp2_ = NULL;
		gint _tmp3_ = 0;
		_tmp0_ = self->priv->_sock;
		_tmp1_ = g_socket_connection_get_socket (_tmp0_);
		g_socket_close (_tmp1_, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch2_g_error;
		}
		_tmp2_ = self->priv->_server;
		_tmp3_ = self->priv->_id;
		yrcd_yrcd_server_remove_user (_tmp2_, _tmp3_);
	}
	goto __finally2;
	__catch2_g_error:
	{
		GError* e = NULL;
		yrcdyrcd_server* _tmp4_ = NULL;
		GError* _tmp5_ = NULL;
		const gchar* _tmp6_ = NULL;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp4_ = self->priv->_server;
		_tmp5_ = e;
		_tmp6_ = _tmp5_->message;
		_tmp7_ = g_strdup_printf ("Error closing socket: %s", _tmp6_);
		_tmp8_ = _tmp7_;
		yrcd_yrcd_server_log (_tmp4_, _tmp8_);
		_g_free0 (_tmp8_);
		_g_error_free0 (e);
	}
	__finally2:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


void yrcd_yrcd_user_change_nick (yrcdyrcd_user* self, gchar** args, int args_length1) {
	gchar** _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	gchar* oldnick = NULL;
	const gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	gchar** _tmp7_ = NULL;
	gint _tmp7__length1 = 0;
	const gchar* _tmp8_ = NULL;
	gboolean _tmp9_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = args;
	_tmp0__length1 = args_length1;
	if (_tmp0__length1 < 2) {
		yrcdyrcd_server* _tmp1_ = NULL;
		gint _tmp2_ = 0;
		gchar* _tmp3_ = NULL;
		gchar* _tmp4_ = NULL;
		_tmp1_ = self->priv->_server;
		_tmp2_ = self->priv->_id;
		_tmp3_ = g_strdup_printf ("User %d attempted NICK with invalid arguments", _tmp2_);
		_tmp4_ = _tmp3_;
		yrcd_yrcd_server_log (_tmp1_, _tmp4_);
		_g_free0 (_tmp4_);
	}
	_tmp5_ = self->priv->_nick;
	_tmp6_ = g_strdup (_tmp5_);
	oldnick = _tmp6_;
	_tmp7_ = args;
	_tmp7__length1 = args_length1;
	_tmp8_ = _tmp7_[1];
	yrcd_yrcd_user_set_nick (self, _tmp8_);
	_tmp9_ = self->priv->_nick_set;
	if (!_tmp9_) {
		yrcdyrcd_server* _tmp10_ = NULL;
		gint _tmp11_ = 0;
		const gchar* _tmp12_ = NULL;
		gchar* _tmp13_ = NULL;
		gchar* _tmp14_ = NULL;
		gboolean _tmp15_ = FALSE;
		gboolean _tmp16_ = FALSE;
		_tmp10_ = self->priv->_server;
		_tmp11_ = self->priv->_id;
		_tmp12_ = self->priv->_nick;
		_tmp13_ = g_strdup_printf ("User %d set nick to %s", _tmp11_, _tmp12_);
		_tmp14_ = _tmp13_;
		yrcd_yrcd_server_log (_tmp10_, _tmp14_);
		_g_free0 (_tmp14_);
		yrcd_yrcd_user_set_nick_set (self, TRUE);
		_tmp16_ = self->priv->_reg_complete;
		if (!_tmp16_) {
			gboolean _tmp17_ = FALSE;
			_tmp17_ = self->priv->_user_set;
			_tmp15_ = _tmp17_;
		} else {
			_tmp15_ = FALSE;
		}
		if (_tmp15_) {
			yrcd_yrcd_user_reg_finished (self);
		}
	} else {
		yrcdyrcd_server* _tmp18_ = NULL;
		gint _tmp19_ = 0;
		const gchar* _tmp20_ = NULL;
		const gchar* _tmp21_ = NULL;
		gchar* _tmp22_ = NULL;
		gchar* _tmp23_ = NULL;
		_tmp18_ = self->priv->_server;
		_tmp19_ = self->priv->_id;
		_tmp20_ = oldnick;
		_tmp21_ = self->priv->_nick;
		_tmp22_ = g_strdup_printf ("User %d changed nick from %s to %s", _tmp19_, _tmp20_, _tmp21_);
		_tmp23_ = _tmp22_;
		yrcd_yrcd_server_log (_tmp18_, _tmp23_);
		_g_free0 (_tmp23_);
	}
	_g_free0 (oldnick);
}


static gchar* string_replace (const gchar* self, const gchar* old, const gchar* replacement) {
	gchar* result = NULL;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (old != NULL, NULL);
	g_return_val_if_fail (replacement != NULL, NULL);
	{
		GRegex* regex = NULL;
		const gchar* _tmp0_ = NULL;
		gchar* _tmp1_ = NULL;
		gchar* _tmp2_ = NULL;
		GRegex* _tmp3_ = NULL;
		GRegex* _tmp4_ = NULL;
		gchar* _tmp5_ = NULL;
		GRegex* _tmp6_ = NULL;
		const gchar* _tmp7_ = NULL;
		gchar* _tmp8_ = NULL;
		gchar* _tmp9_ = NULL;
		_tmp0_ = old;
		_tmp1_ = g_regex_escape_string (_tmp0_, -1);
		_tmp2_ = _tmp1_;
		_tmp3_ = g_regex_new (_tmp2_, 0, 0, &_inner_error_);
		_tmp4_ = _tmp3_;
		_g_free0 (_tmp2_);
		regex = _tmp4_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch3_g_regex_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_tmp6_ = regex;
		_tmp7_ = replacement;
		_tmp8_ = g_regex_replace_literal (_tmp6_, self, (gssize) (-1), 0, _tmp7_, 0, &_inner_error_);
		_tmp5_ = _tmp8_;
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch3_g_regex_error;
			}
			_g_regex_unref0 (regex);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_tmp9_ = _tmp5_;
		_tmp5_ = NULL;
		result = _tmp9_;
		_g_free0 (_tmp5_);
		_g_regex_unref0 (regex);
		return result;
	}
	goto __finally3;
	__catch3_g_regex_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_assert_not_reached ();
		_g_error_free0 (e);
	}
	__finally3:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


void yrcd_yrcd_user_user_reg (yrcdyrcd_user* self, gchar** args, int args_length1) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_user_set;
	if (!_tmp0_) {
		gchar** _tmp1_ = NULL;
		gint _tmp1__length1 = 0;
		const gchar* _tmp2_ = NULL;
		gchar** _tmp3_ = NULL;
		gint _tmp3__length1 = 0;
		const gchar* _tmp4_ = NULL;
		gboolean _tmp5_ = FALSE;
		gchar** _tmp11_ = NULL;
		gint _tmp11__length1 = 0;
		const gchar* _tmp12_ = NULL;
		gboolean _tmp13_ = FALSE;
		_tmp1_ = args;
		_tmp1__length1 = args_length1;
		_tmp2_ = _tmp1_[1];
		yrcd_yrcd_user_set_ident (self, _tmp2_);
		_tmp3_ = args;
		_tmp3__length1 = args_length1;
		_tmp4_ = _tmp3_[4];
		_tmp5_ = g_str_has_prefix (_tmp4_, ":");
		if (_tmp5_) {
			gchar** _tmp6_ = NULL;
			gint _tmp6__length1 = 0;
			gchar** _tmp7_ = NULL;
			gint _tmp7__length1 = 0;
			const gchar* _tmp8_ = NULL;
			gchar* _tmp9_ = NULL;
			gchar* _tmp10_ = NULL;
			_tmp6_ = args;
			_tmp6__length1 = args_length1;
			_tmp7_ = args;
			_tmp7__length1 = args_length1;
			_tmp8_ = _tmp7_[4];
			_tmp9_ = string_replace (_tmp8_, ":", "");
			_g_free0 (_tmp6_[4]);
			_tmp6_[4] = _tmp9_;
			_tmp10_ = _tmp6_[4];
		}
		_tmp11_ = args;
		_tmp11__length1 = args_length1;
		_tmp12_ = _tmp11_[4];
		yrcd_yrcd_user_set_realname (self, _tmp12_);
		_tmp13_ = self->priv->_nick_set;
		if (_tmp13_) {
			yrcd_yrcd_user_reg_finished (self);
		}
	} else {
		yrcdyrcd_server* _tmp14_ = NULL;
		gint _tmp15_ = 0;
		gchar* _tmp16_ = NULL;
		gchar* _tmp17_ = NULL;
		_tmp14_ = self->priv->_server;
		_tmp15_ = self->priv->_id;
		_tmp16_ = g_strdup_printf ("User %d attempted user registration while already registered", _tmp15_);
		_tmp17_ = _tmp16_;
		yrcd_yrcd_server_log (_tmp14_, _tmp17_);
		_g_free0 (_tmp17_);
	}
}


void yrcd_yrcd_user_reg_finished (yrcdyrcd_user* self) {
	yrcdyrcd_server* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	const gchar* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	g_return_if_fail (self != NULL);
	yrcd_yrcd_user_set_reg_complete (self, TRUE);
	_tmp0_ = self->priv->_server;
	_tmp1_ = self->priv->_id;
	_tmp2_ = self->priv->_nick;
	_tmp3_ = self->priv->_ident;
	_tmp4_ = self->priv->_realname;
	_tmp5_ = g_strdup_printf ("User %d finished registration with nick %s, ident %s, realname %s", _tmp1_, _tmp2_, _tmp3_, _tmp4_);
	_tmp6_ = _tmp5_;
	yrcd_yrcd_server_log (_tmp0_, _tmp6_);
	_g_free0 (_tmp6_);
}


void yrcd_yrcd_user_update_timestamp (yrcdyrcd_user* self) {
	GDateTime* _tmp0_ = NULL;
	GDateTime* _tmp1_ = NULL;
	gint64 _tmp2_ = 0LL;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_date_time_new_now_utc ();
	_tmp1_ = _tmp0_;
	_tmp2_ = g_date_time_to_unix (_tmp1_);
	self->priv->time_last_rcv = _tmp2_;
	_g_date_time_unref0 (_tmp1_);
}


GSocketConnection* yrcd_yrcd_user_get_sock (yrcdyrcd_user* self) {
	GSocketConnection* result;
	GSocketConnection* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_sock;
	result = _tmp0_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void yrcd_yrcd_user_set_sock (yrcdyrcd_user* self, GSocketConnection* value) {
	GSocketConnection* _tmp0_ = NULL;
	GSocketConnection* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_sock);
	self->priv->_sock = _tmp1_;
	g_object_notify ((GObject *) self, "sock");
}


GDataInputStream* yrcd_yrcd_user_get_dis (yrcdyrcd_user* self) {
	GDataInputStream* result;
	GDataInputStream* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_dis;
	result = _tmp0_;
	return result;
}


void yrcd_yrcd_user_set_dis (yrcdyrcd_user* self, GDataInputStream* value) {
	GDataInputStream* _tmp0_ = NULL;
	GDataInputStream* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_dis);
	self->priv->_dis = _tmp1_;
	g_object_notify ((GObject *) self, "dis");
}


GDataOutputStream* yrcd_yrcd_user_get_dos (yrcdyrcd_user* self) {
	GDataOutputStream* result;
	GDataOutputStream* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_dos;
	result = _tmp0_;
	return result;
}


void yrcd_yrcd_user_set_dos (yrcdyrcd_user* self, GDataOutputStream* value) {
	GDataOutputStream* _tmp0_ = NULL;
	GDataOutputStream* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_dos);
	self->priv->_dos = _tmp1_;
	g_object_notify ((GObject *) self, "dos");
}


yrcdyrcd_server* yrcd_yrcd_user_get_server (yrcdyrcd_user* self) {
	yrcdyrcd_server* result;
	yrcdyrcd_server* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_server;
	result = _tmp0_;
	return result;
}


void yrcd_yrcd_user_set_server (yrcdyrcd_user* self, yrcdyrcd_server* value) {
	yrcdyrcd_server* _tmp0_ = NULL;
	yrcdyrcd_server* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_server);
	self->priv->_server = _tmp1_;
	g_object_notify ((GObject *) self, "server");
}


gint yrcd_yrcd_user_get_id (yrcdyrcd_user* self) {
	gint result;
	gint _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_id;
	result = _tmp0_;
	return result;
}


void yrcd_yrcd_user_set_id (yrcdyrcd_user* self, gint value) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_id = _tmp0_;
	g_object_notify ((GObject *) self, "id");
}


const gchar* yrcd_yrcd_user_get_nick (yrcdyrcd_user* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_nick;
	result = _tmp0_;
	return result;
}


void yrcd_yrcd_user_set_nick (yrcdyrcd_user* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_nick);
	self->priv->_nick = _tmp1_;
	g_object_notify ((GObject *) self, "nick");
}


const gchar* yrcd_yrcd_user_get_ident (yrcdyrcd_user* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_ident;
	result = _tmp0_;
	return result;
}


void yrcd_yrcd_user_set_ident (yrcdyrcd_user* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_ident);
	self->priv->_ident = _tmp1_;
	g_object_notify ((GObject *) self, "ident");
}


const gchar* yrcd_yrcd_user_get_realname (yrcdyrcd_user* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_realname;
	result = _tmp0_;
	return result;
}


void yrcd_yrcd_user_set_realname (yrcdyrcd_user* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_realname);
	self->priv->_realname = _tmp1_;
	g_object_notify ((GObject *) self, "realname");
}


gboolean yrcd_yrcd_user_get_nick_set (yrcdyrcd_user* self) {
	gboolean result;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_nick_set;
	result = _tmp0_;
	return result;
}


void yrcd_yrcd_user_set_nick_set (yrcdyrcd_user* self, gboolean value) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_nick_set = _tmp0_;
	g_object_notify ((GObject *) self, "nick-set");
}


gboolean yrcd_yrcd_user_get_user_set (yrcdyrcd_user* self) {
	gboolean result;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_user_set;
	result = _tmp0_;
	return result;
}


void yrcd_yrcd_user_set_user_set (yrcdyrcd_user* self, gboolean value) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_user_set = _tmp0_;
	g_object_notify ((GObject *) self, "user-set");
}


gboolean yrcd_yrcd_user_get_reg_complete (yrcdyrcd_user* self) {
	gboolean result;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_reg_complete;
	result = _tmp0_;
	return result;
}


void yrcd_yrcd_user_set_reg_complete (yrcdyrcd_user* self, gboolean value) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_reg_complete = _tmp0_;
	g_object_notify ((GObject *) self, "reg-complete");
}


static void yrcd_yrcd_user_class_init (yrcdyrcd_userClass * klass) {
	yrcd_yrcd_user_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (yrcdyrcd_userPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_yrcd_yrcd_user_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_yrcd_yrcd_user_set_property;
	G_OBJECT_CLASS (klass)->finalize = yrcd_yrcd_user_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_YRCD_USER_SOCK, g_param_spec_object ("sock", "sock", "sock", G_TYPE_SOCKET_CONNECTION, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_YRCD_USER_DIS, g_param_spec_object ("dis", "dis", "dis", G_TYPE_DATA_INPUT_STREAM, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_YRCD_USER_DOS, g_param_spec_object ("dos", "dos", "dos", g_data_output_stream_get_type (), G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_YRCD_USER_SERVER, g_param_spec_object ("server", "server", "server", YRCD_TYPE_YRCD_SERVER, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_YRCD_USER_ID, g_param_spec_int ("id", "id", "id", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_YRCD_USER_NICK, g_param_spec_string ("nick", "nick", "nick", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_YRCD_USER_IDENT, g_param_spec_string ("ident", "ident", "ident", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_YRCD_USER_REALNAME, g_param_spec_string ("realname", "realname", "realname", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_YRCD_USER_NICK_SET, g_param_spec_boolean ("nick-set", "nick-set", "nick-set", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_YRCD_USER_USER_SET, g_param_spec_boolean ("user-set", "user-set", "user-set", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), YRCD_YRCD_USER_REG_COMPLETE, g_param_spec_boolean ("reg-complete", "reg-complete", "reg-complete", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void yrcd_yrcd_user_instance_init (yrcdyrcd_user * self) {
	self->priv = YRCD_YRCD_USER_GET_PRIVATE (self);
}


static void yrcd_yrcd_user_finalize (GObject* obj) {
	yrcdyrcd_user * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, YRCD_TYPE_YRCD_USER, yrcdyrcd_user);
	_g_object_unref0 (self->priv->_sock);
	_g_object_unref0 (self->priv->_dis);
	_g_object_unref0 (self->priv->_dos);
	_g_object_unref0 (self->priv->_server);
	_g_free0 (self->priv->_nick);
	_g_free0 (self->priv->_ident);
	_g_free0 (self->priv->_realname);
	G_OBJECT_CLASS (yrcd_yrcd_user_parent_class)->finalize (obj);
}


GType yrcd_yrcd_user_get_type (void) {
	static volatile gsize yrcd_yrcd_user_type_id__volatile = 0;
	if (g_once_init_enter (&yrcd_yrcd_user_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (yrcdyrcd_userClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) yrcd_yrcd_user_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (yrcdyrcd_user), 0, (GInstanceInitFunc) yrcd_yrcd_user_instance_init, NULL };
		GType yrcd_yrcd_user_type_id;
		yrcd_yrcd_user_type_id = g_type_register_static (G_TYPE_OBJECT, "yrcdyrcd_user", &g_define_type_info, 0);
		g_once_init_leave (&yrcd_yrcd_user_type_id__volatile, yrcd_yrcd_user_type_id);
	}
	return yrcd_yrcd_user_type_id__volatile;
}


static void _vala_yrcd_yrcd_user_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	yrcdyrcd_user * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, YRCD_TYPE_YRCD_USER, yrcdyrcd_user);
	switch (property_id) {
		case YRCD_YRCD_USER_SOCK:
		g_value_set_object (value, yrcd_yrcd_user_get_sock (self));
		break;
		case YRCD_YRCD_USER_DIS:
		g_value_set_object (value, yrcd_yrcd_user_get_dis (self));
		break;
		case YRCD_YRCD_USER_DOS:
		g_value_set_object (value, yrcd_yrcd_user_get_dos (self));
		break;
		case YRCD_YRCD_USER_SERVER:
		g_value_set_object (value, yrcd_yrcd_user_get_server (self));
		break;
		case YRCD_YRCD_USER_ID:
		g_value_set_int (value, yrcd_yrcd_user_get_id (self));
		break;
		case YRCD_YRCD_USER_NICK:
		g_value_set_string (value, yrcd_yrcd_user_get_nick (self));
		break;
		case YRCD_YRCD_USER_IDENT:
		g_value_set_string (value, yrcd_yrcd_user_get_ident (self));
		break;
		case YRCD_YRCD_USER_REALNAME:
		g_value_set_string (value, yrcd_yrcd_user_get_realname (self));
		break;
		case YRCD_YRCD_USER_NICK_SET:
		g_value_set_boolean (value, yrcd_yrcd_user_get_nick_set (self));
		break;
		case YRCD_YRCD_USER_USER_SET:
		g_value_set_boolean (value, yrcd_yrcd_user_get_user_set (self));
		break;
		case YRCD_YRCD_USER_REG_COMPLETE:
		g_value_set_boolean (value, yrcd_yrcd_user_get_reg_complete (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_yrcd_yrcd_user_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	yrcdyrcd_user * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, YRCD_TYPE_YRCD_USER, yrcdyrcd_user);
	switch (property_id) {
		case YRCD_YRCD_USER_SOCK:
		yrcd_yrcd_user_set_sock (self, g_value_get_object (value));
		break;
		case YRCD_YRCD_USER_DIS:
		yrcd_yrcd_user_set_dis (self, g_value_get_object (value));
		break;
		case YRCD_YRCD_USER_DOS:
		yrcd_yrcd_user_set_dos (self, g_value_get_object (value));
		break;
		case YRCD_YRCD_USER_SERVER:
		yrcd_yrcd_user_set_server (self, g_value_get_object (value));
		break;
		case YRCD_YRCD_USER_ID:
		yrcd_yrcd_user_set_id (self, g_value_get_int (value));
		break;
		case YRCD_YRCD_USER_NICK:
		yrcd_yrcd_user_set_nick (self, g_value_get_string (value));
		break;
		case YRCD_YRCD_USER_IDENT:
		yrcd_yrcd_user_set_ident (self, g_value_get_string (value));
		break;
		case YRCD_YRCD_USER_REALNAME:
		yrcd_yrcd_user_set_realname (self, g_value_get_string (value));
		break;
		case YRCD_YRCD_USER_NICK_SET:
		yrcd_yrcd_user_set_nick_set (self, g_value_get_boolean (value));
		break;
		case YRCD_YRCD_USER_USER_SET:
		yrcd_yrcd_user_set_user_set (self, g_value_get_boolean (value));
		break;
		case YRCD_YRCD_USER_REG_COMPLETE:
		yrcd_yrcd_user_set_reg_complete (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



