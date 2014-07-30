/* main.c generated by valac 0.24.0, the Vala compiler
 * generated from main.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>


#define YRCD_TYPE_YRCD_CONFIG (yrcd_yrcd_config_get_type ())
#define YRCD_YRCD_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_CONFIG, yrcdyrcd_config))
#define YRCD_YRCD_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_CONFIG, yrcdyrcd_configClass))
#define YRCD_IS_YRCD_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_CONFIG))
#define YRCD_IS_YRCD_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_CONFIG))
#define YRCD_YRCD_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_CONFIG, yrcdyrcd_configClass))

typedef struct _yrcdyrcd_config yrcdyrcd_config;
typedef struct _yrcdyrcd_configClass yrcdyrcd_configClass;
typedef struct _yrcdyrcd_configPrivate yrcdyrcd_configPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define YRCD_TYPE_YRCD_SERVER (yrcd_yrcd_server_get_type ())
#define YRCD_YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_server))
#define YRCD_YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverClass))
#define YRCD_IS_YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_YRCD_SERVER))
#define YRCD_IS_YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_YRCD_SERVER))
#define YRCD_YRCD_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_YRCD_SERVER, yrcdyrcd_serverClass))

typedef struct _yrcdyrcd_server yrcdyrcd_server;
typedef struct _yrcdyrcd_serverClass yrcdyrcd_serverClass;
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))

struct _yrcdyrcd_config {
	GObject parent_instance;
	yrcdyrcd_configPrivate * priv;
	GList* listen_ports;
	gchar** listen_ips;
	gint listen_ips_length1;
	GList* motd;
	gint ping_invertal;
	gint max_users;
	gboolean config_error;
	gboolean cloaking;
	gchar* salt;
};

struct _yrcdyrcd_configClass {
	GObjectClass parent_class;
};



void yrcd_main (void);
GType yrcd_yrcd_config_get_type (void) G_GNUC_CONST;
yrcdyrcd_config* yrcd_yrcd_config_new (const gchar* filepath);
yrcdyrcd_config* yrcd_yrcd_config_construct (GType object_type, const gchar* filepath);
GType yrcd_yrcd_server_get_type (void) G_GNUC_CONST;
yrcdyrcd_server* yrcd_yrcd_server_new (yrcdyrcd_config* _config);
yrcdyrcd_server* yrcd_yrcd_server_construct (GType object_type, yrcdyrcd_config* _config);
void yrcd_yrcd_server_log (yrcdyrcd_server* self, const gchar* msg);


void yrcd_main (void) {
	yrcdyrcd_config* config = NULL;
	yrcdyrcd_config* _tmp0_ = NULL;
	yrcdyrcd_config* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	GMainLoop* loop = NULL;
	GMainLoop* _tmp3_ = NULL;
	yrcdyrcd_server* server = NULL;
	yrcdyrcd_config* _tmp4_ = NULL;
	yrcdyrcd_server* _tmp5_ = NULL;
	GMainLoop* _tmp6_ = NULL;
	yrcdyrcd_server* _tmp7_ = NULL;
	_tmp0_ = yrcd_yrcd_config_new ("yrcd.config");
	config = _tmp0_;
	_tmp1_ = config;
	_tmp2_ = _tmp1_->config_error;
	if (_tmp2_) {
		_g_object_unref0 (config);
		return;
	}
	_tmp3_ = g_main_loop_new (NULL, FALSE);
	loop = _tmp3_;
	_tmp4_ = config;
	_tmp5_ = yrcd_yrcd_server_new (_tmp4_);
	server = _tmp5_;
	_tmp6_ = loop;
	g_main_loop_run (_tmp6_);
	_tmp7_ = server;
	yrcd_yrcd_server_log (_tmp7_, "For some reason, we're all done here.... goodbye");
	_g_object_unref0 (server);
	_g_main_loop_unref0 (loop);
	_g_object_unref0 (config);
}


int main (int argc, char ** argv) {
#if !GLIB_CHECK_VERSION (2,35,0)
	g_type_init ();
#endif
	yrcd_main ();
	return 0;
}



