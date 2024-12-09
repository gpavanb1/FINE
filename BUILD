# Define the header-only library
cc_library(
    name = "fine",
    hdrs = glob(["src/*.h"]),  # Include all .h files from the src/ folder
    includes = ["src"],
    visibility = ["//visibility:public"],  # Library can be used anywhere in the workspace
)

# Benchmark target
cc_binary(
    name = "benchmark",
    srcs = ["benchmark.cpp"],
    deps = [":fine"],  # Depends on the library
)

# Test target
cc_test(
    name = "test",
    srcs = ["test.cpp"],
    deps = [
        ":fine",
        "@googletest//:gtest",
        "@googletest//:gtest_main"
        ],  # Depends on the library
    timeout = "short"
)
