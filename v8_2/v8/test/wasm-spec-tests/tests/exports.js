
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

// exports.wast:3
let $1 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:4
let $2 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x00\x00\x01\x62\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:5
let $3 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x83\x80\x80\x80\x00\x02\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x00\x00\x01\x62\x00\x01\x0a\x8f\x80\x80\x80\x00\x02\x82\x80\x80\x80\x00\x00\x0b\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:7
let $4 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:8
let $5 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x07\x8d\x80\x80\x80\x00\x03\x01\x61\x00\x00\x01\x62\x00\x00\x01\x63\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:9
let $6 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x85\x80\x80\x80\x00\x01\x60\x01\x7f\x00\x03\x82\x80\x80\x80\x00\x01\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x00\x00\x01\x62\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:10
let $7 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:11
let $8 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:12
let $9 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:13
let $10 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:14
let $11 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:16
let $12 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x86\x80\x80\x80\x00\x01\x60\x01\x7f\x01\x7f\x03\x82\x80\x80\x80\x00\x01\x00\x07\x85\x80\x80\x80\x00\x01\x01\x65\x00\x00\x0a\x8e\x80\x80\x80\x00\x01\x88\x80\x80\x80\x00\x00\x20\x00\x41\x01\x6a\x0f\x0b");
let $Func = $12;

// exports.wast:22
assert_return(() => call($12, "e", [42]), 43);

// exports.wast:23
assert_return(() => call($Func, "e", [42]), 43);

// exports.wast:24
let $13 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00");

// exports.wast:25
let $14 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00");
let $Other1 = $14;

// exports.wast:26
assert_return(() => call($Func, "e", [42]), 43);

// exports.wast:28
let $15 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x85\x80\x80\x80\x00\x01\x60\x00\x01\x7f\x03\x82\x80\x80\x80\x00\x01\x00\x07\x8d\x80\x80\x80\x00\x03\x01\x61\x00\x00\x01\x62\x00\x00\x01\x63\x00\x00\x0a\x8a\x80\x80\x80\x00\x01\x84\x80\x80\x80\x00\x00\x41\x2a\x0b");

// exports.wast:34
assert_return(() => call($15, "a", []), 42);

// exports.wast:35
assert_return(() => call($15, "b", []), 42);

// exports.wast:36
assert_return(() => call($15, "c", []), 42);

// exports.wast:38
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x00\x00");

// exports.wast:42
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x00\x01\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:46
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x85\x80\x80\x80\x00\x01\x60\x01\x7f\x00\x02\x96\x80\x80\x80\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x09\x70\x72\x69\x6e\x74\x5f\x69\x33\x32\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x00\x01");

// exports.wast:50
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x00\x00\x01\x61\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:54
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x83\x80\x80\x80\x00\x02\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x00\x00\x01\x61\x00\x01\x0a\x8f\x80\x80\x80\x00\x02\x82\x80\x80\x80\x00\x00\x0b\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:58
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x89\x80\x80\x80\x00\x02\x01\x61\x00\x00\x01\x61\x03\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:62
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x00\x00\x01\x61\x01\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:66
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x00\x00\x01\x61\x02\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:74
let $16 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x85\x80\x80\x80\x00\x01\x01\x61\x03\x00");

// exports.wast:75
let $17 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x89\x80\x80\x80\x00\x02\x01\x61\x03\x00\x01\x62\x03\x00");

// exports.wast:76
let $18 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x8b\x80\x80\x80\x00\x02\x7f\x00\x41\x00\x0b\x7f\x00\x41\x00\x0b\x07\x89\x80\x80\x80\x00\x02\x01\x61\x03\x00\x01\x62\x03\x01");

// exports.wast:78
let $19 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x85\x80\x80\x80\x00\x01\x01\x61\x03\x00");

// exports.wast:79
let $20 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x85\x80\x80\x80\x00\x01\x01\x61\x03\x00");

// exports.wast:80
let $21 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x85\x80\x80\x80\x00\x01\x01\x61\x03\x00");

// exports.wast:81
let $22 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x85\x80\x80\x80\x00\x01\x01\x61\x03\x00");

// exports.wast:82
let $23 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x85\x80\x80\x80\x00\x01\x01\x61\x03\x00");

// exports.wast:83
let $24 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x85\x80\x80\x80\x00\x01\x01\x61\x03\x00");

// exports.wast:85
let $25 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x2a\x0b\x07\x85\x80\x80\x80\x00\x01\x01\x65\x03\x00");
let $Global = $25;

// exports.wast:89
assert_return(() => get($25, "e"), 42);

// exports.wast:90
assert_return(() => get($Global, "e"), 42);

// exports.wast:91
let $26 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00");

// exports.wast:92
let $27 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00");
let $Other2 = $27;

// exports.wast:93
assert_return(() => get($Global, "e"), 42);

// exports.wast:95
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x03\x00");

// exports.wast:99
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x85\x80\x80\x80\x00\x01\x01\x61\x03\x01");

