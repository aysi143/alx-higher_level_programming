#!/usr/bin/node

const request = require('request');
const id = process.argv[2];
request(
  'https://swapi-api.hbtn.io/api/films/' + id,
  function (error, response, body) {
    if (error) {
      console.log(error);
    } else {
      const character = JSON.parse(body).characters;
      character.forEach((element) => {
        request(element, function (err, res, content) {
          if (err) {
            console.log(err);
          } else {
            console.log(JSON.parse(content).name);
          }
        });
      });
    }
  }
);
