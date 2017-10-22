from conans import ConanFile, CMake

class GrawlogConan(ConanFile):
    name = "Grawlog"
    version = "0.1"

    license = "MPL-2.0"
    description = "Sane Logging Library for cpp"
    url = "https://github.com/strootje/grawlog"

    settings = "os", "compiler", "build_type", "arch"
    options = { "shared": [True, False], "build_docs": [True, False], "build_specs": [True, False], "build_tests": [True, False] }
    default_options = "shared=False", "build_docs=False", "build_specs=False", "build_tests=False", "cxx11=True"

    generators = "cmake"
    exports_sources = "*"

    requires = "gtest/1.8.0@conan/stable"

    def configure(self):
        self.options["gtest"].shared = self.options.shared

        if self.settings.compiler == "Visual Studio":
            self.options.cxx11 = True 

    def build(self):
        cmake = CMake(self)
        cmake.definitions["BUILD_SHARED_LIBS"] = 'ON' if self.options["shared"] == True else 'OFF'
        cmake.definitions["BUILD_DOCS"] = 'ON' if self.options["build_docs"] == True else 'OFF'
        cmake.definitions["BUILD_SPECS"] = 'ON' if self.options["build_specs"] == True else 'OFF'
        cmake.definitions["BUILD_TESTS"] = 'ON' if self.options["build_tests"] == True else 'OFF'
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.hpp", dst="include/Grawlog", src="include")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["Grawlog"]
