# -*- python -*-

vars = Variables()
vars.Add(PathVariable('PREFIX', 'prefix used to install files', '/usr'))
vars.Add(PathVariable('JSONCPP', 'path of jsoncpp library', None))

env = Environment(variables = vars)

env["CPPFLAGS"] = ["-O2", "-Wall", "-Werror", "-Wshadow", "-std=c++11", "-pthread"]
env["CPPPATH"] = [Dir("src")]
env["LIBPATH"] = []

# jsoncpp library
if "JSONCPP" in env :
    env["CPPPATH"] += ["%s/include" % env["JSONCPP"]]
    env["LIBPATH"] += ["%s/lib" % env["JSONCPP"]]

if "PREFIX" in env :
    env["CPPPATH"] += ["%s/include" % env["PREFIX"]]

plugin = env.SharedLibrary(
    target = "file-server",
    source = ["src/plugin.cpp", "src/fileserver.cpp"]
)

env.Alias("install", env.Install("$PREFIX/lib/zeppelin/plugins", plugin))
