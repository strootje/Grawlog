from conan.packager import ConanMultiPackager

if __name__ == "__main__":
    builder = ConanMultiPackager(args = "--build missing -tf tests/PackageTests -o build_tests=True")
    builder.add_common_builds()
    builder.run()
