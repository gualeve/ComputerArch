#!/usr/bin/python
'''
    FILENAME :       cache.py

    DESCRIPTION :
        Present cache informations (size, association, line size)

    AUTHOR : José Adalberto F. Gualeve       START DATE : 2018-11-09

'''

from os import popen
from platform import system
cache = [
        {"level": "LEVEL1_DCACHE", "size": 0, "assoc": 0, "line_size": 0},
        {"level": "LEVEL1_ICACHE", "size": 0, "assoc": 0, "line_size": 0},
        {"level": "LEVEL2_CACHE", "size": 0, "assoc": 0, "line_size": 0},
        {"level": "LEVEL3_CACHE", "size": 0, "assoc": 0, "line_size": 0}]

def run():
    for i in range(0, len(cache)):
        cache[i]["size"] = int(popen("getconf {}_SIZE".format(cache[i]["level"])).read())
        cache[i]["assoc"] = int(popen("getconf {}_ASSOC".format(cache[i]["level"])).read())
        cache[i]["line_size"] = int(popen("getconf {}_LINESIZE".format(cache[i]["level"])).read())

    for i in cache:
        print("Cache ", i["level"])
        print("Size: ", i["size"], "Bytes")
        print("Association: ", i["assoc"], "Lines/Set")
        print("Line Size: ", i["line_size"], "Bytes")
        print("")

if __name__ == '__main__':
    if system() == 'Linux':
        run()
    else:
        print("Necessario Linux para executar")
