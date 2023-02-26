
'use strict';

let externrefs = {};
let externsym = Symbol("externref");
function externref(s) {
  if (! (s in externrefs)) externrefs[s] = {[externsym]: s};
  return externrefs[s];
}
function is_externref(x) {
  return (x !== null && externsym in x) ? 1 : 0;
}
function is_funcref(x) {
  return typeof x === "function" ? 1 : 0;
}
function eq_externref(x, y) {
  return x === y ? 1 : 0;
}
function eq_funcref(x, y) {
  return x === y ? 1 : 0;
}

let spectest = {
  externref: externref,
  is_externref: is_externref,
  is_funcref: is_funcref,
  eq_externref: eq_externref,
  eq_funcref: eq_funcref,
  print: console.log.bind(console),
  print_i32: console.log.bind(console),
  print_i32_f32: console.log.bind(console),
  print_f64_f64: console.log.bind(console),
  print_f32: console.log.bind(console),
  print_f64: console.log.bind(console),
  global_i32: 666,
  global_i64: 666n,
  global_f32: 666,
  global_f64: 666,
  table: new WebAssembly.Table({initial: 10, maximum: 20, element: 'anyfunc'}),
  memory: new WebAssembly.Memory({initial: 1, maximum: 2})
};

let handler = {
  get(target, prop) {
    return (prop in target) ?  target[prop] : {};
  }
};
let registry = new Proxy({spectest}, handler);

function register(name, instance) {
  registry[name] = instance.exports;
}

function module(bytes, valid = true) {
  let buffer = new ArrayBuffer(bytes.length);
  let view = new Uint8Array(buffer);
  for (let i = 0; i < bytes.length; ++i) {
    view[i] = bytes.charCodeAt(i);
  }
  let validated;
  try {
    validated = WebAssembly.validate(buffer);
  } catch (e) {
    throw new Error("Wasm validate throws");
  }
  if (validated !== valid) {
    throw new Error("Wasm validate failure" + (valid ? "" : " expected"));
  }
  return new WebAssembly.Module(buffer);
}

function instance(bytes, imports = registry) {
  return new WebAssembly.Instance(module(bytes), imports);
}

function call(instance, name, args) {
  return instance.exports[name](...args);
}

function get(instance, name) {
  let v = instance.exports[name];
  return (v instanceof WebAssembly.Global) ? v.value : v;
}

function exports(instance) {
  return {module: instance.exports, spectest: spectest};
}

function run(action) {
  action();
}

function assert_malformed(bytes) {
  try { module(bytes, false) } catch (e) {
    if (e instanceof WebAssembly.CompileError) return;
  }
  throw new Error("Wasm decoding failure expected");
}

function assert_invalid(bytes) {
  try { module(bytes, false) } catch (e) {
    if (e instanceof WebAssembly.CompileError) return;
  }
  throw new Error("Wasm validation failure expected");
}

function assert_unlinkable(bytes) {
  let mod = module(bytes);
  try { new WebAssembly.Instance(mod, registry) } catch (e) {
    if (e instanceof WebAssembly.LinkError) return;
  }
  throw new Error("Wasm linking failure expected");
}

function assert_uninstantiable(bytes) {
  let mod = module(bytes);
  try { new WebAssembly.Instance(mod, registry) } catch (e) {
    if (e instanceof WebAssembly.RuntimeError) return;
  }
  throw new Error("Wasm trap expected");
}

function assert_trap(action) {
  try { action() } catch (e) {
    if (e instanceof WebAssembly.RuntimeError) return;
  }
  throw new Error("Wasm trap expected");
}

let StackOverflow;
try { (function f() { 1 + f() })() } catch (e) { StackOverflow = e.constructor }

function assert_exhaustion(action) {
  try { action() } catch (e) {
    if (e instanceof StackOverflow) return;
  }
  throw new Error("Wasm resource exhaustion expected");
}

