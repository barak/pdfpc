/* base.c generated by valac 0.16.0, the Vala compiler
 * generated from base.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_TYPE_BASE (org_westhoffswelt_pdfpresenter_metadata_base_get_type ())
#define ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_BASE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_TYPE_BASE, orgwesthoffsweltpdfpresenterMetadataBase))
#define ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_BASE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_TYPE_BASE, orgwesthoffsweltpdfpresenterMetadataBaseClass))
#define ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_IS_BASE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_TYPE_BASE))
#define ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_IS_BASE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_TYPE_BASE))
#define ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_BASE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_TYPE_BASE, orgwesthoffsweltpdfpresenterMetadataBaseClass))

typedef struct _orgwesthoffsweltpdfpresenterMetadataBase orgwesthoffsweltpdfpresenterMetadataBase;
typedef struct _orgwesthoffsweltpdfpresenterMetadataBaseClass orgwesthoffsweltpdfpresenterMetadataBaseClass;
typedef struct _orgwesthoffsweltpdfpresenterMetadataBasePrivate orgwesthoffsweltpdfpresenterMetadataBasePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _orgwesthoffsweltpdfpresenterMetadataBase {
	GObject parent_instance;
	orgwesthoffsweltpdfpresenterMetadataBasePrivate * priv;
	gchar* fname;
	gchar* url;
};

struct _orgwesthoffsweltpdfpresenterMetadataBaseClass {
	GObjectClass parent_class;
	guint (*get_slide_count) (orgwesthoffsweltpdfpresenterMetadataBase* self);
};


static gpointer org_westhoffswelt_pdfpresenter_metadata_base_parent_class = NULL;

GType org_westhoffswelt_pdfpresenter_metadata_base_get_type (void) G_GNUC_CONST;
enum  {
	ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_BASE_DUMMY_PROPERTY
};
orgwesthoffsweltpdfpresenterMetadataBase* org_westhoffswelt_pdfpresenter_metadata_base_construct (GType object_type, const gchar* fname);
gchar* org_westhoffswelt_pdfpresenter_metadata_base_get_url (orgwesthoffsweltpdfpresenterMetadataBase* self);
guint org_westhoffswelt_pdfpresenter_metadata_base_get_slide_count (orgwesthoffsweltpdfpresenterMetadataBase* self);
static guint org_westhoffswelt_pdfpresenter_metadata_base_real_get_slide_count (orgwesthoffsweltpdfpresenterMetadataBase* self);
static void org_westhoffswelt_pdfpresenter_metadata_base_finalize (GObject* obj);


/**
         * Base constructor taking the url to specifiy the slideset as argument
         */
orgwesthoffsweltpdfpresenterMetadataBase* org_westhoffswelt_pdfpresenter_metadata_base_construct (GType object_type, const gchar* fname) {
	orgwesthoffsweltpdfpresenterMetadataBase * self = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	const gchar* _tmp2_;
	GFile* _tmp3_ = NULL;
	GFile* _tmp4_;
	gchar* _tmp5_ = NULL;
	g_return_val_if_fail (fname != NULL, NULL);
	self = (orgwesthoffsweltpdfpresenterMetadataBase*) g_object_new (object_type, NULL);
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
gchar* org_westhoffswelt_pdfpresenter_metadata_base_get_url (orgwesthoffsweltpdfpresenterMetadataBase* self) {
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
static guint org_westhoffswelt_pdfpresenter_metadata_base_real_get_slide_count (orgwesthoffsweltpdfpresenterMetadataBase* self) {
	g_critical ("Type `%s' does not implement abstract method `org_westhoffswelt_pdfpresenter_metadata_base_get_slide_count'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return 0U;
}


guint org_westhoffswelt_pdfpresenter_metadata_base_get_slide_count (orgwesthoffsweltpdfpresenterMetadataBase* self) {
	g_return_val_if_fail (self != NULL, 0U);
	return ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_BASE_GET_CLASS (self)->get_slide_count (self);
}


static void org_westhoffswelt_pdfpresenter_metadata_base_class_init (orgwesthoffsweltpdfpresenterMetadataBaseClass * klass) {
	org_westhoffswelt_pdfpresenter_metadata_base_parent_class = g_type_class_peek_parent (klass);
	ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_BASE_CLASS (klass)->get_slide_count = org_westhoffswelt_pdfpresenter_metadata_base_real_get_slide_count;
	G_OBJECT_CLASS (klass)->finalize = org_westhoffswelt_pdfpresenter_metadata_base_finalize;
}


static void org_westhoffswelt_pdfpresenter_metadata_base_instance_init (orgwesthoffsweltpdfpresenterMetadataBase * self) {
}


static void org_westhoffswelt_pdfpresenter_metadata_base_finalize (GObject* obj) {
	orgwesthoffsweltpdfpresenterMetadataBase * self;
	self = ORG_WESTHOFFSWELT_PDFPRESENTER_METADATA_BASE (obj);
	_g_free0 (self->fname);
	_g_free0 (self->url);
	G_OBJECT_CLASS (org_westhoffswelt_pdfpresenter_metadata_base_parent_class)->finalize (obj);
}


/**
     * Metadata base class describing the basic metadata needed for every
     * slideset
     */
GType org_westhoffswelt_pdfpresenter_metadata_base_get_type (void) {
	static volatile gsize org_westhoffswelt_pdfpresenter_metadata_base_type_id__volatile = 0;
	if (g_once_init_enter (&org_westhoffswelt_pdfpresenter_metadata_base_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (orgwesthoffsweltpdfpresenterMetadataBaseClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) org_westhoffswelt_pdfpresenter_metadata_base_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (orgwesthoffsweltpdfpresenterMetadataBase), 0, (GInstanceInitFunc) org_westhoffswelt_pdfpresenter_metadata_base_instance_init, NULL };
		GType org_westhoffswelt_pdfpresenter_metadata_base_type_id;
		org_westhoffswelt_pdfpresenter_metadata_base_type_id = g_type_register_static (G_TYPE_OBJECT, "orgwesthoffsweltpdfpresenterMetadataBase", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&org_westhoffswelt_pdfpresenter_metadata_base_type_id__volatile, org_westhoffswelt_pdfpresenter_metadata_base_type_id);
	}
	return org_westhoffswelt_pdfpresenter_metadata_base_type_id__volatile;
}



