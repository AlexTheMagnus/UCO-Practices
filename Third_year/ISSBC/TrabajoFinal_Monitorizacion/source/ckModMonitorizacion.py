#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
	Modulo encargado de definir el modulo de aplicacion del sistema de
	monitorizacion

	:author: Manuel Alejandro Luque León
	:date: 10/06/2015
"""

__docformat__ = "restructuredtext"

import random
from bcMonitorizacion import *
import bcMonitorizacionComputador as bcMonitComputador
import bcMonitorizacionPacientes as bcMonitPacientes
import bcMonitorizacionCoche as bcMonitCoche
import bcMonitorizacionPlanta as bcMonitPlanta
import os, sys

class MetodoMonitorizacion():
	"""
	Clase donde se codifica el metodo de la monitorizacion

	:author: Manuel Alejandro Luque León
	:date 06/06/2020
	"""

	def __init__(self, dominio, parametro, hallazgoValor):
		self.dominio = dominio
		self.parametrosCandidatos=[]
		self.explicacion=u''
		self.parametro = parametro
		self.hallazgoValor = hallazgoValor
		file = open("historico.txt", "a")
		file.write("Dominio:" + self.dominio + "/Parametro:" + self.parametro + "/Hallazgo:" + self.hallazgoValor.replace(',','.'))
		file.close()

	
	def execute(self):
		# Se recibe el hallazgo desde el exterior
		recibir = Recibir(self.dominio, self.parametro, self.hallazgoValor)
		self.parametrosCandidatos, self.hallazgo = recibir.execute()
		self.explicacion+=u'Se recibe el hallazgo: ' + str(self.hallazgo.valor) + '\n'
	
		# Comienzo de ejecucion del metodo para la monitorizacion
		seleccionar = Seleccionar(self.parametrosCandidatos, self.hallazgo)
		self.parametro = seleccionar.execute()
		self.explicacion+=u'Se selecciona el parámetro: ' + self.parametro.nombre + '\n'

		especificar = Especificar(self.parametro)
		self.norma = especificar.execute()
		self.explicacion+=u'Se especifica la norma: ' + self.norma.tipo + ' ' + str(self.norma.valor) + '\n'

		comparar = Comparar(self.hallazgo, self.norma)
		resultado, self.diferencia = comparar.execute()
		self.explicacion+=u'Comparamos el hallazgo con la norma y obtenemos la diferencia: ' + str(self.diferencia) + '\n'
		if resultado:
			self.explicacion+=u'\nNO HAY DISCREPANCIA\n'
			file = open("historico.txt", "a")
			file.write("\n")
			file.close()
		else:
			self.explicacion+=u'\n¡ATENCIÓN! HAY UNA DISCREPANCIA\n'
			file = open("historico.txt", "a")
			file.write("/DISCREPANCIA\n")
			file.close()

		return self.explicacion
			
			
class Inferencia():
	"""
	Clase padre de todas las inferencias del modelo de aplicacion

	:author: Michael Castillo Polo y Luis Miguel López Coleto
	:date: 10/06/2015
	"""

	def __init__(self):
		pass
	def execute(self):
		pass


class FuncionTransferencia():
	"""
	Clase padre de todas las funciones de transferencia del modelo de aplicacion

	:author: Michael Castillo Polo y Luis Miguel López Coleto
	:date: 10/06/2015
	"""
	def __init__(self):
		pass
	def execute(self):
		pass


class Recibir(FuncionTransferencia):
	"""
	Clase representativa de la funcion de transferencia encargada de recibir
	la información desde el exterior

	:author: Manuel Alejandro Luque León
	:date 06/06/2020
	"""

	def __init__(self, dominio, parametro, hallazgoValor):
		"""
		Constructor de la clase
	
		:param dominio: Dominio del cual se desean obtener la informacion

		:author: Manuel Alejandro Luque León
		:date 06/06/2020
		"""
		FuncionTransferencia.__init__(self)
		self.dominio = dominio
		self.parametro = parametro
		self.hallazgoValor = hallazgoValor


	def execute(self):
		"""
		Metodo encargado de ejecutar la funcion de transferencia "Recibir"
	
		:return: Un hallazgo

		:author: Manuel Alejandro Luque León
		:date: 05/06/2020
		"""
		# Comprobar el dominio especificado
		if self.dominio == 'Coche':
			parametrosCandidatos = bcMonitCoche.clases()

		elif self.dominio == 'Computadoras':
			parametrosCandidatos = bcMonitComputador.clases()

		elif self.dominio == 'Planta':
			parametrosCandidatos = bcMonitPlanta.clases()

		else:
			parametrosCandidatos = bcMonitPacientes.clases()
		
		
		hallazgo = Hallazgo(self.parametro, self.hallazgoValor)

		return parametrosCandidatos, hallazgo

		
class Seleccionar(Inferencia):
	"""
	Clase representativa de la inferencia encargada de seleccionar el parametro
	del valor recibido del exterior

	:author: Michael Castillo Polo y Luis Miguel López Coleto
	:date: 10/06/2015
	"""

	def __init__(self, parametrosCandidatos, hallazgo):
		"""
		Constructor de la clase
	
		:param hallazgo: Informacion recibida del exterior
	
		:param parametrosCandidatos: Listado con todos los parametros candidatos del dominio
	
		:author: Michael Castillo Polo y Luis Miguel López Coleto
		:date: 10/06/2015
		"""
		Inferencia.__init__(self)
		self.hallazgo = hallazgo
		self.parametrosCandidatos = parametrosCandidatos

	def execute(self):
		"""
		Metodo encargado de ejecutar la inferencia "Seleccionar"
	
		:return: El parámetro seleccionado
	
		:author: Michael Castillo Polo y Luis Miguel López Coleto
		:date: 10/06/2015
		"""
		#Recorremos los parametros candidatos para seleccionar el correcto
		for parametro in self.parametrosCandidatos:
			if parametro.nombre == self.hallazgo.parametro:
				return parametro

		
class Especificar(Inferencia):
	"""
	Clase representativa de la inferencia encargada de devolver la norma
	relacionada con un parametro

	:author: Michael Castillo Polo y Luis Miguel López Coleto
	:date: 10/06/2015
	"""

	def __init__(self, parametro):
		"""
		Constructor de la clase
	
		:param parametro: Parametro que se va a monitorizar
	
		:author: Michael Castillo Polo y Luis Miguel López Coleto
		:date: 10/06/2015
		"""
		Inferencia.__init__(self)
		self.parametro = parametro
		
	def execute(self):
		"""
		Metodo encargado de encontrar la norma ligada al parametro
	
		:return: Norma ligada al parametro
	
		:author: Michael Castillo Polo y Luis Miguel López Coleto
		:date: 10/06/2015
		"""
		return self.parametro.norma

	
class Comparar(Inferencia):
	"""
	Clase representativa de la inferencia encargada de comparar el hallazgo
	recibido con la norma del parametro seleccionado

	:author: Michael Castillo Polo y Luis Miguel López Coleto
	:date: 10/06/2015
	"""

	def __init__(self, hallazgo, norma):
		"""
		Constructor de la clase
	
		:param hallazgo: Informacion recibida del exterior
		:param norma: Valor 'normal' del parametro 
	
		:author: Michael Castillo Polo y Luis Miguel López Coleto
		:date: 10/06/2015
		"""
		Inferencia.__init__(self)
		self.hallazgo = hallazgo
		self.norma = norma
		self.explicacion= u''
	
	def execute(self):
		"""
		Metodo encargado de llevar a cabo la comparacion del hallazgo con la norma
	
		:return: Resultado de la equiparacion [True o False], seguido de
				su respectiva explicacion
	
		:author: Manuel Alejandro Luque León
		:date 06/06/2020
		"""

		diferencia = float(self.hallazgo.valor.replace(',','.')) - float(self.norma.valor)

		# Comprobamos el tipo de la norma
		if self.norma.tipo == '<=': #Si la norma es del tipo <=

			if float(self.hallazgo.valor) <= float(self.norma.valor):
				return True, abs(diferencia)
			else:
				return False, abs(diferencia)
		
		elif self.norma.tipo == '>=': #Si la norma es del tipo >=
			if float(self.hallazgo.valor) >= float(self.norma.valor):
				return True, abs(diferencia)
			else:
				return False, abs(diferencia)
