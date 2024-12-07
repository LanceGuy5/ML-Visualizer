#ifndef MODEL_RENDERER_H
#define MODEL_RENDERER_H

#include <QWidget>
class Model;

class ModelRenderer : public QWidget {
public:
  explicit ModelRenderer(QWidget *parent = nullptr) : QWidget(parent) {};
  ~ModelRenderer();
  void init(Model *m);
  void render();

private:
  Model *model;
  void render_model();
};

#endif // MAIN_WINDOW_H