// exports.wast:103
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x02\x98\x80\x80\x80\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x0a\x67\x6c\x6f\x62\x61\x6c\x5f\x69\x33\x32\x03\x7f\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x03\x01");

// exports.wast:107
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x89\x80\x80\x80\x00\x02\x01\x61\x03\x00\x01\x61\x03\x00");

// exports.wast:111
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x06\x8b\x80\x80\x80\x00\x02\x7f\x00\x41\x00\x0b\x7f\x00\x41\x00\x0b\x07\x89\x80\x80\x80\x00\x02\x01\x61\x03\x00\x01\x61\x03\x01");

// exports.wast:115
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x89\x80\x80\x80\x00\x02\x01\x61\x03\x00\x01\x61\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:119
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x89\x80\x80\x80\x00\x02\x01\x61\x03\x00\x01\x61\x01\x00");

// exports.wast:123
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x89\x80\x80\x80\x00\x02\x01\x61\x03\x00\x01\x61\x02\x00");

// exports.wast:131
let $28 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:132
let $29 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x01\x00\x01\x62\x01\x00");

// exports.wast:133
let $30 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x87\x80\x80\x80\x00\x02\x70\x00\x00\x70\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x01\x00\x01\x62\x01\x01");

// exports.wast:135
let $31 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:136
let $32 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x85\x80\x80\x80\x00\x01\x70\x01\x00\x01\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:137
let $33 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:138
let $34 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x85\x80\x80\x80\x00\x01\x70\x01\x00\x01\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:139
let $35 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:140
let $36 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x85\x80\x80\x80\x00\x01\x70\x01\x00\x01\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:141
let $37 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:142
let $38 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x85\x80\x80\x80\x00\x01\x70\x01\x00\x01\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:143
let $39 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:144
let $40 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x85\x80\x80\x80\x00\x01\x70\x01\x00\x01\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:145
let $41 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:146
let $42 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x85\x80\x80\x80\x00\x01\x70\x01\x00\x01\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:150
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x00");

// exports.wast:154
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x01");

// exports.wast:158
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x02\x95\x80\x80\x80\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x05\x74\x61\x62\x6c\x65\x01\x70\x01\x0a\x14\x07\x85\x80\x80\x80\x00\x01\x01\x61\x01\x01");

// exports.wast:162
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x01\x00\x01\x61\x01\x00");

// exports.wast:166
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x87\x80\x80\x80\x00\x02\x70\x00\x00\x70\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x01\x00\x01\x61\x01\x01");

// exports.wast:170
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x01\x00\x01\x61\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:174
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x89\x80\x80\x80\x00\x02\x01\x61\x01\x00\x01\x61\x03\x00");

// exports.wast:178
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x01\x00\x01\x61\x02\x00");

// exports.wast:186
let $43 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:187
let $44 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x02\x00\x01\x62\x02\x00");

// exports.wast:191
let $45 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:192
let $46 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x84\x80\x80\x80\x00\x01\x01\x00\x01\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:193
let $47 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:194
let $48 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x84\x80\x80\x80\x00\x01\x01\x00\x01\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:195
let $49 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:196
let $50 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x84\x80\x80\x80\x00\x01\x01\x00\x01\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:197
let $51 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:198
let $52 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x84\x80\x80\x80\x00\x01\x01\x00\x01\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:199
let $53 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:200
let $54 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x84\x80\x80\x80\x00\x01\x01\x00\x01\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:201
let $55 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:202
let $56 = instance("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x84\x80\x80\x80\x00\x01\x01\x00\x01\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:206
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x00");

// exports.wast:210
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x01");

// exports.wast:214
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x02\x95\x80\x80\x80\x00\x01\x08\x73\x70\x65\x63\x74\x65\x73\x74\x06\x6d\x65\x6d\x6f\x72\x79\x02\x01\x01\x02\x07\x85\x80\x80\x80\x00\x01\x01\x61\x02\x01");

// exports.wast:218
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x02\x00\x01\x61\x02\x00");

// exports.wast:227
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x01\x84\x80\x80\x80\x00\x01\x60\x00\x00\x03\x82\x80\x80\x80\x00\x01\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x02\x00\x01\x61\x00\x00\x0a\x88\x80\x80\x80\x00\x01\x82\x80\x80\x80\x00\x00\x0b");

// exports.wast:231
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x06\x86\x80\x80\x80\x00\x01\x7f\x00\x41\x00\x0b\x07\x89\x80\x80\x80\x00\x02\x01\x61\x02\x00\x01\x61\x03\x00");

// exports.wast:235
assert_invalid("\x00\x61\x73\x6d\x01\x00\x00\x00\x04\x84\x80\x80\x80\x00\x01\x70\x00\x00\x05\x83\x80\x80\x80\x00\x01\x00\x00\x07\x89\x80\x80\x80\x00\x02\x01\x61\x02\x00\x01\x61\x01\x00");
