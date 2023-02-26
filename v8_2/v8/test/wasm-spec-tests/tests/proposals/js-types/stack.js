
'use strict';

let spectest = {
  print: console.log.bind(console),
  print_i32: console.log.bind(console),
  print_i32_f32: console.log.bind(console),
  print_f64_f64: console.log.bind(console),
  print_f32: console.log.bind(console),
  print_f64: console.log.bind(console),
  global_i32: 666,
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

function exports(name, instance) {
  return {[name]: instance.exports};
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
      default:
        if (!Object.is(actual[i], expected[i])) {
          throw new Error("Wasm return value " + expected[i] + " expected, got " + actual[i]);
        };
    }
  }
}

// stack.wast:1
let $1 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7e\x01\x7e\x03\x86\x80\x80\x80\x00\x05\x00\x00\x00\x00\x00\x07\xc4\x80\x80\x80\x00\x05\x08\x66\x61\x63\x2d\x65\x78\x70\x72\x00\x00\x09\x66\x61\x63\x2d\x73\x74\x61\x63\x6b\x00\x01\x0d\x66\x61\x63\x2d\x73\x74\x61\x63\x6b\x2d\x72\x61\x77\x00\x02\x09\x66\x61\x63\x2d\x6d\x69\x78\x65\x64\x00\x03\x0d\x66\x61\x63\x2d\x6d\x69\x78\x65\x64\x2d\x72\x61\x77\x00\x04\x0a\x85\x82\x80\x80\x00\x05\xaf\x80\x80\x80\x00\x01\x02\x7e\x20\x00\x21\x01\x42\x01\x21\x02\x02\x40\x03\x40\x20\x01\x42\x00\x51\x04\x40\x0c\x02\x05\x20\x01\x20\x02\x7e\x21\x02\x20\x01\x42\x01\x7d\x21\x01\x0b\x0c\x00\x0b\x0b\x20\x02\x0b\xaf\x80\x80\x80\x00\x01\x02\x7e\x20\x00\x21\x01\x42\x01\x21\x02\x02\x40\x03\x40\x20\x01\x42\x00\x51\x04\x40\x0c\x02\x05\x20\x01\x20\x02\x7e\x21\x02\x20\x01\x42\x01\x7d\x21\x01\x0b\x0c\x00\x0b\x0b\x20\x02\x0b\xaf\x80\x80\x80\x00\x01\x02\x7e\x20\x00\x21\x01\x42\x01\x21\x02\x02\x40\x03\x40\x20\x01\x42\x00\x51\x04\x40\x0c\x02\x05\x20\x01\x20\x02\x7e\x21\x02\x20\x01\x42\x01\x7d\x21\x01\x0b\x0c\x00\x0b\x0b\x20\x02\x0b\xaf\x80\x80\x80\x00\x01\x02\x7e\x20\x00\x21\x01\x42\x01\x21\x02\x02\x40\x03\x40\x20\x01\x42\x00\x51\x04\x40\x0c\x02\x05\x20\x01\x20\x02\x7e\x21\x02\x20\x01\x42\x01\x7d\x21\x01\x0b\x0c\x00\x0b\x0b\x20\x02\x0b\xaf\x80\x80\x80\x00\x01\x02\x7e\x20\x00\x21\x01\x42\x01\x21\x02\x02\x40\x03\x40\x20\x01\x42\x00\x51\x04\x40\x0c\x02\x05\x20\x01\x20\x02\x7e\x21\x02\x20\x01\x42\x01\x7d\x21\x01\x0b\x0c\x00\x0b\x0b\x20\x02\x0b");

// stack.wast:130
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x89\x80\x80\x80\x00\x02\x60\x00\x00\x60\x01\x7e\x01\x7e\x02\x8f\x80\x80\x80\x00\x01\x02\x24\x31\x08\x66\x61\x63\x2d\x65\x78\x70\x72\x00\x01\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x01\x0a\xa2\x80\x80\x80\x00\x01\x9c\x80\x80\x80\x00\x00\x02\x40\x42\x19\x10\x00\x01\x42\x80\x80\x80\xde\x87\x92\xec\xcf\xe1\x00\x01\x51\x45\x0d\x00\x0f\x0b\x00\x0b", exports("$1", $1)),  "run", []));  // assert_return(() => call($1, "fac-expr", [int64("25")]), int64("7_034_535_277_573_963_776"))

// stack.wast:131
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x89\x80\x80\x80\x00\x02\x60\x00\x00\x60\x01\x7e\x01\x7e\x02\x90\x80\x80\x80\x00\x01\x02\x24\x31\x09\x66\x61\x63\x2d\x73\x74\x61\x63\x6b\x00\x01\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x01\x0a\xa2\x80\x80\x80\x00\x01\x9c\x80\x80\x80\x00\x00\x02\x40\x42\x19\x10\x00\x01\x42\x80\x80\x80\xde\x87\x92\xec\xcf\xe1\x00\x01\x51\x45\x0d\x00\x0f\x0b\x00\x0b", exports("$1", $1)),  "run", []));  // assert_return(() => call($1, "fac-stack", [int64("25")]), int64("7_034_535_277_573_963_776"))

