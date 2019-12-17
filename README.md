## PostgreSQL Proxy

[![Build Status](https://dev.azure.com/envoy-postgres/postgresql-proxy/_apis/build/status/envoy-postgres.postgresql-proxy?branchName=master)](https://dev.azure.com/envoy-postgres/postgresql-proxy/_build/latest?definitionId=1&branchName=master)

To build this project, please prepare your machine following the instructions [here](https://github.com/envoyproxy/envoy/blob/master/bazel/README.md).

TL;DR

```
$ bazel build //source/exe:postgresql-proxy
$ ./bazel-bin/source/exe/postgresql-proxy --version

./bazel-bin/source/exe/postgresql-proxy  version: 7565c76ca39cda76c9a7e7c3ba73ecadb6e42c67/1.13.0-dev/Clean/DEBUG/BoringSSL

```

### License

[LICENSE](LICENSE).
