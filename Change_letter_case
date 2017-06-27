void changeCase(char *string) {

    __asm{
        // BEGIN YOUR CODE HERE
		//
		mov edx, string //eax = &string
		mov ebx, 0// ebx = index
		BeginLoop:
			mov al, byte ptr[edx+ebx]
			cmp al, 0
			je EndLoop
			cmp al, 65 // A
			jl nextIter
			cmp al, 90 //Z
			jle UpperToLower
			cmp al, 97 //a
			jl nextIter
			cmp al, 122 //z
			jle lowerToUpper
			jmp nextIter
		UpperToLower :
			add al, 32
			mov byte ptr[edx + ebx], al
			jmp nextIter
		lowerToUpper:
			sub al, 32
			mov byte ptr[edx + ebx], al
			jmp nextIter

		nextIter:
			inc ebx
			jmp BeginLoop
		EndLoop:
			mov string, edx
        // END YOUR CODE HERE
    }
}