function assert_return(action, ...expected) {
  let actual = action();
  if (actual === undefined) {
    actual = [];
  } else if (!Array.isArray(actual)) {
    actual = [actual];
  }
  if (actual.length !== expected.length) {
    throw new Error(expected.length + " value(s) expected, got " + actual.length);
  }
  for (let i = 0; i < actual.length; ++i) {
    switch (expected[i]) {
      case "nan:canonical":
      case "nan:arithmetic":
      case "nan:any":
        // Note that JS can't reliably distinguish different NaN values,
        // so there's no good way to test that it's a canonical NaN.
        if (!Number.isNaN(actual[i])) {
          throw new Error("Wasm return value NaN expected, got " + actual[i]);
        };
        return;
      case "ref.func":
        if (typeof actual[i] !== "function") {
          throw new Error("Wasm function return value expected, got " + actual[i]);
        };
        return;
      case "ref.extern":
        if (actual[i] === null) {
          throw new Error("Wasm reference return value expected, got " + actual[i]);
        };
        return;
      default:
        if (!Object.is(actual[i], expected[i])) {
          throw new Error("Wasm return value " + expected[i] + " expected, got " + actual[i]);
        };
    }
  }
}

// simd_load32_lane.wast:4
let $1 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x8c\x80\x80\x80\x00\x02\x60\x02\x7f\x7b\x01\x7b\x60\x01\x7b\x01\x7b\x03\x95\x80\x80\x80\x00\x14\x00\x00\x00\x00\x01\x01\x01\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x07\xa9\x84\x80\x80\x00\x14\x12\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x30\x00\x00\x12\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x31\x00\x01\x12\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x32\x00\x02\x12\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x33\x00\x03\x1b\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x30\x5f\x6f\x66\x66\x73\x65\x74\x5f\x30\x00\x04\x1b\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x31\x5f\x6f\x66\x66\x73\x65\x74\x5f\x31\x00\x05\x1b\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x32\x5f\x6f\x66\x66\x73\x65\x74\x5f\x32\x00\x06\x1b\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x33\x5f\x6f\x66\x66\x73\x65\x74\x5f\x33\x00\x07\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x30\x5f\x61\x6c\x69\x67\x6e\x5f\x31\x00\x08\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x30\x5f\x61\x6c\x69\x67\x6e\x5f\x32\x00\x09\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x30\x5f\x61\x6c\x69\x67\x6e\x5f\x34\x00\x0a\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x31\x5f\x61\x6c\x69\x67\x6e\x5f\x31\x00\x0b\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x31\x5f\x61\x6c\x69\x67\x6e\x5f\x32\x00\x0c\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x31\x5f\x61\x6c\x69\x67\x6e\x5f\x34\x00\x0d\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x32\x5f\x61\x6c\x69\x67\x6e\x5f\x31\x00\x0e\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x32\x5f\x61\x6c\x69\x67\x6e\x5f\x32\x00\x0f\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x32\x5f\x61\x6c\x69\x67\x6e\x5f\x34\x00\x10\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x33\x5f\x61\x6c\x69\x67\x6e\x5f\x31\x00\x11\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x33\x5f\x61\x6c\x69\x67\x6e\x5f\x32\x00\x12\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x33\x5f\x61\x6c\x69\x67\x6e\x5f\x34\x00\x13\x0a\xc1\x82\x80\x80\x00\x14\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x02\x00\x00\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x02\x00\x01\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x02\x00\x02\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x02\x00\x03\x0b\x8b\x80\x80\x80\x00\x00\x41\x00\x20\x00\xfd\x56\x02\x00\x00\x0b\x8b\x80\x80\x80\x00\x00\x41\x00\x20\x00\xfd\x56\x02\x01\x01\x0b\x8b\x80\x80\x80\x00\x00\x41\x00\x20\x00\xfd\x56\x02\x02\x02\x0b\x8b\x80\x80\x80\x00\x00\x41\x00\x20\x00\xfd\x56\x02\x03\x03\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x00\x00\x00\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x01\x00\x00\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x02\x00\x00\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x00\x00\x01\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x01\x00\x01\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x02\x00\x01\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x00\x00\x02\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x01\x00\x02\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x02\x00\x02\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x00\x00\x03\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x01\x00\x03\x0b\x8b\x80\x80\x80\x00\x00\x20\x00\x20\x01\xfd\x56\x02\x00\x03\x0b\x0b\x96\x80\x80\x80\x00\x01\x00\x41\x00\x0b\x10\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f");

