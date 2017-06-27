// - This function takes in a square sized grayscale image and applies thresholding on each pixel.
//   i.e. it should change pixel values according to this formula:
//                     0xFF       if x >= threshold
//                     0x00       if x <  threshold
// - The width and height of the image are equal to dim. 
// - You are not allowed to define additional variables.
//
void imageThresholding(unsigned char* image, int dim, unsigned char threshold) {
    __asm {
    
            // YOUR CODE STARTS HERE
		mov eax, 0;//array index eax < n*n(ebx)
		mov ebx, dim;
		imul ebx, ebx;//ebx = dim*dim
		mov dl, threshold;
	beginOfForLoop://use ecx to hold address
		cmp eax, ebx;
		jge endOfForLoop;
		mov ecx, eax;
		add ecx, image; //address = image  + index (eax)*1(char)
		cmp byte ptr[ecx], dl;
		jae aboveThres;
		mov byte ptr[ecx], 0x00;
		jmp endOfCmp;

	aboveThres:
		mov byte ptr[ecx], 0xFF;
		jmp endOfCmp;

	endOfCmp:
		inc eax;
		jmp beginOfForLoop;

	endOfForLoop:

            // YOUR CODE ENDS HERE
    }
}


