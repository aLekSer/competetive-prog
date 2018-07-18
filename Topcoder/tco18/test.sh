#!/bin/bash
g++ -o ./inv -g ./InvestmentAdvice.cpp
java -jar ~/Downloads/investment_tester.jar -exec ./inv --seed 4
