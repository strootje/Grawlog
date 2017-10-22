from conan.packager import ConanMultiPackager

if __name__ == "__main__":
    builder = ConanMultiPackager(args = "--build missing -tf tests/PackageTests -s compiler.libcxx=libstdc++17")
    builder.add_common_builds()
    builder.run()
