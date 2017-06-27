/***********************************************************************************************

    PART 5: Dijkstra's Algorithm to calculate GCD.

    Implement a recursive function in assembly that calculates the greatest common divisor of 
    two unsigned integers.

    Given two unsigned integers n and m, we can define GCD(m , n) as:

           GCD(m , n) = n                       ,    if (m % n) == 0
           GCD(m , n) = GCD(n , m % n)          ,    if (m % n) >  0

************************************************************************************************/

__declspec(naked) 
unsigned int gcd(unsigned int m, unsigned int n) {

// C code to be converted to x86 assembly
/*
    if ((m % n) == 0)
        return n;
    else
        return gcd(n, m % n);
*/
    __asm{
            mov eax, 0
            // BEGIN YOUR CODE HERE
			push ebp
			mov ebp, esp

			push edi
			push esi
			push ebx

			mov edx, 0//hold the mod
			mov eax, dword ptr[ebp+8] //edi = m
			mov ebx, dword ptr[ebp+12] //esi = n
			div ebx 
			//ebx = m%n edi = [m/n] esi=n
			cmp edx, 0
			je ret_1
			
			push eax
			push ecx
			push edx

			//gcd(n, m%n)
			push edx //m%n
			push ebx //n
			call gcd
			add esp, 8
			mov edi, eax

			pop edx
			pop ecx
			pop eax

			mov eax, edi
			jmp the_end

		ret_1:
			mov eax, ebx
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
