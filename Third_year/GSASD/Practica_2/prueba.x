/* Define la estructura de parametros de entrada de las funciones */
struct operandos
{
	float a;
	float b;
};


program CALCULADORA_PROG {
    version CALCULADORA_VERS {
	float SUMA(operandos) = 1;	/* numero de procedimiento = 1 */
	float MULTIPLICACION(operandos) = 2; /*numero de procedimiento = 2*/
	float DIVISION(operandos) = 3; /*numero de procedimiento = 3*/
    } = 1;			/* numero de version = 1 */
} = 0x20000001;			/* numero de programa = 0x20000001 */
			       /* 0x20000000 - 0x3fffffff para usuarios*/
