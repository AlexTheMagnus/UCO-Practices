#!/usr/bin/env python2
# -*- coding: utf-8 -*-

from rdflib import Graph, Namespace

RDFS = Namespace("http://www.w3.org/2000/01/rdf-schema#")

#------------------------DATA---------------------------------------
my_data ='''
                @prefix gems:    <http://example.com/gems#> .
                @prefix prop:    <http://xmlns.com/prop/0.1/> .

                gems:emerald  prop:name        "emerald" .
                gems:emerald  prop:type        "gem" .
                gems:emerald  prop:color       "green" .
                gems:emerald  prop:hardness     7.5 .
                gems:emerald  prop:density     2.7 .

                gems:diamond  prop:name        "diamond" .
                gems:diamond  prop:type        "gem" .
                gems:diamond  prop:color       "white" .
                gems:diamond  prop:hardness     10 .
                gems:diamond  prop:density     3.5 .

                gems:ruby  prop:name        "ruby" .
                gems:ruby  prop:type        "gem" .
                gems:ruby  prop:color       "red" .
                gems:ruby  prop:hardness     9 .
                gems:ruby  prop:density     4 .

                gems:sapphire  prop:name        "sapphire" .
                gems:sapphire  prop:type        "gem" .
                gems:sapphire  prop:color       "blue" .
                gems:sapphire  prop:hardness     9 .
                gems:sapphire  prop:density     4 .

                gems:lapislazuli  prop:name        "lapislazuli" .
                gems:lapislazuli  prop:type        "gem" .
                gems:lapislazuli  prop:color       "blue" .
                gems:lapislazuli  prop:hardness     5.25 .
                gems:lapislazuli  prop:density     2.4 .

                gems:topaz  prop:name        "topaz" .
                gems:topaz  prop:type        "gem" .
                gems:topaz  prop:color       "yellow" .
                gems:topaz  prop:hardness     8 .
                gems:topaz  prop:density     3.5 .

                gems:jade  prop:name        "jade" .
                gems:jade  prop:type        "gem" .
                gems:jade  prop:color       "green" .
                gems:jade  prop:hardness      7 .
                gems:jade  prop:density     3.3 .

                gems:quartz  prop:name        "quartz" .
                gems:quartz  prop:type        "gem" .
                gems:quartz  prop:color       "white" .
                gems:quartz  prop:hardness     7 .
                gems:quartz  prop:density     3.5 .

                gems:amethyst  prop:name        "amethyst" .
                gems:amethyst  prop:type        "gem" .
                gems:amethyst  prop:color       "purple" .
                gems:amethyst  prop:hardness     7 .
                gems:amethyst  prop:density     2.65 .

                gems:garnet  prop:name        "garnet" .
                gems:garnet  prop:type        "gem" .
                gems:garnet  prop:color       "red" .
                gems:garnet  prop:hardness     7 .
                gems:garnet  prop:density     3.7 .
'''

g = Graph()
print
g.parse(data=my_data, format="n3")
print "Información del grafo:"
print "======================"
print g.serialize(format='n3')

#--------------------------------------------------------------------------

#Obtener todos los colores de las gemas del grafo (sin que se repitan)
def q3():
    #Es necesario utilizar la propiedad DISTINCT para que no se repitan
    query='''  

        PREFIX gems:   <http://example.org/gems#> 
        PREFIX prop:   <http://xmlns.com/prop/0.1/>
        
        SELECT DISTINCT ?color
        WHERE { ?x prop:color ?color }
    ''' 

    result = g.query(query)
    print '3. Obtener todos los colores de las gemas del grafo (sin repetir):'
    print '=================================================================='
    print result.serialize()
    print

    for row in result:
        #print row
        print "%s" % tuple(row)
    print



#--------------------------------------------------------------------------

if __name__ == '__main__':

    #Pregunta 3
    q3()