// simd_load32_lane.wast:69
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x8e\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x12\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x30\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x00\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x01\x02\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_0", [0, v128("0 0 0 0")]), v128("50_462_976 0 0 0"))

// simd_load32_lane.wast:72
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x8e\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x12\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x31\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x01\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x01\x02\x03\x04\x00\x00\x00\x00\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_1", [1, v128("0 0 0 0")]), v128("0 67_305_985 0 0"))

// simd_load32_lane.wast:75
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x8e\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x12\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x32\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x02\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x02\x03\x04\x05\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_2", [2, v128("0 0 0 0")]), v128("0 0 84_148_994 0"))

// simd_load32_lane.wast:78
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x8e\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x12\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x33\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x03\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03\x04\x05\x06\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_3", [3, v128("0 0 0 0")]), v128("0 0 0 100_992_003"))

// simd_load32_lane.wast:81
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa4\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x01\x7b\x01\x7b\x02\x97\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1b\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x30\x5f\x6f\x66\x66\x73\x65\x74\x5f\x30\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xce\x80\x80\x80\x00\x01\xc8\x80\x80\x80\x00\x00\x02\x40\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x01\x02\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_0_offset_0", [v128("0 0 0 0")]), v128("50_462_976 0 0 0"))

// simd_load32_lane.wast:83
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa4\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x01\x7b\x01\x7b\x02\x97\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1b\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x31\x5f\x6f\x66\x66\x73\x65\x74\x5f\x31\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xce\x80\x80\x80\x00\x01\xc8\x80\x80\x80\x00\x00\x02\x40\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x01\x02\x03\x04\x00\x00\x00\x00\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_1_offset_1", [v128("0 0 0 0")]), v128("0 67_305_985 0 0"))

// simd_load32_lane.wast:85
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa4\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x01\x7b\x01\x7b\x02\x97\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1b\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x32\x5f\x6f\x66\x66\x73\x65\x74\x5f\x32\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xce\x80\x80\x80\x00\x01\xc8\x80\x80\x80\x00\x00\x02\x40\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x02\x03\x04\x05\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_2_offset_2", [v128("0 0 0 0")]), v128("0 0 84_148_994 0"))

// simd_load32_lane.wast:87
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa4\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x01\x7b\x01\x7b\x02\x97\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1b\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x33\x5f\x6f\x66\x66\x73\x65\x74\x5f\x33\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xce\x80\x80\x80\x00\x01\xc8\x80\x80\x80\x00\x00\x02\x40\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03\x04\x05\x06\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_3_offset_3", [v128("0 0 0 0")]), v128("0 0 0 100_992_003"))

// simd_load32_lane.wast:89
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x96\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x30\x5f\x61\x6c\x69\x67\x6e\x5f\x31\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x00\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x01\x02\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_0_align_1", [0, v128("0 0 0 0")]), v128("50_462_976 0 0 0"))

// simd_load32_lane.wast:92
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x96\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x30\x5f\x61\x6c\x69\x67\x6e\x5f\x32\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x00\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x01\x02\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_0_align_2", [0, v128("0 0 0 0")]), v128("50_462_976 0 0 0"))

// simd_load32_lane.wast:95
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x96\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x30\x5f\x61\x6c\x69\x67\x6e\x5f\x34\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x00\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x01\x02\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_0_align_4", [0, v128("0 0 0 0")]), v128("50_462_976 0 0 0"))

// simd_load32_lane.wast:98
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x96\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x31\x5f\x61\x6c\x69\x67\x6e\x5f\x31\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x01\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x01\x02\x03\x04\x00\x00\x00\x00\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_1_align_1", [1, v128("0 0 0 0")]), v128("0 67_305_985 0 0"))

// simd_load32_lane.wast:101
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x96\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x31\x5f\x61\x6c\x69\x67\x6e\x5f\x32\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x01\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x01\x02\x03\x04\x00\x00\x00\x00\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_1_align_2", [1, v128("0 0 0 0")]), v128("0 67_305_985 0 0"))

