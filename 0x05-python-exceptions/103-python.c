#include <Python.h>
#include <stdio.h>
#include <listobject.h>
#include <object.h>
#include <floatobject.h>
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);
/**
 * print_python_list - prints the basic info of a python list object
 * @p: python list
 * Return: void
 */

void print_python_list(PyObject *p)
{
  Py_ssize_t size_obj, index;
  PyObject *type;

  printf("[*] Python list info\n");
  fflush(stdout);
  if (!PyList_Check(p))
    {
      printf("  [ERROR] Invalid List Object\n");
      return;
    }

  size_obj = PySequence_Length(p);

  printf("[*] Size of the Python List = %li\n", size_obj);
  fflush(stdout);
  printf("[*] Allocated = %li\n", (((PyListObject *)(p))->allocated));
  fflush(stdout);
  for (index = 0; index < size_obj; index++)
    {
      type = PyList_GET_ITEM(p, index);
      if (*((char *)(((PyObject *)(type))->ob_type)) == 'C')
	printf("Element %li: int\n", index);
      else if (*((char *)((PyObject *)(type))->ob_type) == 'I')
	printf("Element %li: str\n", index);
      else if (*((char *)((PyObject *)(type))->ob_type) == '\'')
	printf("Element %li: list\n", index);
      else if (*((char *)((PyObject *)(type))->ob_type) == '3')
	{
	  printf("Element %li: float\n", index);
	  print_python_float(type);
	}
      else if (*((char *)((PyObject *)(type))->ob_type) == '9')
	printf("Element %li: tuple\n", index);
      if (PyBytes_Check(type))
	{
	  printf("Element %li: bytes\n", index);
	  print_python_bytes(type);
	}
      fflush(stdout);
    }
}

/**
 * print_python_bytes - prints some basic info about python bytes objects
 * @p: python byte object
 * Return: void
 */

void print_python_bytes(PyObject *p)
{
  Py_ssize_t size_bytes;
  char *buffer;
  long int i;

  printf("[.] bytes object info\n");
  fflush(stdout);
  if (!PyBytes_Check(p))
    {
      printf("  [ERROR] Invalid Bytes Object\n");
      return;
    }

  size_bytes = PyBytes_Size(p);
  PyBytes_AsStringAndSize(p, &buffer, &size_bytes);
  printf("  size: %li\n", size_bytes);
  fflush(stdout);
  printf("  trying string: %s\n", buffer);
  fflush(stdout);
  if (size_bytes < 10)
    printf("  first %li bytes:", size_bytes + 1);
  else
    {
      printf("  first 10 bytes:");
      size_bytes = 10;
    }
  fflush(stdout);
  for (i = 0; i <= size_bytes && i < 10; i++)
    {
      if (buffer[i])
	printf(" %02x", buffer[i] & 0xff);
      else
	printf(" 00");
      fflush(stdout);
    }
  printf("\n");
}
/**
 * print_python_float - prints the value of float object in python
 * @p: object in python
 * Return: void
 */

void print_python_float(PyObject *p)
{
  printf("[.] float object info\n");
  fflush(stdout);
  if (!PyFloat_Check(p))
    {
      printf("  [ERROR] Invalid Float Object\n");
      return;
    }
}
