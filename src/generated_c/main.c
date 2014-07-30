/* main.c generated by valac 0.25.1, the Vala compiler
 * generated from main.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>


#define YRCD_TYPE_CONFIG (yrcd_config_get_type ())
#define YRCD_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_CONFIG, yrcdConfig))
#define YRCD_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_CONFIG, yrcdConfigClass))
#define YRCD_IS_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_CONFIG))
#define YRCD_IS_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_CONFIG))
#define YRCD_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_CONFIG, yrcdConfigClass))

typedef struct _yrcdConfig yrcdConfig;
typedef struct _yrcdConfigClass yrcdConfigClass;
typedef struct _yrcdConfigPrivate yrcdConfigPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define YRCD_TYPE_SERVER (yrcd_server_get_type ())
#define YRCD_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), YRCD_TYPE_SERVER, yrcdServer))
#define YRCD_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), YRCD_TYPE_SERVER, yrcdServerClass))
#define YRCD_IS_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YRCD_TYPE_SERVER))
#define YRCD_IS_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), YRCD_TYPE_SERVER))
#define YRCD_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), YRCD_TYPE_SERVER, yrcdServerClass))

typedef struct _yrcdServer yrcdServer;
typedef struct _yrcdServerClass yrcdServerClass;
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))

struct _yrcdConfig {
	GObject parent_instance;
	yrcdConfigPrivate * priv;
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

struct _yrcdConfigClass {
	GObjectClass parent_class;
};



void yrcd_main (void);
GType yrcd_config_get_type (void) G_GNUC_CONST;
yrcdConfig* yrcd_config_new (const gchar* filepath);
yrcdConfig* yrcd_config_construct (GType object_type, const gchar* filepath);
GType yrcd_server_get_type (void) G_GNUC_CONST;
yrcdServer* yrcd_server_new (yrcdConfig* _config);
yrcdServer* yrcd_server_construct (GType object_type, yrcdConfig* _config);
void yrcd_server_log (yrcdServer* self, const gchar* msg);


void yrcd_main (void) {
	yrcdConfig* config = NULL;
	yrcdConfig* _tmp0_ = NULL;
	yrcdConfig* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	GMainLoop* loop = NULL;
	GMainLoop* _tmp3_ = NULL;
	yrcdServer* server = NULL;
	yrcdConfig* _tmp4_ = NULL;
	yrcdServer* _tmp5_ = NULL;
	GMainLoop* _tmp6_ = NULL;
	yrcdServer* _tmp7_ = NULL;
	_tmp0_ = yrcd_config_new ("yrcd.config");
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
	_tmp5_ = yrcd_server_new (_tmp4_);
	server = _tmp5_;
	_tmp6_ = loop;
	g_main_loop_run (_tmp6_);
	_tmp7_ = server;
	yrcd_server_log (_tmp7_, "For some reason, we're all done here.... goodbye");
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



