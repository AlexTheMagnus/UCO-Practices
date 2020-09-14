#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
	Modulo encargado de definir la base de conocimiento del dominio de los
	coches

	:author: Manuel Alejandro Luque León
	:date: 5/06/2020
"""

__docformat__ = "restructuredtext"

from bcMonitorizacion import *


# DEFINICION DE LA BASE DE CONOCIMIENTO

##	Clase representativa del parámetro: revoluciones
#
#	Define las especificaciones de las revoluciones
#       
class Revoluciones(Parametro):
    '''
    El parámetro mide las revoluciones del motor del coche donde la unidad son las rpm 
    (revoluciones por minuto) y la norma está por debajo de  3.500
    '''
    def __init__(self):
        Parametro.__init__(self, nombre=u'Revoluciones', unidad='rpm')
        
        self.norma=Norma(valor=3500, tipo='<=')


##	Clase representativa del parámetro: aceite
#
#	Define las especificaciones del aceite
#    
class Aceite(Parametro):
    '''
    El parámetro es el aceite donde la unidad es el cl (centilitro) y la norma 
    está por encima de 300
    '''
    def __init__(self):
        Parametro.__init__(self, nombre=u'Aceite', unidad='cl')
        
        self.norma=Norma(valor=300, tipo='>=')


##	Clase representativa del parámetro: temperatura
#
#	Define las especificaciones de la temperatura
#    
class Temperatura(Parametro):
    '''
    El parámetro es la temperatura del motor donde la unidad es ºC y 
    la norma está por debajo de 150
    '''
    def __init__(self):
        Parametro.__init__(self, nombre=u'Temperatura', unidad=u'ºC')
        
        self.norma=Norma(valor=150, tipo='<=')
        

##	Clase representativa del parámetro: refrigerante
#
#	Define las especificaciones del refrigerante
#    
class Refrigerante(Parametro):
    '''
    El parámetro es la cantidad de refrigerante donde la unidad es cl (centilitro) y 
    la norma esta por encima de 400
    '''
    def __init__(self):
        Parametro.__init__(self, nombre=u'Refrigerante', unidad='cl')
        
        self.norma=Norma(valor=400, tipo='>=')


##	Clase representativa del parámetro: presion neumatica
#
#	Define las especificaciones de la presion neumatica
#    
class PresionNeumatica(Parametro):
    '''
    El parámetro es la presión neumática donde la unidad es bar y la norma esta 
    por encima de 2.1
    '''
    def __init__(self):
        Parametro.__init__(self, nombre=u'Presion Neumatica', unidad='bar')
        
        self.norma=Norma(valor=2.1, tipo='>=')


##	Clase representativa del parámetro: grosor neumatico
#
#	Define las especificaciones del 
#    
class GrosorNeumatico(Parametro):
    '''
    El parámetro es el grosor neumático donde la unidad es mm (milimetro)
    y la norma esta por encima de 1.6
    '''
    def __init__(self):
        Parametro.__init__(self, nombre=u'Grosor Neumatico', unidad=u'mm')

        self.norma=Norma(valor=1.6, tipo='>=')


# FUNCIONES AUXILIARES
def clases():
    '''
    Crea una lista de parámetros de la base de conocimiento.
    '''
    return [Revoluciones(), Aceite(), Temperatura(), Refrigerante(), PresionNeumatica(), GrosorNeumatico()]
