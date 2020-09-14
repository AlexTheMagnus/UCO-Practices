#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
	Modulo encargado de definir el subsistema de control del sistema de
	monitorizacion
"""

__docformat__ = "restructuredtext"

from PyQt4 import QtGui
import ckModMonitorizacion as ma

def eventoMonitorizar(dominio, parametro, hallazgovalor):
	"""
	Metodo encargado de ejecutar el metodo para monitorizar
	indicando el dominio

	:param dominio: Dominio en el que se va a monitorizar

	:author: Manuel Alejandro Luque León
	:date 06/06/2020
	"""

	mp= ma.MetodoMonitorizacion(dominio, parametro, hallazgovalor)
	return mp.execute()
        


