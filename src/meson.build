arduboton_sources = [
  'main.cpp',
  'arduboton-window.cpp',

]

arduboton_deps = [
  dependency('gtkmm-3.0', version: '>= 3.18'),
  dependency('libserialport'),
]

gnome = import('gnome')

arduboton_sources += gnome.compile_resources('arduboton-resources',
  'arduboton.gresource.xml',
  c_name: 'arduboton'
)

executable('arduboton', arduboton_sources,
  dependencies: arduboton_deps, 
  install: true,
)
