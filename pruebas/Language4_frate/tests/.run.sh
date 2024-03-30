touch tests//.timeout
CMD="valgrind --leak-check=full /home/gabriel/Documentos/Informatica/Primero/MP/Proyectos/UGRMPBase/NetBeansProjects/Language4/dist/Debug/GNU-Linux/language4  ../Books/fortunata.bgr ../Books/quijote.bgr ../Books/fortunata.bgr 1> tests//.out7 2>&1"
eval $CMD
rm tests//.timeout
