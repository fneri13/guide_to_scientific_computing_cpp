#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 10 17:23:00 2022

@author: nerifr
"""

import numpy as np
from matplotlib import pyplot as plt

File_data = np.loadtxt("log_eul.txt", dtype=float)
# print(File_data)
t_eul = File_data[:,0]
y_eul = File_data[:,1]

File_data_2 = np.loadtxt("log_rk.txt", dtype=float)
t_rk = File_data_2[:,0]
y_rk = File_data_2[:,1]

t_truth=np.linspace(0,1,100)
y_truth=(t_truth**2+2*t_truth+4)/2


plt.figure(figsize=(9,6))
plt.plot(t_truth,y_truth,label='Analytical')
plt.plot(t_eul,y_eul,'--o',label='Euler backward')
plt.plot(t_rk,y_rk,'--o',label='Runge Kutta 4')
plt.xlabel('t')
plt.ylabel('y')
plt.legend()
plt.show()

