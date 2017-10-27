from conan.packager import ConanMultiPackager
import platform

if __name__ == "__main__":
    builder = ConanMultiPackager(args = "-tf ./tests/PackageTests --build missing")
    
    if platform.system() == "Windows":
        builder.add(settings={"arch": "x86", "build_type": "Debug", "compiler": "Visual Studio", "compiler.version": 14, "compiler.runtime": "MTd"}, options={}, env_vars={}, build_requires={})
        builder.add(settings={"arch": "x86_64", "build_type": "Debug", "compiler": "Visual Studio", "compiler.version": 14, "compiler.runtime": "MTd"}, options={}, env_vars={}, build_requires={})
        builder.add(settings={"arch": "x86", "build_type": "Release", "compiler": "Visual Studio", "compiler.version": 14, "compiler.runtime": "MT"}, options={}, env_vars={}, build_requires={})
        builder.add(settings={"arch": "x86_64", "build_type": "Release", "compiler": "Visual Studio", "compiler.version": 14, "compiler.runtime": "MT"}, options={}, env_vars={}, build_requires={})
    else:
        builder.add(settings={"arch": "x86", "build_type": "Debug"}, options={}, env_vars={}, build_requires={})
        builder.add(settings={"arch": "x86_64", "build_type": "Debug"}, options={}, env_vars={}, build_requires={})
        builder.add(settings={"arch": "x86", "build_type": "Release"}, options={}, env_vars={}, build_requires={})
        builder.add(settings={"arch": "x86_64", "build_type": "Release"}, options={}, env_vars={}, build_requires={})

    builder.run()
