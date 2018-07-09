#include <Eina.h>
#include <Elementary.h>

static void
_etui_doc_key_down_cb(void *data,
                      Evas *_e EINA_UNUSED,
                      Evas_Object *_obj EINA_UNUSED,
                      void *event)
{
   exit(0);
}

EAPI_MAIN int
elm_main(int argc, char *argv[])
{
   Eo *win, *sc, *o;

   win = elm_win_util_standard_add("bla", "foo");
   evas_object_show(win);

   /*sc = elm_scroller_add(win);
   evas_object_size_hint_weight_set(sc, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(sc, EVAS_HINT_FILL, EVAS_HINT_FILL);
   evas_object_show(sc);*/


   o = elm_button_add(win);
   evas_object_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(o, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_object_text_set(o, "Test");
   elm_object_content_set(sc, o);
   evas_object_show(o);

   elm_win_resize_object_add(win, o);

   evas_object_event_callback_add(win, EVAS_CALLBACK_KEY_DOWN,
                                   _etui_doc_key_down_cb, NULL);

   evas_object_resize(win, 400, 400);

   elm_run();

   return 1;
}

ELM_MAIN()
