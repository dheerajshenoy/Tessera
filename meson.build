project('Tessera',
        'c', 'cpp',
        default_options: ['cpp_std=c++20'])

sources = files(
    'src/main.cpp',
    'src/Tessera.cpp',
    'src/Keyboard.cpp',
    'src/Popup.cpp',
    'src/Toplevel.cpp',
    'src/Server.cpp',
)

wlroots_dep = dependency('wlroots-0.18', version: '>=0.16.0')
wayland_server_dep = dependency('wayland-server')
xkbcommon_dep = dependency('xkbcommon')
log_dep = dependency('wayland-client')

wayland_scanner = find_program('wayland-scanner', required: true)

protocols = dependency('wayland-protocols', version: '>=1.25')

xdg_shell_xml = protocols.get_variable('pkgdatadir') / 'stable/xdg-shell/xdg-shell.xml'

xdg_shell_header = custom_target(
    'xdg-shell-protocol.h',
    input: xdg_shell_xml,
    output: 'xdg-shell-protocol.h',
    command: [wayland_scanner, 'server-header', '@INPUT@', '@OUTPUT@'],
    build_by_default: true
)

xdg_shell_code = custom_target(
    'xdg-shell-protocol.c',
    input: xdg_shell_xml,
    output: 'xdg-shell-protocol.c',
    command: [wayland_scanner, 'private-code', '@INPUT@', '@OUTPUT@'],
    build_by_default: true  # Ensures it's built automatically
)

cpp_pch = [ 'src/pch.hpp' ]

executable('tessera',
           sources : [sources, xdg_shell_code],
           dependencies: [wlroots_dep, wayland_server_dep, xkbcommon_dep, log_dep],
           include_directories: include_directories('.'),
           cpp_args: ['-DWLR_USE_UNSTABLE'],
           cpp_pch: cpp_pch)
