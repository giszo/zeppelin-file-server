# -*- python -*-

vars = Variables()
vars.Add(PathVariable('PREFIX', 'prefix used to install files', '/usr'))

env = Environment(variables = vars)

env["CPPFLAGS"] = ["-O2", "-Wall", "-Werror", "-Wshadow", "-std=c++11", "-pthread"]
env["CPPPATH"] = [Dir("src")]

if "PREFIX" in env :
    env["CPPPATH"] += ["%s/include" % env["PREFIX"]]

plugin = env.SharedLibrary(
    target = "file-server",
    source = ["src/plugin.cpp", "src/fileserver.cpp"]
)

env.Alias("install", env.Install("$PREFIX/lib/zeppelin/plugins", plugin))
