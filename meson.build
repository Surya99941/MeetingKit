project('attendance', ['cpp', 'c'],
          version: '0.1.0',
    meson_version: '>= 0.50.0',
  default_options: [ 'warning_level=2',
                     'cpp_std=gnu++2a',
                   ],
)

i18n = import('i18n')


Deps = [
  dependency('gtkmm-3.0', version: '>= 3.18'),
]

subdir('data')
subdir('src')
subdir('po')

Incl = include_directories('./Include')
Source = data_sources + attendance_sources

executable('attendance', Source,
  dependencies: Deps,
  include_directories : Incl,
  install: true,
)

meson.add_install_script('build-aux/meson/postinstall.py')
