`./physx/source/compiler/cmake/emscripten/PhysXWasmBindings.cmake`
```cmake
-s ENVIRONMENT=web,worker # toggle between `web` to `node` to build for both platforms
```

`./physx/include/foundation/PxPreprocessor.h`
```h
#define PX_CHECKED 1 // changed from 0 to enable debug logging
```
