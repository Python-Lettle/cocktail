#include <string>
#include <asm.h>
using namespace std;
/* 内置函数 */
string asm_print(string varname)
{
	string print_asm = 
		"\n\t.globl print\n"
		"\t.type print,@function\n"
		"print:\n"
		"\tadrp    x0, "+varname+"\n"
    	"\tadd x0, x0, :lo12:"+varname+"\n"
		"\tbl  puts\n"
		"\tret\n";
	return	print_asm;
}

/* 变量类型 */
string asm_string(string varname,string str)
{
	string string_asm =
		"."+varname+":\n"
		"\t.ascii\t\""+str+"\"\n";
	return string_asm;
}


string asm_main()
{
	string main_asm =
	"main:\n"
	"\tstp x29, x30, [sp, #-16]!\n"
    "\tadrp    x0, .content\n"
    "\tadd x0, x0, :lo12:.content\n"
	"\tmov x29, sp\n"
	"\tbl  puts\n"
    "\tmov w0, wzr\n"
    "\tldp x29, x30, [sp], #16\n"
    "\tret\n";
	return main_asm;
}

string asm_head()
{
	string head_asm =
		"\t.globl main\n";
	return head_asm;
}

string asm_test_get()
{
    string test_asm = 
    "LC0: \n"
	"\t.ascii \"Hello,cocktail!\\0\" \n"
    ".globl _main \n"
	"\t.def	_main;	.scl	2;	.type	32;	.endef \n"
    "_main: \n"
	"\tpushl	%ebp \n"
	"\tmovl	$16, %eax \n"
	"\tmovl	%esp, %ebp \n"
	"\tsubl	$8, %esp \n"
	"\tandl	$-16, %esp \n"
	"\tcall	__alloca \n"
	"\tcall	___main \n"
	"\tmovl	$LC0, (%esp) \n"
	"\tcall	_printf \n"
	"\tleave \n"
	"\txorl	%eax, %eax \n"
	"\tret \n"
	"\t.def	_printf;	.scl	2;	.type	32;	.endef\n";
    return test_asm;
}
