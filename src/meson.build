# Include directories
inc = include_directories('../include')

# Dependencies
cpp = meson.get_compiler('cpp')

gl_dep = dependency('gl', required : false)
if not gl_dep.found()
  gl_dep = cpp.find_library('GL', required : true)
endif

glu_dep = dependency('glu', required : false)
if not glu_dep.found()
  glu_dep = cpp.find_library('GLU', required : true)
endif

glut_dep = dependency('glut', required : false)
if not glut_dep.found()
  glut_dep = cpp.find_library('glut', required : true)
endif

# Sources
sources = [
  'main.cpp',
  'Camera.cpp',
  'Garage.cpp',
  'Platform.cpp',
  'Poster.cpp',
  'Shelf.cpp',
  'Texture.cpp',
  'Car.cpp',
  'Chassis.cpp',
  'Door.cpp',
  'Wheel.cpp',
  'RearBumper.cpp',
  'FrontBumper.cpp',
  'Drum.cpp',
  'Lamp.cpp',
]

# Executable
executable('nfsu2-opengl',
  sources,
  include_directories : inc,
  dependencies : [gl_dep, glu_dep, glut_dep],
)
