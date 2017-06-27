// - This function rotates a square sized color image 90 degress counterclockwise.
// - The width and height of the image are both equal to dim.
// - Four variables (i0, i90, i180, i270) are defined that you may use in your implementation for
//   temporary data storage. You are not allowed to define additional variables.
//
void imageRotation(unsigned int* image, int dim) {
  
    unsigned int i0, i90, i180, i270;
  
    __asm {
    
            // YOUR CODE STARTS HERE
		mov eax, 0; //row = eax [0,dim/2]
		mov esi, image;
		//eax --> row   ebx -->col	esi -->base
		//always using edx for index check row:  
	Begin_Of_Outter_Loop://row-> [0,dim/2)
		mov edx, dim;
		shr edx, 1; //edx = dim/2
		cmp eax, edx; //row < edx(dim/2)
		jg End_Of_Outter_Loop;
		mov ebx, eax;// col = ebx =eax = row;
	Begin_Of_Inner_Loop://col ->[row, dim-row-1]
		mov edx, dim;
		sub edx, eax; // edx = dim - row
		dec edx;
		cmp ebx, edx; //ebx <= edx(dim -row-1)
		jge End_Of_Inner_Loop;
		//finding i0 = base + (dim * row + col) *4 (integer)
		mov edx, dim;
		imul edx, eax;
		add edx, ebx;
		shl edx, 2;
		add edx, esi;
		mov i0, edx;

		//finding i90 = base + (dim * (dim - col -1) + row)* 4
		mov edx, dim;
		sub edx, ebx;
		dec edx;
		mov ecx, dim;
		imul edx, ecx;
		add edx, eax;
		shl edx, 2;
		add edx, esi;
		mov i90, edx;

		//finding i180 = base + (dim * (dim -row -1) + (dim -col -1)) *4
		mov ecx, dim;
		mov edx, dim;
		sub edx, eax;
		dec edx;
		imul edx, ecx;
		add edx, ecx;
		sub edx, ebx;
		dec edx;
		shl edx, 2;
		add edx, esi;
		mov i180, edx;

		//finding i270 = base + (dim * col + (dim -row -1)) *4
		mov ecx, dim;
		mov edx, dim;
		imul edx, ebx;
		add edx, ecx;
		sub edx, eax;
		dec edx;
		shl edx, 2;
		add edx, esi;
		mov i270, edx;

		//p0 -> p90 -> p180 -> p270 -> p0
		//replace p0 with p270 and store p0 into edi
		mov ecx, i0;
		mov edi, dword ptr[ecx]; //edi = p0
		mov edx, i270;
		mov edx, dword ptr[edx];
		mov dword ptr[ecx], edx; //p0 now is p270

		//replace p90 with p0 and store p90 into edx
		mov ecx, i90;
		mov edx, dword ptr[ecx]; //edx = p90
		mov dword ptr[ecx], edi; //p90 now is p0

		//replace p180 with p90 and store p180 into edi
		mov ecx, i180;
		mov edi, dword ptr[ecx]; //edi ->p180
		mov dword ptr[ecx], edx; //p180 now is p90

		//replace p270 with p180 
		mov ecx, i270;
		mov dword ptr[ecx], edi;
	
		inc ebx;
		jmp Begin_Of_Inner_Loop;
	End_Of_Inner_Loop:
		jmp lable1;

	lable1:
		inc eax;
		jmp Begin_Of_Outter_Loop;
	End_Of_Outter_Loop:

            // Iterate over the red triangle (row by row starting from top left)

                // compute index of pixel p0, find the corresponding memory address and store it in i0

                // compute index of pixel 90, find the corresponding memory address and store it in i270

                // compute index of pixel p180, find the corresponding memory address and store it in i180

                // compute index of pixel 270, find the corresponding memory address and store it in i90

                // rotationaly swap pixel values: p0 -> p90 -> p180 -> p270 -> p0

            // YOUR CODE ENDS HERE
    }
}
