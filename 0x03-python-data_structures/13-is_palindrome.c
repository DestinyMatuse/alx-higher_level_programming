#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <bytesobject.h>

/**
 * print_python_bytes - Prints information about a Python bytes object.
 * @p: Pointer to the Python object to be analyzed.
 *
 * This function prints details about a Python bytes object, including its size
 * and the first 10 bytes of its content in hexadecimal representation. If the
 * object is not a valid bytes object, it prints an error message.
 */
void print_python_bytes(PyObject *p)
{
	long int size;
	int i;
	char *trying_str = NULL;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("[ERROR] Invalid Bytes Object\n");
		return;
	}

	PyBytes_AsStringAndSize(p, &trying_str, &size);

	printf("size: %ld\n", size);
	printf("trying string: %s\n", trying_str);
	if (size < 10)
		printf("first %ld bytes:", size + 1);
	else
		printf("first 10 bytes:");
	for (i = 0; i <= size && i < 10; i++)
		printf(" %02hhx", trying_str[i]);
	printf("\n");
}

/**
 * print_python_list - Prints information about a Python list object.
 * @p: Pointer to the Python list object to be analyzed.
 *
 * This function prints details about a Python list object, including its size
 * and the type of each element in the list. If an element is a bytes object,
 * it calls print_python_bytes to print additional information about the bytes object.
 */
void print_python_list(PyObject *p)
{
	long int size = PyList_Size(p);
	int i;
	PyListObject *list = (PyListObject *)p;
	const char *type;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", list->allocated);
	for (i = 0; i < size; i++)
	{
		type = (list->ob_item[i])->ob_type->tp_name;
		printf("Element %d: %s\n", i, type);
		if (!strcmp(type, "bytes"))
			print_python_bytes(list->ob_item[i]);
	}
}

