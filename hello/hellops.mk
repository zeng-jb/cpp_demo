
hellops.dll: dlldata.obj hello_p.obj hello_i.obj
	link /dll /out:hellops.dll /def:hellops.def /entry:DllMain dlldata.obj hello_p.obj hello_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del hellops.dll
	@del hellops.lib
	@del hellops.exp
	@del dlldata.obj
	@del hello_p.obj
	@del hello_i.obj
