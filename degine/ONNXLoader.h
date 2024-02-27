#pragma once
#include "degine/DegineContext.h"
#include "degine/Loader.h"
#include "degine/ir/Graph.h"
#include "degine/proto/onnx.pb.h"

namespace degine {

class ONNXLoader : public LoaderBase {
public:
  using LoaderBase::LoaderBase;

  Graph Load(std::string fname) {
    onnx::Model m;
    std::ifstream ifs(fname, std::ios::in | std::ios::binary);
    if (!m.ParseFromIstream(&ifs)) {
      throw std::runtime_error("load onnx model failed");
    }
    DegineContext *ctx = GetCtx();
    Graph g = ctx->NewGraph(fname);
    // TODO: impl
    return g;
  }
};

} // namespace degine

DECLARE_MODEL_LOADER("onnx", degine::ONNXLoader)
