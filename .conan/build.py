from conan.packager import ConanMultiPackager
import platform

if __name__ == "__main__":
    builder = ConanMultiPackager(args = "-tf ./tests/PackageTests --build missing")
    builder.add_common_builds()
    builder.run()
