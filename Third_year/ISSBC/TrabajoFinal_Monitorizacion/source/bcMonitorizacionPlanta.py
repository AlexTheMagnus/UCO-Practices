#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
	Modulo encargado de definir la base de conocimiento del dominio de las
	plantas

	:author: Manuel Alejandro Luque León
	:date: 5/06/2020
"""

__docformat__ = "restructuredtext"

from bcMonitorizacion import *


# DEFINICION DE LA BASE DE CONOCIMIENTO

##	Clase representativa del parámetro: humedad
#
#	Define las especificaciones de la humedad
#       
class Humedad(Parametro):
    '''
    El parámetro mide la humedad del ambiente donde la unidad son es % 
    y la norma está por debajo de 80
    '''
    def __init__(self):
        Parametro.__init__(self, nombre=u'Humedad', unidad='%')
        
        self.norma=Norma(valor=80, tipo='<=')


##	Clase representativa del parámetro: temperatura
#
#	Define las especificaciones de la temperatura
#    
class Temperatura(Parametro):
    '''
    El parámetro es la temperatura donde la unidad es el ºC y la norma 
    está por debajo de 30
    '''
    def __init__(self):
        Parametro.__init__(self, nombre=u'Temperatura', unidad=u'ºC')
        
        self.norma=Norma(valor=30, tipo='<=')


##	Clase representativa del parámetro: temperatura
#
#	Define las especificaciones de la temperatura
#    
class NivelLuz(Parametro):
    '''
    El parámetro es el nivel lumínico que recibe la planta 
    donde la unidad es lux y la norma está por encima de 10000
    '''
    def __init__(self):
        Parametro.__init__(self, nombre=u'Nivel de Luz', unidad='lux')
        
        self.norma=Norma(valor=10000, tipo='>=')
        

##	Clase representativa del parámetro: refrigerante
#
#	Define las especificaciones del refrigerante
#    
class DioxidoCarbono(Parametro):
    '''
    El parámetro es la cantidad de dióxido de carbono en el ambiente donde
    la unidad es ppm (partes por millón) y la norma esta por encima de 450
    '''
    def __init__(self):
        Parametro.__init__(self, nombre=u'Dioxido de Carbono', unidad='ppm')
        
        self.norma=Norma(valor=450, tipo='>=')


# FUNCIONES AUXILIARES
def clases():
    '''
    Crea una lista de parámetros de la base de conocimiento.
    '''
    return [Humedad(), Temperatura(), NivelLuz(), DioxidoCarbono()]
