/* base.c generated by valac 0.16.0, the Vala compiler
 * generated from base.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define PDFPC_METADATA_TYPE_BASE (pdfpc_metadata_base_get_type ())
#define PDFPC_METADATA_BASE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PDFPC_METADATA_TYPE_BASE, pdfpcMetadataBase))
#define PDFPC_METADATA_BASE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PDFPC_METADATA_TYPE_BASE, pdfpcMetadataBaseClass))
#define PDFPC_METADATA_IS_BASE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PDFPC_METADATA_TYPE_BASE))
#define PDFPC_METADATA_IS_BASE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PDFPC_METADATA_TYPE_BASE))
#define PDFPC_METADATA_BASE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PDFPC_METADATA_TYPE_BASE, pdfpcMetadataBaseClass))

typedef struct _pdfpcMetadataBase pdfpcMetadataBase;
typedef struct _pdfpcMetadataBaseClass pdfpcMetadataBaseClass;
typedef struct _pdfpcMetadataBasePrivate pdfpcMetadataBasePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _pdfpcMetadataBase {
	GObject parent_instance;
	pdfpcMetadataBasePrivate * priv;
	gchar* fname;
	gchar* url;
};

struct _pdfpcMetadataBaseClass {
	GObjectClass parent_class;
	guint (*get_slide_count) (pdfpcMetadataBase* self);
};


static gpointer pdfpc_metadata_base_parent_class = NULL;

GType pdfpc_metadata_base_get_type (void) G_GNUC_CONST;
enum  {
	PDFPC_METADATA_BASE_DUMMY_PROPERTY
};
pdfpcMetadataBase* pdfpc_metadata_base_construct (GType object_type, const gchar* fname);
gchar* pdfpc_metadata_base_get_url (pdfpcMetadataBase* self);
guint pdfpc_metadata_base_get_slide_count (pdfpcMetadataBase* self);
static guint pdfpc_metadata_base_real_get_slide_count (pdfpcMetadataBase* self);
static void pdfpc_metadata_base_finalize (GObject* obj);


/**
         * Base constructor taking the url to specifiy the slideset as argument
         */
pdfpcMetadataBase* pdfpc_metadata_base_construct (GType object_type, const gchar* fname) {
	pdfpcMetadataBase * self = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	const gchar* _tmp2_;
	GFile* _tmp3_ = NULL;
	GFile* _tmp4_;
	gchar* _tmp5_ = NULL;
	g_return_val_if_fail (fname != NULL, NULL);
	self = (pdfpcMetadataBase*) g_object_new (object_type, NULL);
	_tmp0_ = fname;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->fname);
	self->fname = _tmp1_;
	_tmp2_ = fname;
	_tmp3_ = g_file_new_for_commandline_arg (_tmp2_);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_file_get_uri (_tmp4_);
	_g_free0 (self->url);
	self->url = _tmp5_;
	_g_object_unref0 (_tmp4_);
	return self;
}


/**
         * Return the registered url
         */
gchar* pdfpc_metadata_base_get_url (pdfpcMetadataBase* self) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->url;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}


/**
         * Return the number of slides defined by the given url
         */
static guint pdfpc_metadata_base_real_get_slide_count (pdfpcMetadataBase* self) {
	g_critical ("Type `%s' does not implement abstract method `pdfpc_metadata_base_get_slide_count'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return 0U;
}


guint pdfpc_metadata_base_get_slide_count (pdfpcMetadataBase* self) {
	g_return_val_if_fail (self != NULL, 0U);
	return PDFPC_METADATA_BASE_GET_CLASS (self)->get_slide_count (self);
}


static void pdfpc_metadata_base_class_init (pdfpcMetadataBaseClass * klass) {
	pdfpc_metadata_base_parent_class = g_type_class_peek_parent (klass);
	PDFPC_METADATA_BASE_CLASS (klass)->get_slide_count = pdfpc_metadata_base_real_get_slide_count;
	G_OBJECT_CLASS (klass)->finalize = pdfpc_metadata_base_finalize;
}


static void pdfpc_metadata_base_instance_init (pdfpcMetadataBase * self) {
}


static void pdfpc_metadata_base_finalize (GObject* obj) {
	pdfpcMetadataBase * self;
	self = PDFPC_METADATA_BASE (obj);
	_g_free0 (self->fname);
	_g_free0 (self->url);
	G_OBJECT_CLASS (pdfpc_metadata_base_parent_class)->finalize (obj);
}


/**
     * Metadata base class describing the basic metadata needed for every
     * slideset
     */
GType pdfpc_metadata_base_get_type (void) {
	static volatile gsize pdfpc_metadata_base_type_id__volatile = 0;
	if (g_once_init_enter (&pdfpc_metadata_base_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (pdfpcMetadataBaseClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) pdfpc_metadata_base_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (pdfpcMetadataBase), 0, (GInstanceInitFunc) pdfpc_metadata_base_instance_init, NULL };
		GType pdfpc_metadata_base_type_id;
		pdfpc_metadata_base_type_id = g_type_register_static (G_TYPE_OBJECT, "pdfpcMetadataBase", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&pdfpc_metadata_base_type_id__volatile, pdfpc_metadata_base_type_id);
	}
	return pdfpc_metadata_base_type_id__volatile;
}



