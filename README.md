## PostgreSQL Proxy

[![Build Status](https://dev.azure.com/envoy-postgres/postgresql-proxy/_apis/build/status/envoy-postgres.postgresql-proxy?branchName=master)](https://dev.azure.com/envoy-postgres/postgresql-proxy/_build/latest?definitionId=1&branchName=master)

To build this project, please prepare your machine following the instructions [here](https://github.com/envoyproxy/envoy/blob/master/bazel/README.md).

TL;DR

```
$ bazel build //source/exe:postgresql-proxy
$ ./bazel-bin/source/exe/postgresql-proxy --version

./bazel-bin/source/exe/postgresql-proxy  version: 7565c76ca39cda76c9a7e7c3ba73ecadb6e42c67/1.13.0-dev/Clean/DEBUG/BoringSSL

$ ./bazel-bin/source/exe/postgresql-proxy -c configs/postgresql.yaml
$ # from another terminal session
$ # e.g. you have: docker run --rm -it -p 5432:5432 -e POSTGRES_PASSWORD=testing -e POSTGRES_DB=testing circleci/postgres:11.1-alpine-ram running in localhost.
$ PGPASSWORD=testing psql -U postgres -h localhost -p 54322 -d testing
Type "help" for help.

testing=#
```

### License

[LICENSE](LICENSE).
