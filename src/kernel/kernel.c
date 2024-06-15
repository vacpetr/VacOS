void dummy_test_entrypoint() {
}

void main(){
    unsigned char* videoMem = (unsigned char*) 0xFD000000;
    int counter = 0;

    for(int r = 0; r < 255; r+=3){

        for(int g = 0; g < 255; g+=3){

            for(int b = 0; b < 255; b+=3){

                videoMem[counter] = b;
                videoMem[counter+1] = r;
                videoMem[counter+2] = g;

                counter+=3;

                if(counter > 2000000)break;
            }

             if(counter > 2000000)break;
        }

         if(counter > 2000000)break;
    }
}