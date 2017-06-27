/***********************************************************************************************

    PART 4: Vector Operation

    The vectorOperations function gets as parameters 4 arrays of the same length and
    the number of elements in those arrays. 

    For each pair of elements in first_array and second_array, it calls performOperation
    and stores the returned result in the same index of output_array.

    output_array[index] = performOperation(operation_array[index], first_array[index], second_array[index]).

    You also need to implement the body of performOperation function according to the provided
    C code.
  
************************************************************************************************/

__declspec(naked) 
int performOperation (int operation, int first, int second)
{

// C code to be converted to x86 assembly
/*
    if (operation==0) 
        return first - second;
    else if (operation==1)
        return first + second;
    else if (operation==2)
        return (first < second)? first : second;
    else if (operation==3)
        return (first > second)? first : second;
    else
        return first;
*/

    __asm {
            // BEGIN YOUR CODE HERE
		
		push ebp
		mov ebp, esp

		push edi
		push esi
		push ebx

		mov ebx, [ebp+8] //ebx = operation
		mov ecx, [ebp+12] //ecx = first
		mov edx, [ebp+16] //edx = second

		mov eax, 0

		cmp ebx, 0
		je ret_0
		cmp ebx, 1
		je ret_1
		cmp ebx, 2
		je ret_2
		cmp ebx, 3
		je ret_3
		mov eax, ecx
		jmp the_end

	ret_0:
		sub ecx, edx
		mov eax, ecx
		jmp the_end
	ret_1:
		add ecx, edx
		mov eax, ecx
		jmp the_end
	ret_2:
		cmp ecx, edx
		jge else_
		mov eax, ecx
		jmp the_end
	
	ret_3 :
		cmp ecx, edx
		jle else_
		mov eax, ecx
		jmp the_end
	else_ :
		mov eax, edx
		jmp the_end
	the_end:
		pop ebx
		pop esi
		pop edi
		mov esp, ebp
		pop ebp
            // END YOUR CODE HERE
            ret
    }
  
}

void vectorOperations (int number_of_elements, int *first_array, int *second_array, 
                       int *operation_array, int *output_array)
{
// C code to be converted to x86 assembly
/*
    int i;
    for (i=0; i<number_of_elements; i++)
    {
        output_array[i] = performOperation(operation_array[i], first_array[i], second_array[i]);
    }
*/

    __asm {
            // BEGIN YOUR CODE HERE
		mov edi, output_array
		mov esi, 0
		mov edx, number_of_elements
	begin_loop:
		cmp esi, edx
		jge end_loop

		push eax
		push ecx
		push edx

		mov eax, operation_array
		mov ebx, first_array
		mov ecx, second_array
		mov eax, dword ptr[eax + esi * 4]
		mov ebx, dword ptr[ebx + esi * 4]
		mov ecx, dword ptr[ecx + esi * 4]

		push ecx
		push ebx
		push eax

		call performOperation
		add esp, 12
		mov dword ptr[edi+4*esi], eax
		
		pop edx
		pop ecx
		pop eax

		inc esi
		jmp begin_loop
	end_loop:
		mov output_array, edi

            // END YOUR CODE HERE
    }
}
