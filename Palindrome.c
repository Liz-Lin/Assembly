__declspec(naked)
int isPalindrome(char *input_string, int left_index, int right_index)
{

// C code to be converted to x86 assembly
/*
    // Input Validation
    if (NULL == input_string || left_index < 0 || right_index < 0){
        return -1;
    }
    // Recursion termination condition
    if (left_index >= right_index)
        return 1;
    if (input_string[left_index] == input_string[right_index]){
        return isPalindrome(input_string, left_index + 1, right_index - 1);
    }
    return -1;
*/

    __asm{
            mov eax, 0
            // BEGIN YOUR CODE HERE
			push ebp
			mov ebp, esp
			push edi
			push esi
			push ebx

			mov esi, [ebp+8] //first parameter char *input_string ?? which register
			mov ebx, [ebp+12] //left_index
			mov ecx, [ebp+16] //right_index
			cmp esi, 0
			je negative
			cmp ebx, 0
			jl negative
			cmp ecx, 0
			jl negative
			cmp ebx, ecx//left_index >= right_index
			jge postive
			mov dh, byte ptr[esi+ebx] //left
			mov dl, byte ptr[esi+ecx] //right
			cmp dh, dl
			jne negative
			
			//save 
			push eax
			push ecx
			push edx
			//push parameter
			inc ebx
			dec ecx
			push ecx
			push ebx
			push esi
			call isPalindrome
			add esp, 12
			mov edi, eax

			pop edx
			pop ecx
			pop eax
			mov eax, edi
			jmp the_end

		negative:
			mov eax, -1
			jmp the_end
		postive:
			mov eax, 1
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

