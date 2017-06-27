__declspec(naked) 
int findMinIndex (int integer_array[], int i, int j)
{

// C code to be converted to x86 assembly
/*
    int iMin = i;
    // test against elements after i and before j to find the smallest 
    for ( i ; i < j; i++) {
        // if this element is less, then it is the new minimum   
        if (integer_array[i] < integer_array[iMin]) {
            // found new minimum; remember its index 
            iMin = i;
        }
    }

    return iMin;
*/

    __asm{
            mov eax, 0
            // BEGIN YOUR CODE HERE
			push ebp
			mov ebp, esp
			sub esp, 4 //allocate space for local variable
			push edi
			push esi
			push ebx

			mov eax, [ebp+8]//parameter 1 = &integer_array
			mov esi, [ebp+12]//parameter 2 = i
			mov edi, [ebp+16]//parameter 3= j

			mov ecx, esi //ecx = min index
			//mov ebx, dword ptr[eax + esi*4] //ebx = min value
			begin_loop:
				cmp esi, edi
				jge end_loop //till i<=j
				mov edx, dword ptr[eax+esi*4]//current value
				cmp edx, dword ptr[eax+ecx*4]
				jge next_iter
				//mov ebx, edx
				mov ecx, esi
			next_iter:
				inc esi
				jmp begin_loop
			end_loop:
				mov [ebp-4], ecx//??

			mov eax, [ebp-4]//???
			pop ebx
			pop esi
			pop edi

			mov esp, ebp
			pop ebp
            // END YOUR CODE HERE
            ret
    }

}

void selectionSort (int integer_array[], int array_size)
{

// C code to be converted to x86 assembly
/*  
    int j;
    int iMin;
    int temp;

    // advance the position through the entire array //
    // (could do j < n-1 because single element is also min element) //
    for (j = 0; j < array_size-1; j++) {

        // find the index of min element in the unsorted a[j .. n-1] //
        iMin = findMinIndex (integer_array, j, array_size);
 
        if(iMin != j) { // swap values
            temp = integer_array[iMin];
            integer_array[iMin] = integer_array [j];
            integer_array[j] = temp;    
        }
    }
*/

    __asm{
            // BEGIN YOUR CODE HERE
		mov eax, integer_array
		mov ebx, array_size
		mov esi, 0 //loop counter
		//mov edi, 0 // min index
		dec ebx
		begin_loop:
			cmp esi, ebx
			jge end_loop
			push eax
			push ecx
			push edx

			
			//push ebx
			mov edi, array_size
			push edi
			push esi
			push eax

			call findMinIndex
			add esp, 12
			mov edi, eax

			pop edx
			pop ecx
			pop eax
			//swapping [esi] & [edi]
			cmp edi, esi
			je next_iter
			mov edx, dword ptr[eax + edi*4]//min value
			mov ecx, dword ptr[eax + esi*4]//current value
			mov dword ptr[eax + esi*4], edx
			mov dword ptr[eax + edi*4], ecx
			jmp next_iter
		next_iter:
			inc esi
			jmp begin_loop
		end_loop:
			mov integer_array, eax

            // END YOUR CODE HERE
    }

}