// simd_load32_lane.wast:104
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x96\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x31\x5f\x61\x6c\x69\x67\x6e\x5f\x34\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x01\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x01\x02\x03\x04\x00\x00\x00\x00\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_1_align_4", [1, v128("0 0 0 0")]), v128("0 67_305_985 0 0"))

// simd_load32_lane.wast:107
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x96\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x32\x5f\x61\x6c\x69\x67\x6e\x5f\x31\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x02\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x02\x03\x04\x05\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_2_align_1", [2, v128("0 0 0 0")]), v128("0 0 84_148_994 0"))

// simd_load32_lane.wast:110
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x96\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x32\x5f\x61\x6c\x69\x67\x6e\x5f\x32\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x02\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x02\x03\x04\x05\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_2_align_2", [2, v128("0 0 0 0")]), v128("0 0 84_148_994 0"))

// simd_load32_lane.wast:113
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x96\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x32\x5f\x61\x6c\x69\x67\x6e\x5f\x34\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x02\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x02\x03\x04\x05\x00\x00\x00\x00\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_2_align_4", [2, v128("0 0 0 0")]), v128("0 0 84_148_994 0"))

// simd_load32_lane.wast:116
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x96\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x33\x5f\x61\x6c\x69\x67\x6e\x5f\x31\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x03\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03\x04\x05\x06\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_3_align_1", [3, v128("0 0 0 0")]), v128("0 0 0 100_992_003"))

// simd_load32_lane.wast:119
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x96\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x33\x5f\x61\x6c\x69\x67\x6e\x5f\x32\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x03\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03\x04\x05\x06\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_3_align_2", [3, v128("0 0 0 0")]), v128("0 0 0 100_992_003"))

// simd_load32_lane.wast:122
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\xa5\x80\x80\x80\x00\x07\x60\x00\x00\x60\x01\x7f\x01\x6f\x60\x01\x6f\x01\x7f\x60\x01\x70\x01\x7f\x60\x02\x6f\x6f\x01\x7f\x60\x02\x70\x70\x01\x7f\x60\x02\x7f\x7b\x01\x7b\x02\x96\x81\x80\x80\x00\x06\x06\x6d\x6f\x64\x75\x6c\x65\x1a\x76\x31\x32\x38\x2e\x6c\x6f\x61\x64\x33\x32\x5f\x6c\x61\x6e\x65\x5f\x33\x5f\x61\x6c\x69\x67\x6e\x5f\x34\x00\x06\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x69\x73\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x02\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x69\x73\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x03\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0c\x65\x71\x5f\x65\x78\x74\x65\x72\x6e\x72\x65\x66\x00\x04\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x65\x71\x5f\x66\x75\x6e\x63\x72\x65\x66\x00\x05\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x06\x0a\xd0\x80\x80\x80\x00\x01\xca\x80\x80\x80\x00\x00\x02\x40\x41\x03\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\xfd\x0c\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\x4e\xfd\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03\x04\x05\x06\xfd\x23\xfd\x63\x45\x0d\x00\x0f\x0b\x00\x0b", exports($1)),  "run", []));  // assert_return(() => call($1, "v128.load32_lane_3_align_4", [3, v128("0 0 0 0")]), v128("0 0 0 100_992_003"))

// simd_load32_lane.wast:127
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7b\x01\x7b\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x0a\x91\x80\x80\x80\x00\x01\x8b\x80\x80\x80\x00\x00\x20\x00\x41\x00\xfd\x56\x02\x00\x00\x0b");

// simd_load32_lane.wast:133
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7b\x01\x7b\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x0a\x91\x80\x80\x80\x00\x01\x8b\x80\x80\x80\x00\x00\x41\x00\x20\x00\xfd\x56\x02\x00\x04\x0b");

// simd_load32_lane.wast:139
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7b\x01\x7b\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x01\x0a\x91\x80\x80\x80\x00\x01\x8b\x80\x80\x80\x00\x00\x41\x00\x20\x00\xfd\x56\x03\x00\x00\x0b");
