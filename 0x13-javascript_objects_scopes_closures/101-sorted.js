#!/usr/bin/node

const dict = require('./101-data').dict;

const newDict = {};

for (const [key, value] of Object.entries(dict)) {
  newDict[value] ? newDict[value].push(key) : (newDict[value] = [key]);
}

console.log(newDict);
