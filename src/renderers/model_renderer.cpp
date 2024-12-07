#include "model_renderer.h"
#include "model.h"

#include <iostream>

ModelRenderer::~ModelRenderer() { delete this->model; }

void ModelRenderer::init(Model *m) { this->model = m; }

void ModelRenderer::render() { this->render_model(); }

void ModelRenderer::render_model() {
  std::cout << "RENDERING MODEL" << std::endl;
}