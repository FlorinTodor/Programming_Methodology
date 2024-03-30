touch tests//.timeout
CMD="valgrind --leak-check=full /home/flo/Desktop/MP_2023/Language4_Floriin/dist/Debug/GNU-Linux/language4_floriin  ../Books/fortunata.bgr ../Books/quijote.bgr ../Books/fortunata.bgr 1> tests//.out7 2>&1"
eval $CMD
rm tests//.timeout
