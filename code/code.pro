# code/code.pro  — top-level qmake project
TEMPLATE = subdirs
CONFIG += ordered

# ---- Subprojects ----
# 'general' (static library from head/ + source/)
SUBDIRS += general

# Tests / apps (adjust list to what you actually want to build)
SUBDIRS += P5 \
           P6 \
           P7_1 \
	   P7_2 \
	   P7_3 \
           P8_1 \
	   P8_2 \
           P9 \
           P10 \
           P13_1 \
           P13_2_gl \
           P13_2_text \
           P14_Newmark \
           P14_RungeKutta \
	   text \
	   TissuChaine \
	   TissuCompose \
	   TissuDisque \
	   TissuRectangle \
           Qt_GL


# If a subdir's .pro file is NOT named the same as the folder,
# uncomment and set the exact .pro filename like this:
# P5.file = P5/your_test_name.pro
# P6.file = P6/your_test_name.pro
# ...
# Qt_GL.file = Qt_GL/Qt_GL.pro
