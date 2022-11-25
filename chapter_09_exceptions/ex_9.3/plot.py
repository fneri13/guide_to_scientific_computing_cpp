#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 10 17:23:00 2022

@author: nerifr
"""

import numpy as np
from matplotlib import pyplot as plt

File_data = np.loadtxt("eul.txt", dtype=float)
# print(File_data)
t_eul = File_data[:,0]
y_eul = File_data[:,1]

t_truth=np.linspace(0,1,1000)
y_truth=0.8*np.exp(-100*t_truth)


plt.figure(figsize=(9,6))
plt.plot(t_truth,y_truth,label='Analytical')
plt.plot(t_eul,y_eul,'--o',label='Euler backward')
plt.xlabel('t')
plt.ylabel('y')
plt.xscale('log')
plt.legend()
plt.show()

