#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
	Modulo encargado de definir las vistas del sistema de monitorizacion

	:author: Manuel Alejandro Luque León
	:date 05/06/2020
"""

__docformat__ = "restructuredtext"

import sys
from PyQt4 import QtCore
from PyQt4 import QtGui

from bcMonitorizacion import *
import ckCtrlMonitorizacion as ctrl
import bcMonitorizacionPacientes as bcMonitPacientes
import bcMonitorizacionComputador as bcMonitComputador
import bcMonitorizacionCoche as bcMonitCoche
import bcMonitorizacionPlanta as bcMonitPlanta

class MonitorizacionDlg(QtGui.QWidget):
	"""
	Clase donde se codifica la interfaz de la aplicacion

	:author: Manuel Alejandro Luque León
	:date 05/06/2020
	"""
	def __init__(self):		
		# Llamada al constructor de la clase padre
		super(MonitorizacionDlg, self).__init__()
		
		# Atributos de proposito general
		self.dominio = 'Pacientes'
		self.parametro = bcMonitPacientes.clases()[0].nombre
		self.hallazgoValor = 0
		self.crearTablasDescripcionDominio()

		# Atributos de Interfaz de Usuario
		self.grid = QtGui.QGridLayout()	
		self.grid.setSpacing(10)	
		
		# Descripcion del dominio		
		labelTextDescripcionDominio=QtGui.QLabel(u"Descripción del dominio",self)

		self.grid.addWidget(labelTextDescripcionDominio, 0, 1)
		self.grid.addWidget(self.tablaWidgetComputador, 1, 1, 1, 1)
		self.tablaWidgetComputador.hide()
		self.grid.addWidget(self.tablaWidgetCoche, 1, 1, 1, 1)
		self.tablaWidgetCoche.hide()
		self.grid.addWidget(self.tablaWidgetPlanta, 1, 1, 1, 1)
		self.tablaWidgetPlanta.hide()
		self.grid.addWidget(self.tablaWidgetPacientes, 1, 1, 1, 1)
  
  		# Dominio de aplicacion
		labelComboBoxDominio=QtGui.QLabel("Dominio", self)
		self.comboBoxDominio= QtGui.QComboBox()
		self.comboBoxDominio.addItem('Pacientes')
		self.comboBoxDominio.addItem('Computadoras')
		self.comboBoxDominio.addItem('Coche')
		self.comboBoxDominio.addItem('Planta')
		self.comboBoxDominio.activated[str].connect(self.dominioModificado)
		
		self.grid.addWidget(labelComboBoxDominio, 10, 1)
		self.grid.addWidget(self.comboBoxDominio, 11, 1)

		# Parámetro seleccionado
		labelComboBoxParametro=QtGui.QLabel(u"Parámetro", self)
		self.comboBoxParametro= QtGui.QComboBox()
		self.cc=bcMonitPacientes.clases()
		for c in self.cc:
			self.comboBoxParametro.addItem(c.nombre)

		self.comboBoxParametro.activated[str].connect(self.parametroModificado)
		
		self.grid.addWidget(labelComboBoxParametro, 12, 1)
		self.grid.addWidget(self.comboBoxParametro, 13, 1)

		# Hallazgo seleccionado
		labelHallazgo = QtGui.QLabel(u"Hallazgo", self)

		self.doubleValidator = QtGui.QDoubleValidator()
		self.hallazgoInput = QtGui.QLineEdit(self)
		self.hallazgoInput.setValidator(self.doubleValidator)

		self.hallazgoInput.textChanged[str].connect(self.hallazgoModificado)
		
		self.grid.addWidget(labelHallazgo, 14, 1)
		self.grid.addWidget(self.hallazgoInput, 15, 1)
  
		# Justificacion de la monitorizacion
		labelTextjustificacionL=QtGui.QLabel(u"Justificación de la monitorización",self)		
		self.plainTextEditExplicacion = QtGui.QPlainTextEdit()
		self.plainTextEditExplicacion.setReadOnly(True)
		
		self.grid.addWidget(labelTextjustificacionL, 0, 0)
		self.grid.addWidget(self.plainTextEditExplicacion, 1, 0, 30, 1)
  		

		# Definicion de los botones
		self.monitorizarButtom=QtGui.QPushButton('Monitorizar')
		self.borrarButtom=QtGui.QPushButton('Borrar')
		self.salirButtom=QtGui.QPushButton('Salir') 
		self.buttomsLayout = QtGui.QHBoxLayout()
		self.buttomsLayout.addStretch()
		self.buttomsLayout.addWidget(self.monitorizarButtom)
		self.buttomsLayout.addWidget(self.borrarButtom)
		self.buttomsLayout.addWidget(self.salirButtom)
		self.buttomsLayout.addStretch()
		
		# Creacion de un contenedor vertical para desarrollar la interfaz
		mainLayout = QtGui.QVBoxLayout()
		mainLayout.addLayout(self.grid)
		mainLayout.addLayout(self.buttomsLayout)
		self.setLayout(mainLayout)

		# Definir las dimensiones de la ventana, titulo y a continuacion, mostrarla
		self.setGeometry(0, 0, 1200, 600)
		self.setWindowTitle("TAREA DE MONITORIZACION")
		self.show()
		
		#self.plainTextEditExplicacion.appendPlainText("Dominio" + self.dominio)

		# Señales		
		self.monitorizarButtom.clicked.connect(self.monitorizar)
		self.borrarButtom.clicked.connect(self.plainTextEditExplicacion.clear)
		self.salirButtom.clicked.connect(self.close)

	def crearTablasDescripcionDominio(self):
		"""
		Metodo encargado de crear un tabla representativa de cada dominio
		a traves de cual se podran indicar la descripción del mismo

		:author: Manuel Alejandro Luque León
		:date 05/06/2020
		"""
		self.etiquetasHeader= ['PARAMETRO', 'NORMA', 'UNIDAD']
  
		#PACIENTES
		self.cc=bcMonitPacientes.clases()
   
		# Crear la tabla relativa al dominio de pacientes
		self.tablaWidgetPacientes= QtGui.QTableWidget(len(self.cc), 3)
		self.tablaWidgetPacientes.setColumnWidth(0,200)
		self.tablaWidgetPacientes.setColumnWidth(1,200)
		self.tablaWidgetPacientes.setColumnWidth(2,150)
		self.tablaWidgetPacientes.setHorizontalHeaderLabels(self.etiquetasHeader)

		i=0
		for c in self.cc:
			parametro = QtGui.QTableWidgetItem(c.nombre)
			parametro.setFlags(QtCore.Qt.ItemIsUserCheckable|QtCore.Qt.ItemIsEnabled)

			norma = QtGui.QTableWidgetItem(c.norma.tipo + ' ' + str(c.norma.valor))
			norma.setFlags(QtCore.Qt.ItemIsUserCheckable|QtCore.Qt.ItemIsEnabled)

			unidad = QtGui.QTableWidgetItem(c.unidad)
			unidad.setFlags(QtCore.Qt.ItemIsUserCheckable|QtCore.Qt.ItemIsEnabled)

			self.tablaWidgetPacientes.setItem(i,0,parametro)
			self.tablaWidgetPacientes.setItem(i,1,norma)
			self.tablaWidgetPacientes.setItem(i,2,unidad)
			i=i+1
   
		#COMPUTADORES
		self.cc=bcMonitComputador.clases()

		# Crear la tabla relativa al dominio de los computadores
		self.tablaWidgetComputador= QtGui.QTableWidget(len(self.cc), 3)
		self.tablaWidgetComputador.setColumnWidth(0,200)
		self.tablaWidgetComputador.setColumnWidth(1,200)
		self.tablaWidgetComputador.setColumnWidth(2,150)
		self.tablaWidgetComputador.setHorizontalHeaderLabels(self.etiquetasHeader)
   		
		i=0
		for c in self.cc:
			parametro = QtGui.QTableWidgetItem(c.nombre)
			parametro.setFlags(QtCore.Qt.ItemIsUserCheckable|QtCore.Qt.ItemIsEnabled)

			norma = QtGui.QTableWidgetItem(c.norma.tipo + ' ' + str(c.norma.valor))
			norma.setFlags(QtCore.Qt.ItemIsUserCheckable|QtCore.Qt.ItemIsEnabled)

			unidad = QtGui.QTableWidgetItem(c.unidad)
			unidad.setFlags(QtCore.Qt.ItemIsUserCheckable|QtCore.Qt.ItemIsEnabled)

			self.tablaWidgetComputador.setItem(i,0,parametro)
			self.tablaWidgetComputador.setItem(i,1,norma)
			self.tablaWidgetComputador.setItem(i,2,unidad)
			i=i+1

		#COCHE
		self.cc=bcMonitCoche.clases()
   
		# Crear la tabla relativa al dominio de coche
		self.tablaWidgetCoche= QtGui.QTableWidget(len(self.cc), 3)
		self.tablaWidgetCoche.setColumnWidth(0,200)
		self.tablaWidgetCoche.setColumnWidth(1,200)
		self.tablaWidgetCoche.setColumnWidth(2,150)
		self.tablaWidgetCoche.setHorizontalHeaderLabels(self.etiquetasHeader)

		i=0
		for c in self.cc:
			parametro = QtGui.QTableWidgetItem(c.nombre)
			parametro.setFlags(QtCore.Qt.ItemIsUserCheckable|QtCore.Qt.ItemIsEnabled)

			norma = QtGui.QTableWidgetItem(c.norma.tipo + ' ' + str(c.norma.valor))
			norma.setFlags(QtCore.Qt.ItemIsUserCheckable|QtCore.Qt.ItemIsEnabled)

			unidad = QtGui.QTableWidgetItem(c.unidad)
			unidad.setFlags(QtCore.Qt.ItemIsUserCheckable|QtCore.Qt.ItemIsEnabled)

			self.tablaWidgetCoche.setItem(i,0,parametro)
			self.tablaWidgetCoche.setItem(i,1,norma)
			self.tablaWidgetCoche.setItem(i,2,unidad)
			i=i+1

		#PLANTA
		self.cc=bcMonitPlanta.clases()
   
		# Crear la tabla relativa al dominio de planta
		self.tablaWidgetPlanta= QtGui.QTableWidget(len(self.cc), 3)
		self.tablaWidgetPlanta.setColumnWidth(0,200)
		self.tablaWidgetPlanta.setColumnWidth(1,200)
		self.tablaWidgetPlanta.setColumnWidth(2,150)
		self.tablaWidgetPlanta.setHorizontalHeaderLabels(self.etiquetasHeader)

		i=0
		for c in self.cc:
			parametro = QtGui.QTableWidgetItem(c.nombre)
			parametro.setFlags(QtCore.Qt.ItemIsUserCheckable|QtCore.Qt.ItemIsEnabled)

			norma = QtGui.QTableWidgetItem(c.norma.tipo + ' ' + str(c.norma.valor))
			norma.setFlags(QtCore.Qt.ItemIsUserCheckable|QtCore.Qt.ItemIsEnabled)

			unidad = QtGui.QTableWidgetItem(c.unidad)
			unidad.setFlags(QtCore.Qt.ItemIsUserCheckable|QtCore.Qt.ItemIsEnabled)

			self.tablaWidgetPlanta.setItem(i,0,parametro)
			self.tablaWidgetPlanta.setItem(i,1,norma)
			self.tablaWidgetPlanta.setItem(i,2,unidad)
			i=i+1
    		

	def dominioModificado(self, text):
		"""
		Metodo encargado modificar y ajustar la interfaz de usuario en
		funcion del dominio seleccionado por el usuario
	
		:param text: Dominio seleccionado [str]

		:author: Manuel Alejandro Luque León
		:date 05/06/2020
		"""

		# Comprobar que el dominio seleccionado sea distinto al actual
 
		if self.dominio != text:
			
			# Actualizar de forma interna el dominio seleccionado
			self.dominio = text

			# Actualizar la tabla descriptiva del objeto a clasisficar
			if self.dominio == "Pacientes":
				self.tablaWidgetComputador.hide()
				self.tablaWidgetCoche.hide()
				self.tablaWidgetPlanta.hide()
				self.tablaWidgetPacientes.show()

				self.comboBoxParametro.clear()
				self.cc=bcMonitPacientes.clases()
				for c in self.cc:
					self.comboBoxParametro.addItem(c.nombre)
				self.parametro = bcMonitPacientes.clases()[0].nombre

			elif self.dominio == "Coche":
				self.tablaWidgetComputador.hide()
				self.tablaWidgetPacientes.hide()
				self.tablaWidgetPlanta.hide()
				self.tablaWidgetCoche.show()

				self.comboBoxParametro.clear()
				self.cc=bcMonitCoche.clases()
				for c in self.cc:
					self.comboBoxParametro.addItem(c.nombre)
				self.parametro = bcMonitCoche.clases()[0].nombre

			elif self.dominio == "Planta":
				self.tablaWidgetComputador.hide()
				self.tablaWidgetPacientes.hide()
				self.tablaWidgetCoche.hide()
				self.tablaWidgetPlanta.show()

				self.comboBoxParametro.clear()
				self.cc=bcMonitPlanta.clases()
				for c in self.cc:
					self.comboBoxParametro.addItem(c.nombre)
				self.parametro = bcMonitPlanta.clases()[0].nombre
				
			else:
				self.tablaWidgetPacientes.hide()
				self.tablaWidgetCoche.hide()
				self.tablaWidgetPlanta.hide()
				self.tablaWidgetComputador.show()

				self.comboBoxParametro.clear()
				self.cc=bcMonitComputador.clases()
				for c in self.cc:
					self.comboBoxParametro.addItem(c.nombre)
				self.parametro = bcMonitComputador.clases()[0].nombre

			# Limpiar justificacion de la respuesta
			self.plainTextEditExplicacion.clear()

	def parametroModificado(self, text):
		"""
		Metodo encargado modificar el sistema internamente en
		funcion del parametro seleccionado por el usuario

		:param text: Parametro seleccionado [str]

		:author: Manuel Alejandro Luque León
		:date 06/06/2020
		"""

		# Comprobar que el parámetro seleccionado sea distinto al actual
 
		if self.parametro != text:
			# Actualizar de forma interna el parámetro seleccionado
			self.parametro = text	
			
	def hallazgoModificado(self, text):
		"""
		Metodo encargado modificar el sistema internamente en
		funcion del hallazgo introducido por el usuario

		:param text: Hallazgo introducido [str]

		:author: Manuel Alejandro Luque León
		:date 06/06/2020
		"""
		if self.hallazgoValor != text:
			# Actualizar de forma interna el parámetro seleccionado
			if text == "":
				self.hallazgoValor = 0
			else:
				self.hallazgoValor = text



	def monitorizar(self):
		"""
		Metodo encargado de iniciar el proceso de monitorizacion
		con el dominio elegido por el usuario

		:author: Manuel Alejandro Luque León
		:date 06/06/2020
		"""

		explicacion = ctrl.eventoMonitorizar(self.dominio, self.parametro, self.hallazgoValor)

		# Reflejar los resultados por pantalla
		self.plainTextEditExplicacion.clear()
		self.plainTextEditExplicacion.appendPlainText(explicacion)
		self.plainTextEditExplicacion.moveCursor(QtGui.QTextCursor.Start)
			

if __name__=='__main__':
    app = QtGui.QApplication(sys.argv)
    form = MonitorizacionDlg()
    sys.exit(app.exec_())
