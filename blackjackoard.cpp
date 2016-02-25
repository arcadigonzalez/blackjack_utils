// helloask.cxx (example2a)

#include <FL/Fl.H>
#include <FL/Fl_Window.h>
#include <FL/Fl_Box.h>

int main( ) {
  Fl_Window *window = new Fl_Window(1200, 700);
  window->begin();
  Fl_box *box= new fl_draw_box(Fl_FLAT_BOX, 10, 10, 1180, 680, Fl_GREEN);;
  box->box(FL_UP_BOX);
  box->labelfont(FL_HELVETICA_BOLD_ITALIC);
  box->labelsize(36);
  box->labeltype(FL_SHADOW_LABEL);
  window->end();
  window->show();
  return Fl::run();
}