// stack.wast:132
run(() => call(instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x89\x80\x80\x80\x00\x02\x60\x00\x00\x60\x01\x7e\x01\x7e\x02\x90\x80\x80\x80\x00\x01\x02\x24\x31\x09\x66\x61\x63\x2d\x6d\x69\x78\x65\x64\x00\x01\x03\x82\x80\x80\x80\x00\x01\x00\x07\x87\x80\x80\x80\x00\x01\x03\x72\x75\x6e\x00\x01\x0a\xa2\x80\x80\x80\x00\x01\x9c\x80\x80\x80\x00\x00\x02\x40\x42\x19\x10\x00\x01\x42\x80\x80\x80\xde\x87\x92\xec\xcf\xe1\x00\x01\x51\x45\x0d\x00\x0f\x0b\x00\x0b", exports("$1", $1)),  "run", []));  // assert_return(() => call($1, "fac-mixed", [int64("25")]), int64("7_034_535_277_573_963_776"))

// stack.wast:137
let $2 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x8c\x80\x80\x80\x00\x03\x60\x00\x00\x60\x00\x01\x7f\x60\x01\x7f\x00\x03\x82\x80\x80\x80\x00\x01\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x01\x0a\xb7\x83\x80\x80\x00\x01\xb1\x83\x80\x80\x00\x00\x02\x40\x41\x00\x11\x00\x00\x0b\x03\x40\x41\x00\x11\x00\x00\x0b\x41\x00\x04\x40\x41\x00\x11\x00\x00\x0b\x41\x00\x04\x40\x41\x00\x11\x00\x00\x05\x41\x00\x11\x00\x00\x0b\x02\x40\x41\x00\x11\x00\x00\x0b\x03\x40\x41\x00\x11\x00\x00\x0b\x41\x00\x04\x40\x41\x00\x11\x00\x00\x0b\x41\x00\x04\x40\x41\x00\x11\x00\x00\x05\x41\x00\x11\x00\x00\x0b\x02\x40\x41\x00\x41\x00\x11\x02\x00\x0b\x03\x40\x41\x00\x41\x00\x11\x02\x00\x0b\x41\x00\x04\x40\x41\x00\x41\x00\x11\x02\x00\x0b\x41\x00\x04\x40\x41\x00\x41\x00\x11\x02\x00\x05\x41\x00\x41\x00\x11\x02\x00\x0b\x02\x7f\x41\x00\x11\x01\x00\x0b\x1a\x03\x7f\x41\x00\x11\x01\x00\x0b\x1a\x41\x00\x04\x7f\x41\x00\x11\x01\x00\x05\x41\x00\x11\x01\x00\x0b\x1a\x02\x40\x41\x00\x11\x00\x00\x0b\x03\x40\x41\x00\x11\x00\x00\x0b\x41\x00\x04\x40\x41\x00\x11\x00\x00\x0b\x41\x00\x04\x40\x41\x00\x11\x00\x00\x05\x41\x00\x11\x00\x00\x0b\x02\x40\x41\x00\x11\x00\x00\x0b\x03\x40\x41\x00\x11\x00\x00\x0b\x41\x00\x04\x40\x41\x00\x11\x00\x00\x0b\x41\x00\x04\x40\x41\x00\x11\x00\x00\x05\x41\x00\x11\x00\x00\x0b\x02\x40\x41\x00\x11\x00\x00\x0b\x03\x40\x41\x00\x11\x00\x00\x0b\x41\x00\x04\x40\x41\x00\x11\x00\x00\x0b\x41\x00\x04\x40\x41\x00\x11\x00\x00\x05\x41\x00\x11\x00\x00\x0b\x02\x40\x41\x00\x41\x00\x11\x02\x00\x0b\x03\x40\x41\x00\x41\x00\x11\x02\x00\x0b\x41\x00\x04\x40\x41\x00\x41\x00\x11\x02\x00\x0b\x41\x00\x04\x40\x41\x00\x41\x00\x11\x02\x00\x05\x41\x00\x41\x00\x11\x02\x00\x0b\x02\x7f\x41\x00\x11\x01\x00\x0b\x1a\x03\x7f\x41\x00\x11\x01\x00\x0b\x1a\x41\x00\x04\x7f\x41\x00\x11\x01\x00\x05\x41\x00\x11\x01\x00\x0b\x1a\x02\x40\x41\x00\x11\x00\x00\x0b\x03\x40\x41\x00\x11\x00\x00\x0b\x41\x00\x04\x40\x41\x00\x11\x00\x00\x0b\x41\x00\x04\x40\x41\x00\x11\x00\x00\x05\x41\x00\x11\x00\x00\x0b\x41\x00\x11\x00\x00\x0b");
