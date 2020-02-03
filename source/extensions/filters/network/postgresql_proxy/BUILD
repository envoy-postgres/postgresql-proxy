package(default_visibility = ["//visibility:public"])

licenses(["notice"])  # Apache 2

# PostgresSQL proxy L7 network filter.
# Public docs: docs/root/configuration/network_filters/postgres_proxy_filter.rst

load(
    "@envoy//bazel:envoy_build_system.bzl",
    "envoy_cc_library",
)
load("@envoy_api//bazel:api_build_system.bzl", "api_proto_package")

api_proto_package()

envoy_cc_library(
    name = "filter",
    srcs = [
        "postgresql_filter.cc",
        "postgresql_utils.cc",
        "postgresql_decoder.cc"
    ],
    hdrs = [
        "postgresql_filter.h",
        "postgresql_utils.h",
        "postgresql_decoder.h",
        "postgresql_session.h"
    ],
    repository = "@envoy",
    deps = [
        "@envoy//include/envoy/network:filter_interface",
        "@envoy//include/envoy/server:filter_config_interface",
        "@envoy//include/envoy/stats:stats_interface",
        "@envoy//include/envoy/stats:stats_macros",
        "@envoy//source/common/buffer:buffer_lib",
        "@envoy//source/common/network:filter_lib",
    ],
)

envoy_cc_library(
    name = "config",
    srcs = ["config.cc"],
    hdrs = ["config.h"],
    repository = "@envoy",
    deps = [
        ":filter",
        ":pkg_cc_proto",
        "@envoy//source/extensions/filters/network/common:factory_base_lib",
    ],
)